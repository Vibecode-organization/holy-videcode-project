/* ==== _get_type1_glyph_vector @ 183f9abe8 size=500 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _get_type1_glyph_vector(long param_1,long param_2,int param_3,long param_4)

{
  uint uVar1;
  long lVar2;
  byte *pbVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  byte local_6c [2];
  undefined2 local_6a;
  byte *local_68;
  
  if (*(int *)(param_1 + 8) == -1) {
    if (param_2 != 0) {
      (**(code **)(*(long *)(param_2 + 0x10) + 0xf8))(*(undefined8 *)(param_2 + 0x70),param_4);
    }
    if (*(long *)(param_1 + 0x20) != 0) {
      lVar7 = 0;
      lVar5 = 0;
      lVar4 = _DAT_1e0186218 + 0x83c;
      do {
        pbVar3 = *(byte **)(*(long *)(param_1 + 0x20) + lVar5 * 8);
        if (pbVar3 != (byte *)0x0) {
          if (((param_3 != 0) && (lVar6 = func_0x0001881386f0(pbVar3), lVar6 == 1)) &&
             (*pbVar3 - 0x61 < 0x1a)) {
            local_6c[0] = (byte)*(undefined4 *)(lVar4 + (ulong)(uint)*pbVar3 * 4);
            local_6c[1] = 0;
            pbVar3 = local_6c;
          }
          local_6a = 0;
          local_68 = pbVar3;
          if (param_2 != 0) {
            (**(code **)(*(long *)(param_2 + 0x10) + 0x120))
                      (*(undefined8 *)(param_2 + 0x70),&local_68,&local_6a,1);
          }
          *(undefined2 *)(param_4 + lVar5 * 2) = local_6a;
        }
        lVar5 = lVar5 + 1;
        lVar7 = lVar7 + 8;
      } while (lVar7 != 0x800);
    }
  }
  else {
    uVar1 = *(int *)(param_1 + 8) - 1;
    if (uVar1 < 7) {
      lVar4 = (&DAT_1e05d8818)[uVar1];
    }
    else {
      lVar4 = 0;
    }
    lVar6 = 0;
    lVar7 = 0;
    lVar5 = _DAT_1e0186218 + 0x83c;
    do {
      if ((*(long *)(param_1 + 0x20) == 0) ||
         (pbVar3 = *(byte **)(*(long *)(param_1 + 0x20) + lVar7 * 8), pbVar3 == (byte *)0x0)) {
        if (lVar4 != 0) {
          pbVar3 = *(byte **)(lVar4 + lVar7 * 8);
          goto LAB_183f9ad34;
        }
        pbVar3 = (byte *)0x0;
      }
      else {
LAB_183f9ad34:
        if (((param_3 != 0) && (pbVar3 != (byte *)0x0)) &&
           ((lVar2 = func_0x0001881386f0(pbVar3), lVar2 == 1 && (*pbVar3 - 0x61 < 0x1a)))) {
          local_6c[0] = (byte)*(undefined4 *)(lVar5 + (ulong)(uint)*pbVar3 * 4);
          local_6c[1] = 0;
          pbVar3 = local_6c;
        }
      }
      local_6a = 0;
      local_68 = pbVar3;
      if (param_2 != 0) {
        (**(code **)(*(long *)(param_2 + 0x10) + 0x120))
                  (*(undefined8 *)(param_2 + 0x70),&local_68,&local_6a,1);
      }
      *(undefined2 *)(param_4 + lVar7 * 2) = local_6a;
      lVar7 = lVar7 + 1;
      lVar6 = lVar6 + 8;
    } while (lVar6 != 0x800);
  }
  return;
}



/* ==== _get_builtin_type1_names @ 183f9b6d0 size=732 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _get_builtin_type1_names(undefined8 param_1,long param_2,byte *param_3)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  undefined1 *puVar6;
  ulong uVar7;
  long lVar8;
  undefined8 uVar9;
  byte bVar10;
  ulong extraout_x8;
  ulong uVar11;
  long extraout_x12;
  byte bVar12;
  byte *pbVar13;
  long lVar14;
  undefined1 auStack_290 [8];
  undefined1 *local_288;
  byte *local_280;
  undefined1 *local_278;
  undefined2 local_270 [256];
  long local_70;
  
  local_70 = *_DAT_1e0186220;
  local_280 = param_3;
  lVar4 = FUN_183bf35f0();
  lVar5 = 0;
  if (lVar4 != 0) {
    (**(code **)(*(long *)(lVar4 + 0x10) + 0xf8))(*(undefined8 *)(lVar4 + 0x70),local_270);
    lVar5 = (**(code **)(*(long *)(lVar4 + 0x10) + 0x128))(*(undefined8 *)(lVar4 + 0x70));
  }
  lVar1 = lVar5 + 1;
  local_288 = auStack_290;
  (*_DAT_1e1f91910)(lVar5 + 2);
  local_278 = auStack_290 + -extraout_x12;
  puVar6 = (undefined1 *)0x0;
  if (lVar1 != -1) {
    puVar6 = local_278;
  }
  if (0x81 < extraout_x8) {
    puVar6 = (undefined1 *)func_0x000188138470(lVar1,0x936cae86);
  }
  lVar5 = 0;
  lVar14 = 0x100;
  do {
    if ((lVar4 == 0) ||
       (uVar7 = (**(code **)(*(long *)(lVar4 + 0x10) + 0x130))
                          (*(undefined8 *)(lVar4 + 0x70),local_270[lVar5],puVar6,lVar1),
       (uVar7 & 1) == 0)) {
      *(undefined8 *)(param_2 + lVar5 * 8) = 0;
    }
    else {
      lVar8 = func_0x0001881386f0(puVar6);
      uVar9 = func_0x000188138470(lVar8 + 1,0x521a0281);
      func_0x000188142e40(uVar9,"CGPDFNamedAlloc_Font");
      *(undefined8 *)(param_2 + lVar5 * 8) = uVar9;
      func_0x00018814d5d0(uVar9,puVar6);
    }
    lVar5 = lVar5 + 1;
    lVar14 = lVar14 + -1;
  } while (lVar14 != 0);
  if (puVar6 != local_278) {
    func_0x000188138390(puVar6);
  }
  lVar1 = _DAT_1e0186218;
  uVar7 = 0;
  lVar5 = 0;
  bVar12 = 1;
  lVar4 = 0x100;
  local_278 = (undefined1 *)(_DAT_1e0186218 + 0x3c);
  do {
    pbVar13 = *(byte **)(param_2 + lVar5 * 8);
    if ((pbVar13 != (byte *)0x0) && (iVar2 = func_0x0001881386b0(pbVar13,".notdef"), iVar2 != 0)) {
      lVar14 = func_0x0001881386f0(pbVar13);
      if (lVar14 != 3) {
LAB_183f9b958:
        bVar10 = 0;
        goto LAB_183f9b95c;
      }
      bVar12 = *pbVar13;
      if ((uVar7 & 0xff) == 0) {
        if ((char)bVar12 < 0) {
          iVar2 = func_0x00018814d1b0((long)(char)bVar12,0x100,0);
          uVar11 = (ulong)iVar2;
        }
        else {
          uVar11 = (ulong)*(uint *)((long)local_278 + (ulong)(uint)(int)(char)bVar12 * 4) & 0x100;
        }
        bVar10 = 0;
        uVar7 = (long)(char)bVar12;
        if (uVar11 == 0) goto LAB_183f9b95c;
      }
      else if ((uint)bVar12 != ((uint)uVar7 & 0xff)) goto LAB_183f9b958;
      bVar12 = pbVar13[1];
      if ((char)bVar12 < 0) {
        uVar3 = func_0x00018814d1b0((long)(char)bVar12,0x10000,0);
      }
      else {
        uVar3 = *(uint *)(lVar1 + 0x3c + (ulong)(uint)(int)(char)bVar12 * 4) & 0x10000;
      }
      bVar10 = 0;
      if (uVar3 == 0) goto LAB_183f9b95c;
      bVar12 = pbVar13[2];
      if ((char)bVar12 < 0) {
        iVar2 = func_0x00018814d1b0((long)(char)bVar12,0x10000,0);
        uVar11 = (ulong)iVar2;
      }
      else {
        uVar11 = (ulong)*(uint *)(lVar1 + 0x3c + (ulong)(uint)(int)(char)bVar12 * 4) & 0x10000;
      }
      bVar12 = 0;
      bVar10 = 0;
      if (uVar11 == 0) goto LAB_183f9b95c;
    }
    lVar5 = lVar5 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  bVar10 = bVar12 ^ 1;
LAB_183f9b95c:
  *local_280 = bVar10;
  if (*_DAT_1e0186220 == local_70) {
    return;
  }
  func_0x000188138130();
  return;
}



/* ==== _get_type1_encoding @ 183f9d184 size=8 ==== */

/* WARNING: Control flow encountered bad instruction data */

void _get_type1_encoding(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



