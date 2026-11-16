// FUN_fffffff0081e14c4 @ fffffff0081e14c4 size=232

long * FUN_fffffff0081e14c4(long *param_1)

{
  int iVar1;
  long *plVar2;
  undefined8 *puVar3;
  long lVar4;
  long lVar5;
  
  plVar2 = (long *)thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca1cc8,0x298);
  puVar3 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(plVar2,&DAT_fffffff00ae23008);
  *puVar3 = &DAT_fffffff007c9c538;
  *(undefined2 *)(puVar3 + 9) = 0;
  *(undefined1 *)((long)puVar3 + 0x4a) = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae23008);
  lVar5 = *param_1;
  iVar1 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))(plVar2);
  if (iVar1 != 0) {
    lVar4 = thunk_EXT_FUN_80110000038ff010();
    plVar2[3] = lVar4;
    if (lVar4 != 0) {
      plVar2[2] = lVar5;
      plVar2[6] = 0;
      FUN_fffffff0081e1178(plVar2);
      return plVar2;
    }
  }
  (**(code **)(*plVar2 + 8))(plVar2);
  return (long *)0x0;
}

