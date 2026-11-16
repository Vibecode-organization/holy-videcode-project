// FUN_fffffff0081b8dcc @ fffffff0081b8dcc size=160

undefined8
FUN_fffffff0081b8dcc(long *param_1,int param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  int iVar6;
  long lVar7;
  
  if (param_2 == 0) {
    uVar4 = 1L << ((ulong)param_3 & 0x3f);
    if ((*(ulong *)(param_1[0x50] + 0x105f8) & uVar4) == 0) {
      return 0xe00002bc;
    }
    lVar5 = param_1[0x69];
    lVar7 = (ulong)param_3 * 8;
    iVar6 = (int)lVar7;
    puVar1 = (undefined8 *)(lVar5 + 0xa08 + (long)iVar6);
    if (lVar7 - iVar6 != 0) {
      puVar1 = (undefined8 *)(lVar5 + 0xa08 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
    }
    puVar2 = (undefined8 *)(lVar5 + 0xc08 + (long)iVar6);
    if (lVar7 - iVar6 != 0) {
      puVar2 = (undefined8 *)(lVar5 + 0xc08 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar1 = param_4;
    *puVar2 = param_5;
    uVar3 = (ulong)(param_3 >> 3) & 0x1ffffff8;
    *(ulong *)(lVar5 + 0xa00 + uVar3) = *(ulong *)(lVar5 + 0xa00 + uVar3) | uVar4;
  }
  else {
    *(undefined8 *)(param_1[0x69] + 0xa00) = 0;
  }
  (**(code **)(*param_1 + 0x1b8))();
  return 0;
}

