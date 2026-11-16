// FUN_fffffff0099411ec @ fffffff0099411ec size=348

undefined8 FUN_fffffff0099411ec(long param_1,undefined8 param_2,uint *param_3)

{
  code *pcVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0xc0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xc0) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xc0) = 0;
  if (*(long **)(param_1 + 0xb8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xb8) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xb8) = 0;
  if (*(long **)(param_1 + 0xb0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xb0) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xb0) = 0;
  if (*(long *)(param_1 + 0xa8) != 0) {
    if (*(int *)(param_1 + 0xa0) == 0) {
      lVar4 = FUN_fffffff0099832b0();
      uVar3 = 0xe00002c7;
      FUN_fffffff009942d70();
      if (*(int *)(lVar4 + 0xa4) == 0) {
        uVar3 = 0xe00002bd;
      }
      else if (param_3 != (uint *)0x0) {
        *param_3 = (uint)*(byte *)(lVar4 + 0x35);
      }
      FUN_fffffff009942d7c(lVar4);
      return uVar3;
    }
    thunk_EXT_FUN_801100000321d75c
              (*(long *)(param_1 + 0xa8),*(int *)(param_1 + 0xa0) + 0x3fU >> 3 & 0x1ffffff8);
    *(undefined8 *)(param_1 + 0xa8) = 0;
  }
  lVar4 = *(long *)(param_1 + 0x98);
  if (lVar4 != 0) {
    uVar6 = (ulong)*(uint *)(param_1 + 0xa0);
    if (*(uint *)(param_1 + 0xa0) == 0) {
      lVar5 = 0;
    }
    else {
      uVar7 = 0;
      do {
        plVar2 = *(long **)(lVar4 + uVar7 * 8);
        if (plVar2 != (long *)0x0) {
          (**(code **)(*plVar2 + 0x28))();
          lVar4 = *(long *)(param_1 + 0x98);
          uVar6 = (ulong)*(uint *)(param_1 + 0xa0);
        }
        *(undefined8 *)(lVar4 + uVar7 * 8) = 0;
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar6);
      lVar5 = uVar6 << 3;
    }
    *(undefined8 *)(param_1 + 0x98) = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff0ff8,lVar4,lVar5);
    *(undefined8 *)(param_1 + 0x98) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009941338);
    (*pcVar1)();
  }
  uVar3 = (*DAT_fffffff007fe9080)(param_1);
  return uVar3;
}

