// FUN_fffffff0081ac17c @ fffffff0081ac17c size=728

/* WARNING: Removing unreachable block (ram,0xfffffff0081ac244) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff0081ac17c(long *param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))();
  if ((int)uVar1 != 0) {
    param_1[0x50] = param_2;
    param_1[0x51] = *(long *)(param_2 + 0x148);
    param_1[0xfd] = 0;
    param_1[0xfc] = 0;
    param_1[0xff] = 0;
    param_1[0xfe] = 0;
    *(undefined4 *)(param_1 + 0x100) = 0;
    uVar1 = (**(code **)(*param_1 + 0x98))(param_1);
    if ((int)uVar1 != 0) {
      puVar2 = (undefined8 *)(**(code **)(*(long *)param_1[0x50] + 0x898))();
      param_1[0x42] = (long)puVar2;
      uVar1 = (**(code **)*puVar2)(puVar2,param_1[0x50]);
      if ((int)uVar1 != 0) {
        lVar3 = thunk_EXT_FUN_80110000038ff010();
        param_1[0x120] = lVar3;
        uVar1 = 0;
        if (lVar3 != 0) {
          *(undefined1 *)((long)param_1 + 0x8f4) = 0;
          param_1[0x11f] = 0;
          lVar4 = param_1[0x50];
          lVar6 = param_1[0x10f];
          lVar7 = param_1[0x113];
          param_1[0xb4] = lVar4;
          lVar5 = _UNK_fffffff007113938;
          lVar3 = _DAT_fffffff007113930;
          param_1[0xb9] = _UNK_fffffff007113938;
          param_1[0xb8] = lVar3;
          param_1[0xb5] = lVar6;
          param_1[0xb6] = lVar7;
          param_1[0xba] = lVar4;
          param_1[0xbf] = lVar5;
          param_1[0xbe] = lVar3;
          param_1[0xbb] = lVar6 + 0x30;
          param_1[0xbc] = lVar7 + 0x4800;
          param_1[0xc0] = lVar4;
          param_1[0xc5] = lVar5;
          param_1[0xc4] = lVar3;
          param_1[0xc1] = lVar6 + 0x60;
          param_1[0xc2] = lVar7 + 0x9000;
          param_1[0xc6] = lVar4;
          param_1[0xcb] = lVar5;
          param_1[0xca] = lVar3;
          param_1[199] = lVar6 + 0x90;
          param_1[200] = lVar7 + 0xd800;
          param_1[0xcc] = lVar4;
          param_1[0xd1] = lVar5;
          param_1[0xd0] = lVar3;
          param_1[0xcd] = lVar6 + 0xc0;
          param_1[0xce] = lVar7 + 0x12000;
          param_1[0xd2] = lVar4;
          param_1[0xd7] = lVar5;
          param_1[0xd6] = lVar3;
          param_1[0xd3] = lVar6 + 0xf0;
          param_1[0xd4] = lVar7 + 0x16800;
          param_1[0xd8] = lVar4;
          param_1[0xdd] = lVar5;
          param_1[0xdc] = lVar3;
          param_1[0xd9] = lVar6 + 0x120;
          param_1[0xda] = lVar7 + 0x1b000;
          param_1[0xde] = lVar4;
          param_1[0xe3] = lVar5;
          param_1[0xe2] = lVar3;
          param_1[0xdf] = lVar6 + 0x150;
          param_1[0xe0] = lVar7 + 0x1f800;
          param_1[0xe4] = lVar4;
          param_1[0xe9] = lVar5;
          param_1[0xe8] = lVar3;
          param_1[0xe5] = lVar6 + 0x180;
          param_1[0xe6] = lVar7 + 0x24000;
          lVar5 = param_1[0x50];
          param_1[0xea] = lVar5;
          lVar3 = _DAT_fffffff007113940;
          param_1[0xef] = _UNK_fffffff007113948;
          param_1[0xee] = lVar3;
          param_1[0xeb] = param_1[0x110];
          param_1[0xec] = param_1[0x114];
          param_1[0xf0] = lVar5;
          lVar3 = _DAT_fffffff007113950;
          param_1[0xf5] = _UNK_fffffff007113958;
          param_1[0xf4] = lVar3;
          param_1[0xf1] = param_1[0x111];
          param_1[0xf2] = param_1[0x115];
          param_1[0x111] = 0;
          param_1[0x110] = 0;
          param_1[0x115] = 0;
          param_1[0x114] = 0;
          param_1[0xf6] = lVar5;
          lVar3 = _DAT_fffffff007113960;
          param_1[0xfb] = _UNK_fffffff007113968;
          param_1[0xfa] = lVar3;
          param_1[0xf7] = param_1[0x10e];
          param_1[0xf8] = param_1[0x112];
          param_1[0x10f] = 0;
          param_1[0x10e] = 0;
          param_1[0x113] = 0;
          param_1[0x112] = 0;
          *(undefined1 *)(param_1 + 0x52) = 0;
          param_1[0x17f] = 0xffff;
          param_1[399] = -1;
          param_1[0x18e] = -1;
          param_1[0x18d] = -1;
          param_1[0x18c] = -1;
          param_1[0x18b] = -1;
          param_1[0x18a] = -1;
          param_1[0x189] = -1;
          param_1[0x188] = -1;
          param_1[0x187] = -1;
          param_1[0x186] = -1;
          param_1[0x185] = -1;
          param_1[0x184] = -1;
          param_1[0x183] = -1;
          param_1[0x182] = -1;
          param_1[0x181] = -1;
          param_1[0x180] = -1;
          lVar3 = thunk_EXT_FUN_80110000038ff010();
          param_1[400] = lVar3;
          uVar1 = 0;
          if (lVar3 != 0) {
            *(undefined1 *)((long)param_1 + 0x292) = 0;
            lVar3 = thunk_EXT_FUN_80110000038ff010();
            param_1[0x178] = lVar3;
            uVar1 = 0;
            if (lVar3 != 0) {
              (**(code **)(*param_1 + 0x90))(param_1);
              uVar1 = 1;
            }
          }
        }
      }
    }
  }
  return uVar1;
}

