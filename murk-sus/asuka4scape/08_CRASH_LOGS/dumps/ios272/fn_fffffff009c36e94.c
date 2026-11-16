// FUN_fffffff009c36e94 @ fffffff009c36e94 size=4

void FUN_fffffff009c36e94
               (undefined8 param_1,long param_2,undefined8 param_3,undefined4 *param_4,
               undefined4 *param_5)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 uStack_4c;
  long lStack_48;
  
  lStack_48 = *(long *)PTR_DAT_fffffff00806ca40;
  *param_4 = 0;
  *param_5 = 0xffffffff;
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    uStack_4c = 0xaaaaaaaa;
    iVar1 = FUN_fffffff009c178fc(param_2,param_3,&uStack_4c);
    if (iVar1 == 0) {
      uVar2 = FUN_fffffff009c36d0c(param_1,param_2,uStack_4c,param_3,param_4,param_5);
    }
    else {
      FUN_fffffff009c17530(param_2);
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "%s: failed to assign slot for event %08x, signal value 0x%016llx: ret 0x%x\n");
      uVar2 = 0;
    }
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_48) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar2);
  return;
}

