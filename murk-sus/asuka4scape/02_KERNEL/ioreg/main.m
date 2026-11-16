#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[ir] %@",s);}
static void scan(NSString*tag,NSString*s){for(NSString*l in [s componentsSeparatedByString:@"\n"]){if([l containsString:@"fffffff"]||[l containsString:@"ffffffe"]||[l containsString:@"4d00000"]||[l containsString:@"0x4d"])L(@"[HIT %@] %@",tag,l);}}
static void dump(io_registry_entry_t e,const char*tag){
 char path[512]; IORegistryEntryGetPath(e,kIOServicePlane,path); L(@"[%s] path=%s entry=0x%x",tag,path,e);
 CFMutableDictionaryRef p=NULL; kern_return_t kr=IORegistryEntryCreateCFProperties(e,&p,kCFAllocatorDefault,0); L(@"[%s] props kr=0x%x",tag,kr);
 if(p){NSString*s=[NSString stringWithFormat:@"%@",(__bridge NSDictionary*)p];L(@"[%s] len=%zu",tag,s.length);if(strstr(tag,"AGX")||strstr(tag,"sgx")||strstr(tag,"IOGPU")||strstr(tag,"AppleT811"))L(@"[%s] dict=%.*s",tag,(int)(s.length>4000?4000:s.length),s.UTF8String);scan([NSString stringWithUTF8String:tag],s);CFRelease(p);}
}
static void walk(io_registry_entry_t e,const char*tag,int depth){
 if(depth>3)return; dump(e,tag);
 io_registry_entry_t par=0; if(IORegistryEntryGetParentEntry(e,kIOServicePlane,&par)==KERN_SUCCESS){char pt[80];snprintf(pt,sizeof(pt),"%s^",tag);dump(par,pt);IOObjectRelease(par);}
 io_iterator_t it=0; if(IORegistryEntryGetChildIterator(e,kIOServicePlane,&it)==KERN_SUCCESS){io_registry_entry_t c;int n=0;while((c=IOIteratorNext(it))&&n<32){char t[64];snprintf(t,sizeof(t),"%s.%d",tag,n);walk(c,t,depth+1);IOObjectRelease(c);n++;}IOObjectRelease(it);}
}
static void run(void){
 const char*names[]={"AGXAcceleratorG14P","AGXAccelerator","IOGPU","IOGPUDevice","AppleM2ScalerCSCDriver","AppleJPEGDriver"};
 for(int i=0;i<6;i++){io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching(names[i]));L(@"[svc %s] 0x%x",names[i],svc);if(svc){walk(svc,names[i],0);IOObjectRelease(svc);}}
 io_registry_entry_t root=IORegistryGetRootEntry(kIOMasterPortDefault);if(root){walk(root,"root",0);IOObjectRelease(root);}
 L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"IORegDump\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"ir.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
