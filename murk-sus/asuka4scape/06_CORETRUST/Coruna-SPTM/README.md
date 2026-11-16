# Coruna-SPTM-Bypass-RE
Reverse engineering summary of the SPTM bypass dylib from Coruna chain

## Public Interface
```
// Single export
int _driver(coruna_driver **drv_out);

// Driver vtable (0x50 bytes, all PACIZA-signed)
struct coruna_driver {
    uint32_t version;    // +0x00: 0x20002
    uint32_t pad;        // +0x04
    void    *unk;        // +0x08
    void    *free;       // +0x10: driver_free
    void    *init;       // +0x18: driver_init(drv, 0, &ctx)
    void    *close;      // +0x20: driver_close
    void    *dispatch;   // +0x28: driver_dispatch_command(drv, cmd_struct, arg1, arg2)
    void    *sub_6070;   // +0x30
    void    *sub_60A8;   // +0x38
    void    *sub_60EC;   // +0x40
    void    *sub_6224;   // +0x48
};

// Usage
coruna_driver *drv = NULL;
_driver(&drv);

void *ctx = NULL;
drv->init(drv, 0, &ctx);
// ctx is now the fully initialized 0x1D60-byte internal context
```

## Internal Context (0x1D60 bytes) - Key Offsets
```
// Kernel r/w primitives (PACIZA-signed, callable directly)
+0x30   kread_multipage    // _sub_A354(ctx, addr, buf, size, flag)
+0x38   kread_singlepage   // _sub_A48C(ctx, addr, buf, size, flag) — page boundary checked
+0x40   kwrite_multipage   // _sub_A3F0(ctx, addr, buf, size, flag)
+0x48   kwrite_singlepage  // _sub_A550(ctx, addr, buf, size, flag) — page boundary checked
+0x50   gfx_ctx_ptr        // pointer to 0x5E8-byte GFX context

// Device fingerprint
+0x140  xnu_version        // kernel version word
+0x158  chip_version       // full chip version qword
+0x168  page_shift         // vm_page_shift value
+0x178  core_count_field
+0x180  core_count
+0x188  address_mask       // core_count - 1

// IOGPU / IOKit
+0x1918 iogpu_port         // mach port to AGX service (type 3)
+0x191C iogpu_port_alt
+0x1920 host_priv_port
+0x1924 mach_port_2
+0x1928 host_port
+0x192C registered_thread  // thread port registered for GFX ROP

// File descriptors (all initialized to -1)
+0x1930 fd_0
+0x1934 fd_1
+0x1938 fd_2
+0x193C fd_3
+0x1940 fd_4

// Kernel parsing results
+0x19C8 power_thread_kaddr
+0x19D0 power_thread_ptr
+0x19D8 kernel_base_ptr
+0x19E0 kernel_slide
+0x19E8 kernel_base
+0x19F0 kernel_end
+0x19F8 kext_ctx_ptr       // 0x128-byte kext context (sandbox/AMFI)

// Misc
+0x200  trampoline_addr    // kernel trampoline address
+0x218  kernel_vm_ptr
+0x220  __DATA_CONST ptr
+0x1A00 kext_ctx_2         // second kext context (AMFI driver)
+0x1D18 sandbox_ctx
+0x1D20 amfi_ctx
```

## GFX Context (0x5E8 bytes) - Key Offsets
```
+0x10   kernel_ptr         // first kernel pointer found
+0x438  cmd_buf            // 4MB command buffer (vm_allocated)
+0x440  cmd_buf_2          // 4MB second buffer
+0x448  cmd_buf_size       // 0x400000
+0x450  page_table_buf     // vm_allocated page table buffer
+0x458  mapping_buf        // vm_allocated mapping buffer
+0x460  buf_size           // computed from ctx+0x598
+0x468  hiber_slot_0       // hibernation context slot (via _sub_7DA4)
+0x490  hiber_slot_1       // hibernation context slot (via _sub_7DA4)
+0x4B8  hiber_slot_2       // hibernation context slot (via _sub_7E08, W1=1)
+0x4D8  hiber_slot_3       // hibernation context slot (via _sub_7E08, W1=0)
+0x4F0  ring_buf           // 0xC000 ring buffer (zeroed after trigger)
+0x510  trigger_flag       // STLRB write of 1 fires hibernation
+0x518  power_thread_off   // offset into command array
+0x520  kernel_result_0    // from _sub_9018
+0x528  kernel_result_1
+0x530  kernel_result_2
+0x538  kernel_result_3
+0x540  kernel_result_4
+0x548  fake_hiber_cmd     // 0xC000 fake hibernation command buffer
+0x550  target_page_buf    // target physical page mapping
+0x560  race_buf_0         // page race buffer
+0x568  race_buf_1
+0x578  wire_buf_0         // wired page buffer
+0x580  wire_buf_1
+0x598  chip_selector_0    // from xmmword selection in _sub_A614
+0x5A0  kernel_base_ref
+0x5A8  kernel_slide_ref
+0x5B8  physrw_kread       // PACIZA kread via GFX
+0x5C0  physrw_kwrite      // PACIZA kwrite via GFX
+0x5C8  physrw_fn_3
+0x5D0  main_ctx_backptr   // pointer back to main ctx
+0x5D8  chip_selector_1    // optional xmmword
```

## Chip Path Selection (flag bits at ctx+0x00 & 0x518E241)

0x100000  → A17 Pro path - xmmword_42D80 + xmmword_42D90
             { 0x200000680, 0x7000000000 } + { 0x10, 0x800000000 }

0x4000000 → path B - xmmword_42D70 + xmmword_42D60
             { 0x40, 0x10000000000 } + { 0x220000680, 0x7ff000000000 }

0x1000000 → path C - xmmword_42D70 + xmmword_42DA0
             { 0x40, 0x10000000000 } + { 0x200000680, 0x7ff000000000 }

## Page Table Walker Table (unk_42DC8, 4 levels × 0x38 bytes)
```
// Each entry: { base_mask, addr_mask, shift, valid_mask, leaf_and, leaf_cmp, pgoff_mask }
// 16KB pages (shift=14 at L3)

L0: { 0x800000000000, 0x7fffffffffff, 47, 0x800000000000, 1, 2, 0 }
L1: { 0x1000000000,   0xfffffffff,    36, 0x7ff000000000, 1, 2, 0 }
L2: { 0x2000000,      0x1ffffff,      25, 0xffe000000,    1, 2, 0 }
L3: { 0x4000,         0x3fff,         14, 0x1ffc000,      3, 2, 2 }
```

## GFX Command Template Constants
```
xmmword_42D30 = { 0x33000000,  0x420000  }  // base template header
xmmword_42D40 = { 0x284000,    0x2C4000  }  // GFX_ctx+0x5D8 when selector==0x10
xmmword_42D50 = { 0x304000,    0x204000  }  // GFX_ctx+0x5D8 when selector==0x40
xmmword_42D60 = { 0x220000680, 0x7ff000000000 }
xmmword_42D70 = { 0x40,        0x10000000000  }
xmmword_42D80 = { 0x200000680, 0x7000000000   }  // A17 Pro
xmmword_42D90 = { 0x10,        0x800000000    }  // A17 Pro
xmmword_42DA0 = { 0x200000680, 0x7ff000000000 }
```

## Exploit Chain Summary
```
_driver(&drv)
  └─ allocates 0x50-byte vtable, signs function pointers

drv->init(drv, 0, &ctx)
  └─ driver_init2(ctx_out, flag)
       ├─ calloc(0x1D60)           // main context
       ├─ driver_init2_1()
       │    ├─ kernel_version_parse()
       │    ├─ fingerprint chip (constants → flag bits)
       │    ├─ _sub_CE78() → _sub_CB98() → _sub_CE84() → _sub_CEB8()
       │    │    └─ IOServiceOpen(AGX, type=3) → ctx+0x1918
       │    │    └─ IOConnectMapMemory64 (×2) → ctx+0x2C20, ctx+0x2C30
       │    └─ _sub_A614()         // Rocket SPTM bypass
       │         ├─ chip path selection → GFX context (0x5E8)
       │         ├─ _sub_7630()    // work buffers, find_mem_region
       │         ├─ _sub_7E84()    // 4 hibernation context slots
       │         │    ├─ _sub_7DA4() × 2  // slots via _sub_76B0 pool
       │         │    └─ _sub_7E08() × 2  // slots via _sub_7794
       │         │         └─ _sub_7794() // page table race builder
       │         │              ├─ _sub_6BBC() // race primitive
       │         │              │    ├─ _sub_68A0()
       │         │              │    ├─ mach_make_memory_entry_64 × 4
       │         │              │    └─ vm_map → _sub_6448 → physical addr verify
       │         │              └─ vm_remap self-referencing PTE
       │         ├─ _sub_8710()    // GFX memory + power thread
       │         │    ├─ _sub_8228()
       │         │    ├─ _sub_83C8()
       │         │    ├─ _sub_84F8()
       │         │    └─ _sub_85E4()
       │         ├─ _sub_8758()    // fake hibernation context + ttbr1
       │         │    ├─ finds power thread in command array
       │         │    └─ builds 2 fake hibernation structs → GFX_ctx+0x550
       │         └─ _sub_9018()    // kernel parsing / symbol resolution
       │              ├─ _sub_6DC0()
       │              ├─ _sub_8F18()
       │              └─ _sub_8DDC()
       └─ _sub_7F28()              // TRIGGER
            ├─ setup_thread_policy()  // real-time priority
            ├─ deallocate race pages (slots 0x470, 0x498)
            ├─ vm_copy cmd_buf → cmd_buf_2
            ├─ STLRB 1 → GFX_ctx+0x510  // store-release trigger flag
            └─ vm_copy(hiber_slot_3.D0, 0xC000, -1)  // fires ROP chain

// Post-exploit primitives:
kread(ctx, kaddr, buf, size, flag)   // ctx+0x30 → _sub_A354 → _sub_70A4
kwrite(ctx, kaddr, buf, size, flag)  // ctx+0x40 → _sub_A3F0 → _sub_7128

// Inner mechanism (per 0x4000 chunk):
_sub_6F68(ctx, addr)        // software page table walk → mapped ptr
_sub_6E30(ctx, kaddr, buf, size)  // kread: write page index to GFX_ctx+0x548+0x230
                                  //        vm_copy(+0x548→+0x550, 0xC000)
                                  //        vm_copy(+0x560→+0x568, 0xC000)
                                  //        memcpy(buf, +0x568+(addr&0x3FFF), size)
_sub_6EB8(ctx, kaddr, buf, size)  // kwrite: same trigger + memcpy + vm_copy back
```

## Dispatch Command IDs (for drv->dispatch)
```
// Category bits[15:8]:
// 0x00 = standard, 0x01 = I/O, 0x03 = chip-specific (A13+ only)

0x00000001  // IOServiceOpen / connection setup
0x00000002  // inject entitlement (task port)
0x00000003  // inject task_for_pid-allow entitlement
0x00000006  // _sub_2E00C(ctx, port)
0x00000007  // register thread for GFX ROP
0x00000008  // _sub_3A150 — exploit trigger/init
0x00000009  // _sub_3B7E0 with host port
0x0000000A  // _sub_23D30 — kASLR slide
0x0000000B  // task_info kernel ptr bootstrap (flavor=2, size=8)
0x0000000C  // _sub_2DE64
0x0000000D  // _sub_3AA2C
0x0000000F  // _sub_2DED4(ctx, port, W2=1)
0x00000013  // _sub_2DED4(ctx, port, W2=0)
0x00000014  // _sub_2C0F8
0x00000015  // _sub_3AD2C
0x00000016  // _sub_3AA2C
0x00000017  // _sub_3E1D8
0x0000001A  // _sub_3B7E0 with ctx+0x1920
0x0000001F  // _sub_3C9A4 + _sub_3C450
0x00000022  // _sub_3A5F0
0x00000026  // _sub_3A8DC
0x00000108  // kread variant
0x00000109  // loc_3EA20
0x0000010C  // open file / _CFProcessPath
0x0000010D  // loc_3E99C
0x40000105  // _sub_22464 size=0x14
0x4000010A  // loc_3E9C0
0x80000108  // loc_3E9D4
0x80000109  // check_rootfs_rw
0x8000010C  // loc_3E884
0x8000010D  // loc_3EA44
0xC000010B  // chip version check
0x00000302  // _sub_1FC94 — sync/status
0x40000300  // driver_cmd_setup_untethered_persistence_maybe
0x80000306  // _sub_203B0(ctx, X20, X20+0x10)
0xC0000303  // _sub_1FA7C(ctx, addr, size, data[]) — likely kernel write
```

## Key Physical Address / VM Primitives
```
_sub_6384(src, size, copy)   // vm_remap flags=1    (VM_FLAGS_ANYWHERE)
_sub_63E8(src, size, copy)   // vm_remap flags=0x4000 (VM_FLAGS_FIXED|OVERWRITE)
_sub_6448(vaddr)             // vm_region_recurse_64 flavor=0x13 → physical addr
                             // returns X0=packed(obj_id<<32|offset), X1=phys_addr
_sub_6BBC(ctx, slot)         // page table race trigger
                             // → mach_make_memory_entry_64 × 4 spray
                             // → vm_map → physical verify → returns 1 on win
_sub_6F68(ctx, kaddr)        // software page table walker
                             // → reads L0/L1/L2/L3 PTEs via _sub_6E30
                             // → returns mapped userspace address
```
