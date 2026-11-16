// FUN_fffffff00a2e4f80 @ fffffff00a2e4f80 size=140

void FUN_fffffff00a2e4f80
               (undefined8 param_1,undefined8 *param_2,uint param_3,undefined8 param_4,
               undefined8 param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  iVar3 = FUN_fffffff00a2dffb4(param_1,uVar1,uVar2,param_3 | 0x10000000,0,param_4,param_2);
  if (iVar3 == 0) {
    FUN_fffffff00a2fa8c0(param_1,uVar1,uVar2,param_5,1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4d114("failed to delete entries for overwrite @%s:%d");
}

