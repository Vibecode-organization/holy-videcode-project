#import <UIKit/UIKit.h>
#import "surface_probes.h"

@interface ProbeViewController : UIViewController
@property(nonatomic, strong) UITextView *logView;
@end

@implementation ProbeViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor systemBackgroundColor];
    self.title = @"KRW27 research";

    UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];
    [button setTitle:@"Run IOSurface parser probes" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(runProbes) forControlEvents:UIControlEventTouchUpInside];
    button.translatesAutoresizingMaskIntoConstraints = NO;

    self.logView = [[UITextView alloc] init];
    self.logView.editable = NO;
    self.logView.font = [UIFont monospacedSystemFontOfSize:12 weight:UIFontWeightRegular];
    self.logView.translatesAutoresizingMaskIntoConstraints = NO;
    self.logView.text = @"Target: iPhone14,7 / iOS 27.2 (24B115)\n"
        "Step 1 validates the 32-bit geometry checks; no memory access is triggered.\n";

    [self.view addSubview:button];
    [self.view addSubview:self.logView];
    UILayoutGuide *guide = self.view.safeAreaLayoutGuide;
    [NSLayoutConstraint activateConstraints:@[
        [button.topAnchor constraintEqualToAnchor:guide.topAnchor constant:16],
        [button.leadingAnchor constraintEqualToAnchor:guide.leadingAnchor constant:16],
        [button.trailingAnchor constraintEqualToAnchor:guide.trailingAnchor constant:-16],
        [button.heightAnchor constraintEqualToConstant:48],
        [self.logView.topAnchor constraintEqualToAnchor:button.bottomAnchor constant:16],
        [self.logView.leadingAnchor constraintEqualToAnchor:guide.leadingAnchor constant:16],
        [self.logView.trailingAnchor constraintEqualToAnchor:guide.trailingAnchor constant:-16],
        [self.logView.bottomAnchor constraintEqualToAnchor:guide.bottomAnchor constant:-16],
    ]];
}

- (void)runProbes
{
    self.logView.text = [run_surface_probes() copy];
}

@end

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property(nonatomic, strong) UIWindow *window;
@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application
    didFinishLaunchingWithOptions:(NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.window.rootViewController = [[UINavigationController alloc]
        initWithRootViewController:[[ProbeViewController alloc] init]];
    [self.window makeKeyAndVisible];
    return YES;
}

@end

int main(int argc, char *argv[])
{
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
