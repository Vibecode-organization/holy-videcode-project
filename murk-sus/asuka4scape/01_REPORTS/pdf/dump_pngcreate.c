/* ==== _pdf_source_create_png_filter @ 183c5c3e0 size=572 ==== */

long _pdf_source_create_png_filter(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  ulong local_38;
  
  puVar2 = (undefined8 *)func_0x000188138460(1,0x38,0x10300405cad4b32);
  *(undefined4 *)(puVar2 + 1) = 1;
  puVar2[4] = 8;
  puVar2[3] = 1;
  puVar2[2] = 1;
  if (param_2 != 0) {
    local_38 = 0;
    iVar1 = FUN_183bd6c4c(param_2,"Predictor",&local_38);
    if (iVar1 != 0) {
      if ((local_38 - 10 < 6) || (local_38 - 1 < 2)) {
        *(int *)(puVar2 + 1) = (int)local_38;
      }
      else {
        _pdf_error("/%s is outside the range of allowed values.");
      }
    }
    iVar1 = FUN_183bd6c4c(param_2,"Colors",&local_38);
    if (iVar1 != 0) {
      if ((long)local_38 < 1) {
        _pdf_error("/%s is outside the range of allowed values.");
      }
      else {
        puVar2[2] = local_38;
      }
    }
    iVar1 = FUN_183bd6c4c(param_2,"BitsPerComponent",&local_38);
    if (iVar1 != 0) {
      if ((local_38 < 0x11) && ((1L << (local_38 & 0x3f) & 0x10116U) != 0)) {
        puVar2[4] = local_38;
      }
      else {
        _pdf_error("/%s is outside the range of allowed values.");
      }
    }
    iVar1 = FUN_183bd6c4c(param_2,"Columns",&local_38);
    if (iVar1 != 0) {
      if ((long)local_38 < 1) {
        _pdf_error("/%s is outside the range of allowed values.");
      }
      else {
        puVar2[3] = local_38;
      }
    }
  }
  func_0x000188141250(param_1);
  *puVar2 = param_1;
  uVar5 = puVar2[4];
  uVar6 = 0;
  if (uVar5 != 0) {
    uVar6 = 0xfffffffffffffff8 / uVar5;
  }
  if ((ulong)puVar2[2] <= uVar6) {
    uVar5 = uVar5 * puVar2[2];
    puVar2[5] = uVar5 + 7 >> 3;
    uVar6 = 0;
    if (uVar5 != 0) {
      uVar6 = 0xfffffffffffffff8 / uVar5;
    }
    if ((ulong)puVar2[3] <= uVar6) {
      uVar6 = puVar2[3] * uVar5 + 7 >> 3;
      uVar3 = func_0x000188138460(1,uVar6,0xf8e85256);
      puVar2[6] = uVar3;
      lVar4 = _CGPDFSourceCreateInternal(uVar6);
      if (lVar4 != 0) {
        *(undefined1 *)(lVar4 + 0xd1) = 1;
        *(undefined8 *)(lVar4 + 0x38) = 0x8010000003c5c624;
        *(undefined8 *)(lVar4 + 0x30) = 0x8010000003c5c61c;
        *(undefined8 *)(lVar4 + 0x48) = 0;
        *(undefined8 *)(lVar4 + 0x40) = 0x8020000003c5c83c;
        *(undefined8 **)(lVar4 + 0x50) = puVar2;
        return lVar4;
      }
    }
  }
  _png_filter_finalize(puVar2);
  return 0;
}



