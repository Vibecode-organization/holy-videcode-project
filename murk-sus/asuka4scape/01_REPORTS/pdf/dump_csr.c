/* ==== _cmap_csr_set_add_codespace_range @ 183bf7414 size=100 ==== */

void _cmap_csr_set_add_codespace_range
               (byte *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  
  lVar1 = _csr_create(param_2,param_3,param_4);
  if (lVar1 != 0) {
    func_0x0001881404a0(*(undefined8 *)(param_1 + 8),lVar1);
    if ((uint)param_2 < (uint)*param_1) {
      *param_1 = (byte)param_2;
    }
    if ((uint)param_1[1] < (uint)param_2) {
      param_1[1] = (byte)param_2;
    }
  }
  return;
}



/* ==== _csr_create @ 183bf7478 size=324 ==== */

undefined1 * _csr_create(uint param_1,uint param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  undefined1 *puVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  uint uVar8;
  byte local_68 [4];
  byte local_64 [4];
  
  if (param_1 != 0) {
    puVar3 = (undefined1 *)func_0x000188138460(1,0x20,0x102004001854a68);
    if (puVar3 != (undefined1 *)0x0) {
      lVar4 = 0;
      uVar7 = (ulong)param_1;
      uVar8 = param_1 * 8 - 8;
      uVar6 = uVar7;
      uVar5 = uVar8;
      do {
        local_64[lVar4] = (byte)(param_2 >> (ulong)(uVar5 & 0x1f));
        lVar4 = lVar4 + 1;
        uVar5 = uVar5 - 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
      lVar4 = 0;
      uVar6 = uVar7;
      uVar5 = uVar8;
      do {
        local_68[lVar4] = (byte)(param_3 >> (ulong)(uVar5 & 0x1f));
        lVar4 = lVar4 + 1;
        uVar5 = uVar5 - 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
      lVar4 = 0;
      do {
        bVar1 = local_64[lVar4];
        bVar2 = local_68[lVar4];
        if (bVar2 < bVar1) {
          _pdf_log("Incorrect start/end range ordering; fixing.");
          uVar5 = (uint)(bVar2 ^ bVar1) << (ulong)(uVar8 & 0x1f) & 0xff;
          param_2 = uVar5 ^ param_2;
          param_3 = uVar5 ^ param_3;
        }
        lVar4 = lVar4 + 1;
        uVar8 = uVar8 - 8;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
      *puVar3 = (char)param_1;
      *(uint *)(puVar3 + 4) = param_2;
      *(uint *)(puVar3 + 8) = param_3;
    }
    return puVar3;
  }
  return (undefined1 *)0x0;
}



/* ==== _check_dimension @ 183bf76e4 size=208 ==== */

ulong _check_dimension(ulong param_1,uint param_2,uint param_3)

{
  int iVar1;
  ulong uVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  char local_8 [4];
  char local_4 [4];
  
  iVar1 = (int)param_1;
  if (iVar1 - 5U < 0xfffffffc) {
    return 0;
  }
  lVar4 = 0;
  uVar2 = param_1 & 0xffffffff;
  uVar3 = iVar1 * 8 - 8;
  uVar6 = uVar2;
  uVar5 = uVar3;
  do {
    local_4[lVar4] = (char)(param_2 >> (ulong)(uVar5 & 0x1f));
    lVar4 = lVar4 + 1;
    uVar5 = uVar5 - 8;
    uVar6 = uVar6 - 1;
  } while (uVar6 != 0);
  lVar4 = 0;
  do {
    local_8[lVar4] = (char)(param_3 >> (ulong)(uVar3 & 0x1f));
    lVar4 = lVar4 + 1;
    uVar3 = uVar3 - 8;
    uVar2 = uVar2 - 1;
  } while (uVar2 != 0);
  if (((iVar1 == 2) && (param_2 == 0)) && (param_3 == 0xffff)) {
    param_1 = 1;
  }
  else {
    uVar6 = (ulong)(iVar1 - 1U);
    if (iVar1 - 1U != 0) {
      lVar4 = 0;
      do {
        uVar6 = uVar6 - 1;
        param_1 = (ulong)(local_4[lVar4] == local_8[lVar4]);
        if (local_4[lVar4] != local_8[lVar4]) {
          return param_1;
        }
        lVar4 = lVar4 + 1;
      } while (uVar6 != 0);
    }
  }
  return param_1;
}



