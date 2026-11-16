// FUN_fffffff009970bf8 @ fffffff009970bf8 size=300

void FUN_fffffff009970bf8(long param_1,long *param_2,undefined8 param_3)

{
  code *pcVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  ulong unaff_x30;
  
  uVar4 = (ulong)*(ushort *)((long)param_2 + 0x12);
  lVar2 = (**(code **)(*param_2 + 200))(param_2);
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x18));
  if ((*(ushort *)(param_2 + 2) >> 6 & 1) != 0) {
    lVar2 = FUN_fffffff00997f378(param_2);
  }
  plVar3 = *(long **)(param_1 + 0x138 + uVar4 * 8);
  (**(code **)(*plVar3 + 0xc0))(plVar3,param_3,lVar2);
  *(long *)(param_1 + 0xb8 + uVar4 * 8) = *(long *)(param_1 + 0xb8 + uVar4 * 8) - lVar2;
  lVar2 = param_2[7];
  if (lVar2 == 0) {
    plVar3 = (long *)param_2[8];
    if ((long *)*plVar3 != param_2) goto LAB_fffffff009970d14;
    *(long **)(param_1 + 0x1c0) = plVar3;
  }
  else {
    if (*(long **)(lVar2 + 0x40) != param_2 + 7) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009970d24);
      (*pcVar1)();
    }
    if (*(long **)param_2[8] != param_2) {
LAB_fffffff009970d14:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009970d1c);
      (*pcVar1)();
    }
    *(long **)(lVar2 + 0x40) = (long *)param_2[8];
    plVar3 = (long *)param_2[8];
  }
  *plVar3 = lVar2;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009970d10);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x18));
  return;
}

