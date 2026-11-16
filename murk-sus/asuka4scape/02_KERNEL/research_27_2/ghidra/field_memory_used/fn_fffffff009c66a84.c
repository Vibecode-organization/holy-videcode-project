// FUN_fffffff009c66a84 @ fffffff009c66a84

undefined8
FUN_fffffff009c66a84
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long param_7,ulong param_8,long *param_9,
          undefined8 param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,
          undefined8 param_14)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  ulong uVar5;
  long *plVar6;
  undefined8 uVar7;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  long local_58;
  
  local_58 = *(long *)PTR_DAT_fffffff00807b630;
  uStack_78 = 0;
  local_80 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  uStack_98 = 0;
  local_a0 = 0;
  uStack_88 = 0;
  uStack_90 = 0;
  uStack_a8 = 0;
  local_b0 = 0;
  if (param_9 == (long *)0x0) {
    FUN_fffffff009c7ba54(ZEXT816(0),param_2,param_3,param_4,param_5,param_6);
  }
  else {
    uVar5 = (**(code **)(PTR_DAT_fffffff00807b628 + 0xb8))(param_7,param_14);
    if ((uVar5 & 1) == 0) {
      auVar1._8_8_ = extraout_var;
      auVar1._0_8_ = extraout_d0;
      FUN_fffffff009c7b944(auVar1,param_2,param_3,param_4,param_5,param_6);
    }
    else {
      plVar6 = (long *)(**(code **)(*(long *)PTR_DAT_fffffff008070838 + 0x68))();
      *(long **)(param_7 + 0x88) = plVar6;
      if (plVar6 == (long *)0x0) {
        auVar2._8_8_ = extraout_var_00;
        auVar2._0_8_ = extraout_d0_00;
        FUN_fffffff009c7ba10(auVar2,param_2,param_3,param_4,param_5,param_6);
      }
      else {
        uVar5 = (**(code **)(*plVar6 + 0x548))
                          (plVar6,param_8 & 0xffffffffffff,param_9,param_10,param_11,param_12,0,
                           param_13,0);
        if ((uVar5 & 1) == 0) {
          auVar3._8_8_ = extraout_var_01;
          auVar3._0_8_ = extraout_d0_01;
          FUN_fffffff009c7b988(auVar3,param_2,param_3,param_4,param_5,param_6);
        }
        else {
          (**(code **)(*param_9 + 0xa8))(param_9);
          thunk_FUN_fffffff00a76d3ec((undefined1 *)&local_b0,0x4f,(byte *)"%s%hu");
          plVar6 = thunk_FUN_fffffff00a8d2200(&local_b0);
          *(long **)(param_7 + 0x90) = plVar6;
          if (plVar6 != (long *)0x0) {
            uVar7 = (**(code **)(*plVar6 + 0xa8))();
            *(undefined8 *)(param_7 + 0x98) = uVar7;
            uVar7 = 1;
            goto LAB_fffffff009c66be8;
          }
          auVar4._8_8_ = extraout_var_02;
          auVar4._0_8_ = extraout_d0_02;
          FUN_fffffff009c7b9cc(auVar4,param_2,param_3,param_4,param_5,param_6);
        }
      }
    }
  }
  uVar7 = 0;
LAB_fffffff009c66be8:
  if (*(long *)PTR_DAT_fffffff00807b630 == local_58) {
    return uVar7;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

