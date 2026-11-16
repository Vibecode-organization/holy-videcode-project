// FUN_fffffff00819c014 @ fffffff00819c014 size=656

/* WARNING: Removing unreachable block (ram,0xfffffff00819c1f0) */

void FUN_fffffff00819c014(long param_1,long *param_2)

{
  ulong uVar1;
  ulong uVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  long *plVar8;
  long lVar9;
  int iVar10;
  ulong uVar11;
  ulong uVar12;
  ulong unaff_x30;
  ulong local_68;
  
  param_2[2] = param_2[2] + 1;
  lVar6 = *(long *)(param_1 + 0x88);
  if (0xf < *(uint *)(lVar6 + 0x30)) {
    lVar9 = *(long *)(param_1 + 0x48);
    if ((*(byte *)(lVar9 + 0x1ac44) >> 3 & 1) != 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar9 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930d99,param_2,param_1,0,0,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar9 + 0x1ac48));
      lVar6 = *(long *)(param_1 + 0x88);
    }
    plVar7 = (long *)thunk_EXT_FUN_8011000002940a54(lVar6);
    lVar6 = *(long *)(param_1 + 0x48);
    if ((*(byte *)(lVar6 + 0x1ac44) >> 3 & 1) != 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930d9a,param_2,param_1,0,0,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0x1ac48));
    }
    if (plVar7 != (long *)0x0) {
      uVar4 = (**(code **)(*plVar7 + 0x90))(plVar7);
      if ((uVar4 == 0) || (*param_2 = *param_2 + 1, uVar4 < 0x11)) {
        *(undefined8 *)(param_1 + 0x210) = 0;
      }
      else {
        iVar10 = 0;
        lVar6 = 0;
        uVar11 = 0;
        uVar12 = (ulong)uVar4;
        while( true ) {
          lVar9 = thunk_EXT_FUN_8011000003397c88();
          local_68 = 0;
          thunk_EXT_FUN_8011000003398228(lVar9 - param_2[4],&local_68);
          if (999999 < local_68) break;
          uVar1 = uVar11 + *(long *)(param_1 + 0x210);
          uVar2 = 0;
          if (uVar12 != 0) {
            uVar2 = uVar1 / uVar12;
          }
          lVar6 = uVar1 - uVar2 * uVar12;
          plVar8 = (long *)(**(code **)(*plVar7 + 0x118))(plVar7,lVar6);
          iVar5 = (**(code **)(*plVar8 + 0x148))(*plVar8 + 0x148);
          if (iVar5 != 0) {
            iVar10 = iVar10 + 1;
            param_2[1] = param_2[1] + 1;
          }
          uVar11 = uVar11 + 1;
          if ((uVar12 == uVar11) || (*param_2 = *param_2 + 1, uVar4 - iVar10 < 0x11)) break;
        }
        *(long *)(param_1 + 0x210) = lVar6;
        if (iVar10 != 0) {
          param_2[3] = param_2[3] + 1;
        }
      }
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00819c2a0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*plVar7 + 0x28))(plVar7,(undefined8 *)(*plVar7 + 0x28));
        return;
      }
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00819c298);
      (*pcVar3)();
    }
  }
  return;
}

