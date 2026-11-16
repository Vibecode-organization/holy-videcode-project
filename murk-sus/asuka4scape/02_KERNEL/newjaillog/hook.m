#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <objc/runtime.h>
#import <objc/message.h>

static void nj_log(NSString *s)
{
    NSString *path = [NSTemporaryDirectory() stringByAppendingPathComponent:@"newjail.log"];
    FILE *f = fopen(path.fileSystemRepresentation, "a");
    if (!f) return;
    fprintf(f, "%s\n", s.UTF8String ?: "");
    fflush(f);
    fsync(fileno(f));
    fclose(f);
}

static void nj_appendLog(id self, SEL _cmd, NSString *msg)
{
    nj_log([NSString stringWithFormat:@"[append] %@", msg ?: @""]);
}

static void nj_swizzle(Class c, SEL sel, IMP imp)
{
    Method m = class_getInstanceMethod(c, sel);
    if (!m) {
        nj_log([NSString stringWithFormat:@"no method %@", NSStringFromSelector(sel)]);
        return;
    }
    class_addMethod(c, sel, imp, method_getTypeEncoding(m));
    method_setImplementation(m, imp);
}

__attribute__((constructor)) static void nj_init(void)
{
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)),
                   dispatch_get_main_queue(), ^{
        nj_log(@"=== NewjailLog loaded ===");
        Class c = objc_getClass("JBViewController");
        if (!c) {
            nj_log(@"no JBViewController");
            return;
        }
        nj_swizzle(c, NSSelectorFromString(@"appendLog:"), (IMP)nj_appendLog);
        nj_log(@"appendLog hooked");

        UIWindow *w = UIApplication.sharedApplication.keyWindow;
        id vc = w.rootViewController;
        nj_log([NSString stringWithFormat:@"rootVC=%@", vc]);
        SEL run = NSSelectorFromString(@"runFullChain");
        if (vc && [vc respondsToSelector:run]) {
            nj_log(@"calling runFullChain");
            ((void (*)(id, SEL))objc_msgSend)(vc, run);
        } else {
            nj_log(@"no runFullChain");
        }
    });
}
