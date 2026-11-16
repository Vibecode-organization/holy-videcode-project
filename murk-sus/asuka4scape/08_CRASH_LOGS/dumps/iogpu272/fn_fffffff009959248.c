// FUN_fffffff009959248 @ fffffff009959248 size=288

byte FUN_fffffff009959248(long param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4)

{
  long *plVar1;
  byte bVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  byte bVar8;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x18));
  if ((*(byte *)(param_1 + 0x5f) & 1) != 0) {
    FUN_fffffff009983ac4();
    bVar8 = 0;
    goto LAB_fffffff00995933c;
  }
  plVar1 = (long *)(*(long *)(param_1 + 0x50) + 0x48);
  LOAcquire();
  lVar3 = *plVar1;
  *plVar1 = lVar3 + 1;
  LORelease();
  *(undefined1 *)(param_1 + 0x5f) = 1;
  *(undefined1 *)(param_1 + 0x5e) = param_4;
  *(undefined8 *)(param_1 + 0x20) = param_3;
  FUN_fffffff009959368(lVar3,param_1,param_2);
  bVar8 = *(byte *)(param_1 + 0x5c);
  if ((bVar8 & 1) == 0) {
    if (*(long *)(param_1 + 0x40) == 0) {
      uVar4 = *(undefined8 *)(param_1 + 0x50);
      uVar5 = *(undefined8 *)(param_1 + 0x20);
      uVar7 = *(undefined8 *)(param_1 + 0x38);
      bVar2 = *(byte *)(param_1 + 0x5e);
      uVar6 = 3;
      goto LAB_fffffff009959334;
    }
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Command Buffer Processing Error\n");
    if (*(long *)(param_1 + 0x40) == 0) {
      uVar4 = *(undefined8 *)(param_1 + 0x50);
      uVar5 = *(undefined8 *)(param_1 + 0x20);
      uVar7 = *(undefined8 *)(param_1 + 0x38);
      bVar2 = *(byte *)(param_1 + 0x5e);
      uVar6 = 2;
LAB_fffffff009959334:
      FUN_fffffff0099596f0(uVar4,uVar5,uVar6,uVar7,bVar2 & 1);
    }
    else {
      FUN_fffffff0099597b4(param_1,2);
    }
  }
  bVar8 = bVar8 ^ 1;
LAB_fffffff00995933c:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x18));
  return bVar8 & 1;
}

