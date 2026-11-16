// FUN_fffffff0270a8190 @ fffffff0270a8190 size=2220
// CALLERS:
//   fffffff0270f41e8 no-fn
// CALLEES:
// DECOMPILE_FAILED
bti c
adrp x7,-0xfd8f59000
add x7,x7,#0x200
ld1 {v16.4S,v17.4S,v18.4S,v19.4S},[x7]
eor v31.16B,v31.16B,v31.16B
ldr q30,[x2, #0x20]
ldr q0,[x2, #0x10]
ldr w6,[x5, #0xf0]
tbl v30.16B,{v30.16B},v18.16B
tbl v0.16B,{v0.16B},v18.16B
subs x3,x3,#0x80
b.lt 0xfffffff0270a884c
b 0xfffffff0270a8200
ldr q7,[x0, #0x70]
tbl v22.16B,{v30.16B},v18.16B
ldr q4,[x4]
add v23.4S,v16.4S,v30.4S
add v24.4S,v17.4S,v30.4S
ldr q6,[x4, #0x80]
tbl v7.16B,{v7.16B},v18.16B
add v25.4S,v17.4S,v23.4S
tbl v23.16B,{v23.16B},v18.16B
add v26.4S,v17.4S,v24.4S
pmull2 v2.1Q,v4.2D,v7.2D
tbl v24.16B,{v24.16B},v18.16B
ext v5.16B,v7.16B,v7.16B,0x8
add v27.4S,v17.4S,v25.4S
pmull v3.1Q,v4.1D,v7.1D
tbl v25.16B,{v25.16B},v18.16B
add v28.4S,v17.4S,v26.4S
eor v7.16B,v5.16B,v7.16B
tbl v26.16B,{v26.16B},v18.16B
add v29.4S,v17.4S,v27.4S
tbl v27.16B,{v27.16B},v18.16B
add v30.4S,v17.4S,v28.4S
pmull v1.1Q,v6.1D,v7.1D
ldr q20,[x5]
tbl v28.16B,{v28.16B},v18.16B
tbl v29.16B,{v29.16B},v18.16B
ldr q7,[x0, #0x60]
aese v22.16B,v20.16B
aesmc v22.16B,v22.16B
ldr q4,[x4, #0x10]
aese v23.16B,v20.16B
aesmc v23.16B,v23.16B
tbl v7.16B,{v7.16B},v18.16B
ldr q6,[x4, #0x90]
aese v24.16B,v20.16B
aesmc v24.16B,v24.16B
mov v5.16B,v2.16B
pmull2 v2.1Q,v4.2D,v7.2D
eor v2.16B,v5.16B,v2.16B
aese v25.16B,v20.16B
aesmc v25.16B,v25.16B
mov v5.16B,v3.16B
pmull v3.1Q,v4.1D,v7.1D
eor v3.16B,v5.16B,v3.16B
aese v26.16B,v20.16B
aesmc v26.16B,v26.16B
ext v5.16B,v7.16B,v7.16B,0x8
aese v27.16B,v20.16B
aesmc v27.16B,v27.16B
eor v5.16B,v7.16B,v5.16B
aese v28.16B,v20.16B
aesmc v28.16B,v28.16B
mov v4.16B,v1.16B
pmull v1.1Q,v6.1D,v5.1D
eor v1.16B,v4.16B,v1.16B
aese v29.16B,v20.16B
aesmc v29.16B,v29.16B
ldr q20,[x5, #0x10]
ldr q7,[x0, #0x50]
aese v22.16B,v20.16B
aesmc v22.16B,v22.16B
ldr q4,[x4, #0x20]
aese v23.16B,v20.16B
aesmc v23.16B,v23.16B
tbl v7.16B,{v7.16B},v18.16B
ldr q6,[x4, #0xa0]
aese v24.16B,v20.16B
aesmc v24.16B,v24.16B
mov v5.16B,v2.16B
pmull2 v2.1Q,v4.2D,v7.2D
eor v2.16B,v5.16B,v2.16B
aese v25.16B,v20.16B
aesmc v25.16B,v25.16B
mov v5.16B,v3.16B
pmull v3.1Q,v4.1D,v7.1D
eor v3.16B,v5.16B,v3.16B
aese v26.16B,v20.16B
aesmc v26.16B,v26.16B
ext v5.16B,v7.16B,v7.16B,0x8
aese v27.16B,v20.16B
aesmc v27.16B,v27.16B
eor v5.16B,v7.16B,v5.16B
aese v28.16B,v20.16B
aesmc v28.16B,v28.16B
mov v4.16B,v1.16B
pmull v1.1Q,v6.1D,v5.1D
eor v1.16B,v4.16B,v1.16B
aese v29.16B,v20.16B
aesmc v29.16B,v29.16B
ldr q20,[x5, #0x20]
ldr q7,[x0, #0x40]
aese v22.16B,v20.16B
aesmc v22.16B,v22.16B
ldr q4,[x4, #0x30]
aese v23.16B,v20.16B
aesmc v23.16B,v23.16B
tbl v7.16B,{v7.16B},v18.16B
ldr q6,[x4, #0xb0]
aese v24.16B,v20.16B
aesmc v24.16B,v24.16B
mov v5.16B,v2.16B
pmull2 v2.1Q,v4.2D,v7.2D
eor v2.16B,v5.16B,v2.16B
aese v25.16B,v20.16B
aesmc v25.16B,v25.16B
mov v5.16B,v3.16B
pmull v3.1Q,v4.1D,v7.1D
eor v3.16B,v5.16B,v3.16B
aese v26.16B,v20.16B
aesmc v26.16B,v26.16B
ext v5.16B,v7.16B,v7.16B,0x8
aese v27.16B,v20.16B
aesmc v27.16B,v27.16B
eor v5.16B,v7.16B,v5.16B
aese v28.16B,v20.16B
aesmc v28.16B,v28.16B
mov v4.16B,v1.16B
pmull v1.1Q,v6.1D,v5.1D
eor v1.16B,v4.16B,v1.16B
aese v29.16B,v20.16B
aesmc v29.16B,v29.16B
ldr q20,[x5, #0x30]
ldr q7,[x0, #0x30]
aese v22.16B,v20.16B
aesmc v22.16B,v22.16B
ldr q4,[x4, #0x40]
aese v23.16B,v20.16B
aesmc v23.16B,v23.16B
tbl v7.16B,{v7.16B},v18.16B
ldr q6,[x4, #0xc0]
aese v24.16B,v20.16B
aesmc v24.16B,v24.16B
mov v5.16B,v2.16B
pmull2 v2.1Q,v4.2D,v7.2D
eor v2.16B,v5.16B,v2.16B
aese v25.16B,v20.16B
aesmc v25.16B,v25.16B
mov v5.16B,v3.16B
pmull v3.1Q,v4.1D,v7.1D
eor v3.16B,v5.16B,v3.16B
aese v26.16B,v20.16B
aesmc v26.16B,v26.16B
ext v5.16B,v7.16B,v7.16B,0x8
aese v27.16B,v20.16B
aesmc v27.16B,v27.16B
eor v5.16B,v7.16B,v5.16B
aese v28.16B,v20.16B
aesmc v28.16B,v28.16B
mov v4.16B,v1.16B
pmull v1.1Q,v6.1D,v5.1D
eor v1.16B,v4.16B,v1.16B
aese v29.16B,v20.16B
aesmc v29.16B,v29.16B
ldr q20,[x5, #0x40]
ldr q7,[x0, #0x20]
aese v22.16B,v20.16B
aesmc v22.16B,v22.16B
ldr q4,[x4, #0x50]
aese v23.16B,v20.16B
aesmc v23.16B,v23.16B
tbl v7.16B,{v7.16B},v18.16B
ldr q6,[x4, #0xd0]
aese v24.16B,v20.16B
aesmc v24.16B,v24.16B
mov v5.16B,v2.16B
pmull2 v2.1Q,v4.2D,v7.2D
eor v2.16B,v5.16B,v2.16B
aese v25.16B,v20.16B
aesmc v25.16B,v25.16B
mov v5.16B,v3.16B
pmull v3.1Q,v4.1D,v7.1D
eor v3.16B,v5.16B,v3.16B
aese v26.16B,v20.16B
aesmc v26.16B,v26.16B
ext v5.16B,v7.16B,v7.16B,0x8
aese v27.16B,v20.16B
aesmc v27.16B,v27.16B
eor v5.16B,v7.16B,v5.16B
aese v28.16B,v20.16B
aesmc v28.16B,v28.16B
mov v4.16B,v1.16B
pmull v1.1Q,v6.1D,v5.1D
eor v1.16B,v4.16B,v1.16B
aese v29.16B,v20.16B
aesmc v29.16B,v29.16B
ldr q20,[x5, #0x50]
ldr q7,[x0, #0x10]
aese v22.16B,v20.16B
aesmc v22.16B,v22.16B
ldr q4,[x4, #0x60]
aese v23.16B,v20.16B
aesmc v23.16B,v23.16B
tbl v7.16B,{v7.16B},v18.16B
ldr q6,[x4, #0xe0]
aese v24.16B,v20.16B
aesmc v24.16B,v24.16B
mov v5.16B,v2.16B
pmull2 v2.1Q,v4.2D,v7.2D
eor v2.16B,v5.16B,v2.16B
aese v25.16B,v20.16B
aesmc v25.16B,v25.16B
mov v5.16B,v3.16B
pmull v3.1Q,v4.1D,v7.1D
eor v3.16B,v5.16B,v3.16B
aese v26.16B,v20.16B
aesmc v26.16B,v26.16B
ext v5.16B,v7.16B,v7.16B,0x8
aese v27.16B,v20.16B
aesmc v27.16B,v27.16B
eor v5.16B,v7.16B,v5.16B
aese v28.16B,v20.16B
aesmc v28.16B,v28.16B
mov v4.16B,v1.16B
pmull v1.1Q,v6.1D,v5.1D
eor v1.16B,v4.16B,v1.16B
aese v29.16B,v20.16B
aesmc v29.16B,v29.16B
ldr q20,[x5, #0x60]
ldr q7,[x0]
aese v22.16B,v20.16B
aesmc v22.16B,v22.16B
tbl v7.16B,{v7.16B},v18.16B
ldr q4,[x4, #0x70]
aese v23.16B,v20.16B
aesmc v23.16B,v23.16B
eor v7.16B,v7.16B,v0.16B
ldr q6,[x4, #0xf0]
aese v24.16B,v20.16B
aesmc v24.16B,v24.16B
mov v5.16B,v2.16B
pmull2 v2.1Q,v4.2D,v7.2D
eor v2.16B,v5.16B,v2.16B
aese v25.16B,v20.16B
aesmc v25.16B,v25.16B
mov v5.16B,v3.16B
pmull v3.1Q,v4.1D,v7.1D
eor v3.16B,v5.16B,v3.16B
aese v26.16B,v20.16B
aesmc v26.16B,v26.16B
ext v5.16B,v7.16B,v7.16B,0x8
aese v27.16B,v20.16B
aesmc v27.16B,v27.16B
eor v5.16B,v7.16B,v5.16B
aese v28.16B,v20.16B
aesmc v28.16B,v28.16B
mov v4.16B,v1.16B
pmull v1.1Q,v6.1D,v5.1D
eor v1.16B,v4.16B,v1.16B
aese v29.16B,v20.16B
aesmc v29.16B,v29.16B
ldr q20,[x5, #0x70]
eor v1.16B,v2.16B,v1.16B
aese v22.16B,v20.16B
aesmc v22.16B,v22.16B
eor v1.16B,v3.16B,v1.16B
aese v23.16B,v20.16B
aesmc v23.16B,v23.16B
ext v4.16B,v1.16B,v31.16B,0x8
ext v5.16B,v31.16B,v1.16B,0x8
aese v24.16B,v20.16B
aesmc v24.16B,v24.16B
aese v25.16B,v20.16B
aesmc v25.16B,v25.16B
eor v6.16B,v4.16B,v2.16B
eor v0.16B,v5.16B,v3.16B
aese v26.16B,v20.16B
aesmc v26.16B,v26.16B
ext v2.16B,v0.16B,v0.16B,0x8
pmull v0.1Q,v19.1D,v0.1D
eor v0.16B,v2.16B,v0.16B
aese v27.16B,v20.16B
aesmc v27.16B,v27.16B
aese v28.16B,v20.16B
aesmc v28.16B,v28.16B
aese v29.16B,v20.16B
aesmc v29.16B,v29.16B
ldr q20,[x5, #0x80]
aese v22.16B,v20.16B
aesmc v22.16B,v22.16B
aese v23.16B,v20.16B
aesmc v23.16B,v23.16B
ext v2.16B,v0.16B,v0.16B,0x8
pmull v0.1Q,v19.1D,v0.1D
eor v0.16B,v2.16B,v0.16B
aese v24.16B,v20.16B
aesmc v24.16B,v24.16B
aese v25.16B,v20.16B
aesmc v25.16B,v25.16B
aese v26.16B,v20.16B
aesmc v26.16B,v26.16B
aese v27.16B,v20.16B
aesmc v27.16B,v27.16B
aese v28.16B,v20.16B
aesmc v28.16B,v28.16B
aese v29.16B,v20.16B
aesmc v29.16B,v29.16B
eor v0.16B,v6.16B,v0.16B
ldr q20,[x5, #0x90]
ldr q21,[x5, #0xa0]
cmp w6,#0xa0
b.le 0xfffffff0270a87d4
aese v22.16B,v20.16B
aesmc v22.16B,v22.16B
aese v23.16B,v20.16B
aesmc v23.16B,v23.16B
aese v24.16B,v20.16B
aesmc v24.16B,v24.16B
aese v25.16B,v20.16B
aesmc v25.16B,v25.16B
aese v26.16B,v20.16B
aesmc v26.16B,v26.16B
aese v27.16B,v20.16B
aesmc v27.16B,v27.16B
aese v28.16B,v20.16B
aesmc v28.16B,v28.16B
aese v29.16B,v20.16B
aesmc v29.16B,v29.16B
ldr q20,[x5, #0xa0]
aese v22.16B,v20.16B
aesmc v22.16B,v22.16B
aese v23.16B,v20.16B
aesmc v23.16B,v23.16B
aese v24.16B,v20.16B
aesmc v24.16B,v24.16B
aese v25.16B,v20.16B
aesmc v25.16B,v25.16B
aese v26.16B,v20.16B
aesmc v26.16B,v26.16B
aese v27.16B,v20.16B
aesmc v27.16B,v27.16B
aese v28.16B,v20.16B
aesmc v28.16B,v28.16B
aese v29.16B,v20.16B
aesmc v29.16B,v29.16B
ldr q20,[x5, #0xb0]
ldr q21,[x5, #0xc0]
cmp w6,#0xc0
b.le 0xfffffff0270a87d4
aese v22.16B,v20.16B
aesmc v22.16B,v22.16B
aese v23.16B,v20.16B
aesmc v23.16B,v23.16B
aese v24.16B,v20.16B
aesmc v24.16B,v24.16B
aese v25.16B,v20.16B
aesmc v25.16B,v25.16B
aese v26.16B,v20.16B
aesmc v26.16B,v26.16B
aese v27.16B,v20.16B
aesmc v27.16B,v27.16B
aese v28.16B,v20.16B
aesmc v28.16B,v28.16B
aese v29.16B,v20.16B
aesmc v29.16B,v29.16B
ldr q20,[x5, #0xc0]
aese v22.16B,v20.16B
aesmc v22.16B,v22.16B
aese v23.16B,v20.16B
aesmc v23.16B,v23.16B
aese v24.16B,v20.16B
aesmc v24.16B,v24.16B
aese v25.16B,v20.16B
aesmc v25.16B,v25.16B
aese v26.16B,v20.16B
aesmc v26.16B,v26.16B
aese v27.16B,v20.16B
aesmc v27.16B,v27.16B
aese v28.16B,v20.16B
aesmc v28.16B,v28.16B
aese v29.16B,v20.16B
aesmc v29.16B,v29.16B
ldr q20,[x5, #0xd0]
ldr q21,[x5, #0xe0]
ld1 {v4.4S,v5.4S,v6.4S,v7.4S},[x0], #0x40
aese v22.16B,v20.16B
eor v22.16B,v22.16B,v21.16B
aese v23.16B,v20.16B
eor v23.16B,v23.16B,v21.16B
aese v24.16B,v20.16B
eor v24.16B,v24.16B,v21.16B
aese v25.16B,v20.16B
eor v25.16B,v25.16B,v21.16B
eor v22.16B,v4.16B,v22.16B
eor v23.16B,v5.16B,v23.16B
eor v24.16B,v6.16B,v24.16B
eor v25.16B,v7.16B,v25.16B
ld1 {v4.4S,v5.4S,v6.4S,v7.4S},[x0], #0x40
aese v26.16B,v20.16B
eor v26.16B,v26.16B,v21.16B
aese v27.16B,v20.16B
eor v27.16B,v27.16B,v21.16B
aese v28.16B,v20.16B
eor v28.16B,v28.16B,v21.16B
aese v29.16B,v20.16B
eor v29.16B,v29.16B,v21.16B
st1 {v22.4S,v23.4S,v24.4S,v25.4S},[x1], #0x40
eor v26.16B,v4.16B,v26.16B
eor v27.16B,v5.16B,v27.16B
eor v28.16B,v6.16B,v28.16B
eor v29.16B,v7.16B,v29.16B
st1 {v26.4S,v27.4S,v28.4S,v29.4S},[x1], #0x40
subs x3,x3,#0x80
b.ge 0xfffffff0270a8200
adds x3,x3,#0x70
b.lt 0xfffffff0270a8a64
ldr q7,[x0]
add x7,x4,x3
tbl v7.16B,{v7.16B},v18.16B
ldr q4,[x4,x3]
eor v7.16B,v0.16B,v7.16B
ldr q0,[x7, #0x80]
ext v5.16B,v7.16B,v7.16B,0x8
pmull2 v2.1Q,v4.2D,v7.2D
eor v5.16B,v5.16B,v7.16B
pmull v3.1Q,v4.1D,v7.1D
pmull v1.1Q,v0.1D,v5.1D
mov x7,x5
tbl v7.16B,{v30.16B},v18.16B
ld1 {v4.4S,v5.4S,v6.4S},[x7], #0x30
add v30.4S,v16.4S,v30.4S
aese v7.16B,v4.16B
aesmc v7.16B,v7.16B
aese v7.16B,v5.16B
aesmc v7.16B,v7.16B
aese v7.16B,v6.16B
aesmc v7.16B,v7.16B
ld1 {v4.4S,v5.4S,v6.4S},[x7], #0x30
aese v7.16B,v4.16B
aesmc v7.16B,v7.16B
aese v7.16B,v5.16B
aesmc v7.16B,v7.16B
aese v7.16B,v6.16B
aesmc v7.16B,v7.16B
ld1 {v4.4S,v5.4S,v6.4S},[x7], #0x30
aese v7.16B,v4.16B
aesmc v7.16B,v7.16B
aese v7.16B,v5.16B
aesmc v7.16B,v7.16B
aese v7.16B,v6.16B
aesmc v7.16B,v7.16B
ld1 {v20.4S,v21.4S},[x7], #0x20
cmp w6,#0xa0
b.le 0xfffffff0270a891c
aese v7.16B,v20.16B
aesmc v7.16B,v7.16B
aese v7.16B,v21.16B
aesmc v7.16B,v7.16B
ld1 {v20.4S,v21.4S},[x7], #0x20
cmp w6,#0xc0
b.le 0xfffffff0270a891c
aese v7.16B,v20.16B
aesmc v7.16B,v7.16B
aese v7.16B,v21.16B
aesmc v7.16B,v7.16B
ld1 {v20.4S,v21.4S},[x7], #0x20
aese v7.16B,v20.16B
eor v7.16B,v7.16B,v21.16B
ld1 {v4.4S},[x0], #0x10
eor v7.16B,v4.16B,v7.16B
st1 {v7.4S},[x1], #0x10
subs x3,x3,#0x10
b.lt 0xfffffff0270a8a30
ldr q7,[x0]
tbl v7.16B,{v7.16B},v18.16B
add x7,x4,x3
ldr q4,[x7]
mov v5.16B,v2.16B
pmull2 v2.1Q,v4.2D,v7.2D
eor v2.16B,v5.16B,v2.16B
mov v5.16B,v3.16B
pmull v3.1Q,v4.1D,v7.1D
eor v3.16B,v5.16B,v3.16B
ldr q4,[x7, #0x80]
ext v5.16B,v7.16B,v7.16B,0x8
eor v7.16B,v5.16B,v7.16B
mov v5.16B,v1.16B
pmull v1.1Q,v4.1D,v7.1D
eor v1.16B,v5.16B,v1.16B
mov x7,x5
tbl v7.16B,{v30.16B},v18.16B
ld1 {v4.4S,v5.4S,v6.4S},[x7], #0x30
add v30.4S,v16.4S,v30.4S
aese v7.16B,v4.16B
aesmc v7.16B,v7.16B
aese v7.16B,v5.16B
aesmc v7.16B,v7.16B
aese v7.16B,v6.16B
aesmc v7.16B,v7.16B
ld1 {v4.4S,v5.4S,v6.4S},[x7], #0x30
aese v7.16B,v4.16B
aesmc v7.16B,v7.16B
aese v7.16B,v5.16B
aesmc v7.16B,v7.16B
aese v7.16B,v6.16B
aesmc v7.16B,v7.16B
ld1 {v4.4S,v5.4S,v6.4S},[x7], #0x30
aese v7.16B,v4.16B
aesmc v7.16B,v7.16B
aese v7.16B,v5.16B
aesmc v7.16B,v7.16B
aese v7.16B,v6.16B
aesmc v7.16B,v7.16B
ld1 {v20.4S,v21.4S},[x7], #0x20
cmp w6,#0xa0
b.le 0xfffffff0270a8a14
aese v7.16B,v20.16B
aesmc v7.16B,v7.16B
aese v7.16B,v21.16B
aesmc v7.16B,v7.16B
ld1 {v20.4S,v21.4S},[x7], #0x20
cmp w6,#0xc0
b.le 0xfffffff0270a8a14
aese v7.16B,v20.16B
aesmc v7.16B,v7.16B
aese v7.16B,v21.16B
aesmc v7.16B,v7.16B
ld1 {v20.4S,v21.4S},[x7], #0x20
aese v7.16B,v20.16B
eor v7.16B,v7.16B,v21.16B
ld1 {v4.4S},[x0], #0x10
eor v7.16B,v4.16B,v7.16B
st1 {v7.4S},[x1], #0x10
subs x3,x3,#0x10
b.ge 0xfffffff0270a8938
eor v1.16B,v2.16B,v1.16B
eor v1.16B,v3.16B,v1.16B
ext v5.16B,v1.16B,v31.16B,0x8
eor v6.16B,v5.16B,v2.16B
ext v5.16B,v31.16B,v1.16B,0x8
eor v0.16B,v5.16B,v3.16B
ext v2.16B,v0.16B,v0.16B,0x8
pmull v0.1Q,v19.1D,v0.1D
eor v0.16B,v2.16B,v0.16B
ext v2.16B,v0.16B,v0.16B,0x8
pmull v0.1Q,v19.1D,v0.1D
eor v0.16B,v2.16B,v0.16B
eor v0.16B,v6.16B,v0.16B
tbl v0.16B,{v0.16B},v18.16B
tbl v30.16B,{v30.16B},v18.16B
str q0,[x2, #0x10]
str q30,[x2, #0x20]
ret
