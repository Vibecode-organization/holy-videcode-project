// FUN_fffffff009c2b164 @ fffffff009c2b164 size=500

undefined8 FUN_fffffff009c2b164(byte *param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  undefined8 uVar5;
  long *plVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 uVar9;
  
  plVar4 = (long *)FUN_fffffff009c20000(param_2,param_3);
  if (plVar4 != (long *)0x0) {
    uVar2 = (**(code **)(*plVar4 + 0x90))();
    if (4 < uVar2) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface: %s component count is too large.\n");
      return 0;
    }
    iVar3 = (**(code **)(*plVar4 + 0x90))(plVar4);
    if (iVar3 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface: %s component count is too small.\n");
      return 0;
    }
    bVar1 = *param_1;
    if ((bVar1 != 0) && (uVar2 = (**(code **)(*plVar4 + 0x90))(plVar4), uVar2 != bVar1)) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface: %s component count mismatch.\n");
      return 0;
    }
    bVar1 = (**(code **)(*plVar4 + 0x90))(plVar4);
    *param_1 = bVar1;
    if (bVar1 != 0) {
      uVar8 = 0;
      uVar9 = *(undefined8 *)PTR_DAT_fffffff00806c9f8;
      do {
        uVar5 = (**(code **)(*plVar4 + 0x118))(plVar4,uVar8);
        plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(uVar5,uVar9);
        if (plVar6 != (long *)0x0) {
          uVar7 = (**(code **)(*plVar6 + 0xb0))();
          if (0xff < uVar7) {
            return 0;
          }
          *(char *)(param_4 + uVar8) = (char)uVar7;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *param_1);
    }
  }
  return 1;
}

