// FUN_fffffff0081fb8ec @ fffffff0081fb8ec size=364

undefined8
FUN_fffffff0081fb8ec
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,ulong param_5)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  uint uVar7;
  byte bVar8;
  
  uVar4 = FUN_fffffff0081e4c98();
  if ((int)uVar4 == 0) {
    return uVar4;
  }
  uVar1 = (uint)(param_5 >> 0x20);
  uVar7 = uVar1 & 0xf;
  if ((param_5 >> 0x20 & 0xf) == 0) {
    uVar7 = 5;
  }
  *(char *)(param_1 + 0x59) = (char)uVar7;
  *(ulong *)(param_1 + 0x70) = param_5;
  if (((param_5 & 0x1008000000000) == 0x8000000000) &&
     ((0x401fU >> (ulong)(uVar7 - 1 & 0x1f) & 1) != 0)) {
    uVar7 = (uint)(byte)(&DAT_fffffff007115138)[(int)(uVar7 - 1)];
  }
  if (uVar7 < 0xd) {
    bVar2 = 1;
    if ((1 << (ulong)(uVar7 & 0x1f) & 0x1b00U) == 0) {
      if (uVar7 == 10) {
        bVar8 = 0x10;
        goto LAB_fffffff0081fb998;
      }
      goto LAB_fffffff0081fba50;
    }
  }
  else {
LAB_fffffff0081fba50:
    bVar2 = 0;
  }
  bVar8 = 0x10;
  if (!(bool)((param_5 & 0x8000000000) == 0 & bVar2)) {
    bVar8 = 0;
  }
LAB_fffffff0081fb998:
  *(byte *)(param_1 + 0x58) =
       (byte)(uVar1 >> 4) & 0x20 | (byte)(uVar1 >> 5) & 8 | bVar8 | *(byte *)(param_1 + 0x58) & 0xc3
  ;
  lVar5 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(param_1 + 0x18),&DAT_fffffff00ae21bd0);
  if (((lVar5 != 0) &&
      (plVar6 = (long *)thunk_EXT_FUN_801100000297dd00(*(undefined8 *)(param_1 + 0x18)),
      plVar6 != (long *)0x0)) && (iVar3 = (**(code **)(*plVar6 + 0xa8))(), iVar3 == 2)) {
    *(byte *)(param_1 + 0x58) = *(byte *)(param_1 + 0x58) | 8;
    thunk_EXT_FUN_8011000003890f30(param_4,&DAT_fffffff00ae21bd0);
  }
  thunk_EXT_FUN_801100000297b734
            (param_1,*(undefined1 *)(param_1 + 0x59),*(undefined4 *)(param_1 + 0x14));
  return uVar4;
}

