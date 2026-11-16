// FUN_fffffff009c3c800 @ fffffff009c3c800 size=212
// CALLERS:

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff009c3c800(long param_1,long param_2,ulong param_3)

{
  long *plVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar3 = 0xe00002c2;
  plVar1 = (long *)FUN_fffffff009c49764
                             (param_2 + 0xc,(param_2 + (param_3 & 0xffffffff)) - (param_2 + 0xc),0);
  if (plVar1 != (long *)0x0) {
    lVar2 = FUN_fffffff009c498d4(plVar1,*_DAT_fffffff00806c9f0);
    if (lVar2 != 0) {
      FUN_fffffff009c49684(*(undefined8 *)(param_1 + 0xe0));
      uVar3 = FUN_fffffff009c49a74(lVar2,0);
      if (*(long **)(param_1 + 0x130) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x130) + 0x28))();
      }
      *(undefined8 *)(param_1 + 0x130) = uVar3;
      FUN_fffffff009c49674(*(undefined8 *)(param_1 + 0xe0));
      uVar3 = 0;
    }
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar3;
}

