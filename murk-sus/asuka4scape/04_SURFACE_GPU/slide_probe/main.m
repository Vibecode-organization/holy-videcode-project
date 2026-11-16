#import <UIKit/UIKit.h>
#import <mach-o/dyld.h>
#import <mach-o/loader.h>
static NSMutableString *G; static NSString *P;
static void L(NSString *f,...){va_list a;va_start(a,f);NSString*s=[[NSString alloc]initWithFormat:f arguments:a];va_end(a);
 [G appendFormat:@"%@\n",s];[G writeToFile:P atomically:YES encoding:NSUTF8StringEncoding error:NULL];NSLog(@"[SL] %@",s);}
@interface AppDelegate : UIResponder <UIApplicationDelegate> @property (nonatomic) UIWindow *window; @end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)o{
  G=[NSMutableString new];
  P=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES).firstObject stringByAppendingPathComponent:@"slide.log"];
  L(@"slide probe %@",[[UIDevice currentDevice] systemVersion]);
  uint32_t n=_dyld_image_count();
  L(@"images=%u",n);
  for(uint32_t i=0;i<n;i++){
    const char *nm=_dyld_get_image_name(i);
    if(!nm) continue;
    NSString *s=[NSString stringWithUTF8String:nm];
    BOOL want=[s containsString:@"CoreGraphics"]||[s containsString:@"QuartzCore"]||
              [s containsString:@"ImageIO"]||[s containsString:@"Skia"]||
              [s containsString:@"BackBoard"]||i==0;
    if(!want) continue;
    const struct mach_header_64 *h=(const struct mach_header_64*)_dyld_get_image_header(i);
    intptr_t sl=_dyld_get_image_vmaddr_slide(i);
    uint64_t vmaddr=0;
    if(h && h->magic==MH_MAGIC_64){
      const uint8_t *p=(const uint8_t*)(h+1);
      for(uint32_t c=0;c<h->ncmds;c++){
        const struct load_command *lc=(const struct load_command*)p;
        if(lc->cmd==LC_SEGMENT_64){
          const struct segment_command_64 *sg=(const struct segment_command_64*)lc;
          if(strncmp(sg->segname,"__TEXT",6)==0){ vmaddr=sg->vmaddr; break; }
        }
        p+=lc->cmdsize;
      }
    }
    L(@"idx=%u slide=0x%llx vmaddr=0x%llx base=0x%llx %@",i,(unsigned long long)sl,
      (unsigned long long)vmaddr,(unsigned long long)(vmaddr+(uint64_t)sl),s);
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
