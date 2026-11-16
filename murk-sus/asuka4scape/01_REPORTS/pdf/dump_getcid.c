/* ==== FUN_183fe2778 @ 183fe2778 size=152 ==== */

void FUN_183fe2778(long param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  
  if (param_1 != 0) {
    pcVar2 = *(code **)(param_1 + 0x10);
    puVar1 = (undefined4 *)func_0x000188138470(0x38,0x1050040cac2ec8c);
    *puVar1 = 0;
    *(undefined8 *)(puVar1 + 3) = 0x8000000180000001;
    *(undefined8 *)(puVar1 + 1) = 1;
    *(undefined8 *)(puVar1 + 5) = 0x7fc000007fc00000;
    *(undefined8 *)(puVar1 + 10) = 0;
    *(undefined8 *)(puVar1 + 0xc) = 0;
    *(undefined8 *)(puVar1 + 8) = 0;
    if ((pcVar2 != _the_empty_shape) &&
       (*(int *)(pcVar2 + (long)*(int *)(pcVar2 + 4) * 4) != 0x7fffffff)) {
      puVar1[1] = 1;
      *(code **)(puVar1 + 8) = pcVar2;
      *(code **)(puVar1 + 10) = pcVar2 + 8;
    }
  }
  return;
}



/* ==== FUN_183fe2818 @ 183fe2818 size=56 ==== */

void FUN_183fe2818(long param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = 0xffffffff;
  if (param_2 == 0) {
    uVar1 = 1;
  }
  uVar2 = 0xffffffff;
  if (param_3 == 0) {
    uVar2 = 1;
  }
  FUN_183e6a52c(param_1,*(undefined8 *)(param_1 + 0x10),uVar1,uVar2);
  return;
}



/* ==== FUN_183fe28c8 @ 183fe28c8 size=112 ==== */

void FUN_183fe28c8(undefined4 param_1,double *param_2)

{
  int iVar1;
  undefined8 local_30;
  undefined8 local_28;
  
  local_30 = 0;
  local_28 = 0;
  iVar1 = FUN_183e6a5f4(param_1,(long)&local_28 + 4,&local_28,(long)&local_30 + 4,&local_30);
  if (iVar1 != 0) {
    *param_2 = (double)local_28._4_4_;
    param_2[1] = (double)(int)local_28;
    param_2[2] = (double)(local_30._4_4_ - local_28._4_4_);
    param_2[3] = (double)((int)local_30 - (int)local_28);
  }
  return;
}



/* ==== FUN_183fe2938 @ 183fe2938 size=80 ==== */

void FUN_183fe2938(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_183c19214("CGRegionForwardEnumeratorGetNextBounds",0x45,
                  "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/Regions/CGRegionEnumerator.c"
                  ,"e != NULL","region enumerator is missing");
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183fe2948);
    (*pcVar1)();
  }
  FUN_183e6a7d0();
  return;
}



/* ==== FUN_183fe2988 @ 183fe2988 size=112 ==== */

void FUN_183fe2988(undefined4 param_1,double *param_2)

{
  int iVar1;
  undefined8 local_30;
  undefined8 local_28;
  
  local_30 = 0;
  local_28 = 0;
  iVar1 = FUN_183fe2938(param_1,(long)&local_28 + 4,&local_28,(long)&local_30 + 4,&local_30);
  if (iVar1 != 0) {
    *param_2 = (double)local_28._4_4_;
    param_2[1] = (double)(int)local_28;
    param_2[2] = (double)(local_30._4_4_ - local_28._4_4_);
    param_2[3] = (double)((int)local_30 - (int)local_28);
  }
  return;
}



/* ==== FUN_183fe29f8 @ 183fe29f8 size=48 ==== */

long FUN_183fe29f8(long param_1)

{
  if (param_1 != 0) {
    func_0x000188141250(param_1);
  }
  return param_1;
}



/* ==== FUN_183fe2fcc @ 183fe2fcc size=104 ==== */

bool FUN_183fe2fcc(long param_1,long *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x48);
  if (iVar1 < 1) {
    _pdf_error("stack underflow.");
  }
  else {
    if (param_2 != (long *)0x0) {
      *param_2 = *(long *)(param_1 + 0x50) + (ulong)(iVar1 - 1) * 0x28;
    }
    *(int *)(param_1 + 0x48) = iVar1 + -1;
  }
  return 0 < iVar1;
}



/* ==== FUN_183fe3084 @ 183fe3084 size=4 ==== */

undefined8 FUN_183fe3084(void)

{
  _pdf_error("stack underflow.");
  return 0;
}



/* ==== FUN_183fe3088 @ 183fe3088 size=36 ==== */

undefined8 FUN_183fe3088(void)

{
  _pdf_error("stack underflow.");
  return 0;
}



/* ==== FUN_183fe30ac @ 183fe30ac size=124 ==== */

undefined8 FUN_183fe30ac(long param_1,undefined8 *param_2)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x48) < 1) {
    _pdf_error("stack underflow.");
    return 0;
  }
  uVar3 = *(int *)(param_1 + 0x48) - 1;
  lVar1 = *(long *)(param_1 + 0x50) + (ulong)uVar3 * 0x28;
  *(uint *)(param_1 + 0x48) = uVar3;
  if ((*(long *)(param_1 + 0x50) != 0) && (iVar2 = *(int *)(lVar1 + 8), iVar2 == 0xc || iVar2 == 3))
  {
    if (param_2 != (undefined8 *)0x0) {
      *param_2 = *(undefined8 *)(lVar1 + 0x20);
    }
    return 1;
  }
  return 0;
}



