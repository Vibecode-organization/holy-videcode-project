// FUN_fffffff00819fdc4 @ fffffff00819fdc4 size=124

void FUN_fffffff00819fdc4(long param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  long lVar5;
  
  uVar2 = *param_2;
  uVar3 = (ulong)uVar2;
  if (uVar2 < *(uint *)(param_1 + 0x28)) {
    lVar5 = uVar3 * 0xc;
    puVar1 = (undefined4 *)((long)param_2 + (long)(int)lVar5 + 4);
    if (lVar5 - (int)lVar5 != 0) {
      puVar1 = (undefined4 *)
               ((ulong)(param_2 + uVar3 * 3 + 1) & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar1 = param_4;
    iVar4 = (int)(lVar5 + 4);
    puVar1 = (undefined4 *)((long)param_2 + (long)iVar4 + 4);
    if (lVar5 + 4 != (long)iVar4) {
      puVar1 = (undefined4 *)
               ((ulong)(param_2 + uVar3 * 3 + 2) & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar1 = param_3;
    iVar4 = (int)(lVar5 + 8);
    puVar1 = (undefined4 *)((long)param_2 + (long)iVar4 + 4);
    if (lVar5 + 8 != (long)iVar4) {
      puVar1 = (undefined4 *)
               ((ulong)(param_2 + uVar3 * 3 + 3) & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar1 = 0;
  }
  *param_2 = uVar2 + 1;
  return;
}

