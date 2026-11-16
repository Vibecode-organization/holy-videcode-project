// FUN_fffffff00818f8e8 @ fffffff00818f8e8 size=1924

undefined8 FUN_fffffff00818f8e8(long *param_1,long *param_2,undefined8 param_3,long param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  long *plVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  uint uVar10;
  uint uVar11;
  
  param_1[0xc2] = 0;
  (**(code **)(*param_2 + 0xd58))(param_2,param_3,0,param_1);
  uVar5 = (**(code **)(PTR_DAT_fffffff007ca6130 + 0xe8))(param_1,param_2,param_3,param_4);
  if ((uVar5 & 1) == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed on call to commandQueueStart\n");
    return 0;
  }
  uVar1 = *(uint *)(param_1[0xa6] + 0x11140);
  if (uVar1 == 0) {
    uVar1 = *(uint *)(param_1[0xa6] + 0x610);
  }
  *(uint *)(param_1 + 0x109) = uVar1;
  plVar6 = *(long **)(param_1[0x91] + 0x1f0);
  param_1[0x10a] = (long)plVar6;
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x20))();
    uVar1 = *(uint *)(param_1 + 0x109);
  }
  uVar5 = 0x8000000000000000;
  if (-1 < (int)uVar1) {
    uVar5 = -(ulong)(uVar1 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar1 << 3;
  }
  lVar7 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca30b8,uVar5);
  param_1[0x11e] = lVar7;
  if (lVar7 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to allocate fMSESceneStateGPUAddr"
              );
    return 0;
  }
  lVar7 = -0x8000000000000000;
  if (-1 < (int)param_1[0x109]) {
    lVar7 = (long)(int)param_1[0x109] << 3;
  }
  lVar7 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca3108,lVar7);
  param_1[0x11f] = lVar7;
  if (lVar7 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to allocate fMSESceneStateFWAddr")
    ;
    return 0;
  }
  lVar7 = -0x8000000000000000;
  if (-1 < (int)param_1[0x109]) {
    lVar7 = (long)(int)param_1[0x109] << 2;
  }
  lVar7 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca3158,lVar7);
  param_1[0x120] = lVar7;
  if (lVar7 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to allocate fMSESceneStateNopPtr")
    ;
    return 0;
  }
  lVar7 = -0x8000000000000000;
  if (-1 < (int)param_1[0x109]) {
    lVar7 = (long)(int)param_1[0x109] << 6;
  }
  lVar7 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca31a8,lVar7);
  param_1[0x11c] = lVar7;
  if (lVar7 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,
               "Failed to allocate fCompositeEncoderIDEventArray");
    return 0;
  }
  if (0 < (int)param_1[0x109]) {
    lVar7 = 0;
    do {
      uVar5 = param_1[0x11c] + lVar7 * 0x40;
      if (((param_1[0x11c] ^ uVar5) & 0xffc0000000000000) != 0) {
        uVar5 = uVar5 & 0xffffffffffff | 0xc8a2000000000000;
      }
      thunk_EXT_FUN_8011000002946f14(uVar5);
      lVar7 = lVar7 + 1;
    } while (lVar7 < (int)param_1[0x109]);
  }
  lVar7 = param_1[0xa6];
  uVar1 = *(uint *)(lVar7 + 0x11158);
  uVar11 = uVar1;
  if (uVar1 == 0) {
    uVar11 = *(uint *)(lVar7 + 0x638);
  }
  uVar2 = *(uint *)(lVar7 + 0x1115c);
  if (uVar2 == 0) {
    uVar2 = *(uint *)(lVar7 + 0x63c);
    uVar10 = uVar2;
    if (uVar11 < uVar2) {
      uVar10 = uVar1;
    }
    if (uVar11 < uVar2 && uVar1 == 0) goto LAB_fffffff00818fac0;
  }
  else {
    uVar10 = uVar2;
    if (uVar11 < uVar2) {
      uVar10 = uVar1;
    }
    if (uVar1 == 0 && uVar11 < uVar2) {
LAB_fffffff00818fac0:
      uVar10 = *(uint *)(lVar7 + 0x638);
    }
  }
  *(uint *)((long)param_1 + 0x834) = uVar10;
  iVar4 = *(int *)(lVar7 + 0x11160);
  if (iVar4 == 0) {
    iVar4 = *(int *)(lVar7 + 0x640);
  }
  *(int *)(param_1 + 0x107) = iVar4;
  thunk_EXT_FUN_8011000002946f14(param_1 + 0xcd);
  thunk_EXT_FUN_8011000002946f14(param_1 + 0xe5);
  thunk_EXT_FUN_8011000002946f14(param_1 + 0xd5);
  thunk_EXT_FUN_8011000002946f14(param_1 + 0xed);
  thunk_EXT_FUN_8011000002946f14(param_1 + 0xdd);
  thunk_EXT_FUN_8011000002946f14(param_1 + 0xf5);
  lVar7 = param_1[0xa6];
  iVar4 = *(int *)(lVar7 + 0x1114c);
  if (iVar4 == 0) {
    iVar4 = *(int *)(lVar7 + 0x62c);
  }
  *(int *)(param_1 + 0xff) = iVar4;
  iVar4 = *(int *)(lVar7 + 0x11154);
  if (iVar4 == 0) {
    iVar4 = *(int *)(lVar7 + 0x634);
  }
  *(int *)((long)param_1 + 0x7fc) = iVar4;
  *(undefined4 *)((long)param_1 + 0x7ec) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x7f4) = 0x100;
  *(undefined4 *)((long)param_1 + 0x83c) = 0;
  param_1[0x108] = 0;
  uVar1 = *(uint *)((long)param_1 + 0x834);
  uVar11 = 0;
  if (uVar1 != 0) {
    uVar11 = (uVar1 - 1) / uVar1;
  }
  *(uint *)(param_1 + 0x106) = (uVar1 - 1) - uVar11 * uVar1;
  thunk_EXT_FUN_8011000002946f14(param_1 + 0xc5);
  thunk_EXT_FUN_8011000002946f14(param_1 + 0x10b);
  thunk_EXT_FUN_8011000002946f14(param_1 + 0x113);
  *(undefined4 *)(param_1 + 0x11b) = 0xffffffff;
  *(undefined1 *)((long)param_1 + 0x8dc) = 0;
  *(undefined1 *)(param_1 + 0x121) = 0;
  thunk_EXT_FUN_8011000002946f14(param_1 + 0xba);
  *(undefined1 *)(param_1 + 0xc3) = 0;
  iVar4 = *(int *)(*(long *)(*(long *)(param_1[0xa6] + 0x4b0) + 0x348) + 0xe08);
  if (iVar4 == 0) {
LAB_fffffff00818fc88:
    plVar6 = (long *)thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca20c8,0x30);
    puVar9 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(plVar6,&DAT_fffffff00ae23368);
    *puVar9 = &DAT_fffffff007c9d2b0;
    thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae23368);
    param_1[0x123] = (long)plVar6;
    uVar5 = (**(code **)(*plVar6 + 0x78))(plVar6,param_1[0xa6]);
    if ((uVar5 & 1) == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to init PM Queue Config\n");
      uVar8 = 0;
    }
    else {
      if (((*(byte *)(param_1[0x91] + 0x40) >> 1 & 1) != 0) &&
         ((*(byte *)(param_1[0xa6] + 0x10a9d) & 1) != 0)) {
        *(undefined1 *)(param_1[0x123] + 0x24) = 1;
      }
      thunk_EXT_FUN_80110000029728f4(param_1);
      uVar5 = (**(code **)(*param_1 + 0x158))(param_1,0);
      thunk_EXT_FUN_8011000002972900(param_1);
      if ((uVar5 & 1) == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,
                   "Failed to create command queue FW resources\n");
        uVar8 = 0;
      }
      else {
        *(byte *)((long)param_1 + 0x7f5) = *(byte *)(param_4 + 0x408) & 1;
        uVar1 = *(uint *)(param_4 + 0x408);
        if ((uVar1 >> 1 & 1) != 0) {
          *(undefined1 *)((long)param_1 + 0x7f6) = 1;
          uVar1 = *(uint *)(param_4 + 0x408);
        }
        if ((uVar1 >> 2 & 1) != 0) {
          *(undefined1 *)((long)param_1 + 0x7f7) = 1;
          uVar1 = *(uint *)(param_4 + 0x408);
        }
        if ((uVar1 >> 3 & 1) == 0) {
          uVar8 = 1;
        }
        else {
          uVar8 = thunk_EXT_FUN_80110000039dae48
                            (*(undefined8 *)(param_1[0x91] + 0x50),
                             "com.apple.private.agx.performance-spi");
          if ((int)uVar8 != 0) {
            uVar8 = 1;
            *(undefined1 *)(param_1[0x123] + 0x25) = 1;
          }
        }
      }
    }
  }
  else {
    plVar6 = (long *)thunk_EXT_FUN_80110000039589e4();
    param_1[0x126] = (long)plVar6;
    if (plVar6 == (long *)0x0) {
      (**(code **)(*param_1 + 0x38))(param_1);
      thunk_EXT_FUN_8011000003891b28();
    }
    else {
      uVar8 = (**(code **)(*plVar6 + 0x88))();
      thunk_EXT_FUN_8011000003271c3c(uVar8,"AGXCommandQueueProcessExitWorkLoop");
      lVar7 = thunk_EXT_FUN_801100000395c074(param_1,0);
      param_1[0x127] = lVar7;
      if (lVar7 == 0) {
        (**(code **)(*param_1 + 0x38))(param_1);
        thunk_EXT_FUN_8011000003891b28();
      }
      else {
        iVar3 = (**(code **)(*(long *)param_1[0x126] + 0xa0))((long *)param_1[0x126],lVar7);
        if (iVar3 == 0) {
          (**(code **)(*(long *)param_1[0x127] + 0xb0))();
          *(int *)(param_1 + 0x124) = iVar4;
          lVar7 = thunk_EXT_FUN_801100000396100c(1,param_1,FUN_fffffff00819006c);
          param_1[0x125] = lVar7;
          if (lVar7 != 0) {
            iVar4 = (**(code **)(*(long *)param_1[0x126] + 0xa0))((long *)param_1[0x126],lVar7);
            if (iVar4 == 0) goto LAB_fffffff00818fc88;
            (**(code **)(*(long *)param_1[0x125] + 0x28))();
            param_1[0x125] = 0;
          }
          (**(code **)(*(long *)param_1[0x127] + 0xb8))();
          (**(code **)(*(long *)param_1[0x126] + 0xa8))((long *)param_1[0x126],param_1[0x127]);
        }
        else {
          (**(code **)(*param_1 + 0x38))(param_1);
          thunk_EXT_FUN_8011000003891b28();
        }
        if ((long *)param_1[0x127] != (long *)0x0) {
          (**(code **)(*(long *)param_1[0x127] + 0x28))();
        }
        param_1[0x127] = 0;
      }
      if ((long *)param_1[0x126] != (long *)0x0) {
        (**(code **)(*(long *)param_1[0x126] + 0x28))();
      }
      param_1[0x126] = 0;
    }
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,
               "Failed to create command queue process exit wait timer\n");
    uVar8 = 0;
  }
  return uVar8;
}

