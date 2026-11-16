// FUN_fffffff0081c2694 @ fffffff0081c2694 size=4

void FUN_fffffff0081c2694
               (long param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
               undefined1 param_5,ushort param_6)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  undefined8 *puVar4;
  undefined4 uStack_68;
  undefined1 uStack_64;
  undefined1 uStack_63;
  undefined1 uStack_62;
  undefined1 uStack_61;
  ulong uStack_60;
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
  uStack_68 = 0x25;
  uStack_60 = (ulong)param_6;
  uStack_24 = 2;
  uStack_64 = param_2;
  uStack_63 = param_3;
  uStack_62 = param_4;
  uStack_61 = param_5;
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

