// FUN_fffffff0270e029c @ fffffff0270e029c size=1032
// caller fffffff0270bb85c FUN_fffffff0270bb768
// caller fffffff0270bbbc4 FUN_fffffff0270bbb1c
// caller fffffff0270bbe44 FUN_fffffff0270bbd9c
// caller fffffff0270bc2c0 FUN_fffffff0270bc1dc
// caller fffffff0270bc340 FUN_fffffff0270bc1dc
// caller fffffff0270bcf48 FUN_fffffff0270bcd34
// caller fffffff0270bcfc0 FUN_fffffff0270bcd34
// caller fffffff0270bd048 FUN_fffffff0270bcd34
// caller fffffff0270adca4 FUN_fffffff0270ada40
// caller fffffff0270bfd60 FUN_fffffff0270bfc5c
// caller fffffff0270c7f10 FUN_fffffff0270c7c40
// caller fffffff0270cfe78 FUN_fffffff0270cfdc0

void FUN_fffffff0270e029c(ulong param_1,undefined8 param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  long lVar7;
  undefined8 extraout_x1;
  undefined8 uVar8;
  undefined8 extraout_x1_00;
  undefined8 extraout_x1_01;
  undefined8 extraout_x1_02;
  undefined8 extraout_x1_03;
  ulong uVar9;
  undefined1 auVar10 [16];
  
  FUN_fffffff0270dfa18(param_1,0x46);
  if (param_1 < DAT_fffffff0270921c8 || DAT_fffffff0270921d0 <= param_1) {
    auVar10 = FUN_fffffff0270de884(param_1);
    uVar8 = auVar10._8_8_;
    puVar6 = &DAT_fffffff0270fdec0;
    if (auVar10._0_8_ != (undefined2 *)0x0) {
      puVar6 = auVar10._0_8_;
    }
  }
  else {
    puVar6 = (undefined2 *)
             (DAT_fffffff0270914f0 + (param_1 - DAT_fffffff0270921c8 >> 0xe & 0xffffffff) * 0x10);
    uVar8 = extraout_x1;
  }
  lVar7 = UnkSytemRegRead(3,6,0xf,8,0);
  if (lVar7 == 0) {
    lVar7 = tpidr_el2;
  }
  else {
    lVar7 = UnkSytemRegRead(3,6,0xf,0xb,1);
  }
  if (8 < *(long *)(lVar7 + 0xb08) - 1U) {
LAB_fffffff0270e0424:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: Unexpected Dispatch ID %llu");
  }
  if (((*(ulong *)(&DAT_fffffff027092228 + (ulong)*(byte *)(puVar6 + 1) * 0x90) >>
        ((ulong)((int)*(long *)(lVar7 + 0xb08) - 1) & 0x3f) & 1) == 0) ||
     ((uint)(byte)(&DAT_fffffff027092230)[(ulong)*(byte *)(puVar6 + 1) * 0x90] < (uint)param_2)) {
    FUN_fffffff0270dff30();
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c
              (0x2a,extraout_x1_00,
               "%s(%s:%d) - paddr(%#llx), fte(%p), fte->type(%s), current_iommu(%u), allowed_permissions(%u), mapping_type(%u)\n"
              );
  }
  uVar9 = (ulong)*(byte *)(puVar6 + 1);
  if ((DAT_fffffff0270921e0 <= param_1 || param_1 < DAT_fffffff0270921d8) &&
     (*(byte *)(puVar6 + 1) == 0)) {
    FUN_fffffff0270d0240(0xff000000,uVar8,"%s(%s:%d) - %s(%#llx), %s(%#llx)\n");
    uVar9 = (ulong)*(byte *)(puVar6 + 1);
    uVar8 = extraout_x1_03;
  }
  if (((&DAT_fffffff027092201)[uVar9 * 0x90] == '\x06') && (*(uint *)(puVar6 + 2) >> 0x18 != 0)) {
    uVar4 = (*(uint *)(puVar6 + 2) >> 0x18) - 1;
    if ((uint)DAT_fffffff0270914e8 <= (uVar4 & 0xff)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc("%s: IO range restriction (%d) out of bounds");
    }
    pbVar1 = (byte *)(DAT_fffffff0270914e0 + ((ulong)uVar4 & 0xff) + (ulong)(byte)uVar4 * 0x10);
    if (DAT_fffffff0270914e0 != 0) {
      if (*pbVar1 == 1) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff0270f353c(0x3d,uVar8,"%s(%s:%d) - %s(%#llx), %s(%#llx)\n");
      }
      FUN_fffffff0270dff30();
      lVar7 = FUN_fffffff0270de830();
      uVar4 = *(uint *)(lVar7 + 0x54);
      bVar2 = *pbVar1;
      FUN_fffffff0270dff30();
      lVar7 = FUN_fffffff0270de830();
      iVar5 = *(int *)(lVar7 + 0x54);
      bVar3 = *pbVar1;
      FUN_fffffff0270dff30();
      lVar7 = FUN_fffffff0270de830();
      if (((*(int *)(lVar7 + 0x54) + (uint)bVar3 ^ iVar5 + (uint)bVar2) + 1 <<
           (ulong)(*pbVar1 & 0x1f) & uVar4) == 0) {
        FUN_fffffff0270dff30(puVar6);
                    /* WARNING: Subroutine does not return */
        FUN_fffffff0270f353c(0x3d,extraout_x1_01,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx)\n");
      }
    }
  }
  if ((DAT_fffffff027100028 & 1) != 0) {
    iVar5 = FUN_fffffff0270b8eb0(param_1);
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f353c(0x5d,extraout_x1_02,"%s(%s:%d) - %s(%#llx)\n");
    }
    if ((DAT_fffffff027100028 & 1) != 0) {
      lVar7 = UnkSytemRegRead(3,6,0xf,8,0);
      if (lVar7 == 0) {
        lVar7 = tpidr_el2;
      }
      else {
        lVar7 = UnkSytemRegRead(3,6,0xf,0xb,1);
      }
      if (8 < *(long *)(lVar7 + 0xb08) - 1U) goto LAB_fffffff0270e0424;
      if (*(long *)(lVar7 + 0xb08) == 3) goto LAB_fffffff0270e03ec;
    }
  }
  FUN_fffffff0270e06a4(puVar6,param_2,1);
LAB_fffffff0270e03ec:
  FUN_fffffff0270dfc5c(param_1);
  return;
}

