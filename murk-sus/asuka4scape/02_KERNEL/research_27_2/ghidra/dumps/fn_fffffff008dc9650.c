// FUN_fffffff008dc9650 @ fffffff008dc9650 size=156
// CALLERS:
//   fffffff00afba561 no-fn
//   fffffff008d14250 FUN_fffffff008d141d0@fffffff008d141d0
//   fffffff008d14368 FUN_fffffff008d142e8@fffffff008d142e8
//   fffffff008d143fc FUN_fffffff008d142e8@fffffff008d142e8
// CALLEES:
//   fffffff008dc953c FUN_fffffff008dc953c
//   fffffff008dfeb38 FUN_fffffff008dfeb38
//   fffffff008dfeb00 FUN_fffffff008dfeb00
//   fffffff008cd5954 FUN_fffffff008cd5954

undefined8 FUN_fffffff008dc9650(undefined8 param_1,long param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  if (param_3 == 0) {
    iVar2 = FUN_fffffff008cd5954(1,3);
    if (iVar2 != 0) {
      FUN_fffffff008dfeb38();
    }
  }
  else {
    if (param_2 != 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008dc9698);
        (*pcVar1)();
      }
      uVar3 = FUN_fffffff008dc953c();
      return uVar3;
    }
    iVar2 = FUN_fffffff008cd5954(1,3);
    if (iVar2 != 0) {
      FUN_fffffff008dfeb00();
    }
  }
  return 0xe00002c2;
}

