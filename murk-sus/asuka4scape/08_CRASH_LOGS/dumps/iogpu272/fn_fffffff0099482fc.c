// FUN_fffffff0099482fc @ fffffff0099482fc size=4

undefined8 FUN_fffffff0099482fc(long param_1,undefined8 param_2,long param_3)

{
  long *plVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  plVar1 = (long *)FUN_fffffff009965cc4
                             (*(undefined8 *)(param_1 + 0x120),**(undefined4 **)(param_3 + 0x20));
  if (plVar1 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Could not find event_id %u\n");
    uVar2 = 0xe00002c2;
  }
  else {
    uVar2 = (**(code **)(*plVar1 + 0x80))();
    puVar3 = *(undefined8 **)(param_3 + 0x48);
    *puVar3 = uVar2;
    puVar3[1] = plVar1[4];
    (**(code **)(*plVar1 + 0x28))(plVar1);
    uVar2 = 0;
  }
  return uVar2;
}

