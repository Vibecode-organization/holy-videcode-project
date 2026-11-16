// FUN_fffffff00996fc74 @ fffffff00996fc74 size=320

undefined8 FUN_fffffff00996fc74(long *param_1,undefined8 param_2)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  ulong unaff_x30;
  
  uVar6 = param_1[5];
  uVar5 = uVar6 << 4;
  if (0x7fffffffffffffff < uVar5) {
    uVar5 = 0x8000000000000000;
  }
  if ((uVar6 >> 0x3c & 7) != 0) {
    uVar5 = 0x8000000000000000;
  }
  lVar2 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff1a98,uVar5);
  if (lVar2 != 0) {
    thunk_EXT_FUN_8011000003a61b10(lVar2,param_1[3],param_1[5] << 3);
    uVar5 = param_1[5] << 3;
    if (0x7fffffffffffffff < uVar5) {
      uVar5 = 0x8000000000000000;
    }
    if ((ulong)param_1[5] >> 0x3d != 0) {
      uVar5 = 0x8000000000000000;
    }
    lVar4 = param_1[3];
    param_1[3] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1ae8,lVar4,uVar5);
    param_1[5] = uVar6 << 1;
    param_1[3] = lVar2;
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996fd60);
      (*pcVar1)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff00996fd68. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)(*param_1 + 0x78))(param_1,param_2,(undefined8 *)(*param_1 + 0x78));
    return uVar3;
  }
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: failed to alloc array\n");
  return 0;
}

