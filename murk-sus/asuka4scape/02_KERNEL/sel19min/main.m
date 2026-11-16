#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <IOSurface/IOSurfaceRef.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath; static io_connect_t C;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[s19m] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void s19(const char*tag,uint64_t id){uint64_t si[1]={id};uint8_t o[0x100];memset(o,0xAA,sizeof(o));size_t os=0x18;uint64_t so[4]={0};uint32_t soc=0;
 kern_return_t kr=IOConnectCallMethod(C,19,si,1,NULL,0,so,&soc,o,&os);L(@"[%s id=0x%llx] kr=0x%x osz=0x%zx q0=0x%llx q1=0x%llx q2=0x%llx",tag,(unsigned long long)id,kr,os,(unsigned long long)rd64(o),(unsigned long long)rd64(o+8),(unsigned long long)rd64(o+0x10));}
static kern_return_t mk(uint32_t type,uint64_t a38,uint64_t a48,uint8_t*out){uint8_t in[0x100];memset(in,0,sizeof(in));*(uint32_t*)in=type;*(uint64_t*)(in+0x38)=a38;*(uint64_t*)(in+0x48)=a48;*(uint32_t*)(in+0x50)=0x4000;memset(out,0xAA,0x1000);size_t os=0x1000;return IOConnectCallStructMethod(C,8,in,0x100,out,&os);}

static kern_return_t mk82(uint32_t sid,uint8_t*out){uint8_t in[0x100];memset(in,0,sizeof(in));*(uint32_t*)in=0x82;*(uint32_t*)(in+0x38)=sid;memset(out,0xAA,0x1000);size_t os=0x1000;return IOConnectCallStructMethod(C,8,in,0x100,out,&os);}
static void run(void){
 io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AGXAcceleratorG14P"));L(@"[svc] 0x%x",svc);if(!svc)return;
 kern_return_t kr=IOServiceOpen(svc,mach_task_self(),1,&C);IOObjectRelease(svc);L(@"[open] 0x%x",kr);if(kr)return;
 NSDictionary*d=@{@"IOSurfaceAllocSize":@0x10000,@"IOSurfaceMemoryRegion":@"PurpleGfxMem"};
 IOSurfaceRef s=IOSurfaceCreate((__bridge CFDictionaryRef)d);void*b=IOSurfaceGetBaseAddress(s);size_t al=IOSurfaceGetAllocSize(s);L(@"[purple] base=%p alloc=0x%zx",b,al);memset(b,0x5A,al);
 uint8_t o[0x1000];
 kr=mk(0,(uint64_t)(uintptr_t)b,0x4000,o);uint32_t rid=*(uint32_t*)(o+0x24);L(@"[t0] kr=0x%x rid=%u q0=0x%llx q5=0x%llx q6=0x%llx q7=0x%llx",kr,rid,(unsigned long long)rd64(o),(unsigned long long)rd64(o+0x28),(unsigned long long)rd64(o+0x30),(unsigned long long)rd64(o+0x38));if(!kr)s19("t0",rid);
 kr=mk(3,0x40,0,o);uint32_t gid=*(uint32_t*)(o+0x24);L(@"[t3] kr=0x%x rid=%u q0=0x%llx q5=0x%llx q6=0x%llx q7=0x%llx",kr,gid,(unsigned long long)rd64(o),(unsigned long long)rd64(o+0x28),(unsigned long long)rd64(o+0x30),(unsigned long long)rd64(o+0x38));if(!kr)s19("t3",gid);

 NSDictionary*pd=@{(id)kIOSurfaceWidth:@64,(id)kIOSurfaceHeight:@64,(id)kIOSurfaceBytesPerElement:@4,(id)kIOSurfacePixelFormat:@0x42475241};
 IOSurfaceRef ns=IOSurfaceCreate((__bridge CFDictionaryRef)pd);uint32_t nsid=ns?IOSurfaceGetID(ns):0;L(@"[nsurf] %p id=%u",ns,nsid);
 IOSurfaceRef ps=IOSurfaceCreate((__bridge CFDictionaryRef)d);uint32_t psid=ps?IOSurfaceGetID(ps):0;L(@"[psurf] %p id=%u",ps,psid);
 for(int k=0;k<2;k++){uint32_t sid=k?psid:nsid;if(!sid)continue;uint8_t q[0x1000];kern_return_t r2=mk82(sid,q);uint32_t rr=*(uint32_t*)(q+0x24);L(@"[t82 %d] sid=%u kr=0x%x rid=%u q0=0x%llx q5=0x%llx q6=0x%llx q7=0x%llx",k,sid,r2,rr,(unsigned long long)rd64(q),(unsigned long long)rd64(q+0x28),(unsigned long long)rd64(q+0x30),(unsigned long long)rd64(q+0x38));if(!r2)s19(k?"t82p":"t82",rr);}
 if(ns)CFRelease(ns);if(ps)CFRelease(ps);
 uint8_t so[0x100];memset(so,0xAA,sizeof(so));size_t sos=0x30;uint64_t soo[4]={0};uint32_t soc=0;kr=IOConnectCallMethod(C,21,NULL,0,NULL,0,soo,&soc,so,&sos);L(@"[sel21] kr=0x%x osz=0x%zx q0=0x%llx q1=0x%llx q2=0x%llx",kr,sos,(unsigned long long)rd64(so),(unsigned long long)rd64(so+8),(unsigned long long)rd64(so+0x10));
 if(s)CFRelease(s);IOServiceClose(C);L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"Sel19Min\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"s19m.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
