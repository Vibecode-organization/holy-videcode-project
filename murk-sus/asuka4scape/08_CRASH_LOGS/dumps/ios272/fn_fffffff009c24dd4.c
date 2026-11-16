// FUN_fffffff009c24dd4 @ fffffff009c24dd4 size=252

byte FUN_fffffff009c24dd4(long param_1,long *param_2,undefined8 param_3)

{
  undefined1 uVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x30);
  iVar2 = (**(code **)(*param_2 + 0xb8))(param_2,"CreationProperties");
  if (iVar2 == 0) {
    iVar2 = (**(code **)(*param_2 + 0xb8))(param_2,"IOSurfaceName");
    if (iVar2 != 0) {
      *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x28) + 8) + 0x18) = 1;
    }
    plVar3 = *(long **)(lVar4 + 0x1a8);
    uVar1 = (**(code **)(*plVar3 + 0xf0))(plVar3,param_2,param_3);
    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x20) + 8) + 0x18) = uVar1;
  }
  else {
    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x20) + 8) + 0x18) = 1;
  }
  return (*(byte *)(*(long *)(*(long *)(param_1 + 0x20) + 8) + 0x18) ^ 0xff) & 1;
}

