// FUN_fffffff008190070 @ fffffff008190070 size=316

void FUN_fffffff008190070(long param_1)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  long *plVar4;
  undefined8 *puVar5;
  long lVar6;
  undefined4 local_68;
  undefined8 local_64;
  uint local_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  undefined4 local_24;
  
  uVar2 = thunk_EXT_FUN_80110000029474ec
                    (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x498);
  if (((uVar2 & 1) == 0) && (iVar1 = thunk_EXT_FUN_801100000294991c(param_1), iVar1 != 0)) {
    *(undefined1 *)(*(long *)(param_1 + 0x480) + 0x2a1) = 1;
    local_5c = thunk_EXT_FUN_8011000002940798
                         (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x1acb0),param_1);
    *(ulong *)(param_1 + 0x940) = (ulong)local_5c;
    uStack_30 = 0;
    local_38 = 0;
    uStack_50 = 0;
    uStack_54 = 0;
    uStack_40 = 0;
    local_48 = 0;
    local_68 = 0x29;
    local_64 = *(undefined8 *)(*(long *)(param_1 + 0x610) + 0xe0);
    uStack_58 = 0;
    lVar6 = *(long *)(*(long *)(param_1 + 0x530) + 0x4b0);
    local_24 = 1;
    uVar3 = (**(code **)(*(long *)(lVar6 + 0x848) + 0x30))(lVar6 + 0x848);
    local_28 = 0;
    plVar4 = *(long **)(*(long *)(lVar6 + 0x280) + 0x310);
    puVar5 = (undefined8 *)(*plVar4 + 0xe8);
    iVar1 = (*(code *)*puVar5)(puVar5,plVar4,FUN_fffffff00817ea94,&local_68,&local_24,&local_28,0);
    if ((iVar1 == 0) && (((byte)local_24 >> 1 & 1) != 0)) {
      FUN_fffffff0081a43cc(lVar6,uVar3,local_28);
    }
  }
  return;
}

