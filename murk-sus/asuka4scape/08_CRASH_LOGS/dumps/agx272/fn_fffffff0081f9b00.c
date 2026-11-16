// FUN_fffffff0081f9b00 @ fffffff0081f9b00 size=456

void FUN_fffffff0081f9b00
               (undefined2 *param_1,int param_2,int param_3,uint param_4,uint param_5,ushort param_6
               ,byte param_7,uint param_8,ulong param_9,char param_10)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  undefined1 uVar6;
  uint uVar7;
  
  *(byte *)(param_1 + 7) = param_7;
  *param_1 = (short)param_2;
  param_1[1] = (short)param_3;
  param_1[2] = param_6;
  *(char *)(param_1 + 4) = (char)param_8;
  param_1[3] = (short)(param_9 >> 0x20);
  *(char *)((long)param_1 + 0x11) = param_10;
  *(undefined1 *)((long)param_1 + 0xf) = (undefined1)param_9;
  *(char *)(param_1 + 9) = (char)param_4;
  *(char *)((long)param_1 + 0x13) = (char)param_5;
  *(undefined1 *)(param_1 + 10) = 0;
  *(char *)((long)param_1 + 0x15) = param_9._2_1_;
  *(undefined1 *)(param_1 + 0xb) = param_9._3_1_;
  if ((((param_6 < 2) || (param_9._4_4_ < 0x1001)) || (param_10 != '\0')) || (param_8 < 2)) {
    uVar2 = 0;
    if (param_4 != 0) {
      uVar2 = ((param_2 + param_4) - 1) / param_4;
    }
    uVar3 = 0;
    if (param_5 != 0) {
      uVar3 = ((param_3 + param_5) - 1) / param_5;
    }
    uVar6 = 1;
    uVar7 = 1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f);
    uVar1 = param_9._4_4_ & 0xffff;
    if (uVar7 <= uVar2 * param_7 * uVar3 && (int)uVar1 <= (int)uVar7) {
      if (param_9._2_1_ != '\0') {
        uVar6 = 2;
      }
      if (param_9._1_1_ == '\0') {
        uVar6 = 0;
      }
      *(undefined1 *)(param_1 + 8) = uVar6;
      uVar7 = uVar1 * 3;
      if (0x55555555 < (uint)param_7 * -0x55555555) {
        uVar7 = uVar1;
      }
      uVar5 = 0;
      if (param_7 != 0) {
        uVar5 = uVar7 / param_7;
      }
      uVar7 = 0;
      if (1 < uVar5) {
        uVar7 = 0x20 - (int)LZCOUNT(uVar5 - 1);
      }
      uVar5 = uVar7 >> 1;
      *(char *)(param_1 + 6) = (char)uVar5;
      uVar7 = uVar7 - uVar5;
      *(char *)((long)param_1 + 0xd) = (char)uVar7;
      if (param_9._1_1_ != '\0') {
        if (uVar5 < 6) {
          uVar5 = 5;
        }
        *(char *)(param_1 + 6) = (char)uVar5;
        if (uVar7 < 6) {
          uVar7 = 5;
        }
        *(char *)((long)param_1 + 0xd) = (char)uVar7;
      }
      uVar6 = 0;
      if ((param_9 & 0xffff00000000) != 0) {
        uVar6 = (undefined1)
                ((int)((uint)param_7 << (ulong)(uVar5 + (uVar7 & 0xff) & 0x1f)) / (int)uVar1);
      }
      *(undefined1 *)((long)param_1 + 9) = uVar6;
      if (uVar2 < 2) {
        cVar4 = '\0';
      }
      else {
        cVar4 = ' ' - (char)LZCOUNT(~(-1 << (ulong)(-(int)LZCOUNT(uVar2 - 1) & 0x1f)));
      }
      *(char *)(param_1 + 5) = cVar4;
      if (1 < uVar3) {
        *(char *)((long)param_1 + 0xb) =
             ' ' - (char)LZCOUNT(~(-1 << (ulong)(-(int)LZCOUNT(uVar3 - 1) & 0x1f)));
        return;
      }
      *(undefined1 *)((long)param_1 + 0xb) = 0;
      return;
    }
  }
  return;
}

