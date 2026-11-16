// FUN_fffffff00a592b00 @ fffffff00a592b00 size=1464

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a592b00(ulong param_1,long param_2,long param_3,long param_4)

{
  ulong *puVar1;
  ulong uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  uint *puVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  int in_wzr;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  local_48 = DAT_fffffff00ad30000;
  _DAT_fffffff00ad12638 = _DAT_fffffff00ad12638 + 1;
  DAT_fffffff00adcf37c = DAT_fffffff00adcf37c + 1;
  if (((*(ushort *)(param_1 + 0xd2) >> 3 & 1) == 0) && ((*(byte *)(param_2 + 0x75) >> 5 & 1) == 0))
  {
    puVar8 = (uint *)(param_4 + 4);
    if (((*puVar8 & 0xf0) != 0xe0) || (*puVar8 != *(uint *)(param_3 + 0x10))) {
      _DAT_fffffff00ad12640 = _DAT_fffffff00ad12640 + 1;
      DAT_fffffff00adcf380 = DAT_fffffff00adcf380 + 1;
      uVar6 = 0x16;
      goto LAB_fffffff00a592dd8;
    }
    if ((_DAT_fffffff00ad12680 != 0) && (*(int *)(param_3 + 0xc) == 0)) {
      FUN_fffffff00a228180(&DAT_fffffff00ad953e8);
      for (lVar9 = DAT_fffffff00ad88bf8; lVar9 != 0; lVar9 = *(long *)(lVar9 + 0x88)) {
        if (*(ulong *)(lVar9 + 0x30) == param_1) {
          iVar5 = *(int *)(lVar9 + 0x10);
          *(int *)(lVar9 + 0x10) = iVar5 + 1;
          if (iVar5 + 0xf0000001U < 0xf0000002) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff00aa61ed0();
          }
          FUN_fffffff00a228d30(&DAT_fffffff00ad953e8);
          lVar10 = tpidr_el1;
          puVar1 = (ulong *)(lVar9 + 8);
          if (*puVar1 == 0) {
            *puVar1 = (ulong)*(uint *)(lVar10 + 0x4e8);
          }
          else {
            FUN_fffffff00a2262d4(lVar9,lVar10,0);
          }
          uVar3 = (*(uint *)(lVar9 + 0x78) & 0xff00ff00) >> 8 |
                  (*(uint *)(lVar9 + 0x78) & 0xff00ff) << 8;
          *(uint *)(param_3 + 0xc) = uVar3 >> 0x10 | uVar3 << 0x10;
          if (*(int *)puVar1 == *(int *)(lVar10 + 0x4e8)) {
            *(int *)puVar1 = in_wzr;
          }
          else {
            FUN_fffffff00a226e08(lVar9,lVar10);
          }
          FUN_fffffff00a5937e4(lVar9);
          goto LAB_fffffff00a592c68;
        }
      }
      FUN_fffffff00a228d30(&DAT_fffffff00ad953e8);
    }
LAB_fffffff00a592c68:
    if (DAT_fffffff00ad7e080 != 0) {
      local_58 = 0;
      uStack_50 = 0;
      FUN_fffffff00a8dd3c8(2,puVar8,&local_58,0x10);
      uVar12 = param_1 & 0x7ffffffffff;
      if ((param_1 & 0x80000000000000) != 0) {
        uVar12 = param_1 | 0xffffff8000000000;
      }
      if ((((DAT_fffffff007c6a360 <= uVar12 || uVar12 < DAT_fffffff007c6a358) &&
           (uVar12 < DAT_fffffff007c6a378 || DAT_fffffff007c6a380 <= uVar12)) &&
          (DAT_fffffff007c6a3a8 <= uVar12 || uVar12 < DAT_fffffff007c6a3a0)) &&
         (uVar12 + 0x2400000000 >> 0x25 == 0)) {
        FUN_fffffff00a1d12d4();
      }
    }
    FUN_fffffff00a228180(&DAT_fffffff00adcf430);
    if (DAT_fffffff00ad7e750 != 0) {
      lVar9 = tpidr_el1;
      lVar10 = DAT_fffffff00ad7e750;
LAB_fffffff00a592d24:
      do {
        lVar11 = *(long *)(lVar10 + 0x20);
        *(int *)(lVar9 + 0x1c0) = *(int *)(lVar9 + 0x1c0) + 1;
        if (*(ulong *)(lVar10 + 8) == 0) {
          *(ulong *)(lVar10 + 8) = (ulong)*(uint *)(lVar9 + 0x4e8) | 0x30000000;
        }
        else {
          FUN_fffffff00a2262d4(lVar10,lVar9,1);
        }
        if ((*(ulong *)(lVar10 + 0x38) == param_1) && (*(uint *)(lVar10 + 0x30) == *puVar8)) {
          FUN_fffffff00a5a8e04(lVar10,1);
          puVar1 = (ulong *)(lVar10 + 8);
          if (*(int *)puVar1 == *(int *)(lVar9 + 0x4e8)) {
            *(int *)puVar1 = in_wzr;
          }
          else {
            FUN_fffffff00a226e08(lVar10,lVar9);
          }
          FUN_fffffff00a228d30(&DAT_fffffff00adcf430);
          if (*puVar1 == 0) {
            *puVar1 = (ulong)*(uint *)(lVar9 + 0x4e8);
            uVar12 = *(ulong *)(lVar10 + 0x58);
          }
          else {
            FUN_fffffff00a2262d4(lVar10,lVar9,0);
            uVar12 = *(ulong *)(lVar10 + 0x58);
          }
          if (uVar12 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff00aa5d948
                      ("igi != NULL",
                       "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/igmp.c"
                       ,0x5b9);
          }
          _DAT_fffffff00ad12648 = _DAT_fffffff00ad12648 + 1;
          DAT_fffffff00adcf384 = DAT_fffffff00adcf384 + 1;
          if (*(ulong *)(uVar12 + 8) == 0) {
            *(ulong *)(uVar12 + 8) = (ulong)*(uint *)(lVar9 + 0x4e8);
          }
          else {
            FUN_fffffff00a2262d4(uVar12,lVar9,0);
          }
          if (*(int *)(uVar12 + 0x30) == 3) {
            if (DAT_fffffff00adcf38c != 0) {
              FUN_fffffff00a593704(lVar10);
            }
          }
          else {
            *(undefined4 *)(lVar10 + 0x48) = 0;
            iVar5 = *(int *)(lVar10 + 0x4c);
            if (iVar5 < 5) {
              if (iVar5 - 3U < 2) {
LAB_fffffff00a592f5c:
                if (DAT_fffffff00ad7e080 != 0) {
                  local_58 = 0;
                  uStack_50 = 0;
                  FUN_fffffff00a8dd3c8(2,puVar8,&local_58,0x10);
                  uVar7 = FUN_fffffff00a593778(param_1);
                  uVar2 = param_1 & 0x7ffffffffff;
                  if ((param_1 & 0x80000000000000) != 0) {
                    uVar2 = param_1 | 0xffffff8000000000;
                  }
                  if (((uVar7 & 1) == 0) && (0xffffffdfffffffff < uVar2 + 0x400000000)) {
                    FUN_fffffff00a1d12d4();
                  }
                }
LAB_fffffff00a592fb0:
                iVar5 = 5;
LAB_fffffff00a592fb4:
                *(int *)(lVar10 + 0x4c) = iVar5;
              }
              else if (iVar5 == 2) {
                if (DAT_fffffff00ad7e080 != 0) {
                  local_58 = 0;
                  uStack_50 = 0;
                  FUN_fffffff00a8dd3c8(2,puVar8,&local_58,0x10);
                  uVar7 = FUN_fffffff00a593778(param_1);
                  uVar2 = param_1 & 0x7ffffffffff;
                  if ((param_1 & 0x80000000000000) != 0) {
                    uVar2 = param_1 | 0xffffff8000000000;
                  }
                  if (((uVar7 & 1) == 0) && (0xffffffdfffffffff < uVar2 + 0x400000000)) {
                    FUN_fffffff00a1d12d4();
                  }
                }
                if (*(int *)(uVar12 + 0x30) == 1) {
                  *(undefined4 *)(lVar10 + 0x4c) = 4;
                }
                else if (*(int *)(uVar12 + 0x30) == 2) goto LAB_fffffff00a592fb0;
              }
            }
            else {
              if (iVar5 == 5) goto LAB_fffffff00a592fb4;
              if (iVar5 == 6) goto LAB_fffffff00a592f5c;
            }
          }
          if (uVar12 + 0xa0 <= uVar12) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a592ebc);
            (*pcVar4)();
          }
          if (*(int *)(uVar12 + 8) == *(int *)(lVar9 + 0x4e8)) {
            *(int *)(uVar12 + 8) = in_wzr;
          }
          else {
            FUN_fffffff00a226e08(uVar12,lVar9);
          }
          if (*(int *)(lVar10 + 8) == *(int *)(lVar9 + 0x4e8)) {
            *(int *)(lVar10 + 8) = in_wzr;
          }
          else {
            FUN_fffffff00a226e08(lVar10,lVar9);
          }
          FUN_fffffff00a5a263c(lVar10,0);
          goto LAB_fffffff00a592dd4;
        }
        if (*(int *)(lVar10 + 8) == *(int *)(lVar9 + 0x4e8)) {
          *(int *)(lVar10 + 8) = in_wzr;
          lVar10 = lVar11;
          if (lVar11 == 0) break;
          goto LAB_fffffff00a592d24;
        }
        FUN_fffffff00a226e08(lVar10,lVar9);
        lVar10 = lVar11;
      } while (lVar11 != 0);
    }
    FUN_fffffff00a228d30(&DAT_fffffff00adcf430);
  }
LAB_fffffff00a592dd4:
  uVar6 = 0;
LAB_fffffff00a592dd8:
  if (DAT_fffffff00ad30000 != local_48) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4c590(uVar6);
  }
  return;
}

