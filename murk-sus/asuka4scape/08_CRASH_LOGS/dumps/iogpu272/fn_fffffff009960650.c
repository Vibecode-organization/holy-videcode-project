// FUN_fffffff009960650 @ fffffff009960650 size=484

void FUN_fffffff009960650(long param_1)

{
  long lVar1;
  byte bVar2;
  bool bVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  long *plVar9;
  long lVar10;
  long *plVar11;
  long *plVar12;
  ulong unaff_x30;
  byte bVar13;
  undefined4 in_wzr;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x1a8) + 0x168) + 1;
  *(long *)(*(long *)(param_1 + 0x1a8) + 0x168) = lVar1;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x160));
  bVar13 = (byte)in_wzr;
  if (*(long **)(param_1 + 0x168) == (long *)0x0) {
    lVar10 = 0;
    bVar3 = true;
  }
  else {
    lVar10 = 0;
    bVar3 = true;
    plVar11 = *(long **)(param_1 + 0x168);
    do {
      while( true ) {
        plVar12 = (long *)plVar11[6];
        if (((*(byte *)(param_1 + 0x194) & 1) != 0) ||
           (iVar6 = (**(code **)(*plVar11 + 0x90))(plVar11), iVar6 == 0)) break;
        *(undefined1 *)((long)plVar11 + 0x62) = 0;
        lVar8 = plVar11[0x1a];
        lVar7 = plVar11[6];
        if (lVar7 == 0) {
          plVar9 = (long *)plVar11[7];
          if ((long *)*plVar9 != plVar11) goto LAB_fffffff009960824;
          *(long **)(param_1 + 0x170) = plVar9;
        }
        else {
          if (*(long **)(lVar7 + 0x38) != plVar11 + 6) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009960834);
            (*pcVar4)();
          }
          if (*(long **)plVar11[7] != plVar11) {
LAB_fffffff009960824:
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00996082c);
            (*pcVar4)();
          }
          *(long **)(lVar7 + 0x38) = (long *)plVar11[7];
          plVar9 = (long *)plVar11[7];
        }
        lVar10 = lVar8 + lVar10;
        *plVar9 = lVar7;
        (**(code **)(*plVar11 + 0x28))(plVar11);
        bVar13 = (byte)in_wzr;
        plVar11 = plVar12;
        if (plVar12 == (long *)0x0) goto LAB_fffffff009960768;
      }
      bVar13 = (byte)in_wzr;
      bVar3 = false;
      plVar11 = plVar12;
    } while (plVar12 != (long *)0x0);
  }
LAB_fffffff009960768:
  *(long *)(param_1 + 0x178) = lVar1;
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x160));
  bVar5 = false;
  bVar2 = *(byte *)(param_1 + 400);
  *(byte *)(param_1 + 400) = bVar13;
  if ((bVar2 & 1) != 0) {
    bVar5 = *(long *)(param_1 + 0x180) == *(long *)(param_1 + 0x188);
    *(long *)(param_1 + 0x180) = *(long *)(param_1 + 0x180) + 1;
  }
  *(bool *)(param_1 + 0x191) = bVar3;
  if ((*(int *)(param_1 + 0x198) == 0) || (!bVar3 && !bVar5)) {
    return;
  }
  if (bVar3) {
    lVar10 = FUN_fffffff0099749b8(*(undefined8 *)(param_1 + 0x1a8),0);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    FUN_fffffff00995f52c(param_1,2,lVar10);
    return;
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009960808);
  (*pcVar4)();
}

