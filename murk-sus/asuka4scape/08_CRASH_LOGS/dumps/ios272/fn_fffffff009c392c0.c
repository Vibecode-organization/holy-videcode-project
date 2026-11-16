// FUN_fffffff009c392c0 @ fffffff009c392c0 size=272

undefined8 FUN_fffffff009c392c0(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  
  uVar4 = 0xe00002c2;
  plVar2 = *(long **)(param_3 + 0x40);
  if (plVar2 == (long *)0x0) {
    plVar2 = (long *)0x0;
    lVar3 = *(long *)(param_3 + 0x30);
    uVar1 = *(uint *)(param_3 + 0x38);
  }
  else {
    plVar2 = (long *)(**(code **)(*plVar2 + 0xe8))(plVar2,0x1000);
    if (plVar2 == (long *)0x0) {
      return 0xe00002c8;
    }
    lVar3 = (**(code **)(*plVar2 + 0x78))();
    uVar1 = (**(code **)(**(long **)(param_3 + 0x40) + 0xb0))();
  }
  if (lVar3 != 0 && 0x10 < uVar1) {
    uVar4 = FUN_fffffff009c3d560(param_1,lVar3);
  }
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return uVar4;
}

