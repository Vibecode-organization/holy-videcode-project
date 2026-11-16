// FUN_fffffff009980714 @ fffffff009980714 size=376

long FUN_fffffff009980714
               (long *param_1,undefined8 param_2,undefined8 param_3,long param_4,ulong param_5)

{
  long *plVar1;
  long lVar2;
  ulong uVar3;
  long local_48;
  
  if (((-*(long *)PTR_DAT_fffffff007ff2838 &
       (param_1[0x23] * (ulong)*(uint *)((long)param_1 + 0x2ec)) / 100) < param_5) ||
     (plVar1 = (long *)FUN_fffffff0099805d0(param_2,param_4,param_5), plVar1 == (long *)0x0)) {
    lVar2 = 0;
  }
  else {
    lVar2 = (**(code **)(*param_1 + 0x590))(param_1);
    if (lVar2 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: allocIOGPUResource failed to alloc texture object\n");
      (**(code **)(*plVar1 + 0x28))(plVar1);
    }
    else {
      local_48 = 0;
      thunk_EXT_FUN_8011000003977d8c(plVar1,&local_48);
      uVar3 = (ulong)(uint)~(-1 << (ulong)(*(uint *)PTR_DAT_fffffff007ff2740 & 0x1f));
      uVar3 = local_48 + param_5 + uVar3 & (uVar3 ^ 0xffffffffffffffff);
      *(long *)(lVar2 + 0x88) = param_4 - local_48;
      *(long **)(lVar2 + 0x90) = plVar1;
      *(ulong *)(lVar2 + 0x38) = uVar3;
      *(undefined4 *)(lVar2 + 0x84) = 0;
      param_1[0x22] = param_1[0x22] + uVar3;
    }
  }
  return lVar2;
}

