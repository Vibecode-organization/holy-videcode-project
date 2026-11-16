// FUN_fffffff009c39cf4 @ fffffff009c39cf4 size=280
// CALLERS:
//   fffffff00afec08b no-fn
//   fffffff008069310 no-fn
// CALLEES:
//   fffffff009c3e86c FUN_fffffff009c3e86c

int FUN_fffffff009c39cf4
              (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4
              ,undefined4 param_5,undefined4 param_6,long param_7,undefined8 param_8,long param_9)

{
  int iVar1;
  long *plVar2;
  char *pcVar3;
  ulong uVar4;
  undefined1 extraout_q0 [16];
  
  iVar1 = -0x1ffffd3e;
  plVar2 = *(long **)(param_9 + 0x40);
  if (plVar2 == (long *)0x0) {
    plVar2 = (long *)0x0;
    pcVar3 = *(char **)(param_9 + 0x30);
    uVar4 = (ulong)*(uint *)(param_9 + 0x38);
  }
  else {
    plVar2 = (long *)(**(code **)(*plVar2 + 0xe8))(plVar2,0x1000);
    if (plVar2 == (long *)0x0) {
      return -0x1ffffd38;
    }
    pcVar3 = (char *)(**(code **)(*plVar2 + 0x78))();
    uVar4 = (**(code **)(**(long **)(param_9 + 0x40) + 0xb0))();
    param_1 = extraout_q0;
  }
  if (pcVar3 != (char *)0x0 && (int)uVar4 != 0) {
    iVar1 = FUN_fffffff009c3e86c
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,
                       **(uint **)(param_9 + 0x20),pcVar3,uVar4);
  }
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return iVar1;
}

