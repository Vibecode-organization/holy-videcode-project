// FUN_fffffff00997700c @ fffffff00997700c size=712

/* WARNING: Removing unreachable block (ram,0xfffffff0099770f0) */

void FUN_fffffff00997700c(long *param_1,long param_2)

{
  undefined8 uVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  uVar1 = thunk_EXT_FUN_8011000003397c88();
  if ((int)param_1[0xa4] == 0) {
    plVar2 = (long *)(**(code **)(*(long *)param_1[0xa6] + 0x5c0))();
    param_1[0xa3] = (long)plVar2;
    if (plVar2 != (long *)0x0) {
      uVar3 = (**(code **)(*plVar2 + 0x90))
                        (plVar2,param_1[0xa6],param_1,param_1[0x85],*(undefined8 *)(param_2 + 0x18),
                         0);
      plVar2 = (long *)param_1[0xa3];
      if ((uVar3 & 1) != 0) {
        *(undefined4 *)(plVar2 + 0x19) = 0;
        if ((int)param_1[0xa4] == 0) {
          FUN_fffffff00994c49c(*(undefined8 *)(param_1[0xa6] + 0x148),param_1 + 0x93,plVar2 + 6);
          (**(code **)(*param_1 + 0x118))(*param_1 + 0x118,param_1,param_2);
          if ((*(byte *)(param_1[0xa6] + 0x1ff) >> 2 & 1) == 0) {
            FUN_fffffff00995f52c(*(undefined8 *)(param_1[0xa6] + 0x160),0,0);
          }
          uVar4 = thunk_EXT_FUN_8011000003397c88();
          FUN_fffffff009950abc(*(undefined8 *)(param_1[0xa6] + 0x158));
          if (*(long *)(param_2 + 0x10) != 0) {
            FUN_fffffff00994f180
                      (*(undefined8 *)param_1[0x86],*(long *)(param_2 + 0x10),uVar1,uVar4,
                       (int)param_1[0xa4],0);
          }
          FUN_fffffff009950ac8(*(undefined8 *)(param_1[0xa6] + 0x158));
          if ((int)param_1[0xa4] != 0) {
            *(int *)(param_1[0xa3] + 200) = (int)param_1[0xa4];
          }
          FUN_fffffff00994c6ac(*(undefined8 *)(param_1[0xa6] + 0x148),param_1 + 0x9b,param_1 + 0x93)
          ;
          FUN_fffffff00994c6ac
                    (*(undefined8 *)(param_1[0xa6] + 0x148),param_1 + 0x93,param_1[0xa3] + 0x70);
          FUN_fffffff009950614(*(undefined8 *)(param_1[0xa6] + 0x158),param_1,param_1[0xa3]);
          (**(code **)(*param_1 + 0xb8))(param_1,0);
          if ((long *)param_1[0xaf] != (long *)0x0) {
            (**(code **)(*(long *)param_1[0xaf] + 0x28))();
          }
          param_1[0xaf] = 0;
          goto LAB_fffffff009977298;
        }
        goto LAB_fffffff00997723c;
      }
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar2 + 0x28))();
      }
      param_1[0xa3] = 0;
    }
    *(undefined4 *)(param_1 + 0xa4) = 8;
  }
LAB_fffffff00997723c:
  FUN_fffffff009950abc(*(undefined8 *)(param_1[0xa6] + 0x158));
  if (*(long *)(param_2 + 0x10) != 0) {
    FUN_fffffff00994f180
              (*(undefined8 *)param_1[0x86],*(long *)(param_2 + 0x10),uVar1,uVar1,(int)param_1[0xa4]
               ,0);
  }
  FUN_fffffff00994f180
            (*(undefined8 *)param_1[0x86],*(undefined8 *)(param_2 + 0x18),uVar1,uVar1,
             (int)param_1[0xa4],0);
  FUN_fffffff009950ac8(*(undefined8 *)(param_1[0xa6] + 0x158));
LAB_fffffff009977298:
  if ((long *)param_1[0xa3] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0xa3] + 0x28))();
  }
  param_1[0xa3] = 0;
  return;
}

