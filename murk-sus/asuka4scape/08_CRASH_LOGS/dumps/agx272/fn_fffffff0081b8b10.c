// FUN_fffffff0081b8b10 @ fffffff0081b8b10 size=240

undefined8 FUN_fffffff0081b8b10(long param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = *(long *)(param_1 + 0x280);
  *(int *)(lVar4 + 0x10d54) = param_2;
  iVar1 = param_2;
  if (*(int *)(lVar4 + 0x10d7c) != 0) {
    iVar1 = *(int *)(lVar4 + 0x10d7c);
  }
  uVar3 = 0;
  if (*(uint *)(lVar4 + 0x10d30) != 0) {
    uVar3 = (uint)(iVar1 * 100) / *(uint *)(lVar4 + 0x10d30);
  }
  if (99 < uVar3) {
    uVar3 = 100;
  }
  thunk_EXT_FUN_80110000039b78d4
            (*(undefined8 *)(*(long *)(lVar4 + 0x1ac50) + 0x130),0,(ulong)uVar3 * 0x1999999a >> 0x20
            );
  lVar4 = *(long *)(param_1 + 0x918);
  *(int *)(lVar4 + 300) = iVar1;
  *(undefined4 *)(lVar4 + 0x128) = 1;
  lVar5 = *(long *)(param_1 + 0x280);
  if ((*(byte *)(lVar5 + 0x1ac44) >> 2 & 1) != 0) {
    uVar2 = *(undefined4 *)(lVar4 + 300);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x8592086c,uVar2,param_2,param_3,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x1ac48));
  }
  return 0;
}

