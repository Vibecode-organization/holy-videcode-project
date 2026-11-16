// FUN_fffffff009c3a2d4 @ fffffff009c3a2d4 size=824

undefined8 FUN_fffffff009c3a2d4(long param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  byte bVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  
  uVar2 = (**(code **)(PTR_DAT_fffffff00806ca28 + 0xb8))(param_1,param_4);
  if ((int)uVar2 != 0) {
    uVar2 = thunk_EXT_FUN_801100000326c6a4(param_3);
    lVar4 = param_3;
    if (param_3 == 0) {
      lVar4 = 0;
    }
    *(long *)(param_1 + 0xf8) = lVar4;
    uVar2 = FUN_fffffff009c3a60c(uVar2,param_3,"com.apple.private.iosurfaceinfo");
    *(char *)(param_1 + 0x122) = (char)uVar2;
    uVar3 = FUN_fffffff009c3a60c(uVar2,param_3,"com.apple.private.gpu-restricted");
    if ((uVar3 & 1) == 0) {
      uVar2 = FUN_fffffff009c3a60c(uVar3,param_3,"com.apple.developer.gpu-restricted");
    }
    else {
      uVar2 = 1;
    }
    *(char *)(param_1 + 0x127) = (char)uVar2;
    bVar1 = FUN_fffffff009c3a60c(uVar2,param_3,"com.apple.private.IOSurface.protected-access");
    *(undefined1 *)(param_1 + 0x123) = 0;
    *(byte *)(param_1 + 0x126) = (*(byte *)(param_1 + 0x122) | bVar1) & 1;
    lVar4 = thunk_EXT_FUN_8011000003890f30(param_2,DAT_fffffff008067d90);
    *(long *)(param_1 + 0xe8) = lVar4;
    if (lVar4 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,"provider not IOSurfaceRoot\n");
      uVar2 = 0;
    }
    else {
      lVar4 = FUN_fffffff009c418cc(param_3,param_2,*(byte *)(param_1 + 0x126) & 1);
      if (*(long **)(param_1 + 0x118) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x118) + 0x28))();
      }
      *(long *)(param_1 + 0x118) = lVar4;
      if (lVar4 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,"Cannot allocate IOSurfaceShared\n");
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_fffffff009c371f8(*(undefined8 *)(param_1 + 0xe8));
        lVar4 = thunk_EXT_FUN_801100000396cb64(uVar2,param_3,0,0x1001,0,0);
        if (*(long **)(param_1 + 0x138) != (long *)0x0) {
          (**(code **)(**(long **)(param_1 + 0x138) + 0x28))();
        }
        *(long *)(param_1 + 0x138) = lVar4;
        if (lVar4 == 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,"Cannot map graphics comm page\n");
          uVar2 = 0;
        }
        else {
          lVar4 = thunk_EXT_FUN_80110000038961f4(1);
          if (*(long **)(param_1 + 0x100) != (long *)0x0) {
            (**(code **)(**(long **)(param_1 + 0x100) + 0x28))();
          }
          *(long *)(param_1 + 0x100) = lVar4;
          if (lVar4 == 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,
                       "Cannot allocate notification array\n");
            uVar2 = 0;
          }
          else {
            lVar4 = thunk_EXT_FUN_80110000038961f4(1);
            if (*(long **)(param_1 + 0x140) != (long *)0x0) {
              (**(code **)(**(long **)(param_1 + 0x140) + 0x28))();
            }
            *(long *)(param_1 + 0x140) = lVar4;
            if (lVar4 == 0) {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,
                         "Cannot allocate invalidated surface array\n");
              uVar2 = 0;
            }
            else {
              lVar4 = thunk_EXT_FUN_80110000038ff010();
              *(long *)(param_1 + 0xd8) = lVar4;
              if (lVar4 == 0) {
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,"Cannot allocate IOLock\n");
                uVar2 = 0;
              }
              else {
                lVar4 = thunk_EXT_FUN_80110000038ff3d8();
                *(long *)(param_1 + 0xe0) = lVar4;
                if (lVar4 == 0) {
                  thunk_EXT_FUN_80110000038db19c
                            (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,"Cannot allocate IORWLock\n"
                            );
                  uVar2 = 0;
                }
                else {
                  uVar2 = 1;
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar2;
}

