// FUN_fffffff009c17b2c @ fffffff009c17b2c size=380

undefined8 FUN_fffffff009c17b2c(long param_1,long param_2,uint param_3,ulong param_4)

{
  long lVar1;
  byte *pbVar2;
  ulong uVar3;
  int iVar4;
  long lVar5;
  ulong *puVar6;
  undefined8 uVar7;
  ulong *puVar8;
  
  uVar7 = 0xe00002c7;
  if (((*(byte *)(param_1 + 0x50) >> 1 & 1) != 0) &&
     (iVar4 = FUN_fffffff009c31488(0x80000), iVar4 == 0)) {
    if ((param_3 < 4) && (puVar8 = *(ulong **)(param_1 + 0x58), puVar8 != (ulong *)0x0)) {
      thunk_EXT_FUN_80110000032222a8(puVar8[0xd]);
      lVar1 = (ulong)param_3 * 2 + (ulong)param_3;
      lVar5 = lVar1 * 8;
      iVar4 = (int)lVar5;
      pbVar2 = (byte *)((long)puVar8 + (long)iVar4 + 8);
      if (lVar5 - iVar4 != 0) {
        pbVar2 = (byte *)((ulong)(puVar8 + lVar1 + 1) & 0xffffffffffff | 0x2bad000000000000);
      }
      if (((*pbVar2 & 1) != 0) && (*(long *)(pbVar2 + 8) == param_2)) {
        puVar6 = (ulong *)(*puVar8 + (ulong)param_3 * 8);
        if (((*puVar8 ^ (ulong)puVar6) & 0xffc0000000000000) != 0) {
          puVar6 = (ulong *)((ulong)puVar6 & 0xffffffffffff | 0xc8a2000000000000);
        }
        LOAcquire();
        uVar3 = *puVar6;
        *puVar6 = uVar3 | param_4;
        LORelease();
        thunk_EXT_FUN_8011000003222de0(uVar3,puVar8[0xd]);
        return 0;
      }
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "%s: slot index %u validation failed: allocated=%s, signal value 0x%016llx (expected 0x%016llx) for event %08x\n"
                );
      thunk_EXT_FUN_8011000003222de0(puVar8[0xd]);
    }
    else {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "%s: slot index %u out of range or no agent mask info for event %08x (signal value 0x%016llx)\n"
                );
    }
    uVar7 = 0xe00002f0;
  }
  return uVar7;
}

