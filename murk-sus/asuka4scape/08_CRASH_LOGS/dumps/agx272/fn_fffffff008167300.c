// FUN_fffffff008167300 @ fffffff008167300 size=488

/* WARNING: Removing unreachable block (ram,0xfffffff0081673a4) */

undefined8 FUN_fffffff008167300(long *param_1,ulong param_2,ulong param_3)

{
  ulong *puVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  
  if ((*(byte *)((long)param_1 + 0x1112c) >> 1 & 1) != 0) {
    thunk_EXT_FUN_80110000032222a8(param_1[0x359c]);
    uVar3 = (**(code **)(*param_1 + 0xd98))(param_1,param_1[0x359b],param_2);
    iVar2 = (**(code **)(*param_1 + 0x790))(*param_1 + 0x790,param_1);
    if ((int)uVar3 != iVar2) {
      uVar5 = (uVar3 & 0xffffffff) << 4;
      uVar4 = -(uVar3 >> 0x1f & 1) & 0xfffffff000000000 | uVar5;
      iVar2 = (int)uVar5;
      uVar3 = param_1[0x359d] + (long)iVar2;
      if (uVar4 != (long)iVar2) {
        uVar3 = param_1[0x359d] + uVar4 & 0xffffffffffff | 0x2bad000000000000;
      }
      uVar5 = (param_2 & 0xffffffff) >> 3 & 0x1ffffff8;
      puVar1 = (ulong *)(uVar3 + (long)(int)uVar5);
      if (uVar5 != (long)(int)uVar5) {
        puVar1 = (ulong *)(uVar3 + uVar5 & 0xffffffffffff | 0x2bad000000000000);
      }
      *puVar1 = *puVar1 & (1L << (param_2 & 0x3f) ^ 0xffffffffffffffffU);
    }
    if ((int)param_3 == -1) {
      param_3 = (**(code **)(*param_1 + 0x790))(param_1);
    }
    else {
      uVar3 = (param_3 & 0xffffffff) << 4;
      uVar5 = -(param_3 >> 0x1f & 1) & 0xfffffff000000000 | uVar3;
      iVar2 = (int)uVar3;
      uVar3 = param_1[0x359d] + (long)iVar2;
      if (uVar5 != (long)iVar2) {
        uVar3 = param_1[0x359d] + uVar5 & 0xffffffffffff | 0x2bad000000000000;
      }
      uVar5 = (param_2 & 0xffffffff) >> 3 & 0x1ffffff8;
      puVar1 = (ulong *)(uVar3 + (long)(int)uVar5);
      if (uVar5 != (long)(int)uVar5) {
        puVar1 = (ulong *)(uVar3 + uVar5 & 0xffffffffffff | 0x2bad000000000000);
      }
      *puVar1 = *puVar1 | 1L << (param_2 & 0x3f);
    }
    (**(code **)(*param_1 + 0xd90))(param_1,param_1[0x359b],param_2,param_3);
    thunk_EXT_FUN_8011000003222de0(param_1[0x359c]);
  }
  return 1;
}

