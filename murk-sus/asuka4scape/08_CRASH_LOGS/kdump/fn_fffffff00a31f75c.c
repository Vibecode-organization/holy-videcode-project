// FUN_fffffff00a31f75c @ fffffff00a31f75c size=300
// CALLERS:
//   fffffff00afb9675 ?
//   fffffff00a3d6990 FUN_fffffff00a3d6418@fffffff00a3d6418
//   fffffff00a3d6dd0 FUN_fffffff00a3d6418@fffffff00a3d6418
//   fffffff00a3d7174 FUN_fffffff00a3d6418@fffffff00a3d6418
//   fffffff00a3db598 FUN_fffffff00a3db070@fffffff00a3db070
//   fffffff00a3dbd04 FUN_fffffff00a3db070@fffffff00a3db070
//   fffffff00a3dc000 FUN_fffffff00a3db070@fffffff00a3db070
// CALLS:
//   fffffff00aa4d114 FUN_fffffff00aa4d114
//   fffffff00a220c30 FUN_fffffff00a220c30
//   fffffff00aa65b10 FUN_fffffff00aa65b10

void FUN_fffffff00a31f75c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7)

{
  undefined8 *puVar1;
  long lVar2;
  ulong uVar3;
  uint *puVar4;
  ulong uVar5;
  long lVar6;
  undefined1 auVar7 [16];
  
  if (((param_7 != 0) && ((*(byte *)(param_7 + 0x19) >> 6 & 1) != 0)) &&
     (puVar4 = *(uint **)(param_7 + 0x40), puVar4 != (uint *)0x0)) {
    auVar7 = FUN_fffffff00a220c30
                       (param_1,param_2,param_3,param_4,param_5,param_6,
                        (long *)&DAT_fffffff007c82911,(ulong *)((ulong)(*puVar4 >> 0xb) & 0x1ffff8),
                        (ulong *)0x0,(undefined ********)0x0);
    *(long *)(puVar4 + 8) = auVar7._0_8_;
    if (puVar4[1] != 0) {
      uVar5 = 0;
      lVar6 = 0;
      do {
        puVar1 = (undefined8 *)(*(ulong *)(puVar4 + 8) + lVar6);
        if (((*(ulong *)(puVar4 + 8) ^ (ulong)puVar1) & 0xffc0000000000000) != 0) {
          puVar1 = (undefined8 *)((ulong)puVar1 & 0xffffffffffff | 0xc8a2000000000000);
        }
        lVar2 = *(long *)(puVar4 + uVar5 * 4 + 10);
        uVar3 = (ulong)((*(uint *)(lVar2 + 0x20) & 0x3fff) + *(int *)(lVar2 + 0x28) + 0x3fff >> 0xb)
                & 0x1ffff8;
        FUN_fffffff00aa65b10(puVar1,(undefined8 *)(lVar2 + 0x90),uVar3);
        if (*(uint *)(param_7 + 0x58) < *(uint *)(*(long *)(puVar4 + uVar5 * 4 + 10) + 0x58)) {
          *(uint *)(param_7 + 0x58) = *(uint *)(*(long *)(puVar4 + uVar5 * 4 + 10) + 0x58);
        }
        lVar6 = uVar3 + lVar6;
        uVar5 = uVar5 + 1;
      } while (uVar5 < puVar4[1]);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4d114
            (param_1,param_2,param_3,param_4,param_5,param_6,
             (byte *)"vector_upl_set_pagelist was passed a NULL upl @%s:%d");
}

