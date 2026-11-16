// FUN_fffffff009982f10 @ fffffff009982f10 size=224

ulong FUN_fffffff009982f10(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  long lVar2;
  long *plVar3;
  undefined8 uVar4;
  
  uVar1 = (*DAT_fffffff007feb260)();
  if ((int)uVar1 != 0) {
    lVar2 = thunk_EXT_FUN_80110000038ff010();
    *(long *)(param_1 + 0x28) = lVar2;
    uVar1 = 0;
    if (lVar2 != 0) {
      plVar3 = (long *)thunk_EXT_FUN_80110000039afb74(param_3,param_4);
      *(long **)(param_1 + 0x10) = plVar3;
      uVar1 = 0;
      if ((plVar3 != (long *)0x0) &&
         (plVar3 = (long *)(**(code **)(*plVar3 + 0xa0))(), uVar1 = 0, plVar3 != (long *)0x0)) {
        uVar4 = thunk_EXT_FUN_801100000396cb64(plVar3,param_2,0,1,0,0);
        *(undefined8 *)(param_1 + 0x18) = uVar4;
        (**(code **)(*plVar3 + 0x28))(plVar3);
        uVar1 = (ulong)(*(long *)(param_1 + 0x18) != 0);
      }
    }
  }
  return uVar1;
}

