// FUN_fffffff0081c2f78 @ fffffff0081c2f78 size=228

void FUN_fffffff0081c2f78(long param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  undefined8 *puVar4;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  uStack_58 = 0;
  uStack_48 = 0;
  uStack_50 = 0;
  local_30 = 0;
  uStack_38 = 0;
  local_40 = 0;
  local_68 = 0x1a;
  local_60 = 3;
  local_24 = 2;
  uStack_64 = param_2;
  uVar2 = (**(code **)(*(long *)(param_1 + 0x848) + 0x30))(param_1 + 0x848);
  local_28 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
  puVar4 = (undefined8 *)(*plVar3 + 0xe8);
  iVar1 = (*(code *)*puVar4)(puVar4,plVar3,FUN_fffffff00817ea94,&local_68,&local_24,&local_28,0);
  if ((iVar1 == 0) && (((byte)local_24 >> 1 & 1) != 0)) {
    FUN_fffffff0081a43cc(param_1,uVar2,local_28);
  }
  return;
}

