#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <IOSurface/IOSurfaceRef.h>
#import <Foundation/Foundation.h>
#import <mach/mach.h>
#import <mach/mach_host.h>
#import <mach/task_info.h>
#import <mach/thread_info.h>
#import <mach/port.h>
#import <sys/sysctl.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[kp] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void scan(const char*tag,const void*buf,size_t n){const uint8_t*b=buf;int h=0;for(size_t i=0;i+8<=n;i+=8){uint64_t v=rd64(b+i);if((v&0xfffffff000000000ULL)==0xfffffff000000000ULL){L(@"[HIT %s] +0x%zx=0x%llx",tag,i,(unsigned long long)v);if(++h>16)break;}}}
static void run(void){
 mach_port_t host=mach_host_self(); natural_t type=0; mach_vm_address_t kobj=0;
 kern_return_t kr=mach_port_kobject(mach_task_self(),host,&type,&kobj); L(@"[kobj host] kr=0x%x type=%u kobj=0x%llx",kr,type,(unsigned long long)kobj); scan("kobjhost",&kobj,8);
 kobj=0;type=0;kr=mach_port_kobject(mach_task_self(),mach_task_self(),&type,&kobj); L(@"[kobj task] kr=0x%x type=%u kobj=0x%llx",kr,type,(unsigned long long)kobj); scan("kobjtask",&kobj,8);
 kobj=0;type=0;kr=mach_port_kobject(mach_task_self(),bootstrap_port,&type,&kobj); L(@"[kobj boot] kr=0x%x type=%u kobj=0x%llx",kr,type,(unsigned long long)kobj); scan("kobjboot",&kobj,8);
 ipc_info_space_t info; ipc_info_name_array_t tab=NULL; mach_msg_type_number_t tc=0; ipc_info_tree_name_array_t tree=NULL; mach_msg_type_number_t tr=0;
 kr=mach_port_space_info(mach_task_self(),&info,&tab,&tc,&tree,&tr); L(@"[space] kr=0x%x names=%u tree=%u",kr,tc,tr);
 if(tab&&tc){scan("space_names",tab,tc*sizeof(ipc_info_name_t)); vm_deallocate(mach_task_self(),(vm_address_t)tab,tc*sizeof(ipc_info_name_t));}
 if(tree&&tr){scan("space_tree",tree,tr*sizeof(ipc_info_tree_name_t)); vm_deallocate(mach_task_self(),(vm_address_t)tree,tr*sizeof(ipc_info_tree_name_t));}
 for(int f=0;f<=32;f++){uint8_t b[4096];memset(b,0,sizeof(b));mach_msg_type_number_t c=sizeof(b)/sizeof(natural_t);kr=task_info(mach_task_self(),f,(task_info_t)b,&c);if(kr==KERN_SUCCESS){char t[64];snprintf(t,sizeof(t),"task_info%d",f);scan(t,b,(size_t)c*sizeof(natural_t));}}
 thread_t th=mach_thread_self();for(int f=0;f<=20;f++){uint8_t b[2048];memset(b,0,sizeof(b));mach_msg_type_number_t c=sizeof(b)/sizeof(natural_t);kr=thread_info(th,f,(thread_info_t)b,&c);if(kr==KERN_SUCCESS){char t[64];snprintf(t,sizeof(t),"thread_info%d",f);scan(t,b,(size_t)c*sizeof(natural_t));}}mach_port_deallocate(mach_task_self(),th);
 int pids[2]={0,getpid()};for(int i=0;i<2;i++){int mib[4]={CTL_KERN,KERN_PROC,KERN_PROC_PID,pids[i]};uint8_t b[2048];size_t len=sizeof(b);if(sysctl(mib,4,b,&len,NULL,0)==0){char t[64];snprintf(t,sizeof(t),"kinfo%d",pids[i]);scan(t,b,len);}else L(@"[sysctl %d] fail",pids[i]);}
 io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("IOSurfaceRoot"));L(@"[svc] 0x%x",svc);
 if(svc){io_connect_t c=0;kr=IOServiceOpen(svc,mach_task_self(),0,&c);L(@"[surf open] 0x%x",kr);IOObjectRelease(svc);if(!kr){NSDictionary*d=@{(id)kIOSurfaceWidth:@64,(id)kIOSurfaceHeight:@64,(id)kIOSurfaceBytesPerElement:@4,(id)kIOSurfacePixelFormat:@0x42475241};IOSurfaceRef s=IOSurfaceCreate((__bridge CFDictionaryRef)d);uint32_t sid=s?IOSurfaceGetID(s):0;L(@"[surf] %p id=%u",s,sid);if(s){uint64_t si=sid;uint8_t o[0xa0];memset(o,0xAA,sizeof(o));size_t os=0xa0;uint64_t so[2]={0};uint32_t soc=0;kr=IOConnectCallMethod(c,28,&si,1,NULL,0,so,&soc,o,&os);L(@"[sel28] kr=0x%x osz=0x%zx",kr,os);if(!kr){for(int i=0;i<0xa0;i+=8)L(@"[sel28] +0x%x=0x%llx",i,(unsigned long long)rd64(o+i));scan("sel28",o,0xa0);}CFRelease(s);}IOServiceClose(c);}}
 L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"KaslrPtr\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"kp.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
