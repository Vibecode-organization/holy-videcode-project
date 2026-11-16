// FUN_fffffff008201d84 @ fffffff008201d84 size=820

/* WARNING: Removing unreachable block (ram,0xfffffff008201e90) */

undefined8 FUN_fffffff008201d84(long *param_1)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  undefined4 *puVar7;
  int *piVar8;
  uint *puVar9;
  long *plVar10;
  code *pcVar11;
  uint uVar12;
  uint uVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  
  *(undefined1 *)(param_1 + 0x47) = 0;
  uVar5 = thunk_EXT_FUN_8011000002969cc0();
  if ((int)uVar5 != 0) {
    return uVar5;
  }
  lVar6 = thunk_EXT_FUN_8011000003890f30(param_1[0xc],&DAT_fffffff00ae21f50);
  if (*(int *)(*(long *)(*(long *)(lVar6 + 0x610) + 200) + 0x28) != 0) {
    (**(code **)(*param_1 + 0x88))(param_1);
    (**(code **)(*param_1 + 0x98))(param_1);
    return 0xe00002bd;
  }
  lVar6 = (**(code **)(*(long *)param_1[0xb] + 0x158))((long *)param_1[0xb],param_1[0x3d]);
  if (lVar6 != 0) {
    iVar4 = FUN_fffffff00819cb78(param_1[2] + 0x11df0,lVar6,(int)param_1[0x89],param_1 + 0x3c);
    *(int *)((long)param_1 + 0x1dc) = iVar4;
    if (iVar4 == -1) {
      pcVar11 = *(code **)(*param_1 + 0x98);
    }
    else {
      puVar7 = (undefined4 *)(**(code **)(*param_1 + 0xf8))(param_1);
      *(undefined4 *)(param_1 + 0x68) = *puVar7;
      piVar8 = (int *)(**(code **)(*param_1 + 0xf8))(param_1);
      if (*piVar8 != 0) {
        uVar14 = 0;
        do {
          if (param_1[uVar14 + 0x69] == 0) {
            plVar10 = param_1 + 0x78 + uVar14;
            if ((((ulong)(param_1 + 0x78) ^ (ulong)plVar10) & 0xffc0000000000000) != 0) {
              plVar10 = (long *)((ulong)plVar10 & 0xffffffffffff | 0xc8a2000000000000);
            }
            lVar6 = (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x1e8))
                              (*(long **)(param_1[2] + 0x4b0),plVar10);
            param_1[uVar14 + 0x69] = lVar6;
            if (lVar6 == 0) goto LAB_fffffff008202084;
          }
          uVar14 = uVar14 + 1;
          puVar9 = (uint *)(**(code **)(*param_1 + 0xf8))(param_1);
        } while (uVar14 < *puVar9);
      }
      if (param_1[0x87] != 0) {
LAB_fffffff008202070:
        *(undefined1 *)(param_1 + 0x47) = 1;
        return 0;
      }
      lVar6 = *(long *)(param_1[2] + 0x4b0);
      if (*(long *)(lVar6 + 0x13a8) == 0) {
        param_1[0x87] = 0;
      }
      else {
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0x13c8));
        uVar2 = *(uint *)(lVar6 + 0x13b8);
        if (uVar2 != 0) {
          uVar12 = *(uint *)(lVar6 + 0x13bc);
          uVar13 = uVar2;
          do {
            uVar3 = 0;
            if (uVar2 != 0) {
              uVar3 = uVar12 / uVar2;
            }
            uVar3 = uVar12 - uVar3 * uVar2;
            uVar14 = (ulong)uVar3;
            pcVar1 = (char *)(*(long *)(lVar6 + 0x13a8) + (long)(int)uVar3);
            if (uVar14 != (long)(int)uVar3) {
              pcVar1 = (char *)(*(long *)(lVar6 + 0x13a8) + uVar14 & 0xffffffffffff |
                               0x2bad000000000000);
            }
            if (*pcVar1 == '\0') {
              uVar16 = (ulong)(uVar3 * *(int *)(lVar6 + 0x13b0));
              lVar15 = (**(code **)(**(long **)(*(long *)(lVar6 + 0x1398) + 0x50) + 0x98))();
              param_1[0x88] = lVar15 + uVar16;
              uVar2 = *(uint *)(lVar6 + 0x13b8);
              uVar12 = 0;
              if (uVar2 != 0) {
                uVar12 = (uVar3 + 1) / uVar2;
              }
              pcVar1 = (char *)(*(long *)(lVar6 + 0x13a8) + (long)(int)uVar3);
              if (uVar14 != (long)(int)uVar3) {
                pcVar1 = (char *)(*(long *)(lVar6 + 0x13a8) + uVar14 & 0xffffffffffff |
                                 0x2bad000000000000);
              }
              *(uint *)(lVar6 + 0x13bc) = (uVar3 + 1) - uVar12 * uVar2;
              *pcVar1 = *pcVar1 + '\x01';
              lVar15 = *(long *)(lVar6 + 0x13a0) + uVar16;
              goto LAB_fffffff008202054;
            }
            uVar12 = uVar12 + 1;
            uVar13 = uVar13 - 1;
          } while (uVar13 != 0);
        }
        lVar15 = 0;
LAB_fffffff008202054:
        *(uint *)(lVar6 + 0x13c0) = (uint)(lVar15 == 0);
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0x13c8));
        param_1[0x87] = lVar15;
        if (lVar15 != 0) goto LAB_fffffff008202070;
      }
LAB_fffffff008202084:
      pcVar11 = *(code **)(*param_1 + 0x98);
    }
    (*pcVar11)(param_1);
  }
  return 0xe00002be;
}

