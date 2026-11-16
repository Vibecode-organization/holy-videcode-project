// FUN_fffffff009c25e38 @ fffffff009c25e38 size=1252

/* WARNING: Removing unreachable block (ram,0xfffffff009c2630c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c262a4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c26244) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c261dc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2617c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c26114) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c260b4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c26054) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c25ff4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c25f90) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c25f60) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c25fc4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c26024) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c26084) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c260e4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c26140) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c261a8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2620c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c26274) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c262d0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c25ee0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c25f2c) */
/* WARNING: Type propagation algorithm not settling */

void FUN_fffffff009c25e38(long param_1,undefined8 *param_2,uint param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined8 uVar4;
  undefined8 uVar5;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  if ((param_3 & 1) != 0) {
    lVar3 = *(long *)(param_1 + 0x178);
    uVar4 = param_2[1];
    uVar2 = *param_2;
    uVar5 = param_2[2];
    *(undefined8 *)(lVar3 + 0x4c) = param_2[3];
    *(undefined8 *)(lVar3 + 0x44) = uVar5;
    *(undefined8 *)(lVar3 + 0x3c) = uVar4;
    *(undefined8 *)(lVar3 + 0x34) = uVar2;
  }
  if ((param_3 >> 1 & 1) != 0) {
    lVar3 = *(long *)(param_1 + 0x178);
    uVar2 = param_2[4];
    *(undefined8 *)(lVar3 + 0x5c) = param_2[5];
    *(undefined8 *)(lVar3 + 0x54) = uVar2;
  }
  if ((param_3 >> 2 & 1) != 0) {
    *(undefined8 *)(*(long *)(param_1 + 0x178) + 100) = param_2[6];
  }
  if ((param_3 >> 3 & 1) != 0) {
    *(undefined1 *)(*(long *)(param_1 + 0x178) + 0x6c) = *(undefined1 *)(param_2 + 7);
  }
  if ((param_3 >> 4 & 1) != 0) {
    *(undefined1 *)(*(long *)(param_1 + 0x178) + 0x6d) = *(undefined1 *)((long)param_2 + 0x39);
  }
  if ((param_3 >> 5 & 1) != 0) {
    *(undefined1 *)(*(long *)(param_1 + 0x178) + 0x6e) = *(undefined1 *)((long)param_2 + 0x3a);
  }
  if ((param_3 >> 6 & 1) != 0) {
    *(undefined1 *)(*(long *)(param_1 + 0x178) + 0x6f) = *(undefined1 *)((long)param_2 + 0x3b);
  }
  if ((param_3 >> 7 & 1) != 0) {
    *(undefined1 *)(*(long *)(param_1 + 0x178) + 0x70) = *(undefined1 *)((long)param_2 + 0x3c);
  }
  if ((param_3 >> 8 & 1) != 0) {
    *(undefined1 *)(*(long *)(param_1 + 0x178) + 0x71) = *(undefined1 *)((long)param_2 + 0x3d);
  }
  if ((param_3 >> 9 & 1) != 0) {
    *(undefined1 *)(*(long *)(param_1 + 0x178) + 0x72) = *(undefined1 *)((long)param_2 + 0x3e);
  }
  if ((param_3 >> 10 & 1) != 0) {
    *(undefined1 *)(*(long *)(param_1 + 0x178) + 0x73) = *(undefined1 *)((long)param_2 + 0x3f);
  }
  if ((param_3 >> 0xb & 1) != 0) {
    lVar3 = *(long *)(param_1 + 0x178);
    uVar2 = param_2[8];
    *(undefined8 *)(lVar3 + 0x7c) = param_2[9];
    *(undefined8 *)(lVar3 + 0x74) = uVar2;
    *(undefined8 *)(lVar3 + 0x84) = param_2[10];
  }
  if ((param_3 >> 0xc & 1) != 0) {
    *(undefined4 *)(*(long *)(param_1 + 0x178) + 0x8c) = *(undefined4 *)(param_2 + 0xb);
  }
  if ((param_3 >> 0xd & 1) != 0) {
    *(undefined8 *)(*(long *)(param_1 + 0x178) + 0x90) = *(undefined8 *)((long)param_2 + 0x5c);
  }
  if ((param_3 >> 0xe & 1) != 0) {
    *(undefined1 *)(*(long *)(param_1 + 0x178) + 0x98) = *(undefined1 *)((long)param_2 + 100);
  }
  if ((param_3 >> 0xf & 1) != 0) {
    lVar3 = *(long *)(param_1 + 0x178);
    *(undefined4 *)(lVar3 + 0x9c) = *(undefined4 *)(param_2 + 0xd);
    *(undefined4 *)(lVar3 + 0xa0) = *(undefined4 *)((long)param_2 + 0x6c);
  }
  if ((param_3 >> 0x10 & 1) != 0) {
    *(undefined4 *)(*(long *)(param_1 + 0x178) + 0xa4) = *(undefined4 *)(param_2 + 0xe);
  }
  if ((param_3 >> 0x11 & 1) != 0) {
    *(undefined1 *)(*(long *)(param_1 + 0x178) + 0x99) = *(undefined1 *)((long)param_2 + 0x65);
  }
  if ((param_3 >> 0x12 & 1) != 0) {
    *(undefined1 *)(*(long *)(param_1 + 0x178) + 0x9a) = *(undefined1 *)((long)param_2 + 0x66);
  }
  if ((param_3 >> 0x13 & 1) != 0) {
    lVar3 = *(long *)(param_1 + 0x178);
    uVar2 = *(undefined8 *)((long)param_2 + 0x74);
    *(undefined4 *)(lVar3 + 0xb0) = *(undefined4 *)((long)param_2 + 0x7c);
    *(undefined8 *)(lVar3 + 0xa8) = uVar2;
  }
  if ((param_3 >> 0x14 & 1) != 0) {
    *(undefined2 *)(*(long *)(param_1 + 0x178) + 0xb4) = *(undefined2 *)(param_2 + 0x10);
  }
  if ((param_3 >> 0x15 & 1) != 0) {
    *(undefined2 *)(*(long *)(param_1 + 0x178) + 0xb6) = *(undefined2 *)((long)param_2 + 0x82);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c25f08);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  return;
}

