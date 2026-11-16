// FUN_fffffff009c35dcc @ fffffff009c35dcc size=424

void FUN_fffffff009c35dcc(long param_1,long param_2,ulong param_3)

{
  ulong *puVar1;
  long *plVar2;
  uint uVar3;
  code *pcVar4;
  char *pcVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  uint uVar10;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x140));
  uVar10 = (uint)param_3;
  if ((uVar10 != 0) && (uVar10 < *(uint *)(param_1 + 0xd8))) {
    uVar7 = *(ulong *)(param_1 + 0xd0);
    uVar8 = uVar7 + (ulong)*(uint *)(param_1 + 0xd8) * 8;
    if (((uVar7 ^ uVar8) & 0xffc0000000000000) != 0) {
      uVar8 = uVar8 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar8 < uVar7) || (uVar8 - uVar7 >> 0x20 != 0)) {
      FUN_fffffff009c48f64();
    }
    else {
      uVar6 = param_3 & 0xffffffff;
      if (uVar6 * 8 - (long)(int)(uVar6 * 8) == 0) {
        if (((param_3 & 0x1fffffff) >> 0x1c != 0) ||
           (uVar3 = uVar10 * 8, (uint)(uVar8 - uVar7) < uVar3 + 8)) goto LAB_fffffff009c35f60;
        plVar2 = (long *)(uVar7 + uVar3);
        uVar7 = (ulong)CARRY8(uVar7,(ulong)uVar3);
        uVar8 = -uVar7;
        if ((uVar8 != uVar7) || ((long)uVar8 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        lVar9 = *plVar2;
        if ((lVar9 == 0) || (lVar9 == param_2)) {
          if (uVar6 < *(ulong *)(param_1 + 0xe0)) {
            *(ulong *)(param_1 + 0xe0) = uVar6;
          }
          *plVar2 = 0;
          uVar7 = *(ulong *)(param_1 + 0xe8);
          uVar8 = uVar7 + (ulong)*(uint *)(param_1 + 0xf0) * 8;
          if (((uVar7 ^ uVar8) & 0xffc0000000000000) != 0) {
            uVar8 = uVar8 & 0xffffffffffff | 0xc8a2000000000000;
          }
          if ((uVar8 < uVar7) || (uVar8 - uVar7 >> 0x20 != 0)) {
            FUN_fffffff009c48f64();
LAB_fffffff009c35f6c:
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50();
          }
          uVar10 = uVar10 >> 3 & 0x1ffffff8;
          if ((uint)(uVar8 - uVar7) < uVar10 + 8) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f28();
          }
          puVar1 = (ulong *)(uVar7 + uVar10);
          uVar7 = (ulong)CARRY8(uVar7,(ulong)uVar10);
          uVar8 = -uVar7;
          if ((uVar8 != uVar7) || ((long)uVar8 < 0)) goto LAB_fffffff009c35f6c;
          *puVar1 = *puVar1 & ~(1L << (param_3 & 0x3f));
          goto LAB_fffffff009c35ea8;
        }
        pcVar5 = "Entry for surface handle %d %p is not equal to %p";
        goto LAB_fffffff009c35ea4;
      }
    }
    FUN_fffffff009c48f3c();
LAB_fffffff009c35f60:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff009c48f28();
  }
  pcVar5 = "trying to free apparently bogus surface handle %d";
LAB_fffffff009c35ea4:
  thunk_EXT_FUN_80110000038fe9a0(pcVar5);
LAB_fffffff009c35ea8:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c35ecc);
    (*pcVar4)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
  return;
}

