// FUN_fffffff009c33c34 @ fffffff009c33c34 size=400
// CALLERS:
//   fffffff009c33bd4 FUN_fffffff009c33bbc@fffffff009c33bbc
//   fffffff009c3ae24 FUN_fffffff009c3ab8c@fffffff009c3ab8c
//   fffffff009c3bd0c FUN_fffffff009c3bb20@fffffff009c3bb20
//   fffffff009c3c154 FUN_fffffff009c3bf44@fffffff009c3bf44

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * FUN_fffffff009c33c34(undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  int iVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  
  if (param_3 == 0) {
    FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a0831);
    plVar2 = (long *)0x0;
  }
  else {
    plVar2 = (long *)(**(code **)(*_DAT_fffffff008067118 + 0x68))();
    if (plVar2 == (long *)0x0) {
      FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a084b);
    }
    else {
      uVar3 = FUN_fffffff009c1a914(plVar2,param_1,param_2,param_3,param_4);
      if ((uVar3 & 1) == 0) {
        (**(code **)(*plVar2 + 0x28))(plVar2);
        plVar2 = (long *)0x0;
      }
      else {
        plVar4 = (long *)plVar2[6];
        if (((plVar4 != (long *)0x0) && ((*(byte *)((long)plVar2 + 0x3d1) >> 3 & 1) != 0)) &&
           (iVar1 = (**(code **)(*plVar4 + 0xd8))(plVar4,0), iVar1 == 0)) {
          (**(code **)(*(long *)plVar2[6] + 0xe0))((long *)plVar2[6],0);
        }
        FUN_fffffff009c1fc5c(plVar2);
      }
    }
    FUN_fffffff009c33ed4(param_1);
  }
  return plVar2;
}

