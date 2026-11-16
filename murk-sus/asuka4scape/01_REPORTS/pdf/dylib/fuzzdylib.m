// Injected harness: renders an embedded PDF, logs, exits.
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#include "pdf_bytes.h"

static void run_pdf(void)
{
    @autoreleasepool {
        NSData *data = [NSData dataWithBytes:_home_femboychik_work_pdf_poc_type5_64_pdf
                                      length:_home_femboychik_work_pdf_poc_type5_64_pdf_len];
        CGDataProviderRef prov = CGDataProviderCreateWithCFData((__bridge CFDataRef)data);
        CGPDFDocumentRef doc = CGPDFDocumentCreateWithProvider(prov);
        NSLog(@"[PDFPROBE] doc=%p size=%lu", doc, (unsigned long)data.length);
        if (doc) {
            CGPDFPageRef page = CGPDFDocumentGetPage(doc, 1);
            CGColorSpaceRef cs = CGColorSpaceCreateDeviceRGB();
            CGContextRef ctx = CGBitmapContextCreate(NULL, 300, 300, 8, 0, cs, kCGImageAlphaPremultipliedLast);
            if (ctx) {
                CGContextDrawPDFPage(ctx, page);
                CGContextRelease(ctx);
                NSLog(@"[PDFPROBE] rendered OK");
            }
            CGColorSpaceRelease(cs);
            CGPDFDocumentRelease(doc);
        }
        CGDataProviderRelease(prov);
        NSLog(@"[PDFPROBE] done");
    }
}

__attribute__((constructor))
static void init_probe(void)
{
    NSLog(@"[PDFPROBE] dylib loaded");
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)),
                   dispatch_get_global_queue(0, 0), ^{ run_pdf(); });
}
