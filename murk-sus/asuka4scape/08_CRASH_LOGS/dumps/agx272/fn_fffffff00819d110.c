// FUN_fffffff00819d110 @ fffffff00819d110 size=4

undefined8 FUN_fffffff00819d110(long param_1,uint *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined4 uStack_68;
  undefined4 uStack_64;
  ulong uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  lVar3 = thunk_EXT_FUN_80110000029636a8(*(undefined8 *)(param_1 + 0x120));
  if (*param_2 < 3) {
    if (*(uint *)(lVar3 + 0x1e8) != 0xffffffff) {
      lVar6 = (ulong)*param_2 * 4;
      puVar1 = (undefined4 *)(&DAT_fffffff00711401c + (int)lVar6);
      if (lVar6 - (int)lVar6 != 0) {
        puVar1 = (undefined4 *)
                 ((ulong)(&DAT_fffffff00711401c + lVar6) & 0xffffffffffff | 0x2bad000000000000);
      }
      uStack_64 = *puVar1;
      uStack_58 = 0;
      uStack_48 = 0;
      uStack_50 = 0;
      uStack_30 = 0;
      uStack_38 = 0;
      uStack_40 = 0;
      uStack_60 = (ulong)*(uint *)(lVar3 + 0x1e8);
      uStack_68 = 0x33;
      lVar3 = *(long *)(*(long *)(param_1 + 0xf8) + 0x4b0);
      uStack_24 = 2;
      uVar4 = (**(code **)(*(long *)(lVar3 + 0x848) + 0x30))(lVar3 + 0x848);
      uStack_28 = 0;
      plVar5 = *(long **)(*(long *)(lVar3 + 0x280) + 0x310);
      puVar7 = (undefined8 *)(*plVar5 + 0xe8);
      iVar2 = (*(code *)*puVar7)(puVar7,plVar5,FUN_fffffff00817ea94,&uStack_68,&uStack_24,&uStack_28
                                 ,0);
      if ((iVar2 == 0) && (((byte)uStack_24 >> 1 & 1) != 0)) {
        FUN_fffffff0081a43cc(lVar3,uVar4,uStack_28);
      }
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 0xe00002bc;
  }
  return uVar4;
}

