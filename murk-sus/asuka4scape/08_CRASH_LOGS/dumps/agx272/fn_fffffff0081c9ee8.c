// FUN_fffffff0081c9ee8 @ fffffff0081c9ee8 size=312

undefined8 FUN_fffffff0081c9ee8(long param_1,int *param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  
  if (((uint)param_3 >> 3 & 1) != 0) {
    if (*param_2 == 8) {
      lVar5 = 0x18;
      lVar6 = 0x580;
    }
    else {
      if (*param_2 != 0x26) goto LAB_fffffff0081c9f50;
      lVar5 = 0x14;
      lVar6 = 0x588;
    }
    if (*(long *)(*(long *)(param_1 + 0x280) + lVar6) != *(long *)((long)param_2 + lVar5)) {
      return 0;
    }
  }
LAB_fffffff0081c9f50:
  uVar4 = FUN_fffffff0081a6e20(param_1,param_2,param_3);
  uVar2 = (**(code **)(*(long *)(param_1 + 0x848) + 0x38))(param_1 + 0x848);
  uVar3 = (**(code **)(*(long *)(param_1 + 0x848) + 0x30))(param_1 + 0x848);
  uVar1 = uVar2 - uVar3;
  if (uVar2 < uVar3 || uVar1 == 0) {
    uVar1 = uVar1 + 0x100;
  }
  if ((int)uVar4 == 0) {
    if ((param_3 & 3) != 0 || 0xc0 < uVar1) {
      (**(code **)(**(long **)(param_1 + 0x1460) + 0x568))
                (*(long **)(param_1 + 0x1460),0x84000000000011,(uint)param_3 >> 4 & 1);
      return 0;
    }
    return uVar4;
  }
  return uVar4;
}

