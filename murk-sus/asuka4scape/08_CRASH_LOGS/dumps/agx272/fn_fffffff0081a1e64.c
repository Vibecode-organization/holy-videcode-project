// FUN_fffffff0081a1e64 @ fffffff0081a1e64 size=300

ulong FUN_fffffff0081a1e64(long param_1)

{
  ulong uVar1;
  long lVar2;
  undefined8 *puVar3;
  long *plVar4;
  undefined8 uVar5;
  
  uVar1 = FUN_fffffff0081738c0();
  if ((int)uVar1 != 0) {
    lVar2 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca2208,0x38);
    puVar3 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(lVar2,&DAT_fffffff00ae23550);
    *puVar3 = &DAT_fffffff007c9db40;
    thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae23550);
    *(long *)(param_1 + 0x1acf0) = lVar2;
    uVar1 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))(lVar2);
    if ((int)uVar1 != 0) {
      *(undefined1 *)(lVar2 + 0x18) = 0;
      *(long *)(lVar2 + 0x10) = param_1;
      plVar4 = (long *)thunk_EXT_FUN_801100000392ef4c("ApplePPM",0);
      if (plVar4 != (long *)0x0) {
        uVar5 = thunk_EXT_FUN_801100000392eb04
                          (*(undefined8 *)PTR_DAT_fffffff007ca61c0,plVar4,FUN_fffffff0081eec4c,lVar2
                           ,0,0);
        *(undefined8 *)(lVar2 + 0x28) = uVar5;
        (**(code **)(*plVar4 + 0x28))(plVar4);
      }
      uVar1 = (ulong)(*(long *)(lVar2 + 0x28) != 0);
    }
  }
  return uVar1;
}

