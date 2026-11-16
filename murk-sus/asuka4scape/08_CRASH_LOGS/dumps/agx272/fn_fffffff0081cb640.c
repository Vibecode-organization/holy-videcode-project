// FUN_fffffff0081cb640 @ fffffff0081cb640 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff0081cd3d8) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081cc4e4) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081cc3cc) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081cc49c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081cd064) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081cd858) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081cc384) */

void FUN_fffffff0081cb640(long *param_1)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  float *pfVar5;
  ulong *puVar6;
  uint *puVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  bool bVar11;
  int iVar12;
  int iVar13;
  ulong uVar14;
  long lVar15;
  int iVar16;
  ulong uVar17;
  uint *puVar18;
  ulong uVar19;
  uint uVar20;
  uint uVar21;
  long lVar22;
  undefined8 uVar23;
  ulong uVar24;
  ulong uVar25;
  long lVar26;
  long lVar27;
  long lVar28;
  long lVar29;
  long lVar30;
  int iVar31;
  long lVar32;
  undefined8 uVar33;
  long *plVar34;
  undefined4 *puVar35;
  int *piVar36;
  float fVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined8 uVar40;
  undefined1 auVar41 [16];
  undefined8 uVar42;
  undefined8 uVar43;
  undefined8 uVar44;
  undefined8 uVar45;
  undefined8 uVar46;
  undefined8 uVar47;
  float fVar48;
  ulong uVar49;
  undefined8 uVar50;
  undefined8 uVar51;
  undefined8 uVar52;
  undefined8 uVar53;
  undefined8 uVar54;
  undefined8 uVar55;
  undefined8 uVar56;
  undefined8 uVar57;
  undefined8 uVar58;
  undefined8 uVar59;
  undefined8 uVar60;
  undefined8 uVar61;
  undefined8 uVar62;
  undefined8 uVar63;
  undefined8 uVar64;
  undefined8 uVar65;
  undefined8 uVar66;
  undefined8 uVar67;
  undefined8 uVar68;
  undefined8 uVar69;
  undefined8 uVar70;
  
  lVar22 = param_1[0x58];
  uVar33 = *(undefined8 *)(lVar22 + 0x6bd8);
  uVar23 = *(undefined8 *)(lVar22 + 0x28d8);
  uVar40 = *(undefined8 *)(lVar22 + 0x28b8);
  uVar10 = *(undefined8 *)(lVar22 + 0x28c0);
  uVar45 = *(undefined8 *)(lVar22 + 0x28d0);
  uVar42 = *(undefined8 *)(lVar22 + 0x28c8);
  uVar46 = *(undefined8 *)(lVar22 + 0x28a0);
  uVar43 = *(undefined8 *)(lVar22 + 0x2898);
  uVar44 = *(undefined8 *)(lVar22 + 0x28a8);
  uVar47 = *(undefined8 *)(lVar22 + 0x28b0);
  lVar22 = param_1[0x69];
  auVar41 = *(undefined1 (*) [16])(param_1 + 0x36a);
  lVar27 = param_1[0x369];
  lVar29 = param_1[0x368];
  lVar26 = param_1[0x367];
  lVar28 = param_1[0x366];
  lVar32 = param_1[0x364];
  *(long *)(lVar22 + 0xac) = param_1[0x365];
  *(long *)(lVar22 + 0xa4) = lVar32;
  *(long *)(lVar22 + 0xbc) = lVar26;
  *(long *)(lVar22 + 0xb4) = lVar28;
  *(long *)(lVar22 + 0xcc) = lVar27;
  *(long *)(lVar22 + 0xc4) = lVar29;
  *(long *)(lVar22 + 0xdc) = auVar41._8_8_;
  *(long *)(lVar22 + 0xd4) = auVar41._0_8_;
  *(undefined1 *)(param_1[0x123] + 0x5c8) = 0;
  FUN_fffffff0081a80e0();
  uVar24 = 0;
  lVar22 = param_1[0x58];
  *(undefined8 *)(lVar22 + 0x6bd8) = uVar33;
  *(undefined8 *)(lVar22 + 0x28d8) = uVar23;
  *(undefined8 *)(lVar22 + 0x28c0) = uVar10;
  *(undefined8 *)(lVar22 + 0x28b8) = uVar40;
  *(undefined8 *)(lVar22 + 0x28d0) = uVar45;
  *(undefined8 *)(lVar22 + 0x28c8) = uVar42;
  *(undefined8 *)(lVar22 + 0x28a0) = uVar46;
  *(undefined8 *)(lVar22 + 0x2898) = uVar43;
  *(undefined8 *)(lVar22 + 0x28b0) = uVar47;
  *(undefined8 *)(lVar22 + 0x28a8) = uVar44;
  lVar27 = param_1[0x58];
  lVar22 = lVar27 + 0xbff;
  lVar29 = lVar27 + 0x1bff;
  lVar27 = lVar27 + 0x1fff;
  lVar28 = 0x10;
  do {
    puVar9 = (undefined8 *)(lVar22 + ((uVar24 & 0x7fffffffffffff) << 8 | 0x10));
    puVar9[1] = 0;
    *puVar9 = 0;
    puVar9 = (undefined8 *)(lVar29 + uVar24 * 0x40);
    puVar9[1] = 0x7fff7fff7fff7fff;
    *puVar9 = 0x7fff7fff7fff7fff;
    *(undefined1 *)(lVar27 + uVar24 * 0x20) = 0;
    puVar9 = (undefined8 *)(lVar22 + uVar24 * 0x100);
    puVar9[1] = 0;
    *puVar9 = 0;
    *(undefined4 *)(lVar27 + ((uVar24 & 0x3ffffffffffffff) << 5 | 1)) = 0;
    puVar9 = (undefined8 *)(lVar22 + ((uVar24 & 0x7fffffffffffff) << 8 | 0x20));
    puVar9[1] = 0;
    *puVar9 = 0;
    puVar9 = (undefined8 *)(lVar22 + ((uVar24 & 0x7fffffffffffff) << 8 | 0x30));
    puVar9[1] = 0;
    *puVar9 = 0;
    *(undefined4 *)(lVar27 + ((uVar24 & 0x3ffffffffffffff) << 5 | 5)) = 0;
    *(undefined1 *)(lVar27 + ((uVar24 & 0x3ffffffffffffff) << 5 | 9)) = 0;
    puVar9 = (undefined8 *)(lVar22 + ((uVar24 & 0x7fffffffffffff) << 8 | 0x40));
    puVar9[1] = 0;
    *puVar9 = 0;
    puVar9 = (undefined8 *)(lVar22 + ((uVar24 & 0x7fffffffffffff) << 8 | 0x50));
    puVar9[1] = 0;
    *puVar9 = 0;
    *(undefined4 *)(lVar27 + ((uVar24 & 0x3ffffffffffffff) << 5 | 10)) = 0;
    puVar9 = (undefined8 *)(lVar22 + ((uVar24 & 0x7fffffffffffff) << 8 | 0x60));
    puVar9[1] = 0;
    *puVar9 = 0;
    puVar9 = (undefined8 *)(lVar29 + ((uVar24 & 0x1ffffffffffffff) << 6 | 0x10));
    puVar9[1] = 0x7fff7fff7fff7fff;
    *puVar9 = 0x7fff7fff7fff7fff;
    puVar9 = (undefined8 *)(lVar22 + ((uVar24 & 0x7fffffffffffff) << 8 | 0x70));
    puVar9[1] = 0;
    *puVar9 = 0;
    *(undefined4 *)(lVar27 + ((uVar24 & 0x3ffffffffffffff) << 5 | 0xe)) = 0;
    puVar9 = (undefined8 *)(lVar22 + ((uVar24 & 0x7fffffffffffff) << 8 | 0x80));
    puVar9[1] = 0;
    *puVar9 = 0;
    *(undefined1 *)(lVar27 + ((uVar24 & 0x3ffffffffffffff) << 5 | 0x12)) = 0;
    puVar9 = (undefined8 *)(lVar22 + ((uVar24 & 0x7fffffffffffff) << 8 | 0x90));
    puVar9[1] = 0;
    *puVar9 = 0;
    puVar9 = (undefined8 *)(lVar22 + ((uVar24 & 0x7fffffffffffff) << 8 | 0xa0));
    puVar9[1] = 0;
    *puVar9 = 0;
    *(undefined4 *)(lVar27 + ((uVar24 & 0x3ffffffffffffff) << 5 | 0x13)) = 0;
    puVar9 = (undefined8 *)(lVar29 + ((uVar24 & 0x1ffffffffffffff) << 6 | 0x20));
    puVar9[1] = 0x7fff7fff7fff7fff;
    *puVar9 = 0x7fff7fff7fff7fff;
    puVar9 = (undefined8 *)(lVar22 + ((uVar24 & 0x7fffffffffffff) << 8 | 0xb0));
    puVar9[1] = 0;
    *puVar9 = 0;
    puVar9 = (undefined8 *)(lVar22 + ((uVar24 & 0x7fffffffffffff) << 8 | 0xc0));
    puVar9[1] = 0;
    *puVar9 = 0;
    *(undefined4 *)(lVar27 + ((uVar24 & 0x3ffffffffffffff) << 5 | 0x17)) = 0;
    *(undefined1 *)(lVar27 + ((uVar24 & 0x3ffffffffffffff) << 5 | 0x1b)) = 0;
    puVar9 = (undefined8 *)(lVar22 + ((uVar24 & 0x7fffffffffffff) << 8 | 0xd0));
    puVar9[1] = 0;
    *puVar9 = 0;
    *(undefined1 *)(lVar27 + ((uVar24 & 0x3ffffffffffffff) << 5 | 0x1c)) = 0;
    *(undefined1 *)(lVar27 + ((uVar24 & 0x3ffffffffffffff) << 5 | 0x1d)) = 0;
    puVar9 = (undefined8 *)(lVar22 + ((uVar24 & 0x7fffffffffffff) << 8 | 0xe0));
    puVar9[1] = 0;
    *puVar9 = 0;
    *(undefined1 *)(lVar27 + ((uVar24 & 0x3ffffffffffffff) << 5 | 0x1e)) = 0;
    uVar14 = uVar24 & 0x7fffffffffffff;
    puVar9 = (undefined8 *)(lVar29 + ((uVar24 & 0x1ffffffffffffff) << 6 | 0x30));
    puVar9[1] = 0x7fff7fff7fff7fff;
    *puVar9 = 0x7fff7fff7fff7fff;
    uVar17 = uVar24 & 0x3ffffffffffffff;
    uVar24 = uVar24 + 1;
    *(undefined1 *)(lVar27 + (uVar17 << 5 | 0x1f)) = 0;
    puVar9 = (undefined8 *)(lVar22 + (uVar14 << 8 | 0xf0));
    puVar9[1] = 0;
    *puVar9 = 0;
    lVar28 = lVar28 + -1;
  } while (lVar28 != 0);
  plVar34 = param_1 + 0x152;
  plVar1 = param_1 + 0x15a;
  uVar24 = (long)plVar1 - (long)plVar34;
  plVar2 = param_1 + 0x162;
  plVar3 = param_1 + 0x16a;
  if ((plVar1 < plVar34) || (uVar24 >> 0x20 != 0)) {
LAB_fffffff0081cd920:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff008214ca8
              (
              "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
              );
  }
  if (((long)plVar2 - (long)plVar1 & 0xffffffff00000000U) != 0 || plVar2 < plVar1) {
    if (uVar24 < 4) goto LAB_fffffff0081cd96c;
    *(int *)(param_1[0x58] + 0x6ad4) = (int)param_1[0x152];
    goto LAB_fffffff0081cd920;
  }
  if (((long)plVar3 - (long)plVar2 & 0xffffffff00000000U) != 0 || plVar3 < plVar2) {
    if (3 < uVar24) {
      lVar22 = param_1[0x58];
      *(int *)(lVar22 + 0x6ad4) = (int)param_1[0x152];
      if (3 < (ulong)((long)plVar2 - (long)plVar1)) {
        *(int *)(lVar22 + 0x6b14) = (int)*plVar1;
        goto LAB_fffffff0081cd920;
      }
    }
LAB_fffffff0081cd96c:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff008214ca8
              (
              "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
              );
  }
  uVar24 = 0;
  lVar22 = 0;
  do {
    uVar14 = -(ulong)CARRY8((ulong)plVar34,uVar24);
    if ((uVar14 != CARRY8((ulong)plVar34,uVar24)) || ((long)uVar14 < 0)) goto LAB_fffffff0081cd8a4;
    lVar29 = param_1[0x58];
    *(undefined4 *)(lVar29 + 0x6ad4 + lVar22 * 4) = *(undefined4 *)((long)plVar34 + uVar24);
    uVar14 = -(ulong)CARRY8((ulong)plVar1,uVar24);
    if ((uVar14 != CARRY8((ulong)plVar1,uVar24)) || ((long)uVar14 < 0)) goto LAB_fffffff0081cd8a4;
    *(undefined4 *)(lVar29 + 0x6b14 + lVar22 * 4) = *(undefined4 *)((long)plVar1 + uVar24);
    uVar14 = -(ulong)CARRY8((ulong)plVar2,uVar24);
    if ((uVar14 != CARRY8((ulong)plVar2,uVar24)) || ((long)uVar14 < 0)) goto LAB_fffffff0081cd8a4;
    *(undefined4 *)(lVar29 + 0x6b54 + lVar22 * 4) = *(undefined4 *)((long)plVar2 + uVar24);
    lVar22 = lVar22 + 1;
    uVar24 = uVar24 + 4;
  } while (uVar24 != 0x40);
  plVar34 = param_1 + 0x16b;
  if ((plVar34 < plVar3) || ((ulong)((long)plVar34 - (long)plVar3) >> 0x20 != 0))
  goto LAB_fffffff0081cd920;
  plVar1 = param_1 + 0x16c;
  if ((ulong)((long)plVar1 - (long)plVar34) >> 0x20 != 0 || plVar1 < plVar34) {
    if ((ulong)((long)plVar34 - (long)plVar3) < 4) goto LAB_fffffff0081cd96c;
    *(int *)(lVar29 + 0x6b94) = (int)*plVar3;
    goto LAB_fffffff0081cd920;
  }
  *(int *)(lVar29 + 0x6b94) = (int)*plVar3;
  *(int *)(lVar29 + 0x6b9c) = (int)*plVar34;
  if (-(ulong)((long *)0xfffffffffffffffb < plVar3) != (ulong)((long *)0xfffffffffffffffb < plVar3))
  {
LAB_fffffff0081cd8a4:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff008214ca8
              (
              "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
              );
  }
  *(undefined4 *)(lVar29 + 0x6b98) = *(undefined4 *)((long)param_1 + 0xb54);
  if (-(ulong)((long *)0xfffffffffffffffb < plVar34) !=
      (ulong)((long *)0xfffffffffffffffb < plVar34)) goto LAB_fffffff0081cd8a4;
  *(undefined4 *)(lVar29 + 0x6ba0) = *(undefined4 *)((long)param_1 + 0xb5c);
  plVar34 = param_1 + 0x16d;
  if ((plVar34 < plVar1) || ((ulong)((long)plVar34 - (long)plVar1) >> 0x20 != 0))
  goto LAB_fffffff0081cd920;
  if ((ulong)((long)(param_1 + 0x16e) - (long)plVar34) >> 0x20 != 0 || param_1 + 0x16e < plVar34) {
    if ((ulong)((long)plVar34 - (long)plVar1) < 4) goto LAB_fffffff0081cd96c;
    *(int *)(lVar29 + 0x6ba4) = (int)*plVar1;
    goto LAB_fffffff0081cd920;
  }
  *(int *)(lVar29 + 0x6ba4) = (int)*plVar1;
  *(int *)(lVar29 + 0x6bac) = (int)*plVar34;
  if (-(ulong)((long *)0xfffffffffffffffb < plVar1) != (ulong)((long *)0xfffffffffffffffb < plVar1))
  goto LAB_fffffff0081cd8a4;
  *(undefined4 *)(lVar29 + 0x6ba8) = *(undefined4 *)((long)param_1 + 0xb64);
  if (-(ulong)((long *)0xfffffffffffffffb < plVar34) !=
      (ulong)((long *)0xfffffffffffffffb < plVar34)) goto LAB_fffffff0081cd8a4;
  lVar22 = param_1[0x50] + 0x19488;
  lVar30 = param_1[0x54];
  lVar28 = lVar30 + 0x1124;
  lVar27 = param_1[0x50] + 0x19888;
  *(undefined4 *)(lVar29 + 0x6bb0) = *(undefined4 *)((long)param_1 + 0xb6c);
  lVar26 = lVar30 + 0x1524;
  lVar32 = 0x10;
  uVar24 = 0;
  do {
    lVar15 = uVar24 * 0x40;
    *(undefined4 *)(lVar28 + lVar15) = *(undefined4 *)(lVar22 + lVar15);
    *(undefined4 *)(lVar26 + lVar15) = *(undefined4 *)(lVar27 + lVar15);
    uVar14 = (uVar24 & 0x1ffffffffffffff) << 6 | 4;
    *(undefined4 *)(lVar28 + uVar14) = *(undefined4 *)(lVar22 + uVar14);
    *(undefined4 *)(lVar26 + uVar14) = *(undefined4 *)(lVar27 + uVar14);
    uVar14 = (uVar24 & 0x1ffffffffffffff) << 6 | 8;
    *(undefined4 *)(lVar28 + uVar14) = *(undefined4 *)(lVar22 + uVar14);
    uVar17 = (uVar24 & 0x1ffffffffffffff) << 6 | 0xc;
    *(undefined4 *)(lVar26 + uVar14) = *(undefined4 *)(lVar27 + uVar14);
    *(undefined4 *)(lVar28 + uVar17) = *(undefined4 *)(lVar22 + uVar17);
    *(undefined4 *)(lVar26 + uVar17) = *(undefined4 *)(lVar27 + uVar17);
    uVar14 = (uVar24 & 0x1ffffffffffffff) << 6 | 0x10;
    *(undefined4 *)(lVar28 + uVar14) = *(undefined4 *)(lVar22 + uVar14);
    *(undefined4 *)(lVar26 + uVar14) = *(undefined4 *)(lVar27 + uVar14);
    uVar14 = (uVar24 & 0x1ffffffffffffff) << 6 | 0x14;
    *(undefined4 *)(lVar28 + uVar14) = *(undefined4 *)(lVar22 + uVar14);
    uVar17 = (uVar24 & 0x1ffffffffffffff) << 6 | 0x18;
    *(undefined4 *)(lVar26 + uVar14) = *(undefined4 *)(lVar27 + uVar14);
    *(undefined4 *)(lVar28 + uVar17) = *(undefined4 *)(lVar22 + uVar17);
    *(undefined4 *)(lVar26 + uVar17) = *(undefined4 *)(lVar27 + uVar17);
    uVar14 = (uVar24 & 0x1ffffffffffffff) << 6 | 0x1c;
    *(undefined4 *)(lVar28 + uVar14) = *(undefined4 *)(lVar22 + uVar14);
    *(undefined4 *)(lVar26 + uVar14) = *(undefined4 *)(lVar27 + uVar14);
    uVar14 = (uVar24 & 0x1ffffffffffffff) << 6 | 0x20;
    *(undefined4 *)(lVar28 + uVar14) = *(undefined4 *)(lVar22 + uVar14);
    uVar17 = (uVar24 & 0x1ffffffffffffff) << 6 | 0x24;
    *(undefined4 *)(lVar26 + uVar14) = *(undefined4 *)(lVar27 + uVar14);
    *(undefined4 *)(lVar28 + uVar17) = *(undefined4 *)(lVar22 + uVar17);
    *(undefined4 *)(lVar26 + uVar17) = *(undefined4 *)(lVar27 + uVar17);
    uVar14 = (uVar24 & 0x1ffffffffffffff) << 6 | 0x28;
    *(undefined4 *)(lVar28 + uVar14) = *(undefined4 *)(lVar22 + uVar14);
    *(undefined4 *)(lVar26 + uVar14) = *(undefined4 *)(lVar27 + uVar14);
    uVar14 = (uVar24 & 0x1ffffffffffffff) << 6 | 0x2c;
    *(undefined4 *)(lVar28 + uVar14) = *(undefined4 *)(lVar22 + uVar14);
    uVar17 = (uVar24 & 0x1ffffffffffffff) << 6 | 0x30;
    *(undefined4 *)(lVar26 + uVar14) = *(undefined4 *)(lVar27 + uVar14);
    *(undefined4 *)(lVar28 + uVar17) = *(undefined4 *)(lVar22 + uVar17);
    *(undefined4 *)(lVar26 + uVar17) = *(undefined4 *)(lVar27 + uVar17);
    uVar14 = (uVar24 & 0x1ffffffffffffff) << 6 | 0x34;
    *(undefined4 *)(lVar28 + uVar14) = *(undefined4 *)(lVar22 + uVar14);
    *(undefined4 *)(lVar26 + uVar14) = *(undefined4 *)(lVar27 + uVar14);
    uVar14 = (uVar24 & 0x1ffffffffffffff) << 6 | 0x38;
    *(undefined4 *)(lVar28 + uVar14) = *(undefined4 *)(lVar22 + uVar14);
    uVar17 = (uVar24 & 0x1ffffffffffffff) << 6 | 0x3c;
    *(undefined4 *)(lVar26 + uVar14) = *(undefined4 *)(lVar27 + uVar14);
    *(undefined4 *)(lVar28 + uVar17) = *(undefined4 *)(lVar22 + uVar17);
    uVar39 = *(undefined4 *)(lVar27 + uVar17);
    *(undefined4 *)(lVar30 + 0x1964 + uVar24 * 4) = *(undefined4 *)(lVar29 + 0xd0 + uVar24 * 4);
    *(undefined4 *)(lVar26 + uVar17) = uVar39;
    *(undefined4 *)(lVar30 + 0x19a4 + uVar24 * 4) = *(undefined4 *)(lVar29 + 0x110 + uVar24 * 4);
    uVar24 = uVar24 + 1;
    lVar32 = lVar32 + -1;
  } while (lVar32 != 0);
  lVar22 = param_1[0x50];
  if ((*(byte *)(lVar22 + 0x43d) & 1) != 0) {
    lVar29 = param_1[0x54];
    *(undefined8 *)(lVar29 + 0x1ca4) = 0;
    *(undefined8 *)(lVar29 + 0x1c8c) = 0;
    *(undefined8 *)(lVar29 + 0x1c84) = 0;
    *(undefined8 *)(lVar29 + 0x1c9c) = 0;
    *(undefined8 *)(lVar29 + 0x1c94) = 0;
    *(undefined8 *)(lVar29 + 0x1c6c) = 0;
    *(undefined8 *)(lVar29 + 0x1c64) = 0;
    *(undefined8 *)(lVar29 + 0x1c7c) = 0;
    *(undefined8 *)(lVar29 + 0x1c74) = 0;
    *(undefined8 *)(lVar29 + 0x1c4c) = 0;
    *(undefined8 *)(lVar29 + 0x1c44) = 0;
    *(undefined8 *)(lVar29 + 0x1c5c) = 0;
    *(undefined8 *)(lVar29 + 0x1c54) = 0;
    *(undefined8 *)(lVar29 + 0x1c2c) = 0;
    *(undefined8 *)(lVar29 + 0x1c24) = 0;
    *(undefined8 *)(lVar29 + 0x1c3c) = 0;
    *(undefined8 *)(lVar29 + 0x1c34) = 0;
    *(undefined8 *)(lVar29 + 0x1c0c) = 0;
    *(undefined8 *)(lVar29 + 0x1c04) = 0;
    *(undefined8 *)(lVar29 + 0x1c1c) = 0;
    *(undefined8 *)(lVar29 + 0x1c14) = 0;
    *(undefined8 *)(lVar29 + 0x1bec) = 0;
    *(undefined8 *)(lVar29 + 0x1be4) = 0;
    *(undefined8 *)(lVar29 + 0x1bfc) = 0;
    *(undefined8 *)(lVar29 + 0x1bf4) = 0;
    *(undefined8 *)(lVar29 + 0x1bcc) = 0;
    *(undefined8 *)(lVar29 + 0x1bc4) = 0;
    *(undefined8 *)(lVar29 + 0x1bdc) = 0;
    *(undefined8 *)(lVar29 + 0x1bd4) = 0;
    *(undefined8 *)(lVar29 + 0x1bac) = 0;
    *(undefined8 *)(lVar29 + 0x1ba4) = 0;
    *(undefined8 *)(lVar29 + 0x1bbc) = 0;
    *(undefined8 *)(lVar29 + 0x1bb4) = 0;
    *(undefined8 *)(lVar29 + 0x1b8c) = 0;
    *(undefined8 *)(lVar29 + 0x1b84) = 0;
    *(undefined8 *)(lVar29 + 0x1b9c) = 0;
    *(undefined8 *)(lVar29 + 0x1b94) = 0;
    *(undefined8 *)(lVar29 + 0x1b6c) = 0;
    *(undefined8 *)(lVar29 + 0x1b64) = 0;
    *(undefined8 *)(lVar29 + 0x1b7c) = 0;
    *(undefined8 *)(lVar29 + 0x1b74) = 0;
    iVar12 = *(int *)(lVar22 + 0x1a4d0);
    *(int *)(lVar29 + 0x1b64) = iVar12 + -1;
    *(int *)(lVar29 + 0x1b68) = (int)param_1[0x16f];
    if (iVar12 != 0) {
      uVar24 = 0;
      do {
        *(uint *)(lVar29 + 0x1b6c + uVar24 * 4) = *(uint *)(lVar22 + 0x1a4d8 + uVar24 * 4) / 1000000
        ;
        if (*(int *)(lVar22 + 0x1a4d4) != 0) {
          uVar14 = 0;
          do {
            uVar17 = lVar22 + 0x1a518U + uVar24 * 8;
            if (((lVar22 + 0x1a518U ^ uVar17) & 0xffc0000000000000) != 0) {
              uVar17 = uVar17 & 0xffffffffffff | 0xc8a2000000000000;
            }
            uVar19 = lVar29 + 0x1bacU + uVar24 * 8;
            if (((lVar29 + 0x1bacU ^ uVar19) & 0xffc0000000000000) != 0) {
              uVar19 = uVar19 & 0xffffffffffff | 0xc8a2000000000000;
            }
            *(undefined4 *)(uVar19 + uVar14 * 4) = *(undefined4 *)(uVar17 + uVar14 * 4);
            uVar17 = lVar22 + 0x1a598U + uVar24 * 8;
            if (((lVar22 + 0x1a598U ^ uVar17) & 0xffc0000000000000) != 0) {
              uVar17 = uVar17 & 0xffffffffffff | 0xc8a2000000000000;
            }
            uVar19 = lVar29 + 0x1c2cU + uVar24 * 8;
            if (((lVar29 + 0x1c2cU ^ uVar19) & 0xffc0000000000000) != 0) {
              uVar19 = uVar19 & 0xffffffffffff | 0xc8a2000000000000;
            }
            *(undefined4 *)(uVar19 + uVar14 * 4) = *(undefined4 *)(uVar17 + uVar14 * 4);
            uVar14 = uVar14 + 1;
          } while (uVar14 < *(uint *)(lVar22 + 0x1a4d4));
        }
        uVar24 = uVar24 + 1;
      } while (uVar24 < *(uint *)(lVar22 + 0x1a4d0));
    }
  }
  lVar22 = param_1[0x50];
  if ((*(byte *)(lVar22 + 0x43e) & 1) != 0) {
    lVar29 = param_1[0x54];
    *(undefined8 *)(lVar29 + 0x1dec) = 0;
    *(undefined8 *)(lVar29 + 0x1dd4) = 0;
    *(undefined8 *)(lVar29 + 0x1dcc) = 0;
    *(undefined8 *)(lVar29 + 0x1de4) = 0;
    *(undefined8 *)(lVar29 + 0x1ddc) = 0;
    *(undefined8 *)(lVar29 + 0x1db4) = 0;
    *(undefined8 *)(lVar29 + 0x1dac) = 0;
    *(undefined8 *)(lVar29 + 0x1dc4) = 0;
    *(undefined8 *)(lVar29 + 0x1dbc) = 0;
    *(undefined8 *)(lVar29 + 0x1d94) = 0;
    *(undefined8 *)(lVar29 + 0x1d8c) = 0;
    *(undefined8 *)(lVar29 + 0x1da4) = 0;
    *(undefined8 *)(lVar29 + 0x1d9c) = 0;
    *(undefined8 *)(lVar29 + 0x1d74) = 0;
    *(undefined8 *)(lVar29 + 0x1d6c) = 0;
    *(undefined8 *)(lVar29 + 0x1d84) = 0;
    *(undefined8 *)(lVar29 + 0x1d7c) = 0;
    *(undefined8 *)(lVar29 + 0x1d54) = 0;
    *(undefined8 *)(lVar29 + 0x1d4c) = 0;
    *(undefined8 *)(lVar29 + 0x1d64) = 0;
    *(undefined8 *)(lVar29 + 0x1d5c) = 0;
    *(undefined8 *)(lVar29 + 0x1d34) = 0;
    *(undefined8 *)(lVar29 + 0x1d2c) = 0;
    *(undefined8 *)(lVar29 + 0x1d44) = 0;
    *(undefined8 *)(lVar29 + 0x1d3c) = 0;
    *(undefined8 *)(lVar29 + 0x1d14) = 0;
    *(undefined8 *)(lVar29 + 0x1d0c) = 0;
    *(undefined8 *)(lVar29 + 0x1d24) = 0;
    *(undefined8 *)(lVar29 + 0x1d1c) = 0;
    *(undefined8 *)(lVar29 + 0x1cf4) = 0;
    *(undefined8 *)(lVar29 + 0x1cec) = 0;
    *(undefined8 *)(lVar29 + 0x1d04) = 0;
    *(undefined8 *)(lVar29 + 0x1cfc) = 0;
    *(undefined8 *)(lVar29 + 0x1cd4) = 0;
    *(undefined8 *)(lVar29 + 0x1ccc) = 0;
    *(undefined8 *)(lVar29 + 0x1ce4) = 0;
    *(undefined8 *)(lVar29 + 0x1cdc) = 0;
    *(undefined8 *)(lVar29 + 0x1cb4) = 0;
    *(undefined8 *)(lVar29 + 0x1cac) = 0;
    *(undefined8 *)(lVar29 + 0x1cc4) = 0;
    *(undefined8 *)(lVar29 + 0x1cbc) = 0;
    iVar12 = *(int *)(lVar22 + 0x1a618);
    *(int *)(lVar29 + 0x1cac) = iVar12 + -1;
    *(undefined4 *)(lVar29 + 0x1cb0) = *(undefined4 *)((long)param_1 + 0xb7c);
    if (iVar12 != 0) {
      uVar24 = 0;
      do {
        *(uint *)(lVar29 + 0x1cb4 + uVar24 * 4) = *(uint *)(lVar22 + 0x1a620 + uVar24 * 4) / 1000000
        ;
        if (*(int *)(lVar22 + 0x1a61c) != 0) {
          uVar14 = 0;
          do {
            uVar17 = lVar22 + 0x1a660U + uVar24 * 8;
            if (((lVar22 + 0x1a660U ^ uVar17) & 0xffc0000000000000) != 0) {
              uVar17 = uVar17 & 0xffffffffffff | 0xc8a2000000000000;
            }
            uVar19 = lVar29 + 0x1cf4U + uVar24 * 8;
            if (((lVar29 + 0x1cf4U ^ uVar19) & 0xffc0000000000000) != 0) {
              uVar19 = uVar19 & 0xffffffffffff | 0xc8a2000000000000;
            }
            *(undefined4 *)(uVar19 + uVar14 * 4) = *(undefined4 *)(uVar17 + uVar14 * 4);
            uVar17 = lVar22 + 0x1a6e0U + uVar24 * 8;
            if (((lVar22 + 0x1a6e0U ^ uVar17) & 0xffc0000000000000) != 0) {
              uVar17 = uVar17 & 0xffffffffffff | 0xc8a2000000000000;
            }
            uVar19 = lVar29 + 0x1d74U + uVar24 * 8;
            if (((lVar29 + 0x1d74U ^ uVar19) & 0xffc0000000000000) != 0) {
              uVar19 = uVar19 & 0xffffffffffff | 0xc8a2000000000000;
            }
            *(undefined4 *)(uVar19 + uVar14 * 4) = *(undefined4 *)(uVar17 + uVar14 * 4);
            uVar14 = uVar14 + 1;
          } while (uVar14 < *(uint *)(lVar22 + 0x1a61c));
        }
        uVar24 = uVar24 + 1;
      } while (uVar24 < *(uint *)(lVar22 + 0x1a618));
    }
  }
  lVar22 = param_1[0x50];
  if ((*(byte *)(lVar22 + 0x439) & 1) != 0) {
    lVar29 = param_1[0x54];
    thunk_EXT_FUN_8011000003a61cc0(lVar29 + 0x1df4,0x848);
    iVar12 = *(int *)(lVar22 + 0x19c88);
    *(int *)(lVar29 + 0x1df4) = iVar12 + -1;
    if (iVar12 != 0) {
      uVar24 = 0;
      do {
        *(uint *)(lVar29 + 0x1df8 + uVar24 * 4) = *(uint *)(lVar22 + 0x19c90 + uVar24 * 4) / 1000000
        ;
        if (*(int *)(lVar22 + 0x19c8c) != 0) {
          uVar14 = 0;
          do {
            uVar17 = lVar22 + 0x19cd0U + uVar24 * 0x40;
            if (((lVar22 + 0x19cd0U ^ uVar17) & 0xffc0000000000000) != 0) {
              uVar17 = uVar17 & 0xffffffffffff | 0xc8a2000000000000;
            }
            uVar19 = lVar29 + 0x1e38U + uVar24 * 0x40;
            if (((lVar29 + 0x1e38U ^ uVar19) & 0xffc0000000000000) != 0) {
              uVar19 = uVar19 & 0xffffffffffff | 0xc8a2000000000000;
            }
            *(undefined4 *)(uVar19 + uVar14 * 4) = *(undefined4 *)(uVar17 + uVar14 * 4);
            uVar17 = lVar22 + 0x1a0d0U + uVar24 * 0x40;
            if (((lVar22 + 0x1a0d0U ^ uVar17) & 0xffc0000000000000) != 0) {
              uVar17 = uVar17 & 0xffffffffffff | 0xc8a2000000000000;
            }
            uVar19 = lVar29 + 0x2238U + uVar24 * 0x40;
            if (((lVar29 + 0x2238U ^ uVar19) & 0xffc0000000000000) != 0) {
              uVar19 = uVar19 & 0xffffffffffff | 0xc8a2000000000000;
            }
            *(undefined4 *)(uVar19 + uVar14 * 4) = *(undefined4 *)(uVar17 + uVar14 * 4);
            uVar14 = uVar14 + 1;
          } while (uVar14 < *(uint *)(lVar22 + 0x19c8c));
        }
        uVar24 = uVar24 + 1;
      } while (uVar24 < *(uint *)(lVar22 + 0x19c88));
    }
  }
  lVar22 = param_1[0x54];
  lVar29 = param_1[0x50];
  *(undefined8 *)(lVar22 + 0x1b4c) = 0;
  *(undefined8 *)(lVar22 + 0x1b44) = 0;
  *(undefined8 *)(lVar22 + 0x1b5c) = 0;
  *(undefined8 *)(lVar22 + 0x1b54) = 0;
  *(undefined8 *)(lVar22 + 0x1b2c) = 0;
  *(undefined8 *)(lVar22 + 0x1b24) = 0;
  *(undefined8 *)(lVar22 + 0x1b3c) = 0;
  *(undefined8 *)(lVar22 + 0x1b34) = 0;
  *(undefined8 *)(lVar22 + 0x1b0c) = 0;
  *(undefined8 *)(lVar22 + 0x1b04) = 0;
  *(undefined8 *)(lVar22 + 0x1b1c) = 0;
  *(undefined8 *)(lVar22 + 0x1b14) = 0;
  *(undefined8 *)(lVar22 + 0x1aec) = 0;
  *(undefined8 *)(lVar22 + 0x1ae4) = 0;
  *(undefined8 *)(lVar22 + 0x1afc) = 0;
  *(undefined8 *)(lVar22 + 0x1af4) = 0;
  *(undefined4 *)(lVar22 + 0x1ae4) = *(undefined4 *)(lVar29 + 0x18b78);
  *(undefined4 *)(lVar22 + 0x1b24) = *(undefined4 *)(lVar29 + 0x18bb8);
  *(undefined4 *)(lVar22 + 0x1ae8) = *(undefined4 *)(lVar29 + 0x18b7c);
  *(undefined4 *)(lVar22 + 0x1b28) = *(undefined4 *)(lVar29 + 0x18bbc);
  *(undefined4 *)(lVar22 + 0x1aec) = *(undefined4 *)(lVar29 + 0x18b80);
  *(undefined4 *)(lVar22 + 0x1b2c) = *(undefined4 *)(lVar29 + 0x18bc0);
  *(undefined4 *)(lVar22 + 0x1af0) = *(undefined4 *)(lVar29 + 0x18b84);
  *(undefined4 *)(lVar22 + 0x1b30) = *(undefined4 *)(lVar29 + 0x18bc4);
  *(undefined4 *)(lVar22 + 0x1af4) = *(undefined4 *)(lVar29 + 0x18b88);
  *(undefined4 *)(lVar22 + 0x1b34) = *(undefined4 *)(lVar29 + 0x18bc8);
  *(undefined4 *)(lVar22 + 0x1af8) = *(undefined4 *)(lVar29 + 0x18b8c);
  *(undefined4 *)(lVar22 + 0x1b38) = *(undefined4 *)(lVar29 + 0x18bcc);
  *(undefined4 *)(lVar22 + 0x1afc) = *(undefined4 *)(lVar29 + 0x18b90);
  *(undefined4 *)(lVar22 + 0x1b3c) = *(undefined4 *)(lVar29 + 0x18bd0);
  *(undefined4 *)(lVar22 + 0x1b00) = *(undefined4 *)(lVar29 + 0x18b94);
  *(undefined4 *)(lVar22 + 0x1b40) = *(undefined4 *)(lVar29 + 0x18bd4);
  *(undefined4 *)(lVar22 + 0x1b04) = *(undefined4 *)(lVar29 + 0x18b98);
  *(undefined4 *)(lVar22 + 0x1b44) = *(undefined4 *)(lVar29 + 0x18bd8);
  *(undefined4 *)(lVar22 + 0x1b08) = *(undefined4 *)(lVar29 + 0x18b9c);
  *(undefined4 *)(lVar22 + 0x1b48) = *(undefined4 *)(lVar29 + 0x18bdc);
  *(undefined4 *)(lVar22 + 0x1b0c) = *(undefined4 *)(lVar29 + 0x18ba0);
  *(undefined4 *)(lVar22 + 0x1b4c) = *(undefined4 *)(lVar29 + 0x18be0);
  *(undefined4 *)(lVar22 + 0x1b10) = *(undefined4 *)(lVar29 + 0x18ba4);
  *(undefined4 *)(lVar22 + 0x1b50) = *(undefined4 *)(lVar29 + 0x18be4);
  *(undefined4 *)(lVar22 + 0x1b14) = *(undefined4 *)(lVar29 + 0x18ba8);
  *(undefined4 *)(lVar22 + 0x1b54) = *(undefined4 *)(lVar29 + 0x18be8);
  *(undefined4 *)(lVar22 + 0x1b18) = *(undefined4 *)(lVar29 + 0x18bac);
  *(undefined4 *)(lVar22 + 7000) = *(undefined4 *)(lVar29 + 0x18bec);
  *(undefined4 *)(lVar22 + 0x1b1c) = *(undefined4 *)(lVar29 + 0x18bb0);
  *(undefined4 *)(lVar22 + 0x1b5c) = *(undefined4 *)(lVar29 + 0x18bf0);
  *(undefined4 *)(lVar22 + 0x1b20) = *(undefined4 *)(lVar29 + 0x18bb4);
  *(undefined4 *)(lVar22 + 0x1b60) = *(undefined4 *)(lVar29 + 0x18bf4);
  lVar22 = param_1[0x50];
  *(uint *)(param_1[0x58] + 0x6ac8) = *(uint *)(lVar22 + 0x5c8) >> 0x11 & 1;
  FUN_fffffff00817eee4(lVar22,param_1[0x54] + 0x19e4,0);
  lVar29 = param_1[0x58];
  lVar22 = param_1[0x50];
  auVar41 = NEON_ext(*(undefined1 (*) [16])(lVar22 + 0x10f1c),
                     *(undefined1 (*) [16])(lVar22 + 0x10f1c),4,1);
  *(long *)(lVar29 + 0xb48) = auVar41._8_8_;
  *(long *)(lVar29 + 0xb40) = auVar41._0_8_;
  uVar21 = *(uint *)(lVar22 + 0x19440);
  if (0x10 < uVar21) {
    thunk_EXT_FUN_8011000003a49114
              (
              "AGXk: %s:%d:%s: !!! Verification failed: %s: max pState greater than num supported.\n"
              );
    return;
  }
  lVar27 = param_1[0x54] + 0x1a24;
  uVar20 = *(uint *)(lVar29 + 0xb90);
  uVar24 = (ulong)uVar20 / 100;
  lVar22 = lVar22 + 0x19448;
  uVar14 = (ulong)*(uint *)(lVar22 + uVar24 * 4);
  uVar17 = (ulong)uVar21 - 1;
  lVar29 = uVar17 * 4;
  iVar12 = (int)lVar29;
  puVar7 = (uint *)(lVar22 + iVar12);
  if (lVar29 - iVar12 != 0) {
    puVar7 = (uint *)(lVar22 + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar8 = *puVar7;
  thunk_EXT_FUN_8011000003a61cc0(lVar27,(ulong)uVar21 << 2);
  if (uVar17 <= uVar24) goto LAB_fffffff0081cc270;
  fVar37 = (float)(uVar8 - uVar14);
  uVar19 = (ulong)(uVar20 / 100 + 1);
  lVar28 = 0;
  if (uVar19 <= uVar17) {
    lVar28 = uVar17 - uVar19;
  }
  uVar4 = lVar28 + 1;
  if (uVar4 < 0xc) {
LAB_fffffff0081cc20c:
    uVar20 = uVar20 / 100;
  }
  else {
    uVar25 = 0;
    if (uVar19 <= uVar17) {
      uVar25 = uVar17 - uVar19;
    }
    if (((CARRY4(uVar20 / 100,(uint)uVar25)) || (-(uVar20 / 100) - 2 < (uint)uVar25)) ||
       (uVar25 >> 0x20 != 0)) goto LAB_fffffff0081cc20c;
    lVar28 = 0;
    uVar25 = uVar4 & 0xfffffffffffffffc;
    uVar19 = uVar25;
    do {
      lVar26 = (lVar28 + uVar24) * 4;
      iVar13 = (int)lVar26;
      puVar6 = (ulong *)(lVar22 + iVar13);
      if (lVar26 - iVar13 != 0) {
        puVar6 = (ulong *)(lVar22 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar49 = *puVar6;
      puVar9 = (undefined8 *)(lVar27 + iVar13);
      if (lVar26 - iVar13 != 0) {
        puVar9 = (undefined8 *)(lVar27 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
      }
      puVar9[1] = CONCAT44(((float)((puVar6[1] >> 0x20) - uVar14) * 100.0) / fVar37,
                           ((float)((puVar6[1] & 0xffffffff) - uVar14) * 100.0) / fVar37);
      *puVar9 = CONCAT44(((float)((uVar49 >> 0x20) - uVar14) * 100.0) / fVar37,
                         ((float)((uVar49 & 0xffffffff) - uVar14) * 100.0) / fVar37);
      lVar28 = lVar28 + 4;
      uVar19 = uVar19 - 4;
    } while (uVar19 != 0);
    if (uVar4 == uVar25) goto LAB_fffffff0081cc270;
    uVar20 = uVar20 / 100 + (int)uVar25;
    uVar24 = uVar25 + uVar24;
  }
  do {
    uVar20 = uVar20 + 1;
    lVar28 = uVar24 * 4;
    iVar13 = (int)lVar28;
    puVar7 = (uint *)(lVar22 + iVar13);
    if (lVar28 - iVar13 != 0) {
      puVar7 = (uint *)(lVar22 + lVar28 & 0xffffffffffffU | 0x2bad000000000000);
    }
    pfVar5 = (float *)(lVar27 + iVar13);
    if (lVar28 - iVar13 != 0) {
      pfVar5 = (float *)(lVar27 + lVar28 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *pfVar5 = ((float)(*puVar7 - uVar14) * 100.0) / fVar37;
    uVar24 = (ulong)uVar20;
  } while (uVar24 < uVar17);
LAB_fffffff0081cc270:
  puVar35 = (undefined4 *)(lVar27 + iVar12);
  if (lVar29 - iVar12 != 0) {
    puVar35 = (undefined4 *)(lVar27 + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar35 = 0x42c80000;
  lVar29 = param_1[0x58];
  lVar22 = param_1[0x50];
  *(undefined4 *)(lVar29 + 0x9c8) = *(undefined4 *)(lVar22 + 0x10ec8);
  *(undefined4 *)(lVar29 + 0xb50) = *(undefined4 *)(lVar22 + 0x10f2c);
  uVar40 = *(undefined8 *)(lVar22 + 0x10aac);
  *(undefined8 *)(lVar29 + 0xa4) = uVar40;
  *(undefined8 *)(lVar29 + 0x9c) = uVar40;
  if ((*(byte *)(lVar22 + 0x10f78) & 1) != 0) {
    *(undefined8 *)(lVar29 + 0x2a80) = 0;
    *(undefined8 *)(lVar29 + 0x2a78) = 0;
    *(undefined8 *)(lVar29 + 0x2a90) = 0;
    *(undefined8 *)(lVar29 + 0x2a88) = 0;
    *(undefined8 *)(lVar29 + 0x2a60) = 0;
    *(undefined8 *)(lVar29 + 0x2a58) = 0;
    *(undefined8 *)(lVar29 + 0x2a70) = 0;
    *(undefined8 *)(lVar29 + 0x2a68) = 0;
    *(undefined8 *)(lVar29 + 0x2a40) = 0;
    *(undefined8 *)(lVar29 + 0x2a38) = 0;
    *(undefined8 *)(lVar29 + 0x2a50) = 0;
    *(undefined8 *)(lVar29 + 0x2a48) = 0;
    *(undefined8 *)(lVar29 + 0x2a20) = 0;
    *(undefined8 *)(lVar29 + 0x2a18) = 0;
    *(undefined8 *)(lVar29 + 0x2a30) = 0;
    *(undefined8 *)(lVar29 + 0x2a28) = 0;
    *(undefined8 *)(lVar29 + 0x2a00) = 0;
    *(undefined8 *)(lVar29 + 0x29f8) = 0;
    *(undefined8 *)(lVar29 + 0x2a10) = 0;
    *(undefined8 *)(lVar29 + 0x2a08) = 0;
    *(undefined8 *)(lVar29 + 0x29e0) = 0;
    *(undefined8 *)(lVar29 + 0x29d8) = 0;
    *(undefined8 *)(lVar29 + 0x29f0) = 0;
    *(undefined8 *)(lVar29 + 0x29e8) = 0;
    *(undefined8 *)(lVar29 + 0x29c0) = 0;
    *(undefined8 *)(lVar29 + 0x29b8) = 0;
    *(undefined8 *)(lVar29 + 0x29d0) = 0;
    *(undefined8 *)(lVar29 + 0x29c8) = 0;
    *(undefined8 *)(lVar29 + 0x29a0) = 0;
    *(undefined8 *)(lVar29 + 0x2998) = 0;
    *(undefined8 *)(lVar29 + 0x29b0) = 0;
    *(undefined8 *)(lVar29 + 0x29a8) = 0;
    *(undefined8 *)(lVar29 + 0x2980) = 0;
    *(undefined8 *)(lVar29 + 0x2978) = 0;
    *(undefined8 *)(lVar29 + 0x2990) = 0;
    *(undefined8 *)(lVar29 + 0x2988) = 0;
    *(undefined8 *)(lVar29 + 0x2960) = 0;
    *(undefined8 *)(lVar29 + 0x2958) = 0;
    *(undefined8 *)(lVar29 + 0x2970) = 0;
    *(undefined8 *)(lVar29 + 0x2968) = 0;
    *(undefined8 *)(lVar29 + 0x2940) = 0;
    *(undefined8 *)(lVar29 + 0x2938) = 0;
    *(undefined8 *)(lVar29 + 0x2950) = 0;
    *(undefined8 *)(lVar29 + 0x2948) = 0;
    *(undefined8 *)(lVar29 + 0x2920) = 0;
    *(undefined8 *)(lVar29 + 0x2918) = 0;
    *(undefined8 *)(lVar29 + 0x2930) = 0;
    *(undefined8 *)(lVar29 + 0x2928) = 0;
    *(undefined8 *)(lVar29 + 0x2900) = 0;
    *(undefined8 *)(lVar29 + 0x28f8) = 0;
    *(undefined8 *)(lVar29 + 0x2910) = 0;
    *(undefined8 *)(lVar29 + 0x2908) = 0;
    *(undefined8 *)(lVar29 + 0x28f0) = 0;
    *(undefined8 *)(lVar29 + 0x28e8) = 0;
    *(uint *)(lVar29 + 0x28e8) = *(byte *)(lVar22 + 0x10f78) & 1;
    *(undefined4 *)(lVar29 + 0x28ec) = *(undefined4 *)(lVar22 + 0x10f84);
    uVar39 = *(undefined4 *)(lVar22 + 0x10f7c);
    *(undefined4 *)(lVar29 + 0x28f0) = uVar39;
    *(undefined4 *)(lVar29 + 0x28f4) = uVar39;
    *(undefined4 *)(lVar29 + 0x28f8) = uVar39;
    uVar21 = *(uint *)(lVar22 + 0x10f8c);
    fVar37 = (float)uVar21;
    uVar40 = NEON_fmov(0x3f800000,4);
    fVar48 = (float)((ulong)uVar40 >> 0x20);
    *(ulong *)(lVar29 + 0x2904) = CONCAT44(fVar48 / fVar37,(fVar37 + -1.0) / fVar37);
    *(undefined4 *)(lVar29 + 0x290c) = *(undefined4 *)(lVar22 + 0x10f90);
    iVar12 = (**(code **)(*(long *)param_1[0x50] + 0xb80))(*(long *)param_1[0x50] + 0xb80);
    *(uint *)(lVar29 + 0x2910) = iVar12 * uVar21;
    iVar12 = *(int *)(lVar22 + 0x10f8c);
    iVar13 = (**(code **)(*(long *)param_1[0x50] + 0xb80))(*(long *)param_1[0x50] + 0xb80);
    *(ulong *)(lVar29 + 0x2914) = (ulong)(uint)(iVar12 * iVar13 * 24000);
    *(undefined4 *)(lVar29 + 0x2a94) = 0;
    if (*(int *)(lVar22 + 0x10f80) != 0) {
      uVar24 = 0;
      do {
        piVar36 = (int *)(lVar22 + 0x10f94U + uVar24 * 0x10);
        if (((lVar22 + 0x10f94U ^ (ulong)piVar36) & 0xffc0000000000000) != 0) {
          piVar36 = (int *)((ulong)piVar36 & 0xffffffffffff | 0xc8a2000000000000);
        }
        puVar35 = (undefined4 *)(param_1[0x58] + 0x291cU + uVar24 * 0x28);
        if (((param_1[0x58] + 0x291cU ^ (ulong)puVar35) & 0xffc0000000000000) != 0) {
          puVar35 = (undefined4 *)((ulong)puVar35 & 0xffffffffffff | 0xc8a2000000000000);
        }
        iVar12 = *piVar36;
        iVar13 = piVar36[1];
        *puVar35 = 0;
        puVar35[1] = iVar12;
        uVar21 = piVar36[2];
        iVar31 = piVar36[3];
        puVar35[2] = iVar12 - iVar13;
        puVar35[3] = iVar31;
        fVar37 = (float)uVar21;
        *(ulong *)(puVar35 + 7) = CONCAT44(fVar48 / fVar37,(fVar37 + -1.0) / fVar37);
        iVar12 = (**(code **)(*(long *)param_1[0x50] + 0xb80))(*(long *)param_1[0x50] + 0xb80);
        puVar35[4] = iVar12 * uVar21;
        iVar12 = piVar36[2];
        iVar13 = (**(code **)(*(long *)param_1[0x50] + 0xb80))(*(long *)param_1[0x50] + 0xb80);
        *(ulong *)(puVar35 + 5) = (ulong)(uint)(iVar12 * iVar13 * 24000);
        uVar24 = uVar24 + 1;
      } while (uVar24 < *(uint *)(lVar22 + 0x10f80));
    }
    lVar29 = param_1[0x58];
    *(undefined4 *)(lVar29 + 0x29e4) = *(undefined4 *)(lVar22 + 0x11000);
    *(undefined4 *)(lVar29 + 0x29e8) = 0;
    fVar37 = (float)NEON_ucvtf(*(undefined4 *)(lVar22 + 0x10ff0));
    *(float *)(lVar29 + 0x29f0) = (fVar37 + -1.0) / fVar37;
    *(float *)(lVar29 + 0x29f8) = 1.0 / fVar37;
    *(undefined4 *)(lVar29 + 0x2a00) = *(undefined4 *)(lVar22 + 0x11014);
    uVar38 = *(undefined4 *)(lVar22 + 0x11020);
    *(undefined4 *)(lVar29 + 0x2a10) = uVar38;
    uVar40 = NEON_scvtf(*(undefined8 *)(lVar22 + 0x11018),4);
    *(undefined8 *)(lVar29 + 0x2a08) = uVar40;
    *(undefined4 *)(lVar29 + 0x2a18) = *(undefined4 *)(lVar22 + 0x11024);
    *(undefined8 *)(lVar29 + 0x2a1c) = *(undefined8 *)(lVar22 + 0x11028);
    uVar39 = *(undefined4 *)(lVar22 + 0x11030);
    *(undefined4 *)(lVar29 + 0x2a24) = uVar39;
    uVar21 = *(uint *)(lVar22 + 0x1100c);
    *(float *)(lVar29 + 0x2a2c) = (float)uVar21;
    *(uint *)(lVar29 + 0x2a30) = uVar21;
    *(undefined4 *)(lVar29 + 0x2a64) = uVar39;
    *(undefined4 *)(lVar29 + 0x2a3c) = *(undefined4 *)(lVar22 + 0x10ff4);
    *(undefined8 *)(lVar29 + 0x2a44) = *(undefined8 *)(lVar22 + 0x10ff8);
    *(undefined4 *)(lVar29 + 0x2a38) = 0;
    *(undefined4 *)(lVar29 + 0x2a60) = *(undefined4 *)(lVar22 + 0x11040);
    *(undefined4 *)(lVar29 + 0x2a68) = *(undefined4 *)(lVar22 + 0x11044);
    uVar24 = (ulong)*(uint *)(lVar22 + 0x10f80);
    if (*(uint *)(lVar22 + 0x10f80) == 0) {
      lVar27 = param_1[0x123];
    }
    else {
      lVar26 = 0;
      lVar27 = param_1[0x123];
      lVar28 = lVar27 + 0x24;
      do {
        piVar36 = (int *)(lVar22 + 0x10f94U + lVar26 * 0x10);
        if (((lVar22 + 0x10f94U ^ (ulong)piVar36) & 0xffc0000000000000) != 0) {
          piVar36 = (int *)((ulong)piVar36 & 0xffffffffffff | 0xc8a2000000000000);
        }
        iVar12 = *piVar36;
        lVar32 = lVar26 * 0xc;
        *(int *)(lVar28 + lVar32) = iVar12;
        *(int *)(lVar28 + lVar32 + 4) = iVar12 - piVar36[1];
        *(int *)(lVar28 + lVar32 + 8) = piVar36[2];
        lVar26 = lVar26 + 1;
        uVar24 = uVar24 - 1;
      } while (uVar24 != 0);
    }
    *(undefined4 *)(lVar27 + 0xc) = *(undefined4 *)(lVar22 + 0x10f84);
    *(undefined4 *)(lVar27 + 0x10) = *(undefined4 *)(lVar22 + 0x10ff0);
    *(undefined4 *)(lVar27 + 0x14) = *(undefined4 *)(lVar22 + 0x11014);
    *(undefined4 *)(lVar27 + 0x18) = uVar38;
    *(undefined4 *)(lVar27 + 0x1c) = *(undefined4 *)(lVar22 + 0x11028);
    *(undefined4 *)(lVar27 + 0x20) = *(undefined4 *)(lVar22 + 0x10f8c);
    lVar22 = param_1[0x50];
  }
  *(undefined4 *)(lVar29 + 0x2270) = 0;
  *(undefined8 *)(lVar29 + 0x2278) = *(undefined8 *)(lVar22 + 0x10ab8);
  iVar12 = *(int *)(lVar22 + 0x10ac8);
  if (*(int *)(lVar22 + 0x10b0c) != 0) {
    iVar12 = *(int *)(lVar22 + 0x10b0c);
  }
  *(int *)(lVar29 + 0x2280) = iVar12;
  lVar27 = 0x20;
  if (*(int *)(lVar22 + 0x10b14) != 0) {
    lVar27 = 0x58;
  }
  *(undefined4 *)(lVar29 + 0x2284) = *(undefined4 *)(lVar22 + 0x10ab8 + lVar27);
  *(undefined4 *)(lVar29 + 0x2524) = 0;
  uVar40 = *(undefined8 *)(lVar22 + 0x10b2c);
  uVar10 = *(undefined8 *)(lVar22 + 0x10b34);
  uVar47 = *(undefined8 *)(lVar22 + 0x10b44);
  uVar44 = *(undefined8 *)(lVar22 + 0x10b3c);
  uVar33 = *(undefined8 *)(lVar22 + 0x10b54);
  uVar23 = *(undefined8 *)(lVar22 + 0x10b4c);
  uVar43 = *(undefined8 *)(lVar22 + 0x10b64);
  uVar42 = *(undefined8 *)(lVar22 + 0x10b5c);
  uVar46 = *(undefined8 *)(lVar22 + 0x10b74);
  uVar45 = *(undefined8 *)(lVar22 + 0x10b6c);
  uVar51 = *(undefined8 *)(lVar22 + 0x10b84);
  uVar50 = *(undefined8 *)(lVar22 + 0x10b7c);
  uVar53 = *(undefined8 *)(lVar22 + 0x10b94);
  uVar52 = *(undefined8 *)(lVar22 + 0x10b8c);
  uVar55 = *(undefined8 *)(lVar22 + 0x10ba4);
  uVar54 = *(undefined8 *)(lVar22 + 0x10b9c);
  uVar57 = *(undefined8 *)(lVar22 + 0x10bb4);
  uVar56 = *(undefined8 *)(lVar22 + 0x10bac);
  uVar59 = *(undefined8 *)(lVar22 + 0x10bc4);
  uVar58 = *(undefined8 *)(lVar22 + 0x10bbc);
  uVar61 = *(undefined8 *)(lVar22 + 0x10bd4);
  uVar60 = *(undefined8 *)(lVar22 + 0x10bcc);
  uVar63 = *(undefined8 *)(lVar22 + 0x10be4);
  uVar62 = *(undefined8 *)(lVar22 + 0x10bdc);
  uVar65 = *(undefined8 *)(lVar22 + 0x10bf4);
  uVar64 = *(undefined8 *)(lVar22 + 0x10bec);
  uVar67 = *(undefined8 *)(lVar22 + 0x10c04);
  uVar66 = *(undefined8 *)(lVar22 + 0x10bfc);
  uVar69 = *(undefined8 *)(lVar22 + 0x10c14);
  uVar68 = *(undefined8 *)(lVar22 + 0x10c0c);
  uVar70 = *(undefined8 *)(lVar22 + 0x10c1c);
  *(undefined8 *)(lVar29 + 0x2418) = *(undefined8 *)(lVar22 + 0x10c24);
  *(undefined8 *)(lVar29 + 0x2410) = uVar70;
  *(undefined8 *)(lVar29 + 0x2408) = uVar69;
  *(undefined8 *)(lVar29 + 0x2400) = uVar68;
  *(undefined8 *)(lVar29 + 0x23f8) = uVar67;
  *(undefined8 *)(lVar29 + 0x23f0) = uVar66;
  *(undefined8 *)(lVar29 + 0x23e8) = uVar65;
  *(undefined8 *)(lVar29 + 0x23e0) = uVar64;
  *(undefined8 *)(lVar29 + 0x23d8) = uVar63;
  *(undefined8 *)(lVar29 + 0x23d0) = uVar62;
  *(undefined8 *)(lVar29 + 0x23c8) = uVar61;
  *(undefined8 *)(lVar29 + 0x23c0) = uVar60;
  *(undefined8 *)(lVar29 + 0x23b8) = uVar59;
  *(undefined8 *)(lVar29 + 0x23b0) = uVar58;
  *(undefined8 *)(lVar29 + 0x23a8) = uVar57;
  *(undefined8 *)(lVar29 + 0x23a0) = uVar56;
  *(undefined8 *)(lVar29 + 0x2398) = uVar55;
  *(undefined8 *)(lVar29 + 0x2390) = uVar54;
  *(undefined8 *)(lVar29 + 0x2388) = uVar53;
  *(undefined8 *)(lVar29 + 0x2380) = uVar52;
  *(undefined8 *)(lVar29 + 0x2378) = uVar51;
  *(undefined8 *)(lVar29 + 0x2370) = uVar50;
  *(undefined8 *)(lVar29 + 0x2368) = uVar46;
  *(undefined8 *)(lVar29 + 0x2360) = uVar45;
  *(undefined8 *)(lVar29 + 0x2358) = uVar43;
  *(undefined8 *)(lVar29 + 0x2350) = uVar42;
  *(undefined8 *)(lVar29 + 0x2348) = uVar33;
  *(undefined8 *)(lVar29 + 0x2340) = uVar23;
  *(undefined8 *)(lVar29 + 0x2338) = uVar47;
  *(undefined8 *)(lVar29 + 0x2330) = uVar44;
  *(undefined8 *)(lVar29 + 9000) = uVar10;
  *(undefined8 *)(lVar29 + 0x2320) = uVar40;
  lVar27 = param_1[0x58];
  uVar40 = *(undefined8 *)(lVar22 + 0x10c2c);
  uVar10 = *(undefined8 *)(lVar22 + 0x10c34);
  uVar47 = *(undefined8 *)(lVar22 + 0x10c44);
  uVar44 = *(undefined8 *)(lVar22 + 0x10c3c);
  uVar33 = *(undefined8 *)(lVar22 + 0x10c54);
  uVar23 = *(undefined8 *)(lVar22 + 0x10c4c);
  uVar43 = *(undefined8 *)(lVar22 + 0x10c64);
  uVar42 = *(undefined8 *)(lVar22 + 0x10c5c);
  uVar46 = *(undefined8 *)(lVar22 + 0x10c74);
  uVar45 = *(undefined8 *)(lVar22 + 0x10c6c);
  uVar51 = *(undefined8 *)(lVar22 + 0x10c84);
  uVar50 = *(undefined8 *)(lVar22 + 0x10c7c);
  uVar53 = *(undefined8 *)(lVar22 + 0x10c94);
  uVar52 = *(undefined8 *)(lVar22 + 0x10c8c);
  uVar55 = *(undefined8 *)(lVar22 + 0x10ca4);
  uVar54 = *(undefined8 *)(lVar22 + 0x10c9c);
  uVar57 = *(undefined8 *)(lVar22 + 0x10cb4);
  uVar56 = *(undefined8 *)(lVar22 + 0x10cac);
  uVar59 = *(undefined8 *)(lVar22 + 0x10cc4);
  uVar58 = *(undefined8 *)(lVar22 + 0x10cbc);
  uVar61 = *(undefined8 *)(lVar22 + 0x10cd4);
  uVar60 = *(undefined8 *)(lVar22 + 0x10ccc);
  uVar63 = *(undefined8 *)(lVar22 + 0x10ce4);
  uVar62 = *(undefined8 *)(lVar22 + 0x10cdc);
  uVar65 = *(undefined8 *)(lVar22 + 0x10cf4);
  uVar64 = *(undefined8 *)(lVar22 + 0x10cec);
  uVar67 = *(undefined8 *)(lVar22 + 0x10d04);
  uVar66 = *(undefined8 *)(lVar22 + 0x10cfc);
  uVar69 = *(undefined8 *)(lVar22 + 0x10d14);
  uVar68 = *(undefined8 *)(lVar22 + 0x10d0c);
  uVar70 = *(undefined8 *)(lVar22 + 0x10d1c);
  *(undefined8 *)(lVar27 + 0x2518) = *(undefined8 *)(lVar22 + 0x10d24);
  *(undefined8 *)(lVar27 + 0x2510) = uVar70;
  *(undefined8 *)(lVar27 + 0x2508) = uVar69;
  *(undefined8 *)(lVar27 + 0x2500) = uVar68;
  *(undefined8 *)(lVar27 + 0x24f8) = uVar67;
  *(undefined8 *)(lVar27 + 0x24f0) = uVar66;
  *(undefined8 *)(lVar27 + 0x24e8) = uVar65;
  *(undefined8 *)(lVar27 + 0x24e0) = uVar64;
  *(undefined8 *)(lVar27 + 0x24d8) = uVar63;
  *(undefined8 *)(lVar27 + 0x24d0) = uVar62;
  *(undefined8 *)(lVar27 + 0x24c8) = uVar61;
  *(undefined8 *)(lVar27 + 0x24c0) = uVar60;
  *(undefined8 *)(lVar27 + 0x24b8) = uVar59;
  *(undefined8 *)(lVar27 + 0x24b0) = uVar58;
  *(undefined8 *)(lVar27 + 0x24a8) = uVar57;
  *(undefined8 *)(lVar27 + 0x24a0) = uVar56;
  *(undefined8 *)(lVar27 + 0x2498) = uVar55;
  *(undefined8 *)(lVar27 + 0x2490) = uVar54;
  *(undefined8 *)(lVar27 + 0x2488) = uVar53;
  *(undefined8 *)(lVar27 + 0x2480) = uVar52;
  *(undefined8 *)(lVar27 + 0x2478) = uVar51;
  *(undefined8 *)(lVar27 + 0x2470) = uVar50;
  *(undefined8 *)(lVar27 + 0x2468) = uVar46;
  *(undefined8 *)(lVar27 + 0x2460) = uVar45;
  *(undefined8 *)(lVar27 + 0x2458) = uVar43;
  *(undefined8 *)(lVar27 + 0x2450) = uVar42;
  *(undefined8 *)(lVar27 + 0x2448) = uVar33;
  *(undefined8 *)(lVar27 + 0x2440) = uVar23;
  *(undefined8 *)(lVar27 + 0x2438) = uVar47;
  *(undefined8 *)(lVar27 + 0x2430) = uVar44;
  *(undefined8 *)(lVar27 + 0x2428) = uVar10;
  *(undefined8 *)(lVar27 + 0x2420) = uVar40;
  *(undefined4 *)(lVar29 + 0x228c) = 0;
  *(undefined4 *)(lVar29 + 0x2294) = *(undefined4 *)(lVar22 + 0x10adc);
  *(undefined4 *)(lVar29 + 0x229c) = *(undefined4 *)(lVar22 + 0x10ae0);
  *(undefined4 *)(lVar29 + 0x2288) = *(undefined4 *)(lVar22 + 0x10ae4);
  lVar27 = param_1[0x50];
  piVar36 = (int *)(lVar27 + 0x19440);
  fVar37 = *(float *)(lVar27 + 0x10b1c);
  if (*(float *)(lVar27 + 0x10b1c) == 0.0) {
    fVar37 = *(float *)(lVar27 + 0x10ae8);
  }
  *(float *)(lVar29 + 0x22b4) = fVar37;
  fVar37 = *(float *)(lVar27 + 0x10b20);
  if (*(float *)(lVar27 + 0x10b20) == 0.0) {
    fVar37 = *(float *)(lVar27 + 0x10aec);
  }
  *(float *)(lVar29 + 0x22a4) = fVar37;
  uVar40 = NEON_ucvtf(*(undefined8 *)(lVar22 + 0x10af0),4);
  *(undefined8 *)(lVar29 + 0x22ac) = uVar40;
  *(undefined4 *)(lVar29 + 0x22bc) = *(undefined4 *)(lVar22 + 0x10af8);
  *(undefined8 *)(lVar29 + 0x22c0) = *(undefined8 *)(lVar22 + 0x10afc);
  uVar39 = *(undefined4 *)(lVar22 + 0x10b04);
  *(undefined4 *)(lVar29 + 0x22c8) = uVar39;
  *(undefined4 *)(lVar29 + 0x22cc) = *(undefined4 *)(lVar22 + 0x10ad0);
  *(undefined4 *)(lVar29 + 0x2300) = 0;
  *(undefined4 *)(lVar29 + 0x22d0) = 0;
  iVar13 = *(int *)(lVar27 + 0x10b08);
  bVar11 = iVar13 != 0;
  iVar12 = *(int *)(lVar27 + 0x10ac4);
  if (bVar11) {
    iVar12 = iVar13;
  }
  *(int *)(lVar29 + 0x22d4) = iVar12;
  *(undefined4 *)(lVar29 + 0x2308) = uVar39;
  *(undefined4 *)(lVar29 + 0x22dc) = 0;
  uVar38 = *(undefined4 *)(lVar22 + 0x10b24);
  *(undefined4 *)(lVar29 + 0x2304) = uVar38;
  uVar39 = *(undefined4 *)(lVar22 + 0x10b28);
  *(undefined4 *)(lVar29 + 0x230c) = uVar39;
  iVar12 = *(int *)(lVar27 + 0x10ac4);
  if (bVar11) {
    iVar12 = iVar13;
  }
  lVar22 = param_1[0x123];
  *(int *)(lVar22 + 200) = iVar12;
  iVar12 = *(int *)(lVar27 + 0x10ac8);
  if (*(int *)(lVar27 + 0x10b0c) != 0) {
    iVar12 = *(int *)(lVar27 + 0x10b0c);
  }
  *(int *)(lVar22 + 0xcc) = iVar12;
  lVar29 = 0x20;
  if (*(int *)(lVar27 + 0x10b14) != 0) {
    lVar29 = 0x58;
  }
  *(undefined4 *)(lVar22 + 0xd0) = *(undefined4 *)(lVar27 + 0x10ab8 + lVar29);
  iVar12 = *(int *)(lVar27 + 0x10ad0);
  if (*(int *)(lVar27 + 0x10b18) != 0) {
    iVar12 = *(int *)(lVar27 + 0x10b18);
  }
  *(int *)(lVar22 + 0xd4) = iVar12;
  fVar37 = *(float *)(lVar27 + 0x10b1c);
  if (*(float *)(lVar27 + 0x10b1c) == 0.0) {
    fVar37 = *(float *)(lVar27 + 0x10ae8);
  }
  *(float *)(lVar22 + 0xd8) = fVar37;
  fVar37 = *(float *)(lVar27 + 0x10b20);
  if (*(float *)(lVar27 + 0x10b20) == 0.0) {
    fVar37 = *(float *)(lVar27 + 0x10aec);
  }
  *(float *)(lVar22 + 0xdc) = fVar37;
  *(undefined4 *)(lVar22 + 0xe0) = uVar38;
  *(undefined4 *)(lVar22 + 0xe4) = uVar39;
  *(uint *)(lVar22 + 0xe8) = (uint)bVar11;
  lVar29 = param_1[0x58];
  iVar12 = *(int *)(lVar27 + 0x1109c);
  *(bool *)(lVar29 + 0x2528) = iVar12 != 0;
  iVar13 = *(int *)(lVar27 + 0x110a0);
  *(bool *)(lVar29 + 0x2529) = iVar13 == 1;
  *(undefined4 *)(lVar29 + 0x27e2) = *(undefined4 *)(lVar27 + 0x110ac);
  *(undefined4 *)(lVar29 + 0x2732) = 0;
  *(undefined4 *)(lVar29 + 0x273a) = *(undefined4 *)(lVar27 + 0x110e8);
  *(undefined4 *)(lVar29 + 0x2742) = *(undefined4 *)(lVar27 + 0x110ec);
  fVar37 = *(float *)(lVar27 + 0x110f8);
  if (*(float *)(lVar27 + 0x110f8) == 0.0) {
    fVar37 = *(float *)(lVar27 + 0x110c4);
  }
  *(float *)(lVar29 + 0x275a) = fVar37;
  fVar37 = *(float *)(lVar27 + 0x110fc);
  if (*(float *)(lVar27 + 0x110fc) == 0.0) {
    fVar37 = *(float *)(lVar27 + 0x110c8);
  }
  *(float *)(lVar29 + 0x274a) = fVar37;
  uVar40 = NEON_scvtf(*(undefined8 *)(lVar27 + 0x110d8),4);
  *(undefined8 *)(lVar29 + 0x2752) = uVar40;
  *(undefined4 *)(lVar29 + 0x2762) = *(undefined4 *)(lVar27 + 0x110cc);
  *(undefined4 *)(lVar29 + 0x2766) = *(undefined4 *)(lVar27 + 0x110e0);
  if (iVar12 == 0) {
    iVar31 = *piVar36 * 100 + -100;
  }
  else {
    iVar31 = *(int *)(lVar27 + 0x110e4);
  }
  iVar16 = *(int *)(lVar27 + 0x110b0);
  *(int *)(lVar29 + 0x276a) = iVar31;
  *(int *)(lVar29 + 0x276e) = iVar16;
  *(undefined4 *)(lVar29 + 0x27a6) = 0;
  uVar39 = NEON_ucvtf(*(undefined4 *)(lVar27 + 0x110b8));
  *(undefined4 *)(lVar29 + 0x2776) = uVar39;
  iVar31 = *(int *)(lVar27 + 0x11104);
  if (iVar13 == 1) {
    iVar13 = iVar31;
    if (iVar31 == 0) {
      iVar13 = *(int *)(lVar29 + 0x277a);
    }
  }
  else {
    iVar13 = *(int *)(lVar27 + 0x110a4);
    if (iVar31 != 0) {
      iVar13 = iVar31;
    }
  }
  *(int *)(lVar29 + 0x277a) = iVar13;
  *(undefined4 *)(lVar29 + 0x2782) = *(undefined4 *)(lVar27 + 0x110a8);
  if (iVar12 == 0) {
    iVar16 = *piVar36 * 100 + -100;
  }
  *(int *)(lVar29 + 0x27ae) = iVar16;
  *(undefined4 *)(lVar29 + 0x27aa) = *(undefined4 *)(lVar27 + 0x110f0);
  *(undefined4 *)(lVar29 + 0x27b2) = *(undefined4 *)(lVar27 + 0x110f4);
  *(int *)(lVar27 + 0x110d4) = *(int *)(lVar27 + 0x110d0) * *(int *)(lVar27 + 0x110bc) * 24000;
  *(undefined4 *)(lVar29 + 0x273a) = *(undefined4 *)(lVar27 + 0x110e8);
  *(undefined4 *)(lVar29 + 0x2742) = *(undefined4 *)(lVar27 + 0x110ec);
  *(undefined4 *)(lVar22 + 0xf0) = *(undefined4 *)(lVar27 + 0x110a4);
  uVar39 = *(undefined4 *)(lVar27 + 0x110b4);
  *(undefined4 *)(lVar22 + 0xf4) = uVar39;
  uVar38 = *(undefined4 *)(lVar27 + 0x110c0);
  *(undefined4 *)(lVar22 + 0xf8) = uVar38;
  fVar37 = *(float *)(lVar27 + 0x110f8);
  if (*(float *)(lVar27 + 0x110f8) == 0.0) {
    fVar37 = *(float *)(lVar27 + 0x110c4);
  }
  *(float *)(lVar22 + 0x108) = fVar37;
  fVar37 = *(float *)(lVar27 + 0x110fc);
  if (*(float *)(lVar27 + 0x110fc) == 0.0) {
    fVar37 = *(float *)(lVar27 + 0x110c8);
  }
  *(float *)(lVar22 + 0x10c) = fVar37;
  iVar12 = *(int *)(lVar27 + 0x110d0);
  if (*(int *)(lVar27 + 0x11100) != 0) {
    iVar12 = *(int *)(lVar27 + 0x11100);
  }
  *(int *)(lVar22 + 0x110) = iVar12;
  *(uint *)(lVar22 + 0x118) = (uint)(iVar31 != 0);
  iVar12 = *(int *)(lVar27 + 0x110a8);
  if (*(int *)(lVar27 + 0x1110c) != 0) {
    iVar12 = *(int *)(lVar27 + 0x1110c);
  }
  *(int *)(lVar22 + 0x124) = iVar12;
  *(undefined4 *)(lVar29 + 0x27ca) = uVar39;
  *(undefined4 *)(lVar29 + 0x27ce) = uVar38;
  *(undefined8 *)(lVar29 + 0x27e6) = *(undefined8 *)(lVar27 + 0x11110);
  uVar39 = *(undefined4 *)(lVar27 + 0x11050);
  *(undefined4 *)(lVar29 + 0x2e30) = uVar39;
  iVar13 = *piVar36 * 100 + -100;
  iVar31 = *piVar36 * 100 + -200;
  *(int *)(lVar27 + 0x1107c) = iVar31;
  *(int *)(lVar27 + 0x11080) = iVar13;
  *(int *)(lVar27 + 0x11084) = iVar13;
  *(int *)(lVar27 + 0x1108c) = iVar13;
  *(undefined4 *)(lVar29 + 0x2e50) = 0;
  *(undefined4 *)(lVar29 + 0x2e58) = *(undefined4 *)(lVar27 + 0x1106c);
  *(undefined4 *)(lVar29 + 0x2e60) = *(undefined4 *)(lVar27 + 0x11070);
  *(undefined4 *)(lVar29 + 0x2e78) = *(undefined4 *)(lVar27 + 0x11058);
  *(undefined4 *)(lVar29 + 0x2e68) = *(undefined4 *)(lVar27 + 0x1105c);
  uVar40 = NEON_ucvtf(*(undefined8 *)(lVar27 + 0x11074),4);
  *(undefined8 *)(lVar29 + 0x2e70) = uVar40;
  *(int *)(lVar29 + 0x2e84) = iVar31;
  *(int *)(lVar29 + 0x2e88) = iVar13;
  *(int *)(lVar29 + 0x2e8c) = iVar13;
  *(undefined4 *)(lVar29 + 0x2e4c) = *(undefined4 *)(lVar27 + 0x11098);
  *(undefined4 *)(lVar29 + 0x2ec4) = 0;
  uVar38 = NEON_ucvtf(*(undefined4 *)(lVar27 + 0x11088));
  *(undefined4 *)(lVar29 + 0x2e94) = uVar38;
  *(int *)(lVar29 + 0x2e98) = iVar13;
  uVar38 = *(undefined4 *)(lVar27 + 0x11090);
  *(undefined4 *)(lVar29 + 0x2ea0) = uVar38;
  *(int *)(lVar29 + 0x2ecc) = iVar13;
  *(undefined4 *)(lVar29 + 0x2ec8) = 0;
  *(undefined4 *)(lVar29 + 0x2ed0) = 0;
  iVar12 = *(int *)(lVar27 + 0x11060);
  *(int *)(lVar27 + 0x11068) = iVar12 * *(int *)(lVar27 + 0x11094) * 24000;
  *(undefined4 *)(lVar29 + 0x2e58) = *(undefined4 *)(lVar27 + 0x1106c);
  *(undefined4 *)(lVar29 + 0x2e60) = *(undefined4 *)(lVar27 + 0x11070);
  *(undefined4 *)(lVar22 + 0x620) = uVar39;
  *(int *)(lVar22 + 0x630) = iVar13;
  *(undefined4 *)(lVar22 + 0x624) = *(undefined4 *)(lVar27 + 0x11058);
  *(undefined4 *)(lVar22 + 0x628) = *(undefined4 *)(lVar27 + 0x1105c);
  *(int *)(lVar22 + 0x62c) = iVar12;
  *(undefined4 *)(lVar22 + 0x634) = uVar38;
  *(int *)(lVar22 + 0x640) = iVar31;
  FUN_fffffff00817eee4(lVar27,lVar29 + 0x2ee4,iVar31 / 100);
  lVar22 = param_1[0x58];
  *(long *)(lVar22 + 0x2f28) = param_1[0x322];
  *(int *)(lVar22 + 0x2f30) = (int)param_1[0x323];
  *(undefined4 *)(lVar22 + 0x2f34) = 1;
  uVar40 = *(undefined8 *)((long)param_1 + 0x191c);
  uVar10 = *(undefined8 *)((long)param_1 + 0x1924);
  uVar47 = *(undefined8 *)((long)param_1 + 0x1934);
  uVar44 = *(undefined8 *)((long)param_1 + 0x192c);
  uVar33 = *(undefined8 *)((long)param_1 + 0x1944);
  uVar23 = *(undefined8 *)((long)param_1 + 0x193c);
  uVar43 = *(undefined8 *)((long)param_1 + 0x1954);
  uVar42 = *(undefined8 *)((long)param_1 + 0x194c);
  uVar46 = *(undefined8 *)((long)param_1 + 0x1964);
  uVar45 = *(undefined8 *)((long)param_1 + 0x195c);
  uVar51 = *(undefined8 *)((long)param_1 + 0x1974);
  uVar50 = *(undefined8 *)((long)param_1 + 0x196c);
  uVar53 = *(undefined8 *)((long)param_1 + 0x1984);
  uVar52 = *(undefined8 *)((long)param_1 + 0x197c);
  uVar55 = *(undefined8 *)((long)param_1 + 0x1994);
  uVar54 = *(undefined8 *)((long)param_1 + 0x198c);
  uVar57 = *(undefined8 *)((long)param_1 + 0x19a4);
  uVar56 = *(undefined8 *)((long)param_1 + 0x199c);
  uVar59 = *(undefined8 *)((long)param_1 + 0x19b4);
  uVar58 = *(undefined8 *)((long)param_1 + 0x19ac);
  uVar61 = *(undefined8 *)((long)param_1 + 0x19c4);
  uVar60 = *(undefined8 *)((long)param_1 + 0x19bc);
  uVar63 = *(undefined8 *)((long)param_1 + 0x19d4);
  uVar62 = *(undefined8 *)((long)param_1 + 0x19cc);
  uVar65 = *(undefined8 *)((long)param_1 + 0x19e4);
  uVar64 = *(undefined8 *)((long)param_1 + 0x19dc);
  uVar67 = *(undefined8 *)((long)param_1 + 0x19f4);
  uVar66 = *(undefined8 *)((long)param_1 + 0x19ec);
  uVar68 = *(undefined8 *)((long)param_1 + 0x19fc);
  uVar70 = *(undefined8 *)((long)param_1 + 0x1a14);
  uVar69 = *(undefined8 *)((long)param_1 + 0x1a0c);
  *(undefined8 *)(lVar22 + 0x3020) = *(undefined8 *)((long)param_1 + 0x1a04);
  *(undefined8 *)(lVar22 + 0x3018) = uVar68;
  *(undefined8 *)(lVar22 + 0x3030) = uVar70;
  *(undefined8 *)(lVar22 + 0x3028) = uVar69;
  *(undefined8 *)(lVar22 + 0x3000) = uVar65;
  *(undefined8 *)(lVar22 + 0x2ff8) = uVar64;
  *(undefined8 *)(lVar22 + 0x3010) = uVar67;
  *(undefined8 *)(lVar22 + 0x3008) = uVar66;
  *(undefined8 *)(lVar22 + 0x2fe0) = uVar61;
  *(undefined8 *)(lVar22 + 0x2fd8) = uVar60;
  *(undefined8 *)(lVar22 + 0x2ff0) = uVar63;
  *(undefined8 *)(lVar22 + 0x2fe8) = uVar62;
  *(undefined8 *)(lVar22 + 0x2fc0) = uVar57;
  *(undefined8 *)(lVar22 + 0x2fb8) = uVar56;
  *(undefined8 *)(lVar22 + 0x2fd0) = uVar59;
  *(undefined8 *)(lVar22 + 0x2fc8) = uVar58;
  *(undefined8 *)(lVar22 + 0x2fa0) = uVar53;
  *(undefined8 *)(lVar22 + 0x2f98) = uVar52;
  *(undefined8 *)(lVar22 + 0x2fb0) = uVar55;
  *(undefined8 *)(lVar22 + 0x2fa8) = uVar54;
  *(undefined8 *)(lVar22 + 0x2f80) = uVar46;
  *(undefined8 *)(lVar22 + 0x2f78) = uVar45;
  *(undefined8 *)(lVar22 + 0x2f90) = uVar51;
  *(undefined8 *)(lVar22 + 0x2f88) = uVar50;
  *(undefined8 *)(lVar22 + 0x2f60) = uVar33;
  *(undefined8 *)(lVar22 + 0x2f58) = uVar23;
  *(undefined8 *)(lVar22 + 0x2f70) = uVar43;
  *(undefined8 *)(lVar22 + 0x2f68) = uVar42;
  *(undefined8 *)(lVar22 + 0x2f40) = uVar10;
  *(undefined8 *)(lVar22 + 0x2f38) = uVar40;
  *(undefined8 *)(lVar22 + 0x2f50) = uVar47;
  *(undefined8 *)(lVar22 + 0x2f48) = uVar44;
  uVar40 = *(undefined8 *)((long)param_1 + 0x1a1c);
  uVar10 = *(undefined8 *)((long)param_1 + 0x1a24);
  uVar47 = *(undefined8 *)((long)param_1 + 0x1a34);
  uVar44 = *(undefined8 *)((long)param_1 + 0x1a2c);
  uVar33 = *(undefined8 *)((long)param_1 + 0x1a44);
  uVar23 = *(undefined8 *)((long)param_1 + 0x1a3c);
  uVar43 = *(undefined8 *)((long)param_1 + 0x1a54);
  uVar42 = *(undefined8 *)((long)param_1 + 0x1a4c);
  uVar46 = *(undefined8 *)((long)param_1 + 0x1a64);
  uVar45 = *(undefined8 *)((long)param_1 + 0x1a5c);
  uVar51 = *(undefined8 *)((long)param_1 + 0x1a74);
  uVar50 = *(undefined8 *)((long)param_1 + 0x1a6c);
  uVar53 = *(undefined8 *)((long)param_1 + 0x1a84);
  uVar52 = *(undefined8 *)((long)param_1 + 0x1a7c);
  uVar55 = *(undefined8 *)((long)param_1 + 0x1a94);
  uVar54 = *(undefined8 *)((long)param_1 + 0x1a8c);
  uVar57 = *(undefined8 *)((long)param_1 + 0x1aa4);
  uVar56 = *(undefined8 *)((long)param_1 + 0x1a9c);
  uVar59 = *(undefined8 *)((long)param_1 + 0x1ab4);
  uVar58 = *(undefined8 *)((long)param_1 + 0x1aac);
  uVar61 = *(undefined8 *)((long)param_1 + 0x1ac4);
  uVar60 = *(undefined8 *)((long)param_1 + 0x1abc);
  uVar63 = *(undefined8 *)((long)param_1 + 0x1ad4);
  uVar62 = *(undefined8 *)((long)param_1 + 0x1acc);
  uVar65 = *(undefined8 *)((long)param_1 + 0x1ae4);
  uVar64 = *(undefined8 *)((long)param_1 + 0x1adc);
  uVar67 = *(undefined8 *)((long)param_1 + 0x1af4);
  uVar66 = *(undefined8 *)((long)param_1 + 0x1aec);
  uVar68 = *(undefined8 *)((long)param_1 + 0x1afc);
  uVar70 = *(undefined8 *)((long)param_1 + 0x1b14);
  uVar69 = *(undefined8 *)((long)param_1 + 0x1b0c);
  *(undefined8 *)(lVar22 + 0x3120) = *(undefined8 *)((long)param_1 + 0x1b04);
  *(undefined8 *)(lVar22 + 0x3118) = uVar68;
  *(undefined8 *)(lVar22 + 0x3130) = uVar70;
  *(undefined8 *)(lVar22 + 0x3128) = uVar69;
  *(undefined8 *)(lVar22 + 0x3100) = uVar65;
  *(undefined8 *)(lVar22 + 0x30f8) = uVar64;
  *(undefined8 *)(lVar22 + 0x3110) = uVar67;
  *(undefined8 *)(lVar22 + 0x3108) = uVar66;
  *(undefined8 *)(lVar22 + 0x30e0) = uVar61;
  *(undefined8 *)(lVar22 + 0x30d8) = uVar60;
  *(undefined8 *)(lVar22 + 0x30f0) = uVar63;
  *(undefined8 *)(lVar22 + 0x30e8) = uVar62;
  *(undefined8 *)(lVar22 + 0x30c0) = uVar57;
  *(undefined8 *)(lVar22 + 0x30b8) = uVar56;
  *(undefined8 *)(lVar22 + 0x30d0) = uVar59;
  *(undefined8 *)(lVar22 + 0x30c8) = uVar58;
  *(undefined8 *)(lVar22 + 0x30a0) = uVar53;
  *(undefined8 *)(lVar22 + 0x3098) = uVar52;
  *(undefined8 *)(lVar22 + 0x30b0) = uVar55;
  *(undefined8 *)(lVar22 + 0x30a8) = uVar54;
  *(undefined8 *)(lVar22 + 0x3080) = uVar46;
  *(undefined8 *)(lVar22 + 0x3078) = uVar45;
  *(undefined8 *)(lVar22 + 0x3090) = uVar51;
  *(undefined8 *)(lVar22 + 0x3088) = uVar50;
  *(undefined8 *)(lVar22 + 0x3060) = uVar33;
  *(undefined8 *)(lVar22 + 0x3058) = uVar23;
  *(undefined8 *)(lVar22 + 0x3070) = uVar43;
  *(undefined8 *)(lVar22 + 0x3068) = uVar42;
  *(undefined8 *)(lVar22 + 0x3040) = uVar10;
  *(undefined8 *)(lVar22 + 0x3038) = uVar40;
  *(undefined8 *)(lVar22 + 0x3050) = uVar47;
  *(undefined8 *)(lVar22 + 0x3048) = uVar44;
  lVar27 = param_1[0x58];
  *(undefined8 *)(lVar27 + 0x2cf0) = 0;
  *(undefined8 *)(lVar27 + 0x2ce8) = 0;
  *(undefined8 *)(lVar27 + 0x2d00) = 0;
  *(undefined8 *)(lVar27 + 0x2cf8) = 0;
  *(undefined8 *)(lVar27 + 0x2cd0) = 0;
  *(undefined8 *)(lVar27 + 0x2cc8) = 0;
  *(undefined8 *)(lVar27 + 0x2ce0) = 0;
  *(undefined8 *)(lVar27 + 0x2cd8) = 0;
  *(undefined8 *)(param_1[0x58] + 0x2d08) = 0;
  lVar29 = param_1[0x58];
  *(undefined4 *)(lVar29 + 0x2d30) = 0;
  *(undefined4 *)(lVar27 + 0x2c3c) = 0;
  *(undefined4 *)(lVar27 + 0x2c44) = 0;
  *(undefined8 *)(lVar27 + 0x2c30) = 0;
  *(undefined4 *)(lVar27 + 0x2c4c) = 0;
  *(undefined4 *)(lVar27 + 0x2c54) = 0;
  *(undefined8 *)(lVar27 + 0x2c58) = DAT_fffffff007113f98;
  *(undefined4 *)(lVar27 + 0x2c64) = 0;
  lVar22 = param_1[0x50];
  *(undefined4 *)(lVar27 + 0x2c68) = *(undefined4 *)(lVar22 + 0x10aa8);
  *(int *)(lVar27 + 0x2c6c) = (int)param_1[0x16e] * 100;
  *(undefined8 *)(lVar27 + 0x2c70) = 0;
  *(undefined4 *)(lVar27 + 0x2ca8) = 0;
  *(undefined8 *)(lVar27 + 0x2c78) = 0;
  *(undefined4 *)(lVar27 + 0x2cb0) = 0;
  *(undefined4 *)(lVar27 + 0x2c84) = 0;
  *(undefined8 *)(lVar29 + 0x2b50) = 0;
  *(undefined8 *)(lVar29 + 0x2b48) = 0;
  *(undefined4 *)(lVar29 + 0x2c14) = *(undefined4 *)(lVar22 + 0x10e44);
  iVar12 = *(int *)(lVar22 + 0x10ddc);
  uVar21 = iVar12 * 1000;
  *(uint *)(lVar29 + 0x2c10) = uVar21;
  *(undefined4 *)(lVar29 + 0x2c18) = *(undefined4 *)(lVar22 + 0x10e30);
  *(undefined8 *)(lVar29 + 0x2b68) = 0;
  *(undefined4 *)(lVar29 + 0x2b70) = 0;
  uVar40 = *(undefined8 *)(lVar22 + 0x10e34);
  *(undefined8 *)(lVar29 + 0x2c24) = *(undefined8 *)(lVar22 + 0x10e3c);
  *(undefined8 *)(lVar29 + 0x2c1c) = uVar40;
  *(undefined4 *)(lVar29 + 0x2b78) = *(undefined4 *)(lVar22 + 0x10df0);
  *(undefined4 *)(lVar29 + 0x2b80) = *(undefined4 *)(lVar22 + 0x10dfc);
  *(undefined4 *)(lVar29 + 0x2b88) = *(undefined4 *)(lVar22 + 0x10e04);
  *(undefined4 *)(lVar29 + 0x2ba0) = *(undefined4 *)(lVar22 + 0x10e0c);
  *(undefined4 *)(lVar29 + 0x2b90) = *(undefined4 *)(lVar22 + 0x10e14);
  *(int *)(lVar29 + 0x2bcc) = iVar12 * *(int *)(lVar22 + 0x10df4);
  iVar12 = *(int *)(lVar22 + 0x10ddc);
  *(ulong *)(lVar29 + 0x2bd4) = (ulong)(uint)(*(int *)(lVar22 + 0x10df4) * iVar12 * 24000);
  *(undefined4 *)(lVar29 + 0x2b84) = *(undefined4 *)(lVar22 + 0x10e00);
  *(undefined4 *)(lVar29 + 0x2b8c) = *(undefined4 *)(lVar22 + 0x10e08);
  *(undefined4 *)(lVar29 + 0x2ba4) = *(undefined4 *)(lVar22 + 0x10e10);
  *(undefined4 *)(lVar29 + 0x2b94) = *(undefined4 *)(lVar22 + 0x10e18);
  *(int *)(lVar29 + 0x2bd0) = iVar12 * *(int *)(lVar22 + 0x10df8);
  *(ulong *)(lVar29 + 0x2bdc) =
       (ulong)(uint)(*(int *)(lVar22 + 0x10df8) * *(int *)(lVar22 + 0x10ddc) * 24000);
  *(undefined4 *)(lVar29 + 0x2b74) = 0x32;
  uVar39 = NEON_ucvtf(*(undefined4 *)(lVar22 + 0x10e20));
  uVar40 = NEON_ucvtf(*(undefined8 *)(lVar22 + 0x10e1c),4);
  *(undefined8 *)(lVar29 + 0x2b98) = uVar40;
  *(undefined8 *)(lVar29 + 0x2bac) = *(undefined8 *)(lVar22 + 0x10e28);
  *(undefined4 *)(lVar29 + 0x2bb4) = *(undefined4 *)(lVar22 + 0x10e24);
  *(undefined4 *)(lVar29 + 0x2bb8) = *(undefined4 *)(lVar22 + 0x10dec);
  *(undefined4 *)(lVar29 + 0x2bec) = 0;
  *(float *)(lVar29 + 0x2bbc) = (float)uVar21;
  *(undefined4 *)(lVar29 + 0x2bc4) = 0;
  *(undefined4 *)(lVar29 + 0x2bc0) = *(undefined4 *)(lVar22 + 0x10de8);
  *(undefined4 *)(lVar29 + 0x2be8) = uVar39;
  uVar39 = *(undefined4 *)(lVar22 + 0x10de4);
  *(undefined4 *)(lVar29 + 0x2bc8) = uVar39;
  lVar27 = param_1[0x123];
  *(undefined4 *)(lVar27 + 0x14c) = *(undefined4 *)(lVar22 + 0x10eac);
  *(undefined4 *)(lVar27 + 0x158) = uVar39;
  uVar40 = *(undefined8 *)*(undefined1 (*) [16])(param_1 + 0x30b);
  lVar22 = param_1[0x30c];
  lVar28 = param_1[0x30e];
  lVar27 = param_1[0x30d];
  lVar26 = param_1[0x30f];
  lVar30 = param_1[0x312];
  lVar32 = param_1[0x311];
  *(long *)(lVar29 + 0x62e0) = param_1[0x310];
  *(long *)(lVar29 + 0x62d8) = lVar26;
  *(long *)(lVar29 + 0x62f0) = lVar30;
  *(long *)(lVar29 + 0x62e8) = lVar32;
  *(long *)(lVar29 + 0x62c0) = lVar22;
  *(undefined8 *)(lVar29 + 0x62b8) = uVar40;
  *(long *)(lVar29 + 0x62d0) = lVar28;
  *(long *)(lVar29 + 0x62c8) = lVar27;
  *(long *)(lVar29 + 0x62b0) = param_1[0x313];
  *(int *)(lVar29 + 0x62f8) = (int)param_1[0x314];
  uVar39 = *(undefined4 *)((long)param_1 + 0x18a4);
  *(undefined4 *)(lVar29 + 0x62a8) = 0;
  *(undefined4 *)(lVar29 + 0x62ac) = uVar39;
  lVar22 = param_1[0x123];
  auVar41 = *(undefined1 (*) [16])(param_1 + 0x30b);
  lVar27 = param_1[0x30e];
  lVar29 = param_1[0x30d];
  lVar28 = param_1[0x30f];
  lVar32 = param_1[0x312];
  lVar26 = param_1[0x311];
  *(long *)(lVar22 + 0x524) = param_1[0x310];
  *(long *)(lVar22 + 0x51c) = lVar28;
  *(long *)(lVar22 + 0x534) = lVar32;
  *(long *)(lVar22 + 0x52c) = lVar26;
  *(long *)(lVar22 + 0x504) = auVar41._8_8_;
  *(long *)(lVar22 + 0x4fc) = auVar41._0_8_;
  *(long *)(lVar22 + 0x514) = lVar27;
  *(long *)(lVar22 + 0x50c) = lVar29;
  lVar22 = param_1[0x123];
  *(int *)(lVar22 + 0x4f4) = (int)param_1[0x313];
  *(undefined4 *)(lVar22 + 0x4f8) = *(undefined4 *)((long)param_1 + 0x189c);
  *(int *)(lVar22 + 0x53c) = (int)param_1[0x314];
  *(undefined4 *)(lVar22 + 0x4f0) = *(undefined4 *)((long)param_1 + 0x18a4);
  *(undefined4 *)(lVar22 + 0x4ec) = 0;
  thunk_EXT_FUN_8011000003a61cc0(param_1[0x58] + 0x3138,0x2a90);
  lVar22 = param_1[0x58];
  plVar34 = (long *)param_1[0x50];
  *(long *)(lVar22 + 0x3ba0) = plVar34[0x20bf];
  *(int *)(lVar22 + 0x3ba8) = (int)plVar34[0x20c0];
  *(long *)(lVar22 + 0x5bac) = plVar34[0x2121];
  uVar24 = (**(code **)(*plVar34 + 0x7f0))(*plVar34 + 0x7f0,plVar34);
  if ((uVar24 & 1) == 0) {
    uVar24 = *(ulong *)(lVar22 + 0x3ba0);
    if (uVar24 != 0) {
      uVar24 = (uVar24 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar24 & 0x5555555555555555) << 1;
      uVar24 = (uVar24 & 0xcccccccccccccccc) >> 2 | (uVar24 & 0x3333333333333333) << 2;
      uVar24 = (uVar24 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar24 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar24 = (uVar24 & 0xff00ff00ff00ff00) >> 8 | (uVar24 & 0xff00ff00ff00ff) << 8;
      uVar24 = (uVar24 & 0xffff0000ffff0000) >> 0x10 | (uVar24 & 0xffff0000ffff) << 0x10;
      uVar14 = LZCOUNT(uVar24 >> 0x20 | uVar24 << 0x20);
      uVar24 = uVar14;
      do {
        iVar12 = (int)(uVar24 * 8);
        puVar9 = (undefined8 *)((long)plVar34 + (long)iVar12 + 0x10608);
        if (uVar24 * 8 - (long)iVar12 != 0) {
          puVar9 = (undefined8 *)
                   ((ulong)(plVar34 + uVar24 + 0x20c1) & 0xffffffffffff | 0x2bad000000000000);
        }
        puVar18 = (uint *)*puVar9;
        uVar21 = *puVar18;
        lVar29 = uVar24 * 0x78;
        puVar7 = (uint *)(lVar22 + 0x3bac + (long)(int)lVar29);
        if (lVar29 != (int)lVar29) {
          puVar7 = (uint *)(lVar22 + 0x3bac + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar7 = uVar21;
        thunk_EXT_FUN_8011000003a61b10(puVar7 + 1,puVar18 + 1,(ulong)uVar21 << 2);
        lVar29 = uVar24 * 4;
        puVar18 = (uint *)((long)plVar34 + (long)(int)lVar29 + 0x10808);
        if (lVar29 - (int)lVar29 != 0) {
          puVar18 = (uint *)((long)plVar34 + lVar29 + 0x10808 & 0xffffffffffffU | 0x2bad000000000000
                            );
        }
        puVar7[0x16] = *puVar18;
        uVar21 = (uint)uVar14 & 0x3f;
        uVar17 = 0;
        if (uVar21 != 0x3f) {
          uVar17 = -1L << ((ulong)(uVar21 + 1) & 0x3f);
        }
        uVar17 = *(ulong *)(lVar22 + 0x3ba0 + (uVar24 >> 3 & 0x1ffffffffffffff8)) & uVar17;
        uVar24 = (uVar17 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar17 & 0x5555555555555555) << 1;
        uVar24 = (uVar24 & 0xcccccccccccccccc) >> 2 | (uVar24 & 0x3333333333333333) << 2;
        uVar24 = (uVar24 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar24 & 0xf0f0f0f0f0f0f0f) << 4;
        uVar24 = (uVar24 & 0xff00ff00ff00ff00) >> 8 | (uVar24 & 0xff00ff00ff00ff) << 8;
        uVar24 = (uVar24 & 0xffff0000ffff0000) >> 0x10 | (uVar24 & 0xffff0000ffff) << 0x10;
        uVar21 = (uint)LZCOUNT(uVar24 >> 0x20 | uVar24 << 0x20);
        if (uVar17 == 0) {
          uVar21 = 0xffffffff;
        }
        uVar20 = uVar21 + ((uint)uVar14 & 0xffffffc0);
        uVar14 = (ulong)uVar20;
        if (0x7fffffff < uVar21) {
          uVar20 = 0xffffffff;
        }
        uVar24 = (ulong)uVar20;
      } while (uVar20 != 0xffffffff);
    }
  }
  *(long *)(param_1[0x58] + 0x3b98) = param_1[0x6e];
  lVar22 = param_1[0x58];
  *(undefined4 *)(lVar22 + 0xb30) = 0;
  lVar29 = param_1[0x50];
  *(undefined4 *)(lVar22 + 0xa84) = 0;
  *(undefined4 *)(lVar22 + 0xa8c) = *(undefined4 *)(lVar29 + 0x10d4c);
  *(undefined4 *)(lVar22 + 0xa94) = *(undefined4 *)(lVar29 + 0x10d50);
  *(undefined4 *)(lVar22 + 0xa80) = *(undefined4 *)(lVar29 + 0x10d48);
  fVar37 = *(float *)(lVar29 + 0x10d80);
  if (*(float *)(lVar29 + 0x10d80) == 0.0) {
    fVar37 = *(float *)(lVar29 + 0x10d68);
  }
  *(float *)(lVar22 + 0xaac) = fVar37;
  fVar37 = *(float *)(lVar29 + 0x10d84);
  if (*(float *)(lVar29 + 0x10d84) == 0.0) {
    fVar37 = *(float *)(lVar29 + 0x10d5c);
  }
  *(float *)(lVar22 + 0xa9c) = fVar37;
  uVar40 = NEON_scvtf(*(undefined8 *)(lVar29 + 0x10d60),4);
  *(undefined8 *)(lVar22 + 0xaa4) = uVar40;
  *(undefined4 *)(lVar22 + 0xab4) = *(undefined4 *)(lVar29 + 0x10d6c);
  *(undefined8 *)(lVar22 + 0xab8) = *(undefined8 *)(lVar29 + 0x10d70);
  *(undefined4 *)(lVar22 + 0xac0) = *(undefined4 *)(lVar29 + 0x10d78);
  *(undefined4 *)(lVar22 + 0xaf8) = 0;
  *(undefined4 *)(lVar22 + 0xac8) = 0;
  iVar12 = *(int *)(lVar29 + 0x10d54);
  if (*(int *)(lVar29 + 0x10d7c) != 0) {
    iVar12 = *(int *)(lVar29 + 0x10d7c);
  }
  uVar21 = 0;
  if (*(uint *)(lVar29 + 0x10d30) != 0) {
    uVar21 = (uint)(iVar12 * 100) / *(uint *)(lVar29 + 0x10d30);
  }
  if (99 < uVar21) {
    uVar21 = 100;
  }
  thunk_EXT_FUN_80110000039b78d4
            (*(undefined8 *)(*(long *)(lVar29 + 0x1ac50) + 0x130),0,
             (ulong)uVar21 * 0x1999999a >> 0x20);
  *(int *)(lVar22 + 0xacc) = iVar12;
  *(undefined4 *)(lVar22 + 0xb00) = *(undefined4 *)(lVar29 + 0x10d78);
  *(undefined4 *)(lVar22 + 0xad8) = *(undefined4 *)(lVar29 + 0x10d3c);
  *(undefined8 *)(lVar22 + 0xae0) = *(undefined8 *)(lVar29 + 0x10d40);
  *(undefined4 *)(lVar22 + 0xad4) = 0;
  *(undefined4 *)(lVar22 + 0xafc) = *(undefined4 *)(lVar29 + 69000);
  *(undefined4 *)(lVar22 + 0xb04) = *(undefined4 *)(lVar29 + 0x10d8c);
  lVar27 = param_1[0x123];
  *(int *)(lVar27 + 300) = iVar12;
  *(undefined4 *)(lVar27 + 0x130) = *(undefined4 *)(lVar22 + 0xaac);
  *(undefined4 *)(lVar27 + 0x134) = *(undefined4 *)(lVar22 + 0xa9c);
  *(undefined4 *)(lVar27 + 0x13c) = *(undefined4 *)(lVar29 + 0x10b24);
  *(undefined4 *)(lVar27 + 0x140) = *(undefined4 *)(lVar29 + 0x10b28);
  *(undefined4 *)(lVar27 + 0x144) = 0;
  uVar39 = *(undefined4 *)((long)param_1 + 0xbac);
  thunk_EXT_FUN_80110000032222a8(param_1[0x178]);
  *(undefined4 *)((long)param_1 + 0xbac) = uVar39;
  if ((*(byte *)((long)param_1 + 0xba4) & 1) == 0) {
    uVar39 = (undefined4)param_1[0x175];
  }
  (**(code **)(*param_1 + 0x9e0))(param_1,uVar39,0);
  thunk_EXT_FUN_8011000003222de0(param_1[0x178]);
  lVar22 = param_1[0x58];
  uVar39 = *(undefined4 *)((long)param_1 + 0x18f4);
  uVar40 = NEON_ucvtf(param_1[0x31e],4);
  *(undefined8 *)(lVar22 + 0x2200) = uVar40;
  uVar38 = NEON_ucvtf((int)param_1[799]);
  *(undefined4 *)(lVar22 + 0x2208) = uVar38;
  *(undefined4 *)(lVar22 + 0x220c) = *(undefined4 *)((long)param_1 + 0x18fc);
  iVar12 = (int)param_1[800];
  if (iVar12 == 0) {
    iVar12 = *(int *)((long)param_1 + 0x18ec);
  }
  *(int *)(lVar22 + 0x2218) = iVar12;
  *(undefined4 *)(lVar22 + 0x2220) = uVar39;
  *(undefined4 *)(lVar22 + 0x2224) = *(undefined4 *)((long)param_1 + 0x1904);
  uVar39 = (undefined4)param_1[0x177];
  thunk_EXT_FUN_80110000032222a8(param_1[0x178]);
  *(undefined4 *)(param_1 + 0x177) = uVar39;
  if ((*(byte *)(param_1 + 0x176) & 1) == 0) {
    uVar39 = *(undefined4 *)((long)param_1 + 0xbb4);
  }
  (**(code **)(*param_1 + 0x9e8))(param_1,uVar39);
  thunk_EXT_FUN_8011000003222de0(param_1[0x178]);
  lVar28 = param_1[0x58];
  (**(code **)(*(long *)param_1[0x50] + 0xa18))((long *)param_1[0x50],lVar28 + 0x5bc8);
  lVar22 = 0;
  lVar27 = param_1[0x69];
  *(undefined4 *)(lVar27 + 0xec) = *(undefined4 *)(lVar28 + 0x5bcc);
  *(undefined4 *)(lVar27 + 0xf0) = *(undefined4 *)(lVar28 + 0x5bd0);
  *(undefined4 *)(lVar27 + 0xf4) = *(undefined4 *)(lVar28 + 0x5bd4);
  *(undefined4 *)(lVar27 + 0xf8) = *(undefined4 *)(lVar28 + 0x5bd8);
  *(undefined4 *)(lVar27 + 0xfc) = *(undefined4 *)(lVar28 + 0x5bdc);
  *(undefined4 *)(lVar27 + 0x100) = *(undefined4 *)(lVar28 + 0x5be0);
  *(undefined4 *)(lVar27 + 0x104) = *(undefined4 *)(lVar28 + 0x5be4);
  *(undefined4 *)(lVar27 + 0x108) = *(undefined4 *)(lVar28 + 0x5be8);
  *(undefined4 *)(lVar27 + 0x10c) = *(undefined4 *)(lVar28 + 0x5bec);
  *(undefined4 *)(lVar27 + 0x110) = *(undefined4 *)(lVar28 + 0x5bf0);
  *(undefined4 *)(lVar27 + 0x114) = *(undefined4 *)(lVar28 + 0x5bf4);
  *(undefined4 *)(lVar27 + 0x118) = *(undefined4 *)(lVar28 + 0x5bf8);
  *(undefined4 *)(lVar27 + 0x11c) = *(undefined4 *)(lVar28 + 0x5bfc);
  *(undefined4 *)(lVar27 + 0x120) = *(undefined4 *)(lVar28 + 0x5c00);
  *(undefined4 *)(lVar27 + 0x124) = *(undefined4 *)(lVar28 + 0x5c04);
  *(undefined4 *)(lVar27 + 0x128) = *(undefined4 *)(lVar28 + 0x5c08);
  *(undefined8 *)(lVar27 + 300) = *(undefined8 *)(lVar28 + 0x5c0c);
  *(undefined8 *)(lVar27 + 0x14c) = *(undefined8 *)(lVar28 + 0x5c2c);
  *(undefined8 *)(lVar27 + 0x134) = *(undefined8 *)(lVar28 + 0x5c14);
  *(undefined8 *)(lVar27 + 0x154) = *(undefined8 *)(lVar28 + 0x5c34);
  *(undefined8 *)(lVar27 + 0x13c) = *(undefined8 *)(lVar28 + 0x5c1c);
  *(undefined8 *)(lVar27 + 0x15c) = *(undefined8 *)(lVar28 + 0x5c3c);
  *(undefined8 *)(lVar27 + 0x144) = *(undefined8 *)(lVar28 + 0x5c24);
  *(undefined8 *)(lVar27 + 0x164) = *(undefined8 *)(lVar28 + 0x5c44);
  *(undefined8 *)(lVar27 + 0x16c) = *(undefined8 *)(lVar28 + 0x5c4c);
  *(undefined8 *)(lVar27 + 0x174) = *(undefined8 *)(lVar28 + 0x5c54);
  *(undefined8 *)(lVar27 + 0x17c) = *(undefined8 *)(lVar28 + 0x5c5c);
  *(undefined8 *)(lVar27 + 0x184) = *(undefined8 *)(lVar28 + 0x5c64);
  *(undefined8 *)(lVar27 + 0x18c) = *(undefined8 *)(lVar28 + 0x5c6c);
  *(undefined8 *)(lVar27 + 0x1b4) = *(undefined8 *)(lVar28 + 0x5c94);
  *(undefined8 *)(lVar27 + 0x1bc) = *(undefined8 *)(lVar28 + 0x5c9c);
  *(undefined8 *)(lVar27 + 0x1c4) = *(undefined8 *)(lVar28 + 0x5ca4);
  *(undefined8 *)(lVar27 + 0x1cc) = *(undefined8 *)(lVar28 + 0x5cac);
  *(undefined8 *)(lVar27 + 0x1d4) = *(undefined8 *)(lVar28 + 0x5cb4);
  *(undefined8 *)(lVar27 + 0x1dc) = *(undefined8 *)(lVar28 + 0x5cbc);
  *(undefined8 *)(lVar27 + 0x1e4) = *(undefined8 *)(lVar28 + 0x5cc4);
  *(undefined8 *)(lVar27 + 0x1ec) = *(undefined8 *)(lVar28 + 0x5ccc);
  *(undefined8 *)(lVar27 + 500) = *(undefined8 *)(lVar28 + 0x5cd4);
  *(undefined8 *)(lVar27 + 0x1fc) = *(undefined8 *)(lVar28 + 0x5cdc);
  *(undefined8 *)(lVar27 + 0x204) = *(undefined8 *)(lVar28 + 0x5ce4);
  *(undefined8 *)(lVar27 + 0x20c) = *(undefined8 *)(lVar28 + 0x5cec);
  *(undefined8 *)(lVar27 + 0x214) = *(undefined8 *)(lVar28 + 0x5cf4);
  *(undefined8 *)(lVar27 + 0x21c) = *(undefined8 *)(lVar28 + 0x5cfc);
  *(undefined8 *)(lVar27 + 0x224) = *(undefined8 *)(lVar28 + 0x5d04);
  *(undefined8 *)(lVar27 + 0x46c) = *(undefined8 *)(lVar28 + 0x5f4c);
  *(undefined8 *)(lVar27 + 0x22c) = *(undefined8 *)(lVar28 + 0x5d0c);
  *(undefined8 *)(lVar27 + 0x24c) = *(undefined8 *)(lVar28 + 0x5d2c);
  *(undefined8 *)(lVar27 + 0x474) = *(undefined8 *)(lVar28 + 0x5f54);
  *(undefined8 *)(lVar27 + 0x494) = *(undefined8 *)(lVar28 + 0x5f74);
  *(undefined8 *)(lVar27 + 0x234) = *(undefined8 *)(lVar28 + 0x5d14);
  *(undefined8 *)(lVar27 + 0x254) = *(undefined8 *)(lVar28 + 0x5d34);
  *(undefined8 *)(lVar27 + 0x47c) = *(undefined8 *)(lVar28 + 0x5f5c);
  *(undefined8 *)(lVar27 + 0x49c) = *(undefined8 *)(lVar28 + 0x5f7c);
  *(undefined8 *)(lVar27 + 0x23c) = *(undefined8 *)(lVar28 + 0x5d1c);
  *(undefined8 *)(lVar27 + 0x25c) = *(undefined8 *)(lVar28 + 0x5d3c);
  *(undefined8 *)(lVar27 + 0x484) = *(undefined8 *)(lVar28 + 0x5f64);
  *(undefined8 *)(lVar27 + 0x4a4) = *(undefined8 *)(lVar28 + 0x5f84);
  *(undefined8 *)(lVar27 + 0x244) = *(undefined8 *)(lVar28 + 0x5d24);
  *(undefined8 *)(lVar27 + 0x264) = *(undefined8 *)(lVar28 + 0x5d44);
  *(undefined8 *)(lVar27 + 0x48c) = *(undefined8 *)(lVar28 + 0x5f6c);
  *(undefined8 *)(lVar27 + 0x4ac) = *(undefined8 *)(lVar28 + 0x5f8c);
  lVar29 = 0x40;
  do {
    *(undefined8 *)(lVar27 + 0x26c + lVar22 * 8) = *(undefined8 *)(lVar28 + 0x5d4c + lVar22 * 8);
    *(undefined8 *)(lVar27 + 0x4b4 + lVar22 * 8) = *(undefined8 *)(lVar28 + 0x5f94 + lVar22 * 8);
    lVar22 = lVar22 + 1;
    lVar29 = lVar29 + -1;
  } while (lVar29 != 0);
  *(undefined8 *)(lVar27 + 0x6b4) = *(undefined8 *)(lVar28 + 0x6194);
  *(undefined8 *)(lVar27 + 0x6bc) = *(undefined8 *)(lVar28 + 0x619c);
  *(undefined8 *)(lVar27 + 0x6c4) = *(undefined8 *)(lVar28 + 0x61a4);
  *(undefined8 *)(lVar27 + 0x6cc) = *(undefined8 *)(lVar28 + 0x61ac);
  *(undefined8 *)(lVar27 + 0x6d4) = *(undefined8 *)(lVar28 + 0x61b4);
  *(undefined8 *)(lVar27 + 0x6dc) = *(undefined8 *)(lVar28 + 0x61bc);
  *(undefined8 *)(lVar27 + 0x6e4) = *(undefined8 *)(lVar28 + 0x61c4);
  *(undefined8 *)(lVar27 + 0x6ec) = *(undefined8 *)(lVar28 + 0x61cc);
  *(undefined8 *)(lVar27 + 0x6f4) = *(undefined8 *)(lVar28 + 0x61d4);
  *(undefined8 *)(lVar27 + 0x6fc) = *(undefined8 *)(lVar28 + 0x61dc);
  *(undefined8 *)(lVar27 + 0x704) = *(undefined8 *)(lVar28 + 0x61e4);
  *(undefined8 *)(lVar27 + 0x70c) = *(undefined8 *)(lVar28 + 0x61ec);
  *(undefined8 *)(lVar27 + 0x714) = *(undefined8 *)(lVar28 + 0x61f4);
  *(undefined8 *)(lVar27 + 0x71c) = *(undefined8 *)(lVar28 + 0x61fc);
  *(undefined8 *)(lVar27 + 0x724) = *(undefined8 *)(lVar28 + 0x6204);
  *(undefined8 *)(lVar27 + 0x72c) = *(undefined8 *)(lVar28 + 0x620c);
  *(undefined8 *)(lVar27 + 0x734) = *(undefined8 *)(lVar28 + 0x6214);
  *(undefined8 *)(lVar27 + 0x73c) = *(undefined8 *)(lVar28 + 0x621c);
  *(undefined8 *)(lVar27 + 0x744) = *(undefined8 *)(lVar28 + 0x6224);
  *(undefined8 *)(lVar27 + 0x74c) = *(undefined8 *)(lVar28 + 0x622c);
  *(undefined8 *)(lVar27 + 0x754) = *(undefined8 *)(lVar28 + 0x6234);
  *(undefined8 *)(lVar27 + 0x75c) = *(undefined8 *)(lVar28 + 0x623c);
  *(undefined8 *)(lVar27 + 0x764) = *(undefined8 *)(lVar28 + 0x6244);
  *(undefined8 *)(lVar27 + 0x76c) = *(undefined8 *)(lVar28 + 0x624c);
  *(undefined8 *)(lVar27 + 0x774) = *(undefined8 *)(lVar28 + 0x6254);
  *(undefined8 *)(lVar27 + 0x77c) = *(undefined8 *)(lVar28 + 0x625c);
  *(undefined8 *)(lVar27 + 0x784) = *(undefined8 *)(lVar28 + 0x6264);
  *(undefined8 *)(lVar27 + 0x78c) = *(undefined8 *)(lVar28 + 0x626c);
  *(undefined8 *)(lVar27 + 0x794) = *(undefined8 *)(lVar28 + 0x6274);
  *(undefined8 *)(lVar27 + 0x79c) = *(undefined8 *)(lVar28 + 0x627c);
  *(undefined8 *)(lVar27 + 0x7a4) = *(undefined8 *)(lVar28 + 0x6284);
  *(undefined8 *)(lVar27 + 0x7ac) = *(undefined8 *)(lVar28 + 0x628c);
  *(undefined8 *)(lVar27 + 0x7b4) = *(undefined8 *)(lVar28 + 0x6294);
  *(undefined8 *)(lVar27 + 0x7bc) = *(undefined8 *)(lVar28 + 0x629c);
  *(undefined8 *)(lVar27 + 0x194) = *(undefined8 *)(lVar28 + 0x5c74);
  *(undefined8 *)(lVar27 + 0x19c) = *(undefined8 *)(lVar28 + 0x5c7c);
  *(undefined8 *)(lVar27 + 0x1a4) = *(undefined8 *)(lVar28 + 0x5c84);
  *(undefined8 *)(lVar27 + 0x1ac) = *(undefined8 *)(lVar28 + 0x5c8c);
  lVar29 = param_1[0x58];
  plVar34 = (long *)param_1[0x50];
  uVar39 = *(undefined4 *)((long)plVar34 + 0x10f64);
  *(undefined4 *)(lVar29 + 0x3c) = 0;
  *(undefined4 *)(lVar29 + 0x40) = uVar39;
  lVar22 = plVar34[0x21df];
  *(undefined4 *)(lVar29 + 0x44) = 1;
  *(int *)(lVar29 + 0x48) = (int)lVar22;
  *(undefined4 *)(lVar29 + 0x7c) = 0;
  *(undefined4 *)(lVar29 + 0x80) = uVar39;
  *(undefined4 *)(lVar29 + 0x84) = 1;
  *(int *)(lVar29 + 0x88) = (int)lVar22;
  *(uint *)(lVar29 + 0x6acc) = (uint)((ulong)plVar34[0xb9] >> 0x21) & 1;
  *(uint *)(param_1[0x122] + 4) = *(uint *)(plVar34 + 0xb9) >> 2 & 1;
  *(int *)(lVar27 + 0x98) = *(int *)((long)param_1 + 0xb74) * 100;
  *(undefined4 *)(lVar27 + 0x7ec) = 1;
  *(uint *)(lVar27 + 0x7f0) = (uint)((ulong)plVar34[0xb9] >> 0x39) & 1;
  lVar22 = 0x1bf4;
  if (*(int *)((long)param_1 + 0x1bfc) != 0) {
    lVar22 = 0x1bf8;
  }
  *(undefined4 *)(lVar27 + 0x9b8) = *(undefined4 *)((long)param_1 + lVar22);
  *(uint *)(lVar27 + 0x34) = *(uint *)(plVar34 + 0xb9) >> 1 & 1;
  *(uint *)(lVar27 + 0x38) = *(byte *)((long)plVar34 + 0x5d1) >> 2 & 1;
  lVar22 = 0x1c00;
  if ((int)param_1[0x381] != 0) {
    lVar22 = 0x1c04;
  }
  *(undefined4 *)(lVar27 + 0x9bc) = *(undefined4 *)((long)param_1 + lVar22);
  lVar22 = 0x1c0c;
  if (*(int *)((long)param_1 + 0x1c14) != 0) {
    lVar22 = 0x1c10;
  }
  *(undefined4 *)(lVar27 + 0x9c0) = *(undefined4 *)((long)param_1 + lVar22);
  *(undefined4 *)(lVar27 + 0x7f4) = *(undefined4 *)((long)plVar34 + 0x10aa4);
  *(int *)(lVar27 + 0x7f8) = (int)plVar34[0x2154];
  (**(code **)(*plVar34 + 0xaf0))(plVar34,lVar27 + 0x9e0);
  lVar22 = param_1[0x69];
  *(undefined4 *)(lVar22 + 0x9c) = 0;
  *(undefined4 *)(lVar22 + 0xa0) = 0;
  return;
}

