// FUN_fffffff0081a7870 @ fffffff0081a7870 size=292

long * FUN_fffffff0081a7870(long param_1,long *param_2,uint param_3,int param_4)

{
  ulong uVar1;
  long *plVar2;
  ulong uVar3;
  
  if (param_2 == (long *)0x0) {
    plVar2 = (long *)0x0;
  }
  else {
    if ((param_3 < 0xe) && ((1 << (ulong)(param_3 & 0x1f) & 0x2041U) != 0)) {
      plVar2 = (long *)thunk_EXT_FUN_8011000003a49114
                                 (
                                 "AGXk: %s:%d:%s: !!! Assertion failed: %s: attempting to encode illegal memory range\n"
                                 );
      return plVar2;
    }
    uVar1 = 0x20900000000;
    if (param_3 != 9) {
      uVar1 = (ulong)(param_3 & 0xf) << 0x20;
    }
    uVar3 = 0x10000000085;
    if (param_4 == 0) {
      uVar3 = 0x87;
    }
    plVar2 = (long *)(**(code **)(*param_2 + 0x90))
                               (param_2,*(undefined8 *)(*(long *)(param_1 + 0x280) + 0x11da0),
                                uVar1 | uVar3);
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x20))(plVar2);
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
  }
  return plVar2;
}

