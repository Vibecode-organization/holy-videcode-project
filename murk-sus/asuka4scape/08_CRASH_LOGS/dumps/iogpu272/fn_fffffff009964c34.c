// FUN_fffffff009964c34 @ fffffff009964c34 size=516

ulong FUN_fffffff009964c34(long *param_1,long param_2,long param_3)

{
  byte bVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  
  (*DAT_fffffff007feb260)();
  param_1[9] = param_2;
  thunk_EXT_FUN_801100000326c6a4(param_3);
  param_1[10] = param_3;
  lVar5 = (**(code **)(*param_1 + 0xe0))(param_1,param_3);
  param_1[0xb] = lVar5;
  uVar7 = 0;
  if (lVar5 != 0) {
    lVar5 = thunk_EXT_FUN_80110000038ff010();
    param_1[4] = lVar5;
    uVar7 = 0;
    if (lVar5 != 0) {
      lVar5 = thunk_EXT_FUN_80110000038ff010();
      param_1[5] = lVar5;
      uVar7 = 0;
      if (lVar5 != 0) {
        uVar6 = FUN_fffffff009944798(*(undefined8 *)(param_1[9] + 0x1d0),param_1[0xb]);
        FUN_fffffff0099710dc(param_1[0xb],uVar6);
        FUN_fffffff009970a14(param_1[0xb],param_1);
        lVar5 = thunk_EXT_FUN_80110000032970b4(param_3);
        if (lVar5 == 0) {
          *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
          bVar1 = *(byte *)(param_1 + 8) | 1;
        }
        else {
          uVar3 = thunk_EXT_FUN_8011000003720f30();
          *(undefined4 *)(param_1 + 0xc) = uVar3;
          iVar4 = thunk_EXT_FUN_80110000037233c0(lVar5);
          bVar1 = *(byte *)(param_1 + 8) & 0xfe;
          if (iVar4 != 0) {
            bVar1 = bVar1 + 1;
          }
        }
        *(byte *)(param_1 + 8) = bVar1;
        lVar5 = FUN_fffffff009944e20();
        param_1[2] = lVar5;
        uVar7 = 0;
        if (lVar5 != 0) {
          lVar5 = FUN_fffffff009944e20();
          param_1[0x11] = lVar5;
          uVar7 = 0;
          if (lVar5 != 0) {
            lVar5 = FUN_fffffff009944e20();
            param_1[0x12] = lVar5;
            uVar7 = 0;
            if (lVar5 != 0) {
              lVar5 = FUN_fffffff009963ab0
                                (param_2,param_3,param_1[0xb],0x80,
                                 *(undefined4 *)(param_1[9] + 0x22c),0x100,0x1000);
              param_1[6] = lVar5;
              uVar7 = 0;
              if (lVar5 != 0) {
                lVar5 = FUN_fffffff009944e20();
                param_1[0xf] = lVar5;
                uVar7 = 0;
                if (lVar5 != 0) {
                  lVar5 = FUN_fffffff009944e20();
                  param_1[3] = lVar5;
                  uVar7 = 0;
                  if (lVar5 != 0) {
                    lVar5 = FUN_fffffff009944e20();
                    param_1[0x20] = lVar5;
                    uVar7 = 0;
                    if (lVar5 != 0) {
                      lVar5 = FUN_fffffff009944e20();
                      param_1[0x10] = lVar5;
                      uVar7 = 0;
                      if (lVar5 != 0) {
                        FUN_fffffff00995c524(param_1);
                        lVar5 = thunk_EXT_FUN_80110000038905f0(1,&DAT_fffffff00af220c0);
                        param_1[7] = lVar5;
                        uVar7 = FUN_fffffff0099640c0(param_1[6],0,param_1 + 0x1a);
                        if ((int)uVar7 != 0) {
                          lVar5 = FUN_fffffff009944e20();
                          param_1[0x21] = lVar5;
                          uVar7 = 0;
                          if (lVar5 != 0) {
                            lVar5 = FUN_fffffff009944e20();
                            param_1[0x22] = lVar5;
                            uVar7 = 0;
                            if (lVar5 != 0) {
                              uVar2 = FUN_fffffff009964e38
                                                (param_1,"com.apple.private.agx.rt-priority-spi");
                              param_1[0x1d] = 0;
                              *(undefined1 *)(param_1 + 0x23) = uVar2;
                              param_1[0x1e] = (long)(param_1 + 0x1d);
                              lVar5 = thunk_EXT_FUN_80110000038ff010();
                              param_1[0x1c] = lVar5;
                              uVar7 = (ulong)(lVar5 != 0);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar7;
}

