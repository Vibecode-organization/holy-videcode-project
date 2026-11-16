// FUN_fffffff00a1ff970 @ fffffff00a1ff970 size=140

ulong FUN_fffffff00a1ff970(uint *param_1)

{
  long lVar1;
  ulong uVar2;
  undefined *****pppppuVar3;
  
  lVar1 = FUN_fffffff00a21dd40(*param_1,0);
  if (lVar1 == 0) {
    uVar2 = 0x10000003;
  }
  else {
    pppppuVar3 = *(undefined ******)(lVar1 + 0x28);
    if ((pppppuVar3 == (undefined *****)0x0) || (pppppuVar3 == (undefined *****)0x0)) {
      uVar2 = 4;
    }
    else {
      if (*(long *)(param_1 + 4) != 0) {
        uVar2 = FUN_fffffff00a2e898c
                          (pppppuVar3,*(ulong *)(param_1 + 2),
                           *(long *)(param_1 + 4) + *(ulong *)(param_1 + 2),param_1[6],param_1[8]);
        return uVar2;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}

