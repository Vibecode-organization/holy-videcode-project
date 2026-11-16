// FUN_fffffff0270af44c @ fffffff0270af44c size=136
// CALLERS:
//   fffffff02701f038 ?
// CALLS:
//   fffffff0270a6a58 FUN_fffffff0270a6a58

void FUN_fffffff0270af44c(char *param_1,undefined1 *param_2)

{
  char cVar1;
  long lVar2;
  undefined1 in_wzr;
  
  cVar1 = *param_1;
  FUN_fffffff0270a6a58(param_2,0x4000,0xffffffffffffffff);
  if (cVar1 != '\0') {
    return;
  }
  if (*(long *)(DAT_fffffff0270921b8 + 0x10) == 1) {
    *param_2 = 4;
    *(undefined8 *)(param_2 + 8) = 0xffffffff;
    lVar2 = 0x10;
  }
  else {
    if (*(long *)(DAT_fffffff0270921b8 + 0x10) != 0) goto LAB_fffffff0270af4bc;
    *param_2 = 1;
    lVar2 = 8;
  }
  *(undefined8 *)(param_2 + lVar2) = 0xffffffff;
LAB_fffffff0270af4bc:
  *(undefined2 *)(param_2 + 0x18) = 0xffff;
  param_2[0x1a] = in_wzr;
  return;
}

