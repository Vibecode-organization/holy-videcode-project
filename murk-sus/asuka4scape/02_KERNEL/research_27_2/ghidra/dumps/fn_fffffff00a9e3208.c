// FUN_fffffff00a9e3208 @ fffffff00a9e3208 size=244
// CALLERS:
//   fffffff00afbfadc no-fn
//   fffffff007c66a90 no-fn
// CALLEES:
//   fffffff00a9e3034 FUN_fffffff00a9e3034

ulong FUN_fffffff00a9e3208
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
  undefined8 local_58;
  undefined8 *puStack_50;
  long local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = tpidr_el1;
  puVar7 = *(undefined8 **)(lVar1 + 0x288);
  if (puVar7 != (undefined8 *)0x0) {
    local_58 = *puVar7;
    puStack_50 = puVar7 + 0x60;
    uStack_40 = 0;
    local_48 = 0;
    local_38 = param_7 + 0x40;
    ppuVar5 = param_9;
    iVar3 = (**(code **)(*(long *)(param_7 + 0x10) + 0x20))(param_8,&local_58);
    if (iVar3 != 0) {
      auVar2._8_8_ = extraout_var;
      auVar2._0_8_ = extraout_d0;
      uVar4 = FUN_fffffff00a9e3034
                        (auVar2,param_2,param_3,param_4,param_5,param_6,param_7,(long)puVar7,ppuVar5
                         ,param_10,param_11);
      if (uVar4 == 0) {
        return 0;
      }
      uVar6 = *(ulong *)(param_7 + 0x18) + uVar4 * 0x38;
      if (((*(ulong *)(param_7 + 0x18) ^ uVar6) & 0xffc0000000000000) != 0) {
        uVar6 = uVar6 & 0xffffffffffff | 0xc8a2000000000000;
      }
      local_48 = uVar6 + 0x11;
      uStack_40 = CONCAT44(uStack_40._4_4_,0x20);
      (**(code **)(*(long *)(param_7 + 0x10) + 0x28))
                (param_8,uVar4 | (ulong)*(byte *)(param_7 + 0xd) << 0x18,&local_58,param_9);
      return uVar4;
    }
  }
  return 0;
}

