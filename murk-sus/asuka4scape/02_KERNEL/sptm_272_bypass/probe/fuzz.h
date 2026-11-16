#ifndef FUZZ_H
#define FUZZ_H

#import <Foundation/Foundation.h>

// Runs the IOSurfaceRoot selector fuzzer. iterations per selector.
NSString *fuzz_iosurface(int iterations);
// Runs the Scaler selector fuzzer. iterations per selector.
NSString *fuzz_scaler(int iterations);
NSString *fuzz_last_config_path(void);
NSString *scaler_targeted_probe(void);

#endif
