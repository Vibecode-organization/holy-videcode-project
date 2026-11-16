// FUN_fffffff009c03804 @ fffffff009c03804

/* WARNING: Removing unreachable block (ram,0xfffffff009c03ac0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c03a40) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c039c0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c03940) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c03980) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c03a00) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c03a80) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c03b18) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c038fc) */

undefined8 FUN_fffffff009c03804(long *param_1,int param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  ulong unaff_x30;
  
  if (param_2 == -0x1ffefffe) {
    plVar2 = thunk_FUN_fffffff00a89ca6c(param_1[0x17]);
    if (plVar2 != (long *)0x0) {
      plVar3 = (long *)(**(code **)(*param_1 + 0x370))(param_1);
      plVar4 = (long *)(**(code **)(*plVar2 + 0x88))(plVar2);
      while (plVar4 != (long *)0x0) {
        (**(code **)(*param_1 + 0x300))(param_1,1);
        uVar5 = (**(code **)(*plVar4 + 0x5b0))(*plVar4 + 0x5b0,plVar4);
        uVar6 = (**(code **)(*plVar4 + 0x5a8))(*plVar4 + 0x5a8,plVar4);
        uVar7 = (**(code **)(*plVar3 + 0x5a0))(*plVar3 + 0x5a0,plVar3);
        uVar8 = (**(code **)(*plVar3 + 0x5f0))(*plVar3 + 0x5f0,plVar3);
        uVar9 = (**(code **)(*plVar4 + 0x5c8))(*plVar4 + 0x5c8,plVar4);
        uVar10 = (**(code **)(*plVar3 + 0x5d0))(*plVar3 + 0x5d0,plVar3);
        uVar11 = (**(code **)(*plVar4 + 0x5e0))(*plVar4 + 0x5e0,plVar4);
        (**(code **)(*plVar4 + 0x5e8))
                  (*plVar4 + 0x5e8,plVar4,uVar5,uVar6,uVar7,uVar8,uVar9,uVar10,uVar11,0);
        (**(code **)(*param_1 + 0x308))(*param_1 + 0x308,param_1);
        plVar4 = (long *)(**(code **)(*plVar2 + 0x88))(plVar2);
      }
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
    return 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    uVar5 = (*(code *)PTR_FUN_fffffff0080634a0)(param_1);
    return uVar5;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c03bd0);
  (*pcVar1)();
}

