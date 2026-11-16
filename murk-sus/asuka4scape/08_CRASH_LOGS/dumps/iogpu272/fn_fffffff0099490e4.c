// FUN_fffffff0099490e4 @ fffffff0099490e4 size=188

undefined8 FUN_fffffff0099490e4(long param_1,undefined8 param_2,long param_3)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_fffffff009967bb4
                             (*(undefined8 *)(param_1 + 0x120),**(undefined4 **)(param_3 + 0x20));
  if (plVar1 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid IO Queue ID (%u)\n");
    uVar2 = 0xe00002c2;
  }
  else {
    uVar2 = FUN_fffffff00995bc90
                      (plVar1,*(undefined4 *)(*(long *)(param_3 + 0x20) + 8),
                       *(undefined4 *)(*(long *)(param_3 + 0x20) + 0x10));
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

