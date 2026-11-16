// FUN_fffffff009949d04 @ fffffff009949d04 size=164

undefined8 FUN_fffffff009949d04(long param_1,long param_2)

{
  long *plVar1;
  undefined8 uVar2;
  undefined1 local_25;
  undefined4 local_24;
  
  local_24 = 0;
  local_25 = 0;
  if ((param_2 == 0) ||
     (plVar1 = (long *)FUN_fffffff009965da8(*(undefined8 *)(param_1 + 0x120)), plVar1 == (long *)0x0
     )) {
    uVar2 = FUN_fffffff0099684a8(*(undefined8 *)(param_1 + 0x120),&local_24,&local_25,1,3);
  }
  else {
    uVar2 = FUN_fffffff0099684a8
                      (*(undefined8 *)(param_1 + 0x120),&local_24,&local_25,
                       *(undefined4 *)((long)plVar1 + 0x444),(int)plVar1[0x89]);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

