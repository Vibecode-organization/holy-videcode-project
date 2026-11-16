// FUN_fffffff009c72600 @ fffffff009c72600

void FUN_fffffff009c72600
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long *param_7)

{
  long lVar1;
  long lVar2;
  undefined1 auVar3 [16];
  
  thunk_FUN_fffffff00a2262a8(param_7[5]);
  lVar2 = param_7[0x17];
  thunk_FUN_fffffff00a226de0(param_7[5]);
  lVar1 = (**(code **)(*param_7 + 0x38))(param_7);
  auVar3 = thunk_FUN_fffffff00a895b28(lVar1);
  thunk_FUN_fffffff00a8df19c
            (auVar3,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
             (short *)PTR_DAT_fffffff00807b638,0,
             (byte *)"  %s(%s_%s): Number of outstanding packets: %zu %zu\n");
  param_7[0x18] = lVar2;
  return;
}

