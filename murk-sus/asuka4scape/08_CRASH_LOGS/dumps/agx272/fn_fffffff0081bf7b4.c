// FUN_fffffff0081bf7b4 @ fffffff0081bf7b4 size=24

undefined8 FUN_fffffff0081bf7b4(long param_1,undefined1 param_2,byte param_3)

{
  undefined8 uVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined7 uStack_70;
  undefined1 uStack_69;
  ulong uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if ((*(byte *)(*(long *)(param_1 + 0x280) + 0x11118) & 1) != 0) {
    uStack_48 = 0;
    uStack_50 = 0;
    uStack_38 = 0;
    uStack_40 = 0;
    uStack_58 = 0;
    uStack_60 = 0;
    _uStack_70 = CONCAT17(param_2,0x31);
    uStack_68 = (ulong)param_3;
    uStack_24 = 2;
    uVar1 = (**(code **)(*(long *)(param_1 + 0x848) + 0x30))(param_1 + 0x848);
    uStack_28 = 0;
    plVar2 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
    puVar4 = (undefined8 *)(*plVar2 + 0xe8);
    uVar3 = (*(code *)*puVar4)(puVar4,plVar2,FUN_fffffff00817ea94,&uStack_70,&uStack_24,&uStack_28,0
                              );
    if ((int)uVar3 == 0) {
      if (((byte)uStack_24 >> 1 & 1) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_fffffff0081a43cc(param_1,uVar1,uStack_28);
      }
    }
    return uVar3;
  }
  return 0xe00002c7;
}

