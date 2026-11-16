// FUN_fffffff00890a41c @ fffffff00890a41c size=3896
// CALLERS:
//   fffffff00af7811e no-fn
//   fffffff008981cc4 FUN_fffffff008981be0@fffffff008981be0
// CALLEES:
//   fffffff00890b578 FUN_fffffff00890b578
//   fffffff008a4aff8 thunk_EXT_FUN_801100000369ae5c
//   fffffff008a0d018 FUN_fffffff008a0d018
//   fffffff008a4b008 thunk_EXT_FUN_801100000369c5e8
//   fffffff00890b354 FUN_fffffff00890b354
//   fffffff00890b90c FUN_fffffff00890b90c
//   fffffff008a4ae68 thunk_EXT_FUN_801100000389b3b0
//   fffffff0089875fc FUN_fffffff0089875fc
//   fffffff0089875d4 FUN_fffffff0089875d4
//   fffffff008a4a4e8 thunk_EXT_FUN_80110000038bf120
//   fffffff008a4a528 thunk_EXT_FUN_80110000038bf1ec
//   fffffff008a4b068 thunk_EXT_FUN_801100000335ae94

/* WARNING: Removing unreachable block (ram,0xfffffff00890b110) */

undefined8 FUN_fffffff00890a41c(long param_1,long param_2)

{
  undefined4 uVar1;
  long lVar2;
  byte *pbVar3;
  long *plVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  byte bVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  undefined8 uVar18;
  uint *puVar19;
  long lVar20;
  undefined8 local_70;
  undefined4 local_64;
  
  lVar20 = *(long *)(*(long *)(param_1 + 0x90) + 0x5d0);
  lVar16 = *(long *)(*(long *)(param_1 + 0x90) + 0x5d8);
  if (lVar16 != 0) {
    FUN_fffffff0089875d4(lVar16);
  }
  bVar7 = *(byte *)(lVar20 + 0x27e);
  lVar17 = *(long *)(param_1 + 0x78);
  if (lVar17 != 0) {
    thunk_EXT_FUN_80110000038bf120(lVar17);
  }
  if ((*(byte *)(param_1 + 0xc0) & 1) == 0) {
    thunk_EXT_FUN_801100000389b3b0
              (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
               "[ERROR] %s: %s: chaining request 0x%llx is no longer active\n");
    uVar18 = 0xe00002ee;
    goto LAB_fffffff00890a560;
  }
  puVar19 = (uint *)(param_2 + 0x20);
  if (*puVar19 < *(uint *)(param_1 + 0x3170)) {
    uVar18 = 0;
  }
  else {
    uVar18 = 0xe00002c2;
    thunk_EXT_FUN_801100000389b3b0
              (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
               "%s: %s: output set(0x%x) is larger than total set: 0x%x\n");
  }
  iVar8 = *(int *)(param_2 + 0x1c);
  if (iVar8 < 4) {
    if (iVar8 < 2) {
      if (iVar8 == 0) {
        if ((bVar7 & 1) == 0) {
          if ((DAT_fffffff00ae02f29 >> 6 & 1) != 0) {
            thunk_EXT_FUN_801100000389b3b0
                      (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                       "%s: %s: chaining event 0x%llx start with output set 0x%x\n");
          }
          thunk_EXT_FUN_801100000369ae5c
                    (0x61b00f8,*(undefined8 *)(param_1 + 0xe0),*(undefined4 *)(param_1 + 0xd0),
                     *(undefined8 *)(param_1 + 0xd8),*puVar19,0);
        }
        goto LAB_fffffff00890a560;
      }
      if (iVar8 == 1) {
        if ((DAT_fffffff00ae02f29 >> 6 & 1) != 0) {
          thunk_EXT_FUN_801100000389b3b0
                    (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                     "%s: %s: chaining event 0x%llx complete with output set 0x%x\n");
        }
        if ((bVar7 & 1) != 0) {
          uVar9 = FUN_fffffff008a0d018
                            (*(undefined8 *)(param_1 + 0xa8),*(undefined8 *)(param_2 + 0x430));
          thunk_EXT_FUN_801100000369c5e8
                    (*(undefined4 *)(*(long *)(param_1 + 0xa8) + 0x3bc8),0x61b0126,uVar9,
                     *(undefined8 *)(*(long *)(param_1 + 0x90) + 0xc0),
                     CONCAT44(*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18)),0,
                     *(undefined4 *)(param_1 + 0xe8),0);
        }
        lVar12 = *(long *)(param_1 + 0x3178);
        uVar13 = (ulong)*puVar19;
        lVar15 = uVar13 * 0x50 + 0x20;
        plVar4 = (long *)(lVar12 + (int)lVar15);
        if (lVar15 != (int)lVar15) {
          plVar4 = (long *)(lVar12 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
        }
        if ((*plVar4 != 0) && ((*(byte *)(*(long *)(param_1 + 0xb0) + 0x185) & 1) != 0)) {
          lVar15 = (ulong)*(uint *)(param_1 + 0xa0) * 8;
          plVar4 = (long *)(lVar20 + 0x120 + (long)(int)lVar15);
          if (lVar15 - (int)lVar15 != 0) {
            plVar4 = (long *)(lVar20 + 0x120 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
          }
          if (*plVar4 != 0) {
            FUN_fffffff00890b354(param_1,param_2);
            lVar12 = *(long *)(param_1 + 0x3178);
            uVar13 = (ulong)*(uint *)(param_2 + 0x20);
          }
        }
        lVar15 = uVar13 * 0x50 + 0x30;
        pbVar3 = (byte *)(lVar12 + (int)lVar15);
        if (lVar15 != (int)lVar15) {
          pbVar3 = (byte *)(lVar12 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
        }
        if ((*pbVar3 & 1) == 0) {
          FUN_fffffff00890b578(param_1,param_2);
          FUN_fffffff00890b90c(param_1,4,*(undefined4 *)(param_2 + 0x20));
          if (*(int *)(param_2 + 0x24) != 0) {
            uVar13 = 0;
            do {
              FUN_fffffff00890b90c(param_1,5,*(undefined4 *)(param_2 + 0x28 + uVar13 * 0x20));
              uVar13 = uVar13 + 1;
            } while (uVar13 < *(uint *)(param_2 + 0x24));
          }
          thunk_EXT_FUN_801100000369ae5c
                    (0x61b00f9,*(undefined8 *)(param_1 + 0xe0),*(undefined4 *)(param_1 + 0xd0),
                     *(undefined8 *)(param_1 + 0xd8),*puVar19,0);
        }
        else if ((DAT_fffffff00ae02f29 >> 6 & 1) != 0) {
          thunk_EXT_FUN_801100000389b3b0
                    (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                     "%s: %s: sharedEvents not required for output set: %d\n");
        }
        lVar12 = *(long *)(param_1 + 0x3178);
        uVar13 = (ulong)*puVar19;
        lVar15 = uVar13 * 0x50 + 0x31;
        pbVar3 = (byte *)(lVar12 + (int)lVar15);
        if (lVar15 != (int)lVar15) {
          pbVar3 = (byte *)(lVar12 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
        }
        if ((*pbVar3 & 1) == 0) {
          if ((DAT_fffffff00ae02f29 >> 6 & 1) != 0) {
            thunk_EXT_FUN_801100000389b3b0
                      (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                       "%s: %s: output set: %d is not for open loop\n");
          }
        }
        else {
          lVar15 = *(long *)(param_1 + 0x90);
          if ((*(byte *)(lVar15 + 0xc9) & 1) != 0) {
            thunk_EXT_FUN_801100000389b3b0
                      (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                       "%s: %s: program is aborted, stop looping back the output sets\n");
            goto LAB_fffffff00890a560;
          }
          lVar2 = *(long *)(param_1 + 0x3168) + 1;
          *(long *)(param_1 + 0x3168) = lVar2;
          uVar14 = uVar13 * 0x50 | 8;
          plVar4 = (long *)(lVar12 + (int)uVar14);
          if (uVar14 != (long)(int)uVar14) {
            plVar4 = (long *)(lVar12 + uVar14 & 0xffffffffffff | 0x2bad000000000000);
          }
          *plVar4 = lVar2;
          if ((DAT_fffffff00ae02f29 >> 6 & 1) != 0) {
            thunk_EXT_FUN_801100000389b3b0
                      (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                       "%s: %s: open loop output set: %d to firmware, next signal value: 0x%llx\n");
            lVar15 = *(long *)(param_1 + 0x90);
            uVar13 = (ulong)*puVar19;
          }
          thunk_EXT_FUN_801100000369ae5c
                    (0x61b00f1,*(undefined8 *)(lVar15 + 0xc0),*(undefined4 *)(param_1 + 0xd0),uVar13
                     ,*(undefined4 *)(lVar20 + 0x24c),0);
          iVar8 = (**(code **)(**(long **)(param_1 + 0xa8) + 0x608))
                            (*(long **)(param_1 + 0xa8),param_1 + 0xd8,puVar19,
                             *(long *)(param_1 + 0x90) + 0xc0);
          if (iVar8 != 0) {
            thunk_EXT_FUN_801100000389b3b0
                      (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                       "%s: %s: loopback output set %d send failed\n");
            goto LAB_fffffff00890a560;
          }
          thunk_EXT_FUN_801100000369ae5c
                    (0x61b00f2,*(undefined8 *)(*(long *)(param_1 + 0x90) + 0xc0),
                     *(undefined4 *)(param_1 + 0xd0),*puVar19,0,0);
        }
        if ((((*(byte *)(*(long *)(param_1 + 0x90) + 0xc9) & 1) == 0) &&
            (*(int *)(param_1 + 0x3158) != 0)) && (*(long *)(param_1 + 0x3160) != 0)) {
          local_70 = CONCAT44(local_70._4_4_,0x268);
          if ((DAT_fffffff00ae02f29 >> 6 & 1) != 0) {
            thunk_EXT_FUN_801100000389b3b0
                      (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                       "%s: %s: send cached non-blocking inputs\n");
          }
          lVar20 = thunk_EXT_FUN_801100000335ae94();
          lVar15 = *(long *)(param_1 + 0x3160);
          if (*(long *)(lVar15 + 0x218) != 0) {
            *(long *)(lVar15 + 0x218) = *(long *)(lVar15 + 0x218) + lVar20;
          }
          iVar8 = (**(code **)(**(long **)(param_1 + 0xa8) + 0x600))
                            (*(long **)(param_1 + 0xa8),lVar15,&local_70,
                             *(long *)(param_1 + 0x90) + 0xc0);
          lVar15 = *(long *)(*(long *)(param_1 + 0x3160) + 0x218);
          if (lVar15 != 0) {
            *(long *)(*(long *)(param_1 + 0x3160) + 0x218) = lVar15 - lVar20;
          }
          if (iVar8 != 0) {
            thunk_EXT_FUN_801100000389b3b0
                      (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                       "%s: %s: loopback nonblocking inputs (inputs#: %d) send  to firmware failed\n"
                      );
          }
        }
        goto LAB_fffffff00890a560;
      }
    }
    else {
      if (iVar8 == 2) {
        thunk_EXT_FUN_801100000389b3b0
                  (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                   "%s: %s: chaining event 0x%llx failed with output set 0x%x\n");
        if ((bVar7 & 1) == 0) goto LAB_fffffff00890a560;
        uVar9 = FUN_fffffff008a0d018
                          (*(undefined8 *)(param_1 + 0xa8),*(undefined8 *)(param_2 + 0x430));
        uVar5 = *(undefined4 *)(*(long *)(param_1 + 0xa8) + 0x3bc8);
        uVar10 = *(undefined8 *)(*(long *)(param_1 + 0x90) + 0xc0);
        uVar11 = CONCAT44(*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18));
        uVar6 = *(undefined4 *)(param_1 + 0xe8);
        uVar1 = 0x61b0126;
LAB_fffffff00890ad3c:
        thunk_EXT_FUN_801100000369c5e8(uVar5,uVar1,uVar9,uVar10,uVar11,0,uVar6,0);
        goto LAB_fffffff00890a560;
      }
      if (iVar8 == 3) {
        thunk_EXT_FUN_801100000389b3b0
                  (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                   "%s: %s: chaining event 0x%llx InputTriggerOverflow with output set 0x%x\n");
        goto LAB_fffffff00890a560;
      }
    }
  }
  else if (iVar8 < 6) {
    if (iVar8 == 4) {
      thunk_EXT_FUN_801100000389b3b0
                (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                 "%s: %s: chaining event 0x%llx OutputSetUnderflow with output set 0x%x\n");
      goto LAB_fffffff00890a560;
    }
    if (iVar8 == 5) {
      thunk_EXT_FUN_801100000389b3b0
                (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                 "%s: %s: chaining cacheHandle 0x%llx ProcDropped_ANEInSecureMode with output set 0x%x\n"
                );
      if ((*(int *)(param_1 + 0x3158) != 0) && (*(long *)(param_1 + 0x3160) != 0)) {
        local_64 = 0x268;
        if ((DAT_fffffff00ae02f29 >> 6 & 1) != 0) {
          thunk_EXT_FUN_801100000389b3b0
                    (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                     "%s: %s: chaining cacheHandle: 0x%llx send cached non-blocking inputs eAnsCmdDataChainingEvent_ProcDropped_ANEInSecureMode\n"
                    );
        }
        lVar20 = thunk_EXT_FUN_801100000335ae94();
        lVar15 = *(long *)(param_1 + 0x3160);
        if (*(long *)(lVar15 + 0x218) != 0) {
          *(long *)(lVar15 + 0x218) = *(long *)(lVar15 + 0x218) + lVar20;
        }
        local_70 = 0;
        iVar8 = (**(code **)(**(long **)(param_1 + 0xa8) + 0x600))
                          (*(long **)(param_1 + 0xa8),lVar15,&local_64,&local_70);
        lVar15 = *(long *)(*(long *)(param_1 + 0x3160) + 0x218);
        if (lVar15 != 0) {
          *(long *)(*(long *)(param_1 + 0x3160) + 0x218) = lVar15 - lVar20;
        }
        if (iVar8 != 0) {
          thunk_EXT_FUN_801100000389b3b0
                    (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                     "%s: %s: loopback nonblocking inputs (inputs#: %d) send  to firmware failed\n")
          ;
        }
      }
      goto LAB_fffffff00890a560;
    }
  }
  else if (iVar8 == 6) {
    thunk_EXT_FUN_801100000389b3b0
              (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
               "%s: %s: Invalidate event ignored - uuid: 0x%llx cacheHandle: 0x%llx cacheEventType: %u\n"
              );
  }
  else if (iVar8 == 7) {
    if ((DAT_fffffff00ae02f29 >> 6 & 1) != 0) {
      thunk_EXT_FUN_801100000389b3b0
                (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                 "%s: %s: chaining event 0x%llx startHw with output set 0x%x\n");
    }
    thunk_EXT_FUN_801100000369ae5c
              (0x61b00f8,*(undefined8 *)(param_1 + 0xe0),*(undefined4 *)(param_1 + 0xd0),
               *(undefined8 *)(param_1 + 0xd8),*(undefined4 *)(param_2 + 0x20),0);
    uVar9 = FUN_fffffff008a0d018(*(undefined8 *)(param_1 + 0xa8),*(undefined8 *)(param_2 + 0x430));
    uVar5 = *(undefined4 *)(*(long *)(param_1 + 0xa8) + 0x3bc8);
    uVar10 = *(undefined8 *)(*(long *)(param_1 + 0x90) + 0xc0);
    uVar11 = CONCAT44(*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18));
    uVar6 = *(undefined4 *)(param_1 + 0xe8);
    uVar1 = 0x61b0125;
    goto LAB_fffffff00890ad3c;
  }
  if ((DAT_fffffff00ae02f29 >> 6 & 1) != 0) {
    thunk_EXT_FUN_801100000389b3b0
              (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
               "%s: %s: Ignoring undefined chaining event: 0x%x\n");
  }
LAB_fffffff00890a560:
  if (lVar17 != 0) {
    thunk_EXT_FUN_80110000038bf1ec(lVar17);
  }
  if (lVar16 != 0) {
    FUN_fffffff0089875fc(lVar16);
  }
  return uVar18;
}

