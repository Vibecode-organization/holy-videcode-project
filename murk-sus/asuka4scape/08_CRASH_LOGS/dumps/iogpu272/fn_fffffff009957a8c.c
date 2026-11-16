// FUN_fffffff009957a8c @ fffffff009957a8c size=1220

undefined8
FUN_fffffff009957a8c(long param_1,long *param_2,ulong param_3,ulong param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long *plVar9;
  long *plVar10;
  undefined8 uVar11;
  byte *pbVar12;
  ulong uVar13;
  uint uVar14;
  ulong uVar15;
  long local_90;
  uint local_6c;
  undefined8 local_68;
  
  param_4 = param_4 & 0xffffffff;
  if (DAT_fffffff00af227e8 != 0) {
    if (param_2 == (long *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = (**(code **)(*(long *)param_2[5] + 0xe0))();
    }
    local_68 = 0;
    thunk_EXT_FUN_80110000032db760(uVar6,&local_68);
    uVar6 = local_68;
    uVar7 = (**(code **)(**(long **)(param_1 + 0x28) + 0xe0))();
    local_68 = 0;
    thunk_EXT_FUN_80110000032db760(uVar7,&local_68);
    uVar7 = local_68;
    uVar8 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x50));
    thunk_EXT_FUN_80110000036da494(0x851801a9,uVar6,uVar7,param_4,uVar8,0);
  }
  local_6c = 0;
  plVar9 = (long *)thunk_EXT_FUN_8011000003890f30
                             (*(undefined8 *)(param_1 + 0x28),DAT_fffffff007fe8e10);
  if (plVar9 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: memory is not a virtual memory\n");
    uVar6 = 0xe00002c7;
    goto LAB_fffffff009957e50;
  }
  if (param_2 == (long *)0x0) {
    local_90 = 0;
  }
  else {
    plVar10 = (long *)thunk_EXT_FUN_8011000003890f30(param_2[5],DAT_fffffff007fefaf0);
    if (plVar10 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: source resource memory is not a sys memory\n");
      uVar6 = 0xe0000001;
      goto LAB_fffffff009957e50;
    }
    local_90 = (**(code **)(*plVar10 + 0xf8))(plVar10,(int)plVar9[0x12],param_5,&local_6c);
    if (local_90 == 0) {
      uVar6 = 0xe00002bd;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Failed to create memory descriptors\n");
      goto LAB_fffffff009957e50;
    }
    if (*(int *)((long)param_2 + 0x14) != *(int *)(param_1 + 0x14)) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Protection violation\n");
      uVar6 = 0xe00002e2;
      goto LAB_fffffff009957e50;
    }
  }
  uVar6 = 0;
  if (param_4 != 0) {
    uVar15 = 0;
    do {
      pbVar12 = (byte *)(param_3 + uVar15 * 0x10);
      if (((param_3 ^ (ulong)pbVar12) & 0xffc0000000000000) != 0) {
        pbVar12 = (byte *)((ulong)pbVar12 & 0xffffffffffff | 0xc8a2000000000000);
      }
      uVar14 = *(uint *)(pbVar12 + 8);
      uVar2 = *(uint *)(pbVar12 + 0xc);
      if (CARRY4(uVar2,uVar14)) {
LAB_fffffff009957dac:
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid arguments\n");
        uVar6 = 0xe00002c2;
        break;
      }
      uVar3 = *(uint *)(pbVar12 + 4);
      uVar13 = (ulong)uVar3;
      if (CARRY4(uVar3,uVar14)) goto LAB_fffffff009957dac;
      bVar4 = *pbVar12;
      if ((param_2 != (long *)0x0) &&
         ((local_6c <= uVar3 || local_6c < uVar3 + uVar14) && (bVar4 & 1) != 0))
      goto LAB_fffffff009957dac;
      FUN_fffffff009942d70(plVar9);
      if (uVar2 < uVar2 + uVar14) {
        do {
          if ((bVar4 & 1) == 0) {
            uVar6 = 0;
          }
          else {
            lVar5 = uVar13 * 8;
            uVar13 = (ulong)((int)uVar13 + 1);
            puVar1 = (undefined8 *)(local_90 + (int)lVar5);
            if (lVar5 != (int)lVar5) {
              puVar1 = (undefined8 *)(local_90 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
            }
            uVar6 = *puVar1;
          }
          uVar6 = (**(code **)(*plVar9 + 0x120))(plVar9,uVar2,uVar6);
          if ((int)uVar6 != 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                       "%s: Failed to update memory at index %u\n");
            goto LAB_fffffff009957d90;
          }
          uVar2 = uVar2 + 1;
          uVar14 = uVar14 - 1;
        } while (uVar14 != 0);
        uVar6 = 0;
      }
LAB_fffffff009957d90:
      FUN_fffffff009942d7c(plVar9);
      uVar15 = uVar15 + 1;
    } while (uVar15 != param_4);
  }
LAB_fffffff009957e50:
  if (DAT_fffffff00af227e8 != 0) {
    if (param_2 == (long *)0x0) {
      uVar7 = 0;
    }
    else {
      uVar7 = (**(code **)(*(long *)param_2[5] + 0xe0))();
    }
    local_68 = 0;
    thunk_EXT_FUN_80110000032db760(uVar7,&local_68);
    uVar7 = local_68;
    uVar8 = (**(code **)(**(long **)(param_1 + 0x28) + 0xe0))();
    local_68 = 0;
    thunk_EXT_FUN_80110000032db760(uVar8,&local_68);
    uVar8 = local_68;
    uVar11 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x50));
    thunk_EXT_FUN_80110000036da494(0x851801aa,uVar7,uVar8,(int)uVar6 == 0,uVar11,0);
  }
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  return uVar6;
}

