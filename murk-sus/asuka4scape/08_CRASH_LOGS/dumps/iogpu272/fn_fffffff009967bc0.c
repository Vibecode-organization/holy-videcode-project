// FUN_fffffff009967bc0 @ fffffff009967bc0 size=336

undefined8 FUN_fffffff009967bc0(long param_1,long *param_2,long param_3,long param_4,ulong param_5)

{
  long *plVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  
  FUN_fffffff00994463c(*(undefined8 *)(param_1 + 0x10));
  uVar4 = 0;
  if (param_5 == 0) {
LAB_fffffff009967c58:
    FUN_fffffff009944648(*(undefined8 *)(param_1 + 0x10));
    if (uVar4 != param_5) {
      uVar2 = 0xe00002c2;
      goto joined_r0xfffffff009967c8c;
    }
  }
  else {
    do {
      plVar1 = (long *)FUN_fffffff009945214
                                 (*(undefined8 *)(param_1 + 0x10),
                                  *(undefined4 *)(param_4 + uVar4 * 4));
      *(long **)(param_3 + uVar4 * 8) = plVar1;
      if ((plVar1 == (long *)0x0) || ((char)plVar1[2] == '\x03')) goto LAB_fffffff009967c58;
      (**(code **)(*plVar1 + 0x20))();
      uVar4 = uVar4 + 1;
    } while (param_5 != uVar4);
    FUN_fffffff009944648(*(undefined8 *)(param_1 + 0x10));
    uVar4 = param_5;
  }
  if (param_5 < 0x101) {
    uVar2 = FUN_fffffff009956c5c();
  }
  else {
    uVar2 = FUN_fffffff0099561c4(param_2,param_3,param_5);
  }
joined_r0xfffffff009967c8c:
  if (uVar4 != 0) {
    lVar3 = 0;
    do {
      (**(code **)(**(long **)(param_3 + lVar3 * 8) + 0x28))();
      *(undefined8 *)(param_3 + lVar3 * 8) = 0;
      lVar3 = lVar3 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  return uVar2;
}

