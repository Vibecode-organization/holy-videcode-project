// FUN_fffffff0081a5488 @ fffffff0081a5488 size=160

void FUN_fffffff0081a5488(long param_1,uint param_2,undefined1 param_3,int param_4,int param_5)

{
  undefined1 *puVar1;
  ulong uVar2;
  long lVar3;
  ulong *puVar4;
  ulong uVar5;
  
  if ((int)param_2 < 0x24) {
    uVar2 = 1L << ((ulong)param_2 & 0x3f);
    lVar3 = *(long *)(param_1 + 0x918);
    puVar4 = (ulong *)(lVar3 + 0x644);
    *puVar4 = *puVar4 | uVar2;
    lVar3 = lVar3 + 0x64c;
    puVar1 = (undefined1 *)(lVar3 + (int)param_2);
    if ((ulong)param_2 != (long)(int)param_2) {
      puVar1 = (undefined1 *)(lVar3 + (ulong)param_2 & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar1 = param_3;
    if (param_4 == 0) {
      lVar3 = *(long *)(param_1 + 0x918);
      puVar4 = (ulong *)(lVar3 + 0x674);
      uVar5 = *puVar4 & (uVar2 ^ 0xffffffffffffffff);
    }
    else {
      lVar3 = *(long *)(param_1 + 0x918);
      puVar4 = (ulong *)(lVar3 + 0x674);
      uVar5 = *puVar4 | uVar2;
    }
    *puVar4 = uVar5;
    puVar4 = (ulong *)(lVar3 + 0x67c);
    if (param_5 == 0) {
      uVar2 = *puVar4 & (uVar2 ^ 0xffffffffffffffff);
    }
    else {
      uVar2 = *puVar4 | uVar2;
    }
    *puVar4 = uVar2;
    *(undefined4 *)(lVar3 + 0x684) = 1;
  }
  return;
}

