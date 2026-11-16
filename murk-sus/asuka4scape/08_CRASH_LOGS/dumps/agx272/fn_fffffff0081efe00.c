// FUN_fffffff0081efe00 @ fffffff0081efe00 size=4

bool FUN_fffffff0081efe00(long param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  long lVar5;
  undefined8 *puVar6;
  long lVar7;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined4 uStack_48;
  undefined4 uStack_44;
  
  if (*(int *)(param_1 + 0x48) == 0) {
    bVar1 = false;
  }
  else {
    lVar7 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
    lVar5 = *(long *)(lVar7 + 0x910);
    uStack_68 = 0;
    uStack_70 = 0;
    uStack_58 = 0;
    uStack_60 = 0;
    uStack_88 = 0;
    uStack_78 = 0;
    uStack_80 = 0;
    uStack_90 = 5;
    uStack_44 = 2;
    uVar3 = (**(code **)(*(long *)(lVar7 + 0x848) + 0x30))(lVar7 + 0x848);
    uStack_48 = 0;
    plVar4 = *(long **)(*(long *)(lVar7 + 0x280) + 0x310);
    puVar6 = (undefined8 *)(*plVar4 + 0xe8);
    iVar2 = (*(code *)*puVar6)(puVar6,plVar4,FUN_fffffff00817ea94,&uStack_90,&uStack_44,&uStack_48,0
                              );
    bVar1 = false;
    if (iVar2 == 0) {
      if (((byte)uStack_44 >> 1 & 1) == 0) {
        bVar1 = true;
      }
      else {
        iVar2 = FUN_fffffff0081a43cc(lVar7,uVar3,uStack_48);
        bVar1 = iVar2 == 0;
      }
    }
    *(bool *)(param_1 + 0x54) = *(int *)(lVar5 + 0x4040) != 0;
    if ((*(byte *)(param_1 + 0x34) & 1) != 0) {
      plVar4 = *(long **)(*(long *)(param_1 + 0x10) + 0x4b0);
      (**(code **)(*plVar4 + 0x6c0))(plVar4,0,0);
      *(undefined1 *)(param_1 + 0x34) = 0;
    }
    thunk_EXT_FUN_801100000295d6e0
              (*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x160),
               *(ulong *)(*(long *)(param_1 + 0x10) + 0x5c8) >> 5 & 1);
    if ((*(byte *)(param_1 + 0x2d) >> 1 & 1) != 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x11190));
      FUN_fffffff00817f498
                (*(undefined8 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x8c),
                 *(undefined4 *)(param_1 + 0x90),*(undefined4 *)(param_1 + 0x94));
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x11190));
    }
    *(undefined4 *)(lVar5 + 0x4048) = 0;
  }
  return bVar1;
}

