// FUN_fffffff0081d10b8 @ fffffff0081d10b8 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff0081d11d4) */

undefined8 FUN_fffffff0081d10b8(long *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  long *plVar4;
  long lVar5;
  undefined4 *puVar6;
  undefined1 uStack_31;
  
  param_1[0x292] = 0;
  param_1[0x291] = 0;
  param_1[0x290] = 0;
  param_1[0x28f] = 0;
  param_1[0x28e] = 0;
  param_1[0x28d] = 0;
  param_1[0x28c] = 0;
  *(undefined4 *)(param_1 + 0x28b) = 1;
  iVar1 = FUN_fffffff0081ac17c();
  if (iVar1 != 0) {
    if (param_1[0x17d] != 0) {
      uVar2 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca0fc8,0x30);
      lVar5 = param_1[0x123];
      puVar3 = (undefined8 *)thunk_EXT_FUN_8011000001301968();
      *puVar3 = &DAT_fffffff007c96228;
      puVar3[5] = lVar5 + 0x544;
      param_1[0x377] = (long)puVar3;
      uStack_31 = 0;
      (**(code **)(*(long *)param_1[0x17d] + 0x80))((long *)param_1[0x17d],&uStack_31,uVar2,0);
    }
    uVar2 = (**(code **)(*param_1 + 0x208))(param_1,param_1[0x298],0);
    *(undefined8 *)(param_1[0x122] + 0x4be0) = uVar2;
    uVar2 = (**(code **)(*param_1 + 0x208))(*param_1 + 0x208,param_1,param_1[0x299],0);
    *(undefined8 *)(param_1[0x122] + 0x4be8) = uVar2;
    puVar6 = (undefined4 *)param_1[0x296];
    *puVar6 = 0;
    puVar6[4] = 0;
    lVar5 = param_1[0x122];
    *(undefined8 *)(lVar5 + 0x4bf0) = 0;
    *(undefined4 *)(lVar5 + 0x4c00) = 0;
    *(undefined4 *)(lVar5 + 0x4c10) = 0;
    *(long *)(param_1[0x58] + 0x3b98) = param_1[0x6e];
    *(undefined4 *)(param_1 + 0x37e) = 0;
    lVar5 = param_1[0x101];
    *(undefined8 *)(lVar5 + 0x4a9) = 0;
    *(undefined8 *)(lVar5 + 0x4a1) = 0;
    *(undefined8 *)(lVar5 + 0x4b9) = 0;
    *(undefined8 *)(lVar5 + 0x4b1) = 0;
    lVar5 = param_1[0x69];
    *(undefined8 *)(lVar5 + 0x808) = 0;
    *(undefined8 *)(lVar5 + 0x800) = 0;
    *(undefined8 *)(lVar5 + 0x818) = 0;
    *(undefined8 *)(lVar5 + 0x810) = 0;
    *(undefined8 *)(lVar5 + 0x828) = 0;
    *(undefined8 *)(lVar5 + 0x820) = 0;
    *(undefined8 *)(lVar5 + 0x838) = 0;
    *(undefined8 *)(lVar5 + 0x830) = 0;
    *(undefined8 *)(lVar5 + 0x848) = 0;
    *(undefined8 *)(lVar5 + 0x840) = 0;
    *(undefined8 *)(lVar5 + 0x858) = 0;
    *(undefined8 *)(lVar5 + 0x850) = 0;
    *(undefined8 *)(lVar5 + 0x868) = 0;
    *(undefined8 *)(lVar5 + 0x860) = 0;
    *(undefined8 *)(lVar5 + 0x878) = 0;
    *(undefined8 *)(lVar5 + 0x870) = 0;
    *(undefined8 *)(lVar5 + 0x888) = 0;
    *(undefined8 *)(lVar5 + 0x880) = 0;
    *(undefined8 *)(lVar5 + 0x898) = 0;
    *(undefined8 *)(lVar5 + 0x890) = 0;
    *(undefined8 *)(lVar5 + 0x8a8) = 0;
    *(undefined8 *)(lVar5 + 0x8a0) = 0;
    *(undefined8 *)(lVar5 + 0x8b8) = 0;
    *(undefined8 *)(lVar5 + 0x8b0) = 0;
    *(undefined8 *)(lVar5 + 0x8c8) = 0;
    *(undefined8 *)(lVar5 + 0x8c0) = 0;
    *(undefined8 *)(lVar5 + 0x8d8) = 0;
    *(undefined8 *)(lVar5 + 0x8d0) = 0;
    *(undefined8 *)(lVar5 + 0x8e8) = 0;
    *(undefined8 *)(lVar5 + 0x8e0) = 0;
    *(undefined8 *)(lVar5 + 0x8f8) = 0;
    *(undefined8 *)(lVar5 + 0x8f0) = 0;
    *(undefined8 *)(lVar5 + 0x908) = 0;
    *(undefined8 *)(lVar5 + 0x900) = 0;
    *(undefined8 *)(lVar5 + 0x918) = 0;
    *(undefined8 *)(lVar5 + 0x910) = 0;
    *(undefined8 *)(lVar5 + 0x928) = 0;
    *(undefined8 *)(lVar5 + 0x920) = 0;
    *(undefined8 *)(lVar5 + 0x938) = 0;
    *(undefined8 *)(lVar5 + 0x930) = 0;
    *(undefined8 *)(lVar5 + 0x948) = 0;
    *(undefined8 *)(lVar5 + 0x940) = 0;
    *(undefined8 *)(lVar5 + 0x958) = 0;
    *(undefined8 *)(lVar5 + 0x950) = 0;
    *(undefined8 *)(lVar5 + 0x968) = 0;
    *(undefined8 *)(lVar5 + 0x960) = 0;
    *(undefined8 *)(lVar5 + 0x978) = 0;
    *(undefined8 *)(lVar5 + 0x970) = 0;
    *(undefined8 *)(lVar5 + 0x980) = 0;
    lVar5 = thunk_EXT_FUN_801100000389d0d8(5);
    param_1[0x378] = lVar5;
    lVar5 = thunk_EXT_FUN_80110000038c6e24(0,0x40);
    param_1[0x379] = lVar5;
    lVar5 = thunk_EXT_FUN_80110000038c6e24(0,0x40);
    param_1[0x37a] = lVar5;
    lVar5 = thunk_EXT_FUN_80110000038c6e24(0,0x40);
    param_1[0x37b] = lVar5;
    lVar5 = thunk_EXT_FUN_80110000038c6e24(0,0x40);
    param_1[0x37c] = lVar5;
    lVar5 = thunk_EXT_FUN_80110000038c6e24(0,0x40);
    param_1[0x37d] = lVar5;
    plVar4 = (long *)param_1[0x378];
    if ((plVar4 != (long *)0x0) && (param_1[0x379] != 0)) {
      if (param_1[0x37a] == 0) {
        return 0;
      }
      if (param_1[0x37b] == 0) {
        return 0;
      }
      if (param_1[0x37c] == 0) {
        return 0;
      }
      if (lVar5 == 0) {
        return 0;
      }
      (**(code **)(*plVar4 + 0xf0))(plVar4,DAT_fffffff00ae22508);
      (**(code **)(*(long *)param_1[0x378] + 0xf0))
                ((long *)param_1[0x378],DAT_fffffff00ae22510,param_1[0x37a]);
      (**(code **)(*(long *)param_1[0x378] + 0xf0))
                ((long *)param_1[0x378],DAT_fffffff00ae22518,param_1[0x37b]);
      (**(code **)(*(long *)param_1[0x378] + 0xf0))
                ((long *)param_1[0x378],DAT_fffffff00ae22520,param_1[0x37c]);
      (**(code **)(*(long *)param_1[0x378] + 0xf0))
                ((long *)param_1[0x378],DAT_fffffff00ae22528,param_1[0x37d]);
      return 1;
    }
  }
  return 0;
}

