// FUN_fffffff00998088c @ fffffff00998088c size=708

undefined8 FUN_fffffff00998088c(undefined8 param_1,long param_2,ulong param_3,int param_4)

{
  ulong *puVar1;
  long lVar2;
  ulong *puVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  undefined *puVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  uint uVar11;
  uint uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong local_a0 [4];
  undefined4 local_80;
  undefined4 local_74;
  long local_70;
  ulong local_68;
  
  lVar2 = (param_3 & 0xffffffff) << 4;
  lVar5 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff1d68,lVar2);
  if (lVar5 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Failed to allocate temporary ranges\n");
    uVar6 = 0;
  }
  else {
    uVar12 = 2;
    if (param_4 == 0) {
      uVar12 = 3;
    }
    if ((int)param_3 != 0) {
      uVar13 = 0;
      do {
        lVar8 = uVar13 * 0x10;
        puVar1 = (ulong *)(lVar5 + (int)lVar8);
        if (lVar8 - (int)lVar8 != 0) {
          puVar1 = (ulong *)(lVar5 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
        }
        puVar3 = (ulong *)(param_2 + uVar13 * 0x10);
        uVar14 = *puVar3;
        puVar1[1] = puVar3[1];
        *puVar1 = uVar14;
        uVar9 = *puVar1 & 0xf0ffffffffffffff;
        local_70 = 0;
        uVar14 = uVar9 + puVar1[1];
        local_68 = uVar9;
        if (CARRY8(uVar9,puVar1[1])) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Overflow in range\n");
          puVar7 = &DAT_fffffff007ff1db8;
LAB_fffffff009980ae4:
          thunk_EXT_FUN_80110000038fe768(puVar7,lVar5,lVar2);
          return 0;
        }
        uVar10 = 0;
        uVar11 = uVar12;
        do {
          local_74 = 9;
          local_80 = 0;
          local_a0[1] = 0;
          local_a0[0] = 0;
          local_a0[3] = 0;
          local_a0[2] = 0;
          if (local_70 != 0) {
            uVar10 = uVar9 + local_70;
            local_70 = 0;
            local_68 = uVar10;
          }
          uVar6 = thunk_EXT_FUN_80110000032977b0(param_1);
          iVar4 = thunk_EXT_FUN_8011000003340acc(uVar6,&local_68,&local_70,9,local_a0,&local_74,0);
          if (iVar4 != 0) {
LAB_fffffff009980ad4:
            puVar7 = &DAT_fffffff007ff1e08;
            goto LAB_fffffff009980ae4;
          }
          if (uVar10 == 0) {
            uVar9 = local_68;
            if (local_68 <= *puVar1) goto LAB_fffffff0099809a8;
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Hole in address ranges\n");
            goto LAB_fffffff009980ad4;
          }
          uVar9 = uVar10;
          if (uVar10 != local_68) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Hole in address ranges\n");
            goto LAB_fffffff009980ad4;
          }
LAB_fffffff0099809a8:
          if (((byte)local_a0[0] >> 2 & 1) != 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                       "%s: Disallowing executable page\n");
            goto LAB_fffffff009980ad4;
          }
          uVar12 = 2;
          if ((local_a0[0] & 0x200000000) != 0) {
            uVar12 = uVar11;
          }
          uVar11 = uVar12;
        } while (local_70 + uVar9 < uVar14);
        uVar13 = uVar13 + 1;
      } while (uVar13 < (param_3 & 0xffffffff));
    }
    uVar6 = thunk_EXT_FUN_8011000003977010(lVar5,param_3,uVar12 | 0x110000,param_1);
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1e58,lVar5,lVar2);
  }
  return uVar6;
}

