// FUN_fffffff0094c1d04 @ fffffff0094c1d04 size=540
// CALLERS:
//   fffffff00afb803f ?
//   fffffff0094c0ac8 FUN_fffffff0094c06d0@fffffff0094c06d0
// CALLS:
//   fffffff0094c9a04 thunk_EXT_FUN_8011000003138628
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590
//   fffffff0094c2ebc FUN_fffffff0094c2ebc

ulong FUN_fffffff0094c1d04(ulong *param_1,long param_2,long param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  uint *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  ulong uVar8;
  undefined1 *local_70;
  undefined1 *puStack_68;
  undefined1 *local_60;
  undefined1 *local_58;
  undefined1 *local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff007f5bb60;
  uVar8 = 0x40003;
  local_50 = &DAT_aaaaaaaaaaaaaaaa;
  iVar4 = thunk_EXT_FUN_8011000003138628(param_1,0x2000000000000011,&local_50);
  if (iVar4 != 0) {
    puVar7 = (undefined1 *)param_1[1];
    puVar6 = (undefined1 *)*param_1;
    while (puVar6 < puVar7) {
      iVar4 = thunk_EXT_FUN_8011000003138628(param_1,0x2000000000000010,&local_50);
      if (iVar4 == 0) {
        uVar8 = 0x4000d;
        goto LAB_fffffff0094c1ec0;
      }
      puVar7 = (undefined1 *)*param_1;
      if (CARRY8((ulong)puVar7,(ulong)local_50)) goto LAB_fffffff0094c1f1c;
      puVar6 = puVar7 + (long)local_50;
      if (puVar6 < puVar7 || (undefined1 *)param_1[1] < puVar6) goto LAB_fffffff0094c1ef4;
      local_60 = puVar7;
      local_58 = puVar6;
      uVar8 = thunk_EXT_FUN_8011000003138628(&local_60,6,&local_50);
      if ((uVar8 & 1) == 0) {
        uVar8 = 0x40007;
        goto LAB_fffffff0094c1ec0;
      }
      if ((local_58 < local_60) || (local_58 + -(long)local_60 < local_50))
      goto LAB_fffffff0094c1ef4;
      local_70 = local_60;
      puStack_68 = local_50;
      if (CARRY8((ulong)local_60,(ulong)local_50)) {
LAB_fffffff0094c1f1c:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5513,0xfffffff0094c1f20);
        (*pcVar3)();
      }
      puVar7 = local_60 + (long)local_50;
      if ((local_58 < puVar7) || (puVar7 < local_60)) goto LAB_fffffff0094c1ef4;
      local_60 = puVar7;
      iVar4 = thunk_EXT_FUN_8011000003138628(&local_60,4,&local_50);
      puVar6 = local_58;
      puVar7 = local_60;
      if (iVar4 == 0) {
        uVar8 = 0x40008;
        goto LAB_fffffff0094c1ec0;
      }
      if (CARRY8((ulong)local_60,(ulong)local_50)) goto LAB_fffffff0094c1f1c;
      puVar1 = local_60 + (long)local_50;
      if ((local_58 < puVar1) || (puVar1 < local_60)) {
LAB_fffffff0094c1ef4:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c1ef8);
        (*pcVar3)();
      }
      local_60 = puVar1;
      if (puVar1 != local_58) {
        uVar8 = 0x40009;
        goto LAB_fffffff0094c1ec0;
      }
      puVar5 = (uint *)FUN_fffffff0094c2ebc(&local_70);
      if (((puVar5 != (uint *)0x0) && (uVar2 = *puVar5, *(uint *)(param_2 + 0x68) < uVar2)) &&
         ((*(uint *)(param_3 + 8) == 0 || (uVar2 <= *(uint *)(param_3 + 8))))) {
        *(uint *)(param_2 + 0x68) = uVar2;
        if (puVar6 + -(long)puVar7 < local_50) goto LAB_fffffff0094c1ef4;
        *(undefined1 **)(param_2 + 0x70) = puVar7;
        *(undefined1 **)(param_2 + 0x78) = local_50;
      }
      puVar7 = (undefined1 *)param_1[1];
      if ((puVar7 < local_60) || (local_60 < (undefined1 *)*param_1)) goto LAB_fffffff0094c1ef4;
      *param_1 = (ulong)local_60;
      puVar6 = local_60;
    }
    uVar2 = 0;
    if (puVar6 != puVar7) {
      uVar2 = 0x4000b;
    }
    uVar8 = (ulong)uVar2;
  }
LAB_fffffff0094c1ec0:
  if (*(long *)PTR_DAT_fffffff007f5bb60 == local_48) {
    return uVar8;
  }
  uVar8 = thunk_EXT_FUN_8011000003a48590();
  return uVar8;
}

