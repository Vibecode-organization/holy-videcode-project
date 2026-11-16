// FUN_fffffff0099485dc @ fffffff0099485dc size=4

undefined8 FUN_fffffff0099485dc(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  long *plVar2;
  ulong *puVar3;
  undefined8 uVar4;
  
  plVar2 = (long *)FUN_fffffff0099647b0(**(undefined4 **)(param_3 + 0x20));
  if (plVar2 == (long *)0x0) {
    uVar4 = 0xe00002c2;
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Failed to create IOGPUVnioDesc\n");
  }
  else {
    uVar1 = thunk_FUN_fffffff009944798(*(undefined8 *)(*(long *)(param_1 + 0x120) + 0x108),plVar2);
    if (uVar1 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: VnioDesc add namespace failed\n");
      (**(code **)(*plVar2 + 0x28))(plVar2);
      uVar4 = 0xe00002db;
    }
    else {
      puVar3 = *(ulong **)(param_3 + 0x48);
      *puVar3 = (ulong)uVar1;
      puVar3[1] = plVar2[4];
      (**(code **)(*plVar2 + 0x28))(plVar2);
      uVar4 = 0;
    }
  }
  return uVar4;
}

