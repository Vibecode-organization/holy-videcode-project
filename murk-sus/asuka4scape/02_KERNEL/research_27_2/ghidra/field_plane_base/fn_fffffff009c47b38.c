// FUN_fffffff009c47b38 @ fffffff009c47b38

/* WARNING: Removing unreachable block (ram,0xfffffff009c47bd0) */

byte FUN_fffffff009c47b38
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 param_8,long *param_9,uint param_10)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long *plVar4;
  
  uVar2 = FUN_fffffff009c4755c
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                     param_10 | 2);
  if ((int)uVar2 != 0) {
    lVar3 = FUN_fffffff009c22264(*(long *)(param_7 + 0x18));
    if (lVar3 == 0) {
      *(undefined1 *)(param_7 + 0x21) = 1;
    }
    else {
      plVar4 = (long *)FUN_fffffff009c22264(*(long *)(param_7 + 0x18));
      iVar1 = (**(code **)(*plVar4 + 0xd8))(plVar4,0);
      *(bool *)(param_7 + 0x21) = iVar1 == 0;
      if (iVar1 != 0) goto LAB_fffffff009c47bdc;
    }
    thunk_FUN_fffffff00a8945fc((int *)(*(long *)(*(long *)(param_7 + 0x18) + 0x178) + 0x24));
  }
LAB_fffffff009c47bdc:
  return *(byte *)(param_7 + 0x21) & 1;
}

