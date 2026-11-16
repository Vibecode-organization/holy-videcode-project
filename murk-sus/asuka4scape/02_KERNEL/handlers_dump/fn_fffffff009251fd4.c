// FUN_fffffff009251fd4 @ fffffff009251fd4 size=4 depth=0
// CALLERS:
//   fffffff00afdcebb ?
//   fffffff007eedd60 ?
// CALLS:

undefined8 FUN_fffffff009251fd4(undefined8 param_1,long *param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  long lVar4;
  long extraout_x16;
  long extraout_x16_00;
  long extraout_x16_01;
  long *plVar5;
  undefined8 unaff_x22;
  undefined1 in_q0 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  undefined1 auVar6 [16];
  
  lVar4 = param_3;
  uVar2 = FUN_fffffff009229a50(param_2,in_q0,in_q1,in_s2,in_s3,in_s4,in_s5);
  if ((int)uVar2 == 0) {
    iVar1 = *(int *)(param_3 + 0x60);
    if (iVar1 == 0) {
      plVar5 = *(long **)(param_3 + 0x68);
      if (plVar5 == (long *)0x0) {
        uVar2 = 0xe00002c7;
      }
      else {
        FUN_fffffff009229adc();
        uVar2 = (**(code **)(extraout_x16 + 0xd8))(plVar5,0);
        if ((int)uVar2 == 0) {
          FUN_fffffff009229ac8();
          plVar3 = (long *)(**(code **)(extraout_x16_00 + 0xe8))(plVar5,0);
          if (plVar3 == (long *)0x0) {
            unaff_x22 = 0xe00002bc;
          }
          else {
            (**(code **)(*plVar3 + 0x78))();
            auVar6 = FUN_fffffff009229abc();
            FUN_fffffff00921c478(auVar6._0_8_,auVar6._8_8_,lVar4);
            FUN_fffffff009229a80();
            (**(code **)(extraout_x16_01 + 0xa8))(plVar3);
            (**(code **)(*plVar3 + 0x28))(plVar3);
          }
          (**(code **)(*plVar5 + 0xe0))(plVar5,0);
          uVar2 = unaff_x22;
        }
      }
    }
    else {
      auVar6 = FUN_fffffff009229abc();
      uVar2 = FUN_fffffff00921c478(auVar6._0_8_,auVar6._8_8_,lVar4);
      *(int *)(param_3 + 0x60) = iVar1;
    }
  }
  return uVar2;
}

