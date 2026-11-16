// FUN_fffffff0094c1ff0 @ fffffff0094c1ff0 size=188
// CALLERS:
//   fffffff00afb8043 ?
//   fffffff0094c0b50 FUN_fffffff0094c06d0@fffffff0094c06d0
// CALLS:
//   fffffff0094c9a04 thunk_EXT_FUN_8011000003138628
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590

/* WARNING: Type propagation algorithm not settling */

void FUN_fffffff0094c1ff0(ulong *param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined1 *local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff007f5bb60;
  local_30 = &DAT_aaaaaaaaaaaaaaaa;
  uVar2 = thunk_EXT_FUN_8011000003138628(param_1,4,&local_30);
  if ((uVar2 & 1) != 0) {
    uVar2 = *param_1;
    if (CARRY8(uVar2,(ulong)local_30)) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5513,0xfffffff0094c20ac);
      (*pcVar1)();
    }
    if (uVar2 + (long)local_30 == param_1[1]) {
      if (*(int *)(param_4 + 0x68) == 0) {
        if (uVar2 + (long)local_30 < uVar2) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c2098);
          (*pcVar1)();
        }
        *(ulong *)(param_4 + 0x70) = uVar2;
        *(undefined1 **)(param_4 + 0x78) = local_30;
      }
      uVar3 = 1;
      goto LAB_fffffff0094c205c;
    }
  }
  uVar3 = 0;
LAB_fffffff0094c205c:
  if (*(long *)PTR_DAT_fffffff007f5bb60 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar3);
  return;
}

