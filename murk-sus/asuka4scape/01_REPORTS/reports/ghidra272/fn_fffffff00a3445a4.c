// FUN_fffffff00a3445a4 @ fffffff00a3445a4 size=316

ulong FUN_fffffff00a3445a4
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,undefined *****param_7
                ,ulong *param_8,undefined *****param_9,undefined *****param_10,uint param_11,
                byte *param_12,ulong param_13,uint param_14,uint *param_15,uint *param_16,
                uint param_17)

{
  ulong uVar1;
  undefined *****pppppuVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = 4;
  if ((param_7 != (undefined *****)0x0) && ((param_11 & 0xffefbe96) == 0)) {
    uVar4 = *param_16;
    if ((*param_15 < 8 && uVar4 < 8) && ((*param_15 & (uVar4 ^ 0xffffffff)) == 0)) {
      if (((uVar4 ^ 0xffffffff) & 6) == 0) {
        uVar1 = 2;
      }
      else {
        if ((param_14 == 0) && (1 < uVar4)) {
          iVar3 = 0;
          uVar4 = 0;
        }
        else {
          iVar3 = 1;
          uVar4 = 8;
        }
        pppppuVar2 = (undefined *****)
                     FUN_fffffff00a21d78c
                               (param_1,param_2,param_3,param_4,param_5,param_6,param_12,iVar3,uVar4
                               );
        uVar1 = FUN_fffffff00a2e902c
                          (param_7,param_8,param_9,param_10,
                           (ulong *****)(ulong)(param_11 & 0x4169 ^ 0x100001),pppppuVar2,param_13,
                           param_14,param_15,param_16,param_17);
        FUN_fffffff00a2e6e78((ulong *)pppppuVar2);
        if ((int)uVar1 == 0) {
          FUN_fffffff00a1f4ae8(param_12);
          uVar1 = 0;
        }
      }
    }
  }
  return uVar1;
}

