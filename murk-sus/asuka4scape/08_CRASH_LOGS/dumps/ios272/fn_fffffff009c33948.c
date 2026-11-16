// FUN_fffffff009c33948 @ fffffff009c33948 size=260

long * FUN_fffffff009c33948(long param_1,long param_2)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  undefined8 uVar9;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 1000));
  lVar1 = param_1 + 0x400;
  if (*(long *)(param_1 + 0x400) == param_2) {
    lVar6 = 8;
  }
  else {
    if (*(long *)(param_1 + 0x410) != param_2) {
      lVar6 = *(long *)(param_1 + 0x3f0);
      if (lVar6 != 0) {
        lVar4 = 0;
        lVar5 = *(long *)(param_1 + 0x428);
        lVar7 = lVar5;
        do {
          if (*(long *)(lVar5 + lVar4 * 0x10) == param_2) {
            plVar8 = *(long **)(lVar7 + 8);
            lVar6 = *(long *)(param_1 + 0x3f8);
            lVar7 = lVar6 * 0x10;
            puVar2 = (undefined8 *)(lVar1 + (int)lVar7);
            if (lVar7 - (int)lVar7 != 0) {
              puVar2 = (undefined8 *)(lVar1 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
            }
            puVar3 = (undefined8 *)(lVar5 + lVar4 * 0x10);
            uVar9 = *puVar3;
            puVar2[1] = puVar3[1];
            *puVar2 = uVar9;
            *(ulong *)(param_1 + 0x3f8) = (ulong)~(uint)lVar6 & 1;
            if (plVar8 == (long *)0x0) goto LAB_fffffff009c339f8;
            goto LAB_fffffff009c339d8;
          }
          lVar4 = lVar4 + 1;
          lVar7 = lVar7 + 0x10;
          lVar6 = lVar6 + -1;
        } while (lVar6 != 0);
      }
      plVar8 = (long *)0x0;
      goto LAB_fffffff009c339f8;
    }
    lVar6 = 0x18;
  }
  plVar8 = *(long **)(lVar1 + lVar6);
  if (plVar8 != (long *)0x0) {
LAB_fffffff009c339d8:
    (**(code **)(*plVar8 + 0x20))(plVar8);
  }
LAB_fffffff009c339f8:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 1000));
  return plVar8;
}

