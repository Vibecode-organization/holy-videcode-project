// FUN_fffffff009252c1c @ fffffff009252c1c size=4 depth=0
// CALLERS:
//   fffffff00afdced6 ?
//   fffffff007eee518 ?
// CALLS:

undefined8 FUN_fffffff009252c1c(long param_1,long param_2,long param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  long lVar7;
  undefined8 in_x3;
  undefined *in_x4;
  long extraout_x16;
  long extraout_x16_00;
  long extraout_x16_01;
  undefined8 *puVar8;
  undefined1 in_q0 [16];
  undefined1 auVar9 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined1 in_register_00005044 [12];
  undefined4 in_s3;
  undefined1 in_register_00005064 [12];
  undefined4 in_s4;
  undefined4 in_s5;
  long *plStack_48;
  
  lVar7 = param_3;
  uVar5 = FUN_fffffff00922ac4c(in_q0,in_q1,in_s2,in_s3,in_s4,in_s5,param_1,"measure");
  if ((int)uVar5 == 0) {
    if (*(int *)(param_3 + 0x60) == 0) {
      uVar5 = 0;
    }
    else {
      plStack_48 = (long *)0x0;
      auVar9 = thunk_FUN_fffffff00a2262a8(*(ulong *)(param_2 + 0xe8));
      auVar1._4_12_ = in_register_00005044;
      auVar1._0_4_ = in_s2;
      auVar2._4_12_ = in_register_00005064;
      auVar2._0_4_ = in_s3;
      uVar5 = FUN_fffffff009219b14
                        (auVar9,in_q1,auVar1,auVar2,in_s4,in_s5,param_1,&plStack_48,lVar7,in_x3,
                         in_x4);
      if ((int)uVar5 == 0) {
        *(undefined1 *)(param_2 + 0x100) = 0;
        FUN_fffffff00922ac3c();
        uVar3 = (**(code **)(extraout_x16 + 0xa0))();
        uVar4 = *(uint *)(param_3 + 0x60);
        if (uVar3 < uVar4) {
          FUN_fffffff00922ac3c();
          uVar4 = (**(code **)(extraout_x16_00 + 0xa0))();
        }
        puVar8 = *(undefined8 **)(param_3 + 0x58);
        FUN_fffffff00922ac3c();
        puVar6 = (undefined8 *)(**(code **)(extraout_x16_01 + 0xd8))();
        thunk_FUN_fffffff00aa65b10(puVar8,puVar6,(ulong)uVar4);
        *(uint *)(param_3 + 0x60) = uVar4;
        (**(code **)(*plStack_48 + 0x70))();
      }
      thunk_FUN_fffffff00a226de0(*(ulong *)(param_2 + 0xe8));
    }
  }
  return uVar5;
}

