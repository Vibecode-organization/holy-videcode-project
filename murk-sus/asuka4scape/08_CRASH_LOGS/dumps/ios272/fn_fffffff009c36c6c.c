// FUN_fffffff009c36c6c @ fffffff009c36c6c size=160

long * FUN_fffffff009c36c6c(long param_1,uint param_2,uint *param_3)

{
  bool bVar1;
  uint uVar2;
  long *plVar3;
  long *plVar4;
  
  *param_3 = 0;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x148));
  plVar4 = *(long **)(param_1 + 0x130);
  do {
    if (plVar4 == (long *)0x0) {
      plVar3 = (long *)0x0;
LAB_fffffff009c36cf0:
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x148));
      return plVar3;
    }
    uVar2 = *(uint *)(plVar4 + 4);
    bVar1 = param_2 < uVar2;
    param_2 = param_2 - uVar2;
    if (bVar1) {
      plVar3 = (long *)plVar4[1];
      if (plVar3 != (long *)0x0) {
        (**(code **)(*plVar3 + 0x20))(plVar3);
        uVar2 = *(uint *)(plVar4 + 4);
      }
      *param_3 = uVar2;
      goto LAB_fffffff009c36cf0;
    }
    plVar4 = (long *)*plVar4;
  } while( true );
}

