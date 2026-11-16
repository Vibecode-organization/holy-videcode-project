// FUN_fffffff009aaefbc @ fffffff009aaefbc size=488
// CALLERS:
//   fffffff00afe8a24 no-fn
//   fffffff009ab4ed4 FUN_fffffff009ab4e7c@fffffff009ab4e7c
//   fffffff009ab0ea8 FUN_fffffff009ab0cdc@fffffff009ab0cdc
//   fffffff009ab49ec FUN_fffffff009ab499c@fffffff009ab499c
//   fffffff009ab4d88 FUN_fffffff009ab4a28@fffffff009ab4a28
//   fffffff009aaeb40 no-fn
// CALLEES:
//   fffffff009abcf6c FUN_fffffff009abcf6c

undefined8
FUN_fffffff009aaefbc
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,ulong param_8)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  int iVar4;
  long *plVar5;
  undefined1 auVar6 [16];
  
  if (*(long *)(param_7 + 0x1b38) != 0) {
    if ((param_8 & 1) == 0) {
      if (*(int *)(param_7 + 0x1c2c) == 0) {
        auVar6 = FUN_fffffff009abcf6c(param_1,param_2,param_3,param_4,param_5,param_6);
        lVar3 = auVar6._8_8_;
        plVar2 = auVar6._0_8_;
        plVar5 = (long *)plVar2[0x34b];
        while (plVar1 = plVar5, plVar1 != (long *)0x0) {
          plVar5 = (long *)plVar1[0x1a7];
          if (plVar1[0x182] == lVar3) {
            if ((*(byte *)((long)plVar1 + 0x62b) & 1) == 0) {
              (**(code **)(*plVar2 + 0xb48))(plVar2,plVar1,plVar2 + 0x34b,8);
              (**(code **)(*plVar1 + 0x28))(plVar1);
            }
            else {
              *(undefined1 *)((long)plVar1 + 0x62a) = 1;
            }
          }
        }
        plVar5 = (long *)plVar2[0x349];
        while (plVar1 = plVar5, plVar1 != (long *)0x0) {
          plVar5 = (long *)plVar1[0x1a7];
          if (plVar1[0x182] == lVar3) {
            (**(code **)(*plVar2 + 0xb48))(plVar2,plVar1,plVar2 + 0x349,8);
            (**(code **)(*plVar1 + 0x28))(plVar1);
          }
        }
        (**(code **)(*plVar2 + 0x998))(plVar2);
        if (*(int *)(lVar3 + 0xf8) != 0) {
          (**(code **)(*(long *)plVar2[0x369] + 0x108))((long *)plVar2[0x369],plVar2 + 0x349,0);
        }
        return 0;
      }
      iVar4 = -1;
    }
    else {
      iVar4 = 1;
    }
    *(int *)(param_7 + 0x1c2c) = *(int *)(param_7 + 0x1c2c) + iVar4;
  }
  return 0;
}

