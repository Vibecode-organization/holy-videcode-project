// FUN_fffffff0094c1f20 @ fffffff0094c1f20 size=208
// CALLERS:
//   fffffff00afb8041 ?
//   fffffff0094c0b00 FUN_fffffff0094c06d0@fffffff0094c06d0
// CALLS:
//   fffffff0094c9a04 thunk_EXT_FUN_8011000003138628
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590

void FUN_fffffff0094c1f20(ulong *param_1)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  ulong local_40;
  ulong local_38;
  undefined1 *local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff007f5bb60;
  if (param_1[1] < *param_1) {
LAB_fffffff0094c1fe4:
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c1fe8);
    (*pcVar1)();
  }
  local_30 = &DAT_aaaaaaaaaaaaaaaa;
  local_40 = *param_1;
  local_38 = param_1[1];
  iVar2 = thunk_EXT_FUN_8011000003138628(param_1,0x17,&local_30);
  if (iVar2 == 0) {
    uVar3 = thunk_EXT_FUN_8011000003138628(&local_40,0x18,&local_30);
    if ((int)uVar3 == 0) goto LAB_fffffff0094c1fbc;
    if (local_38 < local_40) goto LAB_fffffff0094c1fe4;
    *param_1 = local_40;
    param_1[1] = local_38;
    uVar3 = local_40;
  }
  else {
    uVar3 = *param_1;
  }
  if (CARRY8(uVar3,(ulong)local_30)) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5513,0xfffffff0094c1ff0);
    (*pcVar1)();
  }
  uVar3 = (ulong)(local_30 + uVar3 == (undefined1 *)param_1[1]);
LAB_fffffff0094c1fbc:
  if (*(long *)PTR_DAT_fffffff007f5bb60 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar3);
  return;
}

