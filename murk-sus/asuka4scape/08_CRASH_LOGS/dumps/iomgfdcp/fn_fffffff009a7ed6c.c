// FUN_fffffff009a7ed6c @ fffffff009a7ed6c size=1620
// CALLERS:
//   fffffff00afb8182 no-fn
//   fffffff009a7ec14 FUN_fffffff009a7ea60@fffffff009a7ea60
//   fffffff009a7ff8c FUN_fffffff009a7fdfc@fffffff009a7fdfc
// CALLEES:
//   fffffff009a7fba4 FUN_fffffff009a7fba4
//   fffffff009a88f34 FUN_fffffff009a88f34
//   fffffff009a99ba0 thunk_EXT_FUN_8011000003222de0
//   fffffff009a9a8a0 thunk_EXT_FUN_80110000036da494
//   fffffff009a996cc FUN_fffffff009a996cc
//   fffffff009a9a7d0 thunk_EXT_FUN_8011000002c2671c
//   fffffff009a9a7e0 thunk_EXT_FUN_8011000002c24af0
//   fffffff009a99bc0 thunk_EXT_FUN_80110000038fe9a0
//   fffffff009a99b60 thunk_EXT_FUN_80110000032222a8
//   fffffff009a9a7b0 thunk_EXT_FUN_8011000002c1e264
//   fffffff009a9a760 thunk_EXT_FUN_8011000002c1e3bc
//   fffffff009a9a750 thunk_EXT_FUN_8011000002c1e35c
//   fffffff009a9a450 thunk_EXT_FUN_8011000002c3d314

/* WARNING: Removing unreachable block (ram,0xfffffff009a7f1dc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009a7ef24) */
/* WARNING: Removing unreachable block (ram,0xfffffff009a7f184) */
/* WARNING: Removing unreachable block (ram,0xfffffff009a7f404) */

void FUN_fffffff009a7ed6c(long *param_1,long *param_2,long *param_3,long param_4)

{
  ulong uVar1;
  char *pcVar2;
  undefined4 uVar3;
  byte bVar4;
  byte bVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  undefined8 uVar10;
  long lVar11;
  long lVar12;
  code *pcVar13;
  long lVar14;
  long *plVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  uint uVar19;
  long lVar20;
  ulong uVar21;
  ulong unaff_x30;
  long local_a0;
  long lStack_98;
  long local_90;
  long lStack_88;
  long local_80;
  long lStack_78;
  long local_70;
  undefined8 uStack_68;
  
  bVar4 = *(byte *)((long)param_1 + 0x4d22);
  lStack_78 = 0;
  local_80 = 0;
  uStack_68 = 0;
  local_70 = 0;
  lStack_98 = 0;
  local_a0 = 0;
  lStack_88 = 0;
  local_90 = 0;
  lVar17 = param_4;
  thunk_EXT_FUN_80110000032222a8(param_1[0x9a6]);
  thunk_EXT_FUN_80110000032222a8(param_1[0x9a5]);
  if (((param_2 == (long *)0x0) || (param_1 == (long *)0x0)) || (param_3 == (long *)0x0)) {
    lVar18 = FUN_fffffff009a996cc();
    if ((lVar18 != 0) && (FUN_fffffff009a7ea60(), lVar17 != 0)) {
      thunk_EXT_FUN_80110000038fe270(&DAT_fffffff008021510,lVar17);
      return;
    }
    return;
  }
  if (((*(byte *)((long)param_2 + 0x62a) & 1) == 0) || ((*(byte *)(param_1 + 0xb0e) & 1) == 0)) {
    uVar3 = *(undefined4 *)((long)param_2 + 0x3d4);
    bVar5 = *(byte *)(param_2 + 0x183);
    if ((*(uint *)PTR_DAT_fffffff008022368 & 0xfffffff7) != 0) {
      uVar9 = thunk_EXT_FUN_8011000002c1e35c(param_3);
      thunk_EXT_FUN_80110000036da494
                (0x31800444,uVar3,uVar9 & 0xffffffff | (ulong)*(uint *)(param_1 + 0xb1e) << 0x20,
                 (long)(int)param_4,0,0);
    }
    lVar17 = 0;
    uVar9 = 0;
    bVar4 = param_2 != (long *)0x0 & bVar4;
    lVar18 = 0x504;
    do {
      if ((bVar5 & 1) == 0) {
        plVar15 = (long *)param_2[uVar9 + 0x170];
      }
      else {
        plVar15 = (long *)param_2[uVar9 + 0x184];
      }
      if (plVar15 == param_3) {
        if ((*(byte *)(param_2 + 0x183) & 1) == 0) {
          uVar21 = thunk_EXT_FUN_8011000002c2671c(param_3);
          if (uVar21 == 0) {
            uVar21 = (**(code **)(*param_1 + 0x7e8))(param_1);
          }
          uVar1 = param_2[0x79];
          if ((ulong)param_2[0x79] <= uVar21) {
            uVar1 = uVar21;
          }
          param_2[0x79] = uVar1;
          *(undefined1 *)((long)param_2 + uVar9 + 0x626) = 0;
          if (((*(byte *)((long)param_1 + 0x5861) & 1) != 0) &&
             (lVar20 = param_2[(uVar9 & 0xffffffff) + 0x170], lVar20 != 0)) {
            plVar15 = (long *)thunk_EXT_FUN_8011000002c1e264(lVar20);
            plVar15 = (long *)(**(code **)(*plVar15 + 0xe8))(plVar15,0);
            if (plVar15 != (long *)0x0) {
              lVar11 = (**(code **)(*plVar15 + 0x78))();
              if ((lVar11 != 0) && (iVar7 = thunk_EXT_FUN_8011000002c1e3bc(lVar20), iVar7 != 0)) {
                uVar19 = 0;
                do {
                  lVar12 = thunk_EXT_FUN_8011000002c24af0(lVar20,uVar19);
                  if ((lVar12 != 0) && (*(char *)(lVar12 + 0x20) != '\0')) {
                    lVar14 = 0;
                    lVar12 = lVar11 + (ulong)*(uint *)(lVar12 + 8);
                    lVar16 = 0x10;
                    do {
                      pcVar2 = (char *)(lVar12 + (int)lVar14);
                      if (lVar14 != (int)lVar14) {
                        pcVar2 = (char *)(lVar12 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
                      }
                      if (*pcVar2 != '\0') goto LAB_fffffff009a7f0c0;
                      lVar14 = lVar14 + 1;
                      lVar16 = lVar16 + -1;
                    } while (lVar16 != 0);
                    thunk_EXT_FUN_8011000002c1e35c(lVar20);
                    thunk_EXT_FUN_80110000038fe9a0
                              (
                              "IOMFB: [%s] SurfaceID 0x%x GP Decompression Error Debug - Detected 16 bytes of zero values in metadata buffer \n"
                              );
                  }
LAB_fffffff009a7f0c0:
                  uVar19 = uVar19 + 1;
                  uVar8 = thunk_EXT_FUN_8011000002c1e3bc(lVar20);
                } while (uVar19 < uVar8);
              }
              (**(code **)(*plVar15 + 0x28))();
            }
          }
          if (bVar4 != 0) {
            local_a0 = (ulong)*(uint *)((long)param_2 + 0x3d4) << 0x20;
            lStack_98 = param_2[0x74];
            lStack_88 = param_2[0x77];
            local_90 = param_2[0x76];
            lStack_78 = param_2[0x79];
            local_80 = param_2[0x78];
            local_70 = param_2[0x72];
          }
          if (((int)param_4 == 0) && (*(long *)((long)param_2 + lVar17 + 0xc50) != 0)) {
            uVar6 = thunk_EXT_FUN_8011000002c1e35c(param_3);
            thunk_EXT_FUN_80110000036da494
                      (0x31800514,uVar3,uVar6,*(undefined4 *)((long)param_2 + lVar17 + 0xc60),lVar18
                       ,0);
            uVar10 = thunk_EXT_FUN_8011000002c1e35c(param_3);
            (**(code **)(*param_1 + 0x888))
                      (*param_1 + 0x888,param_1,0xa5,uVar3,uVar10,
                       *(undefined4 *)((long)param_2 + lVar17 + 0xc60),lVar18);
            uVar10 = thunk_EXT_FUN_8011000002c1e35c(param_3);
            (**(code **)(*param_1 + 0x888))
                      (*param_1 + 0x888,param_1,0xb0,uVar3,uVar10,
                       *(undefined4 *)((long)param_2 + lVar17 + 0xc60),(int)lVar18 + 3);
            plVar15 = *(long **)((long)param_2 + lVar17 + 0xc50);
            if (plVar15 != (long *)0x0) {
              (**(code **)(*plVar15 + 0x28))();
            }
            *(undefined8 *)((long)param_2 + lVar17 + 0xc50) = 0;
          }
          (**(code **)(*param_2 + 0x28))(param_2);
          bVar5 = *(byte *)(param_1 + 0xb0e);
          thunk_EXT_FUN_8011000003222de0(param_1[0x9a5]);
          if ((bVar5 & 1) == 0) {
            uVar10 = thunk_EXT_FUN_8011000002c1e35c(param_3);
            bVar5 = FUN_fffffff009a88f34(param_1,uVar3,uVar10,uVar21,param_4);
            if (((bVar5 & bVar4) == 1) && (plVar15 = (long *)param_1[0x77], plVar15 != (long *)0x0))
            {
              (**(code **)(*plVar15 + 0x80))(plVar15,uVar9,param_3,&local_a0);
            }
          }
          thunk_EXT_FUN_8011000003222de0(param_1[0x9a6]);
          (**(code **)(*param_3 + 0x28))(param_3);
          return;
        }
        uVar6 = thunk_EXT_FUN_8011000002c1e35c(param_3);
        uVar21 = uVar9 & 0xffffffff;
        thunk_EXT_FUN_80110000036da494
                  (0x31800514,uVar3,uVar6,*(undefined4 *)((long)param_2 + lVar17 + 0xc60),
                   lVar18 + -0x200,0);
        uVar10 = thunk_EXT_FUN_8011000002c1e35c(param_3);
        (**(code **)(*param_1 + 0x888))
                  (*param_1 + 0x888,param_1,0xa5,uVar3,uVar10,
                   *(undefined4 *)((long)param_2 + lVar17 + 0xc60),lVar18 + -0x200);
        if (*(int *)((long)param_2 + lVar17 + 0xcd0) == 0) {
          thunk_EXT_FUN_8011000002c3d314(param_2[uVar21 + 0x16c],0xe00002bc);
          (**(code **)(*(long *)param_2[uVar21 + 0x16c] + 0x28))();
          param_2[uVar21 + 0x16c] = 0;
        }
        else {
          FUN_fffffff009a7fba4
                    (param_1,(long)param_2 + lVar17 + 0xcc8,param_2[uVar21 + 0x170],
                     *(undefined4 *)((long)param_2 + 0x3d4),uVar9,0,0x12);
        }
        param_3 = (long *)param_2[uVar21 + 0x184];
        if (param_3 == (long *)0x0) goto LAB_fffffff009a7f360;
        pcVar13 = *(code **)(*param_3 + 0x28);
        goto LAB_fffffff009a7f358;
      }
      uVar9 = uVar9 + 1;
      lVar18 = lVar18 + 0x10000;
      lVar17 = lVar17 + 0x18;
    } while (lVar18 != 0x40504);
  }
  else {
    pcVar13 = *(code **)(*param_3 + 0x28);
LAB_fffffff009a7f358:
    (*pcVar13)(param_3);
LAB_fffffff009a7f360:
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  thunk_EXT_FUN_8011000003222de0(param_1[0x9a5]);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_8011000003222de0(param_1[0x9a6]);
    return;
  }
                    /* WARNING: Does not return */
  pcVar13 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009a7f3b8);
  (*pcVar13)();
}

