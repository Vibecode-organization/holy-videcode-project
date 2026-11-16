// FUN_fffffff00a51a178 @ fffffff00a51a178 size=924

void FUN_fffffff00a51a178(long param_1)

{
  long lVar1;
  bool bVar2;
  long *plVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  long *plVar12;
  long lVar13;
  int in_wzr;
  undefined4 uStack_e4;
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  long local_70;
  
  local_70 = DAT_fffffff00ad30000;
  iVar5 = FUN_fffffff00a3542b4(param_1 + 0x1d0,&DAT_fffffff007029084,0x10);
  if (iVar5 != 0) {
    FUN_fffffff00a228180(&DAT_fffffff00adcdd78);
    if (DAT_fffffff00adcddd8 != 0) {
      bVar2 = false;
      lVar1 = tpidr_el1;
      lVar10 = DAT_fffffff00adcddd8;
      do {
        if (*(ulong *)(lVar10 + 0x58) == 0) {
          *(ulong *)(lVar10 + 0x58) = (ulong)*(uint *)(lVar1 + 0x4e8);
        }
        else {
          FUN_fffffff00a2262d4(lVar10 + 0x50,lVar1,0);
        }
        lVar6 = FUN_fffffff00a4fcfe0(lVar10,param_1 + 0x1d0);
        if (lVar6 == 0) {
          if (bVar2) {
            FUN_fffffff00a771808(lVar10 + 0x60);
            lVar6 = *(long *)(lVar10 + 0x88);
            while (lVar6 != 0) {
              lVar13 = *(long *)(lVar6 + 0x18);
              FUN_fffffff00a6fbb00(lVar6,1);
              lVar6 = lVar13;
            }
          }
          if (*(int *)(lVar10 + 0x58) == *(int *)(lVar1 + 0x4e8)) {
            *(int *)(lVar10 + 0x58) = in_wzr;
          }
          else {
            FUN_fffffff00a226e08(lVar10 + 0x50,lVar1);
          }
        }
        else {
          if (*(ulong *)(lVar6 + 0x38) == 0) {
            *(ulong *)(lVar6 + 0x38) = (ulong)*(uint *)(lVar1 + 0x4e8);
            if ((*(byte *)(param_1 + 0x1d9) & 1) != 0) goto LAB_fffffff00a51a264;
LAB_fffffff00a51a43c:
            lVar13 = FUN_fffffff00a51a514(lVar6,param_1);
          }
          else {
            FUN_fffffff00a2262d4(lVar6 + 0x30,lVar1,0);
            if ((*(byte *)(param_1 + 0x1d9) & 1) == 0) goto LAB_fffffff00a51a43c;
LAB_fffffff00a51a264:
            local_80 = 0;
            uStack_98 = 0;
            local_a0 = 0;
            uStack_88 = 0;
            uStack_90 = 0;
            uStack_b8 = 0;
            local_c0 = 0;
            uStack_a8 = 0;
            uStack_b0 = 0;
            uStack_d4 = 0;
            uStack_c8 = 0;
            uStack_d0 = 0;
            uStack_dc = (undefined4)*(undefined8 *)(param_1 + 0x1d8);
            uStack_d8 = (undefined4)((ulong)*(undefined8 *)(param_1 + 0x1d8) >> 0x20);
            uStack_e4 = (undefined4)*(undefined8 *)(param_1 + 0x1d0);
            local_e0 = (undefined4)((ulong)*(undefined8 *)(param_1 + 0x1d0) >> 0x20);
            for (lVar13 = *(long *)(lVar6 + 0x4a0); lVar13 != 0; lVar13 = *(long *)(lVar13 + lVar11)
                ) {
              iVar5 = FUN_fffffff00a3542b4(&uStack_e4,lVar13 + 0x5c,0x10);
              if (iVar5 < 0) {
                lVar11 = 0x30;
              }
              else {
                if (iVar5 == 0) break;
                lVar11 = 0x38;
              }
            }
          }
          if (lVar13 != 0) {
            plVar12 = *(long **)(lVar13 + 0x90);
            while (plVar3 = plVar12, plVar3 != (long *)0x0) {
              plVar12 = (long *)*plVar3;
              if (((*(ushort *)(plVar3 + 2) >> 2 & 1) != 0) && (plVar3[3] == param_1)) {
                lVar11 = plVar3[0x15];
                if (lVar11 != 0) {
                  lVar7 = plVar3[0x14];
                  plVar3[0x14] = 0;
                  plVar3[0x15] = 0;
                  FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,lVar11,lVar7);
                }
                *(byte *)(lVar13 + 0x74) = *(byte *)(lVar13 + 0x74) & 0xfe;
                lVar11 = *plVar3;
                if (lVar11 == 0) {
                  plVar9 = (long *)plVar3[1];
                  if ((long *)*plVar9 != plVar3) goto LAB_fffffff00a51a500;
                  lVar11 = 0;
                }
                else {
                  if (*(long **)(lVar11 + 8) != plVar3) {
                    /* WARNING: Does not return */
                    pcVar4 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a51a510);
                    (*pcVar4)();
                  }
                  if (*(long **)plVar3[1] != plVar3) {
LAB_fffffff00a51a500:
                    /* WARNING: Does not return */
                    pcVar4 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a51a508);
                    (*pcVar4)();
                  }
                  *(undefined8 **)(lVar11 + 8) = (undefined8 *)plVar3[1];
                  lVar11 = *plVar3;
                  plVar9 = (long *)plVar3[1];
                }
                *plVar9 = lVar11;
                uVar8 = CONCAT44(0xfffffff0,DAT_fffffff00adcdd58);
                DAT_fffffff00adcdd58 = DAT_fffffff00adcdd58 + -1;
                FUN_fffffff00a29762c(uVar8,&DAT_fffffff007c73650,plVar3);
                bVar2 = true;
              }
            }
          }
          if (*(int *)(lVar6 + 0x38) == *(int *)(lVar1 + 0x4e8)) {
            *(int *)(lVar6 + 0x38) = in_wzr;
          }
          else {
            FUN_fffffff00a226e08(lVar6 + 0x30,lVar1);
          }
          if (bVar2) {
            FUN_fffffff00a771808(lVar10 + 0x60);
            lVar6 = *(long *)(lVar10 + 0x88);
            while (lVar6 != 0) {
              lVar11 = *(long *)(lVar6 + 0x18);
              FUN_fffffff00a6fbb00(lVar6,1);
              lVar6 = lVar11;
            }
            if (*(int *)(lVar10 + 0x58) == *(int *)(lVar1 + 0x4e8)) {
              *(int *)(lVar10 + 0x58) = in_wzr;
            }
            else {
              FUN_fffffff00a226e08(lVar10 + 0x50,lVar1);
            }
            if (lVar13 != 0) break;
            bVar2 = true;
          }
          else {
            if (*(int *)(lVar10 + 0x58) == *(int *)(lVar1 + 0x4e8)) {
              *(int *)(lVar10 + 0x58) = in_wzr;
            }
            else {
              FUN_fffffff00a226e08(lVar10 + 0x50,lVar1);
            }
            if (lVar13 != 0) break;
            bVar2 = false;
          }
        }
        lVar10 = *(long *)(lVar10 + 8);
      } while (lVar10 != 0);
    }
    FUN_fffffff00a228d30(&DAT_fffffff00adcdd78);
    *(undefined8 *)(param_1 + 0x1d0) = 0;
    *(undefined8 *)(param_1 + 0x1d8) = 0;
  }
  if (DAT_fffffff00ad30000 == local_70) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590();
}

