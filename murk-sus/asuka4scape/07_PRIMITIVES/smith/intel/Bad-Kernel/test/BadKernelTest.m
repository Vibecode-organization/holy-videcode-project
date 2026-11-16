//  BadKernelTest.m
//  Standalone test binary for BadKernel exploit
//
//  Builds and runs outside of Dopamine to verify exploit phases.
//  Usage: ./BadKernelTest

#import <Foundation/Foundation.h>
#include <stdio.h>
#include <string.h>
#include "BadKernel.h"

// Custom logger that prints with colors
static void colored_log(const char *msg) {
    // Detect phase from prefix
    if (strstr(msg, "[+]")) {
        printf("\033[32m%s\033[0m\n", msg); // Green for success
    } else if (strstr(msg, "[-]") || strstr(msg, "[!]")) {
        printf("\033[31m%s\033[0m\n", msg); // Red for errors
    } else if (strstr(msg, "═══") || strstr(msg, "╔") || strstr(msg, "╚") || strstr(msg, "║")) {
        printf("\033[36m%s\033[0m\n", msg); // Cyan for banners
    } else {
        printf("\033[33m%s\033[0m\n", msg); // Yellow for info
    }
}

int main(int __attribute__((unused)) argc, const char *__attribute__((unused)) argv[]) {
    @autoreleasepool {
        printf("\n");
        printf("  ╔══════════════════════════════════════════╗\n");
        printf("  ║  BadKernel Test Suite                    ║\n");
        printf("  ║  Standalone exploit verification         ║\n");
        printf("  ╚══════════════════════════════════════════╝\n\n");

        // Initialize exploit
        printf("[TEST] Initializing BadKernel...\n\n");
        int ret = BadKernelInitWithLog(colored_log);
        printf("\n[TEST] Init returned: %d\n\n", ret);

        // Check status
        printf("[TEST] Is ready: %s\n", BadKernelIsReady() ? "YES" : "NO");
        printf("[TEST] Kernel base: %#llx\n", BadKernelGetBase());
        printf("[TEST] Kernel slide: %#llx\n\n", BadKernelGetSlide());

        // Test kernel read if ready
        if (BadKernelIsReady() && BadKernelGetBase() != 0) {
            printf("[TEST] Testing kernel read at base...\n");
            uint64_t magic = BadKernelKRead64(BadKernelGetBase());
            printf("[TEST] First 8 bytes at kernel base: %#llx\n", magic);

            // MH_MAGIC_64 check
            if ((magic & 0xFFFFFFFF) == 0xFEEDFACF) {
                printf("[TEST] \033[32m[+] Valid Mach-O magic confirmed!\033[0m\n");
            } else {
                printf("[TEST] \033[31m[-] Not a valid Mach-O magic\033[0m\n");
            }

            // Read kernel version string
            uint64_t kernel_slide = BadKernelGetSlide();
            printf("[TEST] Kernel slide: %#llx\n", kernel_slide);

            // Try to read kernel __TEXT segment
            printf("\n[TEST] Reading kernel headers...\n");
            uint32_t mh_magic = BadKernelKRead32(BadKernelGetBase());
            uint32_t mh_cputype = BadKernelKRead32(BadKernelGetBase() + 4);
            uint32_t mh_cpusubtype = BadKernelKRead32(BadKernelGetBase() + 8);
            uint32_t mh_filetype = BadKernelKRead32(BadKernelGetBase() + 12);
            uint32_t mh_ncmds = BadKernelKRead32(BadKernelGetBase() + 16);

            printf("[TEST]   magic:      0x%08X\n", mh_magic);
            printf("[TEST]   cputype:    0x%08X\n", mh_cputype);
            printf("[TEST]   cpusubtype: 0x%08X\n", mh_cpusubtype);
            printf("[TEST]   filetype:   0x%08X\n", mh_filetype);
            printf("[TEST]   ncmds:      %u\n", mh_ncmds);
        } else {
            printf("[TEST] \033[31m[-] Kernel not ready — skipping read tests\033[0m\n");
        }

        // Test sandbox escape
        printf("\n[TEST] Testing sandbox escape...\n");
        int64_t sh = BadKernelSandboxEscape("/var/mobile/Containers/Data/Application");
        if (sh >= 0) {
            printf("[TEST] \033[32m[+] Sandbox escape success: handle=%lld\033[0m\n", sh);
            BadKernelSandboxRelease(sh);
        } else {
            printf("[TEST] \033[31m[-] Sandbox escape failed: %lld\033[0m\n", sh);
        }

        // Cleanup
        printf("\n[TEST] Cleaning up...\n");
        BadKernelDeinit();
        printf("[TEST] Done.\n\n");
    }
    return 0;
}
