// FUN_fffffff009952ac8 @ fffffff009952ac8 size=296

void FUN_fffffff009952ac8(long *param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long *plVar3;
  uint uVar4;
  ulong unaff_x30;
  
  uVar4 = *(uint *)(param_1 + 2);
  *(uint *)(param_1 + 2) = uVar4 & 0xfffffdff;
  if ((uVar4 & 0xf) == 0) {
    lVar2 = param_1[5];
    if (lVar2 != 0) {
      FUN_fffffff009942d70(lVar2);
      if ((long *)param_1[0x12] != (long *)0x0) {
        (**(code **)(*(long *)param_1[0x12] + 0x28))();
      }
      param_1[0x12] = 0;
      FUN_fffffff009942d7c(lVar2);
    }
  }
  else if ((uVar4 & 0xff) == 0x82) {
    FUN_fffffff009952bf0(param_1[6],param_1);
  }
  if ((param_2 != 0) && (uVar4 = *(uint *)(param_1 + 2), plVar3 = param_1, (uVar4 & 0x600000) == 0))
  {
    while ((uVar4 & 0xff) == 0x82) {
      uVar4 = *(uint *)((long *)plVar3[6] + 2);
      plVar3 = (long *)plVar3[6];
    }
    if (((uVar4 & 0xff) == 0x40) || ((uVar4 & 0xf) != 0)) {
      lVar2 = 0;
    }
    else {
      lVar2 = plVar3[0xf];
    }
    FUN_fffffff00996648c(param_2,lVar2);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009952be4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x28))(param_1,(undefined8 *)(*param_1 + 0x28));
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009952bdc);
  (*pcVar1)();
}

