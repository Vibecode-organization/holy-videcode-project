// FUN_fffffff009c3bf44 @ fffffff009c3bf44 size=1040

/* WARNING: Removing unreachable block (ram,0xfffffff009c3c0ec) */

undefined8 FUN_fffffff009c3bf44(long param_1,long param_2,long param_3,undefined8 param_4)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  undefined8 extraout_x1;
  long lVar6;
  undefined8 uVar7;
  
  if ((param_2 == 0) || (param_3 == 0)) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
               "%s error - invalid memory range (addr=0x%llx size=0x%llx)\n");
    uVar7 = 0xe00002c2;
  }
  else if (*(uint *)(param_1 + 0x128) < 0x4000) {
    plVar2 = (long *)thunk_EXT_FUN_801100000389d0d8(3);
    if (plVar2 == (long *)0x0) {
      uVar7 = 0xe00002bd;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - no properties\n");
    }
    else {
      plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24(param_2,0x40);
      if (plVar3 == (long *)0x0) {
        plVar4 = (long *)thunk_EXT_FUN_80110000038c6e24(param_3,0x40);
      }
      else {
        (**(code **)(*plVar2 + 0x100))(plVar2,"IOSurfaceAddress",plVar3);
        plVar4 = (long *)thunk_EXT_FUN_80110000038c6e24(param_3,0x40);
        (**(code **)(*plVar3 + 0x28))(plVar3);
      }
      if (plVar4 != (long *)0x0) {
        (**(code **)(*plVar2 + 0x100))(plVar2,"IOSurfaceAllocSize",plVar4);
      }
      lVar6 = *(long *)(param_1 + 0xf8);
      if (lVar6 == 0) {
        lVar6 = 0;
      }
      plVar3 = (long *)FUN_fffffff009c33c34(*(undefined8 *)(param_1 + 0xe8),lVar6,plVar2,0);
      if (plVar3 == (long *)0x0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "%s error - failed to alloc surface buffer\n");
        uVar7 = 0xe00002c2;
      }
      else {
        plVar5 = (long *)FUN_fffffff009c2b810(*(undefined8 *)(param_1 + 0x118),plVar3,1);
        if (plVar5 == (long *)0x0) {
          uVar7 = 0xe00002bd;
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "%s error - failed to alloc client buffer\n");
        }
        else {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd8));
          iVar1 = FUN_fffffff009c33dc4(*(undefined8 *)(param_1 + 0xe8),plVar3,(int)plVar3[2]);
          if (iVar1 == 0) {
            uVar7 = 0xe00002bd;
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - set surface id\n");
          }
          else {
            iVar1 = FUN_fffffff009c3f2b0(param_1,plVar5,(int)plVar3[2]);
            if (iVar1 == 0) {
              uVar7 = 0xe00002bd;
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                         "%s error - set surface handle\n");
            }
            else {
              FUN_fffffff009c3f478(param_1,extraout_x1,1);
              FUN_fffffff009c2c18c(plVar5,param_4);
              uVar7 = 0;
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
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - exceeded client limit (%d)\n")
    ;
    uVar7 = 0xe00002be;
  }
  return uVar7;
}

