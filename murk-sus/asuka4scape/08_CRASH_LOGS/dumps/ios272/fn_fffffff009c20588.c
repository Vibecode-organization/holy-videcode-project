// FUN_fffffff009c20588 @ fffffff009c20588 size=372

void FUN_fffffff009c20588(long param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long *plVar4;
  undefined8 uVar5;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  if ((*(byte *)(param_1 + 0x3d0) >> 5 & 1) != 0) {
    iVar3 = *(int *)(param_1 + 0x9c);
    if (iVar3 == 0) {
      iVar3 = 0;
      if (*(long **)(param_1 + 0x28) != (long *)0x0) {
        iVar3 = (**(code **)(**(long **)(param_1 + 0x28) + 0xb8))();
        *(int *)(param_1 + 0x9c) = iVar3;
      }
    }
    uVar1 = iVar3 - 0x100U >> 8;
    if ((uVar1 | iVar3 << 0x18) < 7 && (1 << (ulong)(uVar1 & 0x1f) & 0x4bU) != 0) {
      thunk_EXT_FUN_8011000003390134();
    }
    else {
      plVar4 = *(long **)(param_1 + 0x30);
      if ((plVar4 == (long *)0x0) || (iVar3 = (**(code **)(*plVar4 + 0xd8))(plVar4,0), iVar3 != 0))
      {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "IOSurface::flushProcessorCaches memory prepare failed\n");
      }
      else {
        plVar4 = *(long **)(param_1 + 0x30);
        uVar5 = (**(code **)(*plVar4 + 0xb0))(plVar4);
        (**(code **)(*plVar4 + 0x88))(plVar4,1,0,uVar5);
        (**(code **)(**(long **)(param_1 + 0x30) + 0xe0))(*(long **)(param_1 + 0x30),0);
      }
    }
    *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xffffffdf;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c20630);
    (*pcVar2)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  return;
}

