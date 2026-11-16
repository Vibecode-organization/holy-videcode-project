// FUN_fffffff009949d00 @ fffffff009949d00 size=4

undefined8 FUN_fffffff009949d00(long param_1,long param_2)

{
  long *plVar1;
  undefined8 uVar2;
  undefined1 uStack_25;
  undefined4 uStack_24;
  
  uStack_24 = 0;
  uStack_25 = 0;
  if ((param_2 == 0) ||
     (plVar1 = (long *)FUN_fffffff009965da8(*(undefined8 *)(param_1 + 0x120)), plVar1 == (long *)0x0
     )) {
    uVar2 = FUN_fffffff0099684a8(*(undefined8 *)(param_1 + 0x120),&uStack_24,&uStack_25,1,3);
  }
  else {
    uVar2 = FUN_fffffff0099684a8
                      (*(undefined8 *)(param_1 + 0x120),&uStack_24,&uStack_25,
                       *(undefined4 *)((long)plVar1 + 0x444),(int)plVar1[0x89]);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

