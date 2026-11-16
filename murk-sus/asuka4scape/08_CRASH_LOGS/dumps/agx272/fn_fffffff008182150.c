// FUN_fffffff008182150 @ fffffff008182150 size=60

void FUN_fffffff008182150
               (long *param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  *(undefined1 *)(param_1 + 0x12) = param_2;
                    /* WARNING: Could not recover jumptable at 0xfffffff008182188. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x78))
            (param_1,param_3,param_4,param_5,param_5,(undefined8 *)(*param_1 + 0x78));
  return;
}

