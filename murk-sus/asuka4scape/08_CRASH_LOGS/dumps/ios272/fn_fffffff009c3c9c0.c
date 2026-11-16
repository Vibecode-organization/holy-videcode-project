// FUN_fffffff009c3c9c0 @ fffffff009c3c9c0 size=232

undefined8
FUN_fffffff009c3c9c0(undefined8 param_1,undefined4 *param_2,ulong param_3,undefined8 param_4)

{
  long *plVar1;
  long *plVar2;
  undefined8 uVar3;
  char *pcVar4;
  
  uVar3 = 0xe00002c2;
  plVar1 = (long *)FUN_fffffff009c3f1d0(param_1,*param_2);
  if (plVar1 == (long *)0x0) {
    return 0xe00002c2;
  }
  pcVar4 = (char *)(param_2 + 3);
  if (*pcVar4 == '\0') {
    FUN_fffffff009c284c8(plVar1,0,param_4);
  }
  else {
    if ((pcVar4[(param_3 & 0xffffffff) - 0xd] != '\0') ||
       (plVar2 = (long *)thunk_EXT_FUN_80110000038ce200(pcVar4), plVar2 == (long *)0x0))
    goto LAB_fffffff009c3ca70;
    FUN_fffffff009c284c8(plVar1,plVar2,param_4);
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  uVar3 = 0;
LAB_fffffff009c3ca70:
  (**(code **)(*plVar1 + 0x28))(plVar1);
  return uVar3;
}

