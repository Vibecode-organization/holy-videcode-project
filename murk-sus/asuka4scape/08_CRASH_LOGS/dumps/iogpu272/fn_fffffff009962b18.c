// FUN_fffffff009962b18 @ fffffff009962b18 size=292

void FUN_fffffff009962b18(long *param_1)

{
  code *pcVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long *plVar6;
  ulong uVar7;
  ulong unaff_x30;
  
  uVar2 = (ulong)*(uint *)(param_1 + 10);
  if (0 < (int)*(uint *)(param_1 + 10)) {
    lVar3 = 0;
    uVar5 = param_1[9];
    do {
      plVar6 = (long *)(uVar5 + lVar3 * 0x18);
      if (((uVar5 ^ (ulong)plVar6) & 0xffc0000000000000) != 0) {
        plVar6 = (long *)((ulong)plVar6 & 0xffffffffffff | 0xc8a2000000000000);
      }
      if ((*plVar6 != 0) && ((*(byte *)(plVar6 + 2) & 1) != 0)) {
        *(undefined1 *)(plVar6 + 2) = 0;
        uVar7 = uVar5 + lVar3 * 0x18;
        if (((uVar5 ^ uVar7) & 0xffc0000000000000) != 0) {
          uVar7 = uVar7 & 0xffffffffffff | 0xc8a2000000000000;
        }
        *(int *)(uVar7 + 0xc) = *(int *)(uVar7 + 0xc) + 1;
      }
      lVar3 = lVar3 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  thunk_EXT_FUN_80110000038ff2e0(param_1[0xb]);
  thunk_EXT_FUN_80110000032222a8(param_1[0x2c]);
  *(undefined1 *)((long)param_1 + 0x194) = 0;
  uVar2 = thunk_EXT_FUN_8011000003397c88();
  lVar3 = param_1[0x2d];
  if (lVar3 != 0) {
    lVar4 = param_1[0x21];
    do {
      uVar5 = (uVar2 - lVar4) + *(long *)(lVar3 + 0x78);
      if (uVar2 <= uVar5) {
        uVar5 = uVar2;
      }
      *(ulong *)(lVar3 + 0x78) = uVar5;
      lVar3 = *(long *)(lVar3 + 0x30);
    } while (lVar3 != 0);
  }
  thunk_EXT_FUN_8011000003222de0(param_1[0x2c]);
  *(int *)((long)param_1 + 0x114) = (int)param_1[0x1d];
  *(undefined4 *)(param_1 + 0x1d) = 0;
  FUN_fffffff00994cc9c(param_1[0x36]);
  (**(code **)(*param_1 + 0x98))(param_1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009962c38);
    (*pcVar1)();
  }
  FUN_fffffff0099601b0(param_1);
  return;
}

