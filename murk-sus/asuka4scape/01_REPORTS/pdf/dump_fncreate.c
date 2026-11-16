/* ==== FUN_183f9230c @ 183f9230c size=88 ==== */

undefined8 * FUN_183f9230c(void)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined8 *)func_0x000188138460(1,0x18,0x20040960023a9);
  func_0x000188142e40(puVar1,"CGPDFNamedAlloc_Graphics");
  if (puVar1 != (undefined8 *)0x0) {
    uVar2 = FUN_183bdb998();
    *puVar1 = uVar2;
  }
  return puVar1;
}



/* ==== FUN_183f92364 @ 183f92364 size=96 ==== */

undefined8 * FUN_183f92364(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined8 *)func_0x000188138460(1,0x18,0x20040960023a9);
  func_0x000188142e40(puVar1,"CGPDFNamedAlloc_Graphics");
  if (puVar1 != (undefined8 *)0x0) {
    uVar2 = FUN_183bdbacc(*param_1);
    *puVar1 = uVar2;
  }
  return puVar1;
}



/* ==== FUN_183f923c4 @ 183f923c4 size=156 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183f923fc: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183f92434: Changing call to branch */

void FUN_183f923c4(long *param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  if (param_1 == (long *)0x0) {
    return;
  }
  plVar2 = (long *)param_1[1];
  if (plVar2 != (long *)0x0) {
    do {
      if (plVar2[1] != 0) {
        _CGPDFGStateReleaseProperties(plVar2[1]);
        halt_baddata();
      }
      plVar2 = (long *)*plVar2;
    } while (plVar2 != (long *)0x0);
    plVar2 = (long *)param_1[1];
    while (plVar2 != (long *)0x0) {
      plVar2 = (long *)*plVar2;
      func_0x000188138390();
    }
  }
  if (*param_1 == 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183f92458);
      (*pcVar1)();
    }
  }
  else {
    _CGPDFGStateReleaseProperties(*param_1);
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== FUN_183f924cc @ 183f924cc size=144 ==== */

void FUN_183f924cc(undefined8 *param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  
  if (param_1 != (undefined8 *)0x0) {
    if (param_1[2] != 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183f92514);
        (*pcVar1)();
      }
      _pdf_error("warning: `q\' encountered within text object.");
      return;
    }
    uVar2 = FUN_183bdbacc(*param_1);
    uVar4 = param_1[1];
    puVar3 = (undefined8 *)func_0x000188138460(1,0x10,0xa0040aff93c70);
    *puVar3 = uVar4;
    puVar3[1] = uVar2;
    param_1[1] = puVar3;
  }
  return;
}



/* ==== FUN_183f9255c @ 183f9255c size=144 ==== */

void FUN_183f9255c(long *param_1)

{
  code *pcVar1;
  char *pcVar2;
  long *plVar3;
  long lVar4;
  ulong unaff_x30;
  
  if (param_1 == (long *)0x0) {
    return;
  }
  if (param_1[2] == 0) {
    plVar3 = (long *)param_1[1];
    if (plVar3 != (long *)0x0) {
      lVar4 = *param_1;
      if (lVar4 != 0) {
        _CGPDFGStateReleaseProperties(lVar4);
        func_0x000188138390(lVar4);
        plVar3 = (long *)param_1[1];
      }
      lVar4 = *plVar3;
      *param_1 = plVar3[1];
      func_0x000188138390();
      param_1[1] = lVar4;
      return;
    }
    pcVar2 = "warning: gstate stack underflow.";
  }
  else {
    pcVar2 = "warning: `Q\' encountered within text object.";
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    _pdf_error(pcVar2);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183f9259c);
  (*pcVar1)();
}



/* ==== FUN_183f92aa8 @ 183f92aa8 size=220 ==== */

long FUN_183f92aa8(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  
  lVar1 = FUN_183de74c8(param_1,&DAT_1e222e500);
  if (lVar1 != 0) {
    FUN_183de7690(lVar1,param_2);
    lVar4 = 0;
    lVar5 = 0x14;
    do {
      uVar3 = (ulong)*(uint *)(_names + lVar4 * 4);
      uVar2 = FUN_183de7594(param_2,uVar3);
      if ((uVar2 & 1) == 0) {
        if ((0x1fffeffffU >> (uVar3 & 0x3f) & 1) == 0) {
          FUN_183b75268("%s: Unsupported delegate callback: %d.");
        }
        else {
          *(undefined8 *)(lVar1 + *(long *)(&DAT_184266b38 + uVar3 * 8)) = 0;
        }
      }
      lVar4 = lVar4 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  return lVar1;
}



/* ==== FUN_183f92f24 @ 183f92f24 size=232 ==== */

void FUN_183f92f24(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  
  fVar13 = *param_2;
  fVar14 = param_2[1];
  fVar5 = param_3[4];
  fVar1 = param_3[5];
  fVar6 = *param_3;
  fVar2 = param_3[1];
  fVar3 = param_3[8];
  fVar4 = param_3[9];
  fVar15 = param_2[2];
  fVar16 = param_2[3];
  *param_1 = fVar14 * fVar5 + fVar6 * fVar13 + fVar3 * fVar15;
  param_1[1] = fVar14 * fVar1 + fVar2 * fVar13 + fVar4 * fVar15;
  fVar8 = param_3[6];
  fVar7 = param_3[7];
  fVar10 = param_3[2];
  fVar9 = param_3[3];
  fVar12 = param_3[10];
  fVar11 = param_3[0xb];
  param_1[2] = fVar14 * fVar8 + fVar10 * fVar13 + fVar12 * fVar15;
  param_1[3] = fVar16 + fVar14 * fVar7 + fVar9 * fVar13 + fVar11 * fVar15;
  fVar13 = param_2[4];
  fVar14 = param_2[5];
  fVar15 = param_2[6];
  fVar16 = param_2[7];
  param_1[4] = fVar5 * fVar14 + fVar6 * fVar13 + fVar3 * fVar15;
  param_1[5] = fVar1 * fVar14 + fVar2 * fVar13 + fVar4 * fVar15;
  param_1[6] = fVar8 * fVar14 + fVar10 * fVar13 + fVar12 * fVar15;
  param_1[7] = fVar7 * fVar14 + fVar9 * fVar13 + fVar11 * fVar15 + fVar16;
  fVar14 = param_2[8];
  fVar15 = param_2[9];
  fVar13 = param_2[10];
  fVar16 = param_2[0xb];
  param_1[8] = fVar5 * fVar15 + fVar6 * fVar14 + fVar3 * fVar13;
  param_1[9] = fVar1 * fVar15 + fVar2 * fVar14 + fVar4 * fVar13;
  param_1[10] = fVar8 * fVar15 + fVar10 * fVar14 + fVar12 * fVar13;
  param_1[0xb] = fVar7 * fVar15 + fVar9 * fVar14 + fVar11 * fVar13 + fVar16;
  return;
}



