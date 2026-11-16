// FUN_fffffff00994903c @ fffffff00994903c size=4

undefined8 FUN_fffffff00994903c(long param_1,undefined8 param_2,long param_3)

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
    FUN_fffffff00995bc50();
    (**(code **)(*plVar1 + 0x28))(plVar1);
    uVar2 = 0;
  }
  return uVar2;
}

