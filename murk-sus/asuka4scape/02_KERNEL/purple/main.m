#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <IOSurface/IOSurfaceRef.h>
#import <mach/mach.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[pu] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static IOSurfaceRef mk(NSDictionary*d){return IOSurfaceCreate((__bridge CFDictionaryRef)d);}
static void probe(const char*tag,NSDictionary*d){
 IOSurfaceRef s=mk(d); L(@"[%s] surf=%p",tag,s); if(!s)return;
 void*b=IOSurfaceGetBaseAddress(s); size_t al=IOSurfaceGetAllocSize(s); size_t bpr=IOSurfaceGetBytesPerRow(s); size_t w=IOSurfaceGetWidth(s),h=IOSurfaceGetHeight(s);
 L(@"[%s] base=%p alloc=0x%zx bpr=0x%zx w=%zu h=%zu planes=%zu",tag,b,al,bpr,w,h,IOSurfaceGetPlaneCount(s));
 if(b&&al>=0x20){uint8_t*p=b; L(@"[%s] bytes: %02x %02x %02x %02x %02x %02x %02x %02x",tag,p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7]);
  memset(b,0x5A,0x20); L(@"[%s] wrote 5A",tag);
  /* memory entry alias */
  mach_vm_size_t msz=al; mach_port_t mo=MACH_PORT_NULL;
  kern_return_t kr=mach_make_memory_entry_64(mach_task_self(),&msz,(mach_vm_address_t)(uintptr_t)b,VM_PROT_DEFAULT,&mo,MACH_PORT_NULL);
  L(@"[%s] make_entry kr=0x%x size=0x%llx port=0x%x",tag,kr,(unsigned long long)msz,mo);
  if(!kr&&mo){mach_vm_address_t at=0; mach_vm_size_t as=al;
   kr=mach_vm_map(mach_task_self(),&at,as,0,VM_FLAGS_ANYWHERE,mo,0,0,VM_PROT_DEFAULT,VM_PROT_DEFAULT,VM_INHERIT_NONE);
   L(@"[%s] alias kr=0x%x at=0x%llx size=0x%llx",tag,kr,(unsigned long long)at,(unsigned long long)as);
   if(!kr){L(@"[%s] alias bytes: %02x %02x %02x %02x",tag,((uint8_t*)at)[0],((uint8_t*)at)[1],((uint8_t*)at)[2],((uint8_t*)at)[3]);mach_vm_deallocate(mach_task_self(),at,as);}
   mach_port_deallocate(mach_task_self(),mo);}
 }
 CFRelease(s);
}
static void run(void){
 NSDictionary*base=@{@"IOSurfaceMemoryRegion":@"PurpleGfxMem"};
 for(uint64_t sz=0x4000;sz<=0x20000;sz*=2){NSMutableDictionary*d=[base mutableCopy];d[@"IOSurfaceAllocSize"]=@(sz);probe([[NSString stringWithFormat:@"purple-%llx",(unsigned long long)sz] UTF8String],d);}
 for(uint64_t a=0x04D00000;a<=0x04D08000;a+=0x4000){NSMutableDictionary*d=[base mutableCopy];d[@"IOSurfaceAllocSize"]=@0x4000;d[@"IOSurfaceAddress"]=@(a);probe([[NSString stringWithFormat:@"purple-addr-%llx",(unsigned long long)a] UTF8String],d);}
 {NSMutableDictionary*d=[base mutableCopy];d[@"IOSurfaceAllocSize"]=@0x4000;d[@"IOSurfaceAddress"]=@0x800000000ULL;probe("purple-addr-32g",d);}
 {NSDictionary*d=@{@"IOSurfaceAllocSize":@0x4000,@"IOSurfaceAddress":@0x04D00000ULL};probe("plain-addr",d);}
 {NSDictionary*d=@{@"IOSurfaceAllocSize":@0x4000};probe("plain",d);}
 L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"Purple\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"pu.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
