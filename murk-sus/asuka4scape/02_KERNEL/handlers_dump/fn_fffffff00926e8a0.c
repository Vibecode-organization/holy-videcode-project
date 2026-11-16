// FUN_fffffff00926e8a0 @ fffffff00926e8a0 size=4 depth=0
// CALLERS:
//   fffffff00afdd1cb ?
//   fffffff007efe418 ?
// CALLS:

undefined8 FUN_fffffff00926e8a0(long *param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  long *plVar2;
  long *plVar3;
  ulong uStack_48;
  
  if (*(uint *)(param_3 + 0x60) == 0) {
    plVar2 = *(long **)(param_3 + 0x68);
    if (plVar2 == (long *)0x0) {
      plVar3 = (long *)0x0;
      uVar1 = 0xe00002c7;
    }
    else {
      uStack_48 = (ulong)*(uint *)(param_3 + 0x70);
      uVar1 = (**(code **)(*plVar2 + 0xd8))(plVar2,0);
      if ((int)uVar1 != 0) {
        thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n")
        ;
        plVar2 = (long *)0x0;
        goto LAB_fffffff00926e960;
      }
      plVar3 = (long *)(**(code **)(*plVar2 + 0xe8))(plVar2,0);
      if (plVar3 == (long *)0x0) {
        thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n")
        ;
        uVar1 = 0xe00002bc;
        goto LAB_fffffff00926e960;
      }
      uVar1 = (**(code **)(*plVar3 + 0x78))();
      uVar1 = (**(code **)(*param_1 + 0x5b0))(param_1,uVar1,&uStack_48);
      *(int *)(param_3 + 0x70) = (int)uStack_48;
      if ((int)uVar1 == 0) goto joined_r0xfffffff00926eaac;
    }
LAB_fffffff00926ea78:
    thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
  }
  else {
    uStack_48 = (ulong)*(uint *)(param_3 + 0x60);
    uVar1 = (**(code **)(*param_1 + 0x5b0))(param_1,*(undefined8 *)(param_3 + 0x58),&uStack_48);
    plVar3 = (long *)0x0;
    plVar2 = (long *)0x0;
    *(int *)(param_3 + 0x60) = (int)uStack_48;
    if ((int)uVar1 != 0) goto LAB_fffffff00926ea78;
  }
joined_r0xfffffff00926eaac:
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0xa8))(plVar3);
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
LAB_fffffff00926e960:
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0xe0))(plVar2,0);
  }
  return uVar1;
}

