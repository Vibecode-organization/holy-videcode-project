// FUN_fffffff0081c22d8 @ fffffff0081c22d8 size=236

undefined8
FUN_fffffff0081c22d8
          (long param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  undefined8 *puVar4;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined4 local_28;
  undefined4 local_24;
  
  *(undefined4 *)(param_1 + 0xe1c) = param_3;
  *(undefined4 *)(param_1 + 0xe20) = param_4;
  *(undefined4 *)(param_1 + 0xe24) = param_5;
  uStack_48 = 0;
  local_50 = 0;
  uStack_38 = 0;
  uStack_40 = 0;
  uStack_68 = 0;
  uStack_58 = 0;
  uStack_60 = 0;
  local_70 = 0x30;
  local_24 = 2;
  uVar2 = (**(code **)(*(long *)(param_2 + 0x848) + 0x30))(param_2 + 0x848);
  local_28 = 0;
  plVar3 = *(long **)(*(long *)(param_2 + 0x280) + 0x310);
  puVar4 = (undefined8 *)(*plVar3 + 0xe8);
  iVar1 = (*(code *)*puVar4)(puVar4,plVar3,FUN_fffffff00817ea94,&local_70,&local_24,&local_28,0);
  if ((iVar1 == 0) && (((byte)local_24 >> 1 & 1) != 0)) {
    FUN_fffffff0081a43cc(param_2,uVar2,local_28);
  }
  return 0;
}

