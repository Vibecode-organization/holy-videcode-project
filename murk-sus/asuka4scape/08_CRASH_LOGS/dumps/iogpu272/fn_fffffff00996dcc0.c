// FUN_fffffff00996dcc0 @ fffffff00996dcc0 size=4

ulong FUN_fffffff00996dcc0(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 uVar11;
  ulong uVar12;
  long *plVar13;
  int iVar14;
  ulong uVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  
  uVar10 = 0xe00002d8;
  lVar18 = *(long *)(*(long *)(param_1 + 0x10) + 0x160);
  lVar16 = *(long *)(param_1 + 0x60);
  iVar7 = (int)param_2;
  if (iVar7 == *(int *)(lVar18 + 0x158)) {
    lVar17 = *(long *)(param_1 + 0x28);
    iVar2 = *(int *)(param_1 + 0x30);
    if (iVar2 < 2) {
      uVar12 = 0;
      iVar14 = 0;
    }
    else {
      iVar14 = 0;
      uVar12 = 0;
      uVar15 = (ulong)(iVar2 - 1);
      do {
        if (lVar16 == 0) {
          uVar8 = 0;
        }
        else {
          uVar8 = 0xe00002eb;
          if ((*(byte *)(lVar16 + 0x5c8) & 1) == 0) {
            uVar8 = 0;
          }
        }
        if (iVar7 != *(int *)(lVar18 + 0x158)) {
          uVar8 = 0xe00002d8;
        }
        if (uVar8 != 0) {
          uVar10 = (ulong)(iVar14 - 1);
          if (iVar14 < 1) {
            return (ulong)uVar8;
          }
          lVar16 = uVar10 + 1;
          do {
            FUN_fffffff0099437a0(*(undefined8 *)(lVar17 + uVar10 * 8));
            uVar10 = uVar10 - 1;
            lVar16 = lVar16 + -1;
          } while (lVar16 != 0);
          return (ulong)uVar8;
        }
        plVar13 = *(long **)(lVar17 + (long)iVar14 * 8);
        iVar3 = FUN_fffffff009943760(plVar13,*(undefined8 *)(param_1 + 0x128));
        if (iVar3 == 0) {
          lVar5 = (**(code **)(*plVar13 + 0x108))(plVar13);
          uVar12 = lVar5 + uVar12;
          iVar14 = iVar14 + 1;
        }
        else {
          uVar9 = -(uVar15 >> 0x1f) & 0xfffffff800000000 | uVar15 << 3;
          iVar3 = (int)(uVar15 << 3);
          puVar1 = (undefined8 *)(lVar17 + iVar3);
          if (uVar9 != (long)iVar3) {
            puVar1 = (undefined8 *)(lVar17 + uVar9 & 0xffffffffffff | 0x2bad000000000000);
          }
          *(undefined8 *)(lVar17 + (long)iVar14 * 8) = *puVar1;
          *puVar1 = plVar13;
          uVar15 = (ulong)((int)uVar15 - 1);
        }
      } while (iVar14 < (int)uVar15);
    }
    uVar9 = *(ulong *)(param_1 + 0x130);
    FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x10),0);
    uVar4 = FUN_fffffff0099749b8(*(undefined8 *)(param_1 + 0x10),0);
    uVar15 = FUN_fffffff0099749b8(*(undefined8 *)(param_1 + 0x10),1);
    if (uVar15 <= uVar4) {
      uVar15 = uVar4;
    }
    if ((*(byte *)(*(long *)(param_1 + 0x10) + 0x1ff) >> 4 & 1) == 0) {
      lVar5 = FUN_fffffff009974f6c(*(long *)(param_1 + 0x10),0);
      lVar6 = FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x10),1);
      if (uVar15 < uVar9) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s <%s> (%p) : required > max : requiredBytes = <%llu> preparedBytes : <%llu> maxWired = <%llu> maxWiredInternal = <%llu> currentWired = <%llu>\n"
                  );
        uVar9 = lVar6 + lVar5;
      }
      lVar6 = (long)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ff2740 & 0x1f));
      lVar5 = 0;
      if (lVar6 != 0) {
        lVar5 = (long)(uVar9 - uVar12) / lVar6;
      }
      if (lVar5 < 1) {
        if (lVar5 < 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s <%s>: requiredBytes = <%llu> maxWired = <%llu> preparedBytes : <%llu> remainingBytes : <%lld> remainingPages = <%lld>\n\n"
                    );
        }
      }
      else {
        iVar3 = thunk_EXT_FUN_8011000003313940();
        if (iVar3 != 0) {
          iVar3 = FUN_fffffff009961970
                            (*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x160),uVar9 - uVar12,0);
          FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x10),0);
          if (iVar3 != 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                       "%s <%s> FAILED To Free, should return error: <0x%X> total accelerator = 0x%llX max = 0x%llX\n"
                      );
          }
        }
      }
    }
    if (iVar14 < iVar2) {
      uVar15 = (ulong)iVar14;
      do {
        if (((*(byte *)(param_1 + 0x4c) & 1) != 0) ||
           ((lVar16 != 0 && ((*(byte *)(lVar16 + 0x5c8) & 1) != 0)))) {
          uVar4 = 0xe00002eb;
LAB_fffffff00996e180:
          if ((long)uVar15 < 1) {
            return uVar4;
          }
          uVar12 = uVar15 & 0xffffffff;
          uVar10 = (uVar15 & 0xffffffff) + 1;
          do {
            uVar12 = uVar12 - 1;
            FUN_fffffff0099437a0(*(undefined8 *)(lVar17 + uVar12 * 8));
            uVar10 = uVar10 - 1;
          } while (1 < uVar10);
          return uVar4;
        }
        uVar4 = uVar10;
        if (iVar7 != *(int *)(lVar18 + 0x158)) goto LAB_fffffff00996e180;
        uVar4 = FUN_fffffff009943680
                          (*(undefined8 *)(lVar17 + uVar15 * 8),param_2,0,
                           *(undefined8 *)(param_1 + 0x128));
        if ((int)uVar4 != 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s: failed to prepare memory status = 0x%X\n");
          goto LAB_fffffff00996e180;
        }
        lVar5 = (**(code **)(**(long **)(lVar17 + uVar15 * 8) + 0x108))();
        uVar12 = lVar5 + uVar12;
        uVar15 = uVar15 + 1;
      } while (iVar2 != (int)uVar15);
    }
    if (((*(byte *)(*(long *)(param_1 + 0x10) + 0x1ff) >> 4 & 1) == 0) && (uVar12 != uVar9)) {
      FUN_fffffff009974f6c(*(long *)(param_1 + 0x10),0);
      FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x10),1);
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s <%s>: preparedBytes != requiredBytes : preparedBytes = <%llu> requiredBytes = <%llu> maxWired = <%llu> preWiring = <%llu> currentWired = <%llu> wiring delta = <%llu>\n\n"
                );
    }
    *(undefined1 *)(param_1 + 0x4d) = 1;
    if (DAT_fffffff00af227e8 != 0) {
      uVar11 = *(undefined8 *)(param_1 + 0x100);
      lVar16 = FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x10),0);
      lVar18 = FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x10),1);
      thunk_EXT_FUN_80110000036da494(0x851801c4,uVar11,uVar12,lVar18 + lVar16,0,0);
    }
    uVar10 = 0;
  }
  return uVar10;
}

