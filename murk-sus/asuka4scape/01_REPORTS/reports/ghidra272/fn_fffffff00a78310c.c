// FUN_fffffff00a78310c @ fffffff00a78310c size=364

uint FUN_fffffff00a78310c(long param_1,undefined8 *param_2,long param_3,long param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  
  if (*(char *)(param_1 + 0x40) == -2) {
    uVar2 = 0x3fe - (*(int *)(param_4 + 0x10) + *(int *)(param_4 + 0x48));
    if ((*(int *)(param_4 + 0x48) == 0) && ((*(byte *)(param_4 + 0x169) & 1) != 0)) {
      uVar2 = 1;
    }
    lVar4 = 0;
    uVar2 = uVar2 & ((int)uVar2 >> 0x1f ^ 0xffffffffU);
    goto LAB_fffffff00a7831a4;
  }
  if (*(char *)(param_1 + 0x40) != -1) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114("ptmx kevent: unexpected filter: %d, kn = %p, tty = %p @%s:%d");
  }
  iVar1 = *(int *)(param_4 + 0x80);
  lVar4 = (long)iVar1;
  if ((iVar1 != 0) && ((*(byte *)(param_4 + 0xc1) & 1) == 0)) {
    uVar2 = (uint)(0 < iVar1);
    goto LAB_fffffff00a7831a4;
  }
  if (param_3 == 0) {
LAB_fffffff00a783188:
    uVar2 = 0;
    lVar4 = 0;
  }
  else {
    if (((*(ushort *)(param_3 + 10) >> 3 & 1) == 0) || (*(char *)(param_3 + 0x80) == '\0')) {
      if ((*(ushort *)(param_3 + 10) >> 7 & 1) == 0) goto LAB_fffffff00a783188;
      if (*(char *)(param_3 + 0x81) == '\0') {
        lVar4 = 0;
        uVar2 = 0;
        goto LAB_fffffff00a7831a4;
      }
    }
    lVar4 = 0;
    uVar2 = 1;
  }
LAB_fffffff00a7831a4:
  if ((*(uint *)(param_4 + 0xc0) & 0x120000) == 0x20000) {
    if (0x7fffffff < (uint)(int)(short)*(ushort *)(param_1 + 0x42)) {
      uVar2 = 1;
    }
  }
  else {
    *(ushort *)(param_1 + 0x42) = *(ushort *)(param_1 + 0x42) | 0x8000;
    uVar2 = 1;
  }
  uVar3 = uVar2;
  if ((param_2 != (undefined8 *)0x0) && (uVar3 = 0, uVar2 != 0)) {
    uVar7 = *(undefined8 *)(param_1 + 0x60);
    uVar6 = *(undefined8 *)(param_1 + 0x58);
    uVar9 = *(undefined8 *)(param_1 + 0x70);
    uVar8 = *(undefined8 *)(param_1 + 0x68);
    uVar5 = *(undefined8 *)(param_1 + 0x78);
    uVar10 = *(undefined8 *)(param_1 + 0x48);
    param_2[3] = *(undefined8 *)(param_1 + 0x50);
    param_2[2] = uVar10;
    uVar10 = *(undefined8 *)(param_1 + 0x38);
    param_2[1] = *(undefined8 *)(param_1 + 0x40);
    *param_2 = uVar10;
    param_2[8] = uVar5;
    param_2[5] = uVar7;
    param_2[4] = uVar6;
    param_2[7] = uVar9;
    param_2[6] = uVar8;
    *(undefined4 *)((long)param_2 + 0x1c) = 0;
    *(ushort *)(param_2 + 1) = *(ushort *)(param_2 + 1) | 0xff00;
    if ((*(byte *)(param_1 + 0x42) >> 5 & 1) != 0) {
      *(undefined4 *)(param_1 + 0x50) = 0;
    }
    *(short *)(param_2 + 1) = (short)*(char *)(param_1 + 0x40);
    param_2[4] = lVar4;
    return uVar2;
  }
  return uVar3;
}

