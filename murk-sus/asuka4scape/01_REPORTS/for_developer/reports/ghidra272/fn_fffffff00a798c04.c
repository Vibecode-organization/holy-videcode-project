// FUN_fffffff00a798c04 @ fffffff00a798c04 size=600

uint FUN_fffffff00a798c04(long *param_1,ulong param_2,ulong param_3,int param_4,uint param_5)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  long *plVar7;
  
  lVar2 = param_1[0xc];
  uVar3 = (int)param_3 - (int)param_2;
  if ((int)uVar3 < 1) {
    if ((int)uVar3 < 0) {
      uVar6 = 0;
      plVar7 = param_1;
      do {
        uVar6 = (ulong)(uint)((int)plVar7[3] + (int)uVar6);
        plVar7 = (long *)*plVar7;
      } while (plVar7 != (long *)0x0);
      if (uVar6 < (ulong)-uVar3 + (param_3 & 0xffffffff)) goto LAB_fffffff00a798e30;
      uVar4 = FUN_fffffff00a1d23a0(param_1,(ulong)-uVar3,param_3,0);
      uVar3 = 0;
      param_5 = param_5 + (uVar4 & 0xffff);
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar6 = 0;
    plVar7 = param_1;
    do {
      uVar6 = (ulong)(uint)((int)plVar7[3] + (int)uVar6);
      plVar7 = (long *)*plVar7;
    } while (plVar7 != (long *)0x0);
    if (uVar6 < (ulong)uVar3 + (param_2 & 0xffffffff)) goto LAB_fffffff00a798e30;
    uVar3 = FUN_fffffff00a1d23a0(param_1,(ulong)uVar3,param_2,0);
    uVar3 = uVar3 & 0xffff;
  }
  uVar4 = param_4 + (int)param_3;
  uVar5 = (int)lVar2 - uVar4;
  if (0 < (int)uVar5) {
    uVar6 = 0;
    plVar7 = param_1;
    do {
      uVar6 = (ulong)(uint)((int)plVar7[3] + (int)uVar6);
      plVar7 = (long *)*plVar7;
    } while (plVar7 != (long *)0x0);
    if (uVar6 < (ulong)uVar5 + (ulong)uVar4) {
LAB_fffffff00a798e30:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114("%s: mbuf %p len (%u) < off+len (%u+%u) @%s:%d");
    }
    uVar5 = FUN_fffffff00a1d23a0(param_1,(ulong)uVar5,uVar4,0);
    if (uVar4 == 0) {
      uVar4 = 0;
    }
    else {
      do {
        if (param_1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa4d114("%s: invalid mbuf chain %p [off %u, len %u] @%s:%d");
        }
        uVar1 = uVar4 - *(uint *)(param_1 + 3);
        if (uVar4 < *(uint *)(param_1 + 3)) goto LAB_fffffff00a798d4c;
        param_1 = (long *)*param_1;
        uVar4 = uVar1;
      } while (uVar1 != 0);
      uVar4 = 0;
    }
LAB_fffffff00a798d4c:
    if (((int)param_1[2] + uVar4 & 1) != 0) {
      uVar5 = ((uVar5 & 0xff00ff00) >> 8 | (uVar5 & 0xff00ff) << 8) & 0xffff;
    }
    uVar3 = uVar3 + (uVar5 & 0xffff);
    uVar3 = (uVar3 >> 0x10) + (uVar3 & 0xffff);
  }
  uVar4 = param_5 - uVar3;
  if (param_5 <= uVar3) {
    uVar4 = (uVar3 - param_5 ^ 0xffffffff) & 0xffff;
  }
  if (uVar3 != 0) {
    param_5 = uVar4;
  }
  uVar3 = (param_5 >> 0x10) + (param_5 & 0xffff);
  uVar3 = (uVar3 >> 0x10) + (uVar3 & 0xffff);
  return uVar3 + (uVar3 >> 0x10) & 0xffff;
}

