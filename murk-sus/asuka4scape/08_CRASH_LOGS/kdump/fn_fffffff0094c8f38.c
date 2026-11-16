// FUN_fffffff0094c8f38 @ fffffff0094c8f38 size=188
// CALLERS:
//   fffffff00afb80d9 ?
//   fffffff0094c8e30 FUN_fffffff0094c8d1c@fffffff0094c8d1c
// CALLS:
//   fffffff0094c6bf4 FUN_fffffff0094c6bf4
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590
//   fffffff0094c519c FUN_fffffff0094c519c

void FUN_fffffff0094c8f38(long param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff007f5bb60;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (param_2 + 0x68U < param_2 + 0x58U) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c8ff0);
    (*pcVar1)();
  }
  iVar2 = FUN_fffffff0094c6bf4(param_2 + 0x58U,&local_38,0,&local_48);
  if (((iVar2 == 0) &&
      (iVar2 = FUN_fffffff0094c519c(*(undefined8 *)(param_1 + 0x20),&local_38), iVar2 == 0)) &&
     (iVar2 = FUN_fffffff0094c519c(*(undefined8 *)(param_1 + 0x18),&local_48), iVar2 == 0)) {
    *(ulong *)(param_2 + 0xf0) = *(ulong *)(param_2 + 0xf0) | *(ulong *)(param_1 + 8);
  }
  if (*(long *)PTR_DAT_fffffff007f5bb60 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

