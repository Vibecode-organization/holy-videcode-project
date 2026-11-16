// FUN_fffffff009271e7c @ fffffff009271e7c size=4 depth=0
// CALLERS:
//   fffffff00afdd233 ?
//   fffffff007efeee8 ?
// CALLS:

undefined8 FUN_fffffff009271e7c(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  byte bVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  long *plVar5;
  long *plVar6;
  undefined1 in_q0 [16];
  undefined1 extraout_q0 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  ulong uStack_48;
  
  if (*(int *)(param_3 + 0x28) != 1) {
    thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
    return 0xe00002c2;
  }
  bVar2 = **(byte **)(param_3 + 0x20);
  uVar1 = *(uint *)(param_3 + 0x60);
  if (uVar1 == 0) {
    plVar5 = *(long **)(param_3 + 0x68);
    if (plVar5 == (long *)0x0) {
      plVar6 = (long *)0x0;
      uVar3 = 0xe00002c7;
    }
    else {
      uVar1 = *(uint *)(param_3 + 0x70);
      uStack_48 = (ulong)uVar1;
      uVar3 = (**(code **)(*plVar5 + 0xd8))(plVar5,0);
      if ((int)uVar3 != 0) {
        thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n")
        ;
        plVar5 = (long *)0x0;
        goto LAB_fffffff009271f38;
      }
      plVar6 = (long *)(**(code **)(*plVar5 + 0xe8))(plVar5,0);
      if (plVar6 == (long *)0x0) {
        thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n")
        ;
        uVar3 = 0xe00002bc;
        goto LAB_fffffff009271f38;
      }
      puVar4 = (undefined8 *)(**(code **)(*plVar6 + 0x78))();
      uVar3 = FUN_fffffff00926bf60
                        (extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,param_1,(uint)bVar2,0,
                         (ulong)uVar1,puVar4,&uStack_48);
      if ((int)uVar3 == 0) goto joined_r0xfffffff009272068;
    }
LAB_fffffff009272034:
    thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
  }
  else {
    uStack_48 = (ulong)uVar1;
    uVar3 = FUN_fffffff00926bf60
                      (in_q0,in_q1,in_s2,in_s3,in_s4,in_s5,param_1,(uint)bVar2,0,(ulong)uVar1,
                       *(undefined8 **)(param_3 + 0x58),&uStack_48);
    plVar5 = (long *)0x0;
    plVar6 = (long *)0x0;
    *(int *)(param_3 + 0x60) = (int)uStack_48;
    if ((int)uVar3 != 0) goto LAB_fffffff009272034;
  }
joined_r0xfffffff009272068:
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0xa8))(plVar6);
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
LAB_fffffff009271f38:
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0xe0))(plVar5,0);
  }
  return uVar3;
}

