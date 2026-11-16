// FUN_fffffff0081a72a0 @ fffffff0081a72a0 size=332

/* WARNING: Removing unreachable block (ram,0xfffffff0081a7350) */

ulong FUN_fffffff0081a72a0(long *param_1,long *param_2)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  code *pcVar4;
  long lVar5;
  long lVar6;
  undefined8 local_38;
  
  iVar1 = (**(code **)(*param_1 + 0x38))();
  pcVar4 = *(code **)(*param_1 + 0x30);
  while (uVar2 = (*pcVar4)(param_1), uVar2 == (iVar1 + 1U & 0xff)) {
    local_38 = 0;
    thunk_EXT_FUN_8011000003204ed8(10,1000000,&local_38);
    (**(code **)(*param_2 + 0x110))(*param_2 + 0x110,param_2,param_1,local_38,0);
    iVar1 = (**(code **)(*param_1 + 0x38))(param_1);
    pcVar4 = *(code **)(*param_1 + 0x30);
  }
  lVar6 = param_1[3];
  uVar3 = (**(code **)(*param_1 + 0x38))(param_1);
  lVar5 = (uVar3 & 0xffffffff) * 0x18;
  uVar3 = lVar6 + (int)lVar5;
  if (lVar5 - (int)lVar5 != 0) {
    uVar3 = lVar6 + lVar5 & 0xffffffffffffU | 0x2bad000000000000;
  }
  return uVar3;
}

