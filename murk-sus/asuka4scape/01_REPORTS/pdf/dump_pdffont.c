/* ==== _CGFontCreateWithPDFFontDataAndZapfData @ 183bf4800 size=188 ==== */

long _CGFontCreateWithPDFFontDataAndZapfData(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  if ((DAT_1eb056bd2 & 1) == 0) {
    if (DAT_1edf35ce0 != -1) {
      func_0x00018813aad0(&DAT_1edf35ce0,&DAT_1e223ef28);
    }
    if (DAT_1eb0563cb != '\x01') {
      if (param_1 == 0) {
        return 0;
      }
      lVar1 = FUN_183b34ab8();
      if (lVar1 != 0) {
        lVar2 = (**(code **)(*(long *)(lVar1 + 0x10) + 0x28))(param_1,param_2);
        *(long *)(lVar1 + 0x70) = lVar2;
        if (lVar2 == 0) {
          func_0x000188141240(lVar1);
          return 0;
        }
        return lVar1;
      }
      return 0;
    }
  }
  FUN_183b75268("Attempt to create CGFont from data in Lockdown Mode for Fonts");
  return 0;
}



/* ==== _create_private_data_with_pdf_font_data_and_zapf_data @ 183bf48bc size=84 ==== */

void _create_private_data_with_pdf_font_data_and_zapf_data(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  
  if ((param_1 != 0) && (lVar1 = func_0x00018814c870(), lVar1 != 0)) {
    puVar2 = (undefined8 *)func_0x000188138460(1,0x20,0x1060040d8c947d5);
    *puVar2 = 1;
    puVar2[1] = lVar1;
  }
  return;
}



