// FUN_fffffff0081bf59c @ fffffff0081bf59c size=244

undefined8 FUN_fffffff0081bf59c(long param_1,undefined1 param_2,byte param_3)

{
  undefined8 uVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined7 local_70;
  undefined1 uStack_69;
  ulong uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined4 local_28;
  undefined4 local_24;
  
  uStack_48 = 0;
  local_50 = 0;
  uStack_38 = 0;
  uStack_40 = 0;
  uStack_58 = 0;
  uStack_60 = 0;
  _local_70 = CONCAT17(param_2,0x1000000000031);
  uStack_68 = (ulong)param_3;
  local_24 = 2;
  uVar1 = (**(code **)(*(long *)(param_1 + 0x848) + 0x30))(param_1 + 0x848);
  local_28 = 0;
  plVar2 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
  puVar4 = (undefined8 *)(*plVar2 + 0xe8);
  uVar3 = (*(code *)*puVar4)(puVar4,plVar2,FUN_fffffff00817ea94,&local_70,&local_24,&local_28,0);
  if ((int)uVar3 == 0) {
    if (((byte)local_24 >> 1 & 1) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_fffffff0081a43cc(param_1,uVar1,local_28);
    }
  }
  return uVar3;
}

