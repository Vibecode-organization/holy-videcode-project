// FUN_fffffff00996810c @ fffffff00996810c size=204

undefined8 FUN_fffffff00996810c(long param_1,undefined4 *param_2,undefined8 param_3)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_fffffff009945040(*(undefined8 *)(param_1 + 0x10),*param_2);
  if (plVar1 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid resource ID\n");
    uVar2 = 0xe00002c2;
  }
  else {
    uVar2 = FUN_fffffff0099576f4
                      (plVar1,*(undefined8 *)(param_1 + 0x50),*(undefined8 *)(param_2 + 2),
                       *(undefined8 *)(param_2 + 4),*(byte *)(param_2 + 1) & 1,
                       *(byte *)(param_2 + 1) >> 1 & 1,param_3);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

