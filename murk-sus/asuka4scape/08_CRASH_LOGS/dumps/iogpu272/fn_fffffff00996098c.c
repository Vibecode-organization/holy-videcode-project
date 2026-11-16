// FUN_fffffff00996098c @ fffffff00996098c size=2040

void FUN_fffffff00996098c(long param_1,long *param_2)

{
  int *piVar1;
  byte bVar2;
  undefined4 uVar3;
  byte bVar4;
  bool bVar5;
  byte bVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 in_x6;
  undefined8 in_x7;
  ulong uVar13;
  long lVar14;
  long lVar15;
  long *plVar16;
  undefined *local_a8;
  undefined8 local_a0;
  code *local_98;
  undefined *local_90;
  long lStack_88;
  long *local_80;
  int local_78;
  
  bVar4 = *(byte *)(param_1 + 0x195);
  (**(code **)(*param_2 + 0x20))(param_2);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x150));
  if ((bVar4 & 1) != 0) {
    piVar1 = (int *)(param_1 + 0x198);
    *piVar1 = *piVar1 + 1;
    if (DAT_fffffff00af227e8 != 0) {
      uVar11 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x1a8));
      thunk_EXT_FUN_80110000036da494(0x851801c0,uVar11,param_2[0x19],*piVar1,1,0);
    }
  }
  uVar13 = (ulong)param_2 & 0xffffffffffff | 0xcda1000000000000;
  if (((*(byte *)((long)param_2 + 99) & 1) == 0) && (*(int *)(param_1 + 0x198) == 0)) {
    bVar7 = false;
  }
  else {
    thunk_EXT_FUN_8011000003224180(*(undefined8 *)(param_1 + 0x208));
    bVar7 = true;
  }
  FUN_fffffff0099611ac(param_1,param_2,0);
  uVar11 = DAT_fffffff007835cd0;
  bVar5 = false;
  bVar6 = bVar4;
LAB_fffffff009960aa4:
  do {
    while( true ) {
      while (iVar8 = (int)param_2[0xd], iVar8 == 1) {
        if (DAT_fffffff00af227e8 != 0) {
          uVar12 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x1a8));
          thunk_EXT_FUN_80110000036da494(0x851801bc,uVar12,param_2[0x19],1,0,0,in_x6,in_x7,uVar13);
        }
        iVar8 = thunk_EXT_FUN_80110000038ff064
                          (*(undefined8 *)(param_1 + 0x150),param_2,
                           (*(byte *)((long)param_2 + 0x65) ^ 0xff) & 1);
        if (iVar8 == 2) {
          FUN_fffffff00995d140(param_2,0,0x13,1);
        }
      }
      if (iVar8 == 3) break;
      if (iVar8 == 0) {
        if ((bVar4 & 1) != 0) {
          *(int *)(param_1 + 0x198) = *(int *)(param_1 + 0x198) + -1;
        }
        if (bVar7) {
          thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(param_1 + 0x208));
        }
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x150));
        (**(code **)(*param_2 + 0x28))(param_2);
        return;
      }
    }
    *(undefined1 *)((long)param_2 + 0x61) = 1;
    if (DAT_fffffff00af227e8 != 0) {
      uVar12 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x1a8));
      thunk_EXT_FUN_80110000036da494(0x85180144,uVar12,param_2[0x19],3,0,0,in_x6,in_x7,uVar13);
    }
    if (*(long **)(param_1 + 0x140) == param_2) {
      if ((bVar6 & 1) != 0) goto LAB_fffffff009960b88;
    }
    else if (*(int *)(param_1 + 0x198) != 0 || (bVar6 & 1) != 0) {
LAB_fffffff009960b88:
      if (((*(byte *)((long)param_2 + 100) & 1) == 0) &&
         ((*(byte *)((long)param_2 + 0x65) & 1) == 0)) {
        if (!bVar5) {
          *(int *)(param_1 + 0x198) = *(int *)(param_1 + 0x198) + 1;
        }
        if (*(int *)(param_1 + 0x19c) == 0) {
          bVar2 = *(byte *)(param_1 + 0x191);
          if (*(long *)(param_1 + 0x180) != *(long *)(param_1 + 0x188)) {
            *(long *)(param_1 + 0x188) = *(long *)(param_1 + 0x180);
            plVar16 = *(long **)(param_1 + 0x140);
            if (plVar16 != param_2) {
LAB_fffffff0099610b8:
              thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0x150),plVar16,1);
              if (DAT_fffffff00af227e8 != 0) {
                uVar12 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x1a8));
                thunk_EXT_FUN_80110000036da494(0x85180140,uVar12,plVar16[0x19],3,0,0);
              }
              goto LAB_fffffff009960d1c;
            }
            bVar6 = 0;
            *(undefined1 *)((long)param_2 + 0x61) = 0;
            bVar5 = true;
            goto LAB_fffffff009960aa4;
          }
          plVar16 = *(long **)(param_1 + 0x140);
          if (plVar16 != param_2) goto LAB_fffffff0099610b8;
          bVar6 = 0;
          *(undefined1 *)((long)param_2 + 0x61) = 0;
          bVar5 = true;
          if ((bVar2 & 1) != 0) goto LAB_fffffff009960aa4;
        }
        else {
LAB_fffffff009960d1c:
          *(undefined1 *)((long)param_2 + 0x61) = 0;
        }
        if (DAT_fffffff00af227e8 != 0) {
          uVar12 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x1a8));
          thunk_EXT_FUN_80110000036da494(0x851801bc,uVar12,param_2[0x19],3,0,0);
        }
        FUN_fffffff009975c34(*(undefined8 *)(param_1 + 0x1a8),0x1000000);
        bVar5 = true;
        iVar8 = thunk_EXT_FUN_80110000038ff064(*(undefined8 *)(param_1 + 0x150),param_2,1);
        FUN_fffffff009975c44(*(undefined8 *)(param_1 + 0x1a8),0x1000000);
        bVar6 = 0;
        if (iVar8 == 2) {
          FUN_fffffff00995d140(param_2,0,0x13,1);
          bVar6 = 0;
        }
        goto LAB_fffffff009960aa4;
      }
    }
    uVar3 = *(undefined4 *)(param_1 + 0x158);
    bVar2 = *(byte *)(param_1 + 0x191);
    iVar8 = *(int *)(param_1 + 0x19c);
    *(int *)(param_1 + 0x19c) = iVar8 + 1;
    iVar9 = *(int *)(param_1 + 0x1a0);
    *(int *)(param_1 + 0x1a0) = iVar9 + 1;
    LORelease();
    if ((((*(byte *)((long)param_2 + 99) & 1) != 0) || (*(int *)(param_1 + 0x198) != 0)) && (!bVar7)
       ) {
      thunk_EXT_FUN_8011000003224180(*(undefined8 *)(param_1 + 0x208));
      bVar7 = true;
    }
    *(undefined1 *)((long)param_2 + 100) = 0;
    iVar10 = FUN_fffffff00995ddac(param_2);
    if ((iVar10 != 0) && ((*(byte *)((long)param_2 + 0x65) & 1) == 0)) {
      FUN_fffffff00995d140(param_2,0,0x13,1);
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x150));
    iVar10 = FUN_fffffff00995cc74(param_2,uVar3,bVar2 & 1);
    if (iVar10 == -0x1ffffd28) {
LAB_fffffff009960c64:
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x150));
      if ((((iVar10 == -0x1ffffd42) &&
           ((bool)((*(int *)(param_1 + 0x1a0) == iVar9 + 1 && iVar8 == 0) & bVar5))) &&
          ((bVar2 & 1) != 0)) &&
         ((iVar10 = FUN_fffffff00995d140(param_2,1,8,0), iVar10 == -0x1ffffd15 || (iVar10 == 0)))) {
        iVar10 = -0x1ffffd43;
LAB_fffffff009960e30:
        bVar5 = true;
      }
      else if ((iVar10 == -0x1ffffd28) || (iVar10 == -0x1ffffd42)) {
        *(int *)(param_1 + 0x19c) = *(int *)(param_1 + 0x19c) + -1;
        if (bVar5) {
          bVar6 = 1;
        }
        else {
          iVar8 = *(int *)(param_1 + 0x198);
          *(int *)(param_1 + 0x198) = iVar8 + 1;
          if (iVar8 == 0) {
            DataMemoryBarrier(2,3);
          }
          if (DAT_fffffff00af227e8 != 0) {
            uVar12 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x1a8));
            thunk_EXT_FUN_80110000036da494
                      (0x851801c0,uVar12,param_2[0x19],*(undefined4 *)(param_1 + 0x198),bVar4 & 1,0)
            ;
          }
        }
        goto LAB_fffffff009960e30;
      }
      plVar16 = *(long **)(param_1 + 0x140);
      if (plVar16 == param_2) {
        *(int *)(param_1 + 0x158) = *(int *)(param_1 + 0x158) + 1;
      }
      else {
        thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0x150),plVar16,1);
        if (DAT_fffffff00af227e8 != 0) {
          uVar12 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x1a8));
          thunk_EXT_FUN_80110000036da494(0x85180140,uVar12,plVar16[0x19],1,0,0);
        }
      }
      if (iVar10 == -0x1ffffd43) {
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x150));
        iVar10 = -0x1ffffd43;
LAB_fffffff009960ed8:
        FUN_fffffff00995d1f8(param_2);
      }
      else {
LAB_fffffff009960eb4:
        if (iVar10 == -0x1ffffd43) goto LAB_fffffff009960ed8;
        if (iVar10 != 0) {
          if (iVar10 == -0x1ffffd15) goto LAB_fffffff009960ed8;
          goto LAB_fffffff009960aa4;
        }
      }
      if (DAT_fffffff00af227e8 != 0) {
        uVar12 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x1a8));
        thunk_EXT_FUN_80110000036da494(0x85180149,uVar12,param_2[0x19],0,0,0);
      }
      local_a8 = PTR_DAT_fffffff007ff2748;
      local_a0 = uVar11;
      local_98 = FUN_fffffff009961430;
      local_90 = &DAT_fffffff007fecfa0;
      lStack_88 = param_1;
      local_80 = param_2;
      local_78 = iVar10;
      iVar8 = thunk_EXT_FUN_801100000395c120(&local_90,*(undefined8 *)(param_1 + 0x28),&local_a8);
      if (DAT_fffffff00af227e8 != 0) {
        uVar12 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x1a8));
        thunk_EXT_FUN_80110000036da494(0x8518014a,uVar12,param_2[0x19],(long)iVar8,0,0);
      }
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x150));
      FUN_fffffff0099611ac(param_1,param_2,1);
      if (bVar5) {
        *(int *)(param_1 + 0x198) = *(int *)(param_1 + 0x198) + -1;
      }
      *(int *)(param_1 + 0x19c) = *(int *)(param_1 + 0x19c) + -1;
      if (iVar8 == 0) {
        lVar15 = *(long *)(param_1 + 0x130);
        while (lVar15 != 0) {
          lVar14 = *(long *)(lVar15 + 0x20);
          FUN_fffffff0099611ac(param_1,lVar15,0);
          lVar15 = lVar14;
        }
      }
      bVar5 = false;
      *(undefined1 *)((long)param_2 + 0x61) = 0;
      if (*(int *)(param_1 + 0x198) != 0) {
        bVar5 = false;
        lVar15 = *(long *)(param_1 + 0x140);
        if (lVar15 != 0) {
          thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0x150),lVar15,1);
          bVar5 = false;
          if (DAT_fffffff00af227e8 != 0) {
            uVar12 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x1a8));
            thunk_EXT_FUN_80110000036da494(0x85180140,uVar12,*(undefined8 *)(lVar15 + 200),2,0,0);
            bVar5 = false;
          }
        }
      }
      goto LAB_fffffff009960aa4;
    }
    if (iVar10 != -0x1ffffd2b) {
      if (iVar10 == -0x1ffffd42) goto LAB_fffffff009960c64;
      goto LAB_fffffff009960eb4;
    }
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x150));
    *(int *)(param_1 + 0x19c) = *(int *)(param_1 + 0x19c) + -1;
    *(undefined1 *)((long)param_2 + 0x61) = 0;
  } while( true );
}

