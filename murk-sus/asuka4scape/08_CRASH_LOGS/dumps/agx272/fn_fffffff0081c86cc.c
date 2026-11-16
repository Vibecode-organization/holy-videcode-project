// FUN_fffffff0081c86cc @ fffffff0081c86cc size=4

undefined8 FUN_fffffff0081c86cc(long param_1,uint *param_2,uint param_3)

{
  undefined8 uVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  uint uVar5;
  undefined8 *puVar6;
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
  
  lVar4 = *(long *)(param_1 + 0x910);
  *(undefined4 *)(lVar4 + 0x6c44) = 0;
  uVar5 = param_3;
  if (3 < param_3) {
    uVar5 = 4;
  }
  if (param_3 != 0) {
    if (0x16 < *param_2) {
      return 0xe00002c2;
    }
    *(uint *)(lVar4 + 0x6c34) = *param_2;
    if (param_3 != 1) {
      if (0x16 < param_2[1]) {
        return 0xe00002c2;
      }
      *(uint *)(lVar4 + 0x6c38) = param_2[1];
      if (param_3 != 2) {
        if (0x16 < param_2[2]) {
          return 0xe00002c2;
        }
        *(uint *)(lVar4 + 0x6c3c) = param_2[2];
        if (param_3 != 3) {
          if (0x16 < param_2[3]) {
            return 0xe00002c2;
          }
          *(uint *)(lVar4 + 0x6c40) = param_2[3];
        }
      }
    }
  }
  *(uint *)(lVar4 + 0x6c44) = uVar5;
  uStack_48 = 0;
  uStack_50 = 0;
  uStack_38 = 0;
  uStack_40 = 0;
  uStack_68 = 0;
  uStack_58 = 0;
  uStack_60 = 0;
  uStack_70 = 0x38;
  uStack_24 = 2;
  uVar1 = (**(code **)(*(long *)(param_1 + 0x848) + 0x30))(param_1 + 0x848);
  uStack_28 = 0;
  plVar2 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
  puVar6 = (undefined8 *)(*plVar2 + 0xe8);
  uVar3 = (*(code *)*puVar6)(puVar6,plVar2,FUN_fffffff00817ea94,&uStack_70,&uStack_24,&uStack_28,0);
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

