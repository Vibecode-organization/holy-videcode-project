#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreText/CoreText.h>
#import <dlfcn.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[fc] %@",s);}
static void run(void){
 NSArray*fams=[UIFont familyNames];NSArray*mc=[fams filteredArrayUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(NSString*f,NSDictionary*d){return [f.lowercaseString containsString:@"minecraft"];}]];L(@"[families] count=%zu minecraft=%@",fams.count,mc);
 CFArrayRef names=CTFontManagerCopyAvailablePostScriptNames();if(names){NSArray*a=(__bridge_transfer NSArray*)names;NSArray*m=[a filteredArrayUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(NSString*f,NSDictionary*d){return [f.lowercaseString containsString:@"minecraft"];}]];L(@"[psnames] count=%zu minecraft=%@",a.count,m);}
 void*h=dlopen("/System/Library/PrivateFrameworks/FontServices.framework/FontServices",RTLD_NOW);L(@"[fsdl] %p %s",h,h?dlerror():"");Class cls=NSClassFromString(@"FSUserFontManager");L(@"[fscls] %p",cls);
 if(cls){SEL s=NSSelectorFromString(@"userFontsInfo");if([cls respondsToSelector:s]){IMP imp=[cls methodForSelector:s];id info=((id(*)(id,SEL))imp)(cls,s);L(@"[userinfo] %@",info);}SEL r=NSSelectorFromString(@"registeredFontsInfoForIdentifier:enabled:");if([cls respondsToSelector:r]){IMP imp=[cls methodForSelector:r];id info=((id(*)(id,SEL,NSString*,BOOL))imp)(cls,r,[[NSBundle mainBundle] bundleIdentifier],YES);L(@"[reginfo] %@",info);}}
 NSArray*uf=[[NSFileManager defaultManager] contentsOfDirectoryAtPath:@"/var/mobile/Library/UserFonts" error:nil];L(@"[userfonts] %@",uf);NSArray*gf=[[NSFileManager defaultManager] contentsOfDirectoryAtPath:@"/var/mobile/Library/Fonts" error:nil];L(@"[globalfonts] %@",gf);
 L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"FontCheck\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"fc.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
