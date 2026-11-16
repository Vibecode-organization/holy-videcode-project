// FUN_fffffff009c178fc @ fffffff009c178fc size=560

/* WARNING: Removing unreachable block (ram,0xfffffff009c1796c) */

undefined8 FUN_fffffff009c178fc(long param_1,ulong param_2,undefined4 *param_3)

{
  undefined8 *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 *puVar6;
  
  uVar4 = 0xe00002c7;
  if (((*(byte *)(param_1 + 0x50) >> 1 & 1) != 0) &&
     (iVar3 = FUN_fffffff009c31488(0x80000), iVar3 == 0)) {
    if (**(ulong **)(param_1 + 0x20) < param_2) {
      iVar3 = FUN_fffffff009c18180(param_1);
      if (iVar3 == 0) {
        puVar6 = *(undefined8 **)(param_1 + 0x58);
        thunk_EXT_FUN_80110000032222a8(puVar6[0xd]);
        puVar2 = PTR_DAT_fffffff00806ca48;
        lVar5 = 0;
        do {
          if (((*(byte *)(puVar6 + lVar5 * 3 + 1) & 1) != 0) &&
             (*(ulong *)((long)(puVar6 + lVar5 * 3 + 1) + 8) == param_2))
          goto joined_r0xfffffff009c17ad0;
          lVar5 = lVar5 + 1;
        } while (lVar5 != 4);
        lVar5 = 0;
        puVar1 = puVar6;
        do {
          if ((*(byte *)(puVar6 + lVar5 * 3 + 1) & 1) == 0) {
            *(byte *)(puVar6 + lVar5 * 3 + 1) = 1;
            puVar1[2] = param_2;
            uVar4 = thunk_EXT_FUN_8011000003397c88();
            puVar1[3] = uVar4;
joined_r0xfffffff009c17ad0:
            if (param_3 == (undefined4 *)0x0) {
              uVar4 = 0;
            }
            else {
              uVar4 = 0;
              *param_3 = (int)lVar5;
            }
            goto LAB_fffffff009c17ad8;
          }
          lVar5 = lVar5 + 1;
          puVar1 = puVar1 + 3;
        } while (lVar5 != 4);
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "%s: No free agent mask slots available for event ID %08x (signal value 0x%016llx)\n"
                  );
        thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar2,0x10,"  Currently allocated slots:\n");
        lVar5 = 0;
        do {
          if ((*(byte *)(puVar6 + lVar5 * 3 + 1) & 1) != 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,puVar2,0x10,
                       "    Slot[%u]: SignalValue=0x%016llx Timestamp=%llu\n");
          }
          lVar5 = lVar5 + 1;
        } while (lVar5 != 4);
        iVar3 = FUN_fffffff009c31488(0x100000);
        if (iVar3 != 0) {
          uVar4 = thunk_EXT_FUN_8011000003a49114
                            (
                            "\"%s: Agent mask slot exhaustion detected (event ID %08x, signal value 0x%016llx)\" @%s:%d"
                            );
          return uVar4;
        }
        uVar4 = 0xe00002db;
LAB_fffffff009c17ad8:
        thunk_EXT_FUN_8011000003222de0(puVar6[0xd]);
        return uVar4;
      }
      uVar4 = 0xe00002bd;
    }
    else {
      uVar4 = 0xe0000001;
    }
  }
  return uVar4;
}

