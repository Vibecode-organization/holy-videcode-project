// FUN_fffffff00995bb6c @ fffffff00995bb6c size=120

undefined8 FUN_fffffff00995bb6c(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_fffffff009945154(*(undefined8 *)(param_1 + 0x38));
  if (lVar1 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid IO Commmand Buffer ID (%u)\n"
              );
    uVar2 = 0xe00002c2;
  }
  else {
    FUN_fffffff009959180();
    uVar2 = 0;
  }
  return uVar2;
}

