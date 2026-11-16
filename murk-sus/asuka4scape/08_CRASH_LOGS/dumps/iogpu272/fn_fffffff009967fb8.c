// FUN_fffffff009967fb8 @ fffffff009967fb8 size=156

undefined8 FUN_fffffff009967fb8(long param_1)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_fffffff009945040(*(undefined8 *)(param_1 + 0x10));
  if (plVar1 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid resource ID\n");
    uVar2 = 0xe00002c2;
  }
  else {
    uVar2 = FUN_fffffff00995758c();
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

