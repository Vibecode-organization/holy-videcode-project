// FUN_fffffff009c32794 @ fffffff009c32794 size=4

undefined8 FUN_fffffff009c32794(long param_1)

{
  bool bVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined1 *puStack_80;
  undefined1 *puStack_78;
  undefined4 uStack_70;
  undefined2 uStack_6c;
  undefined1 uStack_6a;
  long lStack_68;
  
  lStack_68 = *(long *)PTR_DAT_fffffff00806ca40;
  if (*(long *)(param_1 + 0x160) == 0) goto LAB_fffffff009c329e8;
  if (*(uint *)(param_1 + 0x170) < 2) {
    bVar1 = true;
  }
  else {
    plVar3 = (long *)thunk_EXT_FUN_801100000392f2f0("vram",0);
    plVar4 = (long *)thunk_EXT_FUN_801100000392ece0(plVar3,0xffffffffffffffff);
    if (plVar4 == (long *)0x0) {
      if (*(int *)(param_1 + 0x170) == 0) {
        bVar1 = true;
      }
      else {
LAB_fffffff009c32894:
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "IOSurface: /vram declares %u carveout(s) but none resolved\n");
        bVar1 = false;
        if (plVar4 != (long *)0x0) goto LAB_fffffff009c328c8;
      }
    }
    else {
      iVar2 = (**(code **)(*plVar4 + 0x3c0))(plVar4);
      if (iVar2 == *(int *)(param_1 + 0x170)) {
        bVar1 = true;
      }
      else {
        if (iVar2 == 0) goto LAB_fffffff009c32894;
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,
                   "IOSurface: /vram declares %u carveout(s) but %u resolved; positions are ambiguous, installing none\n"
                  );
        bVar1 = false;
      }
LAB_fffffff009c328c8:
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
    if (plVar3 != (long *)0x0) {
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
  }
  plVar3 = *(long **)(param_1 + 0x160);
  if (plVar3 != (long *)0x0) {
    do {
      if (plVar3[1] == 0) {
LAB_fffffff009c3299c:
        FUN_fffffff009c34034(param_1);
      }
      else {
        iVar2 = thunk_EXT_FUN_8011000003a7051c(plVar3[1],"sma");
        if (iVar2 == 0) {
          FUN_fffffff009c345d0(param_1,plVar3);
        }
        else {
          if (((plVar3[1] == 0) ||
              (iVar2 = thunk_EXT_FUN_8011000003a7051c(plVar3[1],"vram"), iVar2 != 0)) || (!bVar1))
          goto LAB_fffffff009c3299c;
          puStack_78 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_80 = &DAT_aaaaaaaaaaaaaaaa;
          uStack_70 = 0xaaaaaaaa;
          uStack_6c = 0xaaaa;
          uStack_6a = 0xaa;
          pcVar6 = "%s";
          if (*(int *)((long)plVar3 + 0x14) != 0) {
            pcVar6 = "%s%u";
          }
          thunk_EXT_FUN_80110000037693ec(&puStack_80,0x17,pcVar6);
          FUN_fffffff009c34324(param_1,plVar3,&puStack_80);
        }
      }
      plVar3 = (long *)*plVar3;
    } while (plVar3 != (long *)0x0);
  }
LAB_fffffff009c329e8:
  if (*(long *)PTR_DAT_fffffff00806ca40 != lStack_68) {
    uVar5 = thunk_EXT_FUN_8011000003a48590();
    return uVar5;
  }
  return 0;
}

