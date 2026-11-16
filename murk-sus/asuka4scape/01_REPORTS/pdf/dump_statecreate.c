/* ==== FUN_183ed2078 @ 183ed2078 size=16 ==== */

undefined8 FUN_183ed2078(void)

{
  func_0x00018813aad0(&DAT_1eb058178,&DAT_1e223f628);
  return DAT_1eb058170;
}



/* ==== FUN_183ed207c @ 183ed207c size=40 ==== */

undefined8 FUN_183ed207c(void)

{
  func_0x00018813aad0(&DAT_1eb058178,&DAT_1e223f628);
  return DAT_1eb058170;
}



/* ==== FUN_183ed2640 @ 183ed2640 size=88 ==== */

void FUN_183ed2640(long param_1)

{
  long local_30;
  undefined1 *puStack_28;
  
  func_0x00018813b460(*(undefined8 *)(param_1 + DAT_1eb05432c));
  puStack_28 = &DAT_1000006f15f438;
  local_30 = param_1;
  func_0x000188139980(&local_30,0x1f5b81a60);
  return;
}



/* ==== FUN_183ed2698 @ 183ed2698 size=96 ==== */

long FUN_183ed2698(undefined8 param_1)

{
  long lVar1;
  undefined8 local_30;
  undefined1 *puStack_28;
  
  puStack_28 = &DAT_1000006f15f438;
  local_30 = param_1;
  lVar1 = func_0x000188139980(&local_30,0x1f5653ae0);
  if (lVar1 != 0) {
    func_0x00018813b510(*(undefined8 *)(lVar1 + DAT_1eb05432c));
  }
  return lVar1;
}



/* ==== FUN_183ed272c @ 183ed272c size=72 ==== */

void FUN_183ed272c(long param_1,undefined8 param_2,undefined1 param_3)

{
  _objc_msgSend_setValue_forKey_
            (param_1,param_2,&cfstringStruct_1e22480e0,&cfstringStruct_1e22480a0);
  *(undefined1 *)(param_1 + DAT_1eb054334) = param_3;
  return;
}



/* ==== FUN_183ed278c @ 183ed278c size=56 ==== */

void FUN_183ed278c(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  undefined1 auVar2 [16];
  
  auVar2 = _objc_msgSend_valueForKey_(param_1,param_2,&cfstringStruct_1e22480a0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183ed27c0);
    (*pcVar1)();
  }
  _objc_msgSend_isEqualToString_(auVar2._0_8_,auVar2._8_8_,&cfstringStruct_1e22480c0);
  return;
}



/* ==== FUN_183ed27e8 @ 183ed27e8 size=184 ==== */

ulong FUN_183ed27e8(undefined8 param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulong uVar6;
  ulong unaff_x30;
  
  iVar2 = _objc_msgSend_count();
  if (iVar2 == 1) {
    iVar2 = _objc_msgSend_isBoxRegion(param_1);
    uVar4 = _objc_msgSend_firstChild(param_1);
    if (iVar2 == 0) {
      uVar5 = func_0x000188139990(DAT_1e05dde50);
      uVar3 = func_0x0001881399a0(uVar4,uVar5);
      goto LAB_183ed288c;
    }
    uVar5 = func_0x000188139990(DAT_1e05ddea0);
    uVar6 = func_0x0001881399a0(uVar4,uVar5);
    if ((uVar6 & 1) != 0) {
      _objc_msgSend_firstChild(param_1);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183ed2868);
        (*pcVar1)();
      }
      uVar6 = _objc_msgSend_isGraphicalRegion();
      return uVar6;
    }
  }
  uVar3 = 0;
LAB_183ed288c:
  return (ulong)(uVar3 & 1);
}



/* ==== FUN_183ed28d0 @ 183ed28d0 size=60 ==== */

bool FUN_183ed28d0(void)

{
  double dVar1;
  
  dVar1 = (double)_objc_msgSend_rotationAngle();
  return 0.1 < 360.0 - dVar1 && 0.1 < dVar1;
}



/* ==== FUN_183ed290c @ 183ed290c size=124 ==== */

undefined8 FUN_183ed290c(undefined8 param_1)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  uVar2 = _objc_msgSend_isImageRegion();
  if (((((uVar2 & 1) == 0) && (uVar2 = _objc_msgSend_isShapeRegion(param_1), (uVar2 & 1) == 0)) &&
      (uVar2 = _objc_msgSend_isRowRegion(param_1), (uVar2 & 1) == 0)) &&
     (uVar2 = _objc_msgSend_isTableCellRegion(param_1), (uVar2 & 1) == 0)) {
    uVar3 = _objc_msgSend_isBoxRegion(param_1);
    if ((int)uVar3 != 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183ed2984);
        (*pcVar1)();
      }
      uVar3 = _objc_msgSend_isRotated(param_1);
      return uVar3;
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



/* ==== FUN_183ed299c @ 183ed299c size=80 ==== */

void FUN_183ed299c(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = (long)DAT_1eb05432c;
  if (*(long *)(param_1 + lVar2) != param_3) {
    func_0x00018813b460();
    uVar1 = func_0x00018813b4b0();
    *(undefined8 *)(param_1 + lVar2) = uVar1;
  }
  return;
}



/* ==== FUN_183ed2a3c @ 183ed2a3c size=1324 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FUN_183ed2a3c(ulong param_1,long param_2,long param_3,long param_4,long param_5)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  long *plVar4;
  long lVar5;
  undefined8 uVar6;
  byte bVar7;
  ulong *puVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  int *piVar12;
  long lVar13;
  undefined4 local_84;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_68;
  
  local_68 = *_DAT_1e0186220;
  if (((((param_1 < 0x11) && (param_1 != 0)) && (param_2 != 0)) &&
      ((param_3 != 0 && (param_4 != 0)))) &&
     ((param_1 == *(ulong *)(param_4 + 0x20) &&
      (*(long *)(*(long *)(param_3 + 0x18) + 0x30) == *(long *)(param_4 + 0x30))))) {
    lVar2 = func_0x000188140d60(param_3);
    if (DAT_1edf367a0 != -1) {
      func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
    }
    if ((lVar2 != DAT_1edf36a20) || (2 < *(int *)(*(long *)(param_3 + 0x18) + 0x18) - 7U)) {
      lVar2 = 0;
      uVar11 = param_1;
      do {
        if (*(long *)(param_2 + lVar2 * 8) == 0) goto LAB_183ed2edc;
        lVar2 = lVar2 + 1;
        uVar11 = uVar11 - 1;
      } while (uVar11 != 0);
      piVar3 = (int *)func_0x000188138460(0x78,1,0xfa02cbc7);
      if (piVar3 != (int *)0x0) {
        *piVar3 = 1;
        *(undefined2 *)(piVar3 + 2) = 0;
        *(undefined1 *)((long)piVar3 + 10) = 0;
        lVar2 = func_0x000188140d60(param_3);
        if (DAT_1edf367a0 != -1) {
          func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
        }
        if (lVar2 == DAT_1edf36a20) {
          bVar7 = *(byte *)(*(long *)(param_3 + 0x18) + 0xc);
        }
        else {
          bVar7 = 1;
        }
        piVar12 = piVar3 + 6;
        piVar12[0] = 8;
        piVar12[1] = 4;
        *(byte *)(piVar3 + 3) = bVar7 & 1;
        *(undefined1 *)((long)piVar3 + 0xb) = 0;
        *(undefined2 *)((long)piVar3 + 0xe) = 0;
        puVar8 = (ulong *)(piVar3 + 0xc);
        *puVar8 = param_1;
        *(undefined **)(piVar3 + 0x1c) = &DAT_1e222e980;
        piVar3[8] = 4;
        piVar3[0x14] = 0;
        piVar3[0x15] = 0;
        piVar3[0x16] = 0;
        piVar3[0x17] = 0;
        lVar13 = param_1 * 8;
        lVar2 = func_0x000188138470(lVar13 + 8,0x100004000313f17);
        if (lVar2 != 0) {
          func_0x0001881495f0(lVar2,&DAT_1842659a0,lVar13);
          *(undefined8 *)(lVar2 + param_1 * 8) = 0x3ff0000000000000;
        }
        *(long *)(piVar3 + 10) = lVar2;
        plVar4 = (long *)func_0x000188138460(0x90,1,0xdd0ced2f);
        *(long **)(piVar3 + 0x18) = plVar4;
        if (plVar4 != (long *)0x0) {
          lVar2 = func_0x000188138470(lVar13,0x10040436913f5);
          *plVar4 = lVar2;
          if (lVar2 != 0) {
            uVar11 = 0;
LAB_183ed2c44:
            lVar2 = func_0x0001881386f0(*(undefined8 *)(param_2 + uVar11 * 8));
            lVar2 = func_0x000188138470(lVar2 + 1,0x19a17aea);
            lVar5 = *plVar4;
            *(long *)(lVar5 + uVar11 * 8) = lVar2;
            if (lVar2 != 0) goto code_r0x000183ed2c6c;
            if (uVar11 != 0) {
              lVar2 = 0;
              do {
                func_0x000188138390(*(undefined8 *)(*plVar4 + lVar2 * 8));
                lVar2 = lVar2 + 1;
                uVar11 = uVar11 - 1;
              } while (uVar11 != 0);
              goto LAB_183ed2ec4;
            }
            goto LAB_183ed2ec8;
          }
          goto LAB_183ed2ecc;
        }
        goto LAB_183ed2ed4;
      }
    }
  }
LAB_183ed2edc:
  lVar2 = _CGColorSpaceCreateWithState(0);
LAB_183ed2ee8:
  if (lVar2 != 0) {
    uVar6 = _color_space_state_register(*(undefined8 *)(lVar2 + 0x18));
    *(undefined8 *)(lVar2 + 0x18) = uVar6;
  }
  if (*_DAT_1e0186220 != local_68) {
    lVar2 = func_0x000188138130();
    return lVar2;
  }
  return lVar2;
code_r0x000183ed2c6c:
  func_0x00018814d5d0(lVar2,*(undefined8 *)(param_2 + uVar11 * 8));
  uVar11 = uVar11 + 1;
  if (param_1 == uVar11) goto code_r0x000183ed2c84;
  goto LAB_183ed2c44;
code_r0x000183ed2c84:
  func_0x000188141250(param_3);
  plVar4[1] = param_3;
  func_0x000188141250(param_4);
  plVar4[2] = param_4;
  if (param_5 == 0) {
    plVar4[3] = 0;
  }
  else {
    lVar2 = func_0x000188138470(lVar13,0x2004093837f09);
    plVar4[3] = lVar2;
    if (lVar2 == 0) {
      lVar2 = 0;
      do {
        func_0x000188138390(*(undefined8 *)(*plVar4 + lVar2 * 8));
        lVar2 = lVar2 + 1;
        param_1 = param_1 - 1;
      } while (param_1 != 0);
LAB_183ed2ec4:
      lVar5 = *plVar4;
LAB_183ed2ec8:
      func_0x000188138390(lVar5);
LAB_183ed2ecc:
      func_0x000188138390(*(undefined8 *)(piVar3 + 0x18));
LAB_183ed2ed4:
      func_0x000188138390(piVar3);
      goto LAB_183ed2edc;
    }
    lVar13 = 0;
    do {
      lVar5 = *(long *)(param_5 + lVar13 * 8);
      if (lVar5 != 0) {
        func_0x000188141250(lVar5);
        lVar2 = plVar4[3];
      }
      *(long *)(lVar2 + lVar13 * 8) = lVar5;
      lVar13 = lVar13 + 1;
      param_1 = param_1 - 1;
    } while (param_1 != 0);
  }
  local_80 = 0;
  uStack_78 = 0;
  lVar2 = func_0x000188138470(0x5c,0x100004034a301b9);
  func_0x00018814c300();
  if (lVar2 != 0) {
    func_0x00018814c310(lVar2,piVar12,4);
    func_0x00018814c310(lVar2,puVar8,8);
  }
  plVar4 = *(long **)(piVar3 + 0x18);
  if (*(long *)(piVar3 + 0xc) != 0) {
    uVar11 = 0;
    do {
      uVar9 = *(undefined8 *)(*plVar4 + uVar11 * 8);
      uVar6 = func_0x0001881386f0(uVar9);
      FUN_183bfb034(lVar2,uVar9,uVar6);
      uVar11 = uVar11 + 1;
    } while (uVar11 < *puVar8);
  }
  if (plVar4[1] == 0) {
    lVar13 = 0;
  }
  else {
    lVar5 = *(long *)(plVar4[1] + 0x18);
    lVar13 = 0;
    if (lVar5 != 0) {
      lVar13 = lVar5 + 0x40;
    }
  }
  if (lVar2 != 0) {
    func_0x00018814c310(lVar2,lVar13,0x10);
  }
  if ((plVar4[3] != 0) && (uVar11 = *puVar8, uVar11 != 0)) {
    uVar10 = 0;
    do {
      lVar13 = *(long *)(plVar4[3] + uVar10 * 8);
      if (lVar13 == 0) {
        lVar13 = 0;
      }
      else {
        lVar5 = *(long *)(lVar13 + 0x18);
        lVar13 = 0;
        if (lVar5 != 0) {
          lVar13 = lVar5 + 0x40;
        }
      }
      if (lVar2 != 0) {
        func_0x00018814c310(lVar2,lVar13,0x10);
        uVar11 = *puVar8;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar11);
  }
  local_84 = 0;
  if (plVar4[2] != 0) {
    local_84 = *(undefined4 *)(plVar4[2] + 0x10);
  }
  if (lVar2 == 0) {
    uVar6 = 0;
    uVar9 = 0;
  }
  else {
    func_0x00018814c310(lVar2,&local_84,4);
    func_0x00018814c2f0(&local_80,lVar2);
    uVar6 = local_80;
    uVar9 = uStack_78;
  }
  func_0x000188138390(lVar2);
  *(undefined8 *)(piVar3 + 0x12) = uVar9;
  *(undefined8 *)(piVar3 + 0x10) = uVar6;
  lVar2 = _CGColorSpaceCreateWithState(piVar3);
  iVar1 = *piVar3;
  *piVar3 = iVar1 + -1;
  if (iVar1 == 1) {
    _color_space_state_dealloc(piVar3);
  }
  goto LAB_183ed2ee8;
}



/* ==== FUN_183ed2f68 @ 183ed2f68 size=88 ==== */

undefined8 FUN_183ed2f68(long param_1)

{
  if (*(int *)(*(long *)(param_1 + 0x18) + 0x18) == 8) {
    return *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x18) + 0x60) + 0x10);
  }
                    /* WARNING: Subroutine does not return */
  FUN_183c19214("CGColorSpaceGetTintTransform",0xe2,
                "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/ColorSpaces/CGColorSpace_DeviceN.c"
                ,"s->state->type == kCGColorSpaceDeviceN","Colorspace must be DeviceN. type = %d");
}



/* ==== FUN_183ed2fc0 @ 183ed2fc0 size=88 ==== */

undefined8 FUN_183ed2fc0(long param_1)

{
  if (*(int *)(*(long *)(param_1 + 0x18) + 0x18) == 8) {
    return *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x18) + 0x60) + 0x18);
  }
                    /* WARNING: Subroutine does not return */
  FUN_183c19214("CGColorSpaceGetColorants",0xe9,
                "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/ColorSpaces/CGColorSpace_DeviceN.c"
                ,"s->state->type == kCGColorSpaceDeviceN","Colorspace must be DeviceN. type = %d");
}



