// FUN_fffffff009c3ab8c @ fffffff009c3ab8c size=1328

/* WARNING: Removing unreachable block (ram,0xfffffff009c3ae0c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c3ada8) */

undefined8
FUN_fffffff009c3ab8c
          (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined4 param_5)

{
  bool bVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long lVar7;
  long *plVar8;
  long *plVar9;
  ulong uVar10;
  undefined8 extraout_x1;
  undefined8 uVar11;
  
  uVar11 = 0xe00002c2;
  if (0x3fff < *(uint *)(param_1 + 0x128)) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
               "%s error - exceeded client limit (0x%x)\n");
    return 0xe00002be;
  }
  if (param_2 == 0) {
    return 0xe00002c2;
  }
  plVar3 = (long *)thunk_EXT_FUN_80110000038d4754(param_2,param_5,0);
  if (plVar3 == (long *)0x0) {
    return 0xe00002c2;
  }
  plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(plVar3,*(undefined8 *)PTR_DAT_fffffff00806c9c8);
  if (plVar4 == (long *)0x0) {
    uVar11 = 0xe00002c2;
    goto LAB_fffffff009c3b078;
  }
  if ((int)param_3 == 0) {
    plVar5 = (long *)0x0;
  }
  else {
    plVar5 = (long *)FUN_fffffff009c3f1d0(param_1,param_3);
    if (plVar5 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - invalid parent id (0x%x)\n")
      ;
      goto LAB_fffffff009c3b078;
    }
  }
  uVar11 = (**(code **)(*plVar4 + 0x138))(plVar4,DAT_fffffff008066fc0);
  plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(uVar11,*(undefined8 *)PTR_DAT_fffffff00806c9f8);
  if (plVar6 == (long *)0x0) {
LAB_fffffff009c3ade4:
    lVar7 = *(long *)(param_1 + 0xf8);
    if (lVar7 == 0) {
      lVar7 = 0;
    }
    plVar4 = (long *)FUN_fffffff009c33c34(*(undefined8 *)(param_1 + 0xe8),lVar7,plVar4,plVar5);
    if (plVar4 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "%s error - failed to alloc surface buffer\n");
      uVar11 = 0xe00002c2;
    }
    else {
      if ((*(byte *)(plVar4 + 0x7a) >> 1 & 1) != 0) {
        FUN_fffffff009c3eeac(param_1);
      }
      plVar8 = (long *)FUN_fffffff009c2b810(*(undefined8 *)(param_1 + 0x118),plVar4,1);
      if (plVar8 == (long *)0x0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "%s error - failed to alloc client buffer\n");
        uVar11 = 0xe00002bd;
      }
      else {
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd8));
        iVar2 = FUN_fffffff009c33dc4(*(undefined8 *)(param_1 + 0xe8),plVar4,(int)plVar4[2]);
        if (iVar2 == 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - set surface id\n");
LAB_fffffff009c3afd0:
          uVar11 = 0xe00002bd;
        }
        else {
          iVar2 = FUN_fffffff009c3f2b0(param_1,plVar8,(int)plVar4[2]);
          if (iVar2 == 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - set surface handle\n")
            ;
            goto LAB_fffffff009c3afd0;
          }
          FUN_fffffff009c3f478(param_1,extraout_x1,1);
          FUN_fffffff009c2c18c(plVar8,param_4);
          uVar11 = 0;
        }
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd8));
        (**(code **)(*plVar8 + 0x28))(plVar8);
      }
    }
    bVar1 = true;
    if (plVar6 != (long *)0x0) goto LAB_fffffff009c3b004;
  }
  else {
    (**(code **)(*plVar6 + 0x20))(plVar6);
    lVar7 = (**(code **)(*plVar6 + 0xb0))(plVar6);
    if (lVar7 == 0) goto LAB_fffffff009c3ade4;
    plVar8 = (long *)FUN_fffffff009c372dc(*(undefined8 *)(param_1 + 0xe8));
    plVar9 = (long *)FUN_fffffff009c42814(plVar8,lVar7);
    if (plVar8 != (long *)0x0) {
      (**(code **)(*plVar8 + 0x28))(plVar8);
    }
    if (plVar9 == (long *)0x0) goto LAB_fffffff009c3ade4;
    lVar7 = *(long *)(param_1 + 0xf8);
    if (lVar7 == 0) {
      lVar7 = 0;
    }
    uVar10 = FUN_fffffff009c44170(plVar9,lVar7);
    if ((uVar10 & 1) != 0) {
      (**(code **)(*plVar9 + 0x28))(plVar9);
      goto LAB_fffffff009c3ade4;
    }
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - pool off limits (%llu)\n");
    (**(code **)(*plVar9 + 0x28))(plVar9);
    bVar1 = false;
    plVar4 = (long *)0x0;
    uVar11 = 0xe00002c2;
LAB_fffffff009c3b004:
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  if (!bVar1) {
    uVar11 = 0xe00002e2;
  }
LAB_fffffff009c3b078:
  (**(code **)(*plVar3 + 0x28))(plVar3);
  return uVar11;
}

