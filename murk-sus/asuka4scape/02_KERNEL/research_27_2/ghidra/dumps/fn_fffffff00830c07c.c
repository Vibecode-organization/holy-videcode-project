// FUN_fffffff00830c07c @ fffffff00830c07c size=76
// CALLERS:
// CALLEES:
//   fffffff008357314 thunk_FUN_fffffff00a894d88

void FUN_fffffff00830c07c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6)

{
  undefined8 *puVar1;
  undefined *in_x4;
  
  puVar1 = thunk_FUN_fffffff00a894d88
                     (param_1,param_2,param_3,param_4,param_5,param_6,
                      (undefined8 *)&DAT_fffffff00ae2b3e0,"VictimUserClient",
                      PTR_DAT_fffffff007ce9be8,0x118,in_x4);
  *puVar1 = &PTR_thunk_FUN_fffffff00a895910_fffffff007cd4450;
  return;
}

