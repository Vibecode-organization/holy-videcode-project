// FUN_fffffff0094c1bd8 @ fffffff0094c1bd8 size=300
// CALLERS:
//   fffffff00afb803d ?
//   fffffff0094c0a98 FUN_fffffff0094c06d0@fffffff0094c06d0
// CALLS:
//   fffffff0094c9a04 thunk_EXT_FUN_8011000003138628
//   fffffff0094c9bb4 thunk_EXT_FUN_80110000033502b4
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590
//   fffffff0094c2ebc FUN_fffffff0094c2ebc

void FUN_fffffff0094c1bd8(ulong *param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  undefined1 *puVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined1 *local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff007f5bb60;
  local_40 = &DAT_aaaaaaaaaaaaaaaa;
  uVar4 = thunk_EXT_FUN_8011000003138628(param_1,4,&local_40);
  if ((uVar4 & 1) != 0) {
    if (CARRY8(*param_1,(ulong)local_40)) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5513,0xfffffff0094c1d04);
      (*pcVar2)();
    }
    if (local_40 + *param_1 == (undefined1 *)param_1[1]) {
      if (param_4 + 0x28U < param_4 + 0x18U) {
LAB_fffffff0094c1cf8:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c1cfc);
        (*pcVar2)();
      }
      lVar6 = FUN_fffffff0094c2ebc();
      puVar1 = local_40;
      uVar5 = 0;
      if (lVar6 == 0) goto LAB_fffffff0094c1c48;
      if ((local_40 == *(undefined1 **)(param_4 + 0x88)) &&
         (puVar7 = (undefined8 *)(**(code **)(lVar6 + 0x18))(), puVar1 == (undefined1 *)*puVar7)) {
        if ((param_1[1] < *param_1) ||
           ((*(undefined1 **)(param_4 + 0x88) < local_40 ||
            ((undefined1 *)(param_1[1] - *param_1) < local_40)))) goto LAB_fffffff0094c1cf8;
        iVar3 = thunk_EXT_FUN_80110000033502b4(*(undefined8 *)(param_4 + 0x80));
        if (iVar3 != 0) goto LAB_fffffff0094c1ce4;
      }
      else {
LAB_fffffff0094c1ce4:
        *(undefined4 *)(param_4 + 0xa8) = 0x70002;
      }
      uVar5 = 1;
      goto LAB_fffffff0094c1c48;
    }
  }
  uVar5 = 0;
LAB_fffffff0094c1c48:
  if (*(long *)PTR_DAT_fffffff007f5bb60 == local_38) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar5);
  return;
}

