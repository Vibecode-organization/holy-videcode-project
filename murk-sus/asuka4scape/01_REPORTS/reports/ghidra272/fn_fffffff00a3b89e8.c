// FUN_fffffff00a3b89e8 @ fffffff00a3b89e8 size=268

undefined4
FUN_fffffff00a3b89e8(undefined *****param_1,ulong *param_2,ulong param_3,undefined *****param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  ulong uVar4;
  undefined1 *puVar5;
  uint local_38 [2];
  
  local_38[0] = 3;
  local_38[1] = 3;
  uVar4 = FUN_fffffff00a2e902c
                    (DAT_fffffff007c678d8,param_2,param_4,(undefined *****)0x0,
                     (ulong *****)0x1c100008,param_1,param_3,0,local_38 + 1,local_38,2);
  iVar2 = (int)uVar4;
  if (iVar2 == 0) {
    puVar5 = FUN_fffffff00a2e9df4
                       ((long)DAT_fffffff007c678d8,*param_2,*param_2 + (long)param_4,3,(uint *)0x1c,
                        0,(uint *)0x0,-0xff8434758);
    iVar2 = (int)puVar5;
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
      FUN_fffffff00a2de0a4((long)DAT_fffffff007c678d8,*param_2,(ulong)param_4);
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

