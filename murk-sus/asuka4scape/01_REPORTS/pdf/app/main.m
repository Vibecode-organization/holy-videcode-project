// main.m — PDF shading probe for iOS (Theos app)
// Target: iPhone14,7 / iOS 27.2 RC (24B115)
// Renders bundled Type-5 shading PDFs; on builds without the
// CG-SEC-187882049 range check the shading function evaluation
// writes `range_dim` doubles into a 0x48-byte vertex record.
#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>

static NSString *render_pdf(NSString *name, int iters)
{
    NSMutableString *log = [NSMutableString string];
    NSString *path = [[NSBundle mainBundle] pathForResource:name.stringByDeletingPathExtension
                                                     ofType:name.pathExtension];
    if (!path) { return [NSString stringWithFormat:@"missing %@\n", name]; }
    [log appendFormat:@"%@ → %@\n", name, path.lastPathComponent];
    for (int i = 0; i < iters; i++) {
        @autoreleasepool {
            CFURLRef url = (__bridge CFURLRef)[NSURL fileURLWithPath:path];
            CGPDFDocumentRef doc = CGPDFDocumentCreateWithURL(url);
            if (!doc) { [log appendString:@"  create failed\n"]; break; }
            CGPDFPageRef page = CGPDFDocumentGetPage(doc, 1);
            if (!page) { [log appendString:@"  no page\n"]; CGPDFDocumentRelease(doc); break; }
            CGColorSpaceRef cs = CGColorSpaceCreateDeviceRGB();
            CGContextRef ctx = CGBitmapContextCreate(NULL, 300, 300, 8, 0, cs,
                                                     kCGImageAlphaPremultipliedLast);
            if (ctx) {
                CGContextSetRGBFillColor(ctx, 1, 1, 1, 1);
                CGContextFillRect(ctx, CGRectMake(0, 0, 300, 300));
                CGContextDrawPDFPage(ctx, page);
                CGContextRelease(ctx);
            }
            CGColorSpaceRelease(cs);
            CGPDFDocumentRelease(doc);
            if ((i & 0x3f) == 0) [log appendFormat:@"  iter %d ok\n", i];
        }
    }
    return log;
}

@interface ProbeVC : UIViewController
@property(nonatomic, strong) UITextView *tv;
@end

@implementation ProbeVC
- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor systemBackgroundColor];
    self.title = @"PDFProbe 24B115";
    self.tv = [[UITextView alloc] init];
    self.tv.editable = NO;
    self.tv.font = [UIFont monospacedSystemFontOfSize:11 weight:UIFontWeightRegular];
    self.tv.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:self.tv];
    UILayoutGuide *g = self.view.safeAreaLayoutGuide;
    [NSLayoutConstraint activateConstraints:@[
        [self.tv.topAnchor constraintEqualToAnchor:g.topAnchor],
        [self.tv.leadingAnchor constraintEqualToAnchor:g.leadingAnchor],
        [self.tv.trailingAnchor constraintEqualToAnchor:g.trailingAnchor],
        [self.tv.bottomAnchor constraintEqualToAnchor:g.bottomAnchor],
    ]];
    self.tv.text = @"running…\n";
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)),
                   dispatch_get_main_queue(), ^{ [self run]; });
}

- (void)run
{
    NSMutableString *out = [NSMutableString string];
    [out appendString:render_pdf(@"type5_8.pdf", 1)];
    self.tv.text = out;
    [out appendString:render_pdf(@"type5_32.pdf", 1)];
    self.tv.text = out;
    [out appendString:render_pdf(@"type5_64.pdf", 1)];
    self.tv.text = out;
    [out appendString:render_pdf(@"type5_64.pdf", 200)];
    self.tv.text = out;
    [out appendString:@"done\n"];
    self.tv.text = out;
    NSLog(@"[PDFProbe]\n%@", out);
}
@end

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property(nonatomic, strong) UIWindow *window;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts
{
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.window.rootViewController = [[UINavigationController alloc] initWithRootViewController:[ProbeVC new]];
    [self.window makeKeyAndVisible];
    return YES;
}
@end

int main(int argc, char *argv[])
{
    @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); }
}
