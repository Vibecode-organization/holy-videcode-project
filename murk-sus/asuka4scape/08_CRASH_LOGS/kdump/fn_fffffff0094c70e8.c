// FUN_fffffff0094c70e8 @ fffffff0094c70e8 size=200
// CALLERS:
//   fffffff00afb80b6 ?
//   fffffff0094c8818 FUN_fffffff0094c8638@fffffff0094c8638
//   fffffff0094c8a88 FUN_fffffff0094c8638@fffffff0094c8638
// CALLS:
//   fffffff0094c6eac FUN_fffffff0094c6eac
//   fffffff0094c71b0 FUN_fffffff0094c71b0
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590

void FUN_fffffff0094c70e8
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined1 **local_90;
  undefined8 uStack_88;
  undefined1 *local_80;
  undefined1 *puStack_78;
  undefined1 *puStack_70;
  undefined1 *puStack_68;
  undefined1 *local_60;
  undefined1 *puStack_58;
  undefined1 *puStack_50;
  undefined1 *puStack_48;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff007f5bb60;
  puStack_58 = &DAT_aaaaaaaaaaaaaaaa;
  local_60 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_48 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_50 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_78 = &DAT_aaaaaaaaaaaaaaaa;
  local_80 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_68 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_70 = &DAT_aaaaaaaaaaaaaaaa;
  local_90 = &local_80;
  uStack_88 = 0x40;
  local_a0 = 0;
  uStack_98 = 0;
  iVar1 = FUN_fffffff0094c71b0(param_4,param_5,&local_90,&local_a0,&local_80);
  if (iVar1 == 0) {
    FUN_fffffff0094c6eac(param_1,param_2,param_3,&local_90,&local_a0,param_6);
  }
  if (*(long *)PTR_DAT_fffffff007f5bb60 == local_38) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

