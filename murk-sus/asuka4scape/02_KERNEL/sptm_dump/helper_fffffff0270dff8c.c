// FUN_fffffff0270dff8c @ fffffff0270dff8c size=784
// caller fffffff0270acaf0 FUN_fffffff0270aca80
// caller fffffff0270adbac FUN_fffffff0270ada40
// caller fffffff0270ae64c FUN_fffffff0270ae534
// caller fffffff0270ae664 FUN_fffffff0270ae534
// caller fffffff0270ae938 FUN_fffffff0270ae830
// caller fffffff0270ae950 FUN_fffffff0270ae830
// caller fffffff0270aeb88 FUN_fffffff0270aeb0c
// caller fffffff0270aeba8 FUN_fffffff0270aeb0c
// caller fffffff0270aecc0 FUN_fffffff0270aeb0c
// caller fffffff0270af09c FUN_fffffff0270aeed4
// caller fffffff0270af0a8 FUN_fffffff0270aeed4
// caller fffffff0270af0c0 FUN_fffffff0270aeed4
// caller fffffff0270c6f24 FUN_fffffff0270c6b24
// caller fffffff0270c842c FUN_fffffff0270c7c40
// caller fffffff0270c908c FUN_fffffff0270c8cdc
// caller fffffff0270c913c FUN_fffffff0270c8cdc
// caller fffffff0270c9d4c FUN_fffffff0270c9984
// caller fffffff0270c9da4 FUN_fffffff0270c9984

uint FUN_fffffff0270dff8c(ulong param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  short *psVar3;
  short *psVar4;
  uint uVar5;
  long lVar6;
  
  if (param_1 < DAT_fffffff0270921c8 || DAT_fffffff0270921d0 <= param_1) {
    psVar3 = (short *)FUN_fffffff0270de884(param_1);
    psVar4 = &DAT_fffffff0270fdec0;
    if (psVar3 != (short *)0x0) {
      psVar4 = psVar3;
    }
  }
  else {
    psVar4 = (short *)(DAT_fffffff0270914f0 +
                      (param_1 - DAT_fffffff0270921c8 >> 0xe & 0xffffffff) * 0x10);
  }
  if (((&DAT_fffffff027092201)[(ulong)*(byte *)(psVar4 + 1) * 0x90] != '\x06') && (*psVar4 == 0)) {
    FUN_fffffff0270dff30();
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc
              ("%s: Frame expected to have been acquired has not been acquired %p %s %u %u");
  }
  lVar6 = UnkSytemRegRead(3,6,0xf,8,0);
  if (lVar6 == 0) {
    lVar6 = tpidr_el2;
  }
  else {
    lVar6 = UnkSytemRegRead(3,6,0xf,0xb,1);
  }
  if (*(long *)(lVar6 + 0xb08) - 1U < 9) {
    if (((&DAT_fffffff0270913a0)[((ulong)((int)*(long *)(lVar6 + 0xb08) - 1) & 0xff) * 0x20] & 1) ==
        0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc("%s: IOMMU with id %d not supported");
    }
    if ((char)psVar4[1] == '\x18') {
      lVar6 = UnkSytemRegRead(3,6,0xf,8,0);
      if (lVar6 == 0) {
        lVar6 = tpidr_el2;
      }
      else {
        lVar6 = UnkSytemRegRead(3,6,0xf,0xb,1);
      }
      if (8 < *(long *)(lVar6 + 0xb08) - 1U) goto LAB_fffffff0270e01bc;
      if ((uint)*(byte *)(psVar4 + 3) == ((int)*(long *)(lVar6 + 0xb08) - 1U & 0xff)) {
        if ((&DAT_fffffff027092201)[(ulong)*(byte *)(psVar4 + 1) * 0x90] != '\x05') {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff0270f34fc
                    (
                    "%s: Type (%s) class of FTE (%p) does not match the type class of the type-specific-data trying to be retrieved: actual (%d) != requested (%d)."
                    );
        }
        if ((int)param_2 < 1) {
          if ((int)param_2 < 0) {
            uVar1 = psVar4[2];
            uVar2 = (uint)uVar1;
            psVar4[2] = uVar1 + (short)param_2;
            if (uVar2 < (-param_2 & 0xffff)) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff0270f34fc("%s: refcnt underflow: rc %p old_value %lld value %lld");
            }
          }
          else {
            uVar2 = (uint)(ushort)psVar4[2];
          }
        }
        else {
          uVar5 = param_2;
          if (0x3f < param_2) {
            uVar5 = 0x40;
          }
          uVar1 = psVar4[2];
          psVar4[2] = uVar1 + (short)uVar5;
          uVar2 = (uint)uVar1;
          if (0x3f6 < uVar1 >> 6) {
LAB_fffffff0270e014c:
                    /* WARNING: Subroutine does not return */
            FUN_fffffff0270f34fc("%s: refcnt overflow: rc %p old_value %lld value %lld");
          }
          for (param_2 = param_2 - uVar5; (param_2 & 0xffff) != 0; param_2 = param_2 - uVar5) {
            uVar5 = param_2 & 0xffff;
            if ((param_2 & 0xffc0) != 0) {
              uVar5 = 0x40;
            }
            uVar1 = psVar4[2];
            psVar4[2] = uVar1 + (short)uVar5;
            if (0x3f6 < uVar1 >> 6) goto LAB_fffffff0270e014c;
          }
        }
        return uVar2;
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: IOMMU %s (%d): attempted to increment refcnt of unexpected frame %p");
  }
LAB_fffffff0270e01bc:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff0270f34fc("%s: Unexpected Dispatch ID %llu");
}

