// FUN_fffffff009c1f1b8 @ fffffff009c1f1b8

void FUN_fffffff009c1f1b8
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  long *plVar3;
  undefined8 *puVar4;
  undefined1 auVar5 [16];
  undefined4 uVar6;
  undefined1 auVar7 [12];
  undefined4 uVar8;
  undefined1 auVar9 [12];
  long local_30;
  long local_28;
  
  uVar8 = param_4._0_4_;
  auVar9 = param_4._4_12_;
  uVar6 = param_3._0_4_;
  auVar7 = param_3._4_12_;
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_30 = 0;
  auVar5 = thunk_FUN_fffffff00a2df760(param_7[6],&local_30);
  thunk_FUN_fffffff00a6de494
            (auVar5,param_2,uVar6,uVar8,param_5,param_6,0x85210024,local_30,
             (ulong)*(uint *)(param_7 + 2),0,0);
  plVar3 = (long *)param_7[6];
  if ((plVar3 != (long *)0x0) && ((*(byte *)((long)param_7 + 0x3d1) >> 2 & 1) != 0)) {
    (**(code **)(*plVar3 + 0xe0))(plVar3,0);
  }
  auVar5 = FUN_fffffff009c1f2d4((long)param_7);
  if (*(uint *)(param_7 + 2) != 0) {
    param_7[0x2f] = 0;
    param_7[0x60] = 0;
    auVar1._4_12_ = auVar7;
    auVar1._0_4_ = uVar6;
    auVar2._4_12_ = auVar9;
    auVar2._0_4_ = uVar8;
    FUN_fffffff009c35dcc
              (auVar5,param_2,auVar1,auVar2,param_5,param_6,DAT_fffffff00af483b0,(long)param_7,
               (ulong)*(uint *)(param_7 + 2));
    *(undefined4 *)(param_7 + 2) = 0;
  }
  puVar4 = (undefined8 *)param_7[0x4c];
  if (puVar4 != (undefined8 *)0x0) {
    param_7[0x4c] = 0;
    thunk_FUN_fffffff00a22170c((long *)&DAT_fffffff00806aef0,puVar4);
    param_7[0x4c] = 0;
  }
  (**(code **)(*param_7 + 0x70))(param_7);
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

