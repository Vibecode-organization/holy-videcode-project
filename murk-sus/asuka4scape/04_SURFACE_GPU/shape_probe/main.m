#import <UIKit/UIKit.h>
#import <mach/mach.h>
#include <stddef.h>
typedef mach_port_t io_object_t; typedef io_object_t io_service_t, io_connect_t;
extern io_service_t IOServiceGetMatchingService(mach_port_t, CFDictionaryRef);
extern CFMutableDictionaryRef IOServiceMatching(const char*);
extern kern_return_t IOServiceOpen(io_service_t, mach_port_t, uint32_t, io_connect_t*);
extern kern_return_t IOServiceClose(io_connect_t);
extern kern_return_t IOObjectRelease(io_object_t);
extern kern_return_t IOConnectCallMethod(io_connect_t,uint32_t,const uint64_t*,uint32_t,const void*,size_t,uint64_t*,uint32_t*,void*,size_t*);
static NSMutableString *G; static NSString *P;
static void L(NSString *f,...){va_list a;va_start(a,f);NSString*s=[[NSString alloc]initWithFormat:f arguments:a];va_end(a);
 [G appendFormat:@"%@\n",s];[G writeToFile:P atomically:YES encoding:NSUTF8StringEncoding error:NULL];NSLog(@"[SH] %@",s);}
@interface AppDelegate : UIResponder <UIApplicationDelegate> @property (nonatomic) UIWindow *window; @end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)o{
  G=[NSMutableString new];
  P=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES).firstObject stringByAppendingPathComponent:@"shape.log"];
  L(@"shape probe %@",[[UIDevice currentDevice] systemVersion]);
  NSArray *classes=@[@"AGXAcceleratorG14P",@"AppleM2ScalerCSCDriver",@"IOSurfaceRoot"];
  size_t sizes[]={0,0x18,0x40,0x58,0x100,0x408};
  for(NSString *cls in classes){
    io_service_t svc=IOServiceGetMatchingService(0,IOServiceMatching(cls.UTF8String));
    if(!svc){L(@"%@ absent",cls);continue;}
    for(uint32_t t=0;t<4;t++){
      io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),t,&c);
      if(kr!=KERN_SUCCESS){continue;}
      L(@"%@ t%u open",cls,t);
      for(uint32_t sel=0;sel<=0x37;sel++){
        for(int si=0;si<6;si++){
          for(uint32_t scn=0;scn<=5;scn++){
          uint8_t in[0x408]; memset(in,0,sizeof(in)); size_t isz=sizes[si];
          uint64_t so[8]; memset(so,0,sizeof(so)); uint32_t sc=8;
          uint8_t out[0x100]; memset(out,0,sizeof(out)); size_t osz=sizeof(out);
          uint64_t scal[8]={0,0,0,0,0,0,0,0};
          kr=IOConnectCallMethod(c,sel,scal,scn,isz?in:NULL,isz,so,&sc,out,&osz);
          if(kr!=0xe00002c2 && kr!=0xe00002c7 && kr!=0xe00002e2)
            L(@"  sel=0x%02x scIn=%u in=0x%zx kr=0x%x sc=%u outsz=0x%zx so0=0x%llx",sel,scn,isz,kr,sc,osz,(unsigned long long)so[0]);
          }
        }
      }
      IOServiceClose(c);
    }
    IOObjectRelease(svc);
  }
  L(@"done");
  UIViewController *vc=[UIViewController new];
  UITextView *tv=[[UITextView alloc] initWithFrame:vc.view.bounds]; tv.text=G; tv.editable=NO; [vc.view addSubview:tv];
  self.window=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
  self.window.rootViewController=vc; [self.window makeKeyAndVisible];
  return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,@"AppDelegate");}}
