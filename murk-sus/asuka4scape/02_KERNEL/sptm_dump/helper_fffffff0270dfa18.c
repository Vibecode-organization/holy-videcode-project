// FUN_fffffff0270dfa18 @ fffffff0270dfa18 size=580
// caller fffffff0270e02c8 FUN_fffffff0270e029c
// caller fffffff0270e0a3c FUN_fffffff0270e0a18
// caller fffffff0270be754 FUN_fffffff0270be6dc
// caller fffffff0270acae4 FUN_fffffff0270aca80
// caller fffffff0270ad314 FUN_fffffff0270ad28c
// caller fffffff0270adba0 FUN_fffffff0270ada40
// caller fffffff0270ae298 FUN_fffffff0270ae210
// caller fffffff0270ae600 FUN_fffffff0270ae534
// caller fffffff0270ae640 FUN_fffffff0270ae534
// caller fffffff0270ae92c FUN_fffffff0270ae830
// caller fffffff0270aeb58 FUN_fffffff0270aeb0c
// caller fffffff0270aeb74 FUN_fffffff0270aeb0c
// caller fffffff0270bea78 FUN_fffffff0270bea54
// caller fffffff0270c6d04 FUN_fffffff0270c6b24
// caller fffffff0270c7e9c FUN_fffffff0270c7c40
// caller fffffff0270c8228 FUN_fffffff0270c7c40
// caller fffffff0270c8ff4 FUN_fffffff0270c8cdc
// caller fffffff0270c905c FUN_fffffff0270c8cdc
// caller fffffff0270c9af4 FUN_fffffff0270c9984
// caller fffffff0270c9d10 FUN_fffffff0270c9984

void FUN_fffffff0270dfa18(undefined8 param_1,uint param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 auVar4 [16];
  
  auVar4 = FUN_fffffff0270dd7ec();
  uVar2 = auVar4._8_8_;
  lVar1 = auVar4._0_8_;
  if ((param_2 != 0x46) && (*(byte *)(lVar1 + 2) != param_2)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x46,uVar2,"%s(%s:%d) - fte->type(%s), type(%s)\n");
  }
  lVar3 = UnkSytemRegRead(3,6,0xf,8,0);
  if (lVar3 == 0) {
    lVar3 = tpidr_el2;
  }
  else {
    lVar3 = UnkSytemRegRead(3,6,0xf,0xb,1);
  }
  if (8 < *(long *)(lVar3 + 0xb08) - 1U) {
LAB_fffffff0270dfbdc:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: Unexpected Dispatch ID %llu");
  }
  if ((ulong)*(byte *)(lVar1 + 2) == 0x18) {
    if (DAT_fffffff027092f81 != '\x05') {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc
                (
                "%s: Type (%s) class of FTE (%p) does not match the type class of the type-specific-data trying to be retrieved: actual (%d) != requested (%d)."
                );
    }
    if ((uint)*(byte *)(lVar1 + 6) != ((int)*(long *)(lVar3 + 0xb08) - 1U & 0xff)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f353c(0,uVar2,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx)\n");
    }
  }
  else {
    lVar3 = UnkSytemRegRead(3,6,0xf,8,0);
    if (lVar3 == 0) {
      lVar3 = tpidr_el2;
    }
    else {
      lVar3 = UnkSytemRegRead(3,6,0xf,0xb,1);
    }
    if (8 < *(long *)(lVar3 + 0xb08) - 1U) goto LAB_fffffff0270dfbdc;
    if ((*(ulong *)(&DAT_fffffff027092228 + (ulong)*(byte *)(lVar1 + 2) * 0x90) >>
         ((ulong)((int)*(long *)(lVar3 + 0xb08) - 1) & 0x3f) & 1) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f353c(0x46,uVar2,"%s(%s:%d) - iommu_id(%u), fte(%p), fte->type(%s)\n");
    }
  }
  return;
}

