// FUN_fffffff00996cf5c @ fffffff00996cf5c size=200

void FUN_fffffff00996cf5c(long param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  FUN_fffffff00996cc08
            (param_1,param_2,*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x110),
             "Alloc system memory");
  uVar2 = FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x10),0);
  FUN_fffffff00996cc08(uVar2,param_2,uVar2,"In use system memory");
  uVar2 = FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x10),1);
  FUN_fffffff00996cc08(uVar2,param_2,uVar2,"In use system memory (driver)");
  uVar2 = thunk_EXT_FUN_80110000039b575c(*(undefined8 *)(param_1 + 0x28),3);
  FUN_fffffff00996cc08(uVar2,param_2,uVar2,"recoveryCount");
  uVar2 = thunk_EXT_FUN_80110000039b575c(*(undefined8 *)(param_1 + 0x28),5);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996d020);
    (*pcVar1)();
  }
  FUN_fffffff00996cc08(uVar2,param_2,uVar2,"lastRecoveryTime");
  return;
}

