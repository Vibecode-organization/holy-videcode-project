// FUN_fffffff009c3bb20 @ fffffff009c3bb20 size=1060

/* WARNING: Removing unreachable block (ram,0xfffffff009c3bcf4) */

undefined8 FUN_fffffff009c3bb20(long param_1,long *param_2,undefined8 param_3)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  undefined8 extraout_x1;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  char *local_98 [4];
  char *local_78;
  char *pcStack_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  if (*(uint *)(param_1 + 0x128) < 0x4000) {
    plVar2 = (long *)thunk_EXT_FUN_801100000389d0d8(8);
    if (*param_2 == 0) {
      plVar3 = (long *)0x0;
    }
    else {
      plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24(*param_2,0x40);
      (**(code **)(*plVar2 + 0x100))(plVar2,"IOSurfaceAddress",plVar3);
    }
    lVar7 = 0;
    local_98[0] = "IOSurfaceWidth";
    local_98[1] = "IOSurfaceHeight";
    local_98[2] = "IOSurfacePixelFormat";
    local_98[3] = "IOSurfaceBytesPerElement";
    local_78 = "IOSurfaceBytesPerRow";
    pcStack_70 = "IOSurfaceAllocSize";
    lVar8 = 6;
    do {
      iVar1 = *(int *)((long)param_2 + lVar7 * 4 + 8);
      plVar4 = plVar3;
      if (iVar1 != 0) {
        plVar4 = (long *)thunk_EXT_FUN_80110000038c6e24(iVar1,0x40);
        if (plVar3 != (long *)0x0) {
          (**(code **)(*plVar3 + 0x28))(plVar3);
        }
        (**(code **)(*plVar2 + 0x100))(plVar2,local_98[lVar7],plVar4);
      }
      lVar7 = lVar7 + 1;
      lVar8 = lVar8 + -1;
      plVar3 = plVar4;
    } while (lVar8 != 0);
    lVar7 = *(long *)(param_1 + 0xf8);
    if (lVar7 == 0) {
      lVar7 = 0;
    }
    plVar3 = (long *)FUN_fffffff009c33c34(*(undefined8 *)(param_1 + 0xe8),lVar7,plVar2,0);
    if (plVar3 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "%s error - failed to alloc surface buffer\n");
      uVar6 = 0xe00002c2;
    }
    else {
      if ((*(byte *)(plVar3 + 0x7a) >> 1 & 1) != 0) {
        FUN_fffffff009c3eeac(param_1);
      }
      plVar5 = (long *)FUN_fffffff009c2b810(*(undefined8 *)(param_1 + 0x118),plVar3,1);
      if (plVar5 == (long *)0x0) {
        uVar6 = 0xe00002bd;
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "%s error - failed to alloc client buffer\n");
      }
      else {
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd8));
        iVar1 = FUN_fffffff009c33dc4(*(undefined8 *)(param_1 + 0xe8),plVar3,(int)plVar3[2]);
        if (iVar1 == 0) {
          uVar6 = 0xe00002bd;
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - set surface id\n");
        }
        else {
          iVar1 = FUN_fffffff009c3f2b0(param_1,plVar5,(int)plVar3[2]);
          if (iVar1 == 0) {
            uVar6 = 0xe00002bd;
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - set surface handle\n")
            ;
          }
          else {
            FUN_fffffff009c3f478(param_1,extraout_x1,1);
            FUN_fffffff009c2c18c(plVar5,param_3);
            uVar6 = 0;
          }
        }
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd8));
        (**(code **)(*plVar5 + 0x28))(plVar5);
      }
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - exceeded client limit (%d)\n")
    ;
    uVar6 = 0xe00002be;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_68) {
    uVar6 = thunk_EXT_FUN_8011000003a48590();
    return uVar6;
  }
  return uVar6;
}

