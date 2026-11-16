// FUN_fffffff00994757c @ fffffff00994757c size=4

undefined8 FUN_fffffff00994757c(long param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined8 uStack_28;
  
  puVar4 = *(undefined8 **)(param_3 + 0x58);
  *puVar4 = *(undefined8 *)(param_1 + 0xe8);
  plVar2 = (long *)(*(undefined8 **)(param_1 + 0xd8))[1];
  if (plVar2 == (long *)0x0) {
    plVar2 = (long *)FUN_fffffff009975520
                               (*(undefined8 *)(param_1 + 0xf8),**(undefined8 **)(param_1 + 0xd8));
    *(long **)(*(long *)(param_1 + 0xd8) + 8) = plVar2;
    if (plVar2 == (long *)0x0) {
      puVar4[1] = 0;
      *(undefined4 *)(puVar4 + 3) = 0;
      return 0xe00002bd;
    }
  }
  uVar3 = (**(code **)(*plVar2 + 0x78))();
  puVar4[1] = uVar3;
  uVar1 = (**(code **)(**(long **)(*(long *)(param_1 + 0xd8) + 8) + 0x88))();
  *(undefined4 *)(puVar4 + 3) = uVar1;
  uStack_28 = 0;
  FUN_fffffff009964430(*(undefined8 *)(*(long *)(param_1 + 0x120) + 0x30),0,&uStack_28);
  puVar4[2] = uStack_28;
  return 0;
}

