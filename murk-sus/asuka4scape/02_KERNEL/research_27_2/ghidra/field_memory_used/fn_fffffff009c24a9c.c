// FUN_fffffff009c24a9c @ fffffff009c24a9c

undefined8 FUN_fffffff009c24a9c(long param_1,long *param_2,undefined8 param_3)

{
  ulong uVar1;
  long *plVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20);
  uVar1 = (**(code **)(*param_2 + 0xb8))(param_2,"CreationProperties");
  if ((uVar1 & 1) == 0) {
    plVar2 = *(long **)(lVar3 + 0x1a8);
    (**(code **)(*plVar2 + 0xf0))(plVar2,param_2,param_3);
  }
  return 0;
}

