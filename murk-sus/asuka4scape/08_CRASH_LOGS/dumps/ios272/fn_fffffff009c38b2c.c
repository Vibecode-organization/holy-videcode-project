// FUN_fffffff009c38b2c @ fffffff009c38b2c size=280

undefined8 FUN_fffffff009c38b2c(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *plVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  uVar4 = 0xe00002c2;
  uVar5 = *(undefined8 *)(param_3 + 0x58);
  plVar1 = *(long **)(param_3 + 0x40);
  if (plVar1 == (long *)0x0) {
    plVar1 = (long *)0x0;
    lVar2 = *(long *)(param_3 + 0x30);
    uVar3 = (ulong)*(uint *)(param_3 + 0x38);
  }
  else {
    plVar1 = (long *)(**(code **)(*plVar1 + 0xe8))(plVar1,0x1000);
    if (plVar1 == (long *)0x0) {
      return 0xe00002c8;
    }
    lVar2 = (**(code **)(*plVar1 + 0x78))();
    uVar3 = (**(code **)(**(long **)(param_3 + 0x40) + 0xb0))();
  }
  if (lVar2 != 0 && 0xc < (uint)uVar3) {
    uVar4 = FUN_fffffff009c3c3b8(param_1,lVar2,uVar3,uVar5);
  }
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar4;
}

