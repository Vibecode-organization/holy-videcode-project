// FUN_fffffff009966328 @ fffffff009966328 size=340

undefined8 FUN_fffffff009966328(long param_1,long *param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  uint uVar6;
  
  param_2[1] = 0;
  *param_2 = 0;
  param_2[3] = 0;
  param_2[2] = 0;
  param_2[5] = 0;
  param_2[4] = 0;
  FUN_fffffff00994463c(*(undefined8 *)(param_1 + 0x10));
  lVar3 = *(long *)(param_1 + 0x10);
  uVar1 = *(uint *)(lVar3 + 0x28);
  if (1 < uVar1) {
    uVar6 = 1;
    do {
      lVar3 = FUN_fffffff009945214(*(undefined8 *)(param_1 + 0x10),uVar6);
      if ((lVar3 != 0) && ((*(uint *)(lVar3 + 0x10) & 0xf) != 3)) {
        lVar4 = FUN_fffffff009952c9c(lVar3);
        *param_2 = *param_2 + lVar4;
        iVar2 = FUN_fffffff00997f724(*(undefined8 *)(lVar3 + 0x20));
        if (iVar2 == 0) {
          param_2[2] = param_2[2] + lVar4;
        }
        else {
          param_2[2] = param_2[2] + lVar4;
          param_2[1] = param_2[1] + lVar4;
          param_2[3] = param_2[3] + lVar4;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar1 != uVar6);
    lVar3 = *(long *)(param_1 + 0x10);
  }
  FUN_fffffff009944648(lVar3);
  FUN_fffffff00994463c(*(undefined8 *)(param_1 + 0x78));
  lVar3 = *(long *)(param_1 + 0x78);
  uVar1 = *(uint *)(lVar3 + 0x28);
  if (1 < uVar1) {
    uVar6 = 1;
    do {
      plVar5 = (long *)FUN_fffffff009945214(*(undefined8 *)(param_1 + 0x78),uVar6);
      if (plVar5 != (long *)0x0) {
        lVar3 = (**(code **)(*plVar5 + 0x98))();
        *param_2 = *param_2 + lVar3;
      }
      uVar6 = uVar6 + 1;
    } while (uVar1 != uVar6);
    lVar3 = *(long *)(param_1 + 0x78);
  }
  FUN_fffffff009944648(lVar3);
  return 0;
}

