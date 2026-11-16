#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>

static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"[iomfbabi] %@", s);
}
typedef struct { int sel; uint32_t si, sti, so, sto; } Ent;
// entries from the 101-entry table (only fields we need)
static Ent tbl[] = {
 {0,3,0,0,0},{1,0,0,0,0},{2,0,0,0,0},{3,2,0,1,0},{4,0,0,1,0},
 {5,0,0x6e0,0,0},{6,3,0,0,0},{7,0,0,1,0},{8,0,0,2,0},{9,2,0,0,0},
 {10,1,0,0,0},{11,2,0,0,0},{12,1,0,0,0},{13,1,0,0,0},{14,2,0,1,0},
 {15,2,0,1,0},{16,1,0,0,0},{17,0,0xc0c,0,0},{18,0,0,1,0},{19,1,0,0,0},
 {20,2,0,0,0},{21,2,0,0,0},{22,1,0,0,0},{23,2,0,0,0},{24,0,0,0,0x10},
 {25,0,0,1,0},{26,0,0,0,0},{27,0,0,0,0xc0c},{28,0,0,1,0},{29,0,0,0,8},
 {30,1,0,0,0},{31,1,0,0,0},{32,2,0,0,0},{33,1,0,0,0},{34,1,0,0,0},
 {35,1,0,0,0},{36,0,0,0,0},{37,0,0,0,0},{38,0,0,0,0},{39,0,0,0,0},
 {40,0,0,0,0},{41,1,0,0,0},{42,0,0,0,0x14},{43,0,4,0,0},{44,0,0x10,0,0},
 {45,0,0,0,0},{46,0,0,0,0},{47,4,0,0,0},{48,2,0,1,0},{49,1,0,1,0},
 {50,2,0,0,0},{51,1,0,0,0},{52,1,0,0,0},{53,2,0,0,0},{54,1,0,0,0x48},
 {55,1,0x48,0,0},{56,0,0x9c,0,0},{57,0,0,1,0},{58,2,0,0,0},{59,0,0,0,0},
 {60,0,0,0,0},{61,0,0,0,0},{62,0,0,0,0},{63,0,0,0,0},{64,0,0,0,0},
 {65,0,0,0,0},{66,2,0,0,0},{67,0,0,1,0},{68,1,0xffffffff,0,0},{69,0,0x88,0,0},
 {70,0,0,0,0},{71,0,0,0,0},{72,4,0,0,0},{73,2,0,0,0},{74,1,0,2,0x40},
 {75,0,0x8008,0,0},{76,0,0,0,0},{77,0,0,1,0},{78,0xffffffff,0xffffffff,0xffffffff,0xffffffff},
 {79,0xffffffff,0xffffffff,0xffffffff,0xffffffff},{80,0,0,1,0},{81,2,0,0,0},
 {82,0,0,1,0},{83,1,0,1,0},{84,0,4,0,0},{85,0xffffffff,0xffffffff,0,0},
 {86,0,0xffffffff,1,0},{87,1,0,0,0},{88,1,0,0,0},{89,1,0,0,0},{90,0,0,1,0},
 {91,0,0,1,0},{92,0,0,1,0},{93,1,0x14,0,0},{94,1,0,0,0},{95,1,0x14,0,0},
 {96,1,0,1,0},{97,1,0,0,0},{98,0,0,1,0},{99,0,0xffffffff,1,0},{100,0,0xffffffff,0,0}
};
static void one(io_connect_t c, int sel) {
    Ent *e = NULL; for (unsigned i=0;i<sizeof(tbl)/sizeof(tbl[0]);i++) if (tbl[i].sel==sel) e=&tbl[i];
    if (!e) { L(@"[sel %d] no entry", sel); return; }
    uint32_t sizes[5]; int ns=0;
    if (e->sti==0xffffffff) { sizes[ns++]=0; sizes[ns++]=8; sizes[ns++]=0x10; sizes[ns++]=0x100; sizes[ns++]=0x1000; }
    else sizes[ns++]=e->sti;
    for (int k=0;k<ns;k++) {
        uint32_t sti = sizes[k];
        uint32_t si = e->si==0xffffffff?0:e->si;
        uint32_t so = e->so==0xffffffff?4:e->so;
        uint32_t sto = e->sto==0xffffffff?0x100:e->sto;
        uint64_t *sv = si?calloc(si,8):NULL;
        uint8_t *sin = sti?calloc(1,sti):NULL;
        uint64_t *sov = so?calloc(so,8):NULL; uint32_t soc = so;
        uint8_t *sout = sto?calloc(1,sto):NULL; size_t sos = sto;
        kern_return_t kr = IOConnectCallMethod(c, sel, sv, si, sin, sti, sov, &soc, sout, &sos);
        NSMutableString *o = [NSMutableString string];
        for (unsigned i=0;i<so && i<4;i++) [o appendFormat:@" s%u=%llx", i, (unsigned long long)sov[i]];
        [o appendFormat:@" osz=0x%zx", sos];
        if (sto && kr==0) {
            [o appendString:@" out="];
            for (unsigned i=0;i<16 && i<sos;i++) [o appendFormat:@"%02x", sout[i]];
        }
        L(@"[sel %3d] sti=0x%x -> 0x%x%@", sel, sti, kr, o);
        free(sv); free(sin); free(sov); free(sout);
        if (sti > 0x2000) break;
    }
}
static void run(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOMobileFramebuffer"));
    L(@"[svc] 0x%x", svc);
    if (!svc) return;
    io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc, mach_task_self(), 0, &c);
    L(@"[open] 0x%x conn=0x%x", kr, c);
    IOObjectRelease(svc);
    if (kr) return;
    int list[] = {0,1,2,3,4,7,8,11,12,16,18,19,21,24,25,28,29,31,34,36,42,47,48,49,54,57,67,74,77,80,82,90,91,92,96,98};
    for (unsigned i=0;i<sizeof(list)/sizeof(list[0]);i++) one(c, list[i]);
    IOServiceClose(c);
    L(@"=== done ===");
}
@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (strong, nonatomic) UIWindow *window;
@end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new]; vc.view.backgroundColor = UIColor.blackColor;
    UITextView *tv = [[UITextView alloc] initWithFrame:vc.view.bounds];
    tv.backgroundColor = UIColor.blackColor; tv.textColor = UIColor.greenColor;
    tv.font = [UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];
    tv.editable = NO; tv.text = @"IOMFBABI\n";
    [vc.view addSubview:tv]; self.window.rootViewController = vc; [self.window makeKeyAndVisible];
    [UIApplication sharedApplication].idleTimerDisabled = YES;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
        NSString *docs = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
        gPath = [docs stringByAppendingPathComponent:@"iomfbabi.log"];
        gLog = [NSMutableString new]; run();
        dispatch_async(dispatch_get_main_queue(), ^{ tv.text = gLog; });
    });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
