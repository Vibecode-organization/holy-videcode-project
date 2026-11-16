// FUN_fffffff00821f880 @ fffffff00821f880 size=528
// CALLERS:
//   fffffff00afc19df no-fn
//   fffffff00821f1f0 FUN_fffffff00821ef3c@fffffff00821ef3c
//   fffffff00821f510 FUN_fffffff00821f324@fffffff00821f324
//   fffffff00821f718 FUN_fffffff00821f680@fffffff00821f680
// CALLEES:
//   fffffff00826f868 thunk_FUN_fffffff00a894f30
//   fffffff00826f978 thunk_FUN_fffffff00aa65b10

undefined4
FUN_fffffff00821f880
          (undefined8 param_1,long *param_2,ulong *param_3,long param_4,uint *param_5,uint param_6)

{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  long *plVar4;
  ulong uVar5;
  undefined8 *puVar6;
  long lVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 local_84;
  
  uVar10 = 0;
  uVar8 = 0xe00002c9;
  if (((param_3 != (ulong *)0x0) && (param_4 != 0)) && (param_5 != (uint *)0x0)) {
    uVar10 = *param_5;
    if (param_6 < uVar10) {
      uVar8 = 0xe00002e8;
      goto LAB_fffffff00821fa68;
    }
    if (param_2 == (long *)0x0) {
      uVar8 = 0;
      *param_3 = 0;
      param_3[1] = 0;
      goto LAB_fffffff00821fa68;
    }
    uVar3 = (**(code **)(*param_2 + 0x90))(param_2);
    *param_3 = (ulong)uVar3;
    param_3[1] = 0;
    if (uVar3 == 0) {
      uVar8 = 0;
      goto LAB_fffffff00821fa68;
    }
    uVar9 = 0;
    lVar7 = *(long *)PTR_PTR_fffffff007cb2f30;
    local_84 = 0xe00002bc;
    do {
      plVar4 = (long *)(**(code **)(*param_2 + 0x118))(param_2,uVar9);
      plVar4 = thunk_FUN_fffffff00a894f30(plVar4,lVar7);
      uVar8 = local_84;
      if (plVar4 == (long *)0x0) goto LAB_fffffff00821fa64;
      uVar5 = (**(code **)(*plVar4 + 0xa0))();
      uVar2 = (uVar5 & 0xffffffff) + 4;
      if ((ulong)param_6 < uVar2 + uVar10) {
        uVar8 = 0xffff86d5;
        goto LAB_fffffff00821fa64;
      }
      *(char *)(param_4 + (ulong)uVar10) = (char)uVar5;
      *(char *)(param_4 + (ulong)(uVar10 + 1)) = (char)(uVar5 >> 8);
      uVar1 = uVar10 + 3;
      *(char *)(param_4 + (ulong)(uVar10 + 2)) = (char)(uVar5 >> 0x10);
      uVar10 = uVar10 + 4;
      *(char *)(param_4 + (ulong)uVar1) = (char)(uVar5 >> 0x18);
      if ((int)uVar5 != 0) {
        puVar6 = (undefined8 *)(**(code **)(*plVar4 + 0xd8))(plVar4);
        thunk_FUN_fffffff00aa65b10
                  ((undefined8 *)(param_4 + (ulong)uVar10),puVar6,uVar5 & 0xffffffff);
        uVar10 = (int)uVar5 + uVar10;
      }
      uVar8 = 0xe00002c9;
      if (CARRY8(param_3[1],uVar2)) goto LAB_fffffff00821fa64;
      param_3[1] = param_3[1] + uVar2;
      uVar9 = uVar9 + 1;
    } while (uVar3 != uVar9);
    uVar8 = 0;
  }
LAB_fffffff00821fa64:
  if (param_5 == (uint *)0x0) {
    return uVar8;
  }
LAB_fffffff00821fa68:
  *param_5 = uVar10;
  return uVar8;
}

