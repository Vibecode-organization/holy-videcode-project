// FUN_fffffff0081fa674 @ fffffff0081fa674 size=2660

/* WARNING: Removing unreachable block (ram,0xfffffff0081faa08) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081fac98) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081fa814) */

void FUN_fffffff0081fa674(long param_1,long param_2)

{
  undefined4 *puVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  ulong uVar11;
  undefined4 *puVar12;
  ulong uVar13;
  long lVar14;
  long lVar15;
  ulong uVar16;
  char *pcVar17;
  undefined8 uVar18;
  ulong uVar19;
  undefined4 local_4bc;
  undefined4 uStack_4b8;
  int local_4b4;
  undefined8 local_4b0;
  undefined8 uStack_4a8;
  undefined8 uStack_4a0;
  undefined8 uStack_498;
  undefined8 local_490;
  undefined8 uStack_488;
  undefined8 uStack_480;
  undefined8 uStack_478;
  ulong local_470 [128];
  long local_70;
  
  local_70 = *(long *)PTR_DAT_fffffff007ca61a0;
  if ((*(byte *)(param_1 + 0x10) & 1) == 0) {
    *(undefined1 *)(param_1 + 0x10) = 1;
  }
  plVar6 = (long *)thunk_EXT_FUN_801100000389d0d8(5);
  if (plVar6 != (long *)0x0) {
    plVar7 = (long *)thunk_EXT_FUN_80110000038ce200(param_1 + 0x51);
    if (plVar7 != (long *)0x0) {
      (**(code **)(*plVar6 + 0x100))(plVar6,"process_name",plVar7);
      (**(code **)(*plVar7 + 0x28))(plVar7);
    }
    local_470[0] = 0;
    local_4b0 = (ulong)local_4b0._4_4_ << 0x20;
    thunk_EXT_FUN_8011000003203330(local_470,&local_4b0);
    plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24(local_470[0] & 0xffffffff,0x20);
    if (plVar7 != (long *)0x0) {
      (**(code **)(*plVar6 + 0x100))(plVar6,"timestamp",plVar7);
      (**(code **)(*plVar7 + 0x28))(plVar7);
    }
    (**(code **)(*plVar6 + 0x100))(plVar6,"analysis",*(undefined8 *)(param_1 + 0xc0));
    (**(code **)(*plVar6 + 0x100))
              (*plVar6 + 0x100,plVar6,"registers",*(undefined8 *)(param_1 + 0xb8));
  }
  plVar7 = (long *)thunk_EXT_FUN_801100000389d0d8(5);
  if (plVar7 != (long *)0x0) {
    plVar8 = (long *)thunk_EXT_FUN_80110000038ce200(param_1 + 0x51);
    if (plVar8 != (long *)0x0) {
      (**(code **)(*plVar7 + 0x100))(plVar7,"process_name",plVar8);
      (**(code **)(*plVar8 + 0x28))(plVar8);
    }
    local_470[0] = 0;
    local_4b0 = local_4b0 & 0xffffffff00000000;
    thunk_EXT_FUN_8011000003203330(local_470,&local_4b0);
    plVar8 = (long *)thunk_EXT_FUN_80110000038c6e24(local_470[0] & 0xffffffff,0x20);
    if (plVar8 != (long *)0x0) {
      (**(code **)(*plVar7 + 0x100))(plVar7,"timestamp",plVar8);
      (**(code **)(*plVar8 + 0x28))(plVar8);
    }
    iVar3 = (**(code **)(*plVar7 + 0x120))(plVar7,*(undefined8 *)(param_1 + 0xc0));
    if (iVar3 == 0) {
LAB_fffffff0081fb08c:
      (**(code **)(*plVar7 + 0x28))(plVar7);
      plVar7 = (long *)0x0;
    }
    else {
      thunk_EXT_FUN_8011000003a61cc0(local_470,0x400);
      lVar15 = 0;
      uVar5 = 0x400;
      do {
        uVar18 = (&DAT_fffffff007c9e9c0)[lVar15];
        (**(code **)(*plVar7 + 0x118))(plVar7,uVar18);
        lVar14 = **(long **)(param_1 + 0xc0);
        plVar8 = (long *)(**(code **)(lVar14 + 0x138))
                                   (lVar14 + 0x138,*(long **)(param_1 + 0xc0),uVar18);
        if (plVar8 != (long *)0x0) {
          plVar9 = (long *)thunk_EXT_FUN_8011000003898a6c();
          lVar14 = (**(code **)(*plVar9 + 0x88))();
          if ((lVar14 != 0) && (uVar5 < 0x401)) {
            uVar16 = 0;
            do {
              plVar10 = (long *)(**(code **)(*plVar8 + 0x128))(plVar8,lVar14);
              (**(code **)(*plVar10 + 0xa8))();
              iVar3 = thunk_EXT_FUN_80110000037693ec((long)local_470 + uVar16,uVar5,"%d,");
              uVar5 = iVar3 + (int)uVar16;
              uVar16 = (ulong)uVar5;
              uVar5 = 0x400 - uVar5;
              lVar14 = (**(code **)(*plVar9 + 0x88))(plVar9);
            } while (lVar14 != 0);
          }
          (**(code **)(*plVar9 + 0x28))(plVar9);
        }
        plVar8 = (long *)thunk_EXT_FUN_80110000038ce200(local_470);
        if (plVar8 != (long *)0x0) {
          (**(code **)(*plVar7 + 0x100))(plVar7,uVar18,plVar8);
          (**(code **)(*plVar8 + 0x28))(plVar8);
        }
        thunk_EXT_FUN_8011000003a61cc0(local_470,0x400);
        lVar15 = lVar15 + 1;
      } while (lVar15 != 4);
      pcVar17 = "bif1_fault";
      lVar15 = (**(code **)(**(long **)(param_1 + 0xc0) + 0x138))
                         (*(long **)(param_1 + 0xc0),"bif1_fault");
      if (lVar15 == 0) {
        pcVar17 = "bif0_fault";
        lVar15 = (**(code **)(**(long **)(param_1 + 0xc0) + 0x138))
                           (*(long **)(param_1 + 0xc0),"bif0_fault");
        if (lVar15 != 0) goto LAB_fffffff0081fabf8;
      }
      else {
LAB_fffffff0081fabf8:
        (**(code **)(*plVar7 + 0x118))(plVar7,pcVar17);
        iVar3 = (**(code **)(*plVar7 + 0x120))(plVar7,lVar15);
        if (iVar3 == 0) goto LAB_fffffff0081fb08c;
      }
      (**(code **)(*plVar7 + 0x118))(plVar7,"iofence_list");
      lVar15 = **(long **)(param_1 + 0xc0);
      plVar8 = (long *)(**(code **)(lVar15 + 0x138))
                                 (lVar15 + 0x138,*(long **)(param_1 + 0xc0),"iofence_list");
      if (plVar8 != (long *)0x0) {
        plVar8 = (long *)(**(code **)(*plVar8 + 0x138))(plVar8,"iofence_num_iosurfaces");
        uVar4 = (**(code **)(*plVar8 + 0xa8))();
        uStack_488 = 0;
        local_490 = 0;
        uStack_478 = 0;
        uStack_480 = 0;
        uStack_4a8 = 0;
        local_4b0 = 0;
        uStack_498 = 0;
        uStack_4a0 = 0;
        thunk_EXT_FUN_80110000037693ec(&local_4b0,0x40,"%s__%s");
        plVar8 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar4,0x20);
        if (plVar8 != (long *)0x0) {
          (**(code **)(*plVar7 + 0x100))(plVar7,&local_4b0,plVar8);
          (**(code **)(*plVar8 + 0x28))(plVar8);
        }
      }
    }
  }
  if ((plVar6 != (long *)0x0) &&
     (plVar8 = (long *)thunk_EXT_FUN_80110000038d4814(*(undefined4 *)PTR_DAT_fffffff007ca61e8,0,0),
     plVar8 != (long *)0x0)) {
    uVar16 = (**(code **)(*plVar6 + 0x30))(plVar6,plVar8);
    if ((uVar16 & 1) == 0) {
      uVar16 = 0;
      puVar12 = (undefined4 *)0x0;
    }
    else {
      uVar11 = (**(code **)(*plVar8 + 0xb8))(plVar8);
      uVar16 = (uVar11 & 0xffffffff) + 0x2b & 0x1fffffffc;
      puVar12 = (undefined4 *)thunk_EXT_FUN_80110000038fe580(uVar16);
      if (puVar12 == (undefined4 *)0x0) {
        uVar16 = 0;
      }
      else {
        uVar5 = (**(code **)(*plVar8 + 0xb8))(plVar8);
        puVar12[8] = 0x65;
        uVar4 = (**(code **)(*plVar8 + 0xb8))(plVar8);
        puVar12[9] = uVar4;
        uVar18 = (**(code **)(*plVar8 + 0x78))(plVar8);
        uVar13 = (**(code **)(*plVar8 + 0xb8))(plVar8);
        if (uVar16 - 0x28 < (uVar13 & 0xffffffff)) {
LAB_fffffff0081fb0d0:
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0xbffe,0xfffffff0081fb0d4);
          (*pcVar2)();
        }
        puVar1 = puVar12 + 10;
        uVar13 = (ulong)uVar5;
        uVar19 = (uVar16 - (uVar11 & 0xffffffff)) - 0x28;
        thunk_EXT_FUN_8011000003a61b10(puVar1,uVar18);
        uVar11 = 0;
        if (uVar13 + 0x28 <= uVar16) {
          uVar11 = uVar16 - (uVar13 + 0x28);
        }
        if (uVar11 < uVar19) goto LAB_fffffff0081fb0d0;
        uVar11 = (long)puVar1 + (long)(int)uVar5;
        if (uVar13 != (long)(int)uVar5) {
          uVar11 = (long)puVar1 + uVar13 & 0xffffffffffff | 0x2bad000000000000;
        }
        thunk_EXT_FUN_8011000003a61cc0(uVar11,uVar19);
      }
    }
    (**(code **)(*plVar8 + 0x28))(plVar8);
    if (puVar12 != (undefined4 *)0x0) {
      local_4b4 = 1;
      local_4b0 = local_4b0 & 0xffffffff00000000;
      local_470[0] = 0;
      local_4bc = 0;
      uStack_4b8 = 0;
      uVar18 = thunk_EXT_FUN_8011000003211990();
      iVar3 = thunk_EXT_FUN_8011000003212a14
                        (uVar18,0x2000,&local_4b0,&local_4b4,local_470,&uStack_4b8,&local_4bc);
      if ((iVar3 == 0) && (local_4b4 == 1)) {
        *puVar12 = 0x13;
        *(ulong *)(puVar12 + 2) = local_470[0];
        *(undefined8 *)(puVar12 + 4) = 0;
        *(undefined8 *)(puVar12 + 6) = DAT_fffffff007114010;
        puVar12[1] = (int)uVar16;
        thunk_EXT_FUN_8011000003214790(puVar12,uVar16);
        *(undefined8 *)(puVar12 + 2) = 0;
      }
      thunk_EXT_FUN_80110000038fe6b0(puVar12,uVar16);
    }
  }
  if (plVar7 != (long *)0x0) {
    plVar8 = (long *)thunk_EXT_FUN_80110000038ce200("com.apple.agx.restartreport");
    if (plVar8 != (long *)0x0) {
      lVar15 = *(long *)(*(long *)(param_2 + 0x450) + 0x20);
      if (lVar15 == 0) {
        (**(code **)(*plVar8 + 0xa8))(plVar8);
      }
      else {
        thunk_EXT_FUN_80110000024b8af4(lVar15,plVar8,plVar7);
      }
      (**(code **)(*plVar8 + 0x28))(plVar8);
    }
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  if (*(long *)PTR_DAT_fffffff007ca61a0 == local_70) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

