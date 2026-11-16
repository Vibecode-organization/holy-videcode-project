// FUN_fffffff009c33dc4 @ fffffff009c33dc4 size=272
// CALLERS:
//   fffffff009c33bec FUN_fffffff009c33bbc@fffffff009c33bbc
//   fffffff009c3ae6c FUN_fffffff009c3ab8c@fffffff009c3ab8c
//   fffffff009c3bd54 FUN_fffffff009c3bb20@fffffff009c3bb20
//   fffffff009c3c18c FUN_fffffff009c3bf44@fffffff009c3bf44

undefined8 FUN_fffffff009c33dc4(long param_1,long param_2,ulong param_3)

{
  long *plVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  uint uVar5;
  undefined8 uVar6;
  
  FUN_fffffff009c495b4(*(undefined8 *)(param_1 + 0x140));
  uVar5 = (uint)param_3;
  if ((uVar5 != 0) && (uVar5 < *(uint *)(param_1 + 0xd8))) {
    uVar2 = *(ulong *)(param_1 + 0xd0);
    uVar3 = uVar2 + (ulong)*(uint *)(param_1 + 0xd8) * 8;
    if (((uVar2 ^ uVar3) & 0xffc0000000000000) != 0) {
      uVar3 = uVar3 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar3 < uVar2) || (uVar3 - uVar2 >> 0x20 != 0)) {
      FUN_fffffff009c48f64();
    }
    else {
      lVar4 = (param_3 & 0xffffffff) * 8;
      if (lVar4 - (int)lVar4 == 0) {
        if (((param_3 & 0x1fffffff) >> 0x1c != 0) ||
           (uVar5 = uVar5 * 8, (uint)(uVar3 - uVar2) < uVar5 + 8)) goto LAB_fffffff009c33ecc;
        plVar1 = (long *)(uVar2 + uVar5);
        uVar2 = (ulong)CARRY8(uVar2,(ulong)uVar5);
        uVar3 = -uVar2;
        if ((uVar3 != uVar2) || ((long)uVar3 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        if (*plVar1 == 0) {
          *plVar1 = param_2;
          uVar6 = 1;
          goto LAB_fffffff009c33e98;
        }
        uVar6 = 0xfffffff00789c7e8;
        goto LAB_fffffff009c33e90;
      }
    }
    FUN_fffffff009c48f3c();
LAB_fffffff009c33ecc:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff009c48f28();
  }
  uVar6 = 0xfffffff00789c7b7;
LAB_fffffff009c33e90:
  FUN_fffffff009c495f4(uVar6);
  uVar6 = 0;
LAB_fffffff009c33e98:
  FUN_fffffff009c495d4(*(undefined8 *)(param_1 + 0x140));
  return uVar6;
}

