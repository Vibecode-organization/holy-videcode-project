#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#include <unistd.h>
#include <stdio.h>
extern int csops(pid_t pid, unsigned int ops, void *useraddr, size_t usersize);
#define CS_OPS_ENTITLEMENTS_BLOB 7

static NSMutableString *gLog;
static NSString *gPath;
static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap,fmt); NSString *s=[[NSString alloc] initWithFormat:fmt arguments:ap]; va_end(ap);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    [s writeToFile:@"/tmp/cttest_live.log" atomically:YES encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"[CTTEST] %@", s);
}

static NSString *ents_string(void) {
    unsigned char buf[32768]; memset(buf,0,sizeof(buf));
    int r=csops(getpid(),CS_OPS_ENTITLEMENTS_BLOB,buf,sizeof(buf));
    if (r!=0) return [NSString stringWithFormat:@"csops errno=%d",errno];
    uint32_t len=ntohl(*(uint32_t*)(buf+4)); (void)len;
    if (len>sizeof(buf)-8) len=sizeof(buf)-8;
    NSData *d=[NSData dataWithBytes:buf+8 length:len];
    NSString *s=[[NSString alloc] initWithData:d encoding:NSUTF8StringEncoding];
    return s ?: @"(non-utf8 ents)";
}

static void probe(void) {
    L(@"uid=%d euid=%d pid=%d", getuid(), geteuid(), getpid());
    unsigned int st = 0;
    int sr = csops(getpid(), 0, &st, sizeof(st));
    L(@"csops status -> %d errno=%d flags=0x%x", sr, errno, st);
    L(@"bundle=%@", [[NSBundle mainBundle] bundlePath]);
    L(@"ents=%@", ents_string());
    const char *paths[] = {
        "/private/var/mobile/Library/Preferences/com.apple.springboard.plist",
        "/private/var/mobile/Library/SMS/sms.db",
        "/private/etc/passwd",
        "/System/Library/CoreServices/SystemVersion.plist",
        "/private/var/containers/Shared/SystemGroup",
        NULL
    };
    for (int i=0; paths[i]; i++) {
        NSData *d=[NSData dataWithContentsOfFile:[NSString stringWithUTF8String:paths[i]]];
        L(@"read %s -> %lu", paths[i], (unsigned long)d.length);
    }
    NSError *e=nil;
    BOOL w=[@"cttest" writeToFile:@"/tmp/cttest_bypass.txt" atomically:YES encoding:NSUTF8StringEncoding error:&e];
    L(@"write /tmp/cttest_bypass.txt -> %d err=%@", w, e);
    NSArray *dir=[[NSFileManager defaultManager] contentsOfDirectoryAtPath:@"/private/var/mobile/Library" error:&e];
    L(@"list /private/var/mobile/Library -> %lu err=%@", (unsigned long)dir.count, e);
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@property (nonatomic, strong) UITextView *tv;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    gLog=[NSMutableString new];
    gPath=[NSHomeDirectory() stringByAppendingPathComponent:@"Documents/cttest.log"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    self.window=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc=[UIViewController new];
    self.tv=[[UITextView alloc] initWithFrame:vc.view.bounds];
    self.tv.editable=NO; self.tv.font=[UIFont monospacedSystemFontOfSize:10 weight:UIFontWeightRegular];
    [vc.view addSubview:self.tv];
    self.window.rootViewController=vc; [self.window makeKeyAndVisible];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW,(int64_t)(0.5*NSEC_PER_SEC)),dispatch_get_main_queue(),^{
        dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{
            @autoreleasepool { L(@"=== CTTEST start %@ ===",[[UIDevice currentDevice] systemVersion]); probe(); L(@"=== CTTEST done ==="); dispatch_async(dispatch_get_main_queue(),^{ self.tv.text=gLog; }); }
        });
    });
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
