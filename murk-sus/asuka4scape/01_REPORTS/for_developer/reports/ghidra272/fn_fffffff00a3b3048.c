// FUN_fffffff00a3b3048 @ fffffff00a3b3048 size=520

undefined8
FUN_fffffff00a3b3048
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long *param_7,undefined *****param_8,int param_9)

{
  undefined1 auVar1 [16];
  ulong uVar2;
  undefined **ppuVar4;
  undefined8 uVar5;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 uVar6;
  undefined8 extraout_d0_02;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 uVar7;
  undefined8 extraout_var_02;
  undefined1 auVar8 [16];
  uint local_98 [2];
  ulong local_90;
  undefined *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined *local_70;
  undefined8 uStack_68;
  undefined **ppuVar3;
  
  uVar5 = 0xfae94005;
  *param_7 = 0;
  auVar8 = FUN_fffffff00a2dcc04
                     ((long *)DAT_fffffff007c678d8,(ulong *)0x100,(undefined ********)0x0,
                      (undefined ********)&DAT_00000080,(undefined ********)0x1c,0);
  ppuVar3 = auVar8._8_8_;
  if (auVar8._0_4_ == 0) {
    if (param_9 == 0) {
      ppuVar4 = (undefined **)0x0;
    }
    else {
      local_88 = &DAT_fffffff00ad98dc0;
      local_80 = DAT_fffffff00700d9a0;
      local_78 = &LAB_fffffff00a2dd8e4;
      local_70 = &DAT_fffffff007bca1d0;
      uStack_68 = 0;
      ppuVar4 = &local_88;
    }
    auVar8 = FUN_fffffff00a2dcc04
                       ((long *)DAT_fffffff007c678d8,(ulong *)0x8000,(undefined ********)0x0,
                        (undefined ********)0x8080,(undefined ********)0x1c,(long)ppuVar4);
    ppuVar4 = auVar8._8_8_;
    uVar6 = extraout_d0;
    uVar7 = extraout_var;
    if (auVar8._0_4_ == 0) {
      local_90 = 0;
      local_98[0] = 1;
      local_98[1] = 1;
      uVar2 = FUN_fffffff00a2e902c
                        (param_8,&local_90,(undefined *****)0x8000,(undefined *****)0x0,
                         (ulong *****)0x1c100008,DAT_fffffff007c678d8,(ulong)ppuVar4,0,local_98 + 1,
                         local_98,2);
      uVar6 = extraout_d0_00;
      uVar7 = extraout_var_00;
      if ((int)uVar2 == 0) {
        local_98[0] = 3;
        local_98[1] = 3;
        uVar2 = FUN_fffffff00a2e902c
                          (param_8,&local_90,(undefined *****)0x4000,(undefined *****)0x0,
                           (ulong *****)0x1c104001,DAT_fffffff007c678d8,(ulong)ppuVar4,0,
                           local_98 + 1,local_98,2);
        if ((int)uVar2 == 0) {
          *param_7 = (long)ppuVar3;
          ppuVar3[1] = (undefined *)ppuVar4;
          *(ulong *)(*param_7 + 0x10) = local_90;
          return 0;
        }
        FUN_fffffff00a2de0a4((long)param_8,local_90,0x8000);
        uVar5 = 0xfae94001;
        uVar6 = extraout_d0_01;
        uVar7 = extraout_var_01;
      }
      auVar8._8_8_ = uVar7;
      auVar8._0_8_ = uVar6;
      FUN_fffffff00a2defc4
                (auVar8,param_2,param_3,param_4,param_5,param_6,(uint *)DAT_fffffff007c678d8,ppuVar4
                 ,0x8000,0,(undefined **)0x0);
      uVar6 = extraout_d0_02;
      uVar7 = extraout_var_02;
    }
    auVar1._8_8_ = uVar7;
    auVar1._0_8_ = uVar6;
    FUN_fffffff00a2defc4
              (auVar1,param_2,param_3,param_4,param_5,param_6,(uint *)DAT_fffffff007c678d8,ppuVar3,
               0x100,0,(undefined **)0x0);
  }
  return uVar5;
}

