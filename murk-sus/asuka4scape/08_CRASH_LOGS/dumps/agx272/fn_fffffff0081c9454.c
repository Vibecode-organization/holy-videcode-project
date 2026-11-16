// FUN_fffffff0081c9454 @ fffffff0081c9454 size=216

void FUN_fffffff0081c9454(long param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  undefined8 *puVar4;
  ulong local_70 [9];
  undefined4 local_28;
  undefined4 local_24;
  
  local_70[5] = 0;
  local_70[4] = 0;
  local_70[7] = 0;
  local_70[6] = 0;
  local_70[1] = 0;
  local_70[3] = 0;
  local_70[2] = 0;
  local_70[0] = (ulong)param_2;
  local_24 = 1;
  uVar2 = (**(code **)(*(long *)(param_1 + 0x848) + 0x30))(param_1 + 0x848);
  local_28 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
  puVar4 = (undefined8 *)(*plVar3 + 0xe8);
  iVar1 = (*(code *)*puVar4)(puVar4,plVar3,FUN_fffffff00817ea94,local_70,&local_24,&local_28,0);
  if ((iVar1 == 0) && (((byte)local_24 >> 1 & 1) != 0)) {
    FUN_fffffff0081a43cc(param_1,uVar2,local_28);
  }
  return;
}

