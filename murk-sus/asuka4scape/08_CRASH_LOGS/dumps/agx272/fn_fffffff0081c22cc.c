// FUN_fffffff0081c22cc @ fffffff0081c22cc size=24

undefined8
FUN_fffffff0081c22cc(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  lVar4 = *(long *)(param_1 + 0x348);
  if (lVar4 != 0) {
    *(undefined4 *)(lVar4 + 0xe1c) = param_2;
    *(undefined4 *)(lVar4 + 0xe20) = param_3;
    *(undefined4 *)(lVar4 + 0xe24) = param_4;
    uStack_48 = 0;
    uStack_50 = 0;
    uStack_38 = 0;
    uStack_40 = 0;
    uStack_68 = 0;
    uStack_58 = 0;
    uStack_60 = 0;
    uStack_70 = 0x30;
    uStack_24 = 2;
    uVar2 = (**(code **)(*(long *)(param_1 + 0x848) + 0x30))(param_1 + 0x848);
    uStack_28 = 0;
    plVar3 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
    puVar5 = (undefined8 *)(*plVar3 + 0xe8);
    iVar1 = (*(code *)*puVar5)(puVar5,plVar3,FUN_fffffff00817ea94,&uStack_70,&uStack_24,&uStack_28,0
                              );
    if ((iVar1 == 0) && (((byte)uStack_24 >> 1 & 1) != 0)) {
      FUN_fffffff0081a43cc(param_1,uVar2,uStack_28);
    }
    return 0;
  }
  return 0xe00002d8;
}

