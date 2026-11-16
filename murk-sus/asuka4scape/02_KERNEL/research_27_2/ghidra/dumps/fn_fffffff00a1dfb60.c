// FUN_fffffff00a1dfb60 @ fffffff00a1dfb60 size=336
// CALLERS:
//   fffffff00afb817d no-fn
//   fffffff00a1ee338 FUN_fffffff00a1ee0f0@fffffff00a1ee0f0
//   fffffff00a1dfdf0 FUN_fffffff00a1dfcb0@fffffff00a1dfcb0
//   fffffff00a1e97d8 FUN_fffffff00a1e9454@fffffff00a1e9454
//   fffffff00a1e98a0 FUN_fffffff00a1e9454@fffffff00a1e9454
// CALLEES:
//   fffffff00a36d048 FUN_fffffff00a36d048

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff00a1dfb60(long param_1,long param_2,uint *param_3,ulong *param_4)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  uint *puVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  long *plVar9;
  
  uVar7 = *(ulong *)(param_1 + 0x48);
  if (uVar7 == 0) {
LAB_fffffff00a1dfbb0:
    puVar5 = (uint *)&DAT_0000000c;
    uVar8 = (ulong)_DAT_0000000c;
  }
  else {
    if ((uVar7 >> 0x26 & 1) == 0) {
      if (uVar7 == 0) goto LAB_fffffff00a1dfbb0;
      uVar6 = (uVar7 & 0x3fff) << 0xe;
      uVar7 = uVar7 & 0xffffffffffffc000 | 0x4000000000;
    }
    else {
      uVar6 = (uVar7 & 0x10 | 0x20) << (uVar7 & 0xf);
      uVar7 = uVar7 & 0xffffffffffffffe0;
    }
    puVar5 = (uint *)(uVar7 + 0xc);
    uVar8 = (ulong)*puVar5;
    if (uVar8 * 0x18 + 0x18 <= uVar6) {
      plVar9 = (long *)(uVar7 + uVar8 * 0x18);
      if (((uVar7 ^ (ulong)plVar9) & 0xffc0000000000000) != 0) {
        plVar9 = (long *)((ulong)plVar9 & 0xffffffffffff | 0xc8a2000000000000);
      }
      goto LAB_fffffff00a1dfc08;
    }
  }
  plVar9 = (long *)0x0;
LAB_fffffff00a1dfc08:
  if (plVar9 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a1dfcb0);
    (*pcVar3)();
  }
  *puVar5 = *(uint *)((long)plVar9 + 0xc);
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
  uVar2 = *(uint *)(plVar9 + 1);
  uVar1 = (uVar2 & 0x3000000) * 4 + 0x4000000;
  uVar4 = uVar2 + uVar1;
  if (CARRY4(uVar2,uVar1)) {
    uVar4 = FUN_fffffff00a36d048((int *)(param_1 + 0x20),param_1 + 0x1c,1,2);
    uVar4 = uVar4 << 0x18;
  }
  *(uint *)(plVar9 + 1) = uVar4;
  *(undefined4 *)((long)plVar9 + 0xc) = 0;
  if (param_2 == 0) {
    param_2 = 0;
  }
  *plVar9 = param_2;
  *param_3 = (uint)((uVar8 << 0x20) >> 0x18) | uVar4 >> 0x18 | 3;
  *param_4 = (ulong)plVar9;
  return 0;
}

