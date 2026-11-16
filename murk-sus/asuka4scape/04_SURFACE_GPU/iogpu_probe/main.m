#import <UIKit/UIKit.h>
#import <mach/mach.h>
typedef mach_port_t io_object_t; typedef io_object_t io_service_t, io_connect_t;
extern io_service_t IOServiceGetMatchingService(mach_port_t, CFDictionaryRef);
extern CFMutableDictionaryRef IOServiceMatching(const char *);
extern kern_return_t IOServiceOpen(io_service_t, mach_port_t, uint32_t, io_connect_t *);
extern kern_return_t IOServiceClose(io_connect_t);
extern kern_return_t IOObjectRelease(io_object_t);
extern kern_return_t IOConnectCallMethod(io_connect_t, uint32_t, const uint64_t *, uint32_t,
    const void *, size_t, uint64_t *, uint32_t *, void *, size_t *);
extern kern_return_t IOConnectCallStructMethod(io_connect_t, uint32_t, const void *, size_t, void *, size_t *);

static NSMutableString *G; static NSString *P;
static void L(NSString *f, ...) {
    va_list a; va_start(a,f);
    NSString *s=[[NSString alloc] initWithFormat:f arguments:a]; va_end(a);
    [G appendFormat:@"%@\n",s];
    [G writeToFile:P atomically:YES encoding:NSUTF8StringEncoding error:NULL];
    NSLog(@"[IOG] %@",s);
}

static void probe_sels(io_connect_t c, NSString *tag) {
    for (uint32_t sel = 0; sel <= 0x1a; sel++) {
        uint8_t in[0x408]; memset(in,0,sizeof(in));
        uint64_t so[8]; memset(so,0,sizeof(so)); uint32_t sc=8;
        size_t outsz=0x100; uint8_t out[0x100]; memset(out,0,sizeof(out));
        kern_return_t k1 = IOConnectCallMethod(c, sel, NULL,0, in,0x408, so,&sc, out,&outsz);
        size_t outsz2=0x58; uint8_t out2[0x58]; memset(out2,0,sizeof(out2));
        kern_return_t k2 = IOConnectCallStructMethod(c, sel, in,0x408, out2,&outsz2);
        L(@"%@ sel=0x%02x CallMethod kr=0x%x sc=%u outsz=0x%zx | CallStruct kr=0x%x outsz=0x%zx",
          tag, sel, k1, sc, outsz, k2, outsz2);
    }
}

static void probe_dev(NSString *cls) {
    io_service_t svc = IOServiceGetMatchingService(0, IOServiceMatching(cls.UTF8String));
    if (!svc) { L(@"%@ absent", cls); return; }
    for (uint32_t t=0; t<4; t++) {
        io_connect_t conn=0;
        kern_return_t kr=IOServiceOpen(svc, mach_task_self(), t, &conn);
        L(@"%@ open type%u kr=0x%x conn=%u", cls, t, kr, conn);
        if (kr==KERN_SUCCESS) {
            if (t==1 || [cls containsString:@"Scaler"]) probe_sels(conn, [NSString stringWithFormat:@"%@/t%u",cls,t]);
            IOServiceClose(conn);
        }
    }
    IOObjectRelease(svc);
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic) UIWindow *window;
@end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)o {
    G=[NSMutableString new];
    P=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES).firstObject stringByAppendingPathComponent:@"iogpu.log"];
    L(@"iogpu probe %@", [[UIDevice currentDevice] systemVersion]);
    probe_dev(@"AGXAcceleratorG14P");
    probe_dev(@"AppleM2ScalerCSCDriver");
    probe_dev(@"IOSurfaceRoot");
    L(@"done");
    UIViewController *vc=[UIViewController new];
    UITextView *tv=[[UITextView alloc] initWithFrame:vc.view.bounds];
    tv.text=G; tv.editable=NO; [vc.view addSubview:tv];
    self.window=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.window.rootViewController=vc; [self.window makeKeyAndVisible];
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,@"AppDelegate");}}
