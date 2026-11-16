// FUN_fffffff00995a9b4 @ fffffff00995a9b4 size=4

undefined8 FUN_fffffff00995a9b4(long param_1,long param_2,int param_3,int param_4)

{
  ulong uVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar1 = (*DAT_fffffff007feb260)();
  if ((param_2 != 0) && ((uVar1 & 1) != 0)) {
    *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
    *(int *)(param_1 + 0x14) = param_3;
    if (param_3 < 2) {
      *(int *)(param_1 + 0x18) = param_4;
      if (param_4 < 3) {
        *(long *)(param_1 + 0x78) = param_2;
        lVar2 = thunk_EXT_FUN_80110000038ff010();
        *(long *)(param_1 + 0x20) = lVar2;
        if (lVar2 == 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Failed to create queue Lock\n")
          ;
        }
        else {
          lVar2 = FUN_fffffff009944e20();
          *(long *)(param_1 + 0x38) = lVar2;
          if (lVar2 == 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                       "%s: Failed to create Command Buffer Namespace\n");
          }
          else {
            *(undefined8 *)(param_1 + 0x80) = 0;
            *(undefined8 **)(param_1 + 0x88) = (undefined8 *)(param_1 + 0x80);
            lVar2 = thunk_EXT_FUN_80110000038ff010();
            *(long *)(param_1 + 0x90) = lVar2;
            if (lVar2 == 0) {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                         "%s: Failed to create Active Command Buffers Lock\n");
            }
            else {
              lVar2 = thunk_EXT_FUN_80110000032770a0(FUN_fffffff00995acc0,param_1,1,1);
              *(long *)(param_1 + 0x98) = lVar2;
              if (lVar2 == 0) {
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                           "%s: Failed to create Submit IO Thread\n");
              }
              else {
                lVar2 = thunk_EXT_FUN_80110000038ff010();
                *(long *)(param_1 + 0xa0) = lVar2;
                if (lVar2 == 0) {
                  thunk_EXT_FUN_80110000038db19c
                            (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                             "%s: Failed to create Submit IO Thread Lock\n");
                }
                else {
                  *(undefined8 *)(param_1 + 0x58) = 0;
                  *(undefined8 **)(param_1 + 0x60) = (undefined8 *)(param_1 + 0x58);
                  lVar2 = thunk_EXT_FUN_80110000038ff010();
                  *(long *)(param_1 + 0x68) = lVar2;
                  if (lVar2 != 0) {
                    uVar3 = thunk_EXT_FUN_80110000038905f0(1,&DAT_fffffff00af220c0);
                    *(undefined8 *)(param_1 + 0x30) = uVar3;
                    if (DAT_fffffff00af227e8 == 0) {
                      return 1;
                    }
                    thunk_EXT_FUN_80110000036da494
                              (0x85090028,*(undefined8 *)(*(long *)(param_1 + 0x78) + 0x38),uVar3,0,
                               0,0);
                    return 1;
                  }
                  thunk_EXT_FUN_80110000038db19c
                            (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                             "%s: Failed to IO processing queue Lock\n");
                }
              }
            }
          }
        }
      }
      else {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid IO Queue Priority (%u)\n"
                  );
      }
    }
    else {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid IO Queue Type (%u)\n");
    }
  }
  if (DAT_fffffff00af227e8 != 0) {
    thunk_EXT_FUN_80110000036da494(0x8509002c,0,0,0,0,0);
  }
  return 0;
}

