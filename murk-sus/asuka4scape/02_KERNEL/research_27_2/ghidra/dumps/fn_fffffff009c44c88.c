// FUN_fffffff009c44c88 @ fffffff009c44c88 size=168
// CALLERS:
//   fffffff00afec1dc no-fn
//   fffffff009c35270 FUN_fffffff009c34d4c@fffffff009c34d4c
// CALLEES:
//   fffffff009c44d30 FUN_fffffff009c44d30

undefined8
FUN_fffffff009c44c88
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,long *param_8)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  undefined1 auVar3 [16];
  
  if (param_8 != (long *)0x0) {
    auVar3 = (**(code **)(*param_8 + 0x20))(param_8);
    uVar2 = FUN_fffffff009c44d30(auVar3,param_2,param_3,param_4,param_5,param_6,param_7,param_8,0);
    (**(code **)(*param_8 + 0x28))(param_8);
    return uVar2;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c44d2c);
    (*pcVar1)();
  }
  uVar2 = FUN_fffffff009c44d30
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,(long *)0x0,0);
  return uVar2;
}

