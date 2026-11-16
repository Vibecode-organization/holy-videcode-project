// FUN_fffffff008cfdfac @ fffffff008cfdfac size=1764
// CALLERS:
// CALLEES:
//   fffffff008cd5990 FUN_fffffff008cd5990
//   fffffff008d3cb48 FUN_fffffff008d3cb48
//   fffffff008e00610 thunk_EXT_FUN_8011000002c25268
//   fffffff008dba984 FUN_fffffff008dba984
//   fffffff008ccb620 FUN_fffffff008ccb620
//   fffffff008de3ac8 FUN_fffffff008de3ac8
//   fffffff008de39c0 FUN_fffffff008de39c0
//   fffffff008ccb5c8 FUN_fffffff008ccb5c8
//   fffffff008e00540 thunk_EXT_FUN_8011000002c24f68
//   fffffff008de3b38 FUN_fffffff008de3b38
//   fffffff008de3b70 FUN_fffffff008de3b70
//   fffffff008e00560 thunk_EXT_FUN_8011000002c254a8
//   fffffff008ccb600 FUN_fffffff008ccb600
//   fffffff008d3caec FUN_fffffff008d3caec
//   fffffff008e00460 thunk_EXT_FUN_8011000002c1e74c
//   fffffff008de3a08 FUN_fffffff008de3a08
//   fffffff008ccb5c0 thunk_FUN_fffffff008ccb130
//   fffffff008e00430 thunk_EXT_FUN_8011000002c1e680
//   fffffff008e00530 thunk_EXT_FUN_8011000002c24ea8
//   fffffff008e005e0 thunk_EXT_FUN_8011000002c251a8
//   fffffff008e003f0 thunk_EXT_FUN_8011000002c1b1a8
//   fffffff008de3928 FUN_fffffff008de3928
//   fffffff008de38dc FUN_fffffff008de38dc
//   fffffff008de3b00 FUN_fffffff008de3b00
//   fffffff008cd5954 FUN_fffffff008cd5954
//   fffffff008de3a74 FUN_fffffff008de3a74
//   fffffff008de3974 FUN_fffffff008de3974

undefined4 FUN_fffffff008cfdfac(long param_1,uint param_2,undefined8 param_3)

{
  ulong *puVar1;
  byte *pbVar2;
  int *piVar3;
  undefined4 uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  bool bVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  long lVar16;
  ulong uVar17;
  ulong uVar18;
  ulong uVar19;
  ulong uVar20;
  undefined8 uVar21;
  undefined8 in_x7;
  undefined4 uVar22;
  long lVar23;
  ulong uVar24;
  long lVar25;
  long lVar26;
  ulong uVar27;
  ulong uVar28;
  ulong uVar29;
  ulong uVar30;
  ulong uVar31;
  ulong local_70;
  ulong local_68;
  
  lVar26 = *(long *)(param_1 + 0x18);
  lVar16 = FUN_fffffff008dba984(param_3);
  lVar25 = 0;
  while ((lVar25 != 2 || (*(char *)(lVar26 + 0x1fd) != '\0'))) {
    uVar17 = FUN_fffffff008d3caec(lVar25);
    if ((uVar17 & 1) == 0) {
      if ((*(byte *)(lVar16 + 0x1f2) & 1) == 0) {
        lVar23 = 1;
        goto LAB_fffffff008cfe034;
      }
    }
    else {
      lVar23 = 0;
LAB_fffffff008cfe034:
      if (*(char *)(lVar16 + 0x27c + lVar25) == '\x01') {
        uVar17 = lVar23 << 3 | (ulong)param_2 << 5;
        puVar1 = (ulong *)(lVar16 + 0x128 + (long)(int)uVar17);
        if (uVar17 != (long)(int)uVar17) {
          puVar1 = (ulong *)(lVar16 + 0x128 + uVar17 & 0xffffffffffff | 0x2bad000000000000);
        }
        if (*puVar1 < 0x80) {
          uVar22 = 0xe00002c2;
          iVar9 = FUN_fffffff008cd5954(1,0xc);
          if (iVar9 != 0) {
            FUN_fffffff008de3974(param_2,puVar1,lVar23);
          }
          goto LAB_fffffff008cfe0c4;
        }
        uVar17 = lVar23 << 3 | (ulong)param_2 << 5;
        iVar9 = (int)uVar17;
        pbVar2 = (byte *)(lVar16 + 0xa8 + (long)iVar9);
        if (uVar17 != (long)iVar9) {
          pbVar2 = (byte *)(lVar16 + 0xa8 + uVar17 & 0xffffffffffff | 0x2bad000000000000);
        }
        if ((*pbVar2 & 0x7f) != 0) {
          uVar22 = 0xe00002c2;
          iVar9 = FUN_fffffff008cd5954(1,0xc);
          if (iVar9 != 0) {
            FUN_fffffff008de38dc(param_2,pbVar2,lVar23);
          }
          goto LAB_fffffff008cfe0c4;
        }
        pbVar2 = (byte *)(lVar16 + 0x168 + (long)iVar9);
        if (uVar17 != (long)iVar9) {
          pbVar2 = (byte *)(lVar16 + 0x168 + uVar17 & 0xffffffffffff | 0x2bad000000000000);
        }
        if ((*pbVar2 & 0x7f) != 0) {
          uVar22 = 0xe00002c2;
          iVar9 = FUN_fffffff008cd5954(1,0xc);
          if (iVar9 != 0) {
            FUN_fffffff008de3928(param_2,pbVar2,lVar23);
          }
          goto LAB_fffffff008cfe0c4;
        }
      }
    }
    lVar25 = lVar25 + 1;
    if (lVar25 == 3) break;
  }
  uVar22 = 0;
LAB_fffffff008cfe0c4:
  if ((DAT_fffffff00ae6f1f4 != 0) &&
     (lVar25 = FUN_fffffff008dba984(param_3,param_2), *(int *)(lVar25 + 0xc) != 0)) {
    uVar17 = 0;
    uVar4 = *(undefined4 *)(lVar25 + 0x10);
    do {
      iVar9 = thunk_EXT_FUN_8011000002c254a8(*(undefined8 *)(lVar25 + 0x90),uVar17);
      if (iVar9 == 3) {
        lVar16 = uVar17 * 4;
        piVar3 = (int *)(lVar25 + 0x200 + (long)(int)lVar16);
        if (lVar16 - (int)lVar16 != 0) {
          piVar3 = (int *)(lVar25 + 0x200 + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
        }
        bVar8 = *piVar3 == 1;
        local_70 = 0;
        local_68 = 0;
        uVar10 = thunk_EXT_FUN_8011000002c1e680(*(undefined8 *)(lVar25 + 0x90),uVar17);
        uVar11 = thunk_EXT_FUN_8011000002c1e74c(*(undefined8 *)(lVar25 + 0x90),uVar17);
        FUN_fffffff008ccb5c8(bVar8,&local_68,&local_70);
        uVar24 = local_68;
        uVar7 = local_70;
        lVar16 = thunk_FUN_fffffff008ccb130(uVar4,uVar17,0,bVar8);
        uVar18 = FUN_fffffff008ccb620(uVar4,uVar17,0,bVar8,uVar10,uVar11);
        uVar12 = thunk_EXT_FUN_8011000002c24ea8(*(undefined8 *)(lVar25 + 0x90),uVar17);
        uVar13 = thunk_EXT_FUN_8011000002c24f68(*(undefined8 *)(lVar25 + 0x90),uVar17);
        uVar19 = FUN_fffffff008ccb600(bVar8,uVar10,uVar11,uVar12,uVar13);
        uVar14 = thunk_EXT_FUN_8011000002c251a8(*(undefined8 *)(lVar25 + 0x90),uVar17);
        uVar28 = (ulong)uVar14;
        uVar15 = thunk_EXT_FUN_8011000002c25268(*(undefined8 *)(lVar25 + 0x90),uVar17);
        uVar27 = (ulong)uVar15;
        uVar20 = thunk_EXT_FUN_8011000002c1b1a8(*(undefined8 *)(lVar25 + 0x90));
        uVar31 = (ulong)*(uint *)(lVar25 + 0x18);
        if (uVar14 < uVar15) {
          uVar29 = uVar27 - uVar28;
          uVar30 = uVar20 - uVar27;
          bVar8 = true;
        }
        else if (uVar15 < uVar14) {
          uVar30 = uVar28 - uVar27;
          uVar29 = uVar20 - uVar28;
          bVar8 = true;
        }
        else {
          iVar9 = FUN_fffffff008cd5954(1,0xc);
          if (iVar9 != 0) {
            FUN_fffffff008de39c0(param_2);
          }
          bVar8 = false;
          uVar29 = 0;
          uVar30 = 0;
        }
        if (uVar29 < uVar18) {
          iVar9 = FUN_fffffff008cd5954(1,0xc);
          if (iVar9 != 0) {
            uVar21 = FUN_fffffff008d3cb48(param_2);
            FUN_fffffff008cd5990
                      (1,0xc,0xff,"validateCompressedTileBuffers",
                       "/Library/Caches/com.apple.xbs/707A499F-C092-4EC7-9870-008113E1647D/TemporaryDirectory.2EJgzU/Sources/IOSurfaceAccelerator_kexts/IosaTiledCompressedMemMSR8.cpp"
                       ,0x226,"%s Plane %u Size %llu is less than expected size %llu\n",in_x7,uVar21
                       ,uVar17,uVar29,uVar18);
          }
          bVar8 = false;
        }
        if (uVar30 < uVar19) {
          iVar9 = FUN_fffffff008cd5954(1,0xc);
          if (iVar9 != 0) {
            uVar21 = FUN_fffffff008d3cb48(param_2);
            FUN_fffffff008cd5990
                      (1,0xc,0xff,"validateCompressedTileBuffers",
                       "/Library/Caches/com.apple.xbs/707A499F-C092-4EC7-9870-008113E1647D/TemporaryDirectory.2EJgzU/Sources/IOSurfaceAccelerator_kexts/IosaTiledCompressedMemMSR8.cpp"
                       ,0x22f,"%s Plane %u Metadata Size %llu is less than expected size %llu\n",
                       in_x7,uVar21,uVar17,uVar30,uVar19);
          }
          bVar8 = false;
        }
        uVar5 = 0;
        if (uVar24 != 0) {
          uVar5 = ((uVar24 + uVar10) - 1) / uVar24;
        }
        uVar24 = lVar16 * uVar5;
        if (uVar31 <= uVar24 && uVar24 - uVar31 != 0) {
          iVar9 = FUN_fffffff008cd5954(1,0xc);
          if (iVar9 != 0) {
            uVar21 = FUN_fffffff008d3cb48(param_2);
            FUN_fffffff008cd5990
                      (1,0xc,0xff,"validateCompressedTileBuffers",
                       "/Library/Caches/com.apple.xbs/707A499F-C092-4EC7-9870-008113E1647D/TemporaryDirectory.2EJgzU/Sources/IOSurfaceAccelerator_kexts/IosaTiledCompressedMemMSR8.cpp"
                       ,0x238,"%s Plane %u Stride %llu is less than expected minimum stride %llu\n",
                       in_x7,uVar21,uVar17,uVar31,uVar24);
          }
          bVar8 = false;
        }
        uVar6 = 0;
        if (local_68 != 0) {
          uVar6 = uVar31 / local_68;
        }
        if (uVar31 != uVar6 * local_68) {
          iVar9 = FUN_fffffff008cd5954(1,0xc);
          if (iVar9 != 0) {
            FUN_fffffff008de3a08(param_2,&local_68,uVar17,uVar31);
          }
          bVar8 = false;
        }
        uVar6 = 0;
        if (uVar7 != 0) {
          uVar6 = ((uVar7 + uVar11) - 1) / uVar7;
        }
        if (uVar6 * uVar31 * local_70 < uVar20) {
          iVar9 = FUN_fffffff008cd5954(1,0xc);
          if (iVar9 != 0) {
            uVar21 = FUN_fffffff008d3cb48(param_2);
            FUN_fffffff008cd5990
                      (1,0xc,0xff,"validateCompressedTileBuffers",
                       "/Library/Caches/com.apple.xbs/707A499F-C092-4EC7-9870-008113E1647D/TemporaryDirectory.2EJgzU/Sources/IOSurfaceAccelerator_kexts/IosaTiledCompressedMemMSR8.cpp"
                       ,0x24c,
                       "%s Plane %u Size %llu cannot support a stride of %llu for macroblocks height %llu\n"
                       ,in_x7,uVar21,uVar17,uVar20,uVar31,uVar6);
          }
LAB_fffffff008cfe4e4:
          iVar9 = FUN_fffffff008cd5954(1,0xc);
          if (iVar9 != 0) {
            FUN_fffffff008de3a74(param_2,uVar17);
          }
          iVar9 = FUN_fffffff008cd5954(1,0xc);
          if (iVar9 != 0) {
            FUN_fffffff008cd5990
                      (1,0xc,0xff,"validateCompressedTileBuffers",
                       "/Library/Caches/com.apple.xbs/707A499F-C092-4EC7-9870-008113E1647D/TemporaryDirectory.2EJgzU/Sources/IOSurfaceAccelerator_kexts/IosaTiledCompressedMemMSR8.cpp"
                       ,0x259,
                       "ExpectedSize: %llu, ExpectedMinStride: %llu, ExpectedMetadataSize: %llu, ExpectedTileSize: %llu\n "
                       ,in_x7,uVar19 + uVar18,uVar24,uVar19,uVar18);
          }
          iVar9 = FUN_fffffff008cd5954(1,0xc);
          if (iVar9 != 0) {
            FUN_fffffff008cd5990
                      (1,0xc,0xff,"validateCompressedTileBuffers",
                       "/Library/Caches/com.apple.xbs/707A499F-C092-4EC7-9870-008113E1647D/TemporaryDirectory.2EJgzU/Sources/IOSurfaceAccelerator_kexts/IosaTiledCompressedMemMSR8.cpp"
                       ,0x25d,
                       "ActualSize: %llu, ActualStride: %llu, ActualPlaneBaseOffset: %llu, ActualMetadataOffset: %llu\n"
                       ,in_x7,uVar20,uVar31,uVar28,uVar27);
          }
          iVar9 = FUN_fffffff008cd5954(1,0xc);
          if (iVar9 != 0) {
            FUN_fffffff008de3ac8(uVar29,uVar30);
          }
          iVar9 = FUN_fffffff008cd5954(1,0xc);
          if (iVar9 != 0) {
            FUN_fffffff008de3b00(uVar10,uVar11);
          }
          iVar9 = FUN_fffffff008cd5954(1,0xc);
          if (iVar9 != 0) {
            FUN_fffffff008de3b38(uVar5,uVar6);
          }
          iVar9 = FUN_fffffff008cd5954(1,0xc);
          if (iVar9 != 0) {
            FUN_fffffff008de3b70(&local_68,&local_70);
          }
          return 0xe00002d1;
        }
        if (!bVar8) goto LAB_fffffff008cfe4e4;
      }
      uVar17 = uVar17 + 1;
    } while (uVar17 < *(uint *)(lVar25 + 0xc));
  }
  return uVar22;
}

