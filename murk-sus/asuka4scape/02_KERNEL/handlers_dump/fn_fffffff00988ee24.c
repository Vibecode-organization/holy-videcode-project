// FUN_fffffff00988ee24 @ fffffff00988ee24 size=4 depth=0
// CALLERS:
//   fffffff00afe4348 ?
//   fffffff007fb79b0 ?
// CALLS:

undefined8 FUN_fffffff00988ee24(undefined *param_1,undefined8 param_2,long param_3)

{
  undefined2 uVar1;
  ulong uVar2;
  undefined8 *puVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  long *plVar8;
  ulong uVar9;
  long *plStack_70;
  undefined8 uStack_68;
  long *plStack_60;
  ulong uStack_58;
  
  uVar6 = 0xe00002bd;
  uStack_68 = 0;
  plStack_70 = (long *)0x0;
  uStack_58 = 0;
  plStack_60 = (long *)0x0;
  plVar5 = *(long **)(param_3 + 0x40);
  if (plVar5 == (long *)0x0) {
    plVar5 = thunk_FUN_fffffff00a966e00
                       (*(undefined8 *)(param_3 + 0x30),(ulong)*(uint *)(param_3 + 0x38),2,0);
    if (plVar5 == (long *)0x0) {
      return 0xe00002bd;
    }
  }
  else {
    (**(code **)(*plVar5 + 0x20))(plVar5);
  }
  plVar8 = *(long **)(param_3 + 0x68);
  if (plVar8 == (long *)0x0) {
    plVar8 = thunk_FUN_fffffff00a966d2c((ulong)*(uint *)(param_3 + 0x60),1,0);
    if (plVar8 == (long *)0x0) goto LAB_fffffff00988f02c;
  }
  else {
    (**(code **)(*plVar8 + 0x20))(plVar8);
  }
  plStack_70 = plVar5;
  uVar1 = (**(code **)(*plVar5 + 0xb0))(plVar5);
  uStack_68 = CONCAT62(uStack_68._2_6_,uVar1);
  plStack_60 = plVar8;
  uVar1 = (**(code **)(*plVar8 + 0xb0))(plVar8);
  uStack_58 = CONCAT62(uStack_58._2_6_,uVar1);
  uStack_58 = (ulong)CONCAT24(**(undefined2 **)(param_3 + 0x20),(undefined4)uStack_58);
  uVar6 = FUN_fffffff00986f418(param_1,(long *)&plStack_70,(undefined8 *)0x0);
  if ((int)uVar6 == 0) {
    uVar9 = uStack_58 & 0xffff;
    uVar2 = (**(code **)(*plVar8 + 0xb0))(plVar8);
    if (uVar2 < uVar9) {
      uVar6 = 0xe00002e1;
    }
    else {
      if (*(long *)(param_3 + 0x68) == 0) {
        puVar7 = *(undefined8 **)(param_3 + 0x58);
        (**(code **)(*plVar8 + 0x20))(plVar8);
        puVar3 = (undefined8 *)(**(code **)(*plVar8 + 0x148))(plVar8);
        thunk_FUN_fffffff00aa65b10(puVar7,puVar3,uStack_58 & 0xffff);
        (**(code **)(*plVar8 + 0x28))(plVar8);
        lVar4 = 0x60;
      }
      else {
        lVar4 = 0x70;
      }
      uVar6 = 0;
      *(uint *)(param_3 + lVar4) = (uint)(ushort)uStack_58;
    }
  }
  (**(code **)(*plVar8 + 0x28))(plVar8);
LAB_fffffff00988f02c:
  (**(code **)(*plVar5 + 0x28))(plVar5);
  return uVar6;
}

