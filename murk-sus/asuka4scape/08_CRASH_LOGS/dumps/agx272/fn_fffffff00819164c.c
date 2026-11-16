// FUN_fffffff00819164c @ fffffff00819164c size=1792

undefined8
FUN_fffffff00819164c
          (long param_1,long param_2,long param_3,ulong param_4,long param_5,undefined8 param_6,
          undefined8 param_7,int *param_8)

{
  char *pcVar1;
  undefined4 *puVar2;
  uint uVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  long *plVar7;
  ulong uVar8;
  undefined4 uVar9;
  long lVar10;
  long lVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  
  if ((param_4 & 1) == 0) goto LAB_fffffff008191ca4;
  lVar10 = *(long *)(param_1 + 0x610);
  if (*(int *)(lVar10 + 0x98) == 0) {
    lVar4 = FUN_fffffff00818d738(param_1,0,0);
    uVar12 = 0;
    if (lVar4 == 0) goto LAB_fffffff008191c7c;
    lVar10 = *(long *)(param_1 + 0x610);
    uVar3 = *(uint *)(lVar10 + 0x98);
    *(uint *)(lVar10 + 0x98) = uVar3 + 1;
    lVar11 = (ulong)uVar3 * 8;
    plVar5 = (long *)(lVar10 + 0x28 + (long)(int)lVar11);
    if (lVar11 - (int)lVar11 != 0) {
      plVar5 = (long *)(lVar10 + 0x28 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *plVar5 = lVar4;
  }
  if ((*(byte *)(*(long *)(param_1 + 0x918) + 0x24) & 1) == 0) {
    lVar4 = *(long *)(lVar10 + 0x28);
    if (*(long *)(lVar4 + 0x218) == 0) {
      uVar12 = FUN_fffffff008214518(lVar4,*(undefined8 *)(*(long *)(lVar10 + 0xb0) + 0x28));
      if ((int)uVar12 == 0) goto LAB_fffffff008191c7c;
      lVar4 = *(long *)(*(long *)(param_1 + 0x610) + 0x28);
      if (*(long *)(lVar4 + 0x230) != 0) goto LAB_fffffff008191934;
LAB_fffffff0081919b4:
      uVar13 = *(undefined8 *)(param_1 + 0x488);
      plVar7 = *(long **)(lVar4 + 0xc0);
      uVar12 = *(undefined8 *)(lVar4 + 0x100);
      plVar5 = (long *)(**(code **)(*plVar7 + 0x878))(plVar7);
      if (plVar5 != (long *)0x0) {
        uVar8 = (**(code **)(*plVar5 + 0x78))(plVar5,plVar7,uVar13,uVar12);
        if ((uVar8 & 1) != 0) {
          *(long **)(lVar4 + 0x230) = plVar5;
          lVar4 = *(long *)(*(long *)(param_1 + 0x610) + 0x28);
          lVar10 = *(long *)(lVar4 + 0x228);
          goto joined_r0xfffffff008191a2c;
        }
        (**(code **)(*plVar5 + 0x28))(plVar5);
      }
      *(undefined8 *)(lVar4 + 0x230) = 0;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,
                 "Failed to create Render Target Memory\n");
      uVar12 = 0;
LAB_fffffff008191c7c:
      *(undefined4 *)(param_1 + 0x520) = 8;
      return uVar12;
    }
    if ((*(long *)(lVar4 + 0x230) != 0) && (*(long *)(lVar4 + 0x228) != 0))
    goto LAB_fffffff0081916fc;
    if (*(long *)(lVar4 + 0x230) == 0) goto LAB_fffffff0081919b4;
LAB_fffffff008191934:
    lVar10 = *(long *)(lVar4 + 0x228);
joined_r0xfffffff008191a2c:
    if (lVar10 == 0) {
      uVar12 = FUN_fffffff00821465c
                         (lVar4,*(undefined8 *)(param_1 + 0x488),*(undefined8 *)(param_1 + 0x918));
      if ((int)uVar12 == 0) goto LAB_fffffff008191c7c;
      lVar4 = *(long *)(*(long *)(param_1 + 0x610) + 0x28);
    }
    uVar3 = *(uint *)(param_1 + 0x7ec);
    uVar8 = (ulong)uVar3;
    if (*(int *)(param_1 + 0x44c) == 1) {
      uVar9 = *(undefined4 *)(param_1 + 0x450);
      plVar5 = *(long **)(lVar4 + 0x218);
    }
    else {
      uVar9 = 2;
      plVar5 = *(long **)(lVar4 + 0x218);
    }
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x110))(plVar5,uVar8,uVar9);
    }
    (**(code **)(**(long **)(lVar4 + 0x220) + 0x110))(*(long **)(lVar4 + 0x220),uVar8,uVar9);
    if ((5 < uVar3) || ((0x37U >> (ulong)(uVar3 & 0x1f) & 1) == 0)) {
      uVar12 = thunk_EXT_FUN_8011000003a49114
                         ("AGXk: %s:%d:%s: !!! Invalid priority %d used for work queue 0x%p\n");
      return uVar12;
    }
    lVar10 = uVar8 * 4;
    puVar2 = (undefined4 *)(&DAT_fffffff007115cc0 + (int)lVar10);
    if (lVar10 - (int)lVar10 != 0) {
      puVar2 = (undefined4 *)
               ((ulong)(&DAT_fffffff007115cc0 + lVar10) & 0xffffffffffff | 0x2bad000000000000);
    }
    thunk_EXT_FUN_8011000002958c50(lVar4,*puVar2);
    lVar10 = *(long *)(*(long *)(*(long *)(param_1 + 0x610) + 0x28) + 0x228);
    puVar2 = (undefined4 *)(*(long *)(lVar10 + 0x10) + 0x11184);
    if ((*(byte *)(*(long *)(lVar10 + 0x10) + 0x11181) & 1) == 0) {
      puVar2 = (undefined4 *)(*(long *)(param_1 + 0x918) + 0x20);
    }
    uVar9 = *puVar2;
    *(undefined4 *)(lVar10 + 0x1c4) = uVar9;
    *(undefined4 *)(*(long *)(*(long *)(lVar10 + 0x20) + 0x48) + 0xc) = uVar9;
  }
  else {
LAB_fffffff0081916fc:
    *(undefined8 *)(param_1 + 0x818) = 0;
    *(undefined8 *)(param_1 + 0x808) = 0;
    *(undefined8 *)(param_1 + 0x800) = 0;
    *(undefined8 *)(param_1 + 0x828) = 0;
  }
  if (param_8 == (int *)0x0) {
    thunk_EXT_FUN_80110000029615ec(*(undefined8 *)(param_1 + 0x488));
  }
  uStack_78 = 0;
  local_80 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  uStack_98 = 0;
  local_a0 = 0;
  uStack_88 = 0;
  uStack_90 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  plVar5 = (long *)(**(code **)(DAT_fffffff00ae256a0 + 0x68))();
  uVar12 = *(undefined8 *)(param_1 + 0x530);
  uVar13 = *(undefined8 *)(param_1 + 0x480);
  pcVar1 = (char *)0x0;
  if (*(char *)(param_2 + 0x10) != '\0') {
    pcVar1 = (char *)(param_2 + 0x10);
  }
  uVar14 = *(undefined8 *)(param_5 + 0x78);
  uVar6 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(param_1 + 0x580),&DAT_fffffff00ae22130);
  (**(code **)(*plVar5 + 0xe8))(plVar5,uVar12,param_1,uVar13,pcVar1,uVar14,uVar6);
  plVar7 = (long *)(**(code **)(DAT_fffffff00ae21fa0 + 0x68))();
  if (plVar7 == (long *)0x0) {
LAB_fffffff008191974:
    *(undefined4 *)(param_1 + 0x520) = 0x111;
    if (param_8 == (int *)0x0) {
      thunk_EXT_FUN_80110000029615f8(*(undefined8 *)(param_1 + 0x488));
    }
    return 0;
  }
  uVar8 = (**(code **)(*plVar7 + 0x68))();
  if ((uVar8 & 1) == 0) {
    (**(code **)(*plVar7 + 0x28))(plVar7);
    goto LAB_fffffff008191974;
  }
  lVar10 = *(long *)(*(long *)(param_1 + 0x488) + 0x1e0);
  if (lVar10 != 0) {
    if (*(long *)(lVar10 + 0x50) != 0) {
      thunk_EXT_FUN_8011000002969a34(plVar5);
    }
    if (*(long *)(lVar10 + 0x58) != 0) {
      thunk_EXT_FUN_8011000002969a34(plVar5);
    }
    if (*(long *)(lVar10 + 0x50) != 0) {
      thunk_EXT_FUN_8011000002969a34(plVar5);
    }
    if (*(long *)(lVar10 + 0x58) != 0) {
      thunk_EXT_FUN_8011000002969a34(plVar5);
    }
  }
  thunk_EXT_FUN_801100000296a540(plVar5,*(long *)(*(long *)(param_5 + 0x70) + 0x20) + 0x20);
  if ((*(byte *)(param_3 + 8) & 1) == 0) {
LAB_fffffff008191ca4:
    uVar12 = thunk_EXT_FUN_8011000003a49114
                       ("AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n");
    return uVar12;
  }
  if (((*(byte *)(param_3 + 0x128) & 1) == 0) || ((*(byte *)(param_3 + 0x129) & 1) != 0)) {
    if ((*(int *)(*(long *)(param_1 + 0x530) + 0x414) != 1) &&
       ((*(int *)(*(long *)(param_1 + 0x918) + 0x10) != 0 &&
        ((uint)(1 << (ulong)(*(uint *)(*(long *)(param_1 + 0x918) + 0xc) & 0x1f)) <
         *(uint *)(param_3 + 300))))) {
      uVar9 = 0x100;
      goto LAB_fffffff008191d14;
    }
    uVar8 = FUN_fffffff008197670
                      (param_1,param_2,param_3,param_6,param_7,param_8,plVar5,plVar5,param_5,
                       &local_a0,&uStack_a8,&local_b0,plVar7);
    if ((uVar8 & 1) != 0) {
      if (param_8 == (int *)0x0) {
        thunk_EXT_FUN_80110000029615f8(*(undefined8 *)(param_1 + 0x488));
LAB_fffffff008191b50:
        *(undefined4 *)(plVar5 + 0x23c) = *(undefined4 *)(*(long *)(param_1 + 0x808) + 0x18);
        lVar10 = *(long *)(param_1 + 0x530);
        if ((*(byte *)(lVar10 + 0x1ac45) & 1) != 0) {
          FUN_fffffff0081a0304(*(undefined8 *)(lVar10 + 0x148),0x806,&local_a0,plVar5[0x20]);
          lVar10 = *(long *)(param_1 + 0x530);
        }
        *(byte *)(plVar5 + 0x69) = (byte)(*(uint *)(lVar10 + 0x5c8) >> 0xf) & 1;
        thunk_EXT_FUN_801100000294849c(*(undefined8 *)(lVar10 + 0x148),&local_a0,plVar5 + 0x49);
        FUN_fffffff0081938f0(param_1,plVar5,*(undefined8 *)(param_1 + 0x818));
      }
      else {
        if (*param_8 != 3) {
          if (*param_8 == 4) {
            *(long **)(param_8 + 0xe) = plVar5;
          }
          goto LAB_fffffff008191b50;
        }
        uVar12 = *(undefined8 *)(param_1 + 0x818);
        *(long **)(param_8 + 0xe) = plVar5;
        *(undefined8 *)(param_8 + 0x10) = uVar12;
        uVar12 = *(undefined8 *)(param_1 + 0x800);
        *(undefined8 *)(param_8 + 0x16) = *(undefined8 *)(param_1 + 0x808);
        *(undefined8 *)(param_8 + 0x14) = uVar12;
        lVar10 = *(long *)(param_1 + 0x530);
        if ((*(byte *)(lVar10 + 0x1ac45) & 1) != 0) {
          FUN_fffffff0081a0304(*(undefined8 *)(lVar10 + 0x148),0x806,&local_a0,plVar5[0x20]);
          lVar10 = *(long *)(param_1 + 0x530);
        }
        *(byte *)(plVar5 + 0x69) = (byte)(*(uint *)(lVar10 + 0x5c8) >> 0xf) & 1;
        thunk_EXT_FUN_801100000294849c(*(undefined8 *)(lVar10 + 0x148),&local_a0,plVar5 + 0x49);
      }
      uVar12 = 1;
      goto LAB_fffffff008191c14;
    }
  }
  else {
    (**(code **)(*plVar5 + 0x28))(plVar5);
    uVar9 = 0xc;
LAB_fffffff008191d14:
    *(undefined4 *)(param_1 + 0x520) = uVar9;
  }
  if (param_8 == (int *)0x0) {
    thunk_EXT_FUN_80110000029615f8(*(undefined8 *)(param_1 + 0x488));
  }
  uVar12 = 0;
LAB_fffffff008191c14:
  (**(code **)(*plVar7 + 0x28))(plVar7);
  return uVar12;
}

