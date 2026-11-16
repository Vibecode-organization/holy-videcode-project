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

static NSMutableString *G; static NSString *P;
static void L(NSString *f, ...){va_list a;va_start(a,f);NSString*s=[[NSString alloc]initWithFormat:f arguments:a];va_end(a);
 [G appendFormat:@"%@\n",s];[G writeToFile:P atomically:YES encoding:NSUTF8StringEncoding error:NULL];NSLog(@"[EDID] %@",s);}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic) UIWindow *window;
@end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)o {
    G=[NSMutableString new];
    P=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES).firstObject stringByAppendingPathComponent:@"edid.log"];
    L(@"edid probe %@", [[UIDevice currentDevice] systemVersion]);
    io_service_t svc=IOServiceGetMatchingService(0, IOServiceMatching("AppleM2ScalerCSCDriver"));
    if(!svc){L(@"no service");}
    else{
      for(uint32_t t=0;t<4;t++){
        io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),t,&c);
        L(@"open t%u kr=0x%x",t,kr);
        if(kr==KERN_SUCCESS){
          uint8_t buf[0x298]; memset(buf,0xAA,sizeof(buf));
          size_t sz=sizeof(buf);
          kr=IOConnectCallMethod(c,0x0b,NULL,0,NULL,0,NULL,NULL,buf,&sz);
          L(@"sel0x0b kr=0x%x size=0x%zx",kr,sz);
          int hits=0;
          for(size_t i=0;i+8<=sz && i<0x298;i+=8){
            uint64_t q=*(uint64_t*)(buf+i);
            if((q>>40)==0xffffff||(q>>40)==0xfffffe||(q>>40)==0xfffffff){
              L(@"  +0x%03zx = 0x%016llx  <== kernel-like",i,(unsigned long long)q); hits++;
            }
          }
          L(@"kernel-like hits=%d",hits);
          for(size_t off=0;off<sz && off<0x100;off+=16){
            NSMutableString *h=[NSMutableString string];
            for(size_t j=0;j<16&&off+j<sz;j++) [h appendFormat:@"%02x",buf[off+j]];
            L(@"%03zx: %@",off,h);
          }
          IOServiceClose(c);
        }
      }
      IOObjectRelease(svc);
    }
    L(@"done");
    UIViewController *vc=[UIViewController new];
    UITextView *tv=[[UITextView alloc] initWithFrame:vc.view.bounds]; tv.text=G; tv.editable=NO;
    [vc.view addSubview:tv];
    self.window=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.window.rootViewController=vc; [self.window makeKeyAndVisible];
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,@"AppDelegate");}}
