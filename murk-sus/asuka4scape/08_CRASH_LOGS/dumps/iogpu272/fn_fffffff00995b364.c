// FUN_fffffff00995b364 @ fffffff00995b364 size=424

undefined8 FUN_fffffff00995b364(long param_1,uint *param_2)

{
  long *plVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  long *plVar5;
  uint *puVar6;
  undefined8 uVar7;
  long lVar8;
  ulong uVar9;
  
  uVar7 = 0xe00002bc;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  if ((*(long *)(param_1 + 0x78) != 0) && (*(long *)(param_1 + 0x28) != 0)) {
    if (*param_2 != 0) {
      uVar9 = 0;
      do {
        puVar6 = param_2 + 2 + uVar9 * 6;
        if ((((ulong)(param_2 + 2) ^ (ulong)puVar6) & 0xffc0000000000000) != 0) {
          puVar6 = (uint *)((ulong)puVar6 & 0xffffffffffff | 0xc8a2000000000000);
        }
        if (*puVar6 == 0) {
          FUN_fffffff00995b50c(param_1);
        }
        else {
          uVar2 = puVar6[1];
          uVar7 = *(undefined8 *)(puVar6 + 2);
          uVar3 = puVar6[4];
          plVar5 = (long *)FUN_fffffff009945040(*(undefined8 *)(param_1 + 0x38));
          if (plVar5 != (long *)0x0) {
            iVar4 = FUN_fffffff009959248(plVar5,uVar2,uVar7,(char)uVar3 != '\0');
            if (iVar4 == 0) {
              (**(code **)(*plVar5 + 0x28))(plVar5);
            }
            else {
              lVar8 = plVar5[7];
              if (DAT_fffffff00af227e8 != 0) {
                thunk_EXT_FUN_80110000036da494
                          (0x85180171,*(undefined8 *)(param_1 + 0x30),lVar8,0,0,0);
              }
              thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x90));
              plVar5[0xc] = 0;
              plVar1 = *(long **)(param_1 + 0x88);
              uVar7 = *(undefined8 *)(param_1 + 0x90);
              plVar5[0xd] = (long)plVar1;
              *plVar1 = (long)plVar5;
              *(long **)(param_1 + 0x88) = plVar5 + 0xc;
              thunk_EXT_FUN_8011000003222de0(uVar7);
              if (DAT_fffffff00af227e8 != 0) {
                thunk_EXT_FUN_80110000036da494
                          (0x85180172,*(undefined8 *)(param_1 + 0x30),lVar8,0,0,0);
              }
              FUN_fffffff00995a4ac(param_1);
            }
          }
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < *param_2);
    }
    uVar7 = 0;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
  return uVar7;
}

