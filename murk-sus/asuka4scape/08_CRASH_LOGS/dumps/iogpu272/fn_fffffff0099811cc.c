// FUN_fffffff0099811cc @ fffffff0099811cc size=4

long FUN_fffffff0099811cc(long *param_1,undefined8 param_2,long *param_3)

{
  ulong uVar1;
  long lVar2;
  
  if ((param_3 == (long *)0x0) ||
     (uVar1 = thunk_EXT_FUN_8011000003977d8c(param_3,0),
     (-*(long *)PTR_DAT_fffffff007ff2838 &
     (param_1[0x23] * (ulong)*(uint *)((long)param_1 + 0x2ec)) / 100) < uVar1)) {
    lVar2 = 0;
  }
  else {
    lVar2 = (**(code **)(*param_1 + 0x590))(param_1);
    if (lVar2 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: allocIOGPUResource failed to alloc texture object\n");
    }
    else {
      *(long **)(lVar2 + 0x90) = param_3;
      (**(code **)(*param_3 + 0x20))(param_3);
      *(ulong *)(lVar2 + 0x38) = uVar1;
      *(undefined4 *)(lVar2 + 0x84) = 0;
      param_1[0x22] = param_1[0x22] + uVar1;
    }
  }
  return lVar2;
}

