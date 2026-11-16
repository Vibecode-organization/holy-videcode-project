// FUN_fffffff0081fdf54 @ fffffff0081fdf54 size=1736

undefined8
FUN_fffffff0081fdf54(long *param_1,long param_2,undefined8 param_3,undefined8 param_4,uint param_5)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  long *plVar8;
  long *plVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  uint uVar13;
  long lVar14;
  ulong unaff_x30;
  
  iVar5 = FUN_fffffff0081e6c88();
  if (iVar5 == 0) {
    return 0;
  }
  *(undefined4 *)((long)param_1 + 0x274) = 0;
  param_1[0x5f] = 0;
  lVar11 = 2;
  lVar12 = 1;
  do {
    lVar14 = lVar11 + -1;
    uVar13 = (uint)lVar14;
    if (0xd < uVar13 || (1 << (ulong)(uVar13 & 0x1f) & 0x2041U) == 0) {
      if ((1 << (ulong)(uVar13 & 0x1f) & 0x5f80U) == 0) {
        uVar7 = *(ulong *)(&UNK_fffffff007115150 + lVar12 * 0x20);
        uVar10 = *(ulong *)(&DAT_fffffff007115148 + lVar12 * 0x20) >>
                 ((ulong)DAT_fffffff00ae2181c & 0x3f);
        plVar9 = (long *)thunk_EXT_FUN_801100000397b408
                                   ((uVar7 >> ((ulong)DAT_fffffff00ae2181c & 0x3f)) + uVar10 + -1,0,
                                    0,0);
        param_1[lVar12 + 0x3e] = (long)plVar9;
        if ((plVar9 == (long *)0x0) ||
           (iVar5 = (**(code **)(*plVar9 + 0xb8))(plVar9,0,uVar10), iVar5 == 0))
        goto LAB_fffffff0081fe1d4;
      }
      else {
        thunk_EXT_FUN_80110000032222a8(DAT_fffffff00ae23bd0);
        *(undefined1 *)(param_1 + 0x54) = 1;
        uVar13 = (-1 << (ulong)(uVar13 & 0x1f) ^ 0xffffffffU) & 0x5f80;
        plVar9 = (long *)(&DAT_fffffff00ae23b98)
                         [(byte)(POPCOUNT((char)uVar13) + POPCOUNT((char)(uVar13 >> 8)))];
        (**(code **)(*plVar9 + 0x20))(plVar9);
        if ((*(byte *)(param_1 + 0x54) & 1) != 0) {
          *(undefined1 *)(param_1 + 0x54) = 0;
          thunk_EXT_FUN_8011000003222de0(DAT_fffffff00ae23bd0);
        }
        param_1[lVar12 + 0x3e] = (long)plVar9;
        uVar7 = *(ulong *)(&UNK_fffffff007115150 + lVar12 * 0x20);
      }
      param_1[lVar12 + 7] = uVar7;
      param_1[lVar12 + 0x17] = 0;
    }
    lVar12 = lVar12 + 1;
    lVar11 = lVar11 + 1;
  } while (lVar11 != 0x10);
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(param_2 + 0x11a70));
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(param_2 + 0x11a78));
  if (*(int *)(param_2 + 0x11a68) != 0) {
    FUN_fffffff0081fe61c(param_2);
    uVar6 = thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! AGXSecureGart::init\n");
    return uVar6;
  }
  if (param_5 == 0) {
    lVar12 = param_1[5];
    plVar9 = (long *)(**(code **)(DAT_fffffff00ae25900 + 0x68))();
    if (plVar9 != (long *)0x0) {
      iVar5 = (**(code **)(*plVar9 + 0x68))();
      if (iVar5 != 0) {
        plVar9[2] = 0;
        plVar9[3] = 0;
        if ((DAT_fffffff00ae25928 & 1) == 0) {
          lVar12 = FUN_fffffff00820ef68(lVar12,param_2);
          plVar9[3] = lVar12;
          lVar12 = plVar9[2];
        }
        else {
          lVar12 = thunk_EXT_FUN_80110000039e860c(lVar12,param_2);
          plVar9[2] = lVar12;
        }
        plVar8 = plVar9;
        if (lVar12 == 0) {
          lVar12 = plVar9[3];
          goto joined_r0xfffffff0081fe2f0;
        }
        goto LAB_fffffff0081fe2f4;
      }
      goto LAB_fffffff0081fe590;
    }
LAB_fffffff0081fe614:
    plVar8 = (long *)0x0;
  }
  else {
    plVar9 = (long *)(**(code **)(DAT_fffffff00ae25900 + 0x68))();
    if (plVar9 == (long *)0x0) goto LAB_fffffff0081fe614;
    iVar5 = (**(code **)(*plVar9 + 0x68))();
    if (iVar5 == 0) {
LAB_fffffff0081fe590:
      plVar8 = (long *)0x0;
    }
    else {
      plVar9[2] = 0;
      plVar9[3] = 0;
      if ((DAT_fffffff00ae25928 & 1) == 0) {
        lVar12 = FUN_fffffff00820f51c(param_2);
        plVar9[3] = lVar12;
        lVar12 = plVar9[2];
      }
      else {
        lVar12 = thunk_EXT_FUN_80110000039ea074();
        plVar9[2] = lVar12;
      }
      plVar8 = plVar9;
      if (lVar12 == 0) {
        lVar12 = plVar9[3];
joined_r0xfffffff0081fe2f0:
        plVar8 = plVar9;
        if (lVar12 == 0) goto LAB_fffffff0081fe590;
      }
LAB_fffffff0081fe2f4:
      (**(code **)(*plVar8 + 0x20))(plVar8);
      plVar9 = plVar8;
    }
    (**(code **)(*plVar9 + 0x28))(plVar9);
  }
  param_1[0x5a] = (long)plVar8;
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(param_2 + 0x11a78));
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(param_2 + 0x11a70));
  puVar3 = PTR_DAT_fffffff007ca61d0;
  if (plVar8 == (long *)0x0) {
    return 0;
  }
  if (((param_5 & 1) == 0) && (param_1[5] == *(long *)PTR_DAT_fffffff007ca61d0)) {
    DAT_fffffff00ae23b30 = thunk_EXT_FUN_80110000038ff010();
    if (DAT_fffffff00ae23b30 == 0) {
      return 0;
    }
    iVar5 = (**(code **)(*(long *)param_1[2] + 0x778))();
    DAT_fffffff00ae23b40 = iVar5 + 1;
    uVar7 = -(ulong)(DAT_fffffff00ae23b40 >> 0x1f) & 0xfffffff800000000 |
            (ulong)DAT_fffffff00ae23b40 << 3;
    if (iVar5 < -1) {
      uVar7 = 0x8000000000000000;
    }
    DAT_fffffff00ae23b38 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4a58,uVar7);
    if (DAT_fffffff00ae23b38 == 0) {
      return 0;
    }
    if (0 < (int)DAT_fffffff00ae23b40) {
      uVar7 = 0;
      do {
        lVar11 = thunk_EXT_FUN_80110000038ff010();
        lVar12 = DAT_fffffff00ae23b38;
        *(long *)(DAT_fffffff00ae23b38 + uVar7 * 8) = lVar11;
        if (lVar11 == 0) break;
        uVar7 = uVar7 + 1;
      } while ((long)uVar7 < (long)(int)DAT_fffffff00ae23b40);
      if ((int)uVar7 < (int)DAT_fffffff00ae23b40) {
        if (0 < (int)uVar7) {
          uVar10 = uVar7 & 0x7fffffff;
          uVar7 = uVar7 + 1;
          do {
            uVar10 = uVar10 - 1;
            thunk_EXT_FUN_80110000038ff020(*(undefined8 *)(lVar12 + uVar10 * 8));
            lVar12 = DAT_fffffff00ae23b38;
            *(undefined8 *)(DAT_fffffff00ae23b38 + uVar10 * 8) = 0;
            uVar7 = uVar7 - 1;
          } while (1 < uVar7);
        }
        uVar7 = -(ulong)(DAT_fffffff00ae23b40 >> 0x1f) & 0xfffffff800000000 |
                (ulong)DAT_fffffff00ae23b40 << 3;
        if (0x7fffffff < DAT_fffffff00ae23b40) {
          uVar7 = 0x8000000000000000;
        }
        DAT_fffffff00ae23b38 = 0;
        thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4aa8,lVar12,uVar7);
        DAT_fffffff00ae23b38 = 0;
        DAT_fffffff00ae23b40 = 0;
        return 0;
      }
    }
  }
  puVar2 = PTR_DAT_fffffff007ca5f88;
  if (((*(byte *)(param_1[2] + 0x5cc) >> 4 & 1) != 0) && (param_1[5] != *(long *)puVar3)) {
    lVar12 = (long)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f));
    lVar12 = thunk_EXT_FUN_8011000003962900
                       (param_1[5],*(uint *)(param_1[2] + 0x18b70) | 99,lVar12,lVar12);
    param_1[0x55] = lVar12;
    if (lVar12 != 0) {
      param_1[0x56] = 0x6fffff8000;
      iVar5 = (**(code **)(*param_1 + 0x98))
                        (param_1,5,0x6fffff8000,(long)(1 << (ulong)(*(uint *)puVar2 & 0x1f)));
      if ((iVar5 != 0) &&
         (iVar5 = (**(code **)(*(long *)param_1[0x55] + 0xd8))((long *)param_1[0x55],0), iVar5 == 0)
         ) goto LAB_fffffff0081fe530;
      if ((long *)param_1[0x55] != (long *)0x0) {
        (**(code **)(*(long *)param_1[0x55] + 0x28))();
      }
      param_1[0x55] = 0;
    }
    return 0;
  }
LAB_fffffff0081fe530:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081fe58c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar6 = (**(code **)(*param_1 + 0x188))(param_1,(undefined8 *)(*param_1 + 0x188));
    return uVar6;
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081fe584);
  (*pcVar4)();
LAB_fffffff0081fe1d4:
  plVar9 = (long *)param_1[lVar14 + 0x3e];
  if (plVar9 != (long *)0x0) {
    if ((1 << (ulong)((int)lVar11 - 1U & 0x1f) & 0x5f80U) == 0) {
LAB_fffffff0081fe204:
      (**(code **)(*plVar9 + 0x28))();
      bVar1 = *(byte *)(param_1 + 0x54);
      param_1[lVar14 + 0x3e] = 0;
      if ((bVar1 & 1) == 0) goto LAB_fffffff0081fe1c4;
    }
    else {
      thunk_EXT_FUN_80110000032222a8(DAT_fffffff00ae23bd0);
      *(undefined1 *)(param_1 + 0x54) = 1;
      plVar9 = (long *)param_1[lVar14 + 0x3e];
      if (plVar9 != (long *)0x0) goto LAB_fffffff0081fe204;
      param_1[lVar14 + 0x3e] = 0;
    }
    *(undefined1 *)(param_1 + 0x54) = 0;
    thunk_EXT_FUN_8011000003222de0(DAT_fffffff00ae23bd0);
  }
LAB_fffffff0081fe1c4:
  lVar14 = lVar14 + -1;
  lVar11 = lVar11 + -1;
  if (lVar11 < 2) {
    return 0;
  }
  goto LAB_fffffff0081fe1d4;
}

