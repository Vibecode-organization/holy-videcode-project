// FUN_fffffff0081fb394 @ fffffff0081fb394 size=432

ulong FUN_fffffff0081fb394(long *param_1,undefined8 param_2)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  
  plVar2 = (long *)thunk_EXT_FUN_8011000003890f30(param_1[3],&DAT_fffffff00ae21bd0);
  if (plVar2 == (long *)0x0) {
    lVar3 = thunk_EXT_FUN_8011000003890f30(param_1[3],*(undefined8 *)PTR_DAT_fffffff007ca6050);
    if (lVar3 == 0) {
      return 0;
    }
    lVar3 = *(long *)(lVar3 + 0x80);
  }
  else {
    (**(code **)(*param_1 + 0x120))(param_1);
    lVar3 = (**(code **)(*plVar2 + 0x88))(plVar2);
  }
  if (((*(byte *)(*(long *)(param_1[3] + 0x10) + 0x10958) & 1) == 0) &&
     (iVar1 = (**(code **)(*param_1 + 0x100))(param_1), iVar1 != 0)) {
    (**(code **)(*param_1 + 0x110))(param_1);
  }
  uVar4 = (**(code **)(*(long *)param_1[4] + 0x1a0))((long *)param_1[4],param_1,param_2);
  if ((uVar4 & 1) == 0) {
    (**(code **)(*param_1 + 0x98))(param_1);
    (**(code **)(*param_1 + 200))(param_1);
  }
  *(long *)(param_1[4] + 0x1c8) = *(long *)(param_1[4] + 0x1c8) - lVar3;
  return uVar4;
}

