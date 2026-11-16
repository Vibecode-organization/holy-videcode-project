// FUN_fffffff0081c2f74 @ fffffff0081c2f74 size=4

void FUN_fffffff0081c2f74(long param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  undefined8 *puVar4;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_58 = 0;
  uStack_48 = 0;
  uStack_50 = 0;
  uStack_30 = 0;
  uStack_38 = 0;
  uStack_40 = 0;
  uStack_68 = 0x1a;
  uStack_60 = 3;
  uStack_24 = 2;
  uStack_64 = param_2;
  uVar2 = (**(code **)(*(long *)(param_1 + 0x848) + 0x30))(param_1 + 0x848);
  uStack_28 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
  puVar4 = (undefined8 *)(*plVar3 + 0xe8);
  iVar1 = (*(code *)*puVar4)(puVar4,plVar3,FUN_fffffff00817ea94,&uStack_68,&uStack_24,&uStack_28,0);
  if ((iVar1 == 0) && (((byte)uStack_24 >> 1 & 1) != 0)) {
    FUN_fffffff0081a43cc(param_1,uVar2,uStack_28);
  }
  return;
}

