// mprobe.dylib — constructor probe for DYLD_INSERT into a system app.
#import <Foundation/Foundation.h>
#import <dlfcn.h>
#import <unistd.h>
#import <fcntl.h>
#import <sys/stat.h>

__attribute__((constructor)) static void mprobe_init(void) {
    NSString *out = @"/var/tmp/com.apple.CoreDevice/mprobe_loaded";
    int fd = open(out.fileSystemRepresentation, O_CREAT|O_WRONLY|O_TRUNC, 0644);
    if (fd >= 0) {
        dprintf(fd, "loaded pid=%d uid=%d euid=%d\n", getpid(), getuid(), geteuid());
        close(fd);
    }
    NSLog(@"[mprobe] loaded pid=%d uid=%d", getpid(), getuid());
    void *h = dlopen("/usr/lib/system/libsystem_sandbox.dylib", RTLD_NOW);
    char *(*issue)(const char *, const char *, uint32_t) = h ? dlsym(h, "sandbox_extension_issue_file") : NULL;
    if (issue) {
        char *t = issue("com.apple.app-sandbox.read-write", "/", 0);
        int tf = open("/var/tmp/com.apple.CoreDevice/mprobe_token", O_CREAT|O_WRONLY|O_TRUNC, 0644);
        if (tf >= 0) {
            if (t) { write(tf, t, strlen(t)); }
            else { dprintf(tf, "issue failed errno=%d", errno); }
            close(tf);
        }
        if (t) free(t);
    }
}
