// FUN_fffffff00820087c @ fffffff00820087c size=816

void FUN_fffffff00820087c(long param_1)

{
  byte *pbVar1;
  long lVar2;
  byte bVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  long *plVar8;
  ulong uVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 400) != 0) {
    thunk_EXT_FUN_80110000038fe6b0(*(long *)(param_1 + 400),(ulong)*(uint *)(param_1 + 0x184) << 6);
    *(undefined4 *)(param_1 + 0x184) = 0;
    *(undefined8 *)(param_1 + 400) = 0;
  }
  if (*(long *)(param_1 + 0x1b0) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x1b0) = 0;
  }
  if (*(long *)(param_1 + 0x198) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x198) = 0;
  }
  if (*(long *)(param_1 + 0x168) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x168) = 0;
  }
  if ((*(byte *)(param_1 + 0x170) & 1) != 0) {
    thunk_EXT_FUN_80110000039a3d30(param_1 + 0x128);
    *(undefined1 *)(param_1 + 0x170) = 0;
  }
  if (*(long *)(param_1 + 0x178) != 0) {
    lVar11 = 0;
    lVar13 = 1;
    do {
      pbVar1 = (byte *)(*(long *)(param_1 + 0x178) + lVar11 * 2);
      if ((pbVar1[1] & 1) != 0) {
        lVar12 = *(long *)(param_1 + 0x48);
        bVar3 = *pbVar1;
        uVar9 = (ulong)bVar3;
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar12 + 0x11f30));
        uVar6 = (ulong)(bVar3 >> 6);
        uVar7 = 1L << (uVar9 & 0x3f);
        if (((*(ulong *)(lVar12 + 0x17f70 + uVar6 * 8) & uVar7) == 0) &&
           ((*(ulong *)(lVar12 + 0x17f90 + uVar6 * 8) & uVar7) == 0)) {
          lVar2 = lVar12 + 0x11f70 + uVar9 * 0x60;
          if ((ulong)*(ushort *)(lVar2 + 0x58) < 0x100 &&
              *(int *)(*(long *)(*(long *)(lVar2 + 0x50) + 0x48) + 0x10934) != 0) {
            *(undefined2 *)
             (*(long *)(*(long *)(lVar2 + 0x50) + 0x178) + (ulong)*(ushort *)(lVar2 + 0x58) * 2) = 0
            ;
          }
          iVar5 = thunk_EXT_FUN_80110000029479f8
                            (*(undefined8 *)(*(long *)(lVar12 + 0x11f38) + 0x148),lVar2 + 8);
          if (iVar5 != 0) {
            thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar12 + 0x11f30));
            FUN_fffffff0081e02dc(lVar12 + 0x11ee8,uVar9);
            goto LAB_fffffff00820094c;
          }
          *(undefined8 *)(lVar2 + 0x50) = 0;
        }
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar12 + 0x11f30));
      }
LAB_fffffff00820094c:
      lVar11 = lVar11 + 1;
      lVar13 = lVar13 + 2;
    } while (lVar13 != 0x201);
    thunk_EXT_FUN_80110000038fe6b0(*(undefined8 *)(param_1 + 0x178),0x200);
    *(undefined8 *)(param_1 + 0x178) = 0;
  }
  plVar10 = *(long **)(param_1 + 0x1f0);
  if (plVar10 != (long *)0x0) {
    lVar11 = *(long *)(param_1 + 0x48);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar11 + 0x338));
    iVar5 = (int)plVar10[4] + -1;
    *(int *)(plVar10 + 4) = iVar5;
    if (iVar5 == 0) {
      lVar13 = plVar10[2];
      if (lVar13 == 0) {
        plVar8 = (long *)plVar10[3];
        if ((long *)*plVar8 != plVar10) goto LAB_fffffff008200b9c;
        *(long **)(lVar11 + 0x348) = plVar8;
      }
      else {
        if (*(long **)(lVar13 + 0x18) != plVar10 + 2) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff008200bac);
          (*pcVar4)();
        }
        if (*(long **)plVar10[3] != plVar10) {
LAB_fffffff008200b9c:
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff008200ba4);
          (*pcVar4)();
        }
        *(long **)(lVar13 + 0x18) = (long *)plVar10[3];
        plVar8 = (long *)plVar10[3];
      }
      *plVar8 = lVar13;
      (**(code **)(*plVar10 + 0x28))(plVar10);
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar11 + 0x338));
    if (*(long **)(param_1 + 0x1f0) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x1f0) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x1f0) = 0;
  }
  plVar10 = (long *)thunk_EXT_FUN_80110000029636a8(param_1);
  if (plVar10 != (long *)0x0) {
    (**(code **)(*plVar10 + 0x180))();
  }
  if (*(long *)(param_1 + 0x1c0) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x1c0) = 0;
  }
  *(undefined1 *)(param_1 + 0x1c8) = 0;
  if (*(long **)(param_1 + 0x1e0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1e0) + 0x28))();
    *(undefined8 *)(param_1 + 0x1e0) = 0;
  }
  if (*(long *)(param_1 + 0x1e8) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x1e8) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008200b90);
    (*pcVar4)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff008200b98. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca60d0 + 0x80))(param_1);
  return;
}

