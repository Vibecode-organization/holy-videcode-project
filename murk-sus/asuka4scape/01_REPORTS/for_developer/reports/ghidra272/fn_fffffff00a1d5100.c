// FUN_fffffff00a1d5100 @ fffffff00a1d5100 size=1136
// DECOMPILE_FAILED
pacibsp
sub sp,sp,#0xd0
stp x28,x27,[sp, #0x70]
stp x26,x25,[sp, #0x80]
stp x24,x23,[sp, #0x90]
stp x22,x21,[sp, #0xa0]
stp x20,x19,[sp, #0xb0]
stp x29,x30,[sp, #0xc0]
add x29,sp,#0xc0
mov w21,#0x4
cbz x1,0xfffffff00a1d54a0
mov x23,x2
cbz w2,0xfffffff00a1d54a0
cbz x6,0xfffffff00a1d54a0
mov x22,x3
mov x25,x0
mov x26,x4
mov x20,x5
str x6,[sp, #0x30]
mov w8,w23
mov x24,x1
mov x0,x1
mov x1,x8
bl 0xfffffff00aa65cc0
adrp x8,-0xff8444000
ldr w8,[x8]
cmp w23,w8
csel w28,w23,w8,cc
mrs x19,tpidr_el1
ldr w8,[x19, #0x4e8]
adrp x27,-0xff52cd000
add x27,x27,#0xc50
tbnz w22,#0x14,0xfffffff00a1d51ac
mov x9,#0x0
casa x9,x8,[x27]
cmp x9,#0x0
b.eq 0xfffffff00a1d51bc
adrp x0,-0xff52cd000
add x0,x0,#0xc48
mov x1,x19
mov w2,#0x0
bl 0xfffffff00a2262d4
b 0xfffffff00a1d51bc
mov w9,#0x0
casa w9,w8,[x27]
cmp w9,#0x0
b.ne 0xfffffff00a1d5424
adrp x8,-0xff5266000
str wzr,[x8, #0x28]
adrp x8,-0xff5266000
str xzr,[x8, #0x30]
adrp x8,-0xff5266000
str xzr,[x8, #0x38]
adrp x8,-0xff5268000
ldr w8,[x8, #0xb00]
tst w8,#0xfffffff7
b.ne 0xfffffff00a1d54f4
bl 0xfffffff00a2c122c
mov x21,x0
cbnz w0,0xfffffff00a1d548c
mrs x8,daif
tbz w8,#0x9,0xfffffff00a1d5528
str x28,[sp, #0x20]
and x8,x8,#0x1c0
cmp x8,#0x1c0
b.eq 0xfffffff00a1d520c
msr DAIFSet,#0x7
ldr x9,[x19, #0x1b8]
ldr x9,[x9, #0x58]
mov x28,x9
mrs x27,sreg(0x3, 0x4, c0xf, c0xa, 0x6)
ldr x9,[x19, #0x1b8]
ldr x9,[x9, #0x58]
cmp x9,x28
b.ne 0xfffffff00a1d5214
cmp x8,#0x1c0
cset w8,ne
str w8,[sp, #0x2c]
mov w0,#0x15
movk w0,#0x61f, LSL #16
mov x1,#0x0
mov x2,#0x0
mov x3,#0x0
mov x4,#0x0
bl 0xfffffff00a29ead8
stp w25,wzr,[sp, #0x38]
stp x24,xzr,[sp, #0x40]
stp w23,wzr,[sp, #0x50]
stp x22,x26,[sp, #0x58]
stp w20,wzr,[sp, #0x68]
add x0,sp,#0x38
bl 0xfffffff00a1d5570
ldr x8,[x19, #0x1b8]
ldr x8,[x8, #0x58]
cbz w0,0xfffffff00a1d5284
mov x21,x0
b 0xfffffff00a1d532c
mov x9,x8
mrs x10,sreg(0x3, 0x4, c0xf, c0xa, 0x6)
ldr x8,[x19, #0x1b8]
ldr x8,[x8, #0x58]
cmp x8,x9
b.ne 0xfffffff00a1d5284
add x8,x10,x9
adrp x22,-0xff5266000
str x8,[x22, #0x8]
adrp x20,-0xff5266000
str xzr,[x20, #0x10]
str xzr,[sp]
mov w0,#0x1
mov x1,#0x0
mov x2,#0x0
mov x3,#0x0
mov x4,#0x0
mov x5,#0x0
mov w6,#0x0
mov x7,#0x0
bl 0xfffffff00a2105b0
mov x21,x0
ldr x8,[x19, #0x1b8]
ldr x10,[x8, #0x58]
mov x8,x10
mrs x9,sreg(0x3, 0x4, c0xf, c0xa, 0x6)
ldr x10,[x19, #0x1b8]
ldr x10,[x10, #0x58]
cmp x10,x8
b.ne 0xfffffff00a1d52e4
ldr x10,[x22, #0x8]
add x9,x9,x8
sub x10,x9,x10
str x9,[x20, #0x10]
adrp x9,-0xff5266000
ldr x11,[x9, #0x18]
add x11,x11,#0x1
str x11,[x9, #0x18]
adrp x9,-0xff5266000
ldr x11,[x9, #0x20]
add x10,x10,x11
str x10,[x9, #0x20]
add x22,x27,x28
mov x20,x8
mrs x23,sreg(0x3, 0x4, c0xf, c0xa, 0x6)
ldr x8,[x19, #0x1b8]
ldr x8,[x8, #0x58]
cmp x8,x20
b.ne 0xfffffff00a1d5330
mov w8,#0x15
movk w8,#0x61f, LSL #16
add w0,w8,#0x1
mov x1,#0x0
mov x2,#0x0
mov x3,#0x0
mov x4,#0x0
bl 0xfffffff00a29ead8
ldr w0,[sp, #0x2c]
bl 0xfffffff00a393464
adrp x24,-0xff52d0000
ldr x8,[x24, #0x108]
mov w9,#0x1d90
adrp x25,-0xff52d0000
add x25,x25,#0x110
mul x8,x8,x9
add x9,x25,x8
eor x16,x25,x9
tst x16,#-0x40000000000000
b.eq 0xfffffff00a1d539c
movk x9,#0xc8a2, LSL #48
stlur wzr,[x9, #0x64]
adrp x8,-0xff52bb000
ldr x1,[x8, #0xfc0]
adrp x27,-0xff52cd000
add x27,x27,#0xc50
cbz x1,0xfffffff00a1d53ec
adrp x8,-0xff8399000
ldr x0,[x8, #0x8d8]
adrp x8,-0xff52c3000
ldr w8,[x8, #0xb00]
lsl w9,w8,#0xf
mov w10,#0xc
umaddl x2,w8,w10,x9
mov w3,#0x0
mov x4,#0x0
bl 0xfffffff00a2defc4
adrp x8,-0xff52bb000
add x8,x8,#0xfc0
movi v0.2D,#0x0
stp q0,q0,[x8]
cbnz w21,0xfffffff00a1d5438
ldr x8,[x24, #0x108]
mov w9,#0x1d90
mul x8,x8,x9
add x9,x25,x8
eor x16,x25,x9
tst x16,#-0x40000000000000
b.eq 0xfffffff00a1d5410
movk x9,#0xc8a2, LSL #48
ldrb w8,[x9, #0x60]
tbz w8,#0x0,0xfffffff00a1d542c
bl 0xfffffff00a1d62d8
mov x21,x0
b 0xfffffff00a1d5438
mov w21,#0x28
b 0xfffffff00a1d54a0
bl 0xfffffff00a1d5a08
mov x21,x0
cbz w0,0xfffffff00a1d54c4
add x8,x23,x20
adrp x9,-0xff5266000
ldr x9,[x9, #0x38]
cbz x9,0xfffffff00a1d5450
sub x10,x8,x22
str x10,[x9]
ldr x9,[x24, #0x108]
mov w10,#0x1d90
mul x9,x9,x10
add x10,x25,x9
eor x16,x25,x10
tst x16,#-0x40000000000000
b.eq 0xfffffff00a1d5470
movk x10,#0xc8a2, LSL #48
ldr w4,[x10, #0x1d88]
ldr x9,[sp, #0x30]
str w4,[x9]
adrp x9,-0xff5268000
ldr w9,[x9, #0xb00]
tst w9,#0xfffffff7
b.ne 0xfffffff00a1d5550
ldr w8,[x19, #0x4e8]
mov x2,x8
casl w2,wzr,[x27]
cmp w2,w8
b.ne 0xfffffff00a1d5514
mov x0,x21
ldp x29,x30,[sp, #0xc0]
ldp x20,x19,[sp, #0xb0]
ldp x22,x21,[sp, #0xa0]
ldp x24,x23,[sp, #0x90]
ldp x26,x25,[sp, #0x80]
ldp x28,x27,[sp, #0x70]
add sp,sp,#0xd0
retab
ldr x8,[x24, #0x108]
mov w9,#0x1d90
mul x8,x8,x9
add x9,x25,x8
eor x16,x25,x9
tst x16,#-0x40000000000000
b.eq 0xfffffff00a1d54e4
movk x9,#0xc8a2, LSL #48
ldrb w8,[x9, #0x60]
tbnz w8,#0x0,0xfffffff00a1d5418
bl 0xfffffff00a1d5fcc
b 0xfffffff00a1d541c
sxtw x3,w25
mov w0,#0x11
movk w0,#0x1a1, LSL #16
mov x1,x22
mov x2,x28
mov x4,x26
bl 0xfffffff00a6de494
b 0xfffffff00a1d51e4
adrp x0,-0xff52cd000
add x0,x0,#0xc48
mov x1,x19
bl 0xfffffff00a226e08
b 0xfffffff00a1d54a0
mov w8,#0x4e6
adrp x9,-0xff8fa8000
add x9,x9,#0x4c2
adrp x10,-0xff8fa8000
add x10,x10,#0x50f
stp x9,x8,[sp, #0x8]
str x10,[sp]
adrp x0,-0xff8fa8000
add x0,x0,#0x4dc
bl 0xfffffff00aa4d114
sxtw x1,w21
sub x2,x8,x22
mov w8,#0x11
movk w8,#0x1a1, LSL #16
add w0,w8,#0x1
ldr x3,[sp, #0x20]
bl 0xfffffff00a6de494
b 0xfffffff00a1d548c
