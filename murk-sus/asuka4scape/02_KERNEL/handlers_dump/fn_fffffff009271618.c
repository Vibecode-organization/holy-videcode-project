// FUN_fffffff009271618 @ fffffff009271618 size=4 depth=0
// CALLERS:
//   fffffff00afdd227 ?
//   fffffff007efee58 ?
// CALLS:

undefined8 FUN_fffffff009271618(long *param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long *plVar6;
  long *plVar7;
  
  if (*(int *)(param_3 + 0x28) != 1) {
    thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
    return 0xe00002c2;
  }
  uVar3 = **(undefined1 **)(param_3 + 0x20);
  iVar1 = *(int *)(param_3 + 0x60);
  if (iVar1 == 0) {
    uVar4 = 0xe00002bc;
    plVar6 = *(long **)(param_3 + 0x68);
    if (plVar6 == (long *)0x0) {
      plVar7 = (long *)0x0;
      uVar4 = 0xe00002c7;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x70);
      uVar5 = (**(code **)(*plVar6 + 0xd8))(plVar6,0);
      if ((int)uVar5 != 0) {
        thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n")
        ;
        return uVar5;
      }
      plVar7 = (long *)(**(code **)(*plVar6 + 0xe8))(plVar6,0);
      if (plVar7 == (long *)0x0) {
        thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n")
        ;
        goto LAB_fffffff0092716f4;
      }
      uVar4 = (**(code **)(*plVar7 + 0x78))();
      uVar4 = (**(code **)(*param_1 + 0x640))(param_1,uVar3,uVar4);
      *(undefined4 *)(param_3 + 0x70) = uVar2;
      if ((int)uVar4 == 0) goto joined_r0xfffffff009271830;
    }
LAB_fffffff0092717fc:
    thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
  }
  else {
    uVar4 = (**(code **)(*param_1 + 0x640))(param_1,uVar3,*(undefined8 *)(param_3 + 0x58));
    plVar6 = (long *)0x0;
    plVar7 = (long *)0x0;
    *(int *)(param_3 + 0x60) = iVar1;
    if ((int)uVar4 != 0) goto LAB_fffffff0092717fc;
  }
joined_r0xfffffff009271830:
  if (plVar7 != (long *)0x0) {
    (**(code **)(*plVar7 + 0xa8))(plVar7);
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  if (plVar6 == (long *)0x0) {
    return uVar4;
  }
LAB_fffffff0092716f4:
  (**(code **)(*plVar6 + 0xe0))(plVar6,0);
  return uVar4;
}

