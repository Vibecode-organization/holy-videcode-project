// FUN_fffffff0081f10d8 @ fffffff0081f10d8 size=4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong FUN_fffffff0081f10d8(long param_1,long param_2,uint param_3)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  uint uVar5;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  
  if (param_2 != 0) {
    lVar2 = *(long *)(param_1 + 8);
    if ((uint)(*(int *)(lVar2 + 4) << 3) <= param_3) {
      uStack_50 = 0;
      uStack_58 = _UNK_fffffff0071150c0;
      uStack_60 = _DAT_fffffff0071150b8;
      if (*(int *)(lVar2 + 4) != 0) {
        uVar5 = 0;
        uVar4 = 0;
        do {
          uStack_58 = CONCAT71(uStack_58._1_7_,(char)uVar5);
          uStack_60._0_4_ = *(undefined4 *)(lVar2 + 0x1c);
          uVar1 = (**(code **)(lVar2 + 0x60))(&uStack_60);
          *(undefined4 *)(param_2 + uVar4 * 4) = uVar1;
          iVar3 = (int)uVar4;
          uStack_60._0_4_ = *(int *)(*(long *)(param_1 + 8) + 0x1c) + 8;
          uVar1 = (**(code **)(*(long *)(param_1 + 8) + 0x60))(&uStack_60);
          *(undefined4 *)(param_2 + (ulong)(iVar3 + 1) * 4) = uVar1;
          uStack_60._0_4_ = *(int *)(*(long *)(param_1 + 8) + 0x1c) + 0x10;
          uVar1 = (**(code **)(*(long *)(param_1 + 8) + 0x60))(&uStack_60);
          *(undefined4 *)(param_2 + (ulong)(iVar3 + 2) * 4) = uVar1;
          uStack_60._0_4_ = *(int *)(*(long *)(param_1 + 8) + 0x1c) + 0x18;
          uVar1 = (**(code **)(*(long *)(param_1 + 8) + 0x60))(&uStack_60);
          *(undefined4 *)(param_2 + (ulong)(iVar3 + 3) * 4) = uVar1;
          uStack_60._0_4_ = *(int *)(*(long *)(param_1 + 8) + 0x1c) + 0x20;
          uVar1 = (**(code **)(*(long *)(param_1 + 8) + 0x60))(&uStack_60);
          *(undefined4 *)(param_2 + (ulong)(iVar3 + 4) * 4) = uVar1;
          uStack_60._0_4_ = *(int *)(*(long *)(param_1 + 8) + 0x1c) + 0x28;
          uVar1 = (**(code **)(*(long *)(param_1 + 8) + 0x60))(&uStack_60);
          *(undefined4 *)(param_2 + (ulong)(iVar3 + 5) * 4) = uVar1;
          uStack_60._0_4_ = *(int *)(*(long *)(param_1 + 8) + 0x1c) + 0x30;
          uVar1 = (**(code **)(*(long *)(param_1 + 8) + 0x60))(&uStack_60);
          *(undefined4 *)(param_2 + (ulong)(iVar3 + 6) * 4) = uVar1;
          uStack_60 = CONCAT44(uStack_60._4_4_,*(int *)(*(long *)(param_1 + 8) + 0x1c) + 0x38);
          uVar1 = (**(code **)(*(long *)(param_1 + 8) + 0x60))(&uStack_60);
          *(undefined4 *)(param_2 + (ulong)(iVar3 + 7) * 4) = uVar1;
          uVar4 = (ulong)(iVar3 + 8);
          uVar5 = uVar5 + 1;
          lVar2 = *(long *)(param_1 + 8);
        } while (uVar5 < *(uint *)(lVar2 + 4));
        return uVar4;
      }
    }
  }
  return 0;
}

