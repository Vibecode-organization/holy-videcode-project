// FUN_fffffff008182614 @ fffffff008182614 size=328

void FUN_fffffff008182614(long param_1,long *param_2,undefined8 *param_3)

{
  long *plVar1;
  undefined8 *puVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  
  if ((param_2 != (long *)0x0) && (param_3 != (undefined8 *)0x0)) {
    uVar5 = *(ulong *)(param_1 + 0x130);
    if (uVar5 == 0) {
      lVar3 = *(long *)(param_1 + 0x140);
      if (lVar3 == 0) {
        *param_2 = 0;
        uVar4 = 0;
      }
      else {
        if (*(long *)(param_1 + 0x148) == 0) {
          uVar4 = thunk_EXT_FUN_8011000003397c88();
          *(undefined8 *)(param_1 + 0x148) = uVar4;
          lVar3 = *(long *)(param_1 + 0x140);
        }
        *param_2 = lVar3;
        uVar4 = *(undefined8 *)(param_1 + 0x148);
      }
    }
    else {
      lVar3 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
      uVar8 = *(long *)(lVar3 + 0x920) + 0x4c28;
      uVar6 = uVar5 - uVar8 & 0x7fffffff8;
      if ((uVar5 < uVar8 || *(long *)(lVar3 + 0x920) + 0x6c28U <= uVar5) || uVar6 == 0x7fffffff8) {
        lVar7 = 0;
      }
      else {
        lVar7 = *(long *)(lVar3 + 0x910) + 0x4c28;
        plVar1 = (long *)(lVar7 + (int)uVar6);
        if (uVar6 != (long)(int)uVar6) {
          plVar1 = (long *)(lVar7 + uVar6 & 0xffffffffffff | 0x2bad000000000000);
        }
        lVar7 = *plVar1;
      }
      *param_2 = lVar7;
      uVar6 = *(ulong *)(param_1 + 0x138);
      uVar5 = *(long *)(lVar3 + 0x920) + 0x4c28;
      uVar8 = uVar6 - uVar5 & 0x7fffffff8;
      if ((uVar6 < uVar5 || *(long *)(lVar3 + 0x920) + 0x6c28U <= uVar6) || uVar8 == 0x7fffffff8) {
        uVar4 = 0;
      }
      else {
        lVar3 = *(long *)(lVar3 + 0x910) + 0x4c28;
        puVar2 = (undefined8 *)(lVar3 + (int)uVar8);
        if (uVar8 != (long)(int)uVar8) {
          puVar2 = (undefined8 *)(lVar3 + uVar8 & 0xffffffffffff | 0x2bad000000000000);
        }
        uVar4 = *puVar2;
      }
    }
    *param_3 = uVar4;
  }
  return;
}

