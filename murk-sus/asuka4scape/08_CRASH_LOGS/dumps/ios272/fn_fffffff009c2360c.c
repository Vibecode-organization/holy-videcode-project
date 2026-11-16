// FUN_fffffff009c2360c @ fffffff009c2360c size=380

/* WARNING: Removing unreachable block (ram,0xfffffff009c236c8) */

undefined8 FUN_fffffff009c2360c(long *param_1,long param_2,long param_3)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  long *plVar8;
  long *plVar9;
  
  thunk_EXT_FUN_80110000032222a8(param_1[10]);
  if ((int)param_1[0x75] == 0) {
    plVar8 = (long *)param_1[8];
    while (plVar1 = plVar8, plVar1 != (long *)0x0) {
      plVar9 = plVar1 + 6;
      plVar8 = (long *)*plVar9;
      if (plVar1[3] == param_2) {
        if (((*(byte *)((long)plVar1 + 0x59) & 1) == 0) ||
           (iVar3 = (**(code **)(*plVar1 + 0x18))(plVar1), iVar3 != 1)) goto LAB_fffffff009c23644;
        if (plVar1 == (long *)param_1[7]) {
          param_1[7] = 0;
          puVar6 = (undefined8 *)param_1[0x2f];
          *(undefined2 *)(puVar6 + 1) = 0;
          *puVar6 = 0;
        }
        (**(code **)(*param_1 + 0x20))(param_1);
        lVar4 = *plVar9;
        if (lVar4 == 0) {
          plVar5 = (long *)plVar1[7];
          if ((long *)*plVar5 != plVar1) goto LAB_fffffff009c23778;
          param_1[9] = (long)plVar5;
        }
        else {
          if (*(long **)(lVar4 + 0x38) != plVar9) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c23788);
            (*pcVar2)();
          }
          if (*(long **)plVar1[7] != plVar1) {
LAB_fffffff009c23778:
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c23780);
            (*pcVar2)();
          }
          *(long **)(lVar4 + 0x38) = (long *)plVar1[7];
          plVar5 = (long *)plVar1[7];
        }
        *plVar5 = lVar4;
        plVar5 = *(long **)(param_3 + 8);
        plVar1[6] = 0;
        plVar1[7] = (long)plVar5;
        *plVar5 = (long)plVar1;
        *(long **)(param_3 + 8) = plVar9;
      }
    }
    uVar7 = 1;
  }
  else {
LAB_fffffff009c23644:
    uVar7 = 0;
  }
  thunk_EXT_FUN_8011000003222de0(param_1[10]);
  return uVar7;
}

