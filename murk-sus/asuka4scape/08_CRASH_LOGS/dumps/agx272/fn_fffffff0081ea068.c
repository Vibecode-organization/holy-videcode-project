// FUN_fffffff0081ea068 @ fffffff0081ea068 size=4

void FUN_fffffff0081ea068(long param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  long lVar8;
  char *pcVar9;
  long lVar10;
  long *plVar11;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000002951bac
            (*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x20),param_2,"Parameter Stack Free List");
  pcVar9 = *(char **)(*(long *)(param_1 + 0x38) + 0x20);
  pcVar1 = "Firmware Parameter Buffer, Scene Objects, and Page List Entries";
  if (pcVar9 != (char *)0x0) {
    pcVar1 = pcVar9;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x38) + 0x48),pcVar1);
  pcVar9 = *(char **)(*(long *)(param_1 + 0x40) + 0x20);
  pcVar1 = "Firmware Page List Entries, Parameter Scene statistics";
  if (pcVar9 != (char *)0x0) {
    pcVar1 = pcVar9;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x40) + 0x48),pcVar1);
  thunk_EXT_FUN_8011000002951bac
            (*(undefined8 *)(param_1 + 0x48),param_2,
             "Parameter Scene Allocations (MList, MTileArray, VHeap Table)");
  pcVar9 = *(char **)(*(long *)(param_1 + 0x30) + 0x20);
  pcVar1 = "Firmware Page List Entries";
  if (pcVar9 != (char *)0x0) {
    pcVar1 = pcVar9;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x30) + 0x48),pcVar1);
  if ((*(byte *)(param_1 + 0x198) & 1) == 0) {
    uVar3 = *(uint *)(*(long *)(param_1 + 0x88) + 8);
    uVar4 = *(uint *)(*(long *)(param_1 + 0x88) + 4);
    if ((*(uint *)(param_1 + 0x138) <= uVar3) || (*(uint *)(param_1 + 0x138) <= uVar4)) {
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Assertion failed: %s: OOB access in GPU Driver Resource\n");
      return;
    }
    if (uVar3 == uVar4) {
      lVar10 = 0;
    }
    else {
      lVar10 = 0;
      do {
        lVar8 = (ulong)uVar3 * 8;
        puVar2 = (undefined8 *)(*(long *)(param_1 + 400) + (long)(int)lVar8);
        if (lVar8 != (int)lVar8) {
          puVar2 = (undefined8 *)
                   (*(long *)(param_1 + 400) + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
        }
        plVar11 = (long *)*puVar2;
        lVar8 = (**(code **)(*plVar11 + 0x80))(plVar11);
        lVar10 = lVar8 + lVar10;
        (**(code **)(*plVar11 + 0x98))(plVar11,param_2);
        uVar5 = *(uint *)(param_1 + 0x138);
        uVar6 = 0;
        if (uVar5 != 0) {
          uVar6 = (uVar3 + 1) / uVar5;
        }
        uVar3 = (uVar3 + 1) - uVar6 * uVar5;
      } while (uVar3 != uVar4);
    }
    thunk_EXT_FUN_8011000002979258(param_2,lVar10,param_3,"Parameter Page List Backing");
  }
  if ((int)param_3 == 0) {
    return;
  }
  thunk_EXT_FUN_8011000002951bc8(*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x20),param_2,param_3);
  thunk_EXT_FUN_8011000002977950(param_2,*(undefined8 *)(*(long *)(param_1 + 0x38) + 0x48),param_3);
  thunk_EXT_FUN_8011000002977950(param_2,*(undefined8 *)(*(long *)(param_1 + 0x40) + 0x48),param_3);
  thunk_EXT_FUN_8011000002951bc8(*(undefined8 *)(param_1 + 0x48),param_2,param_3);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_8011000002977950
              (param_2,*(undefined8 *)(*(long *)(param_1 + 0x30) + 0x48),param_3);
    return;
  }
                    /* WARNING: Does not return */
  pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ea288);
  (*pcVar7)();
}

