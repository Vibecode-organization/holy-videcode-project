// FUN_fffffff0094c03ec @ fffffff0094c03ec size=740
// CALLERS:
//   fffffff00afb8028 ?
//   fffffff0094c43a0 FUN_fffffff0094c41a4@fffffff0094c41a4
//   fffffff0094c0db0 FUN_fffffff0094c06d0@fffffff0094c06d0
//   fffffff0094c4bb8 FUN_fffffff0094c4ba0@fffffff0094c4ba0
// CALLS:
//   fffffff0094c9a04 thunk_EXT_FUN_8011000003138628
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590
//   fffffff0094c1a90 FUN_fffffff0094c1a90
//   fffffff0094c862c FUN_fffffff0094c862c
//   fffffff0094c8220 FUN_fffffff0094c8220

undefined8 FUN_fffffff0094c03ec(undefined8 param_1,long param_2,long *param_3)

{
  long *plVar1;
  undefined1 *puVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  undefined1 *puVar6;
  undefined8 uVar7;
  undefined1 *local_70;
  undefined1 *puStack_68;
  undefined1 *local_60;
  undefined1 *puStack_58;
  undefined1 *local_50;
  undefined1 *local_48;
  undefined1 *local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff007f5bb60;
  puVar6 = (undefined1 *)param_3[1];
  if (CARRY8((ulong)puVar6,param_3[2])) goto LAB_fffffff0094c06c8;
  puVar2 = puVar6 + param_3[2];
  if (puVar2 < puVar6) goto LAB_fffffff0094c06c4;
  local_50 = &DAT_aaaaaaaaaaaaaaaa;
  local_48 = puVar6;
  local_40 = puVar2;
  if (*param_3 == 3) {
    if (*(long *)(param_2 + 0x58) == 1) {
      uVar7 = 0x8000a;
      goto LAB_fffffff0094c063c;
    }
    local_70 = puVar6;
    puStack_68 = puVar2;
    iVar4 = thunk_EXT_FUN_8011000003138628(&local_48,0x8000000000000000,&local_50);
    puVar6 = local_48;
    puVar2 = local_40;
    if (iVar4 == 0) {
      iVar4 = thunk_EXT_FUN_8011000003138628(&local_70,0xa000000000000000,&local_50);
      if ((iVar4 == 0) ||
         (iVar4 = thunk_EXT_FUN_8011000003138628(&local_70,4,&local_50), iVar4 == 0)) {
        uVar7 = 0x80006;
        goto LAB_fffffff0094c063c;
      }
      puVar6 = local_70;
      puVar2 = puStack_68;
      if (puStack_68 < local_70) goto LAB_fffffff0094c06c4;
    }
    local_40 = puVar2;
    if ((local_40 < puVar6) || (local_40 + -(long)puVar6 < local_50)) goto LAB_fffffff0094c06c4;
    puStack_58 = local_50;
    local_60 = puVar6;
    if (CARRY8((ulong)puVar6,(ulong)local_50)) {
LAB_fffffff0094c06c8:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5513,0xfffffff0094c06cc);
      (*pcVar3)();
    }
    puVar2 = puVar6 + (long)local_50;
    if ((local_40 < puVar2) || (puVar2 < puVar6)) goto LAB_fffffff0094c06c4;
    local_48 = puVar2;
    uVar5 = FUN_fffffff0094c8220(param_2 + 0x18,&local_60);
    if (uVar5 == 0) {
      uVar7 = 0x80007;
      goto LAB_fffffff0094c063c;
    }
  }
  else {
    if (*param_3 != 1) {
      uVar7 = 0x80001;
      goto LAB_fffffff0094c063c;
    }
    uVar7 = 0x80002;
    iVar4 = thunk_EXT_FUN_8011000003138628(&local_48,0x2000000000000010,&local_50);
    if (iVar4 == 0) goto LAB_fffffff0094c063c;
    iVar4 = thunk_EXT_FUN_8011000003138628(&local_48,0x2000000000000010,&local_50);
    if (iVar4 == 0) {
      uVar7 = 0x80003;
      goto LAB_fffffff0094c063c;
    }
    if ((local_40 < local_48) || (local_40 + -(long)local_48 < local_50)) goto LAB_fffffff0094c06c4;
    local_70 = local_48;
    puStack_68 = local_50;
    if (CARRY8((ulong)local_48,(ulong)local_50)) goto LAB_fffffff0094c06c8;
    puVar6 = local_48 + (long)local_50;
    if ((local_40 < puVar6) || (puVar6 < local_48)) goto LAB_fffffff0094c06c4;
    local_48 = puVar6;
    iVar4 = thunk_EXT_FUN_8011000003138628(&local_48,2,&local_50);
    if (iVar4 == 0) {
      uVar7 = 0x80004;
      goto LAB_fffffff0094c063c;
    }
    if ((local_40 < local_48) || (local_40 + -(long)local_48 < local_50)) goto LAB_fffffff0094c06c4;
    local_60 = local_48;
    puStack_58 = local_50;
    if (CARRY8((ulong)local_48,(ulong)local_50)) goto LAB_fffffff0094c06c8;
    puVar6 = local_48 + (long)local_50;
    if (((local_40 < puVar6) || (puVar6 < local_48)) ||
       (local_48 = puVar6, param_2 + 0x28U < param_2 + 0x18U)) goto LAB_fffffff0094c06c4;
    uVar5 = FUN_fffffff0094c1a90(param_2 + 0x18U,&local_70,&local_60);
    if (uVar5 == 0) {
      uVar7 = 0x80005;
      goto LAB_fffffff0094c063c;
    }
  }
  if (local_48 == local_40) {
    if (((uVar5 + 0x130 < uVar5) || (param_2 + 0x28U < param_2 + 0x18U)) ||
       (plVar1 = param_3 + 0x15, plVar1 < param_3 + 0x13)) {
LAB_fffffff0094c06c4:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c06c8);
      (*pcVar3)();
    }
    uVar7 = FUN_fffffff0094c862c();
    if ((int)*plVar1 == 0x50001) {
      *(int *)plVar1 = (int)uVar7;
    }
  }
  else {
    uVar7 = 0x800ff;
  }
LAB_fffffff0094c063c:
  if (*(long *)PTR_DAT_fffffff007f5bb60 != local_38) {
    uVar7 = thunk_EXT_FUN_8011000003a48590();
    return uVar7;
  }
  return uVar7;
}

