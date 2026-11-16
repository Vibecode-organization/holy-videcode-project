// FUN_fffffff00a2e457c @ fffffff00a2e457c size=720

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_fffffff00a2e457c
          (long param_1,ulong param_2,long param_3,ulong param_4,ulong param_5,undefined8 param_6,
          long param_7,uint *param_8)

{
  ulong uVar1;
  uint uVar2;
  long lVar3;
  ulong *puVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined *local_88;
  undefined8 local_80;
  code *local_78;
  undefined *local_70;
  uint local_68;
  ulong local_60;
  ulong local_58;
  
  if (*(byte *)(param_1 + 0x2c) < 0xe && (param_5 & 0x4000) == 0) {
    if ((param_4 & param_2) != 0) {
      return 3;
    }
    if ((param_5 & 0xfff000000) == 0x6000000 &&
        *(undefined8 **)(param_1 + 0x58) == &DAT_fffffff00ad6cc50) {
      return 3;
    }
  }
  else if ((param_4 & param_2) != 0) {
    return 3;
  }
  uVar5 = *(ulong *)(param_1 + 0x18);
  uVar6 = *(ulong *)(param_1 + 0x10);
  if ((*(uint *)(param_1 + 0xf8) & 0x8008) == 0x8000) {
    local_60 = 0;
    local_58 = 0;
    FUN_fffffff00a2e26f0(param_1,param_2,1,&local_60);
    uVar5 = local_58;
    uVar6 = local_60;
    if (local_58 == 0) {
      return 1;
    }
  }
  if (6 < DAT_fffffff007c6a5b8 && param_1 == DAT_fffffff007c678d8) {
    puVar4 = (ulong *)FUN_fffffff00a2dcab8(param_2,param_3);
    uVar6 = *puVar4;
    uVar5 = puVar4[1];
  }
  uVar7 = 1;
  uVar1 = param_3 + param_2;
  if (((param_2 < uVar1) && (uVar6 <= param_2)) && (uVar1 <= uVar5)) {
    if (((uint)param_5 >> 0xe & 1) == 0) {
      uVar7 = FUN_fffffff00a2fa8c0(param_1,param_2,uVar1,param_6,0);
    }
    else {
      uVar2 = (uint)(param_5 >> 0x20);
      local_88 = &DAT_fffffff00ad98dc0;
      local_80 = DAT_fffffff00700d9a0;
      local_78 = FUN_fffffff00a2e5134;
      local_70 = &DAT_fffffff007bca438;
      uVar2 = uVar2 >> 6 & 8 | uVar2 >> 5 & 0x20;
      *(undefined ***)(param_7 + 0x20) = &local_88;
      local_68 = uVar2;
      uVar7 = FUN_fffffff00a348784(param_7,param_1,param_2,uVar1,0x12a);
      if ((int)uVar7 != 0) {
        lVar3 = tpidr_el1;
        *(undefined8 *)(lVar3 + 0x228) = 0;
        *(undefined8 *)(param_7 + 0x10) = 0;
        *(undefined8 *)(param_7 + 0x18) = 0;
        *(undefined8 *)(param_7 + 0x34) = 0;
        *(undefined8 *)(param_7 + 0x2c) = 0;
        *(undefined8 *)(param_7 + 0x44) = 0;
        *(undefined8 *)(param_7 + 0x3c) = 0;
        *(undefined8 *)(param_7 + 0x54) = 0;
        *(undefined8 *)(param_7 + 0x4c) = 0;
        *(undefined8 *)(param_7 + 100) = 0;
        *(undefined8 *)(param_7 + 0x5c) = 0;
        *(undefined4 *)(param_7 + 0x6c) = 0;
      }
      lVar3 = tpidr_el1;
      *(int *)(lVar3 + 0x21c) = *(int *)(lVar3 + 0x21c) + 1;
      if (((*(ulong *)(param_1 + 0x38) & 0xffffffff0001ffff) == 0x10000) &&
         (*(int *)(param_1 + 0x3c) == 0)) {
        *(int *)(param_1 + 0x3c) = 2;
      }
      else {
        FUN_fffffff00a22a2a0(param_1 + 0x30,lVar3,0);
      }
      *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(lVar3 + 0x4e8);
      if ((int)uVar7 == 0) {
        *param_8 = uVar2;
      }
      if (*(undefined ***)(param_7 + 0x20) == &local_88) {
        *(undefined8 *)(param_7 + 0x20) = _DAT_fffffff00ad0e730;
      }
    }
  }
  return uVar7;
}

