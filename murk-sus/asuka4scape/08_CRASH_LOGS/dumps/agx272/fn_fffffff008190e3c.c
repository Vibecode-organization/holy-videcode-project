// FUN_fffffff008190e3c @ fffffff008190e3c size=4

void FUN_fffffff008190e3c
               (long *param_1,undefined8 param_2,ulong param_3,ulong param_4,ulong param_5,
               ulong param_6,undefined8 param_7)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined4 uVar7;
  undefined8 *puVar8;
  undefined *puStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  ulong uStack_c0;
  ulong uStack_b8;
  ulong uStack_b0;
  ulong uStack_a0;
  ulong uStack_98;
  ulong uStack_90;
  undefined *puStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  
  if ((*(int *)((long)param_1 + 0x44c) == 5) && ((*(byte *)(param_1[0xa6] + 0x1ac78) & 1) == 0)) {
    *(undefined4 *)(param_1 + 0xa4) = 0x108;
    return;
  }
  if (7 < (ulong)param_1[0xa9] || (1L << (param_1[0xa9] & 0x3fU) & 0x8bU) == 0) {
    *(undefined4 *)(param_1 + 0xa4) = 0x10;
    return;
  }
  uStack_98 = param_4;
  uStack_90 = param_3;
  if (param_4 < param_3) {
    uStack_98 = 0;
    uStack_90 = 0;
  }
  uStack_b8 = param_6;
  uStack_b0 = param_5;
  if (param_6 < param_5) {
    uStack_b8 = 0;
    uStack_b0 = 0;
  }
  uStack_d0 = 0;
  uStack_d8 = 0;
  puStack_e0 = &DAT_fffffff007c9ed60;
  uStack_c8 = param_2;
  uStack_c0 = uStack_b0;
  uStack_a0 = uStack_90;
  uVar4 = FUN_fffffff0081e15ac(&puStack_e0,&puStack_e0,&uStack_a0);
  if ((uVar4 & 1) == 0) {
    *(undefined4 *)(param_1 + 0xa4) = uStack_d8._4_4_;
    return;
  }
  if ((uStack_d8 & 1) == 0) {
LAB_fffffff0081914d4:
    thunk_EXT_FUN_8011000003a49114
              ("AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n");
    return;
  }
  if ((int)uStack_d0 != 0x10000) {
    (**(code **)(PTR_DAT_fffffff007ca6130 + 0xb0))
              (param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    return;
  }
  puVar5 = (undefined8 *)thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca3298,0x178);
  *(undefined1 *)(puVar5 + 1) = 0;
  *(undefined4 *)((long)puVar5 + 0xc) = 0;
  *puVar5 = &DAT_fffffff007c9c208;
  puVar8 = puVar5 + 0x1a;
  puVar5[0x1b] = 0;
  *puVar8 = 0;
  puVar5[3] = 0;
  puVar5[2] = 0;
  puVar5[5] = 0;
  puVar5[4] = 0;
  puVar5[7] = 0;
  puVar5[6] = 0;
  puVar5[9] = 0;
  puVar5[8] = 0;
  puVar5[0xb] = 0;
  puVar5[10] = 0;
  puVar5[0xd] = 0;
  puVar5[0xc] = 0;
  puVar5[0xf] = 0;
  puVar5[0xe] = 0;
  puVar5[0x11] = 0;
  puVar5[0x10] = 0;
  puVar5[0x13] = 0;
  puVar5[0x12] = 0;
  puVar5[0x15] = 0;
  puVar5[0x14] = 0;
  puVar5[0x17] = 0;
  puVar5[0x16] = 0;
  puVar5[0x19] = 0;
  puVar5[0x18] = 0;
  puVar5[0x1d] = 0;
  puVar5[0x1c] = 0;
  *(undefined1 *)(puVar5 + 0x1e) = 0;
  puVar5[0x20] = 0;
  puVar5[0x1f] = 0;
  *(undefined8 *)((long)puVar5 + 0x16a) = 0;
  *(undefined8 *)((long)puVar5 + 0x162) = 0;
  puVar5[0x2a] = 0;
  puVar5[0x29] = 0;
  puVar5[0x2c] = 0;
  puVar5[0x2b] = 0;
  puVar5[0x26] = 0;
  puVar5[0x25] = 0;
  puVar5[0x28] = 0;
  puVar5[0x27] = 0;
  puVar5[0x22] = 0;
  puVar5[0x21] = 0;
  puVar5[0x24] = 0;
  puVar5[0x23] = 0;
  uVar4 = FUN_fffffff0081df4b4(puVar5,&uStack_a0,&uStack_c0);
  if ((uVar4 & 1) == 0) {
    uVar7 = *(undefined4 *)((long)puVar5 + 0xc);
  }
  else {
    if ((*(byte *)(puVar5 + 1) & 1) == 0) goto LAB_fffffff0081914d4;
    if (*(int *)((long)puVar5 + 0x94) != 0) goto LAB_fffffff008191454;
    uVar1 = *(undefined8 *)(param_1[0xa3] + 0x130);
    uVar2 = *(undefined8 *)(param_1[0xa3] + 0x138);
    uVar4 = (**(code **)(*param_1 + 0x158))(param_1,1);
    if ((uVar4 & 1) == 0) {
      if ((*(byte *)(param_1[0xa6] + 0x1ac44) >> 3 & 1) != 0) {
        FUN_fffffff00817dc48(param_1[0xa6],0x362,2,param_1,1,0,0,0);
      }
      uVar7 = 8;
      goto LAB_fffffff008191304;
    }
    if ((*(byte *)(puVar5 + 1) & 1) == 0) goto LAB_fffffff0081914d4;
    iVar3 = *(int *)(puVar5 + 0x16);
    if (iVar3 < 5) {
      if (iVar3 == 1) {
        *(int *)(param_1[0xa3] + 0xd0) = *(int *)(param_1[0xa3] + 0xd0) + 1;
        puVar6 = (undefined8 *)thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca32e8,0x1c8);
        *(undefined1 *)(puVar6 + 1) = 0;
        *(undefined4 *)((long)puVar6 + 0xc) = 0;
        *puVar6 = &DAT_fffffff007c9e328;
        *(undefined1 *)(puVar6 + 2) = 0;
        puVar6[3] = 0;
        *(undefined4 *)((long)puVar6 + 300) = 0;
        *(undefined1 *)(puVar6 + 0x26) = 0;
        *(undefined1 *)(puVar6 + 0x29) = 0;
        puVar6[7] = 0;
        puVar6[6] = 0;
        puVar6[9] = 0;
        puVar6[8] = 0;
        puVar6[0xb] = 0;
        puVar6[10] = 0;
        puVar6[0xd] = 0;
        puVar6[0xc] = 0;
        puVar6[0xf] = 0;
        puVar6[0xe] = 0;
        puVar6[0x11] = 0;
        puVar6[0x10] = 0;
        puVar6[0x13] = 0;
        puVar6[0x12] = 0;
        puVar6[0x15] = 0;
        puVar6[0x14] = 0;
        puVar6[0x17] = 0;
        puVar6[0x16] = 0;
        puVar6[0x19] = 0;
        puVar6[0x18] = 0;
        puVar6[0x1b] = 0;
        puVar6[0x1a] = 0;
        puVar6[0x1d] = 0;
        puVar6[0x1c] = 0;
        puVar6[0x1f] = 0;
        puVar6[0x1e] = 0;
        puVar6[0x21] = 0;
        puVar6[0x20] = 0;
        puVar6[0x23] = 0;
        puVar6[0x22] = 0;
        puVar6[5] = 0;
        puVar6[4] = 0;
        *(undefined8 *)((long)puVar6 + 0x122) = 0;
        *(undefined8 *)((long)puVar6 + 0x11a) = 0;
        *(undefined4 *)(puVar6 + 0x38) = 0;
        puVar6[0x35] = 0;
        puVar6[0x34] = 0;
        puVar6[0x37] = 0;
        puVar6[0x36] = 0;
        puVar6[0x31] = 0;
        puVar6[0x30] = 0;
        puVar6[0x33] = 0;
        puVar6[0x32] = 0;
        puVar6[0x2d] = 0;
        puVar6[0x2c] = 0;
        puVar6[0x2f] = 0;
        puVar6[0x2e] = 0;
        puVar6[0x2b] = 0;
        puVar6[0x2a] = 0;
        uVar4 = FUN_fffffff0081f70c0(puVar6,puVar8);
        if ((uVar4 & 1) == 0) {
          *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)((long)puVar6 + 0xc);
        }
        else {
          (**(code **)(**(long **)(param_1[0xa6] + 0x4b0) + 0x178))
                    (*(long **)(param_1[0xa6] + 0x4b0),1,*(undefined4 *)((long)param_1 + 0x7ec));
          uVar4 = FUN_fffffff00819164c
                            (param_1,puVar5,puVar6,uStack_d8 & 0xff,uStack_c8,uVar1,uVar2,0);
          if ((uVar4 & 1) == 0) {
            if (((int)param_1[0xa4] == 0x10b) || ((int)param_1[0xa4] == 0x10a)) {
              *(undefined4 *)(param_1 + 0xa4) = 0;
              uVar4 = FUN_fffffff00819164c
                                (param_1,puVar5,puVar6,uStack_d8 & 0xff,uStack_c8,uVar1,uVar2,0);
              if ((uVar4 & 1) != 0) goto LAB_fffffff0081912a8;
            }
            (**(code **)(**(long **)(param_1[0xa6] + 0x4b0) + 0x178))
                      (*(long **)(param_1[0xa6] + 0x4b0),0,*(undefined4 *)((long)param_1 + 0x7ec));
          }
        }
LAB_fffffff0081912a8:
        thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca32e8,puVar6,0x1c8);
        goto LAB_fffffff008191454;
      }
      if (iVar3 == 2) {
        *(int *)(param_1[0xa3] + 0xd0) = *(int *)(param_1[0xa3] + 0xd0) + 1;
        puVar6 = (undefined8 *)thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca3338,0x110);
        *(undefined1 *)(puVar6 + 1) = 0;
        *(undefined4 *)((long)puVar6 + 0xc) = 0;
        *puVar6 = &DAT_fffffff007c95048;
        *(undefined1 *)(puVar6 + 2) = 0;
        puVar6[3] = 0;
        puVar6[5] = 0;
        puVar6[4] = 0;
        puVar6[7] = 0;
        puVar6[6] = 0;
        puVar6[9] = 0;
        puVar6[8] = 0;
        puVar6[0xb] = 0;
        puVar6[10] = 0;
        puVar6[0xd] = 0;
        puVar6[0xc] = 0;
        puVar6[0xf] = 0;
        puVar6[0xe] = 0;
        puVar6[0x11] = 0;
        puVar6[0x10] = 0;
        puVar6[0x13] = 0;
        puVar6[0x12] = 0;
        *(undefined4 *)(puVar6 + 0x14) = 0;
        puVar6[0x16] = 0;
        puVar6[0x15] = 0;
        puVar6[0x18] = 0;
        puVar6[0x17] = 0;
        puVar6[0x1a] = 0;
        puVar6[0x19] = 0;
        puVar6[0x1c] = 0;
        puVar6[0x1b] = 0;
        puVar6[0x1e] = 0;
        puVar6[0x1d] = 0;
        puVar6[0x20] = 0;
        puVar6[0x1f] = 0;
        *(undefined1 *)(puVar6 + 0x21) = 0;
        uVar4 = FUN_fffffff0081a2b80(puVar6,puVar8);
        if ((uVar4 & 1) == 0) {
          *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)((long)puVar6 + 0xc);
        }
        else {
          (**(code **)(**(long **)(param_1[0xa6] + 0x4b0) + 0x178))
                    (*(long **)(param_1[0xa6] + 0x4b0),1,*(undefined4 *)((long)param_1 + 0x7ec));
          uVar4 = FUN_fffffff008191d4c(param_1,puVar5,puVar6,uStack_d8 & 0xff,uStack_c8,uVar1,uVar2)
          ;
          if ((uVar4 & 1) == 0) {
            (**(code **)(**(long **)(param_1[0xa6] + 0x4b0) + 0x178))
                      (*(long **)(param_1[0xa6] + 0x4b0),0,*(undefined4 *)((long)param_1 + 0x7ec));
          }
        }
        thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca3338,puVar6,0x110);
        goto LAB_fffffff008191454;
      }
      if (iVar3 == 3) {
        *(int *)(param_1[0xa3] + 0xcc) = *(int *)(param_1[0xa3] + 0xcc) + 1;
        puVar6 = (undefined8 *)thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca3388,0xa8);
        *(undefined1 *)(puVar6 + 1) = 0;
        *(undefined4 *)((long)puVar6 + 0xc) = 0;
        *puVar6 = &DAT_fffffff007c94020;
        *(undefined1 *)(puVar6 + 2) = 0;
        puVar6[3] = 0;
        puVar6[5] = 0;
        puVar6[4] = 0;
        puVar6[7] = 0;
        puVar6[6] = 0;
        puVar6[9] = 0;
        puVar6[8] = 0;
        puVar6[0xb] = 0;
        puVar6[10] = 0;
        puVar6[0xd] = 0;
        puVar6[0xc] = 0;
        puVar6[0xf] = 0;
        puVar6[0xe] = 0;
        puVar6[0x11] = 0;
        puVar6[0x10] = 0;
        puVar6[0x13] = 0;
        puVar6[0x12] = 0;
        *(undefined8 *)((long)puVar6 + 0x9d) = 0;
        uVar4 = FUN_fffffff00819c940(puVar6,puVar8);
        if ((uVar4 & 1) == 0) {
          *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)((long)puVar6 + 0xc);
        }
        else {
          (**(code **)(**(long **)(param_1[0xa6] + 0x4b0) + 0x178))
                    (*(long **)(param_1[0xa6] + 0x4b0),1,*(undefined4 *)((long)param_1 + 0x7ec));
          uVar4 = FUN_fffffff0081920f4
                            (param_1,puVar5,puVar6,uStack_d8 & 0xff,uStack_c8,uVar1,uVar2,0);
          if ((uVar4 & 1) == 0) {
            (**(code **)(**(long **)(param_1[0xa6] + 0x4b0) + 0x178))
                      (*(long **)(param_1[0xa6] + 0x4b0),0,*(undefined4 *)((long)param_1 + 0x7ec));
          }
        }
        thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca3388,puVar6,0xa8);
        goto LAB_fffffff008191454;
      }
    }
    else {
      if (iVar3 == 5) {
        *(int *)(param_1[0xa3] + 0xd0) = *(int *)(param_1[0xa3] + 0xd0) + 1;
        *(undefined1 *)((long)param_1 + 0x8dc) = 1;
        FUN_fffffff00819233c(param_1,puVar8,&uStack_c0,puVar5,&puStack_e0,uVar1,uVar2);
        *(undefined1 *)((long)param_1 + 0x8dc) = 0;
        goto LAB_fffffff008191454;
      }
      if (iVar3 == 6) {
        puStack_80 = &DAT_fffffff007c9f130;
        uStack_78 = 0;
        uStack_68 = 0;
        uStack_70 = 0;
        uStack_58 = 0;
        uStack_60 = 0;
        uVar4 = FUN_fffffff00820236c(&puStack_80,&puStack_80,puVar8);
        if ((uVar4 & 1) != 0) {
          FUN_fffffff008193828(param_1,puVar5,&puStack_80);
          goto LAB_fffffff008191454;
        }
        uVar7 = uStack_78._4_4_;
        goto LAB_fffffff008191304;
      }
      if (iVar3 == 7) {
        *(int *)(param_1[0xa3] + 0xd0) = *(int *)(param_1[0xa3] + 0xd0) + 1;
        FUN_fffffff00819338c(param_1,puVar8,&uStack_c0,puVar5,&puStack_e0,uVar1,uVar2);
        goto LAB_fffffff008191454;
      }
    }
    uVar7 = 0x106;
  }
LAB_fffffff008191304:
  *(undefined4 *)(param_1 + 0xa4) = uVar7;
LAB_fffffff008191454:
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca3298,puVar5,0x178);
  return;
}

