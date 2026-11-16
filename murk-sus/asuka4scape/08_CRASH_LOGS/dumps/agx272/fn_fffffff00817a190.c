// FUN_fffffff00817a190 @ fffffff00817a190 size=316

void FUN_fffffff00817a190(long param_1,int param_2,long param_3)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  
  if (param_2 != 3) {
    if (param_2 == 1) {
      uVar3 = 0;
      *(undefined1 *)(param_1 + 0x1ac3c) = 0;
    }
    else {
      if (param_2 != 0) {
        return;
      }
      *(undefined1 *)(param_1 + 0x1ac3c) = 1;
      uVar3 = *(uint *)(param_1 + 0x1ac40);
    }
    goto LAB_fffffff00817a230;
  }
  *(undefined4 *)(param_1 + 0x1ac40) = 0;
  bVar2 = *(byte *)(param_3 + 0x10b2);
  bVar1 = (bVar2 & 1) != 0;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x1ac40) = 1;
    bVar2 = *(byte *)(param_3 + 0x10b2);
  }
  uVar3 = (uint)bVar1;
  if ((bVar2 >> 1 & 1) != 0) {
    uVar3 = uVar3 | 2;
    *(uint *)(param_1 + 0x1ac40) = uVar3;
    bVar2 = *(byte *)(param_3 + 0x10b2);
  }
  if ((bVar2 >> 2 & 1) == 0) {
    if ((bVar2 >> 3 & 1) != 0) goto LAB_fffffff00817a248;
LAB_fffffff00817a208:
    if ((bVar2 >> 4 & 1) != 0) goto LAB_fffffff00817a258;
LAB_fffffff00817a20c:
    if ((bVar2 >> 5 & 1) != 0) goto LAB_fffffff00817a268;
LAB_fffffff00817a210:
    if ((bVar2 >> 6 & 1) != 0) goto LAB_fffffff00817a278;
LAB_fffffff00817a214:
    if ((char)bVar2 < '\0') goto LAB_fffffff00817a288;
LAB_fffffff00817a218:
    bVar2 = *(byte *)(param_3 + 0x10b3);
  }
  else {
    uVar3 = uVar3 | 4;
    *(uint *)(param_1 + 0x1ac40) = uVar3;
    bVar2 = *(byte *)(param_3 + 0x10b2);
    if ((bVar2 >> 3 & 1) == 0) goto LAB_fffffff00817a208;
LAB_fffffff00817a248:
    uVar3 = uVar3 | 8;
    *(uint *)(param_1 + 0x1ac40) = uVar3;
    bVar2 = *(byte *)(param_3 + 0x10b2);
    if ((bVar2 >> 4 & 1) == 0) goto LAB_fffffff00817a20c;
LAB_fffffff00817a258:
    uVar3 = uVar3 | 0x10;
    *(uint *)(param_1 + 0x1ac40) = uVar3;
    bVar2 = *(byte *)(param_3 + 0x10b2);
    if ((bVar2 >> 5 & 1) == 0) goto LAB_fffffff00817a210;
LAB_fffffff00817a268:
    uVar3 = uVar3 | 0x20;
    *(uint *)(param_1 + 0x1ac40) = uVar3;
    bVar2 = *(byte *)(param_3 + 0x10b2);
    if ((bVar2 >> 6 & 1) == 0) goto LAB_fffffff00817a214;
LAB_fffffff00817a278:
    uVar3 = uVar3 | 0x40;
    *(uint *)(param_1 + 0x1ac40) = uVar3;
    if (-1 < *(char *)(param_3 + 0x10b2)) goto LAB_fffffff00817a218;
LAB_fffffff00817a288:
    uVar3 = uVar3 | 0x80;
    *(uint *)(param_1 + 0x1ac40) = uVar3;
    bVar2 = *(byte *)(param_3 + 0x10b3);
  }
  if ((bVar2 & 1) != 0) {
    uVar3 = uVar3 | 0x100;
    *(uint *)(param_1 + 0x1ac40) = uVar3;
    bVar2 = *(byte *)(param_3 + 0x10b3);
  }
  if ((bVar2 >> 1 & 1) != 0) {
    uVar3 = uVar3 | 0x200;
    *(uint *)(param_1 + 0x1ac40) = uVar3;
    bVar2 = *(byte *)(param_3 + 0x10b3);
  }
  if ((bVar2 >> 2 & 1) == 0) {
    bVar2 = *(byte *)(param_1 + 0x1ac3c);
  }
  else {
    uVar3 = uVar3 | 0x400;
    *(uint *)(param_1 + 0x1ac40) = uVar3;
    bVar2 = *(byte *)(param_1 + 0x1ac3c);
  }
  if ((bVar2 & 1) == 0) {
    return;
  }
LAB_fffffff00817a230:
  *(uint *)(param_1 + 0x1ac44) = uVar3;
  return;
}

