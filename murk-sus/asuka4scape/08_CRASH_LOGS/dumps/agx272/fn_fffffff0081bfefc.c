// FUN_fffffff0081bfefc @ fffffff0081bfefc size=232

undefined8
FUN_fffffff0081bfefc(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  undefined4 local_24;
  
  uStack_30 = 0;
  local_38 = 0;
  uStack_40 = 0;
  local_48 = 0;
  uStack_50 = 0;
  local_58 = 0;
  local_68 = 0x18;
  local_24 = 2;
  uStack_64 = param_2;
  local_60 = param_3;
  uStack_5c = param_4;
  uVar1 = (**(code **)(*(long *)(param_1 + 0x848) + 0x30))(param_1 + 0x848);
  local_28 = 0;
  plVar2 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
  puVar4 = (undefined8 *)(*plVar2 + 0xe8);
  uVar3 = (*(code *)*puVar4)(puVar4,plVar2,FUN_fffffff00817ea94,&local_68,&local_24,&local_28,0);
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

