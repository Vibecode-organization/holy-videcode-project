// FUN_fffffff0081c8b70 @ fffffff0081c8b70 size=312

/* WARNING: Removing unreachable block (ram,0xfffffff0081c8c70) */

undefined8 FUN_fffffff0081c8b70(long *param_1,long *param_2,long *param_3,long *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = param_1[0x50];
  iVar2 = FUN_fffffff0081a5528();
  if (iVar2 != 0) {
    iVar2 = (**(code **)(*param_4 + 0xa8))(param_4);
    iVar3 = (**(code **)(*param_2 + 0xb8))(param_2,"power");
    if (iVar3 == 0) {
      return 0xe00002c7;
    }
    iVar3 = (**(code **)(*param_3 + 0xb8))(param_3,"pz_enable");
    if (iVar3 == 0) {
      return 0xe00002c7;
    }
    if ((*(byte *)(lVar4 + 0x10f78) & 1) == 0) {
      return 0xe00002c7;
    }
    uVar1 = 0;
    if (iVar2 != 0) {
      uVar1 = *(undefined4 *)(lVar4 + 0x10f80);
    }
    *(undefined4 *)(lVar4 + 0x10f84) = uVar1;
    *(undefined4 *)(param_1[0x123] + 0xc) = uVar1;
    (**(code **)(*param_1 + 0x690))(*param_1 + 0x690,param_1);
  }
  return 0;
}

