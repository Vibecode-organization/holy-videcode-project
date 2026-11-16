// FUN_fffffff008a282a4 @ fffffff008a282a4 size=1
// CALLERS:
// CALLEES:

void FUN_fffffff008a282a4(long param_1,long param_2,ulong *param_3)

{
  ulong uVar1;
  undefined *puVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  int iStack_7c;
  ulong uStack_70;
  ulong uStack_68;
  
  uStack_70 = *param_3;
  if ((param_2 < 1) || (6 < param_2)) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0x10,
               "[ERROR] %s: %s: Invalid endpoint index: %ld\n");
  }
  else {
    uVar10 = param_1 + 0x5c8U + param_2 * 0x40;
    if (((param_1 + 0x5c8U ^ uVar10) & 0xffc0000000000000) != 0) {
      uVar10 = uVar10 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if (*(long *)(uVar10 + 0x28) == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0x10,
                 "[ERROR] %s: %s: Endpoint[%ld] is NULL, ignoring message");
    }
    else {
      lVar4 = thunk_EXT_FUN_8011000003397c88();
      puVar2 = PTR_DAT_fffffff007ddeaa8;
      iStack_7c = 0;
      do {
        lVar5 = *(long *)(uVar10 + 0x18);
        if ((lVar5 == 0) || (*(long *)(lVar5 + 0x30) == 0)) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,puVar2,0x10,
                     "[ERROR] %s: %s: Endpoint[%ld] surfaceParams not initialized, ignoring message"
                    );
        }
        else {
          uVar7 = uStack_70 >> 0x2c & 0xff;
          uVar8 = uStack_70 >> 0x34 & 3;
          uVar9 = uVar7 << 0x14;
          if (uVar8 != 2) {
            uVar9 = uVar7 << 0x15;
          }
          uVar1 = 0;
          if (uVar8 != 0) {
            uVar1 = uVar7 << 0xc;
          }
          if (uVar8 < 2) {
            uVar9 = uVar1;
          }
          uVar7 = *(ulong *)(uVar10 + 8);
          if ((long)(uStack_70 << 0x14) >> 0x14 == *(long *)(lVar5 + 0x18) && uVar9 == uVar7) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,puVar2,0,"%s: %s: ACK received for endpoint index %ld name %s\n"
                      );
            *(undefined1 *)(uVar10 + 0x38) = 1;
          }
          else {
            uVar9 = uStack_70 & 0xffffff;
            uVar8 = uStack_70 >> 0x18 & 0xffffff;
            if (((uVar8 == 0) || (uVar7 <= uVar9)) || (uVar7 < uVar8 + uVar9)) {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,puVar2,0x10,
                         "[ERROR] %s: %s: Invalid offset[0x%llx] and size[0x%llx] for endpoint[%ld] bufferSize[0x%zx]. Out of bounds message"
                        );
            }
            else if (param_2 < 4) {
              if (param_2 - 2U < 2) {
                iVar3 = FUN_fffffff008a1754c(param_1,*(long *)(lVar5 + 0x38) + uVar9,uVar8,0);
                if (iVar3 != 0) {
                  thunk_EXT_FUN_80110000038db19c
                            (&MACH_HEADER,puVar2,0x10,
                             "[ERROR] %s: %s: Could not process command response for endpoint: %ld bufferLocation:%llx, size 0x%llx, result=0x%x\n"
                            );
                }
              }
              else if (uVar8 < 0x88) {
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,puVar2,0x10,
                           "[ERROR] %s: %s: Endpoint[%ld] message too small for handshake info: offset[0x%llx] size[0x%llx]\n"
                          );
              }
              else {
                *(byte *)(param_1 + 0x3a8d) =
                     (byte)*(undefined4 *)(*(long *)(lVar5 + 0x38) + uVar9) & 1;
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,puVar2,0,
                           "%s: %s: RTBuddy endpoint: %ld name: %s fFirmwareUnitTestMode %d\n");
              }
            }
            else if (param_2 == 4) {
              iVar3 = FUN_fffffff008a22568(param_1,uVar9,uVar8);
              if (iVar3 != 0) {
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,puVar2,0x10,
                           "[ERROR] %s: %s: Could not process shared memory request for endpoint: %ld offset:0x%llx, size:0x%llx, result:0x%x\n"
                          );
              }
            }
            else if (param_2 == 5) {
              if (uVar8 < 8) {
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,puVar2,0x10,
                           "[ERROR] %s: %s: Endpoint[%ld] message too small for command header: offset[0x%llx] size[0x%llx]\n"
                          );
              }
              else {
                lVar5 = *(long *)(lVar5 + 0x38);
                if ((DAT_fffffff00ae430b1 >> 2 & 1) != 0) {
                  thunk_EXT_FUN_80110000038db19c
                            (&MACH_HEADER,puVar2,0,
                             "%s: %s: MBI_ENDPOINT_FW_TO_HOST_CMDS_INDEX: virtualAddress 0%llx offset %lld size %lld\n"
                            );
                }
                iVar3 = FUN_fffffff0089da0b0(param_1,lVar5 + uVar9,uVar8,0);
                if (iVar3 != 0) {
                  thunk_EXT_FUN_80110000038db19c
                            (&MACH_HEADER,puVar2,0x10,
                             "[ERROR] %s: %s: Could not process FW to host command for endpoint: %ld bufferLocation:%llx, size 0x%llx, result=0x%x\n"
                            );
                }
              }
            }
            else {
              lVar6 = *(long *)(lVar5 + 0x38);
              lVar5 = thunk_EXT_FUN_8011000003397c88();
              uStack_68 = 0;
              thunk_EXT_FUN_8011000003398228(lVar5 - lVar4,&uStack_68);
              if ((uStack_68 < 50000000) || (iStack_7c == 0)) {
                iStack_7c = iStack_7c + 1;
                FUN_fffffff008a0bb58(param_1,lVar6 + uVar9,uVar8,0);
              }
            }
          }
        }
        iVar3 = thunk_EXT_FUN_8011000002f45e24(*(undefined8 *)(uVar10 + 0x28),&uStack_70,0);
      } while (iVar3 == 0);
    }
  }
  return;
}

