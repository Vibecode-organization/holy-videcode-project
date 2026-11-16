// FUN_fffffff00a4bc168 @ fffffff00a4bc168 size=1008

undefined8 FUN_fffffff00a4bc168(long param_1,short *param_2,undefined4 *param_3)

{
  ulong uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  ushort uVar7;
  short sVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  undefined8 uVar12;
  
  iVar5 = 0;
  do {
    FUN_fffffff00a228180(&DAT_fffffff00adcb5d8);
    lVar11 = *(long *)(DAT_fffffff00adcb5e8 + ((ulong)*(byte *)((long)param_2 + 0x1d) & 0x1f) * 0x10
                      );
    if (lVar11 != 0) {
      lVar10 = 0;
      do {
        if (1 < DAT_fffffff00ad9447c) {
          FUN_fffffff00a4b8148("net_port_info_match_npi",lVar11 + 0x2c);
        }
        lVar9 = lVar10;
        if (((*(short *)(lVar11 + 0x2c) == *param_2) ||
            (((*(ushort *)(lVar11 + 0x2e) >> 0xc & 1) != 0 && (((ushort)param_2[1] >> 0xc & 1) != 0)
             ))) && (*(short *)(lVar11 + 0x48) == param_2[0xe])) {
          uVar7 = *(ushort *)(lVar11 + 0x2e);
          uVar2 = param_2[1] ^ uVar7;
          if ((uVar2 & 0xd) == 0 || (uVar2 & 0xe) == 0) {
            sVar8 = *(short *)(lVar11 + 0x4a);
            if (sVar8 == param_2[0xf]) {
              uVar2 = param_2[1] & uVar7;
              if ((uVar2 & 1) == 0) {
                if (((uVar2 >> 1 & 1) == 0) ||
                   ((iVar4 = FUN_fffffff00a3542b4(lVar11 + 0x4c,param_2 + 0x10,0x10), iVar4 != 0 ||
                    (iVar4 = FUN_fffffff00a3542b4(lVar11 + 0x5c,param_2 + 0x18,0x10), iVar4 != 0))))
                {
LAB_fffffff00a4bc1fc:
                  sVar8 = *(short *)(lVar11 + 0x4a);
                  goto LAB_fffffff00a4bc200;
                }
                uVar7 = *(ushort *)(lVar11 + 0x2e);
              }
              else if ((*(int *)(lVar11 + 0x4c) != *(int *)(param_2 + 0x10)) ||
                      (*(int *)(lVar11 + 0x5c) != *(int *)(param_2 + 0x18)))
              goto LAB_fffffff00a4bc1fc;
              if ((uVar7 >> 9 & 1) == 0) goto LAB_fffffff00a4bc414;
              lVar9 = lVar11;
              if (lVar10 != 0) {
                lVar9 = lVar10;
              }
            }
            else {
LAB_fffffff00a4bc200:
              if (sVar8 == 0) {
                if (lVar10 == 0) {
                  FUN_fffffff00a3542b4(lVar11 + 0x4c,param_2 + 0x10,0x10);
                  lVar9 = lVar11;
                }
                else if (((*(ushort *)(lVar11 + 0x2e) >> 9 & 1) == 0) &&
                        (iVar4 = FUN_fffffff00a3542b4(lVar11 + 0x4c,param_2 + 0x10,0x10),
                        lVar9 = lVar11, iVar4 != 0)) {
                  lVar9 = lVar10;
                }
              }
            }
          }
        }
        lVar11 = *(long *)(lVar11 + 8);
        lVar10 = lVar9;
      } while (lVar11 != 0);
      if (lVar9 != 0) {
        uVar7 = *(ushort *)(lVar9 + 0x2e);
        lVar11 = lVar9;
LAB_fffffff00a4bc414:
        param_2[1] = uVar7 & 0xfffc | param_2[1] & 3U;
        param_2[0x45] = *(short *)(lVar11 + 0xb6);
        *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(lVar11 + 0x6c);
        *(undefined4 *)(param_2 + 0x22) = *(undefined4 *)(lVar11 + 0x70);
        uVar6 = FUN_fffffff00a1d14a0(lVar11 + 0x74,0x11);
        uVar1 = uVar6;
        if (0x10 < uVar6) {
          uVar1 = 0x11;
        }
        if (0xf < uVar6) {
          uVar6 = 0x10;
        }
        FUN_fffffff00aa65b10(param_2 + 0x24,lVar11 + 0x74,uVar1);
        *(undefined1 *)((long)(param_2 + 0x24) + uVar6) = 0;
        uVar6 = FUN_fffffff00a1d14a0(lVar11 + 0x85,0x11);
        uVar1 = uVar6;
        if (0x10 < uVar6) {
          uVar1 = 0x11;
        }
        if (0xf < uVar6) {
          uVar6 = 0x10;
        }
        FUN_fffffff00aa65b10((long)param_2 + 0x59,lVar11 + 0x85,uVar1);
        *(undefined1 *)((long)param_2 + 0x59 + uVar6) = 0;
        uVar12 = *(undefined8 *)(lVar11 + 0x96);
        *(undefined8 *)(param_2 + 0x39) = *(undefined8 *)(lVar11 + 0x9e);
        *(undefined8 *)(param_2 + 0x35) = uVar12;
        uVar12 = *(undefined8 *)(lVar11 + 0xa6);
        *(undefined8 *)(param_2 + 0x41) = *(undefined8 *)(lVar11 + 0xae);
        *(undefined8 *)(param_2 + 0x3d) = uVar12;
        uVar3 = *(undefined4 *)(lVar11 + 0x28);
        *(undefined4 *)(lVar11 + 0x28) = DAT_fffffff00adcb60c;
        *param_3 = uVar3;
        iVar5 = FUN_fffffff00a228d30(&DAT_fffffff00adcb5d8);
        if (iVar5 == 1) {
          if (DAT_fffffff00ad9447c != 0) {
            FUN_fffffff00a4b8148("wake packet match",param_2);
          }
          return 1;
        }
        goto LAB_fffffff00a4bc534;
      }
    }
    iVar4 = FUN_fffffff00a228d30(&DAT_fffffff00adcb5d8);
    if (iVar4 != 1) {
LAB_fffffff00a4bc534:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114("lck_rw_unlock_shared(): lock %p held in mode: %d @%s:%d");
    }
    if (DAT_fffffff00ad9447c == 0) {
      lVar11 = *(long *)(param_1 + 0x898);
    }
    else {
      FUN_fffffff00a4b8148("wake packet no match",param_2);
      lVar11 = *(long *)(param_1 + 0x898);
    }
    if (lVar11 == 0) {
      return 0;
    }
    if (iVar5 == 4) {
      if (0 < DAT_fffffff00ad95218) {
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,DAT_fffffff00ad95428,0,
                   "net_port_info_find_match: max delegation depth %u exceeded for %s");
      }
      return 0;
    }
    if (0 < DAT_fffffff00ad95218) {
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad95428,0,
                 "net_port_info_find_match %s check on delegated %s");
      lVar11 = *(long *)(param_1 + 0x898);
    }
    *param_2 = *(short *)(lVar11 + 0xcc);
    param_1 = *(long *)(param_1 + 0x898);
    iVar5 = iVar5 + 1;
  } while( true );
}

