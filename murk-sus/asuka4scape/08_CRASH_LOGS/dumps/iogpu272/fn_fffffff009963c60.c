// FUN_fffffff009963c60 @ fffffff009963c60 size=208

undefined8 FUN_fffffff009963c60(long param_1)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  uint uVar6;
  
  uVar1 = *(uint *)(param_1 + 0x50);
  if (uVar1 == 0) {
    uVar6 = 0x400;
  }
  else {
    if (uVar1 >> 0x16 != 0) {
      return 0;
    }
    uVar6 = uVar1 << 1;
  }
  lVar5 = *(long *)(param_1 + 0x40);
  lVar3 = thunk_EXT_FUN_80110000038fe5cc(uVar6 >> 3);
  *(long *)(param_1 + 0x40) = lVar3;
  if (lVar3 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"IOMalloc failed to alloc handles\n");
    uVar4 = 0;
    *(long *)(param_1 + 0x40) = lVar5;
  }
  else {
    *(uint *)(param_1 + 0x50) = uVar6;
    if (lVar5 != 0) {
      uVar1 = uVar1 >> 3;
      if (uVar6 >> 3 < uVar1) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffe,0xfffffff009963d30);
        (*pcVar2)();
      }
      thunk_EXT_FUN_8011000003a61b10(lVar3,lVar5,uVar1);
      thunk_EXT_FUN_80110000038fe6b0(lVar5,uVar1);
    }
    uVar4 = 1;
  }
  return uVar4;
}

