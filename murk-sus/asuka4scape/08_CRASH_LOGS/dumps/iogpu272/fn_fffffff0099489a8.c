// FUN_fffffff0099489a8 @ fffffff0099489a8 size=332

undefined8 FUN_fffffff0099489a8(long param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  long *plVar2;
  long *plVar3;
  undefined8 uVar4;
  
  uVar1 = (*(undefined4 **)(param_3 + 0x20))[2];
  plVar2 = (long *)FUN_fffffff009967bb4
                             (*(undefined8 *)(param_1 + 0x120),**(undefined4 **)(param_3 + 0x20));
  if (plVar2 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid IO Queue ID (%u)\n");
  }
  else {
    plVar3 = (long *)FUN_fffffff009965db4(*(undefined8 *)(param_1 + 0x120),uVar1);
    if (plVar3 != (long *)0x0) {
      uVar4 = FUN_fffffff00995b2ec(plVar2,plVar3);
      (**(code **)(*plVar2 + 0x28))(plVar2);
      (**(code **)(*plVar3 + 0x28))(plVar3);
      return uVar4;
    }
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid Notification Queue ID (%u)\n"
              );
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return 0xe00002c2;
}

