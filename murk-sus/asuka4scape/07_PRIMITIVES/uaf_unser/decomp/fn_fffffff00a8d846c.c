// FUN_fffffff00a8d846c @ fffffff00a8d846c size=500
// CALLERS:
//   fffffff00a9dd7d8 FUN_fffffff00a9dd4f0@fffffff00a9dd4f0
//   fffffff00a8c0a28 FUN_fffffff00a8c0908@fffffff00a8c0908
//   fffffff00a9e52b4 FUN_fffffff00a9e51d8@fffffff00a9e51d8
//   fffffff00a8b6798 FUN_fffffff00a8b6638@fffffff00a8b6638
//   fffffff00a8da420 FUN_fffffff00a8da3fc@fffffff00a8da3fc
//   fffffff00a8da4a0 FUN_fffffff00a8da470@fffffff00a8da470
//   fffffff00a8d8750 FUN_fffffff00a8d8678@fffffff00a8d8678
//   fffffff00a8d8810 FUN_fffffff00a8d8754@fffffff00a8d8754
//   fffffff00a8d8674 FUN_fffffff00a8d8660@fffffff00a8d8660

long FUN_fffffff00a8d846c
               (long param_1,long param_2,long param_3,undefined4 param_4,undefined8 *param_5)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  
  if ((param_1 == 0) ||
     (plVar2 = (long *)FUN_fffffff00a292e20(DAT_fffffff007c7c2d0,DAT_fffffff007c7c2d8,0x40),
     plVar2 == (long *)0x0)) {
    lVar5 = 0;
  }
  else {
    if (param_5 != (undefined8 *)0x0) {
      *param_5 = 0;
    }
    *plVar2 = param_1;
    plVar2[1] = DAT_fffffff00700db98;
    plVar2[2] = 0;
    plVar2[3] = 0;
    plVar3 = (long *)(**(code **)(DAT_fffffff00ad95c70 + 0x68))();
    if ((plVar3 != (long *)0x0) &&
       (uVar4 = (**(code **)(*plVar3 + 0xd0))(plVar3,0x80), (uVar4 & 1) == 0)) {
      (**(code **)(*plVar3 + 0x28))(plVar3);
      plVar3 = (long *)0x0;
    }
    plVar2[4] = (long)plVar3;
    plVar2[5] = (long)param_5;
    plVar2[7] = 0;
    plVar2[6] = 0;
    plVar2[9] = param_2;
    plVar2[10] = param_3;
    *(undefined4 *)(plVar2 + 8) = param_4;
    FUN_fffffff00a8d5ea4(plVar2);
    lVar5 = plVar2[6];
    lVar1 = plVar2[2];
    while (lVar1 != 0) {
      if (*(long **)(lVar1 + 0x18) != (long *)0x0) {
        (**(code **)(**(long **)(lVar1 + 0x18) + 0x28))();
      }
      if (*(long *)(lVar1 + 0x30) != 0) {
        FUN_fffffff00a2214fc(&DAT_fffffff007c6afb0);
      }
      if (*(long **)(lVar1 + 0x20) != (long *)0x0) {
        (**(code **)(**(long **)(lVar1 + 0x20) + 0x28))();
      }
      if (*(long *)(lVar1 + 0x38) != 0) {
        FUN_fffffff00a2214fc(&DAT_fffffff007c6afb0);
      }
      lVar6 = *(long *)(lVar1 + 8);
      FUN_fffffff00a29762c(&DAT_fffffff007c7c390,lVar1);
      lVar1 = lVar6;
    }
    (**(code **)(*(long *)plVar2[4] + 0x28))();
    FUN_fffffff00a29762c(&DAT_fffffff007c7c310,plVar2);
  }
  return lVar5;
}

