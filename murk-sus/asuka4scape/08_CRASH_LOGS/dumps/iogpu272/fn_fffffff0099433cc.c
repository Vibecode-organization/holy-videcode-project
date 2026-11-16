// FUN_fffffff0099433cc @ fffffff0099433cc size=588

undefined8 FUN_fffffff0099433cc(long *param_1,int param_2,ulong param_3,ulong param_4)

{
  int *piVar1;
  uint *puVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  ulong uVar7;
  
  thunk_EXT_FUN_80110000032222a8(param_1[9]);
  if ((*(byte *)(param_1 + 6) >> 4 & 1) == 0) {
    uVar5 = *(uint *)((long)param_1 + 0x24);
    if ((uVar5 & 1) == 0) {
      uVar6 = (**(code **)(*param_1 + 0xd8))(param_1,param_4);
      if ((int)uVar6 != -0x1ffffd28) {
        if ((int)uVar6 == 0) {
LAB_fffffff009943454:
          if (((param_3 & 1) != 0) || (param_2 == *(int *)(*(long *)(param_1[2] + 0x160) + 0x158)))
          {
            uVar7 = param_4 & (param_1[5] ^ 0xffffffffffffffffU);
            if (uVar7 == 0) {
              lVar3 = DAT_fffffff00af21d38 + 1;
              param_1[8] = DAT_fffffff00af21d38;
              DAT_fffffff00af21d38 = lVar3;
            }
            else {
              uVar6 = (**(code **)(*param_1 + 0xf0))(param_1,uVar7);
              if (((uVar5 >> 1 & 1) == 0) && ((int)uVar6 != 0)) goto LAB_fffffff009943560;
              lVar3 = DAT_fffffff00af21d38 + 1;
              param_1[8] = DAT_fffffff00af21d38;
              DAT_fffffff00af21d38 = lVar3;
              if ((int)uVar6 != 0) goto LAB_fffffff009943598;
            }
            uVar6 = 0;
            param_1[5] = param_1[5] | param_4;
            LORelease();
            puVar2 = (uint *)((long)param_1 + 0x24);
            uVar5 = *puVar2;
            *puVar2 = uVar5 | 3;
            uVar7 = CONCAT44((int)((ulong)puVar2 >> 0x20),uVar5);
            LORelease();
            goto LAB_fffffff0099435a4;
          }
          uVar6 = 0xe00002d8;
          if ((uVar5 >> 1 & 1) == 0) {
LAB_fffffff009943560:
            (**(code **)(*param_1 + 0xd0))(param_1);
          }
        }
        else if ((*(byte *)(param_1 + 6) >> 2 & 1) == 0) {
          uVar6 = FUN_fffffff009961750(*(undefined8 *)(param_1[2] + 0x160),param_1);
          if ((int)uVar6 == 0) goto LAB_fffffff009943454;
        }
        else {
          uVar6 = 0xe00002bd;
        }
      }
      lVar3 = DAT_fffffff00af21d38 + 1;
      param_1[8] = DAT_fffffff00af21d38;
      DAT_fffffff00af21d38 = lVar3;
    }
    else {
      uVar7 = param_1[5];
      if ((uVar7 & param_4) != 0) {
        uVar6 = 0;
        goto LAB_fffffff0099435a4;
      }
      uVar6 = (**(code **)(*param_1 + 0xf0))(param_1,param_4 & (uVar7 ^ 0xffffffffffffffff));
      if ((int)uVar6 == 0) {
        uVar7 = param_1[5];
        param_1[5] = uVar7 | param_4;
        LORelease();
        goto LAB_fffffff0099435a4;
      }
    }
  }
  else {
    uVar6 = 0xe00002bd;
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Attempting to prepare detached resource\n");
  }
LAB_fffffff009943598:
  piVar1 = (int *)((long)param_1 + 0x24);
  iVar4 = *piVar1;
  *piVar1 = iVar4 + -4;
  uVar7 = CONCAT44((int)((ulong)piVar1 >> 0x20),iVar4);
LAB_fffffff0099435a4:
  thunk_EXT_FUN_8011000003222de0(uVar7,param_1[9]);
  return uVar6;
}

