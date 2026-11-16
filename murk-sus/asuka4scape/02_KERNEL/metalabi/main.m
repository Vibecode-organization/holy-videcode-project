#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <IOSurface/IOSurfaceRef.h>
#import <Metal/Metal.h>
#import <objc/message.h>
#import <stdio.h>
#import <stdarg.h>
#import <unistd.h>
#import <fcntl.h>
#import <string.h>
#import <stdlib.h>
#import <dlfcn.h>
static int g_fd=-1; static char g_path[512];
static void ip_open(void){if(g_fd>=0)return;const char*h=getenv("HOME");snprintf(g_path,sizeof(g_path),"%s/Documents/abi.log",h?h:".");g_fd=open(g_path,O_WRONLY|O_CREAT|O_APPEND,0644);}
static void ip(const char*fmt,...){ip_open();if(g_fd<0)return;char b[4096];va_list ap;va_start(ap,fmt);int n=vsnprintf(b,sizeof(b),fmt,ap);va_end(ap);if(n>0)write(g_fd,b,n);}
static kern_return_t (*o_iccm)(io_connect_t,uint32_t,const uint64_t*,uint32_t,const void*,size_t,uint64_t*,uint32_t*,void*,size_t*);
static kern_return_t (*o_iccs)(io_connect_t,uint32_t,const void*,size_t,void*,size_t*);
static kern_return_t (*o_iccm_a)(io_connect_t,uint32_t,const uint64_t*,uint32_t,const void*,size_t,mach_port_t,uint32_t,const void*,size_t);
static void dumphex(const char*tag,const void*p,size_t n){ip(" %s:",tag);const uint8_t*b=p;for(size_t i=0;i<n&&i<0x400;i++)ip("%02x",b[i]);ip("\n");}
static kern_return_t my_iccm(io_connect_t c,uint32_t sel,const uint64_t*si,uint32_t sic,const void*str,size_t sz,uint64_t*so,uint32_t*soc,void*stro,size_t*sosz){
 kern_return_t kr=o_iccm(c,sel,si,sic,str,sz,so,soc,stro,sosz);
 if(sel>=6&&sel<=54){ip("[ICCM] c=0x%x sel=%u sic=%u sz=0x%zx -> 0x%x",c,sel,sic,sz,kr);for(uint32_t i=0;i<sic&&i<16;i++)ip(" si%u=0x%llx",i,(unsigned long long)si[i]);if(so&&soc)for(uint32_t i=0;i<*soc&&i<8;i++)ip(" so%u=0x%llx",i,(unsigned long long)so[i]);ip("\n");if(str&&sz&&sz<=0x1000)dumphex("str",str,sz);}
 return kr;
}
static kern_return_t my_iccs(io_connect_t c,uint32_t sel,const void*in,size_t insz,void*out,size_t*outsz){
 kern_return_t kr=o_iccs(c,sel,in,insz,out,outsz);
 if(sel>=6&&sel<=54){ip("[ICCS] c=0x%x sel=%u insz=0x%zx -> 0x%x",c,sel,insz,kr);if(out&&outsz)ip(" outsz=0x%zx",*outsz);ip("\n");if(in&&insz&&insz<=0x1000)dumphex("in",in,insz);if(out&&outsz&&*outsz<=0x1000&&kr==0)dumphex("out",out,*outsz);}
 return kr;
}
static kern_return_t my_iccm_a(io_connect_t c,uint32_t sel,const uint64_t*si,uint32_t sic,const void*str,size_t sz,mach_port_t w,uint32_t ref,const void*rc,size_t rsz){
 kern_return_t kr=o_iccm_a(c,sel,si,sic,str,sz,w,ref,rc,rsz);
 if(sel>=6&&sel<=54){ip("[ICCMA] c=0x%x sel=%u sic=%u sz=0x%zx -> 0x%x\n",c,sel,sic,sz,kr);if(str&&sz&&sz<=0x1000)dumphex("strA",str,sz);}
 return kr;
}
#define DYLD_INTERPOSE(_r,_x) __attribute__((used)) static struct { const void *replacement; const void *replacee; } _interpose_##_x __attribute__((section("__DATA,__interpose"))) = { (const void*)(unsigned long)&_r, (const void*)(unsigned long)&_x };
DYLD_INTERPOSE(my_iccm,IOConnectCallMethod)
DYLD_INTERPOSE(my_iccs,IOConnectCallStructMethod)
DYLD_INTERPOSE(my_iccm_a,IOConnectCallAsyncMethod)
static void run(void){
 o_iccm=(void*)dlsym(RTLD_NEXT,"IOConnectCallMethod"); o_iccs=(void*)dlsym(RTLD_NEXT,"IOConnectCallStructMethod"); o_iccm_a=(void*)dlsym(RTLD_NEXT,"IOConnectCallAsyncMethod");
 unlink(g_path);
 ip("=== MetalABI start ===\n");
 @autoreleasepool{
  id<MTLDevice> d=MTLCreateSystemDefaultDevice(); ip("[dev] %p %@\n",d,d?[d name]:@"nil");
  id<MTLCommandQueue> q=[d newCommandQueue]; ip("[queue] %p\n",q);
  id<MTLBuffer> b1=[d newBufferWithLength:0x4000 options:MTLResourceStorageModeShared]; ip("[buf shared] %p gpu=0x%llx\n",b1,(unsigned long long)[b1 gpuAddress]);
  id<MTLBuffer> b2=[d newBufferWithLength:0x4000 options:MTLResourceStorageModePrivate]; ip("[buf priv] %p gpu=0x%llx\n",b2,(unsigned long long)[b2 gpuAddress]);
  MTLTextureDescriptor*td=[MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatBGRA8Unorm width:64 height:64 mipmapped:NO];
  id<MTLTexture> t=[d newTextureWithDescriptor:td]; ip("[tex] %p gpu?%llu\n",t,(unsigned long long)t.usage);
  NSDictionary*pd=@{(id)kIOSurfaceWidth:@64,(id)kIOSurfaceHeight:@64,(id)kIOSurfaceBytesPerElement:@4,(id)kIOSurfacePixelFormat:@0x42475241};
  IOSurfaceRef sf=IOSurfaceCreate((__bridge CFDictionaryRef)pd); ip("[surface] %p id=%u base=%p\n",sf,sf?IOSurfaceGetID(sf):0,sf?IOSurfaceGetBaseAddress(sf):0);
  if(sf){id<MTLBuffer> b3=[d newBufferWithBytesNoCopy:IOSurfaceGetBaseAddress(sf) length:0x4000 options:MTLResourceStorageModeShared deallocator:nil];ip("[buf surface] %p gpu=0x%llx\n",b3,(unsigned long long)[b3 gpuAddress]);}
  NSDictionary*pp=@{@"IOSurfaceAllocSize":@0x4000,@"IOSurfaceMemoryRegion":@"PurpleGfxMem"};
  IOSurfaceRef pf=IOSurfaceCreate((__bridge CFDictionaryRef)pp); ip("[purple] %p base=%p alloc=0x%zx\n",pf,pf?IOSurfaceGetBaseAddress(pf):0,pf?IOSurfaceGetAllocSize(pf):0);
  if(pf){id<MTLBuffer> b4=[d newBufferWithBytesNoCopy:IOSurfaceGetBaseAddress(pf) length:0x4000 options:MTLResourceStorageModeShared deallocator:nil];ip("[buf purple] %p gpu=0x%llx\n",b4,(unsigned long long)[b4 gpuAddress]);}
  id<MTLCommandBuffer> cb=[q commandBuffer]; [cb commit]; [cb waitUntilCompleted]; ip("[cb] status=%ld\n",(long)cb.status);
  if(sf)CFRelease(sf); if(pf)CFRelease(pf);
 }
 ip("=== done ===\n");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"MetalABI\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{run();dispatch_async(dispatch_get_main_queue(),^{tv.text=@"done";});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
