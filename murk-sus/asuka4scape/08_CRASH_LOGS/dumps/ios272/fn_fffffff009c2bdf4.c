// FUN_fffffff009c2bdf4 @ fffffff009c2bdf4 size=804

/* WARNING: Removing unreachable block (ram,0xfffffff009c2c044) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2bfd0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2bf28) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2becc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2bef4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2bf84) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2c00c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2c078) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2be40) */

void FUN_fffffff009c2bdf4(long param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  ulong unaff_x30;
  
  plVar8 = (long *)(param_1 + 0x40);
  lVar4 = *plVar8;
  if (lVar4 != 0) {
    if ((lVar4 != 0) && (*(long *)(param_1 + 0x30) != 0)) {
      plVar7 = (long *)(param_1 + 0x28);
      FUN_fffffff009c2a738(lVar4);
      lVar4 = *plVar7;
      if (lVar4 == 0) {
        plVar6 = *(long **)(param_1 + 0x30);
        if (*plVar6 != param_1) goto LAB_fffffff009c2c108;
        lVar5 = *plVar8;
        *(long **)(lVar5 + 0x2f8) = plVar6;
        *plVar6 = 0;
      }
      else {
        if (*(long **)(lVar4 + 0x30) != plVar7) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c2c118);
          (*pcVar2)();
        }
        if (**(long **)(param_1 + 0x30) != param_1) {
LAB_fffffff009c2c108:
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c2c110);
          (*pcVar2)();
        }
        *(long **)(lVar4 + 0x30) = *(long **)(param_1 + 0x30);
        lVar5 = *(long *)(param_1 + 0x40);
        **(long **)(param_1 + 0x30) = lVar4;
        if (lVar5 == 0) {
          lVar5 = 0;
        }
      }
      FUN_fffffff009c2a744(lVar5);
      *plVar7 = 0;
      *(undefined8 *)(param_1 + 0x30) = 0;
      lVar4 = *plVar8;
      if (lVar4 == 0) goto LAB_fffffff009c2c0a8;
    }
    if (((lVar4 != 0) && (uVar1 = *(uint *)(lVar4 + 0x98), uVar1 != 0)) &&
       (lVar5 = *(long *)(param_1 + 0x68), lVar5 != param_1 + 0x78)) {
      *(undefined8 *)(param_1 + 0x68) = 0;
      thunk_EXT_FUN_80110000038fe768(&DAT_fffffff00806c010,lVar5,(ulong)uVar1 << 3);
      *(undefined8 *)(param_1 + 0x68) = 0;
      lVar4 = *(long *)(param_1 + 0x40);
      if (lVar4 == 0) goto LAB_fffffff009c2c0a8;
    }
    if (lVar4 != 0) {
      if ((int)*(undefined8 *)(param_1 + 0x90) != 0) {
        FUN_fffffff009c2302c(lVar4,0);
        lVar4 = *plVar8;
      }
      if (*(ulong *)(param_1 + 0x90) >> 0x20 != 0) {
        if (lVar4 == 0) {
          lVar4 = 0;
        }
        FUN_fffffff009c2302c(lVar4,1);
        lVar4 = *plVar8;
      }
      if (lVar4 == 0) {
        lVar4 = 0;
      }
      iVar3 = FUN_fffffff009c233e4(lVar4);
      if (iVar3 != 0) {
        lVar4 = *plVar8;
        if (lVar4 == 0) {
          lVar4 = 0;
        }
        FUN_fffffff009c2344c(lVar4);
      }
      plVar7 = (long *)*plVar8;
      if (plVar7 == (long *)0x0) {
        plVar7 = (long *)0x0;
      }
      (**(code **)(*plVar7 + 0x28))();
      *plVar8 = 0;
    }
  }
LAB_fffffff009c2c0a8:
  if (*(long **)(param_1 + 0x10) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x10) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x10) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2c0fc);
    (*pcVar2)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c2c104. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
  return;
}

