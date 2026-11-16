// FUN_fffffff0081ea2fc @ fffffff0081ea2fc size=144

void FUN_fffffff0081ea2fc(long param_1,long *param_2)

{
  ulong uVar1;
  code *pcVar2;
  long lVar3;
  ulong unaff_x30;
  
  lVar3 = (ulong)*(uint *)((long)param_2 + 0xc) * 0x40;
  uVar1 = *(long *)(param_1 + 0x188) + (long)(int)lVar3;
  if (lVar3 - (int)lVar3 != 0) {
    uVar1 = *(long *)(param_1 + 0x188) + lVar3 & 0xffffffffffffU | 0x2bad000000000000;
  }
  thunk_EXT_FUN_801100000294849c
            (*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x148),param_1 + 200,uVar1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ea380);
    (*pcVar2)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081ea388. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x28))(param_2,(undefined8 *)(*param_2 + 0x28));
  return;
}

