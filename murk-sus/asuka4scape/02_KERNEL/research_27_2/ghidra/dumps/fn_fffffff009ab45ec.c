// FUN_fffffff009ab45ec @ fffffff009ab45ec size=260
// CALLERS:
//   fffffff00afe8a90 no-fn
//   fffffff009ab1018 FUN_fffffff009ab0f98@fffffff009ab0f98
//   fffffff009ab43c8 FUN_fffffff009ab40ec@fffffff009ab40ec
// CALLEES:

ulong FUN_fffffff009ab45ec(ulong param_1,uint param_2,long param_3,int *param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  
  uVar1 = *(uint *)(param_3 + 8);
  uVar4 = 0;
  if (uVar1 != 0) {
    uVar4 = 0x4000 / uVar1;
  }
  iVar2 = 0x1f;
  if (0x80000000U >> (ulong)((uint)LZCOUNT(uVar4) & 0x1f) < uVar4) {
    iVar2 = 0x20;
  }
  uVar6 = iVar2 - (uint)LZCOUNT(uVar4);
  uVar4 = 1 << (ulong)(uVar6 + 1 >> 1 & 0x1f);
  uVar6 = uVar1 << (ulong)(uVar6 >> 1 & 0x1f);
  uVar5 = (ulong)uVar6;
  iVar2 = 0;
  if (uVar5 != 0) {
    iVar2 = (int)(((uVar5 + (ulong)uVar1 * (param_1 & 0xffffffff)) - 1) / uVar5);
  }
  iVar2 = iVar2 * uVar6;
  uVar1 = 0;
  if (uVar4 != 0) {
    uVar1 = ((param_2 + uVar4) - 1) / uVar4;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = iVar2;
  }
  uVar1 = uVar1 * uVar4 * iVar2 + 0x7f & 0xffffff80;
  if (param_5 != (uint *)0x0) {
    *param_5 = uVar1;
  }
  uVar5 = (ulong)param_2 + 0xf >> 4;
  uVar4 = (uint)LZCOUNT((int)uVar5);
  iVar2 = 0x1f;
  if (0x80000000 >> (ulong)(uVar4 & 0x1f) < uVar5) {
    iVar2 = 0;
  }
  uVar5 = (param_1 & 0xffffffff) + 7 >> 3;
  uVar6 = (uint)LZCOUNT((int)uVar5);
  iVar3 = 0x1f;
  if (0x80000000 >> (ulong)(uVar6 & 0x1f) < uVar5) {
    iVar3 = 0;
  }
  uVar5 = (ulong)(uint)~(-1 << (ulong)(*(uint *)PTR_DAT_fffffff00802a388 & 0x1f));
  return uVar5 + (uVar1 + (((2 << (ulong)(iVar3 - uVar6 & 0x1f)) << (ulong)(iVar2 - uVar4 & 0x1f)) +
                           0x7fU & 0xffffff80)) & (uVar5 ^ 0xffffffffffffffff);
}

