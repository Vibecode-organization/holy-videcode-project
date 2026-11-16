// FUN_fffffff0270e08e4 @ fffffff0270e08e4 size=580
// CALLERS:
//   fffffff0270e1194 FUN_fffffff0270e1168@fffffff0270e1168
//   fffffff0270e1900 FUN_fffffff0270e18dc@fffffff0270e18dc
//   fffffff0270bf318 FUN_fffffff0270bf2a0@fffffff0270bf2a0
//   fffffff0270ace30 FUN_fffffff0270acdcc@fffffff0270acdcc
//   fffffff0270ad660 FUN_fffffff0270ad5d8@fffffff0270ad5d8
//   fffffff0270ae090 FUN_fffffff0270adf30@fffffff0270adf30
//   fffffff0270ae788 FUN_fffffff0270ae700@fffffff0270ae700
//   fffffff0270aeaf0 FUN_fffffff0270aea24@fffffff0270aea24
//   fffffff0270aec88 FUN_fffffff0270aea24@fffffff0270aea24
//   fffffff0270aefc0 FUN_fffffff0270aeec4@fffffff0270aeec4
//   fffffff0270af1ec FUN_fffffff0270af1a0@fffffff0270af1a0
//   fffffff0270af208 FUN_fffffff0270af1a0@fffffff0270af1a0
//   fffffff0270bf63c FUN_fffffff0270bf618@fffffff0270bf618
//   fffffff0270c7c04 FUN_fffffff0270c7a24@fffffff0270c7a24
//   fffffff0270c8cf8 FUN_fffffff0270c8a9c@fffffff0270c8a9c
//   fffffff0270c9084 FUN_fffffff0270c8a9c@fffffff0270c8a9c
//   fffffff0270c9e50 FUN_fffffff0270c9b38@fffffff0270c9b38
//   fffffff0270c9eb8 FUN_fffffff0270c9b38@fffffff0270c9b38
//   fffffff0270ca950 FUN_fffffff0270ca7e0@fffffff0270ca7e0
//   fffffff0270cab6c FUN_fffffff0270ca7e0@fffffff0270ca7e0
// CALLS:
//   fffffff0270de6b8 FUN_fffffff0270de6b8
//   fffffff0270f46f4 FUN_fffffff0270f46f4
//   fffffff0270f46b4 FUN_fffffff0270f46b4

void FUN_fffffff0270e08e4(undefined8 param_1,uint param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 auVar4 [16];
  
  auVar4 = FUN_fffffff0270de6b8();
  uVar2 = auVar4._8_8_;
  lVar1 = auVar4._0_8_;
  if ((param_2 != 0x46) && (*(byte *)(lVar1 + 2) != param_2)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f46f4(0x46,uVar2,"%s(%s:%d) - fte->type(%s), type(%s)\n");
  }
  lVar3 = UnkSytemRegRead(3,6,0xf,8,0);
  if (lVar3 == 0) {
    lVar3 = tpidr_el2;
  }
  else {
    lVar3 = UnkSytemRegRead(3,6,0xf,0xb,1);
  }
  if (8 < *(long *)(lVar3 + 0xb08) - 1U) {
LAB_fffffff0270e0aa8:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f46b4("%s: Unexpected Dispatch ID %llu");
  }
  if ((ulong)*(byte *)(lVar1 + 2) == 0x18) {
    if (DAT_fffffff027092f81 != '\x05') {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f46b4
                (
                "%s: Type (%s) class of FTE (%p) does not match the type class of the type-specific-data trying to be retrieved: actual (%d) != requested (%d)."
                );
    }
    if ((uint)*(byte *)(lVar1 + 6) != ((int)*(long *)(lVar3 + 0xb08) - 1U & 0xff)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f46f4(0,uVar2,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx)\n");
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
    if (8 < *(long *)(lVar3 + 0xb08) - 1U) goto LAB_fffffff0270e0aa8;
    if ((*(ulong *)(&DAT_fffffff027092228 + (ulong)*(byte *)(lVar1 + 2) * 0x90) >>
         ((ulong)((int)*(long *)(lVar3 + 0xb08) - 1) & 0x3f) & 1) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f46f4(0x46,uVar2,"%s(%s:%d) - iommu_id(%u), fte(%p), fte->type(%s)\n");
    }
  }
  return;
}

