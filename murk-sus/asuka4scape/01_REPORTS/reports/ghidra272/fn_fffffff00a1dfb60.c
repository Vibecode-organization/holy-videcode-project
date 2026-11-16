// FUN_fffffff00a1dfb60 @ fffffff00a1dfb60 size=336
// DECOMPILE_FAILED
pacibsp
stp x24,x23,[sp, #-0x40]!
stp x22,x21,[sp, #0x10]
stp x20,x19,[sp, #0x20]
stp x29,x30,[sp, #0x30]
add x29,sp,#0x30
mov x19,x3
mov x20,x2
mov x21,x1
mov x17,x0
ldr x16,[x17, #0x48]!
cbz x16,0xfffffff00a1dfbb0
movk x17,#0xb8b5, LSL #48
autda x16,x17
tbnz x16,#0x26,0xfffffff00a1dfbc0
cbz x16,0xfffffff00a1dfbb0
ubfiz x9,x16,#0xe,#0xe
and x8,x16,#-0x4000
orr x10,x8,#0x4000000000
b 0xfffffff00a1dfbd4
mov w8,#0xc
ldr w22,[x8]
mov x23,#0x0
b 0xfffffff00a1dfc08
and x8,x16,#0x10
orr x8,x8,#0x20
and x9,x16,#0xf
lsl x9,x8,x9
and x10,x16,#-0x20
mov x8,x10
ldr w22,[x8, #0xc]!
mov w11,#0x18
umull x11,w22,w11
add x11,x11,#0x18
cmp x11,x9
b.hi 0xfffffff00a1dfbb8
add x9,x22,x22, LSL #0x1
add x23,x10,x9, LSL #0x3
eor x16,x10,x23
tst x16,#-0x40000000000000
b.eq 0xfffffff00a1dfc08
movk x23,#0xc8a2, LSL #48
cbz x23,0xfffffff00a1dfca4
ldr w9,[x23, #0xc]
str w9,[x8]
ldr w8,[x0, #0x18]
sub w8,w8,#0x1
str w8,[x0, #0x18]
ldr w8,[x23, #0x8]
lsl w9,w8,#0x2
and w9,w9,#0xc000000
mov w10,#0x4000000
add w9,w9,w10
adds w8,w8,w9
b.cc 0xfffffff00a1dfc58
mov x8,x0
add x0,x0,#0x20
add x1,x8,#0x1c
mov w2,#0x1
mov w3,#0x2
bl 0xfffffff00a36d048
lsl w8,w0,#0x18
stp w8,wzr,[x23, #0x8]
cbz x21,0xfffffff00a1dfc74
mov x16,x23
movk x16,#0xf444, LSL #48
mov x17,x21
pacda x17,x16
b 0xfffffff00a1dfc78
mov x17,#0x0
str x17,[x23]
extr w8,w22,w8,#0x18
orr w8,w8,#0x3
str w8,[x20]
str x23,[x19]
mov w0,#0x0
ldp x29,x30,[sp, #0x30]
ldp x20,x19,[sp, #0x20]
ldp x22,x21,[sp, #0x10]
ldp x24,x23,[sp], #0x40
retab
adrp x8,-0xff8395000
add x8,x8,#0xb0c
brk #0xbffc
