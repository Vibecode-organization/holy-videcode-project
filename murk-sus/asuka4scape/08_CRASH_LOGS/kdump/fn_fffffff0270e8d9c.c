// FUN_fffffff0270e8d9c @ fffffff0270e8d9c size=2440
// CALLERS:
//   fffffff027022268 ?
//   fffffff027022898 ?
//   fffffff0270e978c FUN_fffffff0270e9724@fffffff0270e9724
// CALLS:
//   fffffff0270debdc FUN_fffffff0270debdc
//   fffffff0270f353c FUN_fffffff0270f353c
//   fffffff0270a40e8 FUN_fffffff0270a40e8
//   fffffff0270f34fc FUN_fffffff0270f34fc
//   fffffff0270de884 FUN_fffffff0270de884
//   fffffff0270d1924 FUN_fffffff0270d1924

void FUN_fffffff0270e8d9c(ulong param_1,ulong param_2,ulong param_3,undefined8 param_4)

{
  ushort uVar1;
  uint uVar2;
  undefined1 uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  char *pcVar10;
  ulong *puVar11;
  long lVar12;
  byte bVar13;
  ushort *puVar14;
  uint uVar15;
  uint uVar16;
  undefined1 auVar17 [16];
  undefined2 local_62;
  
  if (((param_1 & 0x3fff) != 0 || param_1 < DAT_fffffff0270921c8) || DAT_fffffff0270921d0 <= param_1
     ) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(6,param_2,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx)\n");
  }
  uVar16 = (uint)param_2;
  if ((0x43 < (uVar16 & 0xff)) || (uVar15 = (uint)param_3, 0x43 < (uVar15 & 0xff))) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(9,param_2,"%s(%s:%d) - %s(%#llx), %s(%#llx)\n");
  }
  lVar8 = UnkSytemRegRead(3,6,0xf,0xb,1);
  *(long *)(lVar8 + 0x1640) = *(long *)(lVar8 + 0x1640) + 1;
  if ((param_1 < DAT_fffffff0270921c8) || (DAT_fffffff0270921d0 <= param_1)) {
    auVar17 = FUN_fffffff0270de884(param_1);
    uVar5 = auVar17._8_8_;
    puVar14 = &DAT_fffffff0270fdec0;
    if (auVar17._0_8_ != (ushort *)0x0) {
      puVar14 = auVar17._0_8_;
    }
  }
  else {
    uVar5 = param_2;
    puVar14 = (ushort *)
              (DAT_fffffff0270914f0 + (param_1 - DAT_fffffff0270921c8 >> 0xe & 0xffffffff) * 0x10);
  }
  uVar1 = *puVar14;
  if (uVar1 == 0) {
    *puVar14 = 1;
  }
  uVar6 = (ulong)(byte)puVar14[1];
  if (uVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c
              (0x42,uVar5,"%s(%s:%d) - fte(%p), fte->type(%s), new_type(%s), retype_params(%#llx)\n"
              );
  }
  lVar8 = uVar6 * 0x90;
  pcVar10 = &DAT_fffffff027092200 + lVar8;
  uVar7 = uVar6;
  if ((param_2 & 0xff) != 0) {
    lVar9 = UnkSytemRegRead(3,6,0xf,0xb,1);
    uVar7 = (ulong)(byte)puVar14[1];
    if (*(char *)(lVar9 + 0xb00) != *pcVar10) {
      UnkSytemRegRead(3,6,0xf,0xb,1);
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f353c
                (0x44,uVar5,
                 "%s(%s:%d) - fte(%p), fte->type(%s), current_type(%s), calling_domain(%u), owner_domain(%u)\n"
                );
    }
  }
  if ((uint)uVar7 == 0xb) {
    uVar2 = (uint)(DAT_fffffff027102040 >> 0x16) & 1;
    uVar4 = (ulong)(byte)puVar14[1];
    if ((param_2 & 0xff) != 0) {
      uVar2 = 1;
    }
    if (((uint)(byte)puVar14[1] != (uVar16 & 0xff)) && (uVar2 != 0)) {
LAB_fffffff0270e951c:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f353c
                (0x46,uVar5,
                 "%s(%s:%d) - paddr(%#llx), fte->type(%s), current_type(%s), new_type(%s)\n");
    }
    if (((uint)DAT_fffffff027102040 >> 0x16 & 1) == 0) {
      pcVar10 = &DAT_fffffff027092200;
    }
  }
  else {
    uVar4 = param_2;
    if ((uint)uVar7 != (uVar16 & 0xff)) goto LAB_fffffff0270e951c;
  }
  uVar7 = *(ulong *)(pcVar10 + 0x48) >> (param_3 & 0x3f);
  if ((param_3 & 0x40) == 0) {
    uVar7 = (*(ulong *)(pcVar10 + 0x48) << 1) << ((ulong)~uVar15 & 0x3f) |
            *(ulong *)(pcVar10 + 0x40) >> (param_3 & 0x3f);
  }
  if ((uVar7 & 1) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x19,uVar5,"%s(%s:%d) - paddr(%#llx), fte->type(%s), new_type(%s)\n");
  }
  if (((&DAT_fffffff027092201)[((uVar4 & 0xff) + (uVar4 & 0xff) * 8) * 0x10] != '\x06') &&
     (*puVar14 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: Frame expected to have been acquired has not been acquired %p %s %u");
  }
  if (((byte)(&DAT_fffffff027092231)[(uVar4 & 0xff) * 0x90] >> 2 & 1) == 0) {
    bVar13 = *(byte *)((long)puVar14 + 3) >> 1 & 1;
  }
  else {
    bVar13 = 1;
  }
  if ((((&DAT_fffffff027092231)[(uVar4 & 0xff) * 0x90] & 3) != 0) && (bVar13 != 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c
              (0x1a,uVar5,"%s(%s:%d) - paddr(%#llx), fte(%p), fte->type(%s), new_type(%s)\n");
  }
  (*(code *)(&PTR_FUN_fffffff027092270)[uVar6 * 0x12])(puVar14,uVar15 & 0xff);
  if (((DAT_fffffff0270921b8 != 0) && ((*(byte *)(DAT_fffffff0270921b8 + 0x80) & 1) != 0)) &&
     ((&DAT_fffffff027092201)[((param_2 & 0xff) + (param_2 & 0xff) * 8) * 0x10] == '\x03')) {
    if ((*puVar14 & 1) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc("%s: FTE %p should be held exclusive by sptm_retype()");
    }
    if ((&DAT_fffffff027092201)[(ulong)(byte)puVar14[1] * 0x90] != '\x03') {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc("%s: Only CPU pages may need a GMMU TLBI on retype");
    }
    uVar1 = puVar14[3];
    if ((uVar1 & 0xc000) != 0) {
      if (uVar1 < 0xc000) {
        uVar5 = (ulong)(uVar1 >> 8) & 0x3f;
        if (((uVar1 & 0xc000) == 0x4000) &&
           ((ushort)*(byte *)(DAT_fffffff0270921b8 + uVar5 * 2 + 0x83) != (uVar1 & 0xff))) {
          lVar9 = UnkSytemRegRead(3,6,0xf,0xb,1);
          *(long *)(lVar9 + 0x1670) = *(long *)(lVar9 + 0x1670) + 1;
        }
        else {
          pcVar10 = (char *)(DAT_fffffff0270921b8 + 0x82 + uVar5 * 2);
          *pcVar10 = *pcVar10 + '\x01';
          DataSynchronizationBarrier(0,2,0);
          SysOp_W(0,8,1,2,uVar5 << 0x30);
          DataSynchronizationBarrier(0,3,0);
          pcVar10 = (char *)(DAT_fffffff0270921b8 + uVar5 * 2 + 0x83);
          *pcVar10 = *pcVar10 + '\x01';
          lVar9 = UnkSytemRegRead(3,6,0xf,0xb,1);
          *(long *)(lVar9 + 0x1648) = *(long *)(lVar9 + 0x1648) + 1;
        }
      }
      else if (((uVar1 & 0x3f00) == 0) &&
              ((ushort)*(byte *)(DAT_fffffff0270921b8 + 0x103) != (uVar1 & 0xff))) {
        lVar9 = UnkSytemRegRead(3,6,0xf,0xb,1);
        *(long *)(lVar9 + 0x1678) = *(long *)(lVar9 + 0x1678) + 1;
      }
      else {
        lVar9 = 0;
        lVar12 = 0x82;
        do {
          pcVar10 = (char *)(DAT_fffffff0270921b8 + 0x82 + lVar9 * 2);
          *pcVar10 = *pcVar10 + '\x01';
          lVar9 = lVar9 + 1;
          lVar12 = lVar12 + 2;
        } while (lVar12 != 0x102);
        *(char *)(DAT_fffffff0270921b8 + 0x102) = *(char *)(DAT_fffffff0270921b8 + 0x102) + '\x01';
        DataSynchronizationBarrier(0,2,0);
        SysOp_W(4,8,1,4,0);
        DataSynchronizationBarrier(0,3,0);
        lVar9 = 0;
        lVar12 = 0x83;
        do {
          pcVar10 = (char *)(DAT_fffffff0270921b8 + lVar9 * 2 + 0x83);
          *pcVar10 = *pcVar10 + '\x01';
          lVar9 = lVar9 + 1;
          lVar12 = lVar12 + 2;
        } while (lVar12 != 0x103);
        *(char *)(DAT_fffffff0270921b8 + 0x103) = *(char *)(DAT_fffffff0270921b8 + 0x103) + '\x01';
        lVar9 = UnkSytemRegRead(3,6,0xf,0xb,1);
        *(long *)(lVar9 + 0x1650) = *(long *)(lVar9 + 0x1650) + 1;
      }
    }
  }
  if ((*(ushort *)(&DAT_fffffff027092260 + lVar8) >> 4 & 1) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (undefined1)puVar14[2];
  }
  *(undefined1 *)(puVar14 + 2) = uVar3;
  if ((*(ushort *)(&DAT_fffffff027092260 + lVar8) >> 5 & 1) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined1 *)((long)puVar14 + 5);
  }
  *(undefined1 *)((long)puVar14 + 5) = uVar3;
  if ((*(ushort *)(&DAT_fffffff027092260 + lVar8) >> 6 & 1) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (undefined1)puVar14[3];
  }
  *(undefined1 *)(puVar14 + 3) = uVar3;
  if ((*(ushort *)(&DAT_fffffff027092260 + lVar8) >> 7 & 1) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined1 *)((long)puVar14 + 7);
  }
  *(undefined1 *)((long)puVar14 + 7) = uVar3;
  if ((*(ushort *)(&DAT_fffffff027092260 + lVar8) >> 8 & 1) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (undefined1)puVar14[4];
  }
  *(undefined1 *)(puVar14 + 4) = uVar3;
  if ((*(ushort *)(&DAT_fffffff027092260 + lVar8) >> 9 & 1) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined1 *)((long)puVar14 + 9);
  }
  *(undefined1 *)((long)puVar14 + 9) = uVar3;
  if ((*(ushort *)(&DAT_fffffff027092260 + lVar8) >> 10 & 1) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (undefined1)puVar14[5];
  }
  *(undefined1 *)(puVar14 + 5) = uVar3;
  if ((*(ushort *)(&DAT_fffffff027092260 + lVar8) >> 0xb & 1) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined1 *)((long)puVar14 + 0xb);
  }
  *(undefined1 *)((long)puVar14 + 0xb) = uVar3;
  if ((*(ushort *)(&DAT_fffffff027092260 + lVar8) >> 0xc & 1) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (undefined1)puVar14[6];
  }
  lVar9 = (param_3 & 0xff) + (param_3 & 0xff) * 8;
  *(undefined1 *)(puVar14 + 6) = uVar3;
  if ((*(ushort *)(&DAT_fffffff027092260 + lVar8) >> 0xd & 1) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined1 *)((long)puVar14 + 0xd);
  }
  *(undefined1 *)((long)puVar14 + 0xd) = uVar3;
  if ((*(ushort *)(&DAT_fffffff027092260 + lVar8) >> 0xe & 1) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (undefined1)puVar14[7];
  }
  *(undefined1 *)(puVar14 + 7) = uVar3;
  if (*(short *)(&DAT_fffffff027092260 + lVar8) < 0) {
    uVar3 = *(undefined1 *)((long)puVar14 + 0xf);
  }
  else {
    uVar3 = 0;
  }
  *(undefined1 *)((long)puVar14 + 0xf) = uVar3;
  local_62 = 0;
  (*(code *)(&PTR_FUN_fffffff027092268)[lVar9 * 2])(puVar14,uVar15 & 0xff,param_4,&local_62);
  *(char *)(puVar14 + 1) = (char)param_3;
  FUN_fffffff0270d1924
            (param_1,(&DAT_fffffff027092206)[lVar9 * 0x10],(undefined1)local_62,
             (local_62._1_1_ & 1) << 6 | 3);
  if (((&DAT_fffffff027092204)[(param_3 & 0xff) * 0x48] & 0x2020) != 0) {
    if (((uint)DAT_fffffff027102040 >> 8 & 1) == 0) {
      lVar8 = (param_1 - DAT_fffffff0270921c8) + DAT_fffffff027090ff0;
    }
    else {
      uVar5 = (ulong)DAT_fffffff0270fd9f8;
      if (DAT_fffffff0270fd9f8 != 0) {
        lVar8 = 0;
        do {
          puVar11 = &DAT_fffffff0270fda00 + lVar8 * 3;
          if ((((ulong)puVar11 ^ 0xfffffff0270fda00) & 0xffc0000000000000) != 0) {
            puVar11 = (ulong *)((ulong)puVar11 & 0xffffffffffff | 0xc8a2000000000000);
          }
          uVar6 = *puVar11;
          if ((uVar6 <= param_1) && (param_1 < uVar6 + (ulong)(uint)puVar11[2] * 0x4000)) {
            lVar8 = (param_1 - uVar6) + puVar11[1];
            goto LAB_fffffff0270e91dc;
          }
          lVar8 = lVar8 + 1;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      lVar8 = FUN_fffffff0270debdc(param_1);
    }
LAB_fffffff0270e91dc:
    FUN_fffffff0270a40e8(lVar8,0x4000);
  }
  if (((uint)DAT_fffffff027102040 >> 8 & 1) == 0) {
    lVar8 = (param_1 - DAT_fffffff0270921c8) + DAT_fffffff027090ff0;
  }
  else {
    uVar5 = (ulong)DAT_fffffff0270fd9f8;
    if (DAT_fffffff0270fd9f8 != 0) {
      lVar8 = 0;
      do {
        puVar11 = &DAT_fffffff0270fda00 + lVar8 * 3;
        if ((((ulong)puVar11 ^ 0xfffffff0270fda00) & 0xffc0000000000000) != 0) {
          puVar11 = (ulong *)((ulong)puVar11 & 0xffffffffffff | 0xc8a2000000000000);
        }
        uVar6 = *puVar11;
        if ((uVar6 <= param_1) && (param_1 < uVar6 + (ulong)(uint)puVar11[2] * 0x4000)) {
          lVar8 = (param_1 - uVar6) + puVar11[1];
          goto LAB_fffffff0270e9254;
        }
        lVar8 = lVar8 + 1;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    lVar8 = FUN_fffffff0270debdc(param_1);
  }
LAB_fffffff0270e9254:
  (*(code *)(&PTR_FUN_fffffff027092238)[lVar9 * 2])(puVar14,lVar8);
  *puVar14 = 0;
  return;
}

