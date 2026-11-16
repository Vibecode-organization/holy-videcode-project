#import <UIKit/UIKit.h>

static const CGFloat kWhaleSize = 64.0;

static NSString *const kWhaleBase64 =
    @"iVBORw0KGgoAAAANSUhEUgAAAGAAAABgAgMAAACf9p+rAAAACVBMVEUAAABNa/4AAAC4/te6AAAAA3RSTlMA/wBpUjmsAAAB0UlEQVR42u2VPZKcMBCFP7UhJ4DcR9ENPAFzSk/gyHEHvg0E5KsqOVCjP5hka8NVACqeXr9W67WA7/HpMdpbemC6Au65AvgLsDZMA5aVBfZCYABwKzwBrUTkEiSltUiVoY0HgJcqw4riEHC+24qHmcH00xe1Ha0gdSSbTWvKyvd1ckAUXBtdLbZUEk1+0iQ7wJFmoS17lbng29MIaXJ0B5UFVVy37WjPjuGs9gEZ+jrtAMfFDBMRiIpMd+7Zb+zjHWwKAtur95UCQtT46mJ5QHyA+IeLvZLGRzq6mmrieyppTAu0nId9OYteefcAGH24AB8AzPECoKmyejmAAwj/SuUzIwCjL+rZPrHgXUcpdx1lIo54skRPm4R3jAjwcNz3+bieVajaoFWXo1EvK6RsPrwR77woIXdOvDB8qx7ehTJGLPke9Uu4pKUGaG7YJgfhwAFu6dKSvNrnnjEgmPpssscJRBgh4myx5lBqsR6pmZpaTaAMoOUOEDiswVyKP2cgnPfgg1CujSFFHZ/AkATmrKHlilG7xxKwn7tdfNsfpRTLL80n2PojbMqrAHvllO13mv0AYPtpJf/bueSkFKoxjFIRTjNsALxu/2ZP//1L/+rxHyaLhh2oVmbKAAAAAElFTkSuQmCC";

@interface DSPassthroughWindow : UIWindow
@end

@implementation DSPassthroughWindow
- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event {
    UIView *hit = [super hitTest:point withEvent:event];
    return hit == self ? nil : hit;
}
@end

@interface DSWhaleView : UIView
@end

@implementation DSWhaleView
- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (!self) return nil;

    self.backgroundColor = UIColor.clearColor;
    self.isAccessibilityElement = NO;

    NSData *data = [[NSData alloc] initWithBase64EncodedString:kWhaleBase64 options:0];
    UIImage *image = [UIImage imageWithData:data scale:1.5];

    UIImageView *imageView = [[UIImageView alloc] initWithImage:image];
    imageView.frame = self.bounds;
    imageView.contentMode = UIViewContentModeScaleAspectFit;
    imageView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    imageView.userInteractionEnabled = NO;
    [self addSubview:imageView];

    return self;
}
@end

@interface DSDragHandler : NSObject
- (void)handlePan:(UIPanGestureRecognizer *)pan;
@end

@implementation DSDragHandler
- (void)handlePan:(UIPanGestureRecognizer *)pan {
    UIView *view = pan.view;
    UIView *container = view.superview;
    CGPoint translation = [pan translationInView:container];

    CGPoint center = CGPointMake(view.center.x + translation.x, view.center.y + translation.y);

    UIEdgeInsets safe = container.safeAreaInsets;
    CGRect bounds = container.bounds;
    CGFloat half = kWhaleSize / 2.0;

    center.x = MAX(half + safe.left,  MIN(bounds.size.width  - half - safe.right,  center.x));
    center.y = MAX(half + safe.top,   MIN(bounds.size.height - half - safe.bottom, center.y));

    view.center = center;
    [pan setTranslation:CGPointZero inView:container];
}
@end

static DSPassthroughWindow *sWindow = nil;
static DSWhaleView *sWhale = nil;
static DSDragHandler *sDragHandler = nil;

static void DSInstall(void) {
    if (sWindow) return;

    UIWindow *window = nil;

    if (@available(iOS 13.0, *)) {
        UIWindowScene *activeScene = nil;
        for (UIScene *scene in UIApplication.sharedApplication.connectedScenes) {
            if ([scene isKindOfClass:[UIWindowScene class]] &&
                scene.activationState == UISceneActivationStateForegroundActive) {
                activeScene = (UIWindowScene *)scene;
                break;
            }
        }
        if (!activeScene) return;
        window = [[DSPassthroughWindow alloc] initWithWindowScene:activeScene];
    } else {
        window = [[DSPassthroughWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
    }

    window.windowLevel = UIWindowLevelStatusBar + 100;
    window.backgroundColor = UIColor.clearColor;
    window.hidden = NO;
    sWindow = (DSPassthroughWindow *)window;

    sDragHandler = [DSDragHandler new];

    sWhale = [[DSWhaleView alloc] initWithFrame:CGRectMake(
        window.bounds.size.width - kWhaleSize - 16,
        window.bounds.size.height / 2.0,
        kWhaleSize,
        kWhaleSize)];

    UIPanGestureRecognizer *pan =
        [[UIPanGestureRecognizer alloc] initWithTarget:sDragHandler action:@selector(handlePan:)];
    pan.maximumNumberOfTouches = 1;
    [sWhale addGestureRecognizer:pan];

    [sWindow addSubview:sWhale];
}

__attribute__((constructor))
static void DSInit(void) {
    NSNotificationCenter *center = NSNotificationCenter.defaultCenter;
    NSOperationQueue *mainQueue = NSOperationQueue.mainQueue;

    [center addObserverForName:UIApplicationDidBecomeActiveNotification
                        object:nil
                         queue:mainQueue
                    usingBlock:^(NSNotification *note) { DSInstall(); }];

    if (@available(iOS 13.0, *)) {
        [center addObserverForName:UISceneDidActivateNotification
                            object:nil
                             queue:mainQueue
                        usingBlock:^(NSNotification *note) { DSInstall(); }];
    }

    dispatch_async(dispatch_get_main_queue(), ^{
        DSInstall();
    });
}
