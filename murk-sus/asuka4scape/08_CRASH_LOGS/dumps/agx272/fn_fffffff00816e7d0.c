// FUN_fffffff00816e7d0 @ fffffff00816e7d0 size=12

void FUN_fffffff00816e7d0(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  long *plVar3;
  undefined *puStack_68;
  undefined8 uStack_60;
  code *pcStack_58;
  undefined *puStack_50;
  long lStack_48;
  undefined8 uStack_40;
  undefined4 uStack_38;
  
  if ((*(byte *)(param_2 + 0x4c) & 1) == 0) {
    plVar3 = *(long **)(param_2 + 0x230);
    puStack_68 = PTR_DAT_fffffff007ca5f90;
    uStack_60 = DAT_fffffff007113e50;
    pcStack_58 = FUN_fffffff00816e908;
    puStack_50 = &DAT_fffffff007c92ee8;
    uStack_38 = *(undefined4 *)(param_1 + 0x28);
    uStack_40 = *(undefined8 *)(param_1 + 0x20);
    if (plVar3 != (long *)0x0) {
      lStack_48 = param_2;
      thunk_EXT_FUN_801100000294e120(plVar3);
      lVar1 = (**(code **)(*plVar3 + 0x80))(plVar3);
      uVar2 = (**(code **)(*plVar3 + 0x98))(plVar3);
      if (lVar1 != 0) {
        (*pcStack_58)(&puStack_68,lVar1,uVar2);
        (**(code **)(*plVar3 + 0x88))(plVar3);
      }
      thunk_EXT_FUN_801100000294e12c(plVar3);
    }
  }
  return;
}

