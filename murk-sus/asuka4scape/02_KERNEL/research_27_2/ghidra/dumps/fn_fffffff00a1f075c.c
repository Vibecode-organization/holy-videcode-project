// FUN_fffffff00a1f075c @ fffffff00a1f075c size=232
// CALLERS:
//   fffffff00afb828d no-fn
//   fffffff00a1f7bb8 FUN_fffffff00a1f79e8@fffffff00a1f79e8
// CALLEES:
//   fffffff00aa4cc7c FUN_fffffff00aa4cc7c

undefined8
FUN_fffffff00a1f075c(long param_1,undefined4 param_2,ulong param_3,ulong param_4,uint *param_5)

{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  code *pcVar4;
  ulong *puVar5;
  ulong uVar6;
  
  if ((*(byte *)(param_1 + 1) & 7) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4cc7c();
  }
  uVar6 = *(ulong *)(param_1 + 0x68);
  if ((uVar6 != 0) && (uVar6 != 0)) {
    uVar1 = uVar6 & 0xffffffffffffc000 | 0x4000000000;
    uVar3 = (uVar6 & 0x3fff) << 0xe;
    if ((uVar6 & 0x4000000000) != 0) {
      uVar1 = uVar6 & 0xffffffffffffffe0;
      uVar3 = (uVar6 & 0x10 | 0x20) << (uVar6 & 0xf);
    }
    uVar2 = *(uint *)(uVar1 + 8);
    if (uVar2 != 0) {
      if ((ulong)uVar2 * 0x10 + 0x10 <= uVar3) {
        puVar5 = (ulong *)(uVar1 + (ulong)uVar2 * 0x10);
        if (((uVar1 ^ (ulong)puVar5) & 0xffc0000000000000) != 0) {
          puVar5 = (ulong *)((ulong)puVar5 & 0xffffffffffff | 0xc8a2000000000000);
        }
        if (puVar5 != (ulong *)0x0) {
          *(int *)(uVar1 + 8) = (int)puVar5[1];
          *(undefined4 *)(puVar5 + 1) = param_2;
          *puVar5 = param_4 | param_3;
          if ((param_4 == 3) && ((*(uint *)(param_1 + 0x10) >> 6 & 1) == 0)) {
            *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x40;
          }
          *param_5 = uVar2;
          return 0;
        }
      }
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a1f0834);
      (*pcVar4)();
    }
  }
  return 3;
}

