#import <UIKit/UIKit.h>
#import "probes.h"
#import "logger.h"
#import "fuzz.h"
#import <unistd.h>

@interface ProbeViewController : UIViewController
@property(nonatomic, strong) UITextView *logView;
@end

@implementation ProbeViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor systemBackgroundColor];
    self.title = @"SPTM 27.2 probe";

    UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];
    [button setTitle:@"Run" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(runAll) forControlEvents:UIControlEventTouchUpInside];
    button.translatesAutoresizingMaskIntoConstraints = NO;

    self.logView = [[UITextView alloc] init];
    self.logView.editable = NO;
    self.logView.font = [UIFont monospacedSystemFontOfSize:11 weight:UIFontWeightRegular];
    self.logView.translatesAutoresizingMaskIntoConstraints = NO;
    self.logView.text = @"Target: iPhone14,7 / iOS 27.2 (24B115)\n"
        "Read-only probes. No unknown physical memory is dereferenced.\n";

    UIButton *fuzzIO = [UIButton buttonWithType:UIButtonTypeSystem];
    [fuzzIO setTitle:@"FUZZ IOSurface" forState:UIControlStateNormal];
    [fuzzIO addTarget:self action:@selector(runFuzzIOS) forControlEvents:UIControlEventTouchUpInside];
    fuzzIO.translatesAutoresizingMaskIntoConstraints = NO;

    UIButton *fuzzSC = [UIButton buttonWithType:UIButtonTypeSystem];
    [fuzzSC setTitle:@"FUZZ Scaler" forState:UIControlStateNormal];
    [fuzzSC addTarget:self action:@selector(runFuzzSC) forControlEvents:UIControlEventTouchUpInside];
    fuzzSC.translatesAutoresizingMaskIntoConstraints = NO;

    [self.view addSubview:button];
    [self.view addSubview:fuzzIO];
    [self.view addSubview:fuzzSC];
    [self.view addSubview:self.logView];
    UILayoutGuide *guide = self.view.safeAreaLayoutGuide;
    [NSLayoutConstraint activateConstraints:@[
        [button.topAnchor constraintEqualToAnchor:guide.topAnchor constant:12],
        [button.leadingAnchor constraintEqualToAnchor:guide.leadingAnchor constant:12],
        [button.trailingAnchor constraintEqualToAnchor:guide.trailingAnchor constant:-12],
        [button.heightAnchor constraintEqualToConstant:44],
        [fuzzIO.topAnchor constraintEqualToAnchor:button.bottomAnchor constant:4],
        [fuzzIO.leadingAnchor constraintEqualToAnchor:guide.leadingAnchor constant:12],
        [fuzzIO.trailingAnchor constraintEqualToAnchor:guide.trailingAnchor constant:-12],
        [fuzzIO.heightAnchor constraintEqualToConstant:36],
        [fuzzSC.topAnchor constraintEqualToAnchor:fuzzIO.bottomAnchor constant:4],
        [fuzzSC.leadingAnchor constraintEqualToAnchor:guide.leadingAnchor constant:12],
        [fuzzSC.trailingAnchor constraintEqualToAnchor:guide.trailingAnchor constant:-12],
        [fuzzSC.heightAnchor constraintEqualToConstant:36],
        [self.logView.topAnchor constraintEqualToAnchor:fuzzSC.bottomAnchor constant:8],
        [self.logView.leadingAnchor constraintEqualToAnchor:guide.leadingAnchor constant:12],
        [self.logView.trailingAnchor constraintEqualToAnchor:guide.trailingAnchor constant:-12],
        [self.logView.bottomAnchor constraintEqualToAnchor:guide.bottomAnchor constant:-12],
    ]];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    if (self.logView.text.length < 200) {
        [self runAll];
    }
}

- (void)runFuzzIOS
{
    log_write(@"app: fuzz IOSurface begin");
    self.logView.text = @"fuzz IOSurface running...";
    __weak ProbeViewController *weakSelf = self;
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
        NSString *r = fuzz_iosurface(3);
        log_write(@"app: fuzz IOSurface done");
        dispatch_async(dispatch_get_main_queue(), ^{
            weakSelf.logView.text = [NSString stringWithFormat:@"last: %@\n%@",
                fuzz_last_config_path(), r];
            [weakSelf runFuzzSC];
        });
    });
}

- (void)runFuzzSC
{
    log_write(@"app: fuzz Scaler begin");
    self.logView.text = @"fuzz Scaler running...";
    __weak ProbeViewController *weakSelf = self;
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
        NSString *r = fuzz_scaler(2);
        NSString *t = scaler_targeted_probe();
        log_write(@"app: fuzz Scaler done");
        dispatch_async(dispatch_get_main_queue(), ^{
            weakSelf.logView.text = [NSString stringWithFormat:@"last: %@\n%@\n%@",
                fuzz_last_config_path(), r, t];
        });
    });
}

- (void)runAll
{
    NSString *logPath = log_start();
    log_write(@"app: runAll begin");
    self.logView.text = [NSString stringWithFormat:@"running...\nlog: %@", logPath];
    __weak ProbeViewController *weakSelf = self;
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
        NSMutableArray<NSString *> *out = [NSMutableArray array];
        log_write(@"phase: identity");
        void (^step)(NSString *) = ^(NSString *name) {
            log_write(@"STEP: %@", name);
            dispatch_async(dispatch_get_main_queue(), ^{
                weakSelf.logView.text = [NSString stringWithFormat:@"STEP: %@\n\n%@",
                    name, [out componentsJoinedByString:@"\n"]];
            });
            usleep(150000);
        };
        step(@"identity");
        { NSString *r = run_identity_probe(); [out addObject:r]; log_write(@"identity result:\n%@", r); }
        step(@"gpu client");
        { NSString *r = run_gpu_probe(); [out addObject:r]; log_write(@"gpu result:\n%@", r); }
        step(@"metal device + ports");
        { NSString *r = run_metal_probe(); [out addObject:r]; log_write(@"metal result:\n%@", r); }
        step(@"device tree");
        { NSString *r = run_devicetree_probe(); [out addObject:r]; log_write(@"dt result:\n%@", r); }
        step(@"memory regions");
        { NSString *r = run_region_probe(); [out addObject:r]; log_write(@"region result:\n%@", r); }
        step(@"iosurface address");
        { NSString *r = run_address_probe(); [out addObject:r]; log_write(@"addr result:\n%@", r); }
        step(@"compressed geometry");
        { NSString *r = run_surface_probes(); [out addObject:r]; log_write(@"compressed result:\n%@", r); }
        step(@"done");
        log_write(@"app: runAll done");
        dispatch_async(dispatch_get_main_queue(), ^{
            weakSelf.logView.text = [NSString stringWithFormat:@"log: %@\n\n%@",
                logPath, [out componentsJoinedByString:@"\n"]];
            [weakSelf runFuzzIOS];
        });
    });
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
