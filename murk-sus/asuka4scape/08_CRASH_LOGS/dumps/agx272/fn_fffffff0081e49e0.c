// FUN_fffffff0081e49e0 @ fffffff0081e49e0 size=696

undefined8 FUN_fffffff0081e49e0(undefined8 param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  
  uVar1 = param_2 + param_3;
  if (CARRY8(param_2,param_3)) {
    return 0;
  }
  uVar5 = param_2 >> 0x20;
  if (uVar5 < 0x11) {
LAB_fffffff0081e49f8:
    uVar4 = 0;
  }
  else if (param_2 >> 0x21 < 9) {
    uVar4 = 1;
  }
  else {
    if (uVar5 < 0x13) goto LAB_fffffff0081e49f8;
    if (param_2 >> 0x22 < 5) {
      uVar4 = 2;
    }
    else if (param_2 < 0x14ffc00000) {
      uVar4 = 3;
    }
    else if (uVar5 < 0x15) {
      uVar4 = 4;
    }
    else if (param_2 >> 0x24 < 7) {
      uVar4 = 5;
    }
    else if (param_2 < 0xffffff9fffe00000) {
      if (0x38 < param_2 >> 0x21) goto LAB_fffffff0081e49f8;
      uVar4 = 0xd;
    }
    else if (param_2 < 0xffffffa000000000) {
      uVar4 = 7;
    }
    else if (param_2 < 0xffffffa0c0000000) {
      uVar4 = 8;
    }
    else if (param_2 < 0xffffffa180000000) {
      uVar4 = 9;
    }
    else if (param_2 < 0xffffffa181400000) {
      uVar4 = 10;
    }
    else if (param_2 < 0xffffffa185400000) {
      uVar4 = 0xb;
    }
    else {
      if (0xffffffa1893fffff < param_2) goto LAB_fffffff0081e49f8;
      uVar4 = 0xc;
    }
  }
  uVar5 = uVar1 >> 0x20;
  if (0x10 < uVar5) {
    if (uVar1 >> 0x21 < 9) {
      uVar3 = 1;
      goto LAB_fffffff0081e4a34;
    }
    if (0x12 < uVar5) {
      if (uVar1 >> 0x22 < 5) {
        uVar3 = 2;
        goto LAB_fffffff0081e4a34;
      }
      if (uVar1 < 0x14ffc00000) {
        uVar3 = 3;
        goto LAB_fffffff0081e4a34;
      }
      if (uVar5 < 0x15) {
        uVar3 = 4;
        goto LAB_fffffff0081e4a34;
      }
      if (uVar1 >> 0x24 < 7) {
        uVar3 = 5;
        goto LAB_fffffff0081e4a34;
      }
      if (uVar1 < 0xffffff9fffe00000) {
        if (uVar1 >> 0x21 < 0x39) {
          uVar3 = 0xd;
          goto LAB_fffffff0081e4a34;
        }
      }
      else {
        if (uVar1 < 0xffffffa000000000) {
          uVar3 = 7;
          goto LAB_fffffff0081e4a34;
        }
        if (uVar1 < 0xffffffa0c0000000) {
          uVar3 = 8;
          goto LAB_fffffff0081e4a34;
        }
        if (uVar1 < 0xffffffa180000000) {
          uVar3 = 9;
          goto LAB_fffffff0081e4a34;
        }
        if (uVar1 < 0xffffffa181400000) {
          uVar3 = 10;
          goto LAB_fffffff0081e4a34;
        }
        if (uVar1 < 0xffffffa185400000) {
          uVar3 = 0xb;
          goto LAB_fffffff0081e4a34;
        }
        if (uVar1 < 0xffffffa189400000) {
          uVar3 = 0xc;
          goto LAB_fffffff0081e4a34;
        }
      }
    }
  }
  uVar3 = 0;
LAB_fffffff0081e4a34:
  if (((uVar4 == uVar3) && (uVar4 < 6)) && ((1 << (ulong)uVar4 & 0x26U) != 0)) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081e4a6c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(PTR_DAT_fffffff007ca60f8 + 200))();
    return uVar2;
  }
  return 0;
}

