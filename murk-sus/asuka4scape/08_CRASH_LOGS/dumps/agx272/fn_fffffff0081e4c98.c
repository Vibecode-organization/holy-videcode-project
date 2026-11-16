// FUN_fffffff0081e4c98 @ fffffff0081e4c98 size=380

/* WARNING: Removing unreachable block (ram,0xfffffff0081e4d90) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081e4d28) */

undefined8
FUN_fffffff0081e4c98
          (long *param_1,long *param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          uint param_6)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  int iVar5;
  long lVar6;
  
  uVar3 = (**(code **)(PTR_DAT_fffffff007ca60f8 + 0x98))();
  if ((int)uVar3 != 0) {
    uVar1 = (uint)((ulong)param_5 >> 0x20);
    *(byte *)(param_1 + 0xb) =
         (byte)(uVar1 >> 5) & 2 | (byte)(uVar1 >> 4) & 1 | *(byte *)(param_1 + 0xb) & 0xfc;
    lVar4 = (**(code **)(*param_1 + 0x118))(*param_1 + 0x118,param_1);
    lVar6 = (long)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f));
    param_1[9] = (lVar4 + lVar6) - 1U & -lVar6;
    param_1[10] = lVar4;
    uVar2 = (**(code **)(*param_2 + 0xb18))(*param_2 + 0xb18,param_2);
    uVar1 = 1 << (ulong)(uVar1 >> 0xb & 0x1f);
    if (uVar2 <= DAT_fffffff00ae21818) {
      uVar2 = DAT_fffffff00ae21818;
    }
    if (uVar1 <= uVar2) {
      uVar1 = uVar2;
    }
    if ((uVar1 < param_6) || (param_6 = uVar1, 1 < uVar1)) {
      iVar5 = 1 << (ulong)(-(int)LZCOUNT(param_6 - 1) & 0x1f);
    }
    else {
      iVar5 = 1;
    }
    *(int *)((long)param_1 + 0x14) = iVar5;
  }
  return uVar3;
}

