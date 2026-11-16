// FUN_fffffff0081ff7d8 @ fffffff0081ff7d8 size=180

void FUN_fffffff0081ff7d8(long param_1,uint param_2,long *param_3)

{
  undefined8 *puVar1;
  long *plVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  
  lVar3 = *(long *)(param_1 + 0x200);
  lVar5 = (ulong)param_2 * 8;
  plVar2 = (long *)(lVar3 + (int)lVar5);
  if (lVar5 != (int)lVar5) {
    plVar2 = (long *)(lVar3 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
  }
  plVar2 = (long *)*plVar2;
  lVar5 = (ulong)param_2 * 8;
  iVar4 = (int)lVar5;
  if (param_3 != plVar2 && plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))();
    lVar3 = *(long *)(param_1 + 0x200);
    puVar1 = (undefined8 *)(lVar3 + iVar4);
    if (lVar5 - iVar4 != 0) {
      puVar1 = (undefined8 *)(lVar3 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar1 = 0;
  }
  plVar2 = (long *)(lVar3 + iVar4);
  if (lVar5 - iVar4 != 0) {
    plVar2 = (long *)(lVar3 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *plVar2 = (long)param_3;
  return;
}

