// FUN_fffffff00a1dfcb0 @ fffffff00a1dfcb0 size=404

undefined8
FUN_fffffff00a1dfcb0
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,uint *param_7,long param_8,
          uint *param_9,ulong *param_10)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  undefined1 extraout_q0 [16];
  
  lVar1 = tpidr_el1;
  *(int *)(lVar1 + 0x1c0) = *(int *)(lVar1 + 0x1c0) + 1;
  LOAcquire();
  uVar3 = param_7[2];
  param_7[2] = uVar3 + 0x1000000;
  if ((uVar3 >> 0x10 & 0xff) == uVar3 >> 0x18) {
    param_7[3] = *(uint *)(lVar1 + 0x4e8);
  }
  else {
    param_1 = FUN_fffffff00a22b5a8((long)param_7,(ulong)(uVar3 >> 0x18),lVar1);
  }
  while( true ) {
    uVar7 = *(ulong *)(param_7 + 0x12);
    if ((uVar7 == 0) || (uVar7 == 0)) {
      FUN_fffffff00a22b850((long)param_7);
      return 0x10;
    }
    uVar7 = *(ulong *)(param_7 + 0x12);
    if (uVar7 == 0) {
      uVar3 = param_7[5];
      uVar5 = 0;
      uVar6 = 0;
    }
    else {
      uVar3 = param_7[5];
      uVar5 = 0;
      if (uVar7 != 0) {
        uVar5 = (uVar7 & 0x3fff) << 0xe;
      }
      uVar6 = 0;
      if (uVar7 != 0) {
        uVar6 = uVar7 & 0xffffffffffffc000 | 0x4000000000;
      }
      if ((uVar7 & 0x4000000000) != 0) {
        uVar5 = (uVar7 & 0x10 | 0x20) << (uVar7 & 0xf);
        uVar6 = uVar7 & 0xffffffffffffffe0;
      }
    }
    if ((uVar3 + 1 <= (uint)((int)((uVar5 & 0xffffffff) * 0xaaaaaab >> 0x20) * 7) >> 3) &&
       (*(uint *)(uVar6 + 0xc) != 0)) break;
    uVar4 = FUN_fffffff00a1dfe44(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0xffffffff)
    ;
    param_1 = extraout_q0;
    if ((int)uVar4 != 0) {
      return uVar4;
    }
  }
  if ((ulong)*(uint *)(uVar6 + 0xc) * 0x18 + 0x18 <= uVar5) {
    FUN_fffffff00a1dfb60((long)param_7,param_8,param_9,param_10);
    return 0;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a1dfe44);
  (*pcVar2)();
}

