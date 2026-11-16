// FUN_fffffff009941ddc @ fffffff009941ddc size=344

undefined8 FUN_fffffff009941ddc(long *param_1,long *param_2,ulong param_3,uint param_4,uint param_5)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  if (((CARRY4((uint)param_3,param_5)) || (CARRY4(param_4,param_5))) ||
     (*(uint *)(param_1 + 0x14) <= param_4 || *(uint *)(param_1 + 0x14) < param_4 + param_5)) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid arguments\n");
    uVar3 = 0xe00002c2;
  }
  else {
    FUN_fffffff009942d70(param_1);
    if (param_1 != param_2) {
      FUN_fffffff009942d70(param_2);
    }
    if (param_4 < param_4 + param_5) {
      uVar4 = (ulong)param_4;
      do {
        lVar2 = uVar4 * 8;
        puVar1 = (undefined8 *)(param_1[0x13] + (long)(int)lVar2);
        if (lVar2 - (int)lVar2 != 0) {
          puVar1 = (undefined8 *)(param_1[0x13] + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar3 = (**(code **)(*param_2 + 0x120))(param_2,param_3,*puVar1);
        if ((int)uVar3 != 0) goto LAB_fffffff009941f18;
        param_3 = (ulong)((int)param_3 + 1);
        uVar4 = uVar4 + 1;
        param_5 = param_5 - 1;
      } while (param_5 != 0);
    }
    uVar3 = 0;
LAB_fffffff009941f18:
    if (param_1 != param_2) {
      FUN_fffffff009942d7c(param_2);
    }
    FUN_fffffff009942d7c(param_1);
  }
  return uVar3;
}

