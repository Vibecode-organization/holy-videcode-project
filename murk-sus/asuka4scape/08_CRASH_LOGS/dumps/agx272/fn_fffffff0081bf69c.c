// FUN_fffffff0081bf69c @ fffffff0081bf69c size=24

undefined8 FUN_fffffff0081bf69c(long param_1,undefined2 param_2,undefined2 param_3)

{
  undefined8 uVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined8 uStack_70;
  long lStack_68;
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
    uStack_70 = 0x1000000000031;
    lStack_68 = (ulong)CONCAT22(param_3,param_2) << 8;
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

