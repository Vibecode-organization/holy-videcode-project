// FUN_fffffff009c27118 @ fffffff009c27118 size=1540

undefined8
FUN_fffffff009c27118
          (long param_1,long *param_2,undefined8 *param_3,uint param_4,undefined4 param_5,
          long param_6,long param_7,long param_8,uint param_9)

{
  undefined4 uVar1;
  bool bVar2;
  code *pcVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  long *plVar9;
  long lVar10;
  undefined8 uVar11;
  long *plVar12;
  long lVar13;
  uint uVar14;
  undefined8 local_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar5 = (long *)(**(code **)(*DAT_fffffff00806a150 + 0x68))();
  if (plVar5 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
               "IOSurface::createWriteFence: WARNING: IOFence new failure!\n");
    uVar11 = 0;
    goto LAB_fffffff009c276a8;
  }
  (**(code **)(*plVar5 + 0x68))();
  if ((*(byte *)(param_1 + 0x3d2) >> 5 & 1) == 0) {
    FUN_fffffff009c22ee0(param_1,0);
  }
  FUN_fffffff009c16670(plVar5 + 2,param_1);
  *(undefined4 *)(plVar5 + 4) = param_5;
  *(uint *)((long)plVar5 + 0x24) = param_4;
  plVar5[5] = param_6;
  plVar5[6] = param_7;
  plVar5[7] = param_8;
  *(undefined2 *)(plVar5 + 10) = 0;
  *(undefined4 *)((long)plVar5 + 0x4c) = 0;
  lVar6 = thunk_EXT_FUN_8011000003397c88();
  plVar5[0x12] = lVar6;
  FUN_fffffff009c16670(plVar5 + 3,param_2);
  thunk_EXT_FUN_80110000038909d8(plVar5 + 0x13,8);
  if ((param_9 >> 2 & 1) != 0) {
    *(undefined1 *)((long)plVar5 + 0x52) = 1;
  }
  plVar12 = plVar5 + 0xb;
  *plVar12 = 0;
  plVar5[0xc] = 0;
  plVar5[0xd] = 0;
  plVar5[0xe] = 0;
  plVar5[0xf] = 0;
  plVar5[0x10] = 0;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  if (param_2 != (long *)0x0) {
    FUN_fffffff009c1946c(param_2,plVar5);
  }
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  local_70 = 0;
  thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x30),&local_70);
  uVar7 = thunk_EXT_FUN_80110000036da494(0x85210000,param_5,uVar1,param_4,local_70,0);
  if ((param_9 & 1) != 0) {
    *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | 0x2000;
  }
  lVar6 = *(long *)(param_1 + 0x240);
  lVar10 = lVar6;
  if (lVar6 == 0) {
    lVar10 = 0;
  }
  else {
    do {
      if (*(int *)(lVar10 + 0x4c) == 0) break;
      lVar10 = *(long *)(lVar10 + 0x58);
    } while (lVar10 != 0);
  }
  lVar13 = *(long *)(param_1 + 0x250);
  for (lVar8 = lVar13; lVar8 != 0; lVar8 = *(long *)(lVar8 + 0x58)) {
    if (*(int *)(lVar8 + 0x4c) == 0) {
      if (lVar10 != 0) {
        bVar2 = true;
        goto LAB_fffffff009c27344;
      }
      uVar14 = *(uint *)(param_1 + 0x3d0) & 0x2000;
      bVar2 = true;
      goto LAB_fffffff009c273a8;
    }
  }
  if ((lVar10 != 0) && (lVar8 = lVar6, lVar6 != 0)) {
LAB_fffffff009c27310:
    uVar7 = FUN_fffffff009c26af8(uVar7,plVar5,lVar8,1);
    if ((uVar7 & 1) != 0) goto code_r0xfffffff009c27324;
    bVar2 = false;
    lVar8 = 0;
LAB_fffffff009c27344:
    uVar14 = *(uint *)(param_1 + 0x3d0) & 0x2000;
    if ((((param_4 >> 1 & 1) != 0) && (uVar14 != 0)) && ((*(byte *)(lVar10 + 0x24) & 1) != 0)) {
      while (lVar6 != 0) {
        lVar10 = *(long *)(lVar6 + 0x58);
        FUN_fffffff009c41358(lVar6,0);
        lVar6 = lVar10;
      }
      goto LAB_fffffff009c27464;
    }
    if ((((param_4 & 1) != 0) && (uVar14 != 0)) &&
       (uVar14 = 1, (*(byte *)(lVar10 + 0x24) >> 1 & 1) != 0)) {
      FUN_fffffff009c41358(plVar5,0);
      plVar5[0xb] = 0;
      plVar9 = *(long **)(param_1 + 0x248);
      plVar5[0xc] = (long)plVar9;
      *plVar9 = (long)plVar5;
      *(long **)(param_1 + 0x248) = plVar12;
      goto LAB_fffffff009c2747c;
    }
LAB_fffffff009c273a8:
    if ((((param_4 & 2) != 0) && (bVar2)) && ((uVar14 != 0 && ((*(byte *)(lVar8 + 0x24) & 1) != 0)))
       ) {
      while (lVar13 != 0) {
        lVar6 = *(long *)(lVar13 + 0x58);
        FUN_fffffff009c41358(lVar13,0);
        lVar13 = lVar6;
      }
    }
    if ((param_9 >> 1 & 1) == 0) {
      thunk_EXT_FUN_80110000036da494(0x85210004,param_5,*(undefined4 *)(param_1 + 0x10),param_4,0,0)
      ;
      bVar2 = false;
      plVar5[0xb] = 0;
      plVar9 = *(long **)(param_1 + 600);
      plVar5[0xc] = (long)plVar9;
      *plVar9 = (long)plVar5;
      *(long **)(param_1 + 600) = plVar12;
    }
    else {
      *(undefined4 *)((long)plVar5 + 0x4c) = 1;
      (**(code **)(*plVar5 + 0x28))(plVar5);
      plVar5 = (long *)0x0;
      bVar2 = false;
    }
    goto LAB_fffffff009c2748c;
  }
LAB_fffffff009c27464:
  plVar5[0xb] = 0;
  plVar9 = *(long **)(param_1 + 0x248);
  plVar5[0xc] = (long)plVar9;
  *plVar9 = (long)plVar5;
  *(long **)(param_1 + 0x248) = plVar12;
LAB_fffffff009c2747c:
  bVar2 = true;
  *(undefined1 *)((long)plVar5 + 0x53) = 1;
  FUN_fffffff009c26bc4(param_1,plVar5);
LAB_fffffff009c2748c:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  if ((((param_9 >> 1 & 1) != 0) || (param_6 != 0)) || (bVar2)) {
    if (bVar2) goto LAB_fffffff009c274f0;
joined_r0xfffffff009c27530:
    if (((param_2 != (long *)0x0) &&
        (iVar4 = FUN_fffffff009c37a94(DAT_fffffff00af483b0), iVar4 != 0)) &&
       ((iVar4 = FUN_fffffff009c19b40(param_2,param_2,0,0), iVar4 != 0 &&
        (iVar4 = FUN_fffffff009c31488(0x400), iVar4 != 0)))) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,"Breaking IOFence deadlock\n");
      thunk_EXT_FUN_801100000322ffdc("Breaking IOFence deadlock\n");
      FUN_fffffff009c41314(plVar5,0);
    }
    uVar11 = 0;
  }
  else {
    iVar4 = FUN_fffffff009c37158(DAT_fffffff00af483b0,plVar5);
    if (iVar4 != 0) {
      if (iVar4 == -0x1ffffd2a) {
        FUN_fffffff009c27858(param_1);
      }
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
      if ((*(byte *)((long)plVar5 + 0x51) & 1) == 0) {
        lVar6 = plVar5[0xb];
        if (lVar6 == 0) {
          plVar12 = (long *)plVar5[0xc];
          if ((long *)*plVar12 != plVar5) goto LAB_fffffff009c27708;
          *(long **)(param_1 + 600) = plVar12;
        }
        else {
          if (*(long **)(lVar6 + 0x60) != plVar5 + 0xb) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c27718);
            (*pcVar3)();
          }
          if (*(long **)plVar5[0xc] != plVar5) {
LAB_fffffff009c27708:
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c27710);
            (*pcVar3)();
          }
          *(long **)(lVar6 + 0x60) = (long *)plVar5[0xc];
          plVar12 = (long *)plVar5[0xc];
        }
        *plVar12 = lVar6;
        *(undefined4 *)((long)plVar5 + 0x4c) = 1;
        (**(code **)(*plVar5 + 0x28))(plVar5);
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
        plVar5 = (long *)0x0;
        goto joined_r0xfffffff009c27530;
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
    }
LAB_fffffff009c274f0:
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    local_70 = 0;
    thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x30),&local_70);
    thunk_EXT_FUN_80110000036da494(0x85210008,param_5,uVar1,param_4,local_70,0);
    uVar11 = 1;
  }
  plVar12 = (long *)*param_3;
  *param_3 = plVar5;
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x20))(plVar5);
  }
  if (plVar12 != (long *)0x0) {
    (**(code **)(*plVar12 + 0x28))(plVar12);
  }
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
LAB_fffffff009c276a8:
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_68) {
    return uVar11;
  }
  uVar11 = thunk_EXT_FUN_8011000003a48590();
  return uVar11;
code_r0xfffffff009c27324:
  lVar8 = *(long *)(lVar8 + 0x58);
  if (lVar8 == 0) goto LAB_fffffff009c27464;
  goto LAB_fffffff009c27310;
}

