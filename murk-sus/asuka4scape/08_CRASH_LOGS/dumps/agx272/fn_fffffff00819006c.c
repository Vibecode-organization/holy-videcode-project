// FUN_fffffff00819006c @ fffffff00819006c size=4

void FUN_fffffff00819006c(long param_1)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  long *plVar4;
  undefined8 *puVar5;
  long lVar6;
  undefined4 uStack_68;
  undefined8 uStack_64;
  uint uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uVar2 = thunk_EXT_FUN_80110000029474ec
                    (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x498);
  if (((uVar2 & 1) == 0) && (iVar1 = thunk_EXT_FUN_801100000294991c(param_1), iVar1 != 0)) {
    *(undefined1 *)(*(long *)(param_1 + 0x480) + 0x2a1) = 1;
    uStack_5c = thunk_EXT_FUN_8011000002940798
                          (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x1acb0),param_1);
    *(ulong *)(param_1 + 0x940) = (ulong)uStack_5c;
    uStack_30 = 0;
    uStack_38 = 0;
    uStack_50 = 0;
    uStack_54 = 0;
    uStack_40 = 0;
    uStack_48 = 0;
    uStack_68 = 0x29;
    uStack_64 = *(undefined8 *)(*(long *)(param_1 + 0x610) + 0xe0);
    uStack_58 = 0;
    lVar6 = *(long *)(*(long *)(param_1 + 0x530) + 0x4b0);
    uStack_24 = 1;
    uVar3 = (**(code **)(*(long *)(lVar6 + 0x848) + 0x30))(lVar6 + 0x848);
    uStack_28 = 0;
    plVar4 = *(long **)(*(long *)(lVar6 + 0x280) + 0x310);
    puVar5 = (undefined8 *)(*plVar4 + 0xe8);
    iVar1 = (*(code *)*puVar5)(puVar5,plVar4,FUN_fffffff00817ea94,&uStack_68,&uStack_24,&uStack_28,0
                              );
    if ((iVar1 == 0) && (((byte)uStack_24 >> 1 & 1) != 0)) {
      FUN_fffffff0081a43cc(lVar6,uVar3,uStack_28);
    }
  }
  return;
}

