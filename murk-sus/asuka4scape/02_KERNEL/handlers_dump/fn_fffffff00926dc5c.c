// FUN_fffffff00926dc5c @ fffffff00926dc5c size=4 depth=0
// CALLERS:
//   fffffff00afdd1b9 ?
//   fffffff007efe2f8 ?
// CALLS:

undefined8 FUN_fffffff00926dc5c(long *param_1,long param_2,long param_3)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  
  if (*(int *)(param_3 + 0x38) == 0x40) {
    puVar5 = *(undefined8 **)(param_3 + 0x30);
    plVar1 = thunk_FUN_fffffff00a97ae84(*puVar5,puVar5[1],2,param_2);
    if (plVar1 == (long *)0x0) {
      uVar4 = 0xe00002bc;
      thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
    }
    else {
      plVar2 = thunk_FUN_fffffff00a97ae84(puVar5[2],puVar5[3],2,param_2);
      if (plVar2 == (long *)0x0) {
        uVar4 = 0xe00002bc;
        thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n")
        ;
        plVar3 = (long *)0x0;
      }
      else {
        plVar3 = thunk_FUN_fffffff00a97ae84(puVar5[4],puVar5[5],2,param_2);
        if (plVar3 == (long *)0x0) {
          uVar4 = 0xe00002bc;
          thunk_FUN_fffffff00a9029a0
                    ((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
        }
        else {
          uVar4 = (**(code **)(*param_1 + 0x550))(param_1,plVar1,plVar2,plVar3);
        }
      }
      (**(code **)(*plVar1 + 0x28))(plVar1);
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar2 + 0x28))(plVar2);
      }
      if (plVar3 != (long *)0x0) {
        (**(code **)(*plVar3 + 0x28))(plVar3);
      }
    }
  }
  else {
    thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
    uVar4 = 0xe00002c2;
  }
  return uVar4;
}

