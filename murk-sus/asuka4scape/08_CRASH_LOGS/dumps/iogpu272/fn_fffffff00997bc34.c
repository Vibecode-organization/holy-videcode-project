// FUN_fffffff00997bc34 @ fffffff00997bc34 size=532

void FUN_fffffff00997bc34(void)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  long *plVar4;
  long *plVar5;
  undefined8 uVar6;
  long lVar7;
  long in_x3;
  uint uVar8;
  undefined8 uVar9;
  ulong unaff_x30;
  
  plVar4 = (long *)FUN_fffffff00997b958();
  plVar5 = (long *)(**(code **)(*plVar4 + 0x138))(plVar4,"Mappings");
  if (plVar5 == (long *)0x0) {
    plVar5 = (long *)thunk_EXT_FUN_80110000038961f4(2);
    (**(code **)(*plVar4 + 0x100))(plVar4,"Mappings",plVar5);
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
  }
  plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(plVar5,*(undefined8 *)PTR_DAT_fffffff007ff27a0);
  iVar2 = (**(code **)(*plVar4 + 0x90))();
  if (iVar2 != 0) {
    uVar8 = 0;
    uVar9 = *(undefined8 *)PTR_DAT_fffffff007ff27a8;
    do {
      uVar6 = (**(code **)(*plVar4 + 0x118))(plVar4,uVar8);
      plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(uVar6,uVar9);
      lVar7 = (**(code **)(*plVar5 + 0xb0))();
      if (lVar7 == in_x3) {
        return;
      }
      uVar8 = uVar8 + 1;
      uVar3 = (**(code **)(*plVar4 + 0x90))(plVar4);
    } while (uVar8 < uVar3);
  }
  plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(in_x3,0x40);
  (**(code **)(*plVar4 + 0xe8))(plVar4,plVar5);
  if (plVar5 == (long *)0x0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00997be30. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar5 + 0x28))(plVar5,(undefined8 *)(*plVar5 + 0x28));
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997be28);
  (*pcVar1)();
}

