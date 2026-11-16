#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreText/CoreText.h>
#import <dlfcn.h>
#import <dispatch/dispatch.h>
#import <objc/runtime.h>
@interface FSUserFontManager : NSObject
+ (void)installFonts:(NSArray*)fonts forIdentifier:(NSString*)ident enabled:(BOOL)enabled completionHandler:(void(^)(NSArray*,NSDictionary*))handler;
+ (id)userFontsInfo;
+ (id)registeredFontsInfoForIdentifier:(NSString*)ident enabled:(BOOL)enabled;
@end
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[fs] %@",s);}
static void reg(NSURL*url,CTFontManagerScope scope,const char*tag){
 CFErrorRef err=NULL; bool ok=CTFontManagerRegisterFontsForURL((__bridge CFURLRef)url,scope,&err);
 CFIndex code=err?CFErrorGetCode(err):0; L(@"[%s scope=%u] ok=%d code=%ld err=%@",tag,(unsigned)scope,ok,(long)code,err?(__bridge NSString*)CFErrorCopyDescription(err):@"(null)");
 if(err)CFRelease(err);
}
static void install_via_fontservices(NSURL*url){
 void*h=dlopen("/System/Library/PrivateFrameworks/FontServices.framework/FontServices",RTLD_NOW);L(@"[fsdl] %p %s",h,h?dlerror():"");
 Class cls=NSClassFromString(@"FSUserFontManager");L(@"[fscls] %p",cls);if(!cls)return;
 NSString*bid=[[NSBundle mainBundle] bundleIdentifier];
 SEL sel=NSSelectorFromString(@"installFonts:forIdentifier:enabled:appInfo:completionHandler:");
 L(@"[fssel] responds=%d",[cls respondsToSelector:sel]);
 if([cls respondsToSelector:sel]){
  IMP imp=[cls methodForSelector:sel];
  for(int attempt=0;attempt<2;attempt++){
   __block NSString*result=@"timeout"; __block uintptr_t ra=0,rb=0; dispatch_semaphore_t sem=dispatch_semaphore_create(0);
   void(^handler)(uintptr_t,uintptr_t)=^(uintptr_t a,uintptr_t b){ ra=a; rb=b; result=@"called"; dispatch_semaphore_signal(sem);};
   id appInfo=attempt?@{@"CFBundleIdentifier":bid,@"CFBundleVersion":@"1",@"CFBundleShortVersionString":@"1.0"}:nil;
   ((void(*)(id,SEL,NSArray*,NSString*,BOOL,id,id))imp)(cls,sel,@[url],bid,YES,appInfo,handler);
   long w=dispatch_semaphore_wait(sem,dispatch_time(DISPATCH_TIME_NOW,8*NSEC_PER_SEC));
   L(@"[fsinstall%d] wait=%ld a=0x%llx b=0x%llx",attempt,w,(unsigned long long)ra,(unsigned long long)rb);
  }
 }
 Class sc=NSClassFromString(@"FSUserFontServicesManager");L(@"[fssvc] %p",sc);
 SEL psel=NSSelectorFromString(@"GSFontRegisterPersistentURLs:enabled:forProfileFonts:withReply:");
 if(sc&&[sc respondsToSelector:psel]){IMP pimp=[sc methodForSelector:psel];__block NSString*pr=@"timeout";__block uintptr_t pa=0,pb=0;dispatch_semaphore_t ps=dispatch_semaphore_create(0);void(^rh)(uintptr_t,uintptr_t)=^(uintptr_t a,uintptr_t b){ pa=a; pb=b; pr=@"called"; dispatch_semaphore_signal(ps);};((void(*)(id,SEL,NSArray*,BOOL,BOOL,id))pimp)(sc,psel,@[url],YES,NO,rh);long pw=dispatch_semaphore_wait(ps,dispatch_time(DISPATCH_TIME_NOW,8*NSEC_PER_SEC));L(@"[fspersist] wait=%ld a=0x%llx b=0x%llx",pw,(unsigned long long)pa,(unsigned long long)pb);}
 SEL infosel=NSSelectorFromString(@"registeredFontsInfoForIdentifier:enabled:");if([cls respondsToSelector:infosel]){IMP ii=[cls methodForSelector:infosel];id inf=((id(*)(id,SEL,NSString*,BOOL))ii)(cls,infosel,bid,YES);L(@"[reginfo] %@",inf);}SEL us=NSSelectorFromString(@"userFontsInfo");if([cls respondsToSelector:us]){IMP ui=[cls methodForSelector:us];id inf=((id(*)(id,SEL))ui)(cls,us);L(@"[userinfo] %@",inf);}
}
static void run(void){
 NSString*src=[[NSBundle mainBundle] pathForResource:@"minecraft" ofType:@"ttf"];L(@"[src] %@",src);
 NSString*dst=[NSTemporaryDirectory() stringByAppendingPathComponent:@"minecraft.ttf"];[[NSFileManager defaultManager] removeItemAtPath:dst error:nil];BOOL cp=[[NSFileManager defaultManager] copyItemAtPath:src toPath:dst error:nil];L(@"[copy] %d path=%@",cp,dst);
 NSURL*url=[NSURL fileURLWithPath:dst];

 reg(url,1,"process"); install_via_fontservices(url);reg(url,2,"user");reg(url,2,"user2");
 L(@"[families] %@",[[UIFont familyNames] filteredArrayUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(NSString*f,NSDictionary*d){return [f.lowercaseString containsString:@"minecraft"];}]]);
 BOOL exists=[[NSFileManager defaultManager] fileExistsAtPath:@"/var/mobile/Library/Fonts/minecraft.ttf"];L(@"[globalfont] %d",exists);
 L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"FontSys\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"fs.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
