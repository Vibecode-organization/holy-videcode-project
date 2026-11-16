// FUN_fffffff009c1a914 @ fffffff009c1a914 size=1536

/* WARNING: Removing unreachable block (ram,0xfffffff009c1ad18) */

ulong FUN_fffffff009c1a914(long param_1,undefined8 param_2,long param_3,long *param_4,long param_5)

{
  undefined8 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  undefined1 *puVar7;
  ulong uVar8;
  undefined1 *puVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  uint uVar13;
  undefined8 local_68;
  undefined1 *local_60;
  undefined1 *local_58;
  undefined8 local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  FUN_fffffff009c46f98(param_1 + 0xc,1);
  uVar4 = FUN_fffffff009c372c4();
  *(undefined8 *)(param_1 + 0x380) = uVar4;
  if (param_5 != 0) {
    if (*(long *)(param_5 + 0x378) != 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "%s error - invalid parent (can\'t be child)\n");
      uVar12 = 0;
      goto LAB_fffffff009c1ac5c;
    }
    FUN_fffffff009c16670(param_1 + 0x378,param_5);
  }
  uVar12 = FUN_fffffff009c35bd8(DAT_fffffff00af483b0,param_1 + 0x10);
  if ((uVar12 & 1) == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - failed to alloc surface id\n")
    ;
    uVar12 = 0;
  }
  else {
    uVar4 = (**(code **)(*param_4 + 0x138))(param_4,"IOSurfacePixelSizeCastingAllowed");
    lVar5 = thunk_EXT_FUN_8011000003890f30(uVar4,*(undefined8 *)PTR_DAT_fffffff00806ca20);
    if (lVar5 == 0) {
      iVar2 = FUN_fffffff009c31488(2);
      puVar1 = (undefined8 *)PTR_DAT_fffffff00806ca60;
      if (iVar2 != 0) {
        puVar1 = (undefined8 *)PTR_DAT_fffffff00806ca58;
      }
      (**(code **)(*param_4 + 0x100))
                (param_4,"IOSurfacePixelSizeCastingAllowed",*(undefined8 *)*puVar1);
    }
    FUN_fffffff009c16670(param_1 + 0x268,param_4);
    if (param_3 != 0) {
      *(long *)(param_1 + 0x170) = param_3;
    }
    *(undefined8 *)(param_1 + 0x78) = 0;
    *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xffffef33;
    *(undefined8 *)(param_1 + 0x98) = 0;
    *(undefined4 *)(param_1 + 400) = 0;
    if (*(long **)(param_1 + 0x1a8) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x1a8) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x1a8) = 0;
    if (*(long **)(param_1 + 0x210) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x210) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x40) = 0;
    *(undefined8 *)(param_1 + 0x218) = 0;
    *(undefined8 *)(param_1 + 0x210) = 0;
    *(undefined8 **)(param_1 + 0x48) = (undefined8 *)(param_1 + 0x40);
    *(undefined8 *)(param_1 + 0x2f0) = 0;
    *(long *)(param_1 + 0x2f8) = param_1 + 0x2f0;
    *(undefined8 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x70) = 0x1010001;
    *(undefined8 *)(param_1 + 0x150) = 0;
    *(undefined4 *)(param_1 + 0x368) = 3;
    *(undefined4 *)(param_1 + 0x22c) = 0;
    *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xffedb3fd | 0x800;
    lVar5 = thunk_EXT_FUN_80110000038ff010();
    *(long *)(param_1 + 0x50) = lVar5;
    if (lVar5 != 0) {
      lVar5 = thunk_EXT_FUN_80110000038ff010();
      *(long *)(param_1 + 0x398) = lVar5;
      if (lVar5 != 0) {
        lVar5 = thunk_EXT_FUN_80110000038961f4(1);
        if (*(long **)(param_1 + 0x3d8) != (long *)0x0) {
          (**(code **)(**(long **)(param_1 + 0x3d8) + 0x28))();
        }
        *(long *)(param_1 + 0x3d8) = lVar5;
        if (lVar5 != 0) {
          *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x10);
          *(undefined8 *)(param_1 + 0x178) = 0;
          *(undefined8 *)(param_1 + 0x300) = 0;
          *(undefined4 *)(param_1 + 0x220) = 0;
          *(undefined8 *)(param_1 + 0x240) = 0;
          *(long *)(param_1 + 0x248) = param_1 + 0x240;
          *(undefined8 *)(param_1 + 0x250) = 0;
          *(long *)(param_1 + 600) = param_1 + 0x250;
          *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xffff5fcf | 0x8000;
          *(undefined4 *)(param_1 + 0x228) = 2;
          local_60 = &DAT_aaaaaaaaaaaaaaaa;
          local_58 = &DAT_aaaaaaaaaaaaaaaa;
          uVar12 = FUN_fffffff009c36818
                             (DAT_fffffff00af483b0,*(undefined4 *)(param_1 + 0x10),&local_58,
                              &local_60);
          if ((uVar12 & 1) == 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                       "%s error - failed to alloc shmem\n");
            uVar12 = 0;
          }
          else {
            puVar7 = local_58;
            if (local_58 == (undefined1 *)0x0) {
              puVar7 = (undefined1 *)0x0;
            }
            *(undefined1 **)(param_1 + 0x178) = puVar7;
            puVar9 = local_60;
            if (local_60 == (undefined1 *)0x0) {
              puVar9 = (undefined1 *)0x0;
            }
            *(undefined1 **)(param_1 + 0x300) = puVar9;
            *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | 0x10000;
            puVar7[0x2c] = 1;
            *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | 0x40000;
            puVar7[0x2e] = 1;
            uVar4 = thunk_EXT_FUN_80110000038961f4(0x10);
            if (*(long **)(param_1 + 0x3c8) != (long *)0x0) {
              (**(code **)(**(long **)(param_1 + 0x3c8) + 0x28))();
            }
            *(undefined8 *)(param_1 + 0x3c8) = uVar4;
            uVar12 = FUN_fffffff009c1af14(param_1,param_4);
            if ((uVar12 & 1) == 0) {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                         "%s error - failed to parse properties\n");
              uVar12 = 0;
            }
            else {
              uVar3 = thunk_EXT_FUN_80110000037225e0();
              *(undefined4 *)(param_1 + 0x3d4) = uVar3;
              uVar12 = *(ulong *)(param_1 + 0x150);
              if (uVar12 == 0) {
                lVar5 = *(long *)(param_1 + 0x90);
              }
              else {
                uVar10 = -*(long *)PTR_DAT_fffffff00806ca78;
                uVar8 = *(long *)PTR_DAT_fffffff00806ca78 - 1;
                uVar11 = uVar8 & uVar12;
                lVar5 = *(long *)(param_1 + 0x90);
                *(ulong *)(param_1 + 0x158) = uVar12 & uVar10;
                *(ulong *)(param_1 + 0x160) = uVar11 + uVar8 + lVar5 & uVar10;
                *(ulong *)(param_1 + 0x168) = uVar11;
              }
              uVar13 = 0x100;
              if (lVar5 == 0) {
                uVar12 = 1;
              }
              else {
                iVar2 = FUN_fffffff009c1e624(param_1);
                uVar12 = (ulong)(iVar2 == 0);
                uVar13 = 0x100;
                if (iVar2 != 0) {
                  uVar13 = 0;
                }
              }
              *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xfffffeff | uVar13;
              local_68 = 0;
              plVar6 = *(long **)(param_1 + 0x1a8);
              if (plVar6 != (long *)0x0) {
                uVar4 = (**(code **)(*plVar6 + 0x138))(plVar6,"IOSurfaceName");
                plVar6 = (long *)thunk_EXT_FUN_8011000003890f30
                                           (uVar4,*(undefined8 *)PTR_DAT_fffffff00806ca10);
                if (plVar6 != (long *)0x0) {
                  uVar4 = (**(code **)(*plVar6 + 0xa8))();
                  thunk_EXT_FUN_80110000036dc388(0x85210040,&local_68,uVar4);
                }
              }
              local_50 = 0;
              thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x30),&local_50);
              thunk_EXT_FUN_80110000036da494
                        (0x85210018,local_50,*(undefined4 *)(param_1 + 0x10),
                         *(undefined4 *)(param_1 + 0x80),
                         *(ulong *)(param_1 + 0x58) | *(long *)(param_1 + 0x60) << 0x20,0);
              local_50 = 0;
              thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x30),&local_50);
              thunk_EXT_FUN_80110000036da494
                        (0x8521003c,local_50,*(undefined4 *)(param_1 + 0x10),
                         *(undefined8 *)(param_1 + 0x90),local_68,0);
            }
          }
          goto LAB_fffffff009c1ac5c;
        }
      }
    }
    uVar12 = 0;
  }
LAB_fffffff009c1ac5c:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_48) {
    return uVar12;
  }
  uVar12 = thunk_EXT_FUN_8011000003a48590();
  return uVar12;
}

