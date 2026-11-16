// FUN_fffffff00a37bbe0 @ fffffff00a37bbe0 size=268

undefined4 FUN_fffffff00a37bbe0(undefined8 param_1,long *param_2,undefined8 param_3,long param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_38;
  undefined4 uStack_34;
  
  local_38 = 3;
  uStack_34 = 3;
  iVar2 = FUN_fffffff00a2ac7fc
                    (DAT_fffffff007c5b790,param_2,param_4,0,0x1c100008,param_1,param_3,0,&uStack_34,
                     &local_38,2);
  if (iVar2 == 0) {
    iVar2 = FUN_fffffff00a2ad4ec
                      (DAT_fffffff007c5b790,*param_2,*param_2 + param_4,3,0x1c,0,0,
                       &DAT_fffffff007bbf8a8);
    uVar3 = 0;
    if (iVar2 != 0) {
      uVar1 = 0xfae94003;
      if (iVar2 != 1) {
        uVar1 = 0xfae94001;
      }
      uVar3 = 0xfae94005;
      if (iVar2 != 3) {
        uVar3 = uVar1;
      }
      FUN_fffffff00a2a187c(DAT_fffffff007c5b790,*param_2,param_4);
    }
  }
  else {
    uVar1 = 0xfae94003;
    if (iVar2 != 1) {
      uVar1 = 0xfae94001;
    }
    uVar3 = 0xfae94005;
    if (iVar2 != 3) {
      uVar3 = uVar1;
    }
  }
  return uVar3;
}

