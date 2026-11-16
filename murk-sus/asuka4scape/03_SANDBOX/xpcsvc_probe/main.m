#import <UIKit/UIKit.h>
@protocol Dummy @end
static NSMutableString *G; static NSString *P;
static void L(NSString *f,...){va_list a;va_start(a,f);NSString*s=[[NSString alloc]initWithFormat:f arguments:a];va_end(a);
 [G appendFormat:@"%@\n",s];[G writeToFile:P atomically:YES encoding:NSUTF8StringEncoding error:NULL];NSLog(@"[XPC] %@",s);}
@interface AppDelegate : UIResponder <UIApplicationDelegate> @property (nonatomic) UIWindow *window; @end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)o{
  G=[NSMutableString new];
  P=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES).firstObject stringByAppendingPathComponent:@"xpcsvc.log"];
  L(@"xpc-service probe %@",[[UIDevice currentDevice] systemVersion]);
  NSArray *svcs=@[@"com.apple.quicklook.ThumbnailsAgent",@"com.apple.ImageIOXPCService",
                  @"com.apple.textkit.nsattributedstringagent",@"com.apple.PrintKit.PrinterTool",
                  @"com.apple.BarcodeSupport.ParsingService"];
  for(NSString *s in svcs){
    @try{
      NSXPCConnection *c=[[NSXPCConnection alloc] initWithServiceName:s];
      c.remoteObjectInterface=[NSXPCInterface interfaceWithProtocol:@protocol(Dummy)];
      __weak NSXPCConnection *wc=c;
      c.interruptionHandler=^{ L(@"%@ interrupted", s); };
      c.invalidationHandler=^{ L(@"%@ invalidated", s); };
      [c resume];
      id proxy=[c synchronousRemoteObjectProxyWithErrorHandler:^(NSError *e){ L(@"%@ ERROR %@ %ld", s, e.domain, (long)e.code); }];
      L(@"%@ proxy=%p conn=%p", s, proxy, wc);
    } @catch(NSException *e){ L(@"%@ EXC %@", s, e.reason); }
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
