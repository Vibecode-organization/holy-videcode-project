// FUN_fffffff0084d7be4 @ fffffff0084d7be4 size=60
// CALLERS:
//   fffffff00afc4e63 no-fn
//   fffffff008528c98 FUN_fffffff0085287f4@fffffff0085287f4
//   fffffff008528e24 FUN_fffffff0085287f4@fffffff0085287f4
//   fffffff0085290b4 FUN_fffffff0085287f4@fffffff0085287f4
// CALLEES:

int FUN_fffffff0084d7be4(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (1 < param_1) {
    iVar1 = 0x20 - (int)LZCOUNT(param_1 + -1);
  }
  iVar2 = 0;
  if (1 < param_2) {
    iVar2 = 0x20 - (int)LZCOUNT(param_2 + -1);
  }
  return param_3 << (ulong)(iVar2 + iVar1 & 0x1f);
}

