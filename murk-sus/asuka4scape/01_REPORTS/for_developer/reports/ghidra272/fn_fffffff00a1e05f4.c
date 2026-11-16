// FUN_fffffff00a1e05f4 @ fffffff00a1e05f4 size=672
// DECOMPILE_FAILED
pacibsp
stp x28,x27,[sp, #-0x60]!
stp x26,x25,[sp, #0x10]
stp x24,x23,[sp, #0x20]
stp x22,x21,[sp, #0x30]
stp x20,x19,[sp, #0x40]
stp x29,x30,[sp, #0x50]
add x29,sp,#0x50
mov x20,x0
mov w0,#0x3
mov w8,#0xff
movk w8,#0x200, LSL #16
cmp w1,w8
b.hi 0xfffffff00a1e0738
bics wzr,w0,w1
b.ne 0xfffffff00a1e0644
cmp w1,#0x100
b.cs 0xfffffff00a1e064c
mov w0,#0x5
b 0xfffffff00a1e0738
mov w0,#0x12
b 0xfffffff00a1e0738
mov x19,x2
lsr w24,w1,#0x8
mrs x2,tpidr_el1
ldr w8,[x2, #0x1c0]
add w8,w8,#0x1
str w8,[x2, #0x1c0]
add x8,x20,#0x8
mov w9,#0x1000000
ldadda w9,w8,[x8]
ubfx w9,w8,#0x10,#0x8
cmp w9,w8, LSR #0x18
b.ne 0xfffffff00a1e0878
ldr w8,[x2, #0x4e8]
str w8,[x20, #0xc]
lsl w23,w1,#0x18
add x21,x20,#0x48
mov w8,#0x18
umull x8,w24,w8
add x26,x8,#0x18
mov x22,x21
movk x22,#0xb8b5, LSL #48
add x27,x24,x24, LSL #0x1
ldr x16,[x21]
cbz x16,0xfffffff00a1e072c
mov x17,x21
movk x17,#0xb8b5, LSL #48
autda x16,x17
cbz x16,0xfffffff00a1e072c
ldr x16,[x21]
cbz x16,0xfffffff00a1e06e4
mov x17,x22
autda x16,x17
tbnz x16,#0x26,0xfffffff00a1e06f4
cbz x16,0xfffffff00a1e06e4
ubfiz x8,x16,#0xe,#0xe
and x9,x16,#-0x4000
orr x9,x9,#0x4000000000
b 0xfffffff00a1e0708
mov x9,#0x0
mov x8,#0x0
mov x25,#0x0
b 0xfffffff00a1e0714
and x8,x16,#0x10
orr x8,x8,#0x20
and x9,x16,#0xf
lsl x8,x8,x9
and x9,x16,#-0x20
cmp x26,x8
b.hi 0xfffffff00a1e06ec
add x25,x9,x27, LSL #0x3
cbnz x25,0xfffffff00a1e0754
add w1,w24,#0x1
mov x0,x20
bl 0xfffffff00a1dfe44
cbz w0,0xfffffff00a1e06a4
b 0xfffffff00a1e0738
mov x0,x20
bl 0xfffffff00a22b850
mov w0,#0x10
ldp x29,x30,[sp, #0x50]
ldp x20,x19,[sp, #0x40]
ldp x22,x21,[sp, #0x30]
ldp x24,x23,[sp, #0x20]
ldp x26,x25,[sp, #0x10]
ldp x28,x27,[sp], #0x60
retab
ldr w10,[x25, #0x8]
tst w10,#0x1f0000
b.eq 0xfffffff00a1e077c
and w8,w10,#0xfc000000
orr w8,w8,#0x3000000
cmp w8,w23
b.ne 0xfffffff00a1e07a0
mov w0,#0x0
str x25,[x19]
b 0xfffffff00a1e0738
ldr w13,[x9, #0xc]
cmp w13,w24
b.ne 0xfffffff00a1e07b0
ldr w8,[x25, #0xc]
str w8,[x9, #0xc]
ldr w8,[x20, #0x18]
sub w8,w8,#0x1
str w8,[x20, #0x18]
b 0xfffffff00a1e0848
mov x0,x20
bl 0xfffffff00a22b850
mov w0,#0x5
b 0xfffffff00a1e0738
mov w11,#0x18
mov w10,w13
umull x12,w13,w11
add x12,x12,#0x18
cmp x12,x8
b.hi 0xfffffff00a1e07f4
add x13,x10,x10, LSL #0x1
add x12,x9,x13, LSL #0x3
eor x16,x9,x12
tst x16,#-0x40000000000000
b.eq 0xfffffff00a1e07e0
movk x12,#0xc8a2, LSL #48
cbz x12,0xfffffff00a1e07fc
ldr w13,[x12, #0xc]
cmp w13,w24
b.ne 0xfffffff00a1e07b4
b 0xfffffff00a1e0808
mov x12,#0x0
cbnz x12,0xfffffff00a1e07e4
adrp x8,-0xff8395000
add x8,x8,#0xb20
brk #0xbffc
ldr w8,[x25, #0xc]
str w8,[x12, #0xc]
ldr w8,[x20, #0x18]
sub w8,w8,#0x1
str w8,[x20, #0x18]
cbz w10,0xfffffff00a1e0848
and w8,w10,#0xffffff
ldr xzr,[x20, #0x48]
ldr w9,[x20, #0x70]
cmp w8,w9
b.cs 0xfffffff00a1e0838
str w8,[x20, #0x70]
ldr w9,[x20, #0x74]
cmp w8,w9
b.ls 0xfffffff00a1e0848
str w8,[x20, #0x74]
add x0,x20,#0x20
add x1,x20,#0x1c
mov w2,#0x1
mov w3,#0x2
bl 0xfffffff00a36d048
mov x8,x0
mov w0,#0x0
and w9,w23,#0xfc000000
orr w8,w9,w8, LSL #0x18
stp w8,wzr,[x25, #0x8]
str x25,[x19]
b 0xfffffff00a1e0738
lsr w8,w8,#0x18
mov x0,x20
mov x21,x1
mov x1,x8
bl 0xfffffff00a22b5a8
mov x1,x21
b 0xfffffff00a1e0684
