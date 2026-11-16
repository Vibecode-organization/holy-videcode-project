/* ==== FUN_183b83418 @ 183b83418 size=304 ==== */

long FUN_183b83418(long param_1)

{
  code *pcVar1;
  undefined *puVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  
  if (param_1 != 0) {
    lVar4 = *(long *)(param_1 + 0x20);
    if (lVar4 == 0) {
      puVar5 = (undefined8 *)func_0x000188138470(0x20,0x10e004015446177);
      uVar6 = *(undefined8 *)(param_1 + 0x28);
      puVar5[2] = *(undefined8 *)(param_1 + 0x30);
      uVar6 = func_0x000188141250(uVar6);
      *puVar5 = uVar6;
      uVar6 = func_0x000188140aa0(*(undefined8 *)(param_1 + 0x28));
      puVar5[3] = uVar6;
      if (*(long *)(param_1 + 0x18) == 0) {
        lVar4 = 1;
      }
      else {
        lVar4 = *(long *)(*(long *)(*(long *)(param_1 + 0x18) + 0x18) + 0x30) + 1;
      }
      puVar5[1] = lVar4;
      iVar3 = FUN_183b19234();
      pcVar1 = _create_function_extended_range;
      if (iVar3 == 0) {
        pcVar1 = _create_function_default_range;
      }
      puVar2 = &DAT_1e222e8a8;
      if (*(char *)(param_1 + 0x14) == '\0') {
        puVar2 = &DAT_1e222e8c0;
      }
      lVar4 = FUN_183b8324c(puVar5,1,_create_function_domain,puVar5[1],
                            pcVar1 + (puVar5[1] * -2 + 10) * 8,puVar2);
      *(long *)(param_1 + 0x20) = lVar4;
      if (lVar4 == 0) {
        func_0x000188141240(*puVar5);
        func_0x000188138390(puVar5);
        lVar4 = 0;
      }
    }
    return lVar4;
  }
                    /* WARNING: Subroutine does not return */
  FUN_183c19214("CGGradientGetFunction",0x1ce,
                "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/API/CGGradient.c"
                ,"g != NULL","gradient is missing");
}



