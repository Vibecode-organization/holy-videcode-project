// FUN_fffffff009957448 @ fffffff009957448 size=152

long FUN_fffffff009957448(long param_1)

{
  long lVar1;
  
  lVar1 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(param_1 + 0x28),DAT_fffffff007fefaf0);
  if (lVar1 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: memory is not a sysmemory\n");
    lVar1 = 0;
  }
  else if (((*(uint *)(param_1 + 0x10) & 0x2000ff) != 0x80) || (*(long *)(param_1 + 0x30) != 0)) {
    lVar1 = 0;
  }
  return lVar1;
}

