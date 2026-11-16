// FUN_fffffff00a1e7754 @ fffffff00a1e7754 size=3800
// DECOMPILE_FAILED
pacibsp
sub sp,sp,#0x150
stp x28,x27,[sp, #0xf0]
stp x26,x25,[sp, #0x100]
stp x24,x23,[sp, #0x110]
stp x22,x21,[sp, #0x120]
stp x20,x19,[sp, #0x130]
stp x29,x30,[sp, #0x140]
add x29,sp,#0x140
mov x21,x1
mov x25,x0
ldr x27,[x5]
ldrb w8,[x0, #0x3f]
lsr w8,w8,#0x6
cmp w8,#0x1
b.eq 0xfffffff00a1e7798
cbnz w8,0xfffffff00a1e77a0
add x20,x25,#0x40
b 0xfffffff00a1e77c0
mov x17,x25
ldr x16,[x17, #0xe8]!
cbz x16,0xfffffff00a1e77bc
movk x17,#0x289d, LSL #48
autda x16,x17
mov x20,x16
b 0xfffffff00a1e77c0
mov x20,#0x0
mov w10,#0x3
movk w10,#0x1000, LSL #16
ldr w8,[x21, #0x18]
tst x27,#0x200000000
ccmp w8,#0x4,#0x0,ne
cset w9,cc
add w8,w10,#0xb
cmp w9,#0x0
csel w8,wzr,w8,ne
cbz w9,0xfffffff00a1e783c
str x5,[sp, #0x48]
ldr x28,[x3, #0x18]
ldr w22,[x21, #0x30]
ldr w8,[x21]
mov w9,#0x1f1f
movk w9,#0x801f, LSL #16
and w8,w8,w9
add w9,w22,#0x8
ldp d1,d0,[x21, #0x8]
movi v2.2D,#0xffffffff
uxtl v1.2D,v1.2S
cmeq v2.2D,v1.2D,v2.2D
orr v1.16B,v2.16B,v1.16B
stp w8,w9,[x20]
stur q1,[x20, #0x8]
str d0,[x20, #0x18]
ldr w8,[x21]
tbnz w8,#0x1f,0xfffffff00a1e7844
mov w26,#0x18
mov w8,#0x20
b 0xfffffff00a1e7854
mov x0,x8
b 0xfffffff00a1e7cc8
ldr w8,[x21, #0x18]
str w8,[x20, #0x20]
mov w26,#0x1c
mov w8,#0x24
add x24,x20,x8
ldrb w8,[x25, #0x3f]
str x2,[sp, #0x50]
tbnz w8,#0x6,0xfffffff00a1e796c
ldr w9,[x21, #0x18]
add x1,x24,x9, LSL #0x4
eor x16,x24,x1
tst x16,#-0x40000000000000
b.eq 0xfffffff00a1e787c
movk x1,#0xc8a2, LSL #48
str x3,[sp, #0x58]
cbz w9,0xfffffff00a1e7998
str x1,[sp, #0x40]
str w4,[sp, #0x38]
lsl w23,w9,#0x4
sub w9,w22,w26
cmp w23,w9
csel w10,w23,w9,cc
tst w8,#0x40
csel w19,w9,w10,eq
ldr x8,[x21, #0x20]
add x0,x8,w26, UXTW 
mov x1,x24
mov x2,x19
bl 0xfffffff00a389b14
cbnz w0,0xfffffff00a1e7b44
str w22,[sp, #0x30]
ldr w9,[x21, #0x18]
cbz w9,0xfffffff00a1e79bc
mov x8,#0x0
mov w15,#0x0
mov x10,#0x1200000000
and x10,x27,x10
mov w11,#0x1
mov w12,#0xf0000000
mov w13,#0xc
mov w14,#0x10
mov w15,w15
add x16,x15,#0xc
cmp x16,x19
b.hi 0xfffffff00a1e7ba8
add x16,x15,x24
ldr w16,[x16, #0x8]
lsr w17,w16,#0x18
subs w0,w17,#0x3
b.cc 0xfffffff00a1e7918
cmp w0,#0x1
b.hi 0xfffffff00a1e7c78
cbnz x10,0xfffffff00a1e7c78
cmp w17,#0x2
b.ne 0xfffffff00a1e792c
ldr w17,[x21, #0x58]
add w17,w17,#0x1
str w17,[x21, #0x58]
cmp x28,x12
cset w17,hi
tst w16,#0xff000000
cset w16,ne
ands w16,w17,w16
csel w17,w14,w13,ne
add w15,w17,w15
cmp w15,w19
b.hi 0xfffffff00a1e7ba8
tst w16,#0x1
csel x16,x11,xzr,ne
orr x8,x16,x8
lsl x11,x11,#0x1
subs w9,w9,#0x1
b.ne 0xfffffff00a1e78e8
b 0xfffffff00a1e79c4
mov x17,x25
ldr x16,[x17, #0xf0]!
cbz x16,0xfffffff00a1e7988
movk x17,#0x9c97, LSL #48
autda x16,x17
mov x1,x16
b 0xfffffff00a1e798c
mov x1,#0x0
ldr w9,[x21, #0x18]
str x3,[sp, #0x58]
cbnz w9,0xfffffff00a1e7884
subs w2,w22,w26
b.ls 0xfffffff00a1e7ad4
ldr x8,[x21, #0x20]
add x0,x8,w26, UXTW 
mov x19,x4
bl 0xfffffff00a389b14
mov x4,x19
cbnz w0,0xfffffff00a1e7b44
b 0xfffffff00a1e7ad4
mov w15,#0x0
mov x8,#0x0
add w26,w19,w26
str w15,[x21, #0x40]
str x8,[x21, #0x38]
ldr w8,[x20, #0x4]
sub w9,w23,w15
add w8,w9,w8
str w8,[x20, #0x4]
ldr w8,[x21, #0x40]
cmp w8,w23
str x20,[sp, #0x28]
str w26,[sp, #0x18]
b.eq 0xfffffff00a1e7a28
sub w2,w19,w8
add x1,x24,x8
eor x16,x24,x1
tst x16,#-0x40000000000000
b.eq 0xfffffff00a1e7a0c
movk x1,#0xc8a2, LSL #48
ldr x20,[sp, #0x40]
mov x0,x20
bl 0xfffffff00aa65b10
ldr w23,[x21, #0x40]
sub w8,w19,w23
add x20,x20,x8
str x20,[sp, #0x40]
ldr x8,[sp, #0x58]
str x25,[sp, #0x20]
ldr x28,[x8, #0x18]
ldr w20,[x21, #0x18]
lsl w8,w20,#0x4
cmp w20,#0x40
b.hi 0xfffffff00a1e804c
add x19,x24,w8, UXTW 
sub w8,w20,#0x1
mov w9,#0x1
lsl x20,x9,x8
mov w26,#0xf0000000
mov x25,#-0x10
mov x22,#-0xc
add x8,x24,w23, UXTW 
ldr w23,[sp, #0x38]
cmp x28,x26
cset w3,hi
sub x19,x19,#0x10
ldr x9,[x21, #0x38]
tst x9,x20
csel x9,x22,x25,eq
add x24,x8,x9
eor x16,x8,x24
tst x16,#-0x40000000000000
b.eq 0xfffffff00a1e7a94
movk x24,#0xc8a2, LSL #48
mov x0,x19
mov x1,x24
mov x2,x21
bl 0xfffffff00a1e862c
cbnz w0,0xfffffff00a1e7cc8
mov x8,x24
cmp x20,#0x2
lsr x20,x20,#0x1
b.cs 0xfffffff00a1e7a68
ldp x25,x20,[sp, #0x20]
mov x4,x23
ldr w22,[sp, #0x30]
ldr w26,[sp, #0x18]
ldr x1,[sp, #0x40]
subs w2,w22,w26
b.hi 0xfffffff00a1e79a0
ldr w8,[x21, #0x34]
cbz w8,0xfffffff00a1e7b54
ldrh w9,[x25, #0x30]
ldrb w10,[x25, #0x3f]
cmp w10,#0x3f
b.hi 0xfffffff00a1e7af8
sub x9,x25,x9
add x9,x9,#0x100
b 0xfffffff00a1e7b18
mov x17,x25
ldr x16,[x17, #0xf0]!
cbz x16,0xfffffff00a1e7b0c
movk x17,#0x9c97, LSL #48
autda x16,x17
ldr w10,[x25, #0xfc]
sub x9,x16,x9
add x9,x9,x10
stp w8,wzr,[x9]
cmp w8,#0x9
b.cc 0xfffffff00a1e7b54
sub x2,x8,#0x8
ldr x8,[x21, #0x28]
add x0,x8,#0x8
add x1,x9,#0x8
mov x19,x4
bl 0xfffffff00a389b14
mov x4,x19
cbz w0,0xfffffff00a1e7b54
mov w0,#0x3
movk w0,#0x1000, LSL #16
sub w0,w0,#0x1
b 0xfffffff00a1e7cc8
mov x23,x4
mov x1,x21
mov x2,x27
bl 0xfffffff00a1eeb48
cbnz w0,0xfffffff00a1e7cc8
ldr x8,[sp, #0x48]
ldr x9,[x8]
str xzr,[sp, #0xd0]
movi v0.2D,#0x0
stp q0,q0,[sp, #0xb0]
stp q0,q0,[sp, #0x90]
stp q0,q0,[sp, #0x70]
str q0,[sp, #0x60]
ldrb w8,[x25, #0x3f]
lsr w8,w8,#0x6
cmp w8,#0x1
b.eq 0xfffffff00a1e7bb8
ldr x0,[sp, #0x50]
cbnz w8,0xfffffff00a1e7bc4
add x16,x25,#0x40
b 0xfffffff00a1e7bd8
mov w0,#0x3
movk w0,#0x1000, LSL #16
add w0,w0,#0x5
b 0xfffffff00a1e7cc8
add x16,x25,#0x40
ldr x0,[sp, #0x50]
b 0xfffffff00a1e7bd8
mov x17,x25
ldr x16,[x17, #0xe8]!
cbz x16,0xfffffff00a1e7bd8
movk x17,#0x289d, LSL #48
autda x16,x17
ldr w19,[x16]
mov w8,#0xe0e0
movk w8,#0x7fe0, LSL #16
tst w19,w8
b.eq 0xfffffff00a1e7bf8
mov w27,#0x0
mov w28,#0x0
b 0xfffffff00a1e7c90
str x16,[sp, #0x60]
ldr w28,[x16, #0x10]
ubfx x24,x19,#0x8,#0x5
stp w28,w24,[sp, #0x88]
cbz w24,0xfffffff00a1e7c88
sub w8,w24,#0x11
cmp w8,#0x4
b.hi 0xfffffff00a1e7c8c
ubfx x22,x19,#0x10,#0x5
str w22,[sp, #0xb0]
mov x27,x22
cbz w22,0xfffffff00a1e7c48
cmp w22,#0x13
b.eq 0xfffffff00a1e7c38
cmp w22,#0x11
b.ne 0xfffffff00a1e7e5c
ldr w27,[x16, #0x18]
str w27,[sp, #0xac]
cmn w27,#0x1
b.eq 0xfffffff00a1e7e60
ldr w1,[x16, #0x8]
and w26,w19,#0x1f
stp w1,w26,[sp, #0x68]
sub w8,w26,#0x11
cmp w8,#0x4
b.hi 0xfffffff00a1e7c94
add w8,w1,#0x1
cmp w8,#0x2
b.cs 0xfffffff00a1e7ce8
mov w20,#0x3
movk w20,#0x1000, LSL #16
b 0xfffffff00a1e7ca0
mov w0,#0x3
movk w0,#0x1000, LSL #16
add w0,w0,#0xc
b 0xfffffff00a1e7cc8
cbz w28,0xfffffff00a1e7c18
mov w27,#0x0
mov w1,#0x0
mov w20,#0x3
movk w20,#0x1000, LSL #16
add w20,w20,#0xd
add x19,sp,#0x60
add x0,x19,#0x18
bl 0xfffffff00a1f9a24
add x0,x19,#0x38
mov x1,x28
bl 0xfffffff00a1f9a24
add x0,x19,#0x60
mov x1,x27
bl 0xfffffff00a1f9a24
mov x0,x20
ldp x29,x30,[sp, #0x140]
ldp x20,x19,[sp, #0x130]
ldp x22,x21,[sp, #0x120]
ldp x24,x23,[sp, #0x110]
ldp x26,x25,[sp, #0x100]
ldp x28,x27,[sp, #0xf0]
add sp,sp,#0x150
retab
cmp w27,w1
b.ne 0xfffffff00a1e7cfc
orr w8,w26,#0x2
cmp w8,#0x13
b.ne 0xfffffff00a1e7c6c
cmp w1,w28
b.ne 0xfffffff00a1e7d14
cmp w24,#0x12
b.eq 0xfffffff00a1e7da4
cmp w26,#0x12
b.eq 0xfffffff00a1e7da4
str x9,[sp, #0x38]
str w1,[sp, #0x40]
add w8,w28,#0x1
cmp w8,#0x2
b.cc 0xfffffff00a1e7d30
cmp w27,w28
b.eq 0xfffffff00a1e8430
bl 0xfffffff00a1facd4
ldr x10,[sp, #0x50]
mov x17,x10
ldr x16,[x17, #0x48]!
cbz x16,0xfffffff00a1e7fc8
movk x17,#0xb8b5, LSL #48
autda x16,x17
cbz x16,0xfffffff00a1e7fc8
str x22,[sp, #0x30]
cbz w27,0xfffffff00a1e7dac
mov x0,x10
mov x1,x27
bl 0xfffffff00a1df9c4
ldr x10,[sp, #0x50]
cbz x0,0xfffffff00a1e7d94
mov x22,x0
ldrb w8,[x0, #0xa]
tbz w8,#0x0,0xfffffff00a1e7d94
ldr x16,[x22]
mov x17,x22
movk x17,#0xf444, LSL #48
autda x16,x17
ldrb w8,[x16]
cmp w8,#0x21
b.eq 0xfffffff00a1e7db0
mov x0,x10
bl 0xfffffff00a22b850
ldr x22,[sp, #0x30]
b 0xfffffff00a1e7e64
mov x1,x28
b 0xfffffff00a1e7c6c
mov x22,#0x0
mov x12,x22
ldr w1,[sp, #0x40]
cmp w27,w1
b.eq 0xfffffff00a1e7dd8
mov x0,x10
ldr w1,[sp, #0x40]
bl 0xfffffff00a1df9c4
ldr x10,[sp, #0x50]
ldr w1,[sp, #0x40]
mov x12,x0
str x20,[sp, #0x28]
cbz x12,0xfffffff00a1e7fc8
ldr w20,[x12, #0x8]
tst w20,#0x70000
b.eq 0xfffffff00a1e7fc8
add w8,w28,#0x1
cmp w8,#0x2
str x22,[sp, #0x20]
b.cs 0xfffffff00a1e7e88
mov x22,#0x0
str x22,[sp, #0x18]
cmp w27,w1
b.eq 0xfffffff00a1e7e3c
mov w22,#0x0
and w8,w19,#0x1e00
mov w3,#0x1
mov w9,#0x1400
cmp w8,w9
b.eq 0xfffffff00a1e7f7c
cmp w1,w28
b.ne 0xfffffff00a1e7f7c
and w8,w19,#0x1e
str x24,[sp, #0x30]
cmp w8,#0x14
b.eq 0xfffffff00a1e7f7c
cmp w26,#0x11
ldr x11,[sp, #0x30]
b.ne 0xfffffff00a1e7ec4
cmp w11,#0x11
b.ne 0xfffffff00a1e7ec4
mov w26,#0x11
mov w3,#0x9
b 0xfffffff00a1e7edc
mov w27,#0x0
str wzr,[sp, #0x40]
mov x0,x27
mov x1,x22
mov w2,#0x20000
bl 0xfffffff00aa4ca7c
mov w20,#0x3
movk w20,#0x1000, LSL #16
add w20,w20,#0x2
ldr w1,[sp, #0x40]
b 0xfffffff00a1e7ca0
cmp w1,w28
str x12,[sp, #0x10]
b.ne 0xfffffff00a1e7ee4
str w20,[sp, #0xa8]
mov x22,x12
mov x0,x10
mov x1,x28
mov x2,x22
mov x3,x24
bl 0xfffffff00a1f9900
ldr x12,[sp, #0x10]
ldr x10,[sp, #0x50]
ldr w1,[sp, #0x40]
cbnz w0,0xfffffff00a1e7e00
b 0xfffffff00a1e7efc
cmp w26,#0x11
b.ne 0xfffffff00a1e7f30
cmp w11,#0x13
b.ne 0xfffffff00a1e7f30
mov w26,#0x11
mov w3,#0x5
mov w22,#0x1
b 0xfffffff00a1e7f7c
mov x0,x10
mov x1,x28
bl 0xfffffff00a1df9c4
cbnz x0,0xfffffff00a1e8610
mov w20,#0x0
ldr x10,[sp, #0x50]
mov x0,x10
bl 0xfffffff00a22b850
and w8,w20,#0xffffff
lsl x8,x8,#0x20
orr x1,x8,x24
mov x0,x28
mov w2,#0x10000
bl 0xfffffff00aa4ca7c
mov w20,#0x3
movk w20,#0x1000, LSL #16
add w20,w20,#0x6
ldr w1,[sp, #0x40]
b 0xfffffff00a1e7ca0
mov x9,x23
mov x8,x10
cmp w26,#0x13
b.ne 0xfffffff00a1e7f50
cmp w11,#0x11
b.ne 0xfffffff00a1e7f50
mov w26,#0x11
b 0xfffffff00a1e7f68
cmp w26,#0x13
b.ne 0xfffffff00a1e8604
ldr x10,[sp, #0x30]
cmp w10,#0x13
b.ne 0xfffffff00a1e8604
mov w26,#0x13
mov w3,#0x5
mov w22,#0x1
ldr w1,[sp, #0x40]
mov x10,x8
mov x23,x9
ldr w8,[x12, #0xc]
str w8,[sp, #0xd0]
add x28,sp,#0x60
str xzr,[sp]
add x6,x28,#0x10
add x7,x28,#0x18
mov x19,x10
mov x0,x10
mov x2,x26
mov w4,#0x1
mov x20,x12
mov x5,x12
bl 0xfffffff00a1f9b10
cbz w0,0xfffffff00a1e7fd8
ldr w8,[sp, #0x68]
str w8,[sp, #0x40]
ldr w28,[sp, #0x88]
ldr w27,[sp, #0xac]
mov x10,x19
mov x0,x10
bl 0xfffffff00a22b850
ldr w1,[sp, #0x40]
b 0xfffffff00a1e7c6c
ldrb w8,[x20, #0xa]
tst w8,#0x1f
b.ne 0xfffffff00a1e7fe8
str wzr,[sp, #0xd0]
ldr w1,[sp, #0xac]
ldr w8,[sp, #0x68]
cmp w1,w8
eor w9,w22,#0x1
csinc w9,w9,wzr,eq
mov x20,x19
mov x27,x23
tbnz w9,#0x0,0xfffffff00a1e8014
ldr x8,[sp, #0x70]
str x8,[sp, #0xb8]
b 0xfffffff00a1e80c8
cbz w1,0xfffffff00a1e80c4
ldr w2,[sp, #0xb0]
add x8,sp,#0x60
str xzr,[sp]
add x6,x8,#0x58
add x7,x8,#0x60
mov x0,x20
mov w3,#0x0
mov w4,#0x3
ldr x5,[sp, #0x20]
bl 0xfffffff00a1f9b10
cbnz w0,0xfffffff00a1e85f8
ldr w1,[sp, #0x68]
b 0xfffffff00a1e80c8
mov w2,w23
sub w8,w8,w23
add x19,x24,x8
mov x0,x19
mov x1,x24
bl 0xfffffff00aa65b10
mov w26,#0xf0000000
mov w23,#0xc
mov w8,#0x10
cmp x28,x26
csel x22,x8,x23,hi
cmp x28,x26
cset w3,hi
ldr w25,[x19, #0x8]
mov x0,x24
mov x1,x19
mov x2,x21
bl 0xfffffff00a1e862c
cbnz w0,0xfffffff00a1e7cc8
add x24,x24,#0x10
lsr w8,w25,#0x18
cmp w8,#0x0
csel x8,x23,x22,eq
add x9,x19,x8
mov x19,x9
subs w20,w20,#0x1
b.ne 0xfffffff00a1e8078
ldp x25,x20,[sp, #0x20]
ldr w4,[sp, #0x38]
b 0xfffffff00a1e7ac0
mov x1,x8
ldr w8,[sp, #0x88]
cmp w8,w1
eor w9,w22,#0x1
csinc w9,w9,wzr,eq
tbnz w9,#0x0,0xfffffff00a1e80e4
ldr x8,[sp, #0x70]
b 0xfffffff00a1e80f8
add w9,w8,#0x1
cmp w9,#0x2
b.cs 0xfffffff00a1e8264
cmn w8,#0x1
csinv x8,x8,xzr,ne
str x8,[sp, #0x90]
mov x23,x25
ldr x24,[sp, #0x70]
mov x0,x24
bl 0xfffffff00a1f036c
mov x0,x20
bl 0xfffffff00a22b850
ldr x17,[sp, #0xb8]
add x8,x17,#0x1
cmp x8,#0x2
b.cc 0xfffffff00a1e8150
ldrb w8,[sp, #0xb0]
add x16,x23,#0x10
movk x16,#0xc442, LSL #48
pacda x17,x16
str x17,[x23, #0x10]
ldrb w9,[x23, #0x3f]
bfxil w9,w8,#0x0,#0x6
strb w9,[x23, #0x3f]
str xzr,[sp, #0xb8]
mov w8,#0x11
str w8,[sp, #0xb0]
ldr w8,[sp, #0x6c]
sub w8,w8,#0x10
cmp w8,#0x5
b.hi 0xfffffff00a1e8170
adrp x9,-0xff8ff0000
add x9,x9,#0x55c
ldr w19,[x9, w8, UXTW #0x2]
b 0xfffffff00a1e8174
mov w19,#0x0
str w19,[sp, #0x6c]
ldr w8,[sp, #0x8c]
sub w8,w8,#0x10
cmp w8,#0x5
b.hi 0xfffffff00a1e8198
adrp x9,-0xff8ff0000
add x9,x9,#0x55c
ldr w22,[x9, w8, UXTW #0x2]
b 0xfffffff00a1e819c
mov w22,#0x0
str w22,[sp, #0x8c]
ldrb w8,[x24, #0x1]
ands w8,w8,#0x7
b.eq 0xfffffff00a1e81e4
ldrb w9,[x24]
cmp w9,#0xd
b.cc 0xfffffff00a1e81f0
cmp w8,#0x2
b.hi 0xfffffff00a1e81f0
adrp x8,-0xff843e000
ldr x8,[x8, #0x980]
mov x17,x24
ldr x16,[x17, #0x48]!
cbz x16,0xfffffff00a1e81dc
movk x17,#0x97f6, LSL #48
autda x16,x17
cmp x16,x8
b.ne 0xfffffff00a1e81f0
ldrh w8,[x23, #0x3c]
orr w8,w8,#0x1
strh w8,[x23, #0x3c]
ldr x8,[sp, #0x38]
tbz w8,#0x7,0xfffffff00a1e82cc
cmp w19,#0x12
b.eq 0xfffffff00a1e82cc
ldr w2,[sp, #0xd0]
cbz w2,0xfffffff00a1e82cc
ldrb w8,[x24, #0x1]
ands w8,w8,#0x7
b.eq 0xfffffff00a1e82cc
cmp w8,#0x2
b.hi 0xfffffff00a1e8240
adrp x8,-0xff843e000
ldr x8,[x8, #0x980]
mov x17,x24
ldr x16,[x17, #0x48]!
cbz x16,0xfffffff00a1e8238
movk x17,#0x97f6, LSL #48
autda x16,x17
cmp x16,x8
b.eq 0xfffffff00a1e82cc
ldrh w8,[x24, #0x38]
ldrh w9,[x24, #0x3a]
cmp w8,w9
b.cs 0xfffffff00a1e82a4
ldr x9,[sp, #0x48]
ldr x8,[x9]
orr x8,x8,#0x10000
str x8,[x9]
b 0xfffffff00a1e82cc
ldr w2,[sp, #0x8c]
add x9,sp,#0x60
str xzr,[sp]
add x6,x9,#0x30
add x7,x9,#0x38
mov x0,x20
mov x1,x8
mov w3,#0x2
mov w4,#0x2
ldr x5,[sp, #0x18]
bl 0xfffffff00a1f9b10
mov x23,x25
cbz w0,0xfffffff00a1e8100
adrp x8,-0xff8395000
add x8,x8,#0xbc0
brk #0xbffc
mov x0,x24
ldr x3,[sp, #0x38]
mov x4,x27
bl 0xfffffff00a1f0ed4
tbz w0,#0x0,0xfffffff00a1e82cc
mov x0,x24
mov w1,#0x1
mov w2,#0x1
bl 0xfffffff00a1f1a80
cbnz w0,0xfffffff00a1e82dc
ldrb w8,[x24, #0x2]
tbnz w8,#0x0,0xfffffff00a1e85ec
add x0,x24,#0x14
bl 0xfffffff00a22b804
and w8,w19,#0x1f
bfm w8,w22,#0x18,#0x4
ldr w9,[sp, #0xb0]
bfm w8,w9,#0x10,#0x4
ldr x9,[sp, #0x60]
ldr w10,[x9]
mov w11,#0xe0e0
movk w11,#0xffe0, LSL #16
and w10,w10,w11
orr w8,w8,w10
str w8,[x9]
str x24,[x9, #0x8]
ldr x8,[sp, #0x90]
str x8,[x9, #0x10]
str xzr,[sp, #0x90]
str xzr,[sp, #0x70]
ldrb w8,[x23, #0x3f]
lsr w8,w8,#0x6
cmp w8,#0x1
b.eq 0xfffffff00a1e8330
cbnz w8,0xfffffff00a1e833c
mov x22,x23
add x24,x23,#0x40
b 0xfffffff00a1e8360
mov x22,x23
mov x17,x23
ldr x16,[x17, #0xe8]!
cbz x16,0xfffffff00a1e835c
movk x17,#0x289d, LSL #48
autda x16,x17
mov x24,x16
b 0xfffffff00a1e8360
mov x24,#0x0
ldr x9,[sp, #0x38]
ldp x23,x26,[x24, #0x8]
mov w8,#0xff
bics wzr,w8,w27
b.eq 0xfffffff00a1e83d0
tbz w9,#0x5,0xfffffff00a1e83d0
mov w10,#0x0
ubfx w8,w27,#0x10,#0x4
subs w11,w8,#0x7
csel w8,w8,wzr,cc
ubfx w9,w27,#0x14,#0x4
sub w12,w8,#0x1
cmp w12,#0x5
b.hi 0xfffffff00a1e83b8
ubfx w10,w27,#0x8,#0x8
add w12,w8,#0x7
mov w13,#0x1
lsl w12,w13,w12
cmn w11,#0x6
mov w11,#0xff
csel w10,w11,w10,cc
orr w10,w12,w10
str w10,[x22, #0x34]
cmp w8,w9
csel w10,w8,w9,hi
cmp w9,#0x7
csel w8,w10,w8,cc
b 0xfffffff00a1e84f8
tbz w9,#0x15,0xfffffff00a1e8428
mrs x19,tpidr_el1
stur wzr,[x29, #-0x5c]
sub x1,x29,#0x5c
mov x0,x19
bl 0xfffffff00a28305c
cmp w0,#0x7
b.eq 0xfffffff00a1e8428
cbnz w0,0xfffffff00a1e8440
ldrsh w8,[x19, #0x206]
cmp w8,#0x2d
b.gt 0xfffffff00a1e8450
cmp w8,#0x24
b.gt 0xfffffff00a1e8458
cmp w8,#0x1e
b.gt 0xfffffff00a1e8460
cmp w8,#0x13
b.gt 0xfffffff00a1e8468
cmp w8,#0x4
mov w8,#0x1
cinc w0,w8,ge
b 0xfffffff00a1e846c
mov w9,#0x0
b 0xfffffff00a1e8480
mov w8,#0xffffffff
str w8,[sp, #0xa8]
orr x8,xzr,#0xffffff00000000
b 0xfffffff00a1e7f0c
ldur w8,[x29, #-0x5c]
sub w8,w8,#0x1
and w8,w8,#0xff
b 0xfffffff00a1e8470
mov w0,#0x6
b 0xfffffff00a1e846c
mov w0,#0x5
b 0xfffffff00a1e846c
mov w0,#0x4
b 0xfffffff00a1e846c
mov w0,#0x3
mov w8,#0xff
add w9,w0,#0x7
mov w10,#0x1
lsl w9,w10,w9
orr w9,w8,w9
str w9,[x22, #0x34]
and w8,w9,#0x3f00
ldr x10,[sp, #0x38]
tbnz w10,#0x5,0xfffffff00a1e84a8
cbz w8,0xfffffff00a1e84f8
lsr w8,w9,#0x8
rbit w8,w8
clz w8,w8
add w8,w8,#0x1
b 0xfffffff00a1e84f8
mov w10,#0x0
lsr w9,w9,#0x8
rbit w9,w9
clz w9,w9
add w9,w9,#0x1
mov w11,w27
mov w12,#0x22000000
tst x11,x12
b.ne 0xfffffff00a1e84e8
and x11,x11,#0x3f00
cbz x11,0xfffffff00a1e84e8
mov w10,#0x3f
ands w10,w10,w27, LSR #0x8
rbit w10,w10
clz w10,w10
csinc w10,wzr,w10,eq
cmp w9,w10
csel w9,w9,w10,hi
cmp w8,#0x0
csel w8,w10,w9,eq
strb w8,[x22, #0x3e]
add x8,x26,#0x1
cmp x8,#0x2
b.cs 0xfffffff00a1e8588
mrs x0,tpidr_el1
bl 0xfffffff00a29bafc
mov x1,x0
mov x0,x22
bl 0xfffffff00a1e87d8
ldr w1,[sp, #0x68]
add x0,x28,#0x18
bl 0xfffffff00a1f9a24
add x19,sp,#0x60
ldr w1,[sp, #0x88]
add x0,x19,#0x38
bl 0xfffffff00a1f9a24
ldr w1,[sp, #0xac]
add x0,x19,#0x60
bl 0xfffffff00a1f9a24
ldr x8,[sp, #0x48]
ldr x19,[x8]
ldr x23,[sp, #0x28]
mov x0,x23
mov x1,x21
mov x2,x19
bl 0xfffffff00a1eeea8
cbz w0,0xfffffff00a1e8578
mov x24,x0
mov x0,x22
bl 0xfffffff00a1e7614
mov x0,x24
b 0xfffffff00a1e7cc8
ldr w8,[x23]
tbnz w8,#0x1f,0xfffffff00a1e85cc
mov w0,#0x0
b 0xfffffff00a1e7cc8
ldrb w8,[x26]
cmp w8,#0xb
b.ne 0xfffffff00a1e8508
ldrb w8,[x23]
cmp w8,#0xc
b.hi 0xfffffff00a1e8508
ldr w8,[x24]
and w8,w8,#0x1f00
mov w9,#0x1200
cmp w8,w9
b.ne 0xfffffff00a1e8508
ldr x8,[sp, #0x38]
ubfx w2,w8,#0x17,#0x1
mov x0,x26
mov x1,x23
bl 0xfffffff00a1f3498
b 0xfffffff00a1e8508
ldr w1,[x21, #0x18]
ldr x2,[x21, #0x50]
mov x0,x22
mov x3,x20
ldr x4,[sp, #0x58]
mov x5,x19
bl 0xfffffff00a1e8934
b 0xfffffff00a1e7cc8
adrp x8,-0xff8395000
add x8,x8,#0xcb0
brk #0xbffc
adrp x8,-0xff8395000
add x8,x8,#0xbac
brk #0xbffc
adrp x8,-0xff8395000
add x8,x8,#0xbd4
brk #0xbffc
mov x22,x0
ldr w20,[x0, #0x8]
str w20,[sp, #0xa8]
tst w20,#0x70000
ldr x10,[sp, #0x50]
b.eq 0xfffffff00a1e7efc
b 0xfffffff00a1e7e9c
