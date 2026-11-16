// FUN_fffffff0094c7554 @ fffffff0094c7554 size=792
// CALLERS:
//   fffffff00afb80bc ?
//   fffffff0094c8c4c FUN_fffffff0094c8c04@fffffff0094c8c04
// CALLS:
//   fffffff0094c9a04 thunk_EXT_FUN_8011000003138628
//   fffffff0094c9bb4 thunk_EXT_FUN_80110000033502b4
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590

undefined8 FUN_fffffff0094c7554(ulong *param_1,ulong *param_2)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  ulong local_80;
  ulong local_78;
  ulong local_70;
  ulong local_68;
  ulong local_60;
  ulong local_58;
  ulong local_50;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff007f5bb60;
  uVar4 = *param_1;
  local_40 = param_1[1];
  if (CARRY8(uVar4,local_40)) {
LAB_fffffff0094c7864:
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5513,0xfffffff0094c7868);
    (*pcVar2)();
  }
  uVar1 = uVar4 + local_40;
  if (uVar1 < uVar4) {
LAB_fffffff0094c77c8:
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c77cc);
    (*pcVar2)();
  }
  *param_2 = 0;
  param_2[1] = 0;
  local_50 = uVar4;
  local_48 = uVar1;
  if (uVar4 < uVar1) {
    do {
      iVar3 = thunk_EXT_FUN_8011000003138628(&local_50,0x2000000000000011,&local_40);
      if ((iVar3 == 0) || (local_40 == 0)) {
        uVar5 = 0xb0002;
        goto LAB_fffffff0094c77ec;
      }
      if (CARRY8(local_50,local_40)) goto LAB_fffffff0094c7864;
      uVar1 = local_50 + local_40;
      uVar4 = local_50;
      if (uVar1 < local_50 || local_48 < uVar1) goto LAB_fffffff0094c77c8;
      while (local_58 = uVar1, local_60 = uVar4, uVar4 < local_58) {
        iVar3 = thunk_EXT_FUN_8011000003138628(&local_60,0x2000000000000010,&local_40);
        if (iVar3 == 0) {
          uVar5 = 0xb0003;
          goto LAB_fffffff0094c77ec;
        }
        if (CARRY8(local_60,local_40)) goto LAB_fffffff0094c7864;
        uVar4 = local_60 + local_40;
        if (uVar4 < local_60 || local_58 < uVar4) goto LAB_fffffff0094c77c8;
        local_70 = local_60;
        local_68 = uVar4;
        iVar3 = thunk_EXT_FUN_8011000003138628(&local_70,6,&local_40);
        uVar4 = local_70;
        if (iVar3 == 0) {
          uVar5 = 0xb0004;
          goto LAB_fffffff0094c77ec;
        }
        if ((local_68 < local_70) || (local_68 - local_70 < local_40)) goto LAB_fffffff0094c77c8;
        if (CARRY8(local_70,local_40)) goto LAB_fffffff0094c7864;
        uVar1 = local_70 + local_40;
        if ((local_68 < uVar1) || (uVar1 < local_70)) goto LAB_fffffff0094c77c8;
        local_70 = uVar1;
        if ((local_40 == 3) &&
           (iVar3 = thunk_EXT_FUN_80110000033502b4(uVar4,&DAT_fffffff007770830,3), iVar3 == 0)) {
          if (local_68 < local_70) goto LAB_fffffff0094c77c8;
          uVar5 = 0xb0005;
          local_80 = local_70;
          local_78 = local_68;
          uVar4 = thunk_EXT_FUN_8011000003138628(&local_80,0xc,&local_40);
          if ((uVar4 & 1) == 0) {
            if (local_68 < local_70) goto LAB_fffffff0094c77c8;
            local_80 = local_70;
            local_78 = local_68;
            uVar4 = thunk_EXT_FUN_8011000003138628(&local_80,0x13,&local_40);
            if ((uVar4 & 1) == 0) {
              if (local_68 < local_70) goto LAB_fffffff0094c77c8;
              local_80 = local_70;
              local_78 = local_68;
              iVar3 = thunk_EXT_FUN_8011000003138628(&local_80,0x14,&local_40);
              if (iVar3 == 0) goto LAB_fffffff0094c77ec;
            }
          }
          if (local_40 == 0) goto LAB_fffffff0094c77ec;
          if (CARRY8(local_80,local_40)) goto LAB_fffffff0094c7864;
          if (local_68 != local_80 + local_40) {
            uVar5 = 0xb0006;
            goto LAB_fffffff0094c77ec;
          }
          if ((local_78 < local_80) || (local_78 - local_80 < local_40)) goto LAB_fffffff0094c77c8;
          *param_2 = local_80;
          param_2[1] = local_40;
        }
        if ((local_58 < local_68) || (uVar4 = local_68, uVar1 = local_58, local_68 < local_60))
        goto LAB_fffffff0094c77c8;
      }
      if (uVar4 != local_58) {
        uVar5 = 0xb0007;
        goto LAB_fffffff0094c77ec;
      }
      if ((local_48 < uVar4) || (uVar4 < local_50)) goto LAB_fffffff0094c77c8;
      local_50 = uVar4;
    } while (uVar4 < local_48);
  }
  local_50 = uVar4;
  if (uVar4 == local_48) {
    if ((param_2[1] == 0) || (*param_2 == 0)) {
      *param_2 = 0;
      param_2[1] = 0;
      uVar5 = 0xb0009;
    }
    else {
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 0xb0008;
  }
LAB_fffffff0094c77ec:
  if (*(long *)PTR_DAT_fffffff007f5bb60 == local_38) {
    return uVar5;
  }
  uVar5 = thunk_EXT_FUN_8011000003a48590();
  return uVar5;
}

