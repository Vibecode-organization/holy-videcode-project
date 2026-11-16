// FUN_fffffff0270dfc5c @ fffffff0270dfc5c size=724
// caller fffffff0270ac7c0 FUN_fffffff0270ac614
// caller fffffff0270acaf8 FUN_fffffff0270aca80
// caller fffffff0270ad3d8 FUN_fffffff0270ad28c
// caller fffffff0270ad418 FUN_fffffff0270ad28c
// caller fffffff0270ad7c0 FUN_fffffff0270ad5a4
// caller fffffff0270ad964 FUN_fffffff0270ad8a4
// caller fffffff0270adbb4 FUN_fffffff0270ada40
// caller fffffff0270addc4 FUN_fffffff0270ada40
// caller fffffff0270ae360 FUN_fffffff0270ae210
// caller fffffff0270ae3b4 FUN_fffffff0270ae210
// caller fffffff0270ae658 FUN_fffffff0270ae534
// caller fffffff0270ae674 FUN_fffffff0270ae534
// caller fffffff0270ae6a8 FUN_fffffff0270ae534
// caller fffffff0270ae940 FUN_fffffff0270ae830
// caller fffffff0270ae96c FUN_fffffff0270ae830
// caller fffffff0270ae99c FUN_fffffff0270ae830
// caller fffffff0270aecc8 FUN_fffffff0270aeb0c
// caller fffffff0270aecdc FUN_fffffff0270aeb0c
// caller fffffff0270af0f0 FUN_fffffff0270aeed4
// caller fffffff0270af0f8 FUN_fffffff0270aeed4
// caller fffffff0270c6f50 FUN_fffffff0270c6b24
// caller fffffff0270c7f04 FUN_fffffff0270c7c40
// caller fffffff0270c8458 FUN_fffffff0270c7c40
// caller fffffff0270c9168 FUN_fffffff0270c8cdc
// caller fffffff0270c9194 FUN_fffffff0270c8cdc
// caller fffffff0270c9eac FUN_fffffff0270c9984
// caller fffffff0270c9eb4 FUN_fffffff0270c9984
// caller fffffff0270e040c FUN_fffffff0270e029c
// caller fffffff0270e0b84 FUN_fffffff0270e0a18
// caller fffffff0270abe7c FUN_fffffff0270abc74
// caller fffffff0270ac410 FUN_fffffff0270ac298
// caller fffffff0270aed24 FUN_fffffff0270aeb0c
// caller fffffff0270af124 FUN_fffffff0270aeed4

void FUN_fffffff0270dfc5c(ulong param_1)

{
  ushort uVar1;
  short *psVar2;
  ushort *puVar3;
  ushort *puVar4;
  long lVar5;
  short *psVar6;
  long lVar7;
  
  if (param_1 < DAT_fffffff0270921c8 || DAT_fffffff0270921d0 <= param_1) {
    psVar2 = (short *)FUN_fffffff0270de884();
    psVar6 = &DAT_fffffff0270fdec0;
    if (psVar2 != (short *)0x0) {
      psVar6 = psVar2;
    }
  }
  else {
    psVar6 = (short *)(DAT_fffffff0270914f0 +
                      (param_1 - DAT_fffffff0270921c8 >> 0xe & 0xffffffff) * 0x10);
  }
  if (((&DAT_fffffff027092201)[(ulong)*(byte *)(psVar6 + 1) * 0x90] != '\x06') && (*psVar6 == 0)) {
    FUN_fffffff0270dff30();
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc
              ("%s: Frame expected to have been acquired has not been acquired %p %s %u %u");
  }
  lVar7 = UnkSytemRegRead(3,6,0xf,8,0);
  if (lVar7 == 0) {
    lVar7 = tpidr_el2;
  }
  else {
    lVar7 = UnkSytemRegRead(3,6,0xf,0xb,1);
  }
  lVar7 = *(long *)(lVar7 + 0xb08);
  if (lVar7 - 1U < 9) {
    if ((param_1 < DAT_fffffff0270921c8) || (DAT_fffffff0270921d0 <= param_1)) {
      puVar3 = (ushort *)FUN_fffffff0270de884();
      puVar4 = &DAT_fffffff0270fdec0;
      if (puVar3 != (ushort *)0x0) {
        puVar4 = puVar3;
      }
    }
    else {
      puVar4 = (ushort *)
               (DAT_fffffff0270914f0 + (param_1 - DAT_fffffff0270921c8 >> 0xe & 0xffffffff) * 0x10);
    }
    lVar5 = UnkSytemRegRead(3,6,0xf,8,0);
    if ((ulong)(byte)puVar4[1] == 0x18) {
      if (lVar5 == 0) {
        lVar5 = tpidr_el2;
      }
      else {
        lVar5 = UnkSytemRegRead(3,6,0xf,0xb,1);
      }
      if (*(long *)(lVar5 + 0xb08) - 1U < 9) {
        if (((&DAT_fffffff0270913a0)[((ulong)((int)*(long *)(lVar5 + 0xb08) - 1) & 0xff) * 0x20] & 1
            ) == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff0270f34fc("%s: IOMMU with id %d not supported");
        }
        if ((uint)(byte)puVar4[3] != ((int)lVar7 - 1U & 0xff)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff0270f34fc("%s: IOMMU %s (%d): attempted to release unexpected frame %p");
        }
LAB_fffffff0270dfdf4:
        lVar7 = (ulong)(byte)puVar4[1] * 0x90;
        if ((&DAT_fffffff027092201)[lVar7] != '\x06') {
          if (((&DAT_fffffff027092233)[lVar7] & 1) == 0) {
            *puVar4 = 0;
          }
          else {
            uVar1 = *puVar4;
            *puVar4 = uVar1 - 2;
            LORelease();
            if ((uVar1 == 0) || ((uVar1 & 1) != 0)) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff0270f34fc("%s: rw_guard_release_shared: %p");
            }
          }
        }
        return;
      }
    }
    else {
      if (lVar5 == 0) {
        lVar7 = tpidr_el2;
      }
      else {
        lVar7 = UnkSytemRegRead(3,6,0xf,0xb,1);
      }
      if (*(long *)(lVar7 + 0xb08) - 1U < 9) {
        if ((*(ulong *)(&DAT_fffffff027092228 + (ulong)(byte)puVar4[1] * 0x90) >>
             ((ulong)((int)*(long *)(lVar7 + 0xb08) - 1) & 0x3f) & 1) == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff0270f34fc
                    (
                    "%s: Tried releasing a frame that should not have been acquired to begin with %d"
                    );
        }
        goto LAB_fffffff0270dfdf4;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff0270f34fc("%s: Unexpected Dispatch ID %llu");
}

