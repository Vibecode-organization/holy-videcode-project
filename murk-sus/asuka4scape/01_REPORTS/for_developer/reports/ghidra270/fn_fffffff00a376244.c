// FUN_fffffff00a376244 @ fffffff00a376244 size=520

undefined8 FUN_fffffff00a376244(long *param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long extraout_x1;
  undefined8 extraout_x1_00;
  undefined **ppuVar2;
  undefined8 uVar3;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined8 local_90;
  undefined *local_88;
  undefined8 local_80;
  code *local_78;
  undefined *local_70;
  undefined8 uStack_68;
  
  uVar3 = 0xfae94005;
  *param_1 = 0;
  iVar1 = FUN_fffffff00a2a03fc(DAT_fffffff007c5b790,0x100,0,0x80,0x1c,0);
  if (iVar1 == 0) {
    if (param_3 == 0) {
      ppuVar2 = (undefined **)0x0;
    }
    else {
      local_88 = &DAT_fffffff00ad58ce0;
      local_80 = DAT_fffffff00700d9a0;
      local_78 = FUN_fffffff00a2a10dc;
      local_70 = &DAT_fffffff007bbe1d0;
      uStack_68 = 0;
      ppuVar2 = &local_88;
    }
    iVar1 = FUN_fffffff00a2a03fc(DAT_fffffff007c5b790,0x8000,0,0x8080,0x1c,ppuVar2);
    if (iVar1 == 0) {
      local_90 = 0;
      local_98 = 1;
      uStack_94 = 1;
      iVar1 = FUN_fffffff00a2ac7fc
                        (param_2,&local_90,0x8000,0,0x1c100008,DAT_fffffff007c5b790,extraout_x1_00,0
                         ,&uStack_94,&local_98,2);
      if (iVar1 == 0) {
        local_98 = 3;
        uStack_94 = 3;
        iVar1 = FUN_fffffff00a2ac7fc
                          (param_2,&local_90,0x4000,0,0x1c104001,DAT_fffffff007c5b790,extraout_x1_00
                           ,0,&uStack_94,&local_98,2);
        if (iVar1 == 0) {
          *param_1 = extraout_x1;
          *(undefined8 *)(extraout_x1 + 8) = extraout_x1_00;
          *(undefined8 *)(*param_1 + 0x10) = local_90;
          return 0;
        }
        FUN_fffffff00a2a187c(param_2,local_90,0x8000);
        uVar3 = 0xfae94001;
      }
      FUN_fffffff00a2a279c(DAT_fffffff007c5b790,extraout_x1_00,0x8000,0,0);
    }
    FUN_fffffff00a2a279c(DAT_fffffff007c5b790,extraout_x1,0x100,0,0);
  }
  return uVar3;
}

