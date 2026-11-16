// FUN_fffffff00a9e2eb8 @ fffffff00a9e2eb8 size=380
// CALLERS:
//   fffffff00afbfad8 ?
//   fffffff007c66a98 ?
// CALLS:
//   fffffff00aa4d114 FUN_fffffff00aa4d114
//   fffffff00a9e3034 FUN_fffffff00a9e3034

ulong FUN_fffffff00a9e2eb8
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                undefined8 param_8,undefined **param_9,ulong param_10,ulong param_11)

{
  long lVar1;
  undefined1 auVar2 [16];
  int iVar3;
  ulong uVar4;
  undefined **ppuVar5;
  ulong uVar6;
  undefined8 *puVar7;
  undefined8 extraout_d0;
  undefined8 extraout_var;
  undefined8 local_68;
  undefined8 *puStack_60;
  long local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = tpidr_el1;
  puVar7 = *(undefined8 **)(lVar1 + 0x288);
  if (puVar7 != (undefined8 *)0x0) {
    local_68 = *puVar7;
    puStack_60 = puVar7 + 0x60;
    uStack_50 = 0;
    local_58 = 0;
    local_48 = param_7 + 0x40;
    ppuVar5 = param_9;
    uVar4 = param_10;
    iVar3 = (**(code **)(*(long *)(param_7 + 0x10) + 0x20))(param_8,&local_68);
    if (iVar3 != 0) {
      auVar2._8_8_ = extraout_var;
      auVar2._0_8_ = extraout_d0;
      uVar4 = FUN_fffffff00a9e3034
                        (auVar2,param_2,param_3,param_4,param_5,param_6,param_7,(long)puVar7,ppuVar5
                         ,uVar4,param_11);
      if (uVar4 == 0) {
        return 0;
      }
      uVar6 = *(ulong *)(param_7 + 0x18) + uVar4 * 0x38;
      if (((*(ulong *)(param_7 + 0x18) ^ uVar6) & 0xffc0000000000000) != 0) {
        uVar6 = uVar6 & 0xffffffffffff | 0xc8a2000000000000;
      }
      local_58 = uVar6 + 0x11;
      uStack_50._0_4_ = 0x20;
      (**(code **)(*(long *)(param_7 + 0x10) + 0x28))
                (param_8,uVar4 | (ulong)*(byte *)(param_7 + 0xd) << 0x18,&local_68,param_9);
      uStack_50 = CONCAT44(uStack_50._4_4_,(undefined4)uStack_50) | 0x100000000;
      auVar2 = (**(code **)(*(long *)(param_7 + 0x10) + 0x30))
                         (param_8,uVar4 | (ulong)*(byte *)(param_7 + 0xd) << 0x18,&local_68,param_10
                         );
      if (uVar4 < *(ulong *)(param_7 + 0x20)) {
        uVar6 = *(ulong *)(param_7 + 0x18) + uVar4 * 0x38;
        if (((*(ulong *)(param_7 + 0x18) ^ uVar6) & 0xffc0000000000000) != 0) {
          uVar6 = uVar6 & 0xffffffffffff | 0xc8a2000000000000;
        }
        *(undefined1 *)(uVar6 + 0x10) = 1;
        return uVar4;
      }
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114
                (auVar2,param_2,param_3,param_4,param_5,param_6,
                 (byte *)"Invalid work token (%llu): index out of bounds. @%s:%d");
    }
  }
  return 0;
}

