// FUN_fffffff009c1f830 @ fffffff009c1f830 size=4

void FUN_fffffff009c1f830(long param_1)

{
  ulong uVar1;
  undefined1 auVar2 [16];
  code *pcVar3;
  long lVar4;
  long lVar5;
  ulong unaff_x30;
  
  if (*(int *)(param_1 + 0x3b0) == 0) {
    if (*(long *)(param_1 + 0x240) == 0) {
      if (*(long *)(param_1 + 0x250) != 0) {
        thunk_EXT_FUN_8011000003a49114("\"IOFence wait queue is not empty for surface: %p\" @%s:%d")
        ;
        return;
      }
      FUN_fffffff009c1fa8c(param_1);
      if (*(long **)(param_1 + 0x378) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x378) + 0x28))();
      }
      *(undefined8 *)(param_1 + 0x378) = 0;
      if (*(long *)(param_1 + 0x40) == 0) {
        if (*(long *)(param_1 + 0x360) != 0) {
          *(undefined8 *)(param_1 + 0x360) = 0;
          thunk_EXT_FUN_80110000038fe270(&DAT_fffffff00806af30);
          *(undefined8 *)(param_1 + 0x360) = 0;
        }
        FUN_fffffff009c1fb48(param_1);
        lVar4 = *(long *)(param_1 + 0x370);
        if (lVar4 != 0) {
          *(undefined8 *)(param_1 + 0x370) = 0;
          thunk_EXT_FUN_80110000038fe6b0(lVar4,(ulong)*(uint *)(param_1 + 0x3b4) << 4);
          *(undefined8 *)(param_1 + 0x370) = 0;
        }
        lVar4 = *(long *)(param_1 + 0x180);
        if (((lVar4 != 0) && (*(uint *)(param_1 + 0x98) != 0)) && (lVar4 != param_1 + 0xa8)) {
          thunk_EXT_FUN_80110000038fe768
                    (&DAT_fffffff00806bca0,lVar4,(ulong)*(uint *)(param_1 + 0x98) * 0x38);
          *(undefined8 *)(param_1 + 0x180) = 0;
          *(undefined4 *)(param_1 + 0x188) = 0;
        }
        if (*(long *)(param_1 + 0x318) != 0) {
          auVar2._8_8_ = 0;
          auVar2._0_8_ = *(ulong *)(param_1 + 0x328);
          lVar5 = *(ulong *)(param_1 + 0x328) * 0x18;
          lVar4 = -0x8000000000000000;
          if (SUB168(auVar2 * ZEXT816(0x18),8) == 0 && -1 < lVar5) {
            lVar4 = lVar5;
          }
          thunk_EXT_FUN_80110000038fe6b0(*(long *)(param_1 + 0x318),lVar4);
          *(undefined8 *)(param_1 + 0x318) = 0;
          *(undefined4 *)(param_1 + 800) = 0;
        }
        if (*(long *)(param_1 + 0x350) != 0) {
          uVar1 = 0x8000000000000000;
          if (-1 < (long)*(ulong *)(param_1 + 0x348)) {
            uVar1 = *(ulong *)(param_1 + 0x348) & 0xffffffffffffffe0;
          }
          thunk_EXT_FUN_80110000038fe6b0(*(long *)(param_1 + 0x350),uVar1);
          *(undefined8 *)(param_1 + 0x350) = 0;
          *(undefined4 *)(param_1 + 0x358) = 0;
        }
        if ((*(long *)(param_1 + 0x308) != 0) && (*(uint *)(param_1 + 0x98) != 0)) {
          thunk_EXT_FUN_80110000038fe6b0
                    (*(long *)(param_1 + 0x308),(ulong)*(uint *)(param_1 + 0x98) * 0x3c);
          *(undefined8 *)(param_1 + 0x308) = 0;
          *(undefined4 *)(param_1 + 0x310) = 0;
          *(undefined4 *)(param_1 + 0x3b8) = 0;
        }
        if (*(int *)(param_1 + 0xa0) != 0) {
          *(undefined4 *)(param_1 + 0xa0) = 0;
        }
        *(undefined8 *)(param_1 + 0x170) = 0;
        if (*(long *)(param_1 + 0x398) != 0) {
          thunk_EXT_FUN_80110000038ff020();
          *(undefined8 *)(param_1 + 0x398) = 0;
        }
        if (*(long *)(param_1 + 0x50) != 0) {
          thunk_EXT_FUN_80110000038ff020();
          *(undefined8 *)(param_1 + 0x50) = 0;
        }
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c1fa00);
          (*pcVar3)();
        }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c1fa08. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
        return;
      }
      thunk_EXT_FUN_8011000003a49114("\"fDeviceCacheList is not empty for surface: %p\" @%s:%d");
      return;
    }
  }
  else {
    thunk_EXT_FUN_8011000003a49114
              ("\"IOSurface released with non-zero client retain count: %p\" @%s:%d");
  }
  thunk_EXT_FUN_8011000003a49114("\"IOFence current queue is not empty for surface: %p\" @%s:%d");
  return;
}

