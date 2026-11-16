// FUN_fffffff009c413b4 @ fffffff009c413b4

void FUN_fffffff009c413b4(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  *(undefined8 *)(param_2 + 4) = *(undefined8 *)(param_1 + 0x20);
  uVar2 = *(undefined8 *)(param_1 + 0x90);
  *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(param_1 + 0x28);
  uVar3 = *(undefined8 *)(param_1 + 0x30);
  *(undefined8 *)(param_2 + 0x30) = *(undefined8 *)(param_1 + 0x38);
  *(undefined8 *)(param_2 + 0x28) = uVar3;
  *(undefined8 *)(param_2 + 0x18) = uVar2;
  lVar1 = thunk_FUN_fffffff00a39bc88();
  *(long *)(param_2 + 0x20) = lVar1;
  uVar3 = *(undefined8 *)(param_1 + 0xb0);
  uVar2 = *(undefined8 *)(param_1 + 0xa8);
  uVar5 = *(undefined8 *)(param_1 + 0xc0);
  uVar4 = *(undefined8 *)(param_1 + 0xb8);
  uVar7 = *(undefined8 *)(param_1 + 0xd0);
  uVar6 = *(undefined8 *)(param_1 + 200);
  uVar8 = *(undefined8 *)(param_1 + 0x98);
  *(undefined8 *)(param_2 + 0x40) = *(undefined8 *)(param_1 + 0xa0);
  *(undefined8 *)(param_2 + 0x38) = uVar8;
  *(undefined8 *)(param_2 + 0x70) = uVar7;
  *(undefined8 *)(param_2 + 0x68) = uVar6;
  *(undefined8 *)(param_2 + 0x60) = uVar5;
  *(undefined8 *)(param_2 + 0x58) = uVar4;
  *(undefined8 *)(param_2 + 0x50) = uVar3;
  *(undefined8 *)(param_2 + 0x48) = uVar2;
  return;
}

