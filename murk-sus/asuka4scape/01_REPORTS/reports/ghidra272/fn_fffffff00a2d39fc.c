// FUN_fffffff00a2d39fc @ fffffff00a2d39fc size=636

void FUN_fffffff00a2d39fc
               (long param_1,long param_2,ulong param_3,ulong param_4,undefined8 param_5,
               long param_6,int param_7,uint param_8,ulong param_9,int *param_10,uint param_11,
               long param_12,int param_13,undefined8 param_14,uint param_15,long *param_16)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  undefined4 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar4 = 0x1320008;
  if ((*(byte *)(param_2 + 0x75) >> 4 & 1) == 0) {
    uVar4 = 0x1320010;
    if ((*(byte *)(param_2 + 0xa9) & 1) != 0) {
      uVar4 = 0x1320014;
    }
  }
  lVar5 = param_1;
  if ((DAT_fffffff00ad98b00 & 0xfffffff7) != 0) {
    iVar2 = *(int *)(param_6 + 4);
    uVar7 = *(undefined8 *)(param_3 + 0x20);
    uVar6 = FUN_fffffff00a723ce4();
    lVar5 = FUN_fffffff00a6de494(uVar4,param_5,param_7 << 8 | iVar2 << 0x10 | param_8,uVar7,uVar6);
  }
  if ((param_9._4_4_ == 0) && (param_10 != (int *)0x0)) {
    if ((param_3 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= param_3)) {
      *param_10 = *(int *)(param_3 + 0x3c);
    }
    else {
      *param_10 = DAT_fffffff007bf0000 + (int)(param_3 - DAT_fffffff007bf0010 >> 6);
    }
    if ((param_11 >> 1 & 1) != 0) {
      *(byte *)(param_3 + 0x2d) = *(byte *)(param_3 + 0x2d) | 1;
    }
  }
  if (param_12 != 0) {
    lVar5 = FUN_fffffff00a22aeac(param_12 + 8);
  }
  if (param_13 != 0) {
    lVar5 = FUN_fffffff00a3042e8(param_1,param_4 & 0xffffffffffffc000,1);
  }
  if ((((param_9 & 1) == 0) && (param_8 < 9)) && ((1 << (ulong)(param_8 & 0x1f) & 400U) != 0)) {
    FUN_fffffff00a2d3c78(param_2,param_14,*(undefined4 *)(param_6 + 0x10));
    lVar5 = FUN_fffffff00a2d8658(param_2,param_14,param_6);
  }
  if ((*(ushort *)(param_3 + 0x2e) >> 0xc & 1) == 0) {
    lVar5 = FUN_fffffff00a329fb4(param_3,param_1,*(undefined8 *)(param_3 + 0x20));
    bVar3 = *(byte *)(param_3 + 0x2c);
  }
  else {
    bVar3 = *(byte *)(param_3 + 0x2c);
  }
  if ((bVar3 >> 2 & 1) != 0) {
    FUN_fffffff00a30a920(lVar5,param_3);
  }
  if ((((param_9 & 1) == 0) && ((param_15 >> 1 & 1) != 0)) &&
     ((*(byte *)(param_2 + 0x75) >> 4 & 1) == 0)) {
    uVar1 = *(ushort *)(param_2 + 0x6c) + 1;
    *(short *)(param_2 + 0x6c) = (short)uVar1;
    if (uVar1 >> 0x10 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114("vm_object_paging_begin(%p): overflow\n @%s:%d");
    }
    *param_16 = param_2;
    param_16[1] = *(long *)(param_2 + 0x50);
    param_16[2] = *(long *)(param_3 + 0x20) + *(long *)(param_2 + 0x60);
  }
  FUN_fffffff00a22aeac(param_1 + 8);
  return;
}

