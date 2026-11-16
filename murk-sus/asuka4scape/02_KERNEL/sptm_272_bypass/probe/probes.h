#ifndef PROBES_H
#define PROBES_H

#import <Foundation/Foundation.h>

NSString *run_surface_probes(void);
NSString *run_address_probe(void);
NSString *run_devicetree_probe(void);
NSString *run_iokit_probe(void);
NSString *run_identity_probe(void);
NSString *run_gpu_probe(void);
NSString *run_metal_probe(void);
NSString *run_region_probe(void);
NSString *run_all_probes(void);

#endif
