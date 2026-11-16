// FUN_fffffff00996eb38 @ fffffff00996eb38 size=392

undefined8
FUN_fffffff00996eb38
          (long param_1,undefined4 param_2,long *param_3,long *param_4,uint param_5,
          undefined8 param_6)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long *plVar4;
  
  iVar1 = (*DAT_fffffff007feb260)();
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x38) = param_2;
    plVar4 = *(long **)(param_1 + 0x20);
    *(long **)(param_1 + 0x20) = param_3;
    if (param_3 != (long *)0x0) {
      (**(code **)(*param_3 + 0x20))(param_3);
    }
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
    plVar4 = *(long **)(param_1 + 0x28);
    *(long **)(param_1 + 0x28) = param_4;
    if (param_4 != (long *)0x0) {
      (**(code **)(*param_4 + 0x20))(param_4);
    }
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
    lVar2 = thunk_EXT_FUN_80110000038fe5cc((ulong)param_5 << 4);
    *(long *)(param_1 + 0x30) = lVar2;
    if (lVar2 != 0) {
      *(uint *)(param_1 + 0x3c) = param_5;
      thunk_EXT_FUN_8011000003a61b10(lVar2,param_6,(ulong)param_5 << 4);
      uVar3 = 1;
      goto joined_r0xfffffff00996ec60;
    }
  }
  uVar3 = 0;
joined_r0xfffffff00996ec60:
  if (param_4 != (long *)0x0) {
    (**(code **)(*param_4 + 0x28))(param_4);
  }
  if (param_3 != (long *)0x0) {
    (**(code **)(*param_3 + 0x28))(param_3);
  }
  return uVar3;
}

