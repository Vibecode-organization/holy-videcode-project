// FUN_fffffff008986cb0 @ fffffff008986cb0 size=4052
// CALLERS:
//   fffffff00afb855c no-fn
//   fffffff0089b4534 FUN_fffffff0089b4450@fffffff0089b4450
// CALLEES:
//   fffffff008a82064 thunk_EXT_FUN_80110000036da494
//   fffffff008987c84 FUN_fffffff008987c84
//   fffffff008987ea8 FUN_fffffff008987ea8
//   fffffff00898823c FUN_fffffff00898823c
//   fffffff008a820d4 thunk_EXT_FUN_8011000003397c88
//   fffffff0089c46a4 FUN_fffffff0089c46a4
//   fffffff008a81534 thunk_EXT_FUN_80110000038ff214
//   fffffff0089c46cc FUN_fffffff0089c46cc
//   fffffff008a82074 thunk_EXT_FUN_80110000036dbc20
//   fffffff008a81574 thunk_EXT_FUN_80110000038ff2e0
//   fffffff008a81ed4 thunk_EXT_FUN_80110000038db19c
//   fffffff008a37d00 FUN_fffffff008a37d00

/* WARNING: Removing unreachable block (ram,0xfffffff008987a40) */

undefined8 FUN_fffffff008986cb0(long param_1,long param_2)

{
  undefined4 uVar1;
  long lVar2;
  byte *pbVar3;
  long *plVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  byte bVar7;
  bool bVar8;
  int iVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  uint uVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  undefined8 uVar20;
  uint *puVar21;
  long lVar22;
  undefined8 local_70;
  undefined4 local_64;
  
  lVar22 = *(long *)(*(long *)(param_1 + 0xa0) + 0x5d0);
  lVar18 = *(long *)(*(long *)(param_1 + 0xa0) + 0x5d8);
  if (lVar18 != 0) {
    FUN_fffffff0089c46a4(lVar18);
  }
  bVar7 = *(byte *)(lVar22 + 0x2b6);
  lVar19 = *(long *)(param_1 + 0x88);
  if (lVar19 != 0) {
    thunk_EXT_FUN_80110000038ff214(lVar19);
  }
  if ((*(byte *)(param_1 + 0xd0) & 1) == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0x10,
               "[ERROR] %s: %s: chaining request 0x%llx is no longer active\n");
    uVar20 = 0xe00002ee;
    goto LAB_fffffff008986df4;
  }
  puVar21 = (uint *)(param_2 + 0x20);
  if (*puVar21 < *(uint *)(param_1 + 0x3180)) {
    uVar20 = 0;
  }
  else {
    uVar20 = 0xe00002c2;
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
               "%s: %s: output set(0x%x) is larger than total set: 0x%x\n");
  }
  iVar9 = *(int *)(param_2 + 0x1c);
  if (iVar9 < 4) {
    if (iVar9 < 2) {
      if (iVar9 == 0) {
        if ((bVar7 & 1) == 0) {
          if ((DAT_fffffff00ae430b1 >> 6 & 1) != 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                       "%s: %s: chaining event 0x%llx start with output set 0x%x\n");
          }
          thunk_EXT_FUN_80110000036da494
                    (0x61b00f8,*(undefined8 *)(param_1 + 0xf0),*(undefined4 *)(param_1 + 0xe0),
                     *(undefined8 *)(param_1 + 0xe8),*puVar21,0);
        }
        goto LAB_fffffff008986df4;
      }
      if (iVar9 == 1) {
        if ((DAT_fffffff00ae430b1 >> 6 & 1) != 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                     "%s: %s: chaining event 0x%llx complete with output set 0x%x\n");
        }
        uVar13 = *puVar21;
        if (*(uint *)(param_1 + 0x3180) <= uVar13) goto LAB_fffffff008986df4;
        if ((bVar7 & 1) != 0) {
          uVar10 = FUN_fffffff008a37d00
                             (*(undefined8 *)(param_1 + 0xb8),*(undefined8 *)(param_2 + 0x430));
          thunk_EXT_FUN_80110000036dbc20
                    (*(undefined4 *)(*(long *)(param_1 + 0xb8) + 0x3bd0),0x61b0126,uVar10,
                     *(undefined8 *)(*(long *)(param_1 + 0xa0) + 0xc0),
                     CONCAT44(*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18)),0,
                     *(undefined4 *)(param_1 + 0xf8),0);
          uVar13 = *(uint *)(param_2 + 0x20);
        }
        uVar14 = (ulong)uVar13;
        lVar15 = *(long *)(param_1 + 0x3188);
        lVar17 = uVar14 * 0x50 + 0x20;
        plVar4 = (long *)(lVar15 + (int)lVar17);
        if (lVar17 != (int)lVar17) {
          plVar4 = (long *)(lVar15 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
        }
        if ((*plVar4 != 0) && ((*(byte *)(*(long *)(param_1 + 0xc0) + 0x199) & 1) != 0)) {
          lVar17 = (ulong)*(uint *)(param_1 + 0xb0) * 8;
          plVar4 = (long *)(lVar22 + 0x138 + (long)(int)lVar17);
          if (lVar17 - (int)lVar17 != 0) {
            plVar4 = (long *)(lVar22 + 0x138 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
          }
          if (*plVar4 != 0) {
            FUN_fffffff008987c84(param_1,param_2);
            lVar15 = *(long *)(param_1 + 0x3188);
            uVar14 = (ulong)*(uint *)(param_2 + 0x20);
          }
        }
        lVar17 = uVar14 * 0x50 + 0x30;
        pbVar3 = (byte *)(lVar15 + (int)lVar17);
        if (lVar17 != (int)lVar17) {
          pbVar3 = (byte *)(lVar15 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
        }
        if ((*pbVar3 & 1) == 0) {
          FUN_fffffff008987ea8(param_1,param_2);
          FUN_fffffff00898823c(param_1,4,*(undefined4 *)(param_2 + 0x20));
          uVar13 = *(uint *)(param_2 + 0x24);
          if (0x20 < uVar13) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0x10,
                       "[ERROR] %s: %s: Firmware reported %u chaining input buffers, clamping to %u\n"
                      );
            uVar13 = *(uint *)(param_2 + 0x24);
          }
          if (uVar13 != 0) {
            uVar14 = 0;
            do {
              FUN_fffffff00898823c(param_1,5,*(undefined4 *)(param_2 + 0x28 + uVar14 * 0x20));
              uVar16 = uVar14 + 1;
              bVar8 = uVar14 < 0x1f;
              uVar14 = uVar16;
            } while (uVar16 < *(uint *)(param_2 + 0x24) && bVar8);
          }
          thunk_EXT_FUN_80110000036da494
                    (0x61b00f9,*(undefined8 *)(param_1 + 0xf0),*(undefined4 *)(param_1 + 0xe0),
                     *(undefined8 *)(param_1 + 0xe8),*puVar21,0);
        }
        else if ((DAT_fffffff00ae430b1 >> 6 & 1) != 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                     "%s: %s: sharedEvents not required for output set: %d\n");
        }
        lVar15 = *(long *)(param_1 + 0x3188);
        uVar14 = (ulong)*puVar21;
        lVar17 = uVar14 * 0x50 + 0x31;
        pbVar3 = (byte *)(lVar15 + (int)lVar17);
        if (lVar17 != (int)lVar17) {
          pbVar3 = (byte *)(lVar15 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
        }
        if ((*pbVar3 & 1) == 0) {
          if ((DAT_fffffff00ae430b1 >> 6 & 1) != 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                       "%s: %s: output set: %d is not for open loop\n");
          }
        }
        else {
          lVar17 = *(long *)(param_1 + 0xa0);
          if ((*(byte *)(lVar17 + 0xc9) & 1) != 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                       "%s: %s: program is aborted, stop looping back the output sets\n");
            goto LAB_fffffff008986df4;
          }
          lVar2 = *(long *)(param_1 + 0x3178) + 1;
          *(long *)(param_1 + 0x3178) = lVar2;
          uVar16 = uVar14 * 0x50 | 8;
          plVar4 = (long *)(lVar15 + (int)uVar16);
          if (uVar16 != (long)(int)uVar16) {
            plVar4 = (long *)(lVar15 + uVar16 & 0xffffffffffff | 0x2bad000000000000);
          }
          *plVar4 = lVar2;
          if ((DAT_fffffff00ae430b1 >> 6 & 1) != 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                       "%s: %s: open loop output set: %d to firmware, next signal value: 0x%llx\n");
            lVar17 = *(long *)(param_1 + 0xa0);
            uVar14 = (ulong)*puVar21;
          }
          thunk_EXT_FUN_80110000036da494
                    (0x61b00f1,*(undefined8 *)(lVar17 + 0xc0),*(undefined4 *)(param_1 + 0xe0),uVar14
                     ,*(undefined4 *)(lVar22 + 0x284),0);
          iVar9 = (**(code **)(**(long **)(param_1 + 0xb8) + 0x608))
                            (*(long **)(param_1 + 0xb8),param_1 + 0xe8,puVar21,
                             *(long *)(param_1 + 0xa0) + 0xc0);
          if (iVar9 != 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                       "%s: %s: loopback output set %d send failed\n");
            goto LAB_fffffff008986df4;
          }
          thunk_EXT_FUN_80110000036da494
                    (0x61b00f2,*(undefined8 *)(*(long *)(param_1 + 0xa0) + 0xc0),
                     *(undefined4 *)(param_1 + 0xe0),*puVar21,0,0);
        }
        if ((((*(byte *)(*(long *)(param_1 + 0xa0) + 0xc9) & 1) == 0) &&
            (*(int *)(param_1 + 0x3168) != 0)) && (*(long *)(param_1 + 0x3170) != 0)) {
          local_70 = CONCAT44(local_70._4_4_,0x268);
          if ((DAT_fffffff00ae430b1 >> 6 & 1) != 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                       "%s: %s: send cached non-blocking inputs\n");
          }
          lVar22 = thunk_EXT_FUN_8011000003397c88();
          lVar17 = *(long *)(param_1 + 0x3170);
          if (*(long *)(lVar17 + 0x218) != 0) {
            *(long *)(lVar17 + 0x218) = *(long *)(lVar17 + 0x218) + lVar22;
          }
          iVar9 = (**(code **)(**(long **)(param_1 + 0xb8) + 0x600))
                            (*(long **)(param_1 + 0xb8),lVar17,&local_70,
                             *(long *)(param_1 + 0xa0) + 0xc0);
          lVar17 = *(long *)(*(long *)(param_1 + 0x3170) + 0x218);
          if (lVar17 != 0) {
            *(long *)(*(long *)(param_1 + 0x3170) + 0x218) = lVar17 - lVar22;
          }
          if (iVar9 != 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                       "%s: %s: loopback nonblocking inputs (inputs#: %d) send  to firmware failed\n"
                      );
          }
        }
        goto LAB_fffffff008986df4;
      }
    }
    else {
      if (iVar9 == 2) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                   "%s: %s: chaining event 0x%llx failed with output set 0x%x\n");
        if ((bVar7 & 1) == 0) goto LAB_fffffff008986df4;
        uVar10 = FUN_fffffff008a37d00
                           (*(undefined8 *)(param_1 + 0xb8),*(undefined8 *)(param_2 + 0x430));
        uVar5 = *(undefined4 *)(*(long *)(param_1 + 0xb8) + 0x3bd0);
        uVar11 = *(undefined8 *)(*(long *)(param_1 + 0xa0) + 0xc0);
        uVar12 = CONCAT44(*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18));
        uVar6 = *(undefined4 *)(param_1 + 0xf8);
        uVar1 = 0x61b0126;
LAB_fffffff00898758c:
        thunk_EXT_FUN_80110000036dbc20(uVar5,uVar1,uVar10,uVar11,uVar12,0,uVar6,0);
        goto LAB_fffffff008986df4;
      }
      if (iVar9 == 3) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                   "%s: %s: chaining event 0x%llx InputTriggerOverflow with output set 0x%x\n");
        goto LAB_fffffff008986df4;
      }
    }
  }
  else if (iVar9 < 6) {
    if (iVar9 == 4) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                 "%s: %s: chaining event 0x%llx OutputSetUnderflow with output set 0x%x\n");
      goto LAB_fffffff008986df4;
    }
    if (iVar9 == 5) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                 "%s: %s: chaining cacheHandle 0x%llx ProcDropped_ANEInSecureMode with output set 0x%x\n"
                );
      if ((*(int *)(param_1 + 0x3168) != 0) && (*(long *)(param_1 + 0x3170) != 0)) {
        local_64 = 0x268;
        if ((DAT_fffffff00ae430b1 >> 6 & 1) != 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                     "%s: %s: chaining cacheHandle: 0x%llx send cached non-blocking inputs eAnsCmdDataChainingEvent_ProcDropped_ANEInSecureMode\n"
                    );
        }
        lVar22 = thunk_EXT_FUN_8011000003397c88();
        lVar17 = *(long *)(param_1 + 0x3170);
        if (*(long *)(lVar17 + 0x218) != 0) {
          *(long *)(lVar17 + 0x218) = *(long *)(lVar17 + 0x218) + lVar22;
        }
        local_70 = 0;
        iVar9 = (**(code **)(**(long **)(param_1 + 0xb8) + 0x600))
                          (*(long **)(param_1 + 0xb8),lVar17,&local_64,&local_70);
        lVar17 = *(long *)(*(long *)(param_1 + 0x3170) + 0x218);
        if (lVar17 != 0) {
          *(long *)(*(long *)(param_1 + 0x3170) + 0x218) = lVar17 - lVar22;
        }
        if (iVar9 != 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                     "%s: %s: loopback nonblocking inputs (inputs#: %d) send  to firmware failed\n")
          ;
        }
      }
      goto LAB_fffffff008986df4;
    }
  }
  else if (iVar9 == 6) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
               "%s: %s: Invalidate event ignored - uuid: 0x%llx cacheHandle: 0x%llx cacheEventType: %u\n"
              );
  }
  else if (iVar9 == 7) {
    if ((DAT_fffffff00ae430b1 >> 6 & 1) != 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                 "%s: %s: chaining event 0x%llx startHw with output set 0x%x\n");
    }
    thunk_EXT_FUN_80110000036da494
              (0x61b00f8,*(undefined8 *)(param_1 + 0xf0),*(undefined4 *)(param_1 + 0xe0),
               *(undefined8 *)(param_1 + 0xe8),*(undefined4 *)(param_2 + 0x20),0);
    uVar10 = FUN_fffffff008a37d00(*(undefined8 *)(param_1 + 0xb8),*(undefined8 *)(param_2 + 0x430));
    uVar5 = *(undefined4 *)(*(long *)(param_1 + 0xb8) + 0x3bd0);
    uVar11 = *(undefined8 *)(*(long *)(param_1 + 0xa0) + 0xc0);
    uVar12 = CONCAT44(*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18));
    uVar6 = *(undefined4 *)(param_1 + 0xf8);
    uVar1 = 0x61b0125;
    goto LAB_fffffff00898758c;
  }
  if ((DAT_fffffff00ae430b1 >> 6 & 1) != 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
               "%s: %s: Ignoring undefined chaining event: 0x%x\n");
  }
LAB_fffffff008986df4:
  if (lVar19 != 0) {
    thunk_EXT_FUN_80110000038ff2e0(lVar19);
  }
  if (lVar18 != 0) {
    FUN_fffffff0089c46cc(lVar18);
  }
  return uVar20;
}

