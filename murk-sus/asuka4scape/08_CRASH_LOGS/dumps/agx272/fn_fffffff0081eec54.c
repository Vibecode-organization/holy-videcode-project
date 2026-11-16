// FUN_fffffff0081eec54 @ fffffff0081eec54 size=288

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff0081eec54(long param_1,undefined8 param_2,long *param_3)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  uStack_38 = _UNK_fffffff007c9dc50;
  local_40 = _DAT_fffffff007c9dc48;
  uStack_28 = _UNK_fffffff007c9dc60;
  uStack_30 = _DAT_fffffff007c9dc58;
  iVar1 = (**(code **)(*param_3 + 0x3a8))
                    (param_3,DAT_fffffff00ae23540,0,0,&local_40,param_1 + 0x30,
                     *(undefined8 *)(param_1 + 0x10));
  if (iVar1 == 0) {
    plVar3 = *(long **)(param_1 + 0x30);
    uVar2 = 0;
    if (plVar3 != (long *)0x0) {
      iVar1 = (**(code **)(*plVar3 + 0x88))(plVar3,0,0x10000);
      if (iVar1 == 0) {
        *(undefined1 *)(param_1 + 0x18) = 1;
        *(long **)(param_1 + 0x20) = param_3;
        (**(code **)(*param_3 + 0x20))(param_3);
        (**(code **)(**(long **)(param_1 + 0x30) + 0x20))();
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
        *(undefined8 *)(param_1 + 0x30) = 0;
        *(undefined8 *)(param_1 + 0x10) = 0;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

