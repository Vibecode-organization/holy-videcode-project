// FUN_fffffff00997b958 @ fffffff00997b958 size=732

/* WARNING: Removing unreachable block (ram,0xfffffff00997bb80) */
/* WARNING: Removing unreachable block (ram,0xfffffff00997bad0) */

long * FUN_fffffff00997b958(undefined8 param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  long *plVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  long *plVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  
  plVar3 = (long *)FUN_fffffff00997b558();
  lVar4 = (**(code **)(*plVar3 + 0x138))(plVar3,"Processes");
  if (lVar4 == 0) {
    plVar5 = (long *)thunk_EXT_FUN_80110000038961f4(1);
    (**(code **)(*plVar3 + 0x100))(plVar3,"Processes",plVar5);
  }
  else {
    plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar4,*(undefined8 *)PTR_DAT_fffffff007ff27a0);
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x20))(plVar5);
    }
  }
  iVar1 = (**(code **)(*plVar5 + 0x90))(plVar5);
  if (iVar1 != 0) {
    uVar8 = 0;
    uVar9 = *(undefined8 *)PTR_DAT_fffffff007ff2758;
    uVar10 = *(undefined8 *)PTR_DAT_fffffff007ff27a8;
    do {
      uVar6 = (**(code **)(*plVar5 + 0x118))(plVar5,uVar8);
      plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(uVar6,uVar9);
      uVar6 = (**(code **)(*plVar3 + 0x138))(*plVar3 + 0x138,plVar3,"PID");
      plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(uVar6,uVar10);
      iVar1 = (**(code **)(*plVar7 + 0xa8))();
      if (iVar1 == param_3) goto LAB_fffffff00997bc00;
      uVar8 = uVar8 + 1;
      uVar2 = (**(code **)(*plVar5 + 0x90))(plVar5);
    } while (uVar8 < uVar2);
  }
  plVar3 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
  plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24((long)param_3,0x40);
  (**(code **)(*plVar3 + 0x100))(*plVar3 + 0x100,plVar3,"PID",plVar7);
  (**(code **)(*plVar5 + 0xe8))(plVar5,plVar3);
  if (plVar7 != (long *)0x0) {
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  (**(code **)(*plVar3 + 0x28))(plVar3);
LAB_fffffff00997bc00:
  (**(code **)(*plVar5 + 0x28))(plVar5);
  return plVar3;
}

