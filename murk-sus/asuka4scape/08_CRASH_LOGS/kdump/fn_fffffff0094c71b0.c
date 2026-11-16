// FUN_fffffff0094c71b0 @ fffffff0094c71b0 size=472
// CALLERS:
//   fffffff00afb80b8 ?
//   fffffff0094c715c FUN_fffffff0094c70e8@fffffff0094c70e8
//   fffffff0094c7404 FUN_fffffff0094c7388@fffffff0094c7388
// CALLS:
//   fffffff0094c9b84 thunk_EXT_FUN_8011000003187110
//   fffffff0094c9b64 thunk_EXT_FUN_801100000317d408
//   fffffff0094c51c8 FUN_fffffff0094c51c8
//   fffffff0094c9b94 thunk_EXT_FUN_801100000318713c
//   fffffff0094c9a64 thunk_EXT_FUN_801100000314e898
//   fffffff0094c9b74 thunk_EXT_FUN_8011000003187100

undefined8 FUN_fffffff0094c71b0(long *param_1,undefined8 param_2,long param_3,undefined8 *param_4)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = FUN_fffffff0094c51c8(param_2,&DAT_fffffff0077707b2,0xb);
  if ((iVar2 == 0) || (iVar2 = FUN_fffffff0094c51c8(param_2,&DAT_fffffff0077707bd,8), iVar2 == 0)) {
    *param_4 = &DAT_fffffff007770735;
    param_4[1] = 9;
    if (*(ulong *)(param_3 + 8) < 0x40) goto LAB_fffffff0094c7384;
    *(undefined8 *)(param_3 + 8) = 0x40;
    thunk_EXT_FUN_801100000318713c();
  }
  else {
    iVar2 = FUN_fffffff0094c51c8(param_2,&DAT_fffffff007770747,9);
    if (iVar2 == 0) {
LAB_fffffff0094c72d8:
      *param_4 = &DAT_fffffff00777071e;
      param_4[1] = 5;
      if (*(ulong *)(param_3 + 8) < 0x14) goto LAB_fffffff0094c7384;
      *(undefined8 *)(param_3 + 8) = 0x14;
      thunk_EXT_FUN_801100000317d408();
    }
    else {
      iVar2 = FUN_fffffff0094c51c8(param_2,&DAT_fffffff007770750,9);
      if (iVar2 == 0) {
LAB_fffffff0094c7304:
        *param_4 = &DAT_fffffff007770723;
        param_4[1] = 9;
        if (*(ulong *)(param_3 + 8) < 0x20) goto LAB_fffffff0094c7384;
        *(undefined8 *)(param_3 + 8) = 0x20;
        thunk_EXT_FUN_8011000003187100();
      }
      else {
        iVar2 = FUN_fffffff0094c51c8(param_2,&DAT_fffffff007770759,9);
        if (iVar2 != 0) {
          iVar2 = FUN_fffffff0094c51c8(param_2,&DAT_fffffff007770774,7);
          if (iVar2 == 0) goto LAB_fffffff0094c72d8;
          iVar2 = FUN_fffffff0094c51c8(param_2,&DAT_fffffff00777077b,8);
          if (iVar2 == 0) goto LAB_fffffff0094c7304;
          iVar2 = FUN_fffffff0094c51c8(param_2,&DAT_fffffff007770783,8);
          if (iVar2 != 0) {
            return 0xa0500;
          }
        }
        *param_4 = &DAT_fffffff00777072c;
        param_4[1] = 9;
        if (*(ulong *)(param_3 + 8) < 0x30) goto LAB_fffffff0094c7384;
        *(undefined8 *)(param_3 + 8) = 0x30;
        thunk_EXT_FUN_8011000003187110();
      }
    }
  }
  if ((param_1[1] != 0) || (*param_1 == 0)) {
    thunk_EXT_FUN_801100000314e898();
    return 0;
  }
LAB_fffffff0094c7384:
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c7388);
  (*pcVar1)();
}

