// FUN_fffffff009c1af14 @ fffffff009c1af14 size=14096

/* WARNING: Removing unreachable block (ram,0xfffffff009c1e030) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1c78c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1c600) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1c554) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1b188) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1c88c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1c738) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1df68) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1e078) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1b134) */

void FUN_fffffff009c1af14(long param_1,undefined8 param_2)

{
  ulong *puVar1;
  uint *puVar2;
  long lVar3;
  uint *puVar4;
  undefined1 **ppuVar5;
  undefined4 *puVar6;
  ushort uVar7;
  uint uVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  bool bVar32;
  bool bVar33;
  byte bVar34;
  int iVar35;
  uint uVar36;
  uint uVar37;
  ulong uVar38;
  long *plVar39;
  long lVar40;
  undefined8 uVar41;
  long lVar42;
  long lVar43;
  long *plVar44;
  uint uVar45;
  ulong uVar46;
  undefined1 *puVar47;
  undefined8 *puVar48;
  ulong uVar49;
  ulong uVar50;
  undefined1 *puVar51;
  ulong uVar52;
  ulong uVar53;
  ulong uVar54;
  byte bVar55;
  uint uVar56;
  byte *pbVar57;
  byte *pbVar58;
  undefined1 **ppuVar59;
  ulong uVar60;
  undefined8 uVar61;
  byte local_89;
  ulong local_88;
  byte local_79;
  undefined1 *local_78;
  long local_70;
  
  local_70 = *(long *)PTR_DAT_fffffff00806ca40;
  local_78 = &DAT_aaaaaaaaaaaaaaaa;
  local_88 = local_88 & 0xffffffffffffff00;
  iVar35 = FUN_fffffff009c1fec4(param_2,"IOSurfaceDisableMapperFlush",&local_88);
  if (iVar35 != 0) {
    *(uint *)(param_1 + 0x3d0) =
         *(uint *)(param_1 + 0x3d0) & 0xff000000 |
         *(uint *)(param_1 + 0x3d0) & 0x7fffff | ((byte)local_88 & 1) << 0x17;
  }
  local_88 = local_88 & 0xffffffffffffff00;
  iVar35 = FUN_fffffff009c1fec4(param_2,"IOSurfacePreallocPages",&local_88);
  if (iVar35 != 0) {
    *(uint *)(param_1 + 0x3d0) =
         *(uint *)(param_1 + 0x3d0) & 0xfffff000 |
         *(uint *)(param_1 + 0x3d0) & 0x7ff | ((byte)local_88 & 1) << 0xb;
  }
  local_88 = local_88 & 0xffffffffffffff00;
  iVar35 = FUN_fffffff009c1fec4(param_2,"IOSurfacePrefetchPages",&local_88);
  if (iVar35 != 0) {
    *(uint *)(param_1 + 0x3d0) =
         *(uint *)(param_1 + 0x3d0) & 0xffff8000 |
         *(uint *)(param_1 + 0x3d0) & 0x3fff | ((byte)local_88 & 1) << 0xe;
  }
  local_88 = local_88 & 0xffffffffffffff00;
  iVar35 = FUN_fffffff009c1fec4(param_2,"IOSurfaceHostOnly",&local_88);
  if (iVar35 != 0) {
    *(uint *)(param_1 + 0x3d0) =
         *(uint *)(param_1 + 0x3d0) & 0xfe000000 |
         *(uint *)(param_1 + 0x3d0) & 0xffffff | ((byte)local_88 & 1) << 0x18;
  }
  local_88 = local_88 & 0xffffffffffffff00;
  iVar35 = FUN_fffffff009c1fec4(param_2,"MetalSharedTexture",&local_88);
  if (iVar35 != 0) {
    *(uint *)(param_1 + 0x3d0) =
         *(uint *)(param_1 + 0x3d0) & 0xfc000000 |
         *(uint *)(param_1 + 0x3d0) & 0x1ffffff | ((byte)local_88 & 1) << 0x19;
  }
  local_88 = local_88 & 0xffffffffffffff00;
  uVar38 = FUN_fffffff009c1fec4(param_2,"IOSurfaceGPUGlobalRO",&local_88);
  if ((uVar38 & 1) == 0) {
    uVar36 = *(uint *)(param_1 + 0x3d0);
    uVar37 = uVar36 >> 0xe & 1;
  }
  else {
    uVar37 = *(uint *)(param_1 + 0x3d0);
    uVar36 = uVar37 & 0xf8000000 | uVar37 & 0x3ffffff | ((byte)local_88 & 1) << 0x1a;
    *(uint *)(param_1 + 0x3d0) = uVar36;
    uVar37 = uVar37 & 0x4000;
  }
  if (uVar37 != 0) {
    *(uint *)(param_1 + 0x3d0) = uVar36 & 0xfffff7ff;
  }
  local_88 = local_88 & 0xffffffffffffff00;
  iVar35 = FUN_fffffff009c1fec4(param_2,"IOSurfaceUseReserve",&local_88);
  if (iVar35 != 0) {
    *(uint *)(param_1 + 0x3d0) =
         *(uint *)(param_1 + 0x3d0) & 0xfffc0000 |
         *(uint *)(param_1 + 0x3d0) & 0x1ffff | ((byte)local_88 & 1) << 0x11;
  }
  local_79 = 0;
  iVar35 = FUN_fffffff009c1fec4(param_2,"IOSurfaceNonPurgeable",&local_79);
  if (iVar35 != 0) {
    *(uint *)(param_1 + 0x3d0) =
         *(uint *)(param_1 + 0x3d0) & 0xffff0000 |
         *(uint *)(param_1 + 0x3d0) & 0x7fff | (~(uint)local_79 & 1) << 0xf;
  }
  local_88 = local_88 & 0xffffffffffffff00;
  iVar35 = FUN_fffffff009c1fec4(param_2,"IsDisplayable",&local_88);
  uVar36 = *(uint *)(param_1 + 0x3d0);
  if (iVar35 != 0) {
    uVar36 = uVar36 & 0xffe00000 | uVar36 & 0xfffff | ((byte)local_88 & 1) << 0x14;
    *(uint *)(param_1 + 0x3d0) = uVar36;
  }
  plVar44 = (long *)(param_1 + 0x178);
  *(byte *)(*(long *)(param_1 + 0x178) + 0x2d) = (byte)(uVar36 >> 0x14) & 1;
  local_88 = local_88 & 0xffffffffffffff00;
  iVar35 = FUN_fffffff009c1fec4(param_2,"IOSurfaceSysMemOnly",&local_88);
  uVar36 = *(uint *)(param_1 + 0x3d0);
  if (iVar35 != 0) {
    uVar36 = uVar36 & 0xfff80000 | uVar36 & 0x3ffff | ((byte)local_88 & 1) << 0x12;
    *(uint *)(param_1 + 0x3d0) = uVar36;
  }
  *(byte *)(*(long *)(param_1 + 0x178) + 0x2e) = (byte)(uVar36 >> 0x12) & 1;
  uVar38 = FUN_fffffff009c1ff50(param_2,"IOSurfaceSubsampling",param_1 + 0x3ac);
  if ((uVar38 & 1) == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
               "IOSurface::parse_properties() problem with kIOSurfaceSubsampling\n");
    lVar43 = 0;
    goto LAB_fffffff009c1b2a8;
  }
  local_88 = local_88 & 0xffffffffffffff00;
  iVar35 = FUN_fffffff009c1fec4(param_2,"IOSurfaceProhibitUseCount",&local_88);
  if (iVar35 != 0) {
    *(uint *)(param_1 + 0x3d0) =
         *(uint *)(param_1 + 0x3d0) & 0xffc00000 |
         *(uint *)(param_1 + 0x3d0) & 0x1fffff | ((byte)local_88 & 1) << 0x15;
  }
  *(undefined8 *)(param_1 + 0x308) = 0;
  *(undefined4 *)(param_1 + 0x310) = 0;
  *(undefined4 *)(param_1 + 0x3b8) = 0;
  plVar39 = (long *)FUN_fffffff009c20000(param_2,"IOSurfacePlaneInfo");
  if (plVar39 == (long *)0x0) {
    *(undefined8 *)(param_1 + 0x180) = 0;
    *(undefined4 *)(param_1 + 0x188) = 0;
    *(undefined8 *)(param_1 + 0x328) = 1;
    uVar38 = thunk_EXT_FUN_80110000038fe5cc(0x18);
    *(ulong *)(param_1 + 0x318) = uVar38;
    *(undefined4 *)(param_1 + 800) = 1;
    lVar43 = 0;
    if (uVar38 == 0) goto LAB_fffffff009c1b2a8;
    uVar52 = (uVar38 + 0x18) - uVar38;
    if ((uVar38 + 0x18 < uVar38) || (uVar52 >> 0x20 != 0)) {
      FUN_fffffff009c48f64();
LAB_fffffff009c1d4d8:
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface: compressed plane[%d] Header region doesn\'t fit into plane size\n");
      lVar43 = 0;
      goto LAB_fffffff009c1b2a8;
    }
    if (uVar52 < 0x18) goto LAB_fffffff009c1e618;
    uVar38 = FUN_fffffff009c201c4(uVar38,param_2);
    if ((uVar38 & 1) == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface::parse_properties() parseAdditionalPlaneInfo failed.\n");
      lVar43 = 0;
      goto LAB_fffffff009c1b2a8;
    }
    *(undefined8 *)(param_1 + 0x348) = 0x20;
    uVar38 = thunk_EXT_FUN_80110000038fe5cc(0x20);
    *(ulong *)(param_1 + 0x350) = uVar38;
    *(undefined4 *)(param_1 + 0x358) = 1;
    lVar43 = 0;
    if (uVar38 == 0) goto LAB_fffffff009c1b2a8;
    uVar52 = (uVar38 + 0x20) - uVar38;
    if ((uVar38 + 0x20 < uVar38) || (uVar52 >> 0x20 != 0)) {
      FUN_fffffff009c48f64();
LAB_fffffff009c1dbb0:
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface: kIOSurfacePlaneHeaderRegionBytesPerSlice must be present for multi-slice plane %d with sliceCount %d .\n"
                );
      lVar43 = 0;
      goto LAB_fffffff009c1b2a8;
    }
    if (uVar52 < 0x20) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f28();
    }
    FUN_fffffff009c1ff50(param_2,"IOSurfacePlaneExtendedPixelsOnLeft",uVar38 + 8);
    FUN_fffffff009c1ff50(param_2,"IOSurfacePlaneExtendedPixelsOnRight",uVar38);
    FUN_fffffff009c1ff50(param_2,"IOSurfacePlaneExtendedPixelsOnBottom",uVar38 + 4);
    FUN_fffffff009c1ff50(param_2,"IOSurfacePlaneExtendedPixelsOnTop",uVar38 + 0xc);
  }
  else {
    uVar36 = (**(code **)(*plVar39 + 0x90))();
    *(uint *)(param_1 + 0x98) = uVar36;
    if (uVar36 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface::::parse_properties() kIOSurfacePlaneInfo array must not be empty.\n");
      lVar43 = 0;
      goto LAB_fffffff009c1b2a8;
    }
    *(ulong *)(param_1 + 0x328) = (ulong)uVar36;
    lVar40 = thunk_EXT_FUN_80110000038fe5cc(((ulong)uVar36 * 2 + (ulong)uVar36) * 8);
    if (*(ulong *)(param_1 + 0x328) >> 0x20 != 0) {
      FUN_fffffff009c48fa8();
LAB_fffffff009c1d28c:
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface: compressed plane[%d] extended left is not supported for compressed iosurfaces\n"
                );
      lVar43 = 0;
      goto LAB_fffffff009c1b2a8;
    }
    *(long *)(param_1 + 0x318) = lVar40;
    *(int *)(param_1 + 800) = (int)*(ulong *)(param_1 + 0x328);
    lVar43 = 0;
    if (lVar40 == 0) goto LAB_fffffff009c1b2a8;
    *(ulong *)(param_1 + 0x348) = (ulong)*(uint *)(param_1 + 0x98) << 5;
    lVar40 = thunk_EXT_FUN_80110000038fe5cc();
    uVar36 = *(uint *)(param_1 + 0x98);
    *(long *)(param_1 + 0x350) = lVar40;
    *(uint *)(param_1 + 0x358) = uVar36;
    lVar43 = 0;
    if (lVar40 == 0) goto LAB_fffffff009c1b2a8;
    if (uVar36 < 4) {
      *(long *)(param_1 + 0x180) = param_1 + 0xa8;
      *(uint *)(param_1 + 0x188) = uVar36;
    }
    else {
      if (0x14 < uVar36) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "IOSurface: maximum plane count of %d exceeded.\n");
        lVar43 = 0;
        goto LAB_fffffff009c1b2a8;
      }
      lVar40 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff00806bcf0,(ulong)uVar36 * 0x38);
      uVar36 = *(uint *)(param_1 + 0x98);
      *(long *)(param_1 + 0x180) = lVar40;
      *(uint *)(param_1 + 0x188) = uVar36;
      lVar43 = 0;
      if (lVar40 == 0) goto LAB_fffffff009c1b2a8;
    }
    lVar43 = lVar40;
    if (uVar36 != 0) {
      lVar40 = 0;
      uVar38 = 0;
      uVar61 = *(undefined8 *)PTR_DAT_fffffff00806c9c8;
      do {
        uVar49 = *(ulong *)(param_1 + 0x180);
        uVar52 = uVar49 + (ulong)*(uint *)(param_1 + 0x188) * 0x38;
        if (((uVar49 ^ uVar52) & 0xffc0000000000000) != 0) {
          uVar52 = uVar52 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar52 < uVar49) || (uVar52 - uVar49 >> 0x20 != 0)) {
          FUN_fffffff009c48f64(lVar43);
LAB_fffffff009c1db90:
          FUN_fffffff009c48f3c();
LAB_fffffff009c1db94:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if (uVar38 * 0x38 != (long)(int)(uVar38 * 0x38)) goto LAB_fffffff009c1db90;
        uVar50 = (uVar38 << 0x26) - (uVar38 << 0x23);
        if (((long)uVar50 < 0) || ((uint)(uVar52 - uVar49) < (int)(uVar50 >> 0x20) + 0x38U))
        goto LAB_fffffff009c1db94;
        puVar1 = (ulong *)(uVar49 + (uVar50 >> 0x20));
        uVar49 = (ulong)CARRY8(uVar49,uVar50 >> 0x20);
        uVar52 = -uVar49;
        if ((uVar52 != uVar49) || ((long)uVar52 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        uVar49 = *(ulong *)(param_1 + 0x350);
        uVar52 = uVar49 + (ulong)*(uint *)(param_1 + 0x358) * 0x20;
        if (((uVar49 ^ uVar52) & 0xffc0000000000000) != 0) {
          uVar52 = uVar52 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar52 < uVar49) || (uVar52 - uVar49 >> 0x20 != 0)) {
          FUN_fffffff009c48f64(lVar43);
LAB_fffffff009c1dba0:
          FUN_fffffff009c48f3c();
LAB_fffffff009c1dba4:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if (uVar38 * 0x20 - (long)(int)(uVar38 * 0x20) != 0) goto LAB_fffffff009c1dba0;
        if ((uVar38 & 0x7ffffff) >> 0x1a != 0) goto LAB_fffffff009c1dba4;
        uVar37 = (uint)uVar38;
        uVar36 = uVar37 * 0x20;
        if ((uint)(uVar52 - uVar49) < uVar36 + 0x20) goto LAB_fffffff009c1dba4;
        puVar2 = (uint *)(uVar49 + uVar36);
        uVar49 = (ulong)CARRY8(uVar49,(ulong)uVar36);
        uVar52 = -uVar49;
        if ((uVar52 != uVar49) || ((long)uVar52 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        puVar1[6] = 0;
        puVar1[3] = 0;
        puVar1[2] = 0;
        puVar1[5] = 0;
        puVar1[4] = 0;
        puVar1[1] = 0;
        *puVar1 = 0;
        uVar41 = (**(code **)(*plVar39 + 0x118))(plVar39,uVar38);
        lVar42 = thunk_EXT_FUN_8011000003890f30(uVar41,uVar61);
        lVar43 = 0;
        if (((((lVar42 == 0) ||
              (lVar43 = FUN_fffffff009c20038(lVar42,"IOSurfacePlaneWidth",puVar1), (int)lVar43 == 0)
              ) || (lVar43 = FUN_fffffff009c20038(lVar42,"IOSurfacePlaneHeight",puVar1 + 1),
                   (int)lVar43 == 0)) ||
            ((lVar43 = FUN_fffffff009c1ff50(lVar42,"IOSurfacePlaneExtendedPixelsOnLeft",puVar2 + 2),
             (int)lVar43 == 0 ||
             (lVar43 = FUN_fffffff009c1ff50(lVar42,"IOSurfacePlaneExtendedPixelsOnRight",puVar2),
             (int)lVar43 == 0)))) ||
           ((lVar43 = FUN_fffffff009c1ff50(lVar42,"IOSurfacePlaneExtendedPixelsOnTop",puVar2 + 3),
            (int)lVar43 == 0 ||
            (lVar43 = FUN_fffffff009c1ff50(lVar42,"IOSurfacePlaneExtendedPixelsOnBottom",puVar2 + 1)
            , (int)lVar43 == 0)))) goto LAB_fffffff009c1b2a8;
        iVar35 = FUN_fffffff009c20038(lVar42,"IOSurfacePlaneBytesPerElement",&local_78);
        if (iVar35 == 0) {
          iVar35 = FUN_fffffff009c20038(lVar42,"IOSurfacePlaneBitsPerElement",&local_78);
          if (iVar35 != 0) {
            if (local_78 < (undefined1 *)0x10000) {
LAB_fffffff009c1b6b0:
              puVar47 = (undefined1 *)((ulong)local_78 >> 3 & 0x1fffffff);
              *(short *)(puVar1 + 6) = (short)puVar47;
              puVar51 = local_78;
              goto LAB_fffffff009c1b6b8;
            }
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                       "IOSurface: kIOSurfacePlaneBitsPerElement out of range\n");
            lVar43 = 0;
            goto LAB_fffffff009c1b2a8;
          }
          iVar35 = FUN_fffffff009c20038(lVar42,"IOSurfacePlaneBitsPerBlock",&local_78);
          if (iVar35 != 0) {
            if (local_78 < (undefined1 *)0x10000) goto LAB_fffffff009c1b6b0;
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                       "IOSurface: kIOSurfacePlaneBitsPerBlock out of range\n");
            lVar43 = 0;
            goto LAB_fffffff009c1b2a8;
          }
          *(undefined2 *)(puVar1 + 6) = 1;
          puVar51 = (undefined1 *)0x8;
        }
        else {
          if ((undefined1 *)0x1fff < local_78) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                       "IOSurface: kIOSurfacePlaneBytesPerElement out of range\n");
            lVar43 = 0;
            goto LAB_fffffff009c1b2a8;
          }
          *(short *)(puVar1 + 6) = (short)local_78;
          puVar47 = local_78;
          puVar51 = (undefined1 *)((long)local_78 << 3);
LAB_fffffff009c1b6b8:
          if ((int)puVar47 == 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                       "IOSurface: plane[%d] bytes per element is zero.\n");
            lVar43 = 0;
            goto LAB_fffffff009c1b2a8;
          }
        }
        pbVar58 = (byte *)((long)puVar1 + 0x34);
        *pbVar58 = 1;
        lVar43 = FUN_fffffff009c20114(lVar42,"IOSurfacePlaneElementWidth",pbVar58);
        if ((int)lVar43 == 0) goto LAB_fffffff009c1b2a8;
        if (*pbVar58 == 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: plane[%d] element width is zero.\n");
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        pbVar57 = (byte *)((long)puVar1 + 0x35);
        *pbVar57 = 1;
        lVar43 = FUN_fffffff009c20114(lVar42,"IOSurfacePlaneElementHeight",pbVar57);
        if ((int)lVar43 == 0) goto LAB_fffffff009c1b2a8;
        if (*pbVar57 == 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: plane[%d] element height is zero.\n");
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        *(char *)((long)puVar1 + 0x36) = '\0';
        lVar43 = FUN_fffffff009c20114(lVar42,"IOSurfaceAddressFormat");
        if ((int)lVar43 == 0) goto LAB_fffffff009c1b2a8;
        uVar52 = *puVar1 + (ulong)*puVar2;
        uVar60 = (ulong)*(byte *)((long)puVar1 + 0x34);
        iVar35 = *(byte *)((long)puVar1 + 0x34) - 1;
        uVar46 = (ulong)iVar35;
        uVar50 = (long)uVar46 >> 0x3f;
        uVar49 = uVar50;
        if (CARRY8(uVar52,(long)iVar35)) {
          uVar49 = uVar50 + 1;
        }
        if (((CARRY8(*puVar1,(ulong)*puVar2)) || (-(uVar49 & 1) != uVar49)) ||
           ((long)-(uVar49 & 1) < 0)) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: plane[%d] extended width exceeds 64bit limit\n");
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        uVar36 = puVar2[2];
        if (CARRY8((ulong)uVar36,uVar46)) {
          uVar50 = uVar50 + 1;
        }
        uVar49 = uVar60;
        if ((uVar50 & 1) != 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: plane[%d] extended left exceeds 64bit limit\n");
          uVar49 = (ulong)*pbVar58;
        }
        uVar50 = 0;
        if (uVar60 != 0) {
          uVar50 = (uVar52 + (long)iVar35) / uVar60;
        }
        uVar52 = 0;
        if (uVar49 != 0) {
          uVar52 = (uVar36 + uVar46) / uVar49;
        }
        iVar35 = FUN_fffffff009c20038(lVar42,"IOSurfacePlaneBytesPerRow",&local_78);
        if (iVar35 == 0) {
          auVar9._8_8_ = 0;
          auVar9._0_8_ = uVar50;
          if (SUB168(auVar9 * ZEXT116(*pbVar58),8) != 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                       "IOSurface: plane[%d] calculated width in pixels exceeds 64bit limit\n");
            lVar43 = 0;
            goto LAB_fffffff009c1b2a8;
          }
          if (CARRY8(uVar50,uVar52)) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                       "IOSurface: plane[%d] total width in elements exceeds 64bit limit\n");
            lVar43 = 0;
            goto LAB_fffffff009c1b2a8;
          }
          uVar49 = CONCAT62(0,(ushort)puVar1[6]);
          auVar10._8_8_ = 0;
          auVar10._0_8_ = uVar50 + uVar52;
          auVar21._8_8_ = 0;
          auVar21._0_8_ = uVar49;
          if (SUB168(auVar10 * auVar21,8) != 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                       "IOSurface: plane[%d] bytesPerRow exceeds 64bit limit\n");
            lVar43 = 0;
            goto LAB_fffffff009c1b2a8;
          }
          uVar60 = (uVar50 + uVar52) * uVar49;
          uVar46 = (ulong)*(uint *)(DAT_fffffff00af483b0 + 0xb0);
          if (CARRY8(uVar60,uVar46)) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                       "IOSurface: plane[%d] calculated bytesPerRow exceeds 64bit limit\n");
            lVar43 = 0;
            goto LAB_fffffff009c1b2a8;
          }
          puVar47 = (undefined1 *)(uVar60 + uVar46 & (uVar46 ^ 0xffffffffffffffff));
          puVar1[4] = (ulong)puVar47;
        }
        else {
          puVar1[4] = (ulong)local_78;
          uVar49 = (ulong)(ushort)puVar1[6];
          puVar47 = local_78;
        }
        auVar11._8_8_ = 0;
        auVar11._0_8_ = uVar50;
        auVar22._8_8_ = 0;
        auVar22._0_8_ = uVar49;
        if (SUB168(auVar11 * auVar22,8) != 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: plane[%d] plane width in bytes exceeds 64bit limit\n");
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        auVar12._8_8_ = 0;
        auVar12._0_8_ = uVar52;
        auVar23._8_8_ = 0;
        auVar23._0_8_ = uVar49;
        if (SUB168(auVar12 * auVar23,8) != 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: plane[%d] minimum extended left bytes per row value exceeds 64bit limit\n"
                    );
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        if (CARRY8(uVar50 * uVar49,uVar52 * uVar49)) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: plane[%d] minimum bytes per row value exceeds 64bit limit\n");
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        if (puVar47 < (undefined1 *)(uVar50 * uVar49 + uVar52 * uVar49)) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: plane[%d] bytes per row value of %llu is too small\n");
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        uVar52 = puVar1[1] + (ulong)puVar2[1];
        bVar55 = *pbVar57;
        iVar35 = bVar55 - 1;
        uVar49 = (long)iVar35 >> 0x3f;
        if (CARRY8(uVar52,(long)iVar35)) {
          uVar49 = uVar49 + 1;
        }
        if (((CARRY8(puVar1[1],(ulong)puVar2[1])) || (-(uVar49 & 1) != uVar49)) ||
           ((long)-(uVar49 & 1) < 0)) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: plane[%d] extended height exceeds 64bit limit\n");
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        uVar49 = 0;
        if ((ulong)bVar55 != 0) {
          uVar49 = (uVar52 + (long)iVar35) / (ulong)bVar55;
        }
        iVar35 = FUN_fffffff009c20038(lVar42,"IOSurfacePlaneSize",&local_78);
        puVar47 = local_78;
        if (iVar35 == 0) {
          auVar13._8_8_ = 0;
          auVar13._0_8_ = puVar1[4];
          auVar24._8_8_ = 0;
          auVar24._0_8_ = uVar49;
          if (SUB168(auVar13 * auVar24,8) != 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                       "IOSurface: plane[%d] calculated size value exceeds 64bit limit\n");
            lVar43 = 0;
            goto LAB_fffffff009c1b2a8;
          }
          puVar47 = (undefined1 *)(puVar1[4] * uVar49);
        }
        puVar1[5] = (ulong)puVar47;
        if (puVar47 == (undefined1 *)0x0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: plane[%d] size is zero\n");
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        iVar35 = FUN_fffffff009c20038(lVar42,"IOSurfacePlaneOffset",&local_78);
        puVar47 = local_78;
        if (iVar35 == 0) {
          if (uVar37 != 0) {
            uVar46 = *(ulong *)(param_1 + 0x180);
            uVar52 = uVar46 + (ulong)*(uint *)(param_1 + 0x188) * 0x38;
            if (((uVar46 ^ uVar52) & 0xffc0000000000000) != 0) {
              uVar52 = uVar52 & 0xffffffffffff | 0xc8a2000000000000;
            }
            if ((uVar52 < uVar46) || (uVar52 - uVar46 >> 0x20 != 0)) {
              FUN_fffffff009c48f64();
            }
            else {
              uVar60 = (ulong)(uVar37 - 1);
              if (uVar60 * 0x38 == (long)(int)(uVar60 * 0x38)) {
                uVar60 = (uVar60 << 0x26) - (uVar60 << 0x23);
                if (((long)uVar60 < 0) || ((uint)(uVar52 - uVar46) < (int)(uVar60 >> 0x20) + 0x38U))
                goto LAB_fffffff009c1de0c;
                lVar43 = uVar46 + (uVar60 >> 0x20);
                uVar46 = (ulong)CARRY8(uVar46,uVar60 >> 0x20);
                uVar52 = -uVar46;
                if ((uVar52 != uVar46) || ((long)uVar52 < 0)) {
                    /* WARNING: Subroutine does not return */
                  FUN_fffffff009c48f50();
                }
                uVar60 = *(ulong *)(lVar43 + 0x10);
                uVar46 = *(ulong *)(lVar43 + 0x28);
                uVar52 = uVar60 + uVar46;
                uVar36 = *(uint *)(DAT_fffffff00af483b0 + 0xac);
                if ((!CARRY8(uVar60,uVar46)) && (!CARRY8((ulong)uVar36,uVar52))) {
                  puVar47 = (undefined1 *)(uVar36 + uVar52 & (ulong)~uVar36);
                  goto LAB_fffffff009c1ba18;
                }
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                           "IOSurface: plane[%d] calculated offset value exceeds 64bit limit\n");
                lVar43 = 0;
                goto LAB_fffffff009c1b2a8;
              }
            }
            FUN_fffffff009c48f3c();
LAB_fffffff009c1de0c:
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f28();
          }
          puVar47 = (undefined1 *)0x0;
        }
LAB_fffffff009c1ba18:
        ppuVar59 = (undefined1 **)(puVar1 + 3);
        *ppuVar59 = puVar47;
        iVar35 = FUN_fffffff009c20038(lVar42,"IOSurfacePlaneBase",&local_78);
        ppuVar5 = &local_78;
        if (iVar35 == 0) {
          ppuVar5 = ppuVar59;
        }
        puVar47 = *ppuVar5;
        puVar1[2] = (ulong)puVar47;
        if ((uVar37 != 0) && (*(long *)(param_1 + 0x378) == 0)) {
          uVar46 = *(ulong *)(param_1 + 0x180);
          uVar52 = uVar46 + (ulong)*(uint *)(param_1 + 0x188) * 0x38;
          if (((uVar46 ^ uVar52) & 0xffc0000000000000) != 0) {
            uVar52 = uVar52 & 0xffffffffffff | 0xc8a2000000000000;
          }
          if ((uVar52 < uVar46) || (uVar52 - uVar46 >> 0x20 != 0)) {
            FUN_fffffff009c48f64();
            goto LAB_fffffff009c1dd84;
          }
          uVar60 = 0;
          lVar43 = 0;
          do {
            if (lVar43 == -0x2492493) {
              FUN_fffffff009c48f3c();
LAB_fffffff009c1d3e0:
                    /* WARNING: Subroutine does not return */
              FUN_fffffff009c48f28();
            }
            if (((long)uVar60 < 0) || ((uint)(uVar52 - uVar46) < (int)(uVar60 >> 0x20) + 0x38U))
            goto LAB_fffffff009c1d3e0;
            lVar3 = uVar46 + (uVar60 >> 0x20);
            uVar54 = (ulong)CARRY8(uVar46,uVar60 >> 0x20);
            uVar53 = -uVar54;
            if ((uVar53 != uVar54) || ((long)uVar53 < 0)) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff009c48f50();
            }
            if (puVar47 < (undefined1 *)(*(long *)(lVar3 + 0x28) + *(long *)(lVar3 + 0x10))) {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                         "IOSurface: plane[%d] base %016llx overlaps with previous plane %d\n");
              lVar43 = 0;
              goto LAB_fffffff009c1b2a8;
            }
            lVar43 = lVar43 + -1;
            uVar60 = uVar60 + 0x3800000000;
          } while (lVar40 != lVar43);
        }
        if (*ppuVar59 < puVar47) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: plane[%d] offset %016llx is less than plane[%d] base %016llx\n");
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        if (CARRY8((ulong)puVar47,puVar1[5])) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: plane[%d] base %016llx plus plane size %016llx exceeds 64bit limit\n"
                    );
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        auVar14._8_8_ = 0;
        auVar14._0_8_ = puVar1[4];
        auVar25._8_8_ = 0;
        auVar25._0_8_ = uVar49 - 1;
        if (SUB168(auVar14 * auVar25,8) != 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: plane[%d] required size exceeds 64bit limit\n");
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        uVar52 = CONCAT62(0,(ushort)puVar1[6]);
        auVar15._8_8_ = 0;
        auVar15._0_8_ = uVar50;
        auVar26._8_8_ = 0;
        auVar26._0_8_ = uVar52;
        if (SUB168(auVar15 * auVar26,8) != 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: plane[%d] required size for one line exceeds 64bit limit\n");
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        uVar49 = puVar1[4] * (uVar49 - 1);
        uVar50 = uVar50 * uVar52;
        if (CARRY8(uVar49,uVar50)) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: plane[%d] total required size exceeds 64bit limit\n");
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        uVar46 = *(ulong *)(param_1 + 0x318);
        uVar52 = uVar46 + (ulong)*(uint *)(param_1 + 800) * 0x18;
        if (((uVar46 ^ uVar52) & 0xffc0000000000000) != 0) {
          uVar52 = uVar52 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar52 < uVar46) || (uVar52 - uVar46 >> 0x20 != 0)) {
          FUN_fffffff009c48f64();
LAB_fffffff009c1dd4c:
          FUN_fffffff009c48f3c();
LAB_fffffff009c1dd50:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if (uVar38 * 0x18 - (long)(int)(uVar38 * 0x18) != 0) goto LAB_fffffff009c1dd4c;
        if ((((ulong)(uVar37 * 3) & 0x1fffffff) >> 0x1c != 0) ||
           (uVar36 = uVar37 * 0x18, (uint)(uVar52 - uVar46) < uVar36 + 0x18))
        goto LAB_fffffff009c1dd50;
        lVar43 = uVar46 + uVar36;
        uVar46 = (ulong)CARRY8(uVar46,(ulong)uVar36);
        uVar52 = -uVar46;
        if ((uVar52 != uVar46) || ((long)uVar52 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50(lVar43);
        }
        uVar52 = FUN_fffffff009c201c4(lVar43,lVar42);
        if ((uVar52 & 1) == 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: plane[%d] parseAdditionalPlaneInfo failed.\n");
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        lVar43 = FUN_fffffff009c20038(lVar42,"IOSurfacePlaneCompressionType",&local_78);
        puVar47 = local_78;
        if ((int)lVar43 != 0) {
          if ((long)local_78 < 2) {
            if (local_78 == (undefined1 *)0x0) {
              if (*(char *)((long)puVar1 + 0x36) != '\x05') goto LAB_fffffff009c1bc70;
              bVar32 = false;
              bVar33 = false;
              bVar55 = 0;
              bVar34 = 0;
            }
            else {
              if (local_78 != (undefined1 *)0x1) {
LAB_fffffff009c1d744:
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                           "IOSurface: plane[%d] illegal compression type: %lld\n");
                lVar43 = 0;
                goto LAB_fffffff009c1b2a8;
              }
              bVar33 = false;
              bVar55 = 0;
              bVar34 = 0;
              bVar32 = true;
            }
          }
          else if (local_78 == (undefined1 *)0x4) {
            bVar32 = false;
            bVar33 = false;
            bVar55 = 0;
            bVar34 = 1;
          }
          else if (local_78 == (undefined1 *)0x3) {
            bVar32 = false;
            bVar33 = false;
            bVar34 = 0;
            bVar55 = 1;
          }
          else {
            if (local_78 != (undefined1 *)0x2) goto LAB_fffffff009c1d744;
            bVar32 = false;
            bVar55 = 0;
            bVar34 = 0;
            bVar33 = true;
          }
          uVar52 = *(ulong *)(param_1 + 0x308);
          if (uVar52 == 0) {
            uVar52 = thunk_EXT_FUN_80110000038fe5cc((ulong)*(uint *)(param_1 + 0x98) * 0x3c);
            uVar36 = *(uint *)(param_1 + 0x98);
            *(ulong *)(param_1 + 0x308) = uVar52;
            *(uint *)(param_1 + 0x310) = uVar36;
            lVar43 = 0;
            if (uVar52 == 0) goto LAB_fffffff009c1b2a8;
          }
          else {
            uVar36 = *(uint *)(param_1 + 0x310);
          }
          uVar49 = uVar52 + (ulong)uVar36 * 0x3c;
          if (((uVar52 ^ uVar49) & 0xffc0000000000000) != 0) {
            uVar49 = uVar49 & 0xffffffffffff | 0xc8a2000000000000;
          }
          if ((uVar49 < uVar52) || (uVar49 - uVar52 >> 0x20 != 0)) {
            FUN_fffffff009c48f64();
          }
          else if (uVar38 * 0x3c == (long)(int)(uVar38 * 0x3c)) {
            uVar50 = (uVar38 << 0x26) - (uVar38 << 0x22);
            if ((long)uVar50 < 0) goto LAB_fffffff009c1de1c;
            uVar46 = uVar50 >> 0x20;
            uVar36 = (int)(uVar50 >> 0x20) + 0x3c;
            if ((uint)(uVar49 - uVar52) < uVar36) goto LAB_fffffff009c1de1c;
            uVar49 = -(ulong)CARRY8(uVar52,uVar46);
            if ((uVar49 != CARRY8(uVar52,uVar46)) || ((long)uVar49 < 0)) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff009c48f50();
            }
            *(char *)(uVar52 + uVar46 + 0x20) = (char)puVar47;
            local_88 = 0;
            if ((bVar32 || bVar33) ||
               (iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceSliceCount",&local_88), iVar35 == 0)
               ) {
              uVar52 = 1;
            }
            else {
              uVar52 = local_88;
              if (local_88 - 0x100000000 < 0xffffffff00000002) {
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                           "IOSurface: sliceCount provided %d is out of bound for maximum / minimum number of required slices.\n"
                          );
                lVar43 = 0;
                goto LAB_fffffff009c1b2a8;
              }
            }
            *(int *)(param_1 + 0x3b8) = (int)uVar52;
            uVar49 = *(ulong *)(param_1 + 0x308);
            uVar52 = uVar49 + (ulong)*(uint *)(param_1 + 0x310) * 0x3c;
            if (((uVar49 ^ uVar52) & 0xffc0000000000000) != 0) {
              uVar52 = uVar52 & 0xffffffffffff | 0xc8a2000000000000;
            }
            if ((uVar52 < uVar49) || (uVar52 - uVar49 >> 0x20 != 0)) {
              FUN_fffffff009c48f64();
LAB_fffffff009c1de28:
                    /* WARNING: Subroutine does not return */
              FUN_fffffff009c48f28();
            }
            if ((uint)(uVar52 - uVar49) < uVar36) goto LAB_fffffff009c1de28;
            puVar4 = (uint *)(uVar49 + uVar46);
            uVar52 = -(ulong)CARRY8(uVar49,uVar46);
            if ((uVar52 != CARRY8(uVar49,uVar46)) || ((long)uVar52 < 0)) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff009c48f50();
            }
            if (bVar32) {
              iVar35 = FUN_fffffff009c20038(lVar42,"IOSurfacePlaneHTPCPredictionSelector",&local_78)
              ;
              if (iVar35 == 0) {
                *(undefined1 *)((long)puVar4 + 0x21) = 0;
              }
              else {
                if ((undefined1 *)0xff < local_78) goto LAB_fffffff009c1d63c;
                *(char *)((long)puVar4 + 0x21) = (char)local_78;
                if ((undefined1 *)0x1 < local_78) {
                  thunk_EXT_FUN_80110000038db19c
                            (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                             "IOSurface: compressed plane[%d] HTPCPredictionSelector must be in range\n"
                            );
                  lVar43 = 0;
                  goto LAB_fffffff009c1b2a8;
                }
              }
            }
            iVar35 = FUN_fffffff009c20038
                               (lVar42,"IOSurfacePlaneBytesPerCompressedTileHeader",&local_78);
            if (iVar35 != 0) {
              if ((ulong)local_78 >> 0x20 != 0) goto LAB_fffffff009c1d63c;
              puVar4[4] = (uint)local_78;
            }
            uVar36 = puVar4[4];
            if (bVar32) {
              if ((uVar36 != 4) && (uVar36 != 8)) {
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                           "IOSurface: HTPC compressed plane[%d] Tile header must be 32-bit or 64-bit\n"
                          );
                lVar43 = 0;
                goto LAB_fffffff009c1b2a8;
              }
            }
            else if ((0x20 < uVar36) || ((1L << ((ulong)uVar36 & 0x3f) & 0x100000104U) == 0)) {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                         "IOSurface: AGX BytesPerCompressedTileHeader of plane[%d] must be 2 or 8 or 32\n"
                        );
              lVar43 = 0;
              goto LAB_fffffff009c1b2a8;
            }
            if (((bool)(bVar55 | bVar34)) &&
               (iVar35 = FUN_fffffff009c20038(lVar42,"IOSurfacePlaneCompressionFootprint",&local_78)
               , iVar35 != 0)) {
              if ((undefined1 *)0x3 < local_78) {
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                           "IOSurface: plane[%d] illegal compression footprint for type kIOSurfaceCompressionTypeInterchangeLossy %lld \n"
                          );
                lVar43 = 0;
                goto LAB_fffffff009c1b2a8;
              }
              *(char *)(puVar4 + 10) = (char)local_78;
            }
            iVar35 = FUN_fffffff009c20038(lVar42,"IOSurfacePlaneCompressedTileWidth",&local_78);
            if (iVar35 == 0) {
              puVar47 = (undefined1 *)(ulong)*puVar4;
            }
            else {
              if ((ulong)local_78 >> 0x20 != 0) goto LAB_fffffff009c1d63c;
              *puVar4 = (uint)local_78;
              puVar47 = local_78;
            }
            uVar36 = (uint)puVar47;
            if (uVar36 == 0) {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                         "IOSurface: compressed plane[%d] CompressedTileWidth must be at least 1\n")
              ;
              lVar43 = 0;
            }
            else if ((uVar36 & uVar36 - 1) == 0) {
              if (uVar36 < 0x400) {
                if (*puVar1 + ((ulong)puVar47 & 0xffffffff) >> 0x20 == 0) {
                  uVar52 = FUN_fffffff009c20038
                                     (lVar42,"IOSurfacePlaneCompressedTileHeight",&local_78);
                  if ((uVar52 & 1) == 0) {
                    puVar47 = (undefined1 *)(ulong)puVar4[1];
                  }
                  else {
                    if ((ulong)local_78 >> 0x20 != 0) goto LAB_fffffff009c1d63c;
                    puVar4[1] = (uint)local_78;
                    puVar47 = local_78;
                  }
                  if (puVar47 == (undefined1 *)0x0) {
                    thunk_EXT_FUN_80110000038db19c
                              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                               "IOSurface: compressed plane[%d] CompressedTileHeight must be at least 1\n"
                              );
                    lVar43 = 0;
                  }
                  else if (puVar47 < (undefined1 *)0x400) {
                    if (((ulong)(puVar47 + 0x3ff) & (ulong)puVar47) == 0) {
                      if ((ulong)(puVar47 + (ulong)puVar4[4] + puVar1[1]) >> 0x20 == 0) {
                        uVar52 = FUN_fffffff009c20038
                                           (lVar42,
                                            "IOSurfacePlaneHorizontalPixelOffsetWithinCompressedTileArray"
                                            ,&local_78);
                        if ((uVar52 & 1) == 0) {
                          puVar47 = (undefined1 *)(ulong)(ushort)puVar4[9];
                        }
                        else {
                          if ((ulong)local_78 >> 0x10 != 0) goto LAB_fffffff009c1d63c;
                          *(short *)(puVar4 + 9) = (short)local_78;
                          puVar47 = local_78;
                        }
                        if (*puVar4 < (uint)puVar47) {
                          thunk_EXT_FUN_80110000038db19c
                                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                     "IOSurface: compressed plane[%d] kIOSurfacePlaneHorizontalPixelOffsetWithinCompressedTileArray is more than a kIOSurfacePlaneCompressedTileWidth.\n"
                                    );
                          lVar43 = 0;
                        }
                        else {
                          uVar52 = FUN_fffffff009c20038
                                             (lVar42,
                                              "IOSurfacePlaneVerticalPixelOffsetWithinCompressedTileArray"
                                              ,&local_78);
                          if ((uVar52 & 1) == 0) {
                            puVar47 = (undefined1 *)(ulong)*(ushort *)((long)puVar4 + 0x26);
                          }
                          else {
                            if ((ulong)local_78 >> 0x10 != 0) goto LAB_fffffff009c1d63c;
                            *(short *)((long)puVar4 + 0x26) = (short)local_78;
                            puVar47 = local_78;
                          }
                          if ((uint)puVar47 <= puVar4[1]) {
                            iVar35 = FUN_fffffff009c20038
                                               (lVar42,"IOSurfacePlaneBytesPerTileData",&local_78);
                            if (iVar35 != 0) {
                              if ((ulong)local_78 >> 0x20 != 0) goto LAB_fffffff009c1d63c;
                              puVar4[0xb] = (uint)local_78;
                            }
                            if (bVar32) {
                              local_88 = 0;
                              iVar35 = FUN_fffffff009c20038
                                                 (lVar42,
                                                  "IOSurfacePlaneHTPCVerticalHeaderGroupingMode",
                                                  &local_88);
                              if ((iVar35 != 0) && (0xff < local_88)) goto LAB_fffffff009c1d63c;
                              *(char *)((long)puVar4 + 0x22) = (char)local_88;
                              if ((local_88 & 0xfc) != 0) {
                                thunk_EXT_FUN_80110000038db19c
                                          (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                           "IOSurface: compressed plane[%d] HTPCVerticalHeaderGroupingMode must be in range\n"
                                          );
                                goto LAB_fffffff009c1d63c;
                              }
                              uVar36 = 1 << (ulong)((uint)local_88 & 0x1f);
                            }
                            else {
                              *(undefined1 *)((long)puVar4 + 0x22) = 0;
                              uVar36 = 1;
                            }
                            iVar35 = FUN_fffffff009c20038
                                               (lVar42,"IOSurfacePlaneWidthInCompressedTiles",
                                                &local_78);
                            if (iVar35 != 0) {
                              if ((ulong)local_78 >> 0x20 != 0) goto LAB_fffffff009c1d63c;
                              puVar4[5] = (uint)local_78;
                            }
                            if (puVar2[2] != 0) goto LAB_fffffff009c1d28c;
                            if (puVar2[3] == 0) {
                              uVar7 = (ushort)puVar4[9];
                              uVar56 = *puVar2;
                              uVar45 = uVar7 + uVar56;
                              uVar52 = (ulong)*puVar4;
                              uVar8 = *puVar4 - 1;
                              if ((CARRY4((uint)uVar7,uVar56)) || (CARRY4(uVar8,uVar45))) {
                                thunk_EXT_FUN_80110000038db19c
                                          (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                           "IOSurface: compressed plane[%d] extra width calculation overflow\n"
                                          );
                                lVar43 = 0;
                              }
                              else {
                                uVar50 = *puVar1;
                                uVar49 = (ulong)(uVar8 + uVar45);
                                if (CARRY8(uVar50,uVar49)) {
                                  thunk_EXT_FUN_80110000038db19c
                                            (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                             "IOSurface: compressed plane[%d] full width calculation overflow\n"
                                            );
                                  lVar43 = 0;
                                }
                                else {
                                  uVar60 = (ulong)puVar4[5];
                                  uVar46 = 0;
                                  if (uVar52 != 0) {
                                    uVar46 = (uVar50 + uVar49) / uVar52;
                                  }
                                  if (uVar46 == uVar60) {
                                    if (CARRY8(uVar50,(ulong)uVar56)) {
                                      thunk_EXT_FUN_80110000038db19c
                                                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                                 "IOSurface: compressed plane[%d] extended width calculation overflow\n"
                                                );
                                      uVar52 = (ulong)*puVar4;
                                      uVar60 = (ulong)puVar4[5];
                                      uVar7 = (ushort)puVar4[9];
                                    }
                                    uVar49 = (ulong)uVar7;
                                    uVar60 = uVar60 * uVar52;
                                    if (uVar60 < uVar49 || uVar60 - uVar49 == 0) {
                                      thunk_EXT_FUN_80110000038db19c
                                                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                                 "IOSurface: compressed plane[%d] planeHorizontalPixelOffsetWithinCompressedTile exceeds compressedPlaneBytesPerTileRow\n"
                                                );
                                      uVar49 = (ulong)(ushort)puVar4[9];
                                    }
                                    if (uVar60 - uVar49 < uVar50 + uVar56) {
                                      thunk_EXT_FUN_80110000038db19c
                                                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                                 "IOSurface: compressed plane[%d] Plane width must fit into tiles\n"
                                                );
                                      lVar43 = 0;
                                      goto LAB_fffffff009c1b2a8;
                                    }
                                    iVar35 = FUN_fffffff009c20038
                                                       (lVar42,"IOSurfacePlaneBytesPerRowOfTileData"
                                                        ,&local_78);
                                    if (iVar35 != 0) {
                                      if ((ulong)local_78 >> 0x20 != 0) goto LAB_fffffff009c1d63c;
                                      if ((puVar4[0xb] != 0) &&
                                         (local_78 != (undefined1 *)(ulong)(puVar4[5] * puVar4[0xb])
                                         )) {
                                        thunk_EXT_FUN_80110000038db19c
                                                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                                                                                      
                                                  "IOSurface: compressed plane[%d] kIOSurfacePlaneBytesPerRowOfTileData is %d less than WidthInCompressedTiles %d x BytesPerTileData %d Bytes.\n"
                                                  );
                                        lVar43 = 0;
                                        goto LAB_fffffff009c1b2a8;
                                      }
                                      puVar4[0xc] = (uint)local_78;
                                    }
                                    iVar35 = FUN_fffffff009c20038
                                                       (lVar42,
                                                  "IOSurfacePlaneHeightInCompressedTiles",&local_78)
                                    ;
                                    if (iVar35 != 0) {
                                      if ((ulong)local_78 >> 0x20 != 0) goto LAB_fffffff009c1d63c;
                                      puVar4[6] = (uint)local_78;
                                    }
                                    uVar52 = puVar1[1] + (ulong)puVar2[1];
                                    uVar49 = *(ushort *)((long)puVar4 + 0x26) + uVar52;
                                    if ((CARRY8(puVar1[1],(ulong)puVar2[1])) ||
                                       (CARRY8((ulong)*(ushort *)((long)puVar4 + 0x26),uVar52))) {
                                      thunk_EXT_FUN_80110000038db19c
                                                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                                 "IOSurface: compressed plane[%d] extendedHeight overflow\n"
                                                );
                                    }
                                    uVar45 = puVar4[1];
                                    uVar56 = uVar45 - 1;
                                    if (CARRY8(uVar49,(ulong)uVar56)) {
                                      thunk_EXT_FUN_80110000038db19c
                                                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                                 "IOSurface: compressed plane[%d] roundedExtendedHeight overflow\n"
                                                );
                                      uVar45 = puVar4[1];
                                    }
                                    uVar50 = (ulong)uVar45;
                                    uVar52 = 0;
                                    if (uVar50 != 0) {
                                      uVar52 = (uVar49 + uVar56) / uVar50;
                                    }
                                    if (uVar52 + uVar36 < 0xffffffff) {
                                      uVar45 = puVar4[6];
                                      if (uVar45 < ((int)(uVar52 + uVar36) - 1U & -uVar36)) {
                                        thunk_EXT_FUN_80110000038db19c
                                                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                                                                                      
                                                  "IOSurface: compressed plane[%d] CompressedTileHeaderRegionHeight must exactly cover the height in tiles\n"
                                                  );
                                        lVar43 = 0;
                                      }
                                      else if ((uVar45 & uVar36 - 1) == 0) {
                                        if (uVar45 * uVar50 -
                                            (ulong)*(ushort *)((long)puVar4 + 0x26) < puVar1[1]) {
                                          thunk_EXT_FUN_80110000038db19c
                                                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                                                                                          
                                                  "IOSurface: compressed plane[%d] Plane height must fit into tiles\n"
                                                  );
                                          lVar43 = 0;
                                        }
                                        else {
                                          iVar35 = FUN_fffffff009c20038
                                                             (lVar42,
                                                  "IOSurfacePlaneBytesPerRowOfCompressedTileHeaderGroups"
                                                  ,&local_78);
                                          if (iVar35 != 0) {
                                            if ((ulong)local_78 >> 0x20 != 0)
                                            goto LAB_fffffff009c1d63c;
                                            puVar4[7] = (uint)local_78;
                                          }
                                          uVar52 = (ulong)puVar4[5] *
                                                   (ulong)(puVar4[4] <<
                                                          (ulong)(*(byte *)((long)puVar4 + 0x22) &
                                                                 0x1f));
                                          if (uVar52 >> 0x20 == 0) {
                                            if ((!bVar32) ||
                                               (uVar52 < puVar4[7] || uVar52 - puVar4[7] == 0)) {
                                              lVar43 = FUN_fffffff009c20288
                                                                 (lVar42,
                                                  "IOSurfacePlaneCompressedTileHeaderRegionOffset",
                                                  puVar4 + 2);
                                              if (((int)lVar43 == 0) ||
                                                 (lVar43 = FUN_fffffff009c20288
                                                                     (lVar42,
                                                  "IOSurfacePlaneCompressedTileDataRegionOffset",
                                                  puVar4 + 3), (int)lVar43 == 0))
                                              goto LAB_fffffff009c1b2a8;
                                              uVar36 = puVar4[7];
                                              uVar45 = puVar4[6] >>
                                                       (ulong)(*(byte *)((long)puVar4 + 0x22) & 0x1f
                                                              );
                                              if (puVar1[5] + puVar1[2] <
                                                  (ulong)puVar4[2] + (ulong)uVar36 * (ulong)uVar45)
                                              goto LAB_fffffff009c1d4d8;
                                              uVar52 = (ulong)puVar4[0xb];
                                              if (puVar4[0xb] == 0) {
                                                uVar52 = ((ulong)puVar51 & 0xffff) * (ulong)*puVar4
                                                         * (ulong)puVar4[1] + 7;
                                                if (uVar52 >> 0x23 != 0) {
                                                  thunk_EXT_FUN_80110000038db19c
                                                            (&MACH_HEADER,PTR_DAT_fffffff00806ca48,
                                                             0x10,
                                                  "IOSurface: compressed plane[%d] uncompressedTileSize doesn\'t fit in 32 bits\n"
                                                  );
                                                  lVar43 = 0;
                                                  goto LAB_fffffff009c1b2a8;
                                                }
                                                uVar52 = uVar52 >> 3;
                                              }
                                              uVar49 = (ulong)puVar4[0xc];
                                              if ((puVar4[0xc] == 0) &&
                                                 (uVar49 = uVar52 * puVar4[5], uVar49 >> 0x20 != 0))
                                              {
                                                thunk_EXT_FUN_80110000038db19c
                                                          (&MACH_HEADER,PTR_DAT_fffffff00806ca48,
                                                           0x10,
                                                  "IOSurface: compressed plane[%d] rowOfUncompressedTiles doesn\'t fit in 32 bits\n"
                                                  );
                                                lVar43 = 0;
                                                goto LAB_fffffff009c1b2a8;
                                              }
                                              uVar49 = uVar49 * puVar4[6];
                                              if (uVar49 >> 0x20 != 0) {
                                                thunk_EXT_FUN_80110000038db19c
                                                          (&MACH_HEADER,PTR_DAT_fffffff00806ca48,
                                                           0x10,
                                                  "IOSurface: compressed plane[%d] dataRegionTotalSize doesn\'t fit in 32 bits\n"
                                                  );
                                                lVar43 = 0;
                                                goto LAB_fffffff009c1b2a8;
                                              }
                                              if (puVar1[5] + puVar1[2] <
                                                  (ulong)puVar4[3] +
                                                  uVar49 * *(uint *)(param_1 + 0x3b8)) {
                                                thunk_EXT_FUN_80110000038db19c
                                                          (&MACH_HEADER,PTR_DAT_fffffff00806ca48,
                                                           0x10,
                                                  "IOSurface: compressed plane[%d] Data region doesn\'t fit into plane size\n"
                                                  );
                                                lVar43 = 0;
                                                goto LAB_fffffff009c1b2a8;
                                              }
                                              if (1 < *(uint *)(param_1 + 0x3b8)) {
                                                lVar43 = FUN_fffffff009c20038
                                                                   (lVar42,
                                                  "IOSurfacePlaneDataRegionBytesPerSlice",&local_78)
                                                ;
                                                if ((int)lVar43 == 0) {
                                                  thunk_EXT_FUN_80110000038db19c
                                                            (&MACH_HEADER,PTR_DAT_fffffff00806ca48,
                                                             0x10,
                                                  "IOSurface: kIOSurfacePlaneDataRegionBytesPerSlice must be present for multi-slice plane %d with sliceCount %d .\n"
                                                  );
                                                  lVar43 = 0;
                                                  goto LAB_fffffff009c1b2a8;
                                                }
                                                if ((ulong)local_78 >> 0x20 != 0) {
                                                  thunk_EXT_FUN_80110000038db19c
                                                            (&MACH_HEADER,PTR_DAT_fffffff00806ca48,
                                                             0x10,
                                                  "IOSurface: kIOSurfacePlaneDataRegionBytesPerSlice %d exceeds maximum value.\n"
                                                  );
                                                  lVar43 = 0;
                                                  goto LAB_fffffff009c1b2a8;
                                                }
                                                if (local_78 <
                                                    (undefined1 *)
                                                    (ulong)(puVar4[6] * puVar4[5] * puVar4[0xb])) {
                                                  thunk_EXT_FUN_80110000038db19c
                                                            (&MACH_HEADER,PTR_DAT_fffffff00806ca48,
                                                             0x10,
                                                  "IOSurface: kIOSurfacePlaneDataRegionBytesPerSlice %d is smaller than expected value %d .\n"
                                                  );
                                                  lVar43 = 0;
                                                  goto LAB_fffffff009c1b2a8;
                                                }
                                                puVar4[0xd] = (uint)local_78;
                                              }
                                              puVar47 = (undefined1 *)
                                                        ((ulong)uVar36 * (ulong)uVar45);
                                              if (bVar32) {
                                                if ((undefined1 *)(ulong)puVar4[3] <
                                                    puVar47 + puVar4[2]) {
                                                  thunk_EXT_FUN_80110000038db19c
                                                            (&MACH_HEADER,PTR_DAT_fffffff00806ca48,
                                                             0x10,
                                                  "IOSurface: HTPC compressed plane[%d] Header region overlaps data region\n"
                                                  );
                                                  lVar43 = 0;
                                                  goto LAB_fffffff009c1b2a8;
                                                }
                                              }
                                              else {
                                                if ((ulong)puVar4[2] <
                                                    (ulong)puVar4[3] +
                                                    uVar49 * *(uint *)(param_1 + 0x3b8)) {
                                                  thunk_EXT_FUN_80110000038db19c
                                                            (&MACH_HEADER,PTR_DAT_fffffff00806ca48,
                                                             0x10,
                                                  "IOSurface: compressed plane[%d] Data region overlaps header region\n"
                                                  );
                                                  lVar43 = 0;
                                                  goto LAB_fffffff009c1b2a8;
                                                }
                                                lVar43 = lVar42;
                                                if (1 < *(uint *)(param_1 + 0x3b8)) {
                                                  lVar43 = FUN_fffffff009c20038
                                                                     (lVar42,
                                                  "IOSurfacePlaneHeaderRegionBytesPerSlice",
                                                  &local_78);
                                                  if ((int)lVar43 == 0) goto LAB_fffffff009c1dbb0;
                                                  if ((ulong)local_78 >> 0x20 != 0) {
                                                    thunk_EXT_FUN_80110000038db19c
                                                              (&MACH_HEADER,PTR_DAT_fffffff00806ca48
                                                               ,0x10,
                                                  "IOSurface: kIOSurfacePlaneHeaderRegionBytesPerSlice %d exeeds maximum value.\n"
                                                  );
                                                  lVar43 = 0;
                                                  goto LAB_fffffff009c1b2a8;
                                                  }
                                                  if (local_78 < puVar47) {
                                                    thunk_EXT_FUN_80110000038db19c
                                                              (&MACH_HEADER,PTR_DAT_fffffff00806ca48
                                                               ,0x10,
                                                  "IOSurface: kIOSurfacePlaneHeaderRegionBytesPerSlice %d is smaller than expected value %d .\n"
                                                  );
                                                  lVar43 = 0;
                                                  goto LAB_fffffff009c1b2a8;
                                                  }
                                                  puVar4[0xe] = (uint)local_78;
                                                  if (puVar1[5] <
                                                      (ulong)((puVar4[0xd] + (uint)local_78) *
                                                             *(int *)(param_1 + 0x3b8))) {
                                                    thunk_EXT_FUN_80110000038db19c
                                                              (&MACH_HEADER,PTR_DAT_fffffff00806ca48
                                                               ,0x10,
                                                  "IOSurface: multi-slice interchange compressed plane[%d] (DataRegionBytesPerSlice %d + HeaderRegionBytesPerSlice %d) * sliceCount %d size is greater than total planeSize %lld\n"
                                                  );
                                                  lVar43 = 0;
                                                  goto LAB_fffffff009c1b2a8;
                                                  }
                                                }
                                              }
                                              if (uVar37 < 5) {
                                                lVar42 = uVar38 * 4;
                                                puVar6 = (undefined4 *)
                                                         (*plVar44 + 0xb8 + (long)(int)lVar42);
                                                if (lVar42 - (int)lVar42 != 0) {
                                                  puVar6 = (undefined4 *)
                                                           (*plVar44 + 0xb8 + lVar42 &
                                                            0xffffffffffffU | 0x2bad000000000000);
                                                }
                                                *puVar6 = (int)uVar49;
                                              }
                                              goto LAB_fffffff009c1c578;
                                            }
                                            thunk_EXT_FUN_80110000038db19c
                                                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                                                                                              
                                                  "IOSurface: compressed plane[%d] BytesPerRowOfCompressedTileHeaderGroups needs to be enough for a row of groups of tiles at this width\n"
                                                  );
                                            lVar43 = 0;
                                          }
                                          else {
                                            thunk_EXT_FUN_80110000038db19c
                                                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                                                                                              
                                                  "IOSurface: compressed plane[%d] bytesPerCompressedTileHeaderGroup * planeWidthInCompressedTiles doesn\'t fit in 32 bits\n"
                                                  );
                                            lVar43 = 0;
                                          }
                                        }
                                      }
                                      else {
                                        thunk_EXT_FUN_80110000038db19c
                                                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                                                                                      
                                                  "IOSurface: compressed plane[%d] Header region height must fit header group\n"
                                                  );
                                        lVar43 = 0;
                                      }
                                    }
                                    else {
                                      thunk_EXT_FUN_80110000038db19c
                                                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                                 "IOSurface: compressed plane[%d] tilesToCoverHeight + headersInGroup doesn\'t fit in 32 bits\n"
                                                );
                                      lVar43 = 0;
                                    }
                                    goto LAB_fffffff009c1b2a8;
                                  }
                                  thunk_EXT_FUN_80110000038db19c
                                            (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                             "IOSurface: compressed plane[%d] CompressedTileHeaderRegionWidth must exactly cover the width in tiles\n"
                                            );
                                  lVar43 = 0;
                                }
                              }
                            }
                            else {
                              thunk_EXT_FUN_80110000038db19c
                                        (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                         "IOSurface: compressed plane[%d] extended top is not supported for compressed iosurfaces\n"
                                        );
                              lVar43 = 0;
                            }
                            goto LAB_fffffff009c1b2a8;
                          }
                          thunk_EXT_FUN_80110000038db19c
                                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                     "IOSurface: compressed plane[%d] kIOSurfacePlaneVerticalPixelOffsetWithinCompressedTileArray is more than a kIOSurfacePlaneCompressedTileHeight.\n"
                                    );
                          lVar43 = 0;
                        }
                      }
                      else {
                        thunk_EXT_FUN_80110000038db19c
                                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                   "IOSurface: compressed plane[%d] Height + CompressedTileHeight doesn\'t fit in 32 bits\n"
                                  );
                        lVar43 = 0;
                      }
                    }
                    else {
                      thunk_EXT_FUN_80110000038db19c
                                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                                 "IOSurface: compressed plane[%d] CompressedTileHeight must be power of 2\n"
                                );
                      lVar43 = 0;
                    }
                  }
                  else {
                    thunk_EXT_FUN_80110000038db19c
                              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                               "IOSurface: compressed plane[%d] CompressedTileHeight must be less than 1024\n"
                              );
                    lVar43 = 0;
                  }
                }
                else {
                  thunk_EXT_FUN_80110000038db19c
                            (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                             "IOSurface: compressed plane[%d] Width + CompressedTileWidth doesn\'t fit in 32 bits\n"
                            );
                  lVar43 = 0;
                }
              }
              else {
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                           "IOSurface: compressed plane[%d] CompressedTileWidth must be less than 1024\n"
                          );
                lVar43 = 0;
              }
            }
            else {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                         "IOSurface: compressed plane[%d] CompressedTileWidth must be power of 2\n")
              ;
              lVar43 = 0;
            }
            goto LAB_fffffff009c1b2a8;
          }
          FUN_fffffff009c48f3c();
LAB_fffffff009c1de1c:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
LAB_fffffff009c1bc70:
        uVar38 = puVar1[3] + uVar49 + uVar50;
        if (*(long *)(param_1 + 0x378) == 0) {
          if (puVar1[5] + puVar1[2] < uVar38) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                       "IOSurface: plane[%d] Image data doesn\'t fit within allocated plane size\n")
            ;
            lVar43 = 0;
            goto LAB_fffffff009c1b2a8;
          }
        }
        else if (*(long *)(*(long *)(param_1 + 0x378) + 0x90) + puVar1[2] < uVar38) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: child surface plane[%d] Image data doesn\'t fit within allocated parent plane size\n"
                    );
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
LAB_fffffff009c1c578:
        uVar38 = (ulong)(uVar37 + 1);
        lVar40 = lVar40 + -1;
      } while (uVar37 + 1 < *(uint *)(param_1 + 0x98));
    }
  }
  *(undefined8 *)(param_1 + 0x3a0) = 0;
  if (*(long *)(param_1 + 0x378) == 0) {
    local_88 = local_88 & 0xffffffffffffff00;
    bVar34 = FUN_fffffff009c1fec4(param_2,"IOSurfaceEnableStatistics",&local_88);
    bVar55 = (byte)local_88;
    local_88 = 0;
    iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceProtectionOptions",&local_88);
    if (iVar35 != 0) {
      if (0xf < local_88) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "Unsupported protection bits set: %016llx\n");
        lVar43 = 0;
        goto LAB_fffffff009c1b2a8;
      }
      uVar52 = FUN_fffffff009c314f8();
      uVar38 = uVar52;
      if ((uVar52 != 0 && (bVar34 & bVar55 & 1) == 0) &&
         (iVar35 = FUN_fffffff009c31488(0x10000), iVar35 != 0)) {
        iVar35 = FUN_fffffff009c31488(0x20000);
        uVar38 = uVar52 | 8;
        if (iVar35 != 0) {
          uVar38 = uVar52;
        }
      }
      goto LAB_fffffff009c1c608;
    }
  }
  else {
    iVar35 = FUN_fffffff009c31488(0x2000);
    uVar38 = *(ulong *)(*(long *)(param_1 + 0x378) + 0x3a0);
    if ((iVar35 == 0) && (uVar38 != 0)) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "Cannot create children of protected surfaces\n");
      lVar43 = 0;
      goto LAB_fffffff009c1b2a8;
    }
LAB_fffffff009c1c608:
    *(ulong *)(param_1 + 0x3a0) = uVar38 & 0xffffffff;
  }
  FUN_fffffff009c1ff50(param_2,"IOSurfaceBufferTileFormat",param_1 + 0x234);
  local_88 = local_88 & 0xffffffffffffff00;
  iVar35 = FUN_fffffff009c1fec4(param_2,"IOFenceAllowTearing",&local_88);
  if (iVar35 != 0) {
    *(uint *)(param_1 + 0x3d0) =
         *(uint *)(param_1 + 0x3d0) & 0xffffc000 |
         *(uint *)(param_1 + 0x3d0) & 0x1fff | ((byte)local_88 & 1) << 0xd;
  }
  local_88 = local_88 & 0xffffffffffffff00;
  iVar35 = FUN_fffffff009c1fec4(param_2,"IOSurfaceBufferTileMode",&local_88);
  uVar36 = *(uint *)(param_1 + 0x3d0);
  if (iVar35 != 0) {
    uVar36 = uVar36 & 0xfffffc00 | uVar36 & 0x1ff | ((byte)local_88 & 1) << 9;
    *(uint *)(param_1 + 0x3d0) = uVar36;
  }
  *(byte *)(*(long *)(param_1 + 0x178) + 0x14) = (byte)(uVar36 >> 9) & 1;
  local_88 = local_88 & 0xffffffffffffff00;
  iVar35 = FUN_fffffff009c1fec4(param_2,"IOSurfacePixelSizeCastingAllowed",&local_88);
  uVar36 = *(uint *)(param_1 + 0x3d0);
  if (iVar35 != 0) {
    uVar36 = uVar36 & 0xfffe0000 | uVar36 & 0xffff | ((byte)local_88 & 1) << 0x10;
    *(uint *)(param_1 + 0x3d0) = uVar36;
  }
  *(byte *)(*plVar44 + 0x2c) = (byte)(uVar36 >> 0x10) & 1;
  local_88 = 0;
  iVar35 = FUN_fffffff009c20038(param_2,"IOSurfacePixelFormat",&local_88);
  if (iVar35 != 0) {
    *(int *)(param_1 + 0x80) = (int)local_88;
  }
  iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceBitsPerBlock",&local_78);
  if (iVar35 == 0) {
LAB_fffffff009c1c7e4:
    iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceBytesPerElement",&local_78);
    if (iVar35 != 0) {
      if ((ulong)local_78 >> 0x10 != 0) goto LAB_fffffff009c1d63c;
      *(short *)(param_1 + 0x70) = (short)local_78;
    }
    iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceWidth",&local_78);
    if (iVar35 == 0) {
      if (*(int *)(param_1 + 0x98) != 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "IOSurface: Planar surfaces must specify a valid buffer width and height.\n");
        lVar43 = 0;
        goto LAB_fffffff009c1b2a8;
      }
    }
    else {
      *(undefined1 **)(param_1 + 0x58) = local_78;
    }
    iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceHeight",&local_78);
    if (iVar35 == 0) {
      if (*(int *)(param_1 + 0x98) != 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "IOSurface: Planar surfaces must specify a valid buffer width and height.\n");
        lVar43 = 0;
        goto LAB_fffffff009c1b2a8;
      }
    }
    else {
      *(undefined1 **)(param_1 + 0x60) = local_78;
    }
    iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceElementWidth",&local_78);
    if (iVar35 != 0) {
      if ((undefined1 *)0xff < local_78) goto LAB_fffffff009c1d63c;
      *(char *)(param_1 + 0x72) = (char)local_78;
    }
    iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceElementHeight",&local_78);
    if (iVar35 != 0) {
      if ((undefined1 *)0xff < local_78) goto LAB_fffffff009c1d63c;
      *(char *)(param_1 + 0x73) = (char)local_78;
    }
    if (*(short *)(param_1 + 0x70) == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface: buffer bytes per element is zero.\n");
      lVar43 = 0;
      goto LAB_fffffff009c1b2a8;
    }
    bVar55 = *(byte *)(param_1 + 0x72);
    if (bVar55 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface: buffer element width is zero.\n");
      lVar43 = 0;
      goto LAB_fffffff009c1b2a8;
    }
    if (*(char *)(param_1 + 0x73) == '\0') {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface: buffer element height is zero.\n");
      lVar43 = 0;
      goto LAB_fffffff009c1b2a8;
    }
    uVar38 = (ulong)(bVar55 - 1);
    uVar49 = (ulong)CARRY8(*(ulong *)(param_1 + 0x58),uVar38);
    uVar52 = -uVar49;
    if ((uVar52 != uVar49) || ((long)uVar52 < 0)) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"IOSurface: buffer width overflow\n");
      lVar43 = 0;
      goto LAB_fffffff009c1b2a8;
    }
    uVar52 = 0;
    if ((ulong)bVar55 != 0) {
      uVar52 = (*(ulong *)(param_1 + 0x58) + uVar38) / (ulong)bVar55;
    }
    iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceBytesPerRow",&local_78);
    if (iVar35 == 0) {
      uVar38 = CONCAT62(0,*(ushort *)(param_1 + 0x70));
      auVar17._8_8_ = 0;
      auVar17._0_8_ = uVar52;
      auVar28._8_8_ = 0;
      auVar28._0_8_ = uVar38;
      puVar47 = (undefined1 *)(uVar52 * uVar38);
      uVar38 = (ulong)*(uint *)(DAT_fffffff00af483b0 + 0xb0);
      if ((SUB168(auVar17 * auVar28,8) != 0) || (CARRY8(uVar38,(ulong)puVar47))) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "IOSurface: bytesPerRow calculation overflow\n");
        lVar43 = 0;
        goto LAB_fffffff009c1b2a8;
      }
      puVar51 = (undefined1 *)((ulong)(puVar47 + uVar38) & (uVar38 ^ 0xffffffffffffffff));
      *(undefined1 **)(param_1 + 0x68) = puVar51;
      bVar33 = false;
    }
    else {
      *(undefined1 **)(param_1 + 0x68) = local_78;
      uVar38 = CONCAT62(0,*(ushort *)(param_1 + 0x70));
      puVar47 = (undefined1 *)(uVar52 * uVar38);
      auVar16._8_8_ = 0;
      auVar16._0_8_ = uVar52;
      auVar27._8_8_ = 0;
      auVar27._0_8_ = uVar38;
      bVar33 = SUB168(auVar16 * auVar27,8) != 0;
      puVar51 = local_78;
    }
    if (bVar33) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface: buffer required width in bytes overflow\n");
      lVar43 = 0;
      goto LAB_fffffff009c1b2a8;
    }
    if (puVar51 < puVar47) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface: buffer bytes per row value is too small\n");
      lVar43 = 0;
      goto LAB_fffffff009c1b2a8;
    }
    iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceOffset",&local_78);
    if (iVar35 != 0) {
      *(undefined1 **)(param_1 + 0x78) = local_78;
    }
    if (*(long *)(param_1 + 0x378) == 0) {
      iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceAllocSize",&local_78);
      puVar47 = local_78;
      if (iVar35 == 0) {
        if (*(int *)(param_1 + 0x98) != 0) {
          uVar49 = *(ulong *)(param_1 + 0x180);
          uVar38 = uVar49 + (ulong)*(uint *)(param_1 + 0x188) * 0x38;
          if (((uVar49 ^ uVar38) & 0xffc0000000000000) != 0) {
            uVar38 = uVar38 & 0xffffffffffff | 0xc8a2000000000000;
          }
          if ((uVar38 < uVar49) || (uVar38 - uVar49 >> 0x20 != 0)) {
            FUN_fffffff009c48f64();
          }
          else {
            uVar50 = (ulong)(*(int *)(param_1 + 0x98) - 1);
            if (uVar50 * 0x38 == (long)(int)(uVar50 * 0x38)) {
              uVar50 = (uVar50 << 0x26) - (uVar50 << 0x23);
              if (((long)uVar50 < 0) || ((uint)(uVar38 - uVar49) < (int)(uVar50 >> 0x20) + 0x38U))
              goto LAB_fffffff009c1e5ec;
              lVar43 = uVar49 + (uVar50 >> 0x20);
              uVar49 = (ulong)CARRY8(uVar49,uVar50 >> 0x20);
              uVar38 = -uVar49;
              if ((uVar38 != uVar49) || ((long)uVar38 < 0)) {
                    /* WARNING: Subroutine does not return */
                FUN_fffffff009c48f50();
              }
              uVar50 = *(ulong *)(lVar43 + 0x10);
              uVar49 = *(ulong *)(lVar43 + 0x28);
              uVar38 = uVar50 + uVar49;
              if (CARRY8(uVar50,uVar49)) {
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                           "IOSurface: required planar allocation size overflow\n");
                lVar43 = 0;
                goto LAB_fffffff009c1b2a8;
              }
              goto LAB_fffffff009c1dca0;
            }
          }
          FUN_fffffff009c48f3c();
LAB_fffffff009c1e5ec:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        auVar18._8_8_ = 0;
        auVar18._0_8_ = *(ulong *)(param_1 + 0x68);
        auVar29._8_8_ = 0;
        auVar29._0_8_ = *(ulong *)(param_1 + 0x60);
        uVar49 = *(ulong *)(param_1 + 0x68) * *(ulong *)(param_1 + 0x60);
        uVar38 = *(ulong *)(param_1 + 0x78) + uVar49;
        if ((SUB168(auVar18 * auVar29,8) != 0) || (CARRY8(*(ulong *)(param_1 + 0x78),uVar49))) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: required allocation size overflow\n");
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
LAB_fffffff009c1dca0:
        uVar49 = (ulong)*(uint *)(DAT_fffffff00af483b0 + 0xac);
        if (CARRY8(uVar38,uVar49)) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: aligned allocation size overflow\n");
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        puVar47 = (undefined1 *)(uVar38 + uVar49 & (uVar49 ^ 0xffffffffffffffff));
      }
    }
    else {
      puVar47 = *(undefined1 **)(*(long *)(param_1 + 0x378) + 0x90);
    }
    *(undefined1 **)(param_1 + 0x90) = puVar47;
    uVar38 = (ulong)(uint)~(-1 << (ulong)(*(uint *)PTR_DAT_fffffff00806c9b0 & 0x1f));
    if ((undefined1 *)((ulong)(puVar47 + uVar38) & (uVar38 ^ 0xffffffffffffffff)) < puVar47) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"IOSurface: allocation size overflow\n")
      ;
      lVar43 = 0;
      goto LAB_fffffff009c1b2a8;
    }
    if ((*(long *)(param_1 + 0x378) != 0) &&
       (*(undefined1 **)(*(long *)(param_1 + 0x378) + 0x90) < puVar47)) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface: child surfaces must specify an allocation size less than or equal to the parent surface size\n"
                );
      lVar43 = 0;
      goto LAB_fffffff009c1b2a8;
    }
    if (*(undefined1 **)(DAT_fffffff00af483b0 + 0x198) < puVar47) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface: allocation size of %llu exceeds limit of %llu bytes\n");
      lVar43 = 0;
      goto LAB_fffffff009c1b2a8;
    }
    if (*(int *)(param_1 + 0x98) == 0) {
      bVar55 = *(byte *)(param_1 + 0x73);
      iVar35 = bVar55 - 1;
      uVar38 = (long)iVar35 >> 0x3f;
      if (CARRY8(*(ulong *)(param_1 + 0x60),(long)iVar35)) {
        uVar38 = uVar38 + 1;
      }
      if ((-(uVar38 & 1) != uVar38) || ((long)-(uVar38 & 1) < 0)) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "IOSurface: aligned height calculation overflow\n");
        lVar43 = 0;
        goto LAB_fffffff009c1b2a8;
      }
      uVar38 = CONCAT62(0,*(ushort *)(param_1 + 0x70));
      auVar19._8_8_ = 0;
      auVar19._0_8_ = uVar52;
      auVar30._8_8_ = 0;
      auVar30._0_8_ = uVar38;
      if (SUB168(auVar19 * auVar30,8) != 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "IOSurface: required bytes per line overflow\n");
        lVar43 = 0;
        goto LAB_fffffff009c1b2a8;
      }
      uVar52 = uVar52 * uVar38;
      uVar38 = 0;
      if ((ulong)bVar55 != 0) {
        uVar38 = (*(ulong *)(param_1 + 0x60) + (long)iVar35) / (ulong)bVar55;
      }
      auVar20._8_8_ = 0;
      auVar20._0_8_ = *(ulong *)(param_1 + 0x68);
      auVar31._8_8_ = 0;
      auVar31._0_8_ = uVar38 - 1;
      uVar49 = *(ulong *)(param_1 + 0x68) * (uVar38 - 1);
      uVar38 = uVar52 + uVar49;
      if ((SUB168(auVar20 * auVar31,8) != 0) || (CARRY8(uVar52,uVar49))) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "IOSurface: required image bytes overflow\n");
        lVar43 = 0;
        goto LAB_fffffff009c1b2a8;
      }
      if (CARRY8(*(ulong *)(param_1 + 0x78),uVar38)) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "IOSurface: required allocation size overflow\n\n");
        lVar43 = 0;
        goto LAB_fffffff009c1b2a8;
      }
      if (puVar47 < (undefined1 *)(*(ulong *)(param_1 + 0x78) + uVar38)) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "IOSurface: buffer allocation size is too small to cover valid image area: fAllocSize=%llu, requiredSizeInBytes=%llu\n"
                  );
        lVar43 = 0;
        goto LAB_fffffff009c1b2a8;
      }
    }
    else {
      uVar52 = *(ulong *)(param_1 + 0x180);
      uVar38 = uVar52 + (ulong)*(uint *)(param_1 + 0x188) * 0x38;
      if (((uVar52 ^ uVar38) & 0xffc0000000000000) != 0) {
        uVar38 = uVar38 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar38 < uVar52) || (uVar38 - uVar52 >> 0x20 != 0)) {
        FUN_fffffff009c48f64();
LAB_fffffff009c1e5f8:
        FUN_fffffff009c48f64();
LAB_fffffff009c1e5fc:
        FUN_fffffff009c48f3c();
LAB_fffffff009c1e600:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f28();
      }
      uVar50 = 0;
      uVar49 = 0xffffffff7fffffc8;
      iVar35 = 0;
      do {
        uVar49 = uVar49 + 0x38;
        if (uVar49 < 0xffffffff00000000) {
          FUN_fffffff009c48f3c();
LAB_fffffff009c1e5dc:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if (((long)uVar50 < 0) || ((uint)(uVar38 - uVar52) < (int)(uVar50 >> 0x20) + 0x38U))
        goto LAB_fffffff009c1e5dc;
        lVar43 = uVar52 + (uVar50 >> 0x20);
        uVar60 = (ulong)CARRY8(uVar52,uVar50 >> 0x20);
        uVar46 = -uVar60;
        if ((uVar46 != uVar60) || ((long)uVar46 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        uVar46 = *(ulong *)(lVar43 + 0x10);
        uVar60 = *(ulong *)(lVar43 + 0x28);
        if (CARRY8(uVar46,uVar60)) goto LAB_fffffff009c1dd84;
        if (puVar47 < (undefined1 *)(uVar46 + uVar60)) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "IOSurface: buffer allocation size is too small to cover valid image area of plane %d: fAllocSize=%llu, planeLimit=%llu\n"
                    );
          lVar43 = 0;
          goto LAB_fffffff009c1b2a8;
        }
        uVar50 = uVar50 + 0x3800000000;
        iVar35 = iVar35 + 1;
      } while (*(int *)(param_1 + 0x98) != iVar35);
    }
    iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceDirection",&local_78);
    if (iVar35 != 0) {
      *(uint *)(param_1 + 0x368) = (uint)local_78;
      if (((uint)local_78 & 0xfffffffe) != 2) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "IOSurface: client direction not InOut or Out\n");
        lVar43 = 0;
        goto LAB_fffffff009c1b2a8;
      }
    }
    iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceAddressOffset",&local_78);
    if ((iVar35 != 0) &&
       (*(ulong *)(param_1 + 0x168) = (ulong)local_78 & 0xffffffff,
       *(ulong *)PTR_DAT_fffffff00806ca78 <= ((ulong)local_78 & 0xffffffff))) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface: fClientAlignedOffset >= page_size\n");
      lVar43 = 0;
      goto LAB_fffffff009c1b2a8;
    }
    plVar39 = (long *)FUN_fffffff009c203b0(param_2,"IOSurfaceAddressRanges");
    if (plVar39 != (long *)0x0) {
      uVar36 = (**(code **)(*plVar39 + 0xa0))();
      if ((uVar36 < 0x10) || ((uVar36 & 0xf) != 0)) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "IOSurface: address ranges size not multiple of IOAddressRange\n");
        lVar43 = 0;
        goto LAB_fffffff009c1b2a8;
      }
      if (*(long *)(param_1 + 0x3a0) != 0) goto LAB_fffffff009c1d63c;
      uVar61 = thunk_EXT_FUN_80110000038fe580(uVar36);
      *(undefined8 *)(param_1 + 0x370) = uVar61;
      *(uint *)(param_1 + 0x3b4) = uVar36 >> 4;
      uVar41 = (**(code **)(*plVar39 + 0xd8))(plVar39);
      thunk_EXT_FUN_8011000003a61b10(uVar61,uVar41,uVar36);
    }
    iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceAddress",&local_78);
    if (iVar35 != 0) {
      if (*(long *)(param_1 + 0x308) != 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "IOSurface: Cannot use kIOSurfaceClientAddress with compressed iosurfaces.\n");
        lVar43 = 0;
        goto LAB_fffffff009c1b2a8;
      }
      if (*(long *)(param_1 + 0x3a0) != 0) goto LAB_fffffff009c1d63c;
      *(undefined1 **)(param_1 + 0x150) = local_78;
    }
    iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceYCbCrMatrix",&local_78);
    if (iVar35 != 0) {
      *(char *)(*plVar44 + 0x6e) = (char)local_78;
    }
    iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceCacheMode",&local_78);
    if (iVar35 != 0) {
      uVar36 = (uint)local_78 & 0xf00;
      bVar33 = 0x9ff < uVar36;
      if (bVar33) {
        uVar36 = 0;
      }
      *(uint *)(param_1 + 0x9c) = uVar36;
      if (bVar33) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"Unknown cache mode: %08x\n");
        lVar43 = 0;
        goto LAB_fffffff009c1b2a8;
      }
    }
    iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceMapCacheAttribute",&local_78);
    if (iVar35 != 0) {
      *(int *)(param_1 + 0x230) = (int)local_78;
    }
    local_89 = 0;
    iVar35 = FUN_fffffff009c1fec4(param_2,"IOSurfaceIsGlobal",&local_89);
    if (iVar35 != 0) {
      *(uint *)(param_1 + 0x3d0) =
           *(uint *)(param_1 + 0x3d0) & 0xfffffffc |
           *(uint *)(param_1 + 0x3d0) & 1 | (local_89 & 1) << 1;
    }
    local_89 = 0;
    iVar35 = FUN_fffffff009c1fec4(param_2,"IOSurfaceIsPrivate",&local_89);
    uVar36 = *(uint *)(param_1 + 0x3d0);
    if (iVar35 != 0) {
      uVar36 = uVar36 & 0xfff00000 | uVar36 & 0x7ffff | (local_89 & 1) << 0x13;
      *(uint *)(param_1 + 0x3d0) = uVar36;
    }
    if (((uVar36 ^ 0xffffffff) & 0x80002) == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface: Cannot set both global and private properties\n");
      lVar43 = 0;
    }
    else {
      local_89 = 0;
      iVar35 = FUN_fffffff009c1fec4(param_2,"IOSurfacePurgeWhenNotInUse",&local_89);
      if (iVar35 != 0) {
        *(uint *)(param_1 + 0x3d0) =
             *(uint *)(param_1 + 0x3d0) & 0xffffff80 |
             *(uint *)(param_1 + 0x3d0) & 0x3f | (local_89 & 1) << 6;
      }
      local_89 = 0;
      iVar35 = FUN_fffffff009c1fec4
                         (param_2,"IOSurfaceResetDefaultAttachmentsWhenNotInUse",&local_89);
      if (iVar35 != 0) {
        *(uint *)(param_1 + 0x3d0) =
             *(uint *)(param_1 + 0x3d0) & 0xffffff00 |
             *(uint *)(param_1 + 0x3d0) & 0x7f | (local_89 & 1) << 7;
      }
      lVar43 = FUN_fffffff009c203e8(param_2);
      if (lVar43 != 0) {
        FUN_fffffff009c16670(param_1 + 0x210,lVar43);
      }
      plVar44 = (long *)FUN_fffffff009c203b0(param_2,"IOSurfaceDefaultBulkAttachments");
      if ((plVar44 != (long *)0x0) && (lVar43 = (**(code **)(*plVar44 + 0xd8))(), lVar43 != 0)) {
        lVar40 = thunk_EXT_FUN_80110000038fe074(&DAT_fffffff00806af70);
        *(long *)(param_1 + 0x260) = lVar40;
        if (lVar40 != 0) {
          uVar36 = (**(code **)(*plVar44 + 0xa0))(plVar44);
          puVar48 = *(undefined8 **)(param_1 + 0x260);
          puVar48[1] = 0;
          *puVar48 = 0;
          puVar48[3] = 0;
          puVar48[2] = 0;
          puVar48[5] = 0;
          puVar48[4] = 0;
          puVar48[7] = 0;
          puVar48[6] = 0;
          puVar48[9] = 0;
          puVar48[8] = 0;
          puVar48[0xb] = 0;
          puVar48[10] = 0;
          puVar48[0xd] = 0;
          puVar48[0xc] = 0;
          puVar48[0xf] = 0;
          puVar48[0xe] = 0;
          *(undefined4 *)(puVar48 + 0x10) = 0;
          if (0x83 < uVar36) {
            uVar36 = 0x84;
          }
          thunk_EXT_FUN_8011000003a61b10(*(undefined8 *)(param_1 + 0x260),lVar43,uVar36);
        }
      }
      *(uint *)(param_1 + 0x3d0) =
           *(uint *)(param_1 + 0x3d0) & 0xf0000000 |
           *(uint *)(param_1 + 0x3d0) & 0x7ffffff |
           (~(uint)*(byte *)(DAT_fffffff00af483b0 + 0x498) & 1) << 0x1b;
      plVar44 = (long *)FUN_fffffff009c20428(param_2,"IOSurfaceName");
      if ((plVar44 != (long *)0x0) &&
         ((uVar38 = (**(code **)(*plVar44 + 0xb8))(plVar44,"QuartzCore"), (uVar38 & 1) != 0 ||
          (iVar35 = (**(code **)(*plVar44 + 0xb8))(plVar44,"CA Framebuffer"), iVar35 != 0)))) {
        *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | 0x8000000;
      }
      lVar43 = FUN_fffffff009c20428(param_2,"IOSurfaceMemoryRegion");
      if (lVar43 == 0) {
        plVar44 = (long *)FUN_fffffff009c20000(param_2,"IOSurfaceMemoryRegion");
        if (plVar44 != (long *)0x0) {
          uVar37 = (**(code **)(*plVar44 + 0x90))();
          uVar36 = uVar37;
          if (1 < uVar37) {
            uVar36 = 2;
          }
          if (uVar37 != 0) {
            uVar37 = 0;
            uVar61 = *(undefined8 *)PTR_DAT_fffffff00806ca10;
            uVar38 = param_1 + 0x198;
            uVar52 = (param_1 + 0x1a8U) - uVar38;
            do {
              uVar41 = (**(code **)(*plVar44 + 0x118))(plVar44,uVar37);
              lVar43 = thunk_EXT_FUN_8011000003890f30(uVar41,uVar61);
              if (lVar43 != 0) {
                lVar43 = FUN_fffffff009c34124(DAT_fffffff00af483b0,lVar43);
                if ((uVar52 & 0xffffffff00000000) != 0 || param_1 + 0x1a8U < uVar38)
                goto LAB_fffffff009c1e5f8;
                uVar49 = (ulong)*(uint *)(param_1 + 400);
                if (uVar49 << 3 != (long)(int)(uVar49 << 3)) goto LAB_fffffff009c1e5fc;
                if ((uVar49 & 0x1fffffff) >> 0x1c != 0) goto LAB_fffffff009c1e600;
                uVar45 = *(uint *)(param_1 + 400) * 8;
                uVar56 = (uint)uVar52;
                if (uVar56 < uVar45 + 8) goto LAB_fffffff009c1e600;
                plVar39 = (long *)(uVar38 + uVar45);
                uVar46 = (ulong)CARRY8(uVar38,(ulong)uVar45);
                uVar50 = -uVar46;
                if ((uVar50 != uVar46) || ((long)uVar50 < 0)) {
                    /* WARNING: Subroutine does not return */
                  FUN_fffffff009c48f50();
                }
                if ((long *)*plVar39 == (long *)0x0) {
                  *plVar39 = lVar43;
                }
                else {
                  (**(code **)(*(long *)*plVar39 + 0x28))();
                  uVar49 = (ulong)*(uint *)(param_1 + 400);
                  *plVar39 = lVar43;
                  if (uVar49 << 3 != (long)(int)(uVar49 << 3)) {
                    FUN_fffffff009c48f3c();
                    goto LAB_fffffff009c1e60c;
                  }
                }
                if ((uVar49 & 0x1fffffff) >> 0x1c != 0) {
LAB_fffffff009c1e60c:
                    /* WARNING: Subroutine does not return */
                  FUN_fffffff009c48f28();
                }
                uVar45 = (int)uVar49 * 8;
                if (uVar56 < uVar45 + 8) goto LAB_fffffff009c1e60c;
                uVar46 = (ulong)CARRY8(uVar38,(ulong)uVar45);
                uVar50 = -uVar46;
                if ((uVar50 != uVar46) || ((long)uVar50 < 0)) {
                    /* WARNING: Subroutine does not return */
                  FUN_fffffff009c48f50();
                }
                if (*(long *)(uVar38 + uVar45) != 0) {
                  *(int *)(param_1 + 400) = (int)uVar49 + 1;
                }
              }
              uVar37 = uVar37 + 1;
            } while (uVar36 != uVar37);
          }
        }
      }
      else {
        lVar43 = FUN_fffffff009c34124(DAT_fffffff00af483b0,lVar43);
        plVar44 = (long *)(param_1 + 0x198);
        uVar38 = (long)(param_1 + 0x1a8U) - (long)plVar44;
        if (((long *)(param_1 + 0x1a8U) < plVar44) || (uVar38 >> 0x20 != 0)) {
          FUN_fffffff009c48f64();
LAB_fffffff009c1e618:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if (uVar38 < 8) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if ((long *)*plVar44 != (long *)0x0) {
          (**(code **)(*(long *)*plVar44 + 0x28))();
        }
        *plVar44 = lVar43;
        if (lVar43 != 0) {
          *(undefined4 *)(param_1 + 400) = 1;
        }
      }
      iVar35 = FUN_fffffff009c20038(param_2,"IOSurfaceAllocateFromSuperbuffer",&local_78);
      if (iVar35 != 0) {
        *(undefined1 **)(param_1 + 0x340) = local_78;
      }
      thunk_EXT_FUN_80110000036da494
                (0x5400010,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x80),
                 *(undefined8 *)(param_1 + 0x90),
                 *(int *)(param_1 + 0x98) << 8 | *(uint *)(param_1 + 0x3d0) >> 9 & 1,0);
      thunk_EXT_FUN_80110000036da494
                (0x5400014,*(undefined4 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x58),
                 *(undefined8 *)(param_1 + 0x60),
                 (long)(int)((uint)*(byte *)(param_1 + 0x72) << 0x18) |
                 (ulong)*(byte *)(param_1 + 0x73) << 0x10 | (ulong)*(ushort *)(param_1 + 0x70),0);
      FUN_fffffff009c20460(param_1);
      lVar43 = 1;
    }
  }
  else {
    if ((ulong)local_78 >> 0x10 == 0) {
      *(ushort *)(param_1 + 0x70) = (ushort)((uint)local_78 >> 3) & 0x1fff;
      goto LAB_fffffff009c1c7e4;
    }
LAB_fffffff009c1d63c:
    lVar43 = 0;
  }
LAB_fffffff009c1b2a8:
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_70) {
    thunk_EXT_FUN_8011000003a48590(lVar43);
    return;
  }
  return;
LAB_fffffff009c1dd84:
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
             "IOSurface: plane limit calculation overflow\n");
  lVar43 = 0;
  goto LAB_fffffff009c1b2a8;
}

