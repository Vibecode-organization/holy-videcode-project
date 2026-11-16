// FUN_fffffff0099554f4 @ fffffff0099554f4 size=180

uint FUN_fffffff0099554f4(long param_1)

{
  bool bVar1;
  uint uVar2;
  long lVar3;
  bool bVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  
  pcVar6 = (char *)(param_1 + 0x10);
  if (*pcVar6 == '\x03') {
    uVar5 = 1;
  }
  else {
    uVar5 = 1;
    do {
      lVar3 = 0;
      uVar7 = 1;
      bVar1 = true;
      do {
        bVar4 = bVar1;
        uVar2 = FUN_fffffff00994b9f8
                          (*(undefined8 *)(*(long *)(param_1 + 0x50) + 0x148),
                           *(long *)(param_1 + 0x18) + lVar3 * 0x40);
        uVar7 = uVar7 & uVar2;
        lVar3 = 1;
        bVar1 = false;
      } while (bVar4);
      if ((*pcVar6 != -0x7e) || (param_1 = *(long *)(param_1 + 0x30), param_1 == 0))
      goto LAB_fffffff009955590;
      uVar5 = uVar5 & uVar7;
      pcVar6 = (char *)(param_1 + 0x10);
    } while (*pcVar6 != '\x03');
    uVar7 = 1;
LAB_fffffff009955590:
    uVar5 = uVar5 & uVar7;
  }
  return uVar5;
}

