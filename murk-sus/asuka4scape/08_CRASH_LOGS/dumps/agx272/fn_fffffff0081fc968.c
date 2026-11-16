// FUN_fffffff0081fc968 @ fffffff0081fc968 size=1392

/* WARNING: Type propagation algorithm not settling */

ulong FUN_fffffff0081fc968(long *param_1,long *param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  long *plVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  long lVar12;
  undefined1 uVar13;
  ulong uVar14;
  long lVar15;
  uint uVar16;
  long lVar17;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  uint local_64;
  
  if ((*(char *)((long)param_2 + 0x59) == '\x0e') &&
     (lVar7 = thunk_EXT_FUN_80110000039ea018(), lVar7 == 1)) {
LAB_fffffff0081fc9b4:
    uVar14 = 0;
  }
  else {
    uVar2 = *(uint *)(param_2[3] + 0x78);
    if ((((*(byte *)(param_1 + 0x5e) & 1) == 0) && (*(int *)((long)param_1 + 0x274) == 0)) ||
       (uVar5 = (**(code **)(*param_1 + 0x160))(param_1), uVar2 == uVar5)) {
      uVar13 = 0;
      bVar3 = *(byte *)(param_2 + 0xd);
    }
    else {
      uVar13 = 1;
      if ((uVar2 & (uVar5 ^ 0xffffffff)) != 0) {
        return 1;
      }
      bVar3 = *(byte *)(param_2 + 0xd);
    }
    if ((bVar3 & 1) == 0) {
      lVar7 = param_1[2];
      thunk_EXT_FUN_8011000003224180(*(undefined8 *)(lVar7 + 0x11a70));
      thunk_EXT_FUN_8011000003224180(*(undefined8 *)(lVar7 + 0x11a78));
      if (*(int *)(param_1[2] + 0x11a68) != 0) goto LAB_fffffff0081fcec8;
    }
    uVar8 = (**(code **)(*param_2 + 0x98))(param_2);
    bVar4 = *(byte *)(param_2 + 0xb);
    uVar5 = (**(code **)(*param_1 + 0x1a8))
                      (param_1,uVar8,param_3,bVar4 >> 4 & 1,bVar4 >> 3 & 1,bVar4 >> 5 & 1,
                       (ulong)param_2[0xe] >> 0x27 & 1);
    uVar2 = uVar5 & 0xfffffdff;
    if (!(bool)uVar13) {
      uVar2 = uVar5;
    }
    lVar7 = thunk_EXT_FUN_8011000003890f30(param_2[3],&DAT_fffffff00ae21bd0);
    if (lVar7 == 0) {
      lVar7 = thunk_EXT_FUN_8011000003890f30(param_2[3],*(undefined8 *)PTR_DAT_fffffff007ca6050);
      if (lVar7 != 0) {
        uVar14 = (**(code **)(*param_2 + 0x100))(param_2);
        if ((uVar14 & 1) == 0) {
          local_64 = 0;
          uVar5 = *(uint *)(lVar7 + 0x90);
          lVar12 = (**(code **)(*param_2 + 0x98))(param_2);
          local_80 = 0;
          uStack_78 = 0;
          local_70 = 0;
          thunk_EXT_FUN_801100000293e3ec(&local_80,lVar7);
          uVar16 = uVar2;
          do {
            while( true ) {
              plVar9 = (long *)thunk_EXT_FUN_801100000293e410(&local_80,&local_64);
              if (plVar9 == (long *)0x0) {
                lVar15 = *(long *)(lVar7 + 0x88);
                plVar9 = *(long **)(lVar7 + 0xb0);
                if (plVar9 == (long *)0x0) {
                  lVar17 = 0;
                }
                else {
                  lVar17 = (**(code **)(*plVar9 + 0xb0))(plVar9);
                  (**(code **)(*plVar9 + 0xa8))(plVar9);
                  if ((DAT_fffffff00ae25928 & 1) == 0) {
                    FUN_fffffff0082105b8
                              (*(undefined8 *)(param_1[0x5a] + 0x18),plVar9,lVar15 + lVar12,lVar17,
                               uVar2);
                  }
                  else {
                    iVar6 = thunk_EXT_FUN_80110000039ea318
                                      (*(undefined8 *)(param_1[0x5a] + 0x10),plVar9,lVar15 + lVar12,
                                       lVar17,uVar2);
                    if (iVar6 != 0) goto LAB_fffffff0081fcec8;
                  }
                }
                plVar9 = *(long **)(lVar7 + 0xb8);
                if (plVar9 != (long *)0x0) {
                  (**(code **)(*plVar9 + 0xa8))(plVar9);
                  lVar7 = param_1[0x5a];
                  uVar8 = (**(code **)(*plVar9 + 0xb0))(plVar9);
                  if ((DAT_fffffff00ae25928 & 1) == 0) {
                    FUN_fffffff0082105b8
                              (*(undefined8 *)(lVar7 + 0x18),plVar9,lVar15 + lVar12 + lVar17,uVar8,
                               uVar2);
                  }
                  else {
                    iVar6 = thunk_EXT_FUN_80110000039ea318
                                      (*(undefined8 *)(lVar7 + 0x10),plVar9,lVar15 + lVar12 + lVar17
                                       ,uVar8,uVar2);
                    if (iVar6 != 0) goto LAB_fffffff0081fcec8;
                  }
                }
                thunk_EXT_FUN_801100000293e4f8(&local_80);
                uVar14 = 1;
                goto joined_r0xfffffff0081fcea8;
              }
              iVar6 = (**(code **)(*plVar9 + 0xa8))();
              uVar1 = uVar16 & 0xfffffdfd;
              if (iVar6 != 2) {
                uVar1 = uVar16;
              }
              lVar15 = param_1[0x5a];
              lVar17 = lVar12 + (ulong)local_64 * (ulong)uVar5;
              uVar8 = (**(code **)(*plVar9 + 0xb0))(plVar9);
              uVar16 = uVar1;
              if ((DAT_fffffff00ae25928 & 1) != 0) break;
              FUN_fffffff0082105b8(*(undefined8 *)(lVar15 + 0x18),plVar9,lVar17,uVar8,uVar1);
            }
            iVar6 = thunk_EXT_FUN_80110000039ea318
                              (*(undefined8 *)(lVar15 + 0x10),plVar9,lVar17,uVar8,uVar1);
          } while (iVar6 == 0);
LAB_fffffff0081fcec8:
          uVar14 = thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! AGXSecureGart::map\n");
          return uVar14;
        }
        goto LAB_fffffff0081fc9b4;
      }
      uVar14 = 0;
    }
    else {
      plVar9 = (long *)thunk_EXT_FUN_801100000297dd00();
      iVar6 = (**(code **)(*plVar9 + 0xa8))();
      uVar5 = uVar2 & 0xfffffdfd;
      if (iVar6 != 2) {
        uVar5 = uVar2;
      }
      lVar7 = param_1[0x5a];
      uVar8 = thunk_EXT_FUN_801100000297dd00(param_2[3]);
      uVar10 = (**(code **)(*param_2 + 0x98))(param_2);
      uVar11 = (**(code **)(*param_2 + 200))(param_2);
      if ((DAT_fffffff00ae25928 & 1) == 0) {
        FUN_fffffff0082105b8(*(undefined8 *)(lVar7 + 0x18),uVar8,uVar10,uVar11,uVar5);
        uVar14 = 1;
      }
      else {
        iVar6 = thunk_EXT_FUN_80110000039ea318
                          (*(undefined8 *)(lVar7 + 0x10),uVar8,uVar10,uVar11,uVar5);
        uVar14 = (ulong)(iVar6 == 0);
      }
    }
joined_r0xfffffff0081fcea8:
    if ((bVar3 & 1) == 0) {
      lVar7 = param_1[2];
      thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar7 + 0x11a78));
      thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar7 + 0x11a70));
    }
  }
  return uVar14;
}

