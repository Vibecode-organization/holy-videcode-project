# VCPDRM / com.apple.driver.VideoProcessing — 27.2 (24B115) finding

Status: **static + on-device open probe** (2026-11-08 06:00–06:10 MSK).
New kext in 27.2: `com.apple.driver.VideoProcessing` (bundle name `VCPDRM`,
version 1.0, path `/System/Library/Extensions/VCPDRM.kext`). It is the only
brand-new IOKit driver in the 27.2 kernelcache besides `AFKHIDTBDevice` and
`security.Image4`.

## 1. On-device reachability

Probe app (signed with the normal `app.lake9674.aquila8809` profile,
no private entitlements) matched the service:

```
match VCPDRMService -> 0x4513
  open VCPDRMService type=0 kr=0xe00002e2 conn=0x0   (kIOReturnUnsupported)
  open VCPDRMService type=1 kr=0xe00002bd conn=0x0   (kIOReturnNoMemory)
  open VCPDRMService type=2 kr=0xe00002bd conn=0x0
  open VCPDRMService type=3 kr=0xe00002bd conn=0x0
match VCPDRMServiceUserClient -> 0x0
match VCPDRMUserClient -> 0x0
match com.apple.VCPDirtyDetectionDRMHandler -> 0x0
match VideoProcessingDRM -> 0x0
match AppleVideoToolboxParavirtualizationDriver -> 0x0
match AppleVideoToolboxParavirtualizationUserClient -> 0x0
no VCPDRM user client opened
```

The service is present (its personality is `IOProviderClass = IOResources`,
`IOResourceMatch = IOBSD`, so it starts at boot), but **no user client type is
openable from an ordinary sandboxed app**.

The kext's own Info.plist personality says:

```
VideoProcessingDRM:
  IOClass = VCPDRMService
  IOProviderClass = IOResources
  IOUserClientClass = VCPDRMServiceUserClient
```

The C++ code, however, contains `VCPDRMService` and `VCPDRMUserClient`;
`VCPDRMServiceUserClient` does not appear in the kext code. The default
`IOService::newUserClient` therefore cannot instantiate the class named in the
Info.plist (`0xe00002e2`), while the types 1..3 path returns `NoMemory`.
This looks like a class-name mismatch / dead user-client path in the new kext,
not an entitlement denial (`NotPrivileged` would be `0xe00002c9`).

## 2. User-client dispatch table

`VCPDRMService::newUserClient` (or the helper that creates the client) is at
`0xfffffff009faa6fc`; it only accepts type 0 and logs the
`virtual IOReturn VCPDRMService::newUserClient(...)` string.

The user client's `externalMethod` wrapper is at `0xfffffff009faaeb0`. It
accepts selectors 0..2 (scalar-only) and calls the generic dispatcher with the
table at **`0xfffffff0080de470`**, stride **0x18**
(`IOExternalMethodDispatch` 27.x, 24 bytes):

| sel | handler | scalarIn | structIn | scalarOut | structOut | likely action |
|---|---|---|---|---|---|---|
| 0 | `0xfffffff009fab1e8` | 1 | 0 | 1 | 0 | create mapping from IOSurface ID; returns slot index |
| 1 | `0xfffffff009fab0c0` | 1 | 0 | 0 | 0 | destroy mapping by mapping ID |
| 2 | `0xfffffff009faaf14` | 1 | 0 | 1 | 0 | lookup mapping by mapping ID; returns kernel pointer |

## 3. Mapping table and the unchecked mapping ID

The user-client object is 0x410 bytes (`VCPDRMUserClient`,
`kalloc_type` size 0x410). Its mapping table starts at `this + 0x110`, 16
entries of `0x30` bytes (`0x110..0x410`). Selector 0 scans for a free entry
(`entry+0x8 == NULL`), maps the IOSurface, and stores:

```
+0x00 u32   lock/ref
+0x04 u8    valid flag
+0x08 ptr   retained surface object
+0x10 ptr   retained mapping object
+0x18 u32   width
+0x1c u32   height
+0x20 u64   surface size
+0x28 ptr   mapping payload pointer (returned by selector 2)
```

Selector 0 returns the **0-based slot index**. Selectors 1/2 take the mapping
ID in `scalarInput[0]` and compute

```
entry = this + 0x110 + (id - 1) * 0x30
```

The only check is `id != 0` (`sub id,#0x11; cmn #0x10; b.lo bad`). There is
**no upper bound of 16**. The arm64e `0x2bad...` csel is only a
32-bit-overflow guard for `id * 0x30`, not an array bound. IDs 17 and above
therefore index past the 0x410-byte object into adjacent kernel heap.

Selector 2 then reads the candidate entry's fields and returns
`*(entry+0x28)` in `scalarOutput[0]`. Selector 1 writes zeros / calls
`release` on `entry+0x8`/`entry+0x10`. A privileged process that can open this
user client would therefore have a **heap OOB read** and a potential
**arbitrary release / OOB write** via a controlled adjacent object, plus a
kernel pointer leak from selector 2 on a valid mapping.

Selector 2 also checks the entry's size (`entry+0x20`) against
`1 << (*(u32 *)0xfffffff007bcd918 & 0x1f)` and calls the panic helper
`0xfffffff00aa4d114` ("Specified surface size ... not within expected size")
on mismatch, and panics on a missing mapping pointer. The static value at
`0x7bcd918` is 0; the IOSurface kext presumably initializes it at boot.

## 4. Why it is not a live app primitive

`IOServiceOpen(VCPDRMService, type 0)` never reaches the custom
`VCPDRMService::newUserClient` path: the default dispatcher rejects the
Info.plist class name `VCPDRMServiceUserClient` (`Unsupported`), and types
1..3 fail with `NoMemory`. The actual `VCPDRMUserClient` class is only
reachable if a caller can use the custom newUserClient / a different service
personality; no such path was found from the sandbox. The new kext appears to
be a VideoToolbox/DRM/exclave-internal service, not a public user client.

The kext is useful as a **static lead**: if a privileged context (VideoToolbox
daemon / root / private entitlement) can open the user client, the missing
mapping-ID upper bound is a concrete kernel heap OOB. It is not reachable from
the normal `app.lake9674.aquila8809` profile.

## 5. Artifacts

- Extracted kext: `/tmp/opencode/vp/com.apple.driver.VideoProcessing`
  (65,872 B, SHA-256 to be filled by the next run).
- Probe app/log: `/tmp/opencode/vcpprobe/`, `/tmp/vcplogs/vcp5.log`.
- Ghidra kernelcache project: `/home/femboychik/123` (read-only, 27.2 24B115).
- Key VAs: `newUserClient`/helper `0x9faa6fc`, externalMethod wrapper
  `0x9faaeb0`, dispatch table `0x80de470`, selector 0 `0x9fab1e8`,
  selector 1 `0x9fab0c0`, selector 2 `0x9faaf14`, class name table
  `0x80de3f8`, user-client kalloc type `0x80de4f8`.
- Panic helper used by the size/missing-mapping checks: `0xaa4d114`.

No on-device panic occurred; the probe app exited after logging the open
failures. The BQ272 sandbox probe app was restored afterwards.
