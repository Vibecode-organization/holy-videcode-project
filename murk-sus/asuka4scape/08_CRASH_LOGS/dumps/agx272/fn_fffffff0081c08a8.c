// FUN_fffffff0081c08a8 @ fffffff0081c08a8 size=304

void FUN_fffffff0081c08a8(undefined8 param_1,long param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_3 < 2) {
    if (param_3 == 0) {
      *(undefined8 *)(param_2 + 0x30) = 0;
      *(undefined8 *)(param_2 + 0x38) = 0xffffffffffff0000;
      *(undefined8 *)(param_2 + 0x40) = 0x100000001;
      return;
    }
    if (param_3 == 1) {
      if (1 < param_4) {
        if (param_4 == 2) {
          *(undefined4 *)(param_2 + 0x30) = 2;
          *(undefined4 *)(param_2 + 0x34) = 2;
          *(undefined8 *)(param_2 + 0x38) = 0xffff000000000000;
          *(undefined8 *)(param_2 + 0x40) = DAT_fffffff007113e40;
          return;
        }
        if (param_4 == 4) {
          *(undefined4 *)(param_2 + 0x30) = 3;
          *(undefined4 *)(param_2 + 0x34) = 3;
          *(undefined8 *)(param_2 + 0x38) = 0;
          *(undefined8 *)(param_2 + 0x40) = DAT_fffffff007113e90;
          return;
        }
LAB_fffffff0081c0990:
        *(undefined4 *)(param_2 + 0x30) = 2;
        *(undefined4 *)(param_2 + 0x34) = 2;
        *(undefined8 *)(param_2 + 0x38) = 0xffff000000000000;
        *(undefined8 *)(param_2 + 0x40) = DAT_fffffff007113f90;
        return;
      }
      if (param_4 != 0) {
        if (param_4 == 1) {
          *(undefined4 *)(param_2 + 0x30) = 2;
          *(undefined4 *)(param_2 + 0x34) = 2;
          *(undefined8 *)(param_2 + 0x38) = 0xffff000000000000;
          *(undefined8 *)(param_2 + 0x40) = DAT_fffffff007113ec0;
          return;
        }
        goto LAB_fffffff0081c0990;
      }
      uVar1 = 2;
      goto LAB_fffffff0081c0928;
    }
  }
  else {
    if (param_3 == 2) {
      *(undefined4 *)(param_2 + 0x30) = 3;
      *(undefined4 *)(param_2 + 0x34) = 3;
      *(undefined8 *)(param_2 + 0x40) = 0;
      *(undefined8 *)(param_2 + 0x38) = 0;
      return;
    }
    if ((param_3 != 4) && (param_3 == 5)) {
      *(undefined8 *)(param_2 + 0x30) = 0;
      *(undefined8 *)(param_2 + 0x38) = 0xffffffffffff0000;
      *(undefined8 *)(param_2 + 0x40) = DAT_fffffff007113ee0;
      return;
    }
  }
  uVar1 = 1;
LAB_fffffff0081c0928:
  *(undefined4 *)(param_2 + 0x30) = uVar1;
  *(undefined4 *)(param_2 + 0x34) = uVar1;
  *(undefined8 *)(param_2 + 0x38) = 0xffffffff00000000;
  *(undefined8 *)(param_2 + 0x40) = 0;
  return;
}

