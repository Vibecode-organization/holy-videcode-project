// FUN_fffffff009961554 @ fffffff009961554 size=308

void FUN_fffffff009961554(long param_1,long *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x160));
  uVar1 = *(uint *)(param_2 + 9);
  if ((uVar1 != *(uint *)((long)param_2 + 0x4c)) && ((*(byte *)((long)param_2 + 0x62) & 1) == 0)) {
    param_2[6] = 0;
    plVar7 = *(long **)(param_1 + 0x170);
    param_2[7] = (long)plVar7;
    *plVar7 = (long)param_2;
    *(long **)(param_1 + 0x170) = param_2 + 6;
    *(byte *)((long)param_2 + 0x62) = 1;
    (**(code **)(*param_2 + 0x20))(param_2);
    lVar6 = thunk_EXT_FUN_8011000003397c88();
    param_2[0xf] = lVar6;
    uVar2 = *(uint *)((long)param_2 + 0x54);
    uVar3 = 0;
    if (uVar2 != 0) {
      uVar3 = uVar1 / uVar2;
    }
    lVar6 = (ulong)(uVar1 - uVar3 * uVar2) * 8;
    plVar7 = (long *)(param_2[0xb] + (long)(int)lVar6);
    if (lVar6 != (int)lVar6) {
      plVar7 = (long *)(param_2[0xb] + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
    }
    FUN_fffffff00994c49c(*(undefined8 *)(param_1 + 0x1b0),*plVar7 + 0x80,param_2 + 0x10);
    *(undefined1 *)(param_1 + 0x191) = 0;
    iVar5 = FUN_fffffff00994b9f8(*(undefined8 *)(param_1 + 0x1b0),param_2 + 0x10);
    if (iVar5 != 0) {
      (**(code **)(**(long **)(param_1 + 0x20) + 0xf8))(*(long **)(param_1 + 0x20),0,0,0);
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009961684);
    (*pcVar4)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x160));
  return;
}

