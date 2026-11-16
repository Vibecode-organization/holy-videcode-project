// FUN_fffffff0094c8c04 @ fffffff0094c8c04 size=280
// CALLERS:
//   fffffff00afb80d6 ?
//   fffffff0094c87a0 FUN_fffffff0094c8638@fffffff0094c8638
// CALLS:
//   fffffff0094c519c FUN_fffffff0094c519c
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590
//   fffffff0094c7554 FUN_fffffff0094c7554
//   fffffff0094c51ec FUN_fffffff0094c51ec

void FUN_fffffff0094c8c04(long param_1)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  undefined1 *local_38;
  undefined1 *puStack_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff007f5bb60;
  if (param_1 + 0x78U < param_1 + 0x68U) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c8d18);
    (*pcVar1)();
  }
  local_38 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_30 = &DAT_aaaaaaaaaaaaaaaa;
  iVar2 = FUN_fffffff0094c7554(param_1 + 0x68U,&local_38);
  if (iVar2 == 0) {
    iVar2 = FUN_fffffff0094c519c(&DAT_fffffff007f5b408,&local_38);
    if (iVar2 == 0) {
      uVar3 = 0xf00;
    }
    else {
      iVar2 = FUN_fffffff0094c519c(&DAT_fffffff007f5b418,&local_38);
      if (iVar2 == 0) {
        uVar3 = 0x800000000008;
      }
      else {
        iVar2 = FUN_fffffff0094c51ec(&DAT_fffffff007f5b428,&local_38);
        if (iVar2 == 0) {
          uVar3 = 0x400000000;
        }
        else {
          iVar2 = FUN_fffffff0094c51ec(&DAT_fffffff007f5b438,&local_38);
          if (iVar2 == 0) {
            uVar3 = 0x800000000;
          }
          else {
            iVar2 = FUN_fffffff0094c51ec(&DAT_fffffff007f5b448,&local_38);
            if (iVar2 != 0) goto LAB_fffffff0094c8cec;
            uVar3 = 0x1000000000;
          }
        }
      }
    }
    *(ulong *)(param_1 + 0xf0) = *(ulong *)(param_1 + 0xf0) | uVar3;
  }
LAB_fffffff0094c8cec:
  if (*(long *)PTR_DAT_fffffff007f5bb60 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

