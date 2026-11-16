// FUN_fffffff009c16b10 @ fffffff009c16b10 size=332

void FUN_fffffff009c16b10(long param_1,long *param_2,ulong param_3)

{
  undefined8 uVar1;
  long lVar2;
  undefined1 *local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))();
  FUN_fffffff009c46f98(param_1 + 0xc,1);
  *(long **)(param_1 + 0x10) = param_2;
  (**(code **)(*param_2 + 0x20))(param_2);
  if (param_3 < 4) {
    *(ulong *)(param_1 + 0x50) = param_3;
    *(undefined8 *)(param_1 + 0x58) = 0;
    uVar1 = FUN_fffffff009c3624c(param_2,param_1 + 0x1c);
    if ((int)uVar1 != 0) {
      local_40 = &DAT_aaaaaaaaaaaaaaaa;
      uVar1 = FUN_fffffff009c32528(param_2,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x38,&local_40)
      ;
      if ((int)uVar1 != 0) {
        *(undefined8 *)(param_1 + 0x40) = 0;
        *(undefined1 **)(param_1 + 0x20) = local_40;
        *(undefined8 **)(param_1 + 0x48) = (undefined8 *)(param_1 + 0x40);
        uVar1 = FUN_fffffff009c372c4();
        *(undefined8 *)(param_1 + 0x28) = uVar1;
        lVar2 = thunk_EXT_FUN_80110000038ff010();
        *(long *)(param_1 + 0x30) = lVar2;
        uVar1 = 0;
        if (lVar2 != 0) {
          lVar2 = thunk_EXT_FUN_80110000038ff010();
          *(long *)(param_1 + 0x60) = lVar2;
          uVar1 = 0;
          if (lVar2 != 0) {
            FUN_fffffff009c363b0(param_2,param_1,*(undefined4 *)(param_1 + 0x1c));
            uVar1 = 1;
          }
        }
      }
    }
  }
  else {
    uVar1 = 0;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar1);
  return;
}

