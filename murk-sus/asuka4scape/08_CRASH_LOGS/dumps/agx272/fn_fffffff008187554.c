// FUN_fffffff008187554 @ fffffff008187554 size=420

void FUN_fffffff008187554(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  ulong unaff_x30;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  uint local_a0;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined2 local_60;
  char local_58 [8];
  undefined2 local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff007ca61a0;
  if ((param_1 == 0) || (*(long *)(param_1 + 0x50) == 0)) {
    if (*(long *)PTR_DAT_fffffff007ca61a0 == local_48) {
      return;
    }
  }
  else {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x80));
    lVar5 = *(long *)(param_1 + 0x50);
    local_58[0] = s_Spill_for_fffffff00711e211[0];
    local_58[1] = s_Spill_for_fffffff00711e211[1];
    local_58[2] = s_Spill_for_fffffff00711e211[2];
    local_58[3] = s_Spill_for_fffffff00711e211[3];
    local_58[4] = s_Spill_for_fffffff00711e211[4];
    local_58[5] = s_Spill_for_fffffff00711e211[5];
    local_58[6] = s_Spill_for_fffffff00711e211[6];
    local_58[7] = s_Spill_for_fffffff00711e211[7];
    local_50 = 0x72;
    local_60 = 0;
    uStack_78 = 0;
    local_80 = 0;
    uStack_68 = 0;
    uStack_70 = 0;
    uStack_88 = 0;
    local_90 = 0;
    local_a0 = 0;
    uStack_b8 = 0;
    local_c0 = 0;
    uStack_a8 = 0;
    uStack_b0 = 0;
    if (0 < (int)param_3) {
      thunk_EXT_FUN_8011000003722d80(param_3,&local_c0,0x24);
      local_a0 = local_a0 & 0xffffff;
    }
    thunk_EXT_FUN_80110000037693ec(&local_90,0x32,"%s %s (%u)");
    lVar2 = *(long *)(lVar5 + 0x28);
    if (0 < lVar2) {
      lVar4 = 0;
      do {
        uVar3 = *(ulong *)(lVar5 + 0x20) + lVar4 * 0x18;
        if (((*(ulong *)(lVar5 + 0x20) ^ uVar3) & 0xffc0000000000000) != 0) {
          uVar3 = uVar3 & 0xffffffffffff | 0xc8a2000000000000;
        }
        plVar6 = *(long **)(uVar3 + 8);
        if (plVar6 != (long *)0x0) {
          do {
            thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*plVar6 + 0x18),&local_90);
            plVar6 = (long *)plVar6[4];
          } while (plVar6 != (long *)0x0);
          lVar2 = *(long *)(lVar5 + 0x28);
        }
        lVar4 = lVar4 + 1;
      } while (lVar4 < lVar2);
    }
    param_1 = *(long *)(param_1 + 0x80);
    if (*(long *)PTR_DAT_fffffff007ca61a0 == local_48) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081876c0);
        (*pcVar1)();
      }
      thunk_EXT_FUN_8011000003222de0();
      return;
    }
  }
  thunk_EXT_FUN_8011000003a48590(param_1);
  return;
}

