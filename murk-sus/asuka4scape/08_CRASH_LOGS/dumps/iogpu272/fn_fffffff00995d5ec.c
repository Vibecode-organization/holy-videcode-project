// FUN_fffffff00995d5ec @ fffffff00995d5ec size=348

void FUN_fffffff00995d5ec(long param_1,long *param_2)

{
  long *plVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  code *pcVar6;
  uint uVar7;
  ulong unaff_x30;
  
  uVar2 = *(uint *)(param_1 + 0x50);
  uVar3 = *(uint *)(param_1 + 0x54);
  if (uVar2 - *(int *)(param_1 + 0x48) == uVar3) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995d65c);
      (*pcVar6)();
    }
    FUN_fffffff00995d3a8(param_1,param_2);
    return;
  }
  uVar7 = *(uint *)(param_1 + 0xc);
  *(uint *)(param_1 + 0xc) = uVar7 + 1;
  uVar5 = 0;
  if (uVar3 != 0) {
    uVar5 = uVar2 / uVar3;
  }
  if (0xffffffe < uVar7) {
    FUN_fffffff009983678(param_1);
  }
  param_2[10] = param_1;
  uVar7 = *(uint *)((long)param_2 + 0xc);
  *(uint *)((long)param_2 + 0xc) = uVar7 + 1;
  if (0xffffffe < uVar7) {
    FUN_fffffff009983678(param_2);
  }
  lVar4 = (ulong)(uVar2 - uVar5 * uVar3) * 8;
  plVar1 = (long *)(*(long *)(param_1 + 0x58) + (long)(int)lVar4);
  if (lVar4 != (int)lVar4) {
    plVar1 = (long *)(*(long *)(param_1 + 0x58) + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *plVar1 = (long)param_2;
  if ((*(byte *)(param_1 + 0x65) & 1) != 0) {
    if ((*(byte *)((long)param_2 + 0x4c) & 1) == 0) {
      (**(code **)(*param_2 + 0x88))(param_2);
    }
    if (param_2[0xd] != 0) {
      *(undefined4 *)(param_2[0xd] + 200) = 0x13;
    }
  }
  *(uint *)(param_1 + 0x50) = uVar2 + 1;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995d72c);
    (*pcVar6)();
  }
  FUN_fffffff00996098c(*(undefined8 *)(param_1 + 0x10),param_1);
  return;
}

