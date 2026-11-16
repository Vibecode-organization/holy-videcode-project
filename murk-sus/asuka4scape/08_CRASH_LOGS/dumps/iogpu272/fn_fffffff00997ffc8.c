// FUN_fffffff00997ffc8 @ fffffff00997ffc8 size=400

undefined8
FUN_fffffff00997ffc8
          (long param_1,ulong param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 uVar8;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x18));
  thunk_EXT_FUN_80110000036da494
            (0x85090118,param_5,param_6,*(undefined8 *)(param_1 + 0x288),param_2,0);
  do {
    FUN_fffffff00997fe30(param_1);
    uVar1 = *(uint *)(param_1 + 0x44);
    iVar3 = *(int *)(param_1 + 0x40) - uVar1;
    if (iVar3 == 0) {
      if (param_2 <= *(ulong *)(param_1 + 0x28)) {
LAB_fffffff00998012c:
        uVar8 = 1;
        goto LAB_fffffff009980130;
      }
    }
    else {
      uVar6 = 0xffffffffffffffff;
      uVar4 = uVar1;
      uVar5 = uVar1;
      do {
        uVar5 = uVar5 - 1;
        uVar7 = *(ulong *)(param_1 + 0x48 + (ulong)(uVar5 & 7) * 8);
        if (uVar6 <= uVar7) break;
        if (param_2 <= uVar7) {
          uVar4 = uVar5;
        }
        bVar2 = iVar3 != -1;
        iVar3 = iVar3 + 1;
        uVar6 = uVar7;
      } while (bVar2);
      if (uVar4 != uVar1) {
        FUN_fffffff00994c49c
                  (*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x148),
                   param_1 + 0x88 + (ulong)(uVar4 & 7) * 0x40,param_3);
        goto LAB_fffffff00998012c;
      }
    }
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    thunk_EXT_FUN_80110000036da494
              (0x850900cd,param_5,param_6,*(undefined8 *)(param_1 + 0x288),param_2,0);
    iVar3 = thunk_EXT_FUN_80110000038ff078(*(undefined8 *)(param_1 + 0x18),param_1,param_4,0);
    thunk_EXT_FUN_80110000036da494
              (0x850900ce,param_5,param_6,*(undefined8 *)(param_1 + 0x288),param_2,0);
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
  } while (iVar3 != 1);
  uVar8 = 0;
LAB_fffffff009980130:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x18));
  return uVar8;
}

