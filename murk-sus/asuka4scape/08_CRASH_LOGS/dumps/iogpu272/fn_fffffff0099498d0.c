// FUN_fffffff0099498d0 @ fffffff0099498d0 size=4

undefined8 FUN_fffffff0099498d0(long param_1,undefined8 param_2,ulong param_3,undefined8 param_4)

{
  long *plVar1;
  undefined8 uVar2;
  undefined4 auStack_d8 [40];
  long lStack_38;
  
  lStack_38 = *(long *)PTR_DAT_fffffff007ff2800;
  uVar2 = 0xe00002c2;
  if ((0x28 < param_3) ||
     (plVar1 = (long *)FUN_fffffff009965da8(*(undefined8 *)(param_1 + 0x120)), plVar1 == (long *)0x0
     )) goto LAB_fffffff009949980;
  if (param_3 < 2) {
    auStack_d8[0] = (undefined4)param_4;
LAB_fffffff00994994c:
    uVar2 = FUN_fffffff00997a4d8(plVar1,auStack_d8,param_3);
  }
  else {
    uVar2 = thunk_EXT_FUN_8011000003385b14(param_4,auStack_d8,param_3 << 2);
    if ((int)uVar2 == 0) goto LAB_fffffff00994994c;
  }
  (**(code **)(*plVar1 + 0x28))(plVar1);
LAB_fffffff009949980:
  if (*(long *)PTR_DAT_fffffff007ff2800 == lStack_38) {
    return uVar2;
  }
  uVar2 = thunk_EXT_FUN_8011000003a48590();
  return uVar2;
}

