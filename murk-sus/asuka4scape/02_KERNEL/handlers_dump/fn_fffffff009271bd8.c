// FUN_fffffff009271bd8 @ fffffff009271bd8 size=4 depth=0
// CALLERS:
//   fffffff00afdd231 ?
//   fffffff007efeed0 ?
// CALLS:

undefined8 FUN_fffffff009271bd8(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  long *plVar7;
  long *plVar8;
  
  if (*(int *)(param_3 + 0x28) != 1) {
    thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
    return 0xe00002c2;
  }
  bVar3 = **(byte **)(param_3 + 0x20);
  iVar1 = *(int *)(param_3 + 0x60);
  if (iVar1 == 0) {
    uVar4 = 0xe00002bc;
    plVar7 = *(long **)(param_3 + 0x68);
    if (plVar7 == (long *)0x0) {
      plVar8 = (long *)0x0;
      uVar4 = 0xe00002c7;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x70);
      uVar5 = (**(code **)(*plVar7 + 0xd8))(plVar7,0);
      if ((int)uVar5 != 0) {
        thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n")
        ;
        return uVar5;
      }
      plVar8 = (long *)(**(code **)(*plVar7 + 0xe8))(plVar7,0);
      if (plVar8 == (long *)0x0) {
        thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n")
        ;
        goto LAB_fffffff009271c98;
      }
      puVar6 = (undefined8 *)(**(code **)(*plVar8 + 0x78))();
      uVar4 = FUN_fffffff00926b7a0(param_1,(uint)bVar3,0,puVar6);
      *(undefined4 *)(param_3 + 0x70) = uVar2;
      if ((int)uVar4 == 0) goto joined_r0xfffffff009271db8;
    }
LAB_fffffff009271d84:
    thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
  }
  else {
    uVar4 = FUN_fffffff00926b7a0(param_1,(uint)bVar3,0,*(undefined8 **)(param_3 + 0x58));
    plVar7 = (long *)0x0;
    plVar8 = (long *)0x0;
    *(int *)(param_3 + 0x60) = iVar1;
    if ((int)uVar4 != 0) goto LAB_fffffff009271d84;
  }
joined_r0xfffffff009271db8:
  if (plVar8 != (long *)0x0) {
    (**(code **)(*plVar8 + 0xa8))(plVar8);
    (**(code **)(*plVar8 + 0x28))(plVar8);
  }
  if (plVar7 == (long *)0x0) {
    return uVar4;
  }
LAB_fffffff009271c98:
  (**(code **)(*plVar7 + 0xe0))(plVar7,0);
  return uVar4;
}

