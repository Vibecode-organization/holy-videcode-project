// FUN_fffffff00995d74c @ fffffff00995d74c size=808

undefined8 FUN_fffffff00995d74c(long *param_1)

{
  long *plVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 in_x6;
  undefined8 in_x7;
  long lVar8;
  uint uVar9;
  long lVar10;
  char *pcVar11;
  long local_50;
  int local_44;
  
  iVar5 = (**(code **)(*param_1 + 0x90))();
  if (iVar5 == 0) {
    uVar9 = *(uint *)((long)param_1 + 0x54);
    uVar3 = 0;
    if (uVar9 != 0) {
      uVar3 = *(uint *)(param_1 + 9) / uVar9;
    }
    lVar8 = (ulong)(*(uint *)(param_1 + 9) - uVar3 * uVar9) * 8;
    plVar1 = (long *)(param_1[0xb] + (long)(int)lVar8);
    if (lVar8 != (int)lVar8) {
      plVar1 = (long *)(param_1[0xb] + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar10 = *plVar1;
    uVar6 = *(undefined8 *)(lVar10 + 0x100);
    lVar8 = *(long *)(lVar10 + 0x60);
    lVar10 = *(long *)(lVar10 + 0x68);
  }
  else {
    pcVar11 = "virtual void IOGPUWorkQueue::restart()";
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: ring is empty and all finished. Nothing to do.\n\n");
    if (-1 < *(int *)(param_1[0x18] + 0x1f0)) {
      thunk_EXT_FUN_80110000036da494(0x85090098,0,0xffffffffffffffff,0,0,0,in_x6,in_x7,pcVar11);
      uVar6 = thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: GPURestartSkipped\n");
      return uVar6;
    }
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: work queue indicates empty/idle - Forcing restart\n");
    lVar10 = 0;
    uVar6 = 0;
    lVar8 = 0;
  }
  local_44 = 0;
  local_50 = 0;
  lVar7 = (**(code **)(*param_1 + 0xc0))(param_1,&local_44,&local_50);
  if (lVar7 != 0) {
    thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"GPU hang: %s\n\n");
  }
  if (*(long **)(param_1[0x18] + 0x140) != (long *)0x0) {
    (**(code **)(**(long **)(param_1[0x18] + 0x140) + 0xa8))();
  }
  thunk_EXT_FUN_80110000038fe9a0("Trying to restart GPU (%s)...\n");
  if ((local_44 == 0) && (local_44 = 2, 2 < *(int *)(param_1[2] + 0xe8) - 2U)) {
    local_44 = 3;
  }
  if ((*(byte *)(param_1[0x18] + 0x1fc) >> 1 & 1) == 0) {
    if (lVar10 == 0) {
      if (lVar8 != 0) {
        lVar10 = thunk_EXT_FUN_8011000003890f30(lVar8,DAT_fffffff007feee18);
        if (lVar10 == 0) {
          FUN_fffffff009962d08(param_1[2],lVar8,local_44);
        }
        else {
          FUN_fffffff009951160(*(undefined8 *)(param_1[0x18] + 0x158),lVar10,local_44);
        }
      }
    }
    else {
      *(int *)(lVar10 + 200) = local_44;
    }
    FUN_fffffff009973410(param_1[0x18],lVar8,lVar7,local_44,uVar6);
    if (lVar8 != 0) {
      for (uVar9 = *(uint *)(param_1 + 9); uVar9 != *(uint *)((long)param_1 + 0x4c);
          uVar9 = uVar9 + 1) {
        uVar3 = *(uint *)((long)param_1 + 0x54);
        uVar4 = 0;
        if (uVar3 != 0) {
          uVar4 = uVar9 / uVar3;
        }
        lVar10 = (ulong)(uVar9 - uVar4 * uVar3) * 8;
        plVar1 = (long *)(param_1[0xb] + (long)(int)lVar10);
        if (lVar10 != (int)lVar10) {
          plVar1 = (long *)(param_1[0xb] + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
        }
        if (((long *)*plVar1)[0xc] == lVar8) {
          (**(code **)(*(long *)*plVar1 + 0x88))();
        }
      }
    }
    uVar6 = (**(code **)(*param_1 + 0xb8))(param_1);
    param_1[8] = 0;
    if (local_50 != 0) {
      uVar6 = thunk_EXT_FUN_80110000038fe6b0(lVar7);
    }
    return uVar6;
  }
  lVar8 = FUN_fffffff009983b80();
  if (*(uint *)(lVar8 + 0x48) == *(uint *)(lVar8 + 0x4c)) {
    return 0;
  }
  uVar9 = *(uint *)(lVar8 + 0x48);
  uVar3 = *(uint *)(lVar8 + 0x54);
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = uVar9 / uVar3;
  }
  lVar10 = (ulong)(uVar9 - uVar4 * uVar3) * 8;
  puVar2 = (undefined8 *)(*(long *)(lVar8 + 0x58) + (long)(int)lVar10);
  if (lVar10 != (int)lVar10) {
    puVar2 = (undefined8 *)(*(long *)(lVar8 + 0x58) + lVar10 & 0xffffffffffffU | 0x2bad000000000000)
    ;
  }
  return *puVar2;
}

