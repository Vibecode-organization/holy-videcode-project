// FUN_fffffff00994b250 @ fffffff00994b250 size=304

void FUN_fffffff00994b250
               (long *param_1,undefined8 param_2,uint *param_3,undefined8 param_4,int param_5)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  long lVar4;
  ulong unaff_x30;
  
  (**(code **)(*param_1 + 0x98))(param_1,param_4);
  uVar1 = *param_3;
  uVar3 = uVar1 | 0x8000;
  uVar1 = (uVar1 & 0xaaaaaaaa | 0x8000) >> 1 | (uVar1 & 0x55555555) << 1;
  uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
  uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
  uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
  lVar4 = LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10);
  if ((int)lVar4 != 0xf) {
    do {
      uVar1 = param_3[lVar4 + 1];
      if (((uVar1 & 0xff) != 0xff && (char)uVar1 != param_5) &&
         (0 < (int)((uVar1 & 0xffffff00) - **(int **)(param_1[4] + (long)(int)(char)uVar1 * 8)))) {
        (**(code **)(*param_1 + 0xa8))(param_1,param_4);
      }
      uVar3 = 1 << (ulong)((uint)lVar4 & 0x1f) ^ uVar3;
      uVar1 = (uVar3 & 0xaaaaaaaa) >> 1 | (uVar3 & 0x55555555) << 1;
      uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
      uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
      uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
      lVar4 = LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10);
    } while ((uint)lVar4 < 0xf);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994b374);
    (*pcVar2)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00994b37c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xa0))(param_1,param_4,(undefined8 *)(*param_1 + 0xa0));
  return;
}

