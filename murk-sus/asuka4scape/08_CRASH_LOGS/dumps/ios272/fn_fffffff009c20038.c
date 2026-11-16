// FUN_fffffff009c20038 @ fffffff009c20038 size=220

bool FUN_fffffff009c20038(long *param_1,undefined8 param_2,ulong *param_3)

{
  undefined8 uVar1;
  long *plVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar1 = (**(code **)(*param_1 + 0x138))();
  plVar2 = (long *)thunk_EXT_FUN_8011000003890f30(uVar1,*(undefined8 *)PTR_DAT_fffffff00806c9f8);
  if (plVar2 != (long *)0x0) {
    uVar3 = (**(code **)(*plVar2 + 0x88))(plVar2);
    uVar4 = (**(code **)(*plVar2 + 0xb0))(plVar2);
    *param_3 = uVar4;
    if (((uint)uVar3 < 0x40) && ((uVar4 >> ((ulong)((uint)uVar3 - 1) & 0x3f) & 1) != 0)) {
      *param_3 = uVar4 | -1L << (uVar3 & 0x3f);
    }
  }
  return plVar2 != (long *)0x0;
}

