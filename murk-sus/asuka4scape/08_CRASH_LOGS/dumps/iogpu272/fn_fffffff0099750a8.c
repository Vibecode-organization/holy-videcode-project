// FUN_fffffff0099750a8 @ fffffff0099750a8 size=116

void FUN_fffffff0099750a8(long param_1,long *param_2)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  
  param_2[2] = 0;
  plVar2 = *(long **)(param_1 + 0x1a0);
  param_2[3] = (long)plVar2;
  *plVar2 = (long)param_2;
  *(long **)(param_1 + 0x1a0) = param_2 + 2;
  iVar1 = (**(code **)(*param_2 + 0x98))(param_2);
  uVar3 = *(undefined8 *)(param_1 + 0x1ac);
  *(undefined8 *)(param_1 + 0x1ac) = CONCAT44((int)((ulong)uVar3 >> 0x20) + iVar1,(int)uVar3 + 1);
  return;
}

