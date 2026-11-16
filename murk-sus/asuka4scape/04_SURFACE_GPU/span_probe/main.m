#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

static NSMutableString *gLog;
static NSString *gPath;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    [gLog appendFormat:@"%@\n", s];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:NULL];
    NSLog(@"[SPAN] %@", s);
}

static void try_html(NSString *tag, NSString *html) {
    NSData *d = [html dataUsingEncoding:NSUTF8StringEncoding];
    NSDictionary *opts = @{ NSDocumentTypeDocumentAttribute: NSHTMLTextDocumentType };
    NSDate *t0 = [NSDate date];
    NSMutableAttributedString *as = nil;
    @try {
        as = [[NSMutableAttributedString alloc] initWithData:d options:opts
                                          documentAttributes:NULL error:NULL];
    } @catch (NSException *e) {
        L(@"%@ EXC %@: %@", tag, e.name, e.reason);
        return;
    }
    double dt = -[t0 timeIntervalSinceNow];
    L(@"%@ ok len=%lu dt=%.3f", tag, (unsigned long)as.length, dt);
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic) UIWindow *window;
@property (nonatomic) UITextView *tv;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)o {
    gLog = [NSMutableString new];
    gPath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject
             stringByAppendingPathComponent:@"span.log"];
    L(@"span probe start os=%@", [[UIDevice currentDevice] systemVersion]);

    try_html(@"small", @"<table><tr><td colspan=2 rowspan=2>x</td></tr></table>");
    try_html(@"c8192",  @"<table><tr><td colspan=8192 rowspan=8192>x</td></tr></table>");
    try_html(@"c65536", @"<table><tr><td colspan=65536 rowspan=65536>x</td></tr></table>");
    try_html(@"c1M",    @"<table><tr><td colspan=1048576 rowspan=1048576>x</td></tr></table>");
    try_html(@"cMAX",   @"<table><tr><td colspan=2147483647 rowspan=2147483647>x</td></tr></table>");
    try_html(@"many",   @"<table><tr><td colspan=2147483647>x</td><td rowspan=2147483647>y</td></tr></table>");
    L(@"span probe done");

    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new];
    self.tv = [[UITextView alloc] initWithFrame:vc.view.bounds];
    self.tv.text = gLog; self.tv.editable = NO;
    [vc.view addSubview:self.tv];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    return YES;
}
@end

int main(int argc, char **argv) {
    @autoreleasepool { return UIApplicationMain(argc, argv, nil, @"AppDelegate"); }
}
