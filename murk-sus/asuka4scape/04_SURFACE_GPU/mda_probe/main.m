#import <UIKit/UIKit.h>
typedef void *xpc_object_t; typedef void *xpc_connection_t; typedef void *xpc_type_t;
typedef void (^xpc_handler_t)(xpc_object_t);
extern xpc_connection_t xpc_connection_create_mach_service(const char*, dispatch_queue_t, uint64_t);
extern void xpc_connection_set_event_handler(xpc_connection_t, xpc_handler_t);
extern void xpc_connection_resume(xpc_connection_t);
extern void xpc_connection_send_message_with_reply(xpc_connection_t, xpc_object_t, dispatch_queue_t, xpc_handler_t);
extern xpc_object_t xpc_dictionary_create(const void*, const void*, size_t);
extern void xpc_dictionary_set_uint64(xpc_object_t, const char*, uint64_t);
extern size_t xpc_dictionary_get_count(xpc_object_t);
extern const char *xpc_dictionary_get_string(xpc_object_t, const char*);
extern xpc_type_t xpc_get_type(xpc_object_t);
extern char *xpc_copy_description(xpc_object_t);
extern void xpc_release(xpc_object_t);
extern char _xpc_type_dictionary, _xpc_type_error;

static NSMutableString *G; static NSString *P;
static void L(NSString *f,...){va_list a;va_start(a,f);NSString*s=[[NSString alloc]initWithFormat:f arguments:a];va_end(a);
 [G appendFormat:@"%@\n",s];[G writeToFile:P atomically:YES encoding:NSUTF8StringEncoding error:NULL];NSLog(@"[MDA] %@",s);}
static void dump(xpc_object_t r, NSString *tag){
  if(!r){L(@"%@ nil",tag);return;}
  xpc_type_t t=xpc_get_type(r);
  if(t==&_xpc_type_error){const char*d=xpc_dictionary_get_string(r,"XPCErrorDescription"); if(d&&strstr(d,"interrupted"))return; L(@"%@ ERROR %s",tag,d?d:"?");return;}
  if(t==&_xpc_type_dictionary){L(@"%@ dict count=%zu",tag,xpc_dictionary_get_count(r));return;}
  char *d=xpc_copy_description(r); L(@"%@ other %s",tag,d?d:"?"); if(d)free(d);
}
static void probe(NSString *svc, NSString *tag, uint64_t flags){
  xpc_connection_t c=xpc_connection_create_mach_service(svc.UTF8String,NULL,flags);
  tag=[NSString stringWithFormat:@"%@/f%llu",tag,(unsigned long long)flags];
  if(!c){L(@"%@ no conn",tag);return;}
  xpc_connection_set_event_handler(c,^(xpc_object_t e){ if(xpc_get_type(e)==&_xpc_type_error) L(@"%@ evt %s",tag,xpc_dictionary_get_string(e,"XPCErrorDescription")); });
  xpc_connection_resume(c);
  xpc_object_t m=xpc_dictionary_create(NULL,NULL,0);
  xpc_dictionary_set_uint64(m,"type",1);
  xpc_connection_send_message_with_reply(c,m,dispatch_get_main_queue(),^(xpc_object_t r){dump(r,[tag stringByAppendingString:@"/reply"]);});
  xpc_release(m); xpc_release(c);
}
@interface AppDelegate : UIResponder <UIApplicationDelegate> @property (nonatomic) UIWindow *window; @end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)o{
  G=[NSMutableString new];
  P=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES).firstObject stringByAppendingPathComponent:@"mda.log"];
  L(@"mda probe %@",[[UIDevice currentDevice] systemVersion]);
  for(NSString *s in @[@"com.apple.mobile.installd", @"com.apple.containermanagerd", @"com.apple.mobile.containermanager", @"com.apple.installcoordinationd", @"com.apple.distnoted.xpc.daemon", @"com.apple.backboardd", @"com.apple.springboard.services", @"com.apple.frontboard.systemappservices", @"com.apple.assetsd", @"com.apple.photoanalysisd", @"com.apple.parsecd", @"com.apple.suggestd", @"com.apple.spotlight", @"com.apple.nsurlsessiond", @"com.apple.cfnetwork.NSURLSessionProxyService", @"com.apple.symptomd", @"com.apple.sysdiagnose", @"com.apple.rapport", @"com.apple.identityservicesd", @"com.apple.cloudd", @"com.apple.FileCoordination", @"com.apple.fseventsd", @"com.apple.diskarbitrationd", @"com.apple.securityd", @"com.apple.trustd", @"com.apple.apsd", @"com.apple.powerd", @"com.apple.wifi.manager", @"com.apple.locationd.registration", @"com.apple.corelocation.locationd", @"com.apple.aggregated"])
    for(uint64_t f=0;f<3;f+=2) probe(s,s,f);
  L(@"queued");
  dispatch_after(dispatch_time(DISPATCH_TIME_NOW,4ull*NSEC_PER_SEC),dispatch_get_main_queue(),^{
    L(@"done");
    UIViewController *vc=[UIViewController new];
    UITextView *tv=[[UITextView alloc] initWithFrame:vc.view.bounds]; tv.text=G; tv.editable=NO; [vc.view addSubview:tv];
    self.window=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.window.rootViewController=vc; [self.window makeKeyAndVisible];
  });
  return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,@"AppDelegate");}}
