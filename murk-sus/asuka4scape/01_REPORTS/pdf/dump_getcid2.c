/* ==== FUN_183fe609c @ 183fe609c size=136 ==== */

long FUN_183fe609c(undefined8 param_1)

{
  long lVar1;
  long lVar2;
  
  if (DAT_1eb056f68 != -1) {
    func_0x00018813aad0(&DAT_1eb056f68,&DAT_1e2240710);
  }
  lVar1 = _pdf_create_cftype(DAT_1eb056f28,0x28);
  if (lVar1 != 0) {
    lVar2 = _cmap_create_with_name(param_1);
    *(long *)(lVar1 + 0x10) = lVar2;
    if (lVar2 == 0) {
      func_0x000188141240(lVar1);
      lVar1 = 0;
    }
    else {
      *(undefined4 *)(lVar1 + 0x20) = 0;
    }
  }
  return lVar1;
}



/* ==== FUN_183fe6124 @ 183fe6124 size=48 ==== */

long FUN_183fe6124(long param_1)

{
  if (param_1 != 0) {
    func_0x000188141250(param_1);
  }
  return param_1;
}



/* ==== FUN_183fe61a0 @ 183fe61a0 size=408 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FUN_183fe61a0(long param_1,char *param_2,long param_3,long param_4,long param_5)

{
  bool bVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  ulong extraout_x8;
  long lVar4;
  long lVar5;
  long lVar6;
  long extraout_x12;
  long lVar7;
  undefined1 auStack_70 [8];
  long local_68;
  
  lVar7 = 0;
  local_68 = *_DAT_1e0186220;
  if ((((param_1 != 0) && (param_2 != (char *)0x0)) && (param_3 != 0)) && (param_4 != 0)) {
    uVar2 = (*_DAT_1e1f91910)(param_3 << 3);
    puVar3 = (undefined1 *)0x0;
    if (extraout_x8 < 0x1fffffffffffffff) {
      puVar3 = auStack_70 + -extraout_x12;
    }
    if (0xe000000000000065 < extraout_x8 + 0xe000000000000001) {
      puVar3 = (undefined1 *)func_0x000188138470(uVar2,0xedba3ad0);
    }
    if (puVar3 == (undefined1 *)0x0) {
      lVar7 = 0;
    }
    else {
      lVar7 = _cmap_convert(*(undefined8 *)(param_1 + 0x10),param_2,param_3,param_4,puVar3);
      if ((param_5 != 0) && (lVar7 != 0)) {
        lVar4 = 0;
        lVar5 = lVar7;
        do {
          lVar6 = *(long *)(puVar3 + lVar4 * 8);
          if (lVar6 == 1) {
            bVar1 = *param_2 == ' ';
          }
          else {
            bVar1 = false;
          }
          *(bool *)(param_5 + lVar4) = bVar1;
          param_2 = param_2 + lVar6;
          lVar4 = lVar4 + 1;
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
      }
      if (puVar3 != auStack_70 + -extraout_x12) {
        func_0x000188138390(puVar3);
      }
    }
  }
  if (*_DAT_1e0186220 == local_68) {
    return lVar7;
  }
  lVar7 = func_0x000188138130();
  return lVar7;
}



/* ==== FUN_183fe6338 @ 183fe6338 size=196 ==== */

long FUN_183fe6338(long param_1)

{
  undefined4 *puVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (*(long *)(param_1 + 0x18) != 0) {
    return *(long *)(param_1 + 0x18);
  }
  func_0x00018813b710(param_1 + 0x20);
  if (*(long *)(param_1 + 0x18) == 0) {
    lVar5 = *(long *)(*(long *)(param_1 + 0x10) + 0x10);
    if (lVar5 == 0) {
      return 0;
    }
    lVar2 = func_0x00018813bb80(lVar5,0x2d);
    if (lVar2 == 0) {
      return 0;
    }
    lVar3 = func_0x000188138470((lVar2 - lVar5) + 6,0x73a64d51);
    if (lVar3 == 0) {
      return 0;
    }
    lVar2 = (lVar2 - lVar5) + 1;
    lVar5 = func_0x000188138710(lVar3,lVar5,lVar2);
    puVar1 = (undefined4 *)(lVar5 + lVar2);
    *(undefined1 *)(puVar1 + 1) = 0;
    *puVar1 = 0x32534355;
    uVar4 = FUN_183fe609c();
    *(undefined8 *)(param_1 + 0x18) = uVar4;
    func_0x000188138390(lVar3);
  }
  func_0x000188138580(param_1 + 0x20);
  return *(long *)(param_1 + 0x18);
}



/* ==== FUN_183fe644c @ 183fe644c size=208 ==== */

ulong FUN_183fe644c(long param_1,ushort *param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  long *plVar10;
  ulong uVar11;
  
  if (param_1 == 0) {
    return 0;
  }
  lVar4 = *(long *)(*(long *)(param_1 + 0x10) + 0x30);
  if (lVar4 != 0) {
    lVar4 = *(long *)(lVar4 + 0x10);
    if (((lVar4 != 0 && param_3 == 1) && (uVar5 = *(ulong *)(lVar4 + 0x38), uVar5 != 0)) &&
       (*(long *)(lVar4 + 0x48) != 0)) {
      uVar7 = (ulong)*param_2;
      uVar8 = uVar5 - 1;
      uVar3 = (uint)uVar5;
      uVar6 = (uint)*param_2;
      if ((uVar5 & uVar8) == 0) {
        uVar9 = uVar3 - 1 & uVar7;
      }
      else {
        uVar9 = uVar7;
        if (uVar5 <= uVar7) {
          uVar1 = 0;
          if (uVar3 != 0) {
            uVar1 = uVar6 / uVar3;
          }
          uVar9 = (ulong)(uVar6 - uVar1 * uVar3);
        }
      }
      plVar10 = *(long **)(*(long *)(lVar4 + 0x30) + uVar9 * 8);
      if (plVar10 != (long *)0x0) {
        do {
          while( true ) {
            plVar10 = (long *)*plVar10;
            if (plVar10 == (long *)0x0) {
              return 0xffffffff;
            }
            uVar11 = plVar10[1];
            if (uVar11 != uVar7) break;
            if (*(ushort *)(plVar10 + 2) == uVar6) {
              return (ulong)*(ushort *)((long)plVar10 + 0x12);
            }
          }
          if ((uVar5 & uVar8) == 0) {
            uVar11 = uVar11 & uVar8;
          }
          else if (uVar5 <= uVar11) {
            uVar2 = 0;
            if (uVar5 != 0) {
              uVar2 = uVar11 / uVar5;
            }
            uVar11 = uVar11 - uVar2 * uVar5;
          }
        } while (uVar11 == uVar9);
      }
    }
    return 0xffffffff;
  }
  return 0;
}



/* ==== FUN_183fe651c @ 183fe651c size=1184 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_183fe651c(long param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  long lVar14;
  uint uVar15;
  ulong uVar16;
  ulong uVar17;
  undefined4 local_64;
  
  if (param_1 != 0) {
    lVar10 = *(long *)(param_1 + 0x10);
    if (lVar10 == 0) {
      return 0;
    }
    lVar5 = func_0x000188141cf0(0,0);
    if (lVar5 != 0) {
      func_0x000188141d50();
      local_64._0_2_ = 0x200;
      func_0x000188141da0(lVar5,&local_64,2);
      local_64 = (uint)local_64._2_2_ << 0x10;
      func_0x000188141da0(lVar5,&local_64,2);
      local_64 = 0;
      func_0x000188141da0(lVar5,&local_64,4);
      lVar10 = *(long *)(lVar10 + 0x30);
      if ((lVar10 != 0) && (*(long *)(lVar10 + 0x10) != 0)) {
        local_64 = CONCAT22(local_64._2_2_,0x600);
        func_0x000188141da0(lVar5,&local_64,2);
        uVar12 = **(uint **)(lVar10 + 0x10);
        lVar6 = func_0x000188138470(*(long *)(*(uint **)(lVar10 + 0x10) + 10) << 1,0x1000040bdfb0063
                                   );
        if (lVar6 != 0) {
          uVar16 = 0;
          uVar11 = 0;
          do {
            lVar7 = _cmap_bf_set_get_unichars(*(undefined8 *)(lVar10 + 0x10),uVar11 & 0xffff,lVar6);
            uVar15 = (uint)uVar16;
            if (lVar7 != 0) {
              uVar15 = uVar15 + 1;
            }
            uVar16 = (ulong)uVar15;
            uVar11 = uVar11 + 1;
          } while ((uVar11 & 0xffff) <= (uVar12 & 0xffff));
          uVar16 = uVar16 & 0xffff;
          lVar7 = func_0x000188138470(uVar16 << 1,0x1000040bdfb0063);
          if (lVar7 != 0) {
            uVar11 = 0;
            lVar14 = 0;
            do {
              uVar13 = uVar11 & 0xffff;
              lVar8 = _cmap_bf_set_get_unichars(*(undefined8 *)(lVar10 + 0x10),uVar13,lVar6);
              if (lVar8 != 0) {
                *(short *)(lVar7 + lVar14 * 2) = (short)uVar11;
                lVar14 = lVar14 + 1;
              }
              uVar11 = uVar11 + 1;
            } while (uVar13 < (uVar12 & 0xffff));
            local_64._0_2_ = 0x600;
            func_0x000188141da0(lVar5,&local_64,2);
            local_64._0_2_ = (ushort)(uVar15 >> 8) & 0xff | (ushort)((uVar15 & 0xff00ff) << 8);
            func_0x000188141da0(lVar5,&local_64,2);
            uVar12 = uVar15 & 0xffff;
            if (uVar12 < 0x8001) {
              if (uVar12 < 2) {
                uVar11 = 0;
                uVar13 = 0xffff;
              }
              else {
                uVar3 = 0;
                uVar2 = 1;
                do {
                  uVar11 = uVar2;
                  uVar13 = uVar3;
                  uVar2 = (uVar11 & 0x7fff) << 1;
                  uVar3 = uVar13 + 1;
                } while (uVar2 < uVar12);
                uVar11 = uVar11 & 0x7fff;
              }
            }
            else {
              uVar13 = 0xf;
              uVar11 = 0x8000;
            }
            local_64._0_2_ =
                 (ushort)(uVar11 * 6 >> 8) & 0xff | (ushort)((uVar11 * 6 & 0xff00ff) << 8);
            func_0x000188141da0(lVar5,&local_64,2);
            local_64._0_2_ = (ushort)(uVar13 >> 8) & 0xff | (ushort)((uVar13 & 0xff00ff) << 8);
            func_0x000188141da0(lVar5,&local_64,2);
            uVar11 = (uVar15 - uVar11) * 6;
            local_64 = CONCAT22(local_64._2_2_,
                                (ushort)(uVar11 >> 8) & 0xff | (ushort)((uVar11 & 0xff00ff) << 8));
            func_0x000188141da0(lVar5,&local_64,2);
            uVar11 = uVar12 * 6 + 0x1a;
            uVar13 = uVar11 & 2;
            uVar11 = uVar13 + uVar11;
            if (uVar12 != 0) {
              lVar14 = 0;
              uVar17 = uVar16;
              uVar12 = uVar11;
              do {
                uVar1 = *(ushort *)(lVar7 + lVar14 * 2);
                local_64 = CONCAT22(local_64._2_2_,uVar1 >> 8 | uVar1 << 8);
                func_0x000188141da0(lVar5,&local_64,2);
                uVar2 = (uVar12 & 0xff00ff00) >> 8 | (uVar12 & 0xff00ff) << 8;
                local_64 = uVar2 >> 0x10 | uVar2 << 0x10;
                func_0x000188141da0(lVar5,&local_64,4);
                iVar4 = _cmap_bf_set_get_unichars(*(undefined8 *)(lVar10 + 0x10),uVar1,lVar6);
                uVar12 = uVar12 + iVar4 * 2 + 0xc;
                uVar2 = uVar12 & 3;
                if (-1 < (int)-uVar12) {
                  uVar2 = -(-uVar12 & 3);
                }
                uVar12 = uVar12 + (uVar2 & 0xffff);
                lVar14 = lVar14 + 1;
                uVar17 = uVar17 - 1;
              } while (uVar17 != 0);
            }
            local_64._0_2_ = 0xffff;
            func_0x000188141da0(lVar5,&local_64,2);
            local_64._0_2_ = 0xffff;
            func_0x000188141da0(lVar5,&local_64,2);
            local_64 = CONCAT22(local_64._2_2_,0xffff);
            func_0x000188141da0(lVar5,&local_64,2);
            for (; uVar13 != 0; uVar13 = uVar13 - 1) {
              local_64 = local_64 & 0xffffff00;
              func_0x000188141da0(lVar5,&local_64,1);
            }
            if ((uVar15 & 0xffff) != 0) {
              uVar17 = 0;
              do {
                lVar14 = _cmap_bf_set_get_unichars
                                   (*(undefined8 *)(lVar10 + 0x10),
                                    *(undefined2 *)(lVar7 + uVar17 * 2),lVar6);
                local_64 = 0xffffffff;
                func_0x000188141da0(lVar5,&local_64,4);
                local_64 = 0xffffffff;
                func_0x000188141da0(lVar5,&local_64,4);
                uVar12 = (uint)lVar14;
                local_64 = CONCAT22(local_64._2_2_,
                                    (ushort)((ulong)lVar14 >> 8) & 0xff |
                                    (ushort)((uVar12 & 0xff00ff) << 8));
                func_0x000188141da0(lVar5,&local_64,2);
                if (lVar14 != 0) {
                  lVar8 = 0;
                  do {
                    uVar1 = *(ushort *)(lVar6 + lVar8 * 2);
                    local_64 = CONCAT22(local_64._2_2_,uVar1 >> 8 | uVar1 << 8);
                    func_0x000188141da0(lVar5,&local_64,2);
                    lVar8 = lVar8 + 1;
                    lVar14 = lVar14 + -1;
                  } while (lVar14 != 0);
                }
                local_64 = local_64 & 0xffff0000;
                func_0x000188141da0(lVar5,&local_64,2);
                uVar12 = uVar11 + uVar12 * 2 + 0xc & 3;
                uVar11 = uVar12;
                while (uVar11 != 0) {
                  local_64 = local_64 & 0xffffff00;
                  func_0x000188141da0(lVar5,&local_64,1);
                  uVar12 = uVar12 - 1;
                  uVar11 = uVar12 & 0xffff;
                }
                uVar11 = 0;
                uVar17 = uVar17 + 1;
              } while (uVar17 != uVar16);
            }
            func_0x000188138390(lVar7);
            func_0x000188138390(lVar6);
          }
        }
      }
      uVar9 = func_0x000188141ce0(lVar5,*_DAT_1e00feaf8);
      func_0x000188141cc0(lVar5);
      func_0x000188141240(lVar5);
      return uVar9;
    }
  }
  return 0;
}



