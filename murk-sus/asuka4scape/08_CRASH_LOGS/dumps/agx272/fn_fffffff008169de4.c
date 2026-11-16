// FUN_fffffff008169de4 @ fffffff008169de4 size=320

void FUN_fffffff008169de4(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x338));
  if ((*(byte *)(param_1 + 0x560) & 1) != 0) {
    thunk_EXT_FUN_8011000003397c88();
    lVar10 = *(long *)(param_1 + 0x340);
    if (lVar10 == 0) {
      *(undefined1 *)(param_1 + 0x560) = 0;
    }
    else {
      do {
        lVar11 = *(long *)(lVar10 + 0x10);
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar10 + 0x50));
        if (*(int *)(lVar10 + 0x48) != 2) {
          piVar7 = *(int **)(lVar10 + 0x1370);
          iVar8 = *piVar7;
          if (iVar8 != 0) {
            uVar9 = piVar7[1];
            uVar2 = uVar9;
            if (iVar8 - 1U <= uVar9) {
              uVar2 = iVar8 - 1U;
            }
            if (7 < uVar2) {
              *(undefined4 *)(lVar10 + 0x48) = 2;
              uVar1 = uVar2 + 1 & 7;
              uVar3 = 8;
              if (uVar1 != 0) {
                uVar3 = uVar1;
              }
              iVar4 = (uVar2 + 1) - uVar3;
              iVar5 = uVar9 - ((uVar2 - uVar3) - 7 & 0xfffffff8);
              uVar9 = uVar9 - iVar4;
              iVar8 = iVar8 - iVar4;
              piVar7[1] = iVar5 + -8;
            }
            do {
              uVar9 = uVar9 - 1;
              if (uVar9 == 0xffffffff) break;
              *(undefined4 *)(lVar10 + 0x48) = 2;
              piVar7[1] = uVar9;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
        }
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar10 + 0x50));
        lVar10 = lVar11;
      } while (lVar11 != 0);
      (**(code **)(**(long **)(param_1 + 0x558) + 0xf0))(*(long **)(param_1 + 0x558),1000);
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x338));
    return;
  }
                    /* WARNING: Does not return */
  pcVar6 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008169f20);
  (*pcVar6)();
}

