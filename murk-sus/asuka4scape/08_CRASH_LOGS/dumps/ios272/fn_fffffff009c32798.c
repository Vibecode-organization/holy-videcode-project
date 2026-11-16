// FUN_fffffff009c32798 @ fffffff009c32798 size=656

undefined8 FUN_fffffff009c32798(long param_1)

{
  bool bVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined1 *local_80;
  undefined1 *puStack_78;
  undefined4 local_70;
  undefined2 local_6c;
  undefined1 local_6a;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
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
          local_80 = &DAT_aaaaaaaaaaaaaaaa;
          local_70 = 0xaaaaaaaa;
          local_6c = 0xaaaa;
          local_6a = 0xaa;
          pcVar6 = "%s";
          if (*(int *)((long)plVar3 + 0x14) != 0) {
            pcVar6 = "%s%u";
          }
          thunk_EXT_FUN_80110000037693ec(&local_80,0x17,pcVar6);
          FUN_fffffff009c34324(param_1,plVar3,&local_80);
        }
      }
      plVar3 = (long *)*plVar3;
    } while (plVar3 != (long *)0x0);
  }
LAB_fffffff009c329e8:
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_68) {
    uVar5 = thunk_EXT_FUN_8011000003a48590();
    return uVar5;
  }
  return 0;
}

