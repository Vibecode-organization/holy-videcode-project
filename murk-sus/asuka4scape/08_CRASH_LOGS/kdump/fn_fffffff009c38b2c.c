// FUN_fffffff009c38b2c @ fffffff009c38b2c size=280
// CALLERS:
//   fffffff00afec05a ?
//   fffffff008068cf8 ?
//   fffffff008069658 ?
// CALLS:
//   fffffff009c3c3b8 FUN_fffffff009c3c3b8

undefined4
FUN_fffffff009c38b2c
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined8 param_8,long param_9)

{
  undefined4 uVar1;
  long *plVar2;
  uint *puVar3;
  ulong uVar4;
  int *piVar5;
  undefined1 extraout_q0 [16];
  
  uVar1 = 0xe00002c2;
  piVar5 = *(int **)(param_9 + 0x58);
  plVar2 = *(long **)(param_9 + 0x40);
  if (plVar2 == (long *)0x0) {
    plVar2 = (long *)0x0;
    puVar3 = *(uint **)(param_9 + 0x30);
    uVar4 = (ulong)*(uint *)(param_9 + 0x38);
  }
  else {
    plVar2 = (long *)(**(code **)(*plVar2 + 0xe8))(plVar2,0x1000);
    if (plVar2 == (long *)0x0) {
      return 0xe00002c8;
    }
    puVar3 = (uint *)(**(code **)(*plVar2 + 0x78))();
    uVar4 = (**(code **)(**(long **)(param_9 + 0x40) + 0xb0))();
    param_1 = extraout_q0;
  }
  if (puVar3 != (uint *)0x0 && 0xc < (uint)uVar4) {
    uVar1 = FUN_fffffff009c3c3b8
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,puVar3,uVar4,piVar5);
  }
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return uVar1;
}

