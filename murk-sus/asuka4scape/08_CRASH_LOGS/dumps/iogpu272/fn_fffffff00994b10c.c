// FUN_fffffff00994b10c @ fffffff00994b10c size=108

void FUN_fffffff00994b10c
               (long *param_1,int param_2,undefined8 param_3,uint *param_4,undefined8 param_5)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  
  uVar1 = *param_4 | 0x8000;
  do {
    uVar2 = (uVar1 & 0xaaaaaaaa) >> 1 | (uVar1 & 0x55555555) << 1;
    uVar2 = (uVar2 & 0xcccccccc) >> 2 | (uVar2 & 0x33333333) << 2;
    uVar2 = (uVar2 & 0xf0f0f0f0) >> 4 | (uVar2 & 0xf0f0f0f) << 4;
    uVar2 = (uVar2 & 0xff00ff00) >> 8 | (uVar2 & 0xff00ff) << 8;
    lVar3 = LZCOUNT(uVar2 >> 0x10 | uVar2 << 0x10);
    uVar2 = (uint)lVar3;
    if (0xe < uVar2) {
      return;
    }
    uVar1 = 1 << (ulong)(uVar2 & 0x1f) ^ uVar1;
  } while (param_2 != (char)param_4[lVar3 + 1]);
                    /* WARNING: Could not recover jumptable at 0xfffffff00994b170. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x90))
            (param_1,param_2,param_5,param_4[lVar3 + 1] & 0xffffff00,param_5,
             (undefined8 *)(*param_1 + 0x90));
  return;
}

