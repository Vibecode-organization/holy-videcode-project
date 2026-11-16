// FUN_fffffff0099411b4 @ fffffff0099411b4 size=56

/* WARNING: Removing unreachable block (ram,0xfffffff009941334) */

undefined8 FUN_fffffff0099411b4(int param_1,undefined8 param_2,uint *param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong unaff_x30;
  
  if (param_1 != 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
      uVar2 = thunk_EXT_FUN_801100000321d024(param_1 + 0x3fU >> 3 & 0x1ffffff8,4);
      return uVar2;
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099411d8);
    (*pcVar1)();
  }
  lVar3 = FUN_fffffff0099832a0();
  if (*(long **)(lVar3 + 0xc0) != (long *)0x0) {
    (**(code **)(**(long **)(lVar3 + 0xc0) + 0x28))();
  }
  *(undefined8 *)(lVar3 + 0xc0) = 0;
  if (*(long **)(lVar3 + 0xb8) != (long *)0x0) {
    (**(code **)(**(long **)(lVar3 + 0xb8) + 0x28))();
  }
  *(undefined8 *)(lVar3 + 0xb8) = 0;
  if (*(long **)(lVar3 + 0xb0) != (long *)0x0) {
    (**(code **)(**(long **)(lVar3 + 0xb0) + 0x28))();
  }
  *(undefined8 *)(lVar3 + 0xb0) = 0;
  if (*(long *)(lVar3 + 0xa8) != 0) {
    if (*(int *)(lVar3 + 0xa0) == 0) {
      lVar3 = FUN_fffffff0099832b0();
      uVar2 = 0xe00002c7;
      FUN_fffffff009942d70();
      if (*(int *)(lVar3 + 0xa4) == 0) {
        uVar2 = 0xe00002bd;
      }
      else if (param_3 != (uint *)0x0) {
        *param_3 = (uint)*(byte *)(lVar3 + 0x35);
      }
      FUN_fffffff009942d7c(lVar3);
      return uVar2;
    }
    thunk_EXT_FUN_801100000321d75c
              (*(long *)(lVar3 + 0xa8),*(int *)(lVar3 + 0xa0) + 0x3fU >> 3 & 0x1ffffff8);
    *(undefined8 *)(lVar3 + 0xa8) = 0;
  }
  lVar5 = *(long *)(lVar3 + 0x98);
  if (lVar5 != 0) {
    uVar7 = (ulong)*(uint *)(lVar3 + 0xa0);
    if (*(uint *)(lVar3 + 0xa0) == 0) {
      lVar6 = 0;
    }
    else {
      uVar8 = 0;
      do {
        plVar4 = *(long **)(lVar5 + uVar8 * 8);
        if (plVar4 != (long *)0x0) {
          (**(code **)(*plVar4 + 0x28))();
          lVar5 = *(long *)(lVar3 + 0x98);
          uVar7 = (ulong)*(uint *)(lVar3 + 0xa0);
        }
        *(undefined8 *)(lVar5 + uVar8 * 8) = 0;
        uVar8 = uVar8 + 1;
      } while (uVar8 < uVar7);
      lVar6 = uVar7 << 3;
    }
    *(undefined8 *)(lVar3 + 0x98) = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff0ff8,lVar5,lVar6);
    *(undefined8 *)(lVar3 + 0x98) = 0;
  }
  uVar2 = (*DAT_fffffff007fe9080)(lVar3);
  return uVar2;
}

