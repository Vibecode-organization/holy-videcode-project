// FUN_fffffff009c3ab8c @ fffffff009c3ab8c size=1328
// CALLERS:
//   fffffff009c389d8 FUN_fffffff009c38890@fffffff009c38890

/* WARNING: Removing unreachable block (ram,0xfffffff009c3ae0c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c3ada8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
    FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a0baa);
    return 0xe00002be;
  }
  if (param_2 == 0) {
    return 0xe00002c2;
  }
  plVar3 = (long *)FUN_fffffff009c49764(param_2,param_5,0);
  if (plVar3 == (long *)0x0) {
    return 0xe00002c2;
  }
  plVar4 = (long *)FUN_fffffff009c498d4(plVar3,*_DAT_fffffff00806c9c8);
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
      FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a0bd3);
      goto LAB_fffffff009c3b078;
    }
  }
  uVar11 = (**(code **)(*plVar4 + 0x138))(plVar4,_DAT_fffffff008066fc0);
  plVar6 = (long *)FUN_fffffff009c498d4(uVar11,*_DAT_fffffff00806c9f8);
  if (plVar6 == (long *)0x0) {
LAB_fffffff009c3ade4:
    lVar7 = *(long *)(param_1 + 0xf8);
    if (lVar7 == 0) {
      lVar7 = 0;
    }
    plVar4 = (long *)FUN_fffffff009c33c34(*(undefined8 *)(param_1 + 0xe8),lVar7,plVar4,plVar5);
    if (plVar4 == (long *)0x0) {
      FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a0c7f);
      uVar11 = 0xe00002c2;
    }
    else {
      if ((*(byte *)(plVar4 + 0x7a) >> 1 & 1) != 0) {
        FUN_fffffff009c3eeac(param_1);
      }
      plVar8 = (long *)FUN_fffffff009c2b810(*(undefined8 *)(param_1 + 0x118),plVar4,1);
      if (plVar8 == (long *)0x0) {
        FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a0c55);
        uVar11 = 0xe00002bd;
      }
      else {
        FUN_fffffff009c495b4(*(undefined8 *)(param_1 + 0xd8));
        iVar2 = FUN_fffffff009c33dc4(*(undefined8 *)(param_1 + 0xe8),plVar4,(int)plVar4[2]);
        if (iVar2 == 0) {
          FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a0c3a);
LAB_fffffff009c3afd0:
          uVar11 = 0xe00002bd;
        }
        else {
          iVar2 = FUN_fffffff009c3f2b0(param_1,plVar8,(int)plVar4[2]);
          if (iVar2 == 0) {
            FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a0c1b);
            goto LAB_fffffff009c3afd0;
          }
          FUN_fffffff009c3f478(param_1,extraout_x1,1);
          FUN_fffffff009c2c18c(plVar8,param_4);
          uVar11 = 0;
        }
        FUN_fffffff009c495d4(*(undefined8 *)(param_1 + 0xd8));
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
    FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a0bf8);
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

