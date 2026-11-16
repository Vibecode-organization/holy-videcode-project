// FUN_fffffff00a2d82a8 @ fffffff00a2d82a8 size=944

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_fffffff00a2d82a8(ulong param_1,undefined8 param_2,ulong *param_3)

{
  uint uVar1;
  long *plVar2;
  ulong *puVar3;
  byte bVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  undefined4 in_wzr;
  
  lVar8 = *(long *)((ulong)*(uint *)(param_1 + 0x1c) * 0x40 + -0x23ffffffc8);
  uVar9 = *(long *)(param_1 + 0x20) - *(long *)(lVar8 + 0x58) & 0xffffffffffffc000;
  if (param_3 != (ulong *)0x0) {
    *param_3 = uVar9;
  }
  if (uVar9 < *(ulong *)(lVar8 + 0x18)) {
    lVar6 = FUN_fffffff00a32bd34(lVar8,uVar9);
    if (lVar6 != 0) {
      return *(byte *)(lVar6 + 0x2c) >> 2 & 1;
    }
    if (((((*(uint *)(lVar8 + 0x74) >> 0xc & 1) == 0) || ((*(uint *)(lVar8 + 0x74) >> 0xf & 1) == 0)
         ) || (*(long *)(lVar8 + 0x50) == 0)) ||
       (iVar5 = FUN_fffffff00a2c5c14(*(long *)(lVar8 + 0x50),*(long *)(lVar8 + 0x60) + uVar9),
       iVar5 != 1)) {
      uVar7 = FUN_fffffff00a32cd9c(param_2);
      if (uVar7 == 0) {
        return 2;
      }
      FUN_fffffff00a3297a4(uVar7,lVar8,uVar9,0,0,0);
      FUN_fffffff00a32f138(param_1,uVar7);
      bVar4 = *(byte *)(param_1 + 0x2d);
      if ((bVar4 >> 4 & 1) != 0) {
        if ((param_1 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= param_1)) {
          iVar5 = *(int *)(param_1 + 0x3c);
        }
        else {
          iVar5 = DAT_fffffff007bf0000 + (int)(param_1 - DAT_fffffff007bf0010 >> 6);
        }
        FUN_fffffff00a37c100(iVar5);
        bVar4 = *(byte *)(param_1 + 0x2d);
      }
      if ((bVar4 >> 3 & 1) != 0) {
        lVar8 = tpidr_el1;
        lVar6 = FUN_fffffff00a29bafc(lVar8);
        plVar2 = (long *)(*(long *)(lVar6 + 0x388) + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
        *plVar2 = *plVar2 + 1;
        if ((param_1 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= param_1)) {
          iVar5 = *(int *)(param_1 + 0x3c);
        }
        else {
          iVar5 = DAT_fffffff007bf0000 + (int)(param_1 - DAT_fffffff007bf0010 >> 6);
        }
        FUN_fffffff00a37c1d0(iVar5);
        uVar9 = (ulong)*(byte *)(param_1 + 0x2d);
        if ((*(byte *)(param_1 + 0x2d) >> 3 & 1) != 0) {
          lVar6 = 0;
          if (*(uint *)(param_1 + 0x1c) != 0) {
            lVar6 = (ulong)*(uint *)(param_1 + 0x1c) * 0x40 + -0x2400000000;
          }
          *(int *)(lVar6 + 0xa0) = *(int *)(lVar6 + 0xa0) + 1;
          *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) & 0xf7;
          puVar3 = (ulong *)(_DAT_fffffff00ad188c8 + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
          uVar9 = *puVar3;
          *puVar3 = uVar9 + 1;
        }
        FUN_fffffff00a37c37c(uVar9,iVar5);
      }
      lVar8 = tpidr_el1;
      *(int *)(lVar8 + 0x1c0) = *(int *)(lVar8 + 0x1c0) + 1;
      uVar9 = (ulong)*(uint *)(lVar8 + 0x4e8) | 0x30000000;
      if (DAT_fffffff00ad6d188 != 0) {
        FUN_fffffff00a2262d4(&DAT_fffffff00ad6d180,lVar8,1);
        uVar9 = DAT_fffffff00ad6d188;
      }
      DAT_fffffff00ad6d188 = uVar9;
      FUN_fffffff00a32c144(uVar7);
      if ((int)DAT_fffffff00ad6d188 == *(int *)(lVar8 + 0x4e8)) {
        DAT_fffffff00ad6d188 = CONCAT44(DAT_fffffff00ad6d188._4_4_,in_wzr);
      }
      else {
        FUN_fffffff00a226e08(&DAT_fffffff00ad6d180,lVar8);
      }
      if ((uVar7 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= uVar7)) {
        uVar1 = *(uint *)(uVar7 + 0x3c);
      }
      else {
        uVar1 = DAT_fffffff007bf0000 + (int)(uVar7 - DAT_fffffff007bf0010 >> 6);
      }
      uVar9 = (ulong)uVar1;
      if ((DAT_fffffff007bf0df0 <= uVar9 << 0xe) && (uVar9 << 0xe < DAT_fffffff007bf0df8)) {
        if (uVar1 < DAT_fffffff007bca750 + DAT_fffffff007bf0000) {
          if (uVar1 < DAT_fffffff007bf0000) {
            uVar9 = FUN_fffffff00a3285d4();
          }
          else {
            uVar9 = DAT_fffffff007bf0010 + (ulong)(uVar1 - DAT_fffffff007bf0000) * 0x40;
          }
        }
        else {
          uVar9 = 0;
        }
        *(ushort *)(uVar9 + 0x38) = *(ushort *)(uVar9 + 0x38) | 0x80;
      }
      *(byte *)(uVar7 + 0x2d) = *(byte *)(uVar7 + 0x2d) | 1;
      FUN_fffffff00a30a920(uVar9,uVar7);
      if ((*(byte *)(param_1 + 0x2c) >> 6 & 1) != 0) {
        *(byte *)(param_1 + 0x2c) = *(byte *)(param_1 + 0x2c) & 0xbf;
        uVar9 = (param_1 ^ param_1 >> 0x1f) * 0x7fb5d329728ea185;
        lVar8 = (uVar9 ^ uVar9 >> 0x1b) * -0x7e25210b43d22bb3;
        uVar9 = DAT_fffffff007bc7040 +
                (ulong)(DAT_fffffff007bc7048 - 1U & ((uint)((ulong)lVar8 >> 0x21) ^ (uint)lVar8)) *
                0x18;
        if (((DAT_fffffff007bc7040 ^ uVar9) & 0xffc0000000000000) != 0) {
          uVar9 = uVar9 & 0xffffffffffff | 0xc8a2000000000000;
        }
        FUN_fffffff00a28c5d4(uVar9,param_1,3,0,0xffffffff);
      }
    }
  }
  return 0;
}

