// FUN_fffffff0081ee504 @ fffffff0081ee504 size=212

void FUN_fffffff0081ee504(long param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  ulong unaff_x30;
  
  lVar4 = *(long *)(param_1 + 0x90);
  while (lVar4 != 0) {
    lVar6 = (lVar4 + -1) * 8;
    puVar1 = (undefined8 *)(*(long *)(param_1 + 0x80) + (long)(int)lVar6);
    if (lVar6 - (int)lVar6 != 0) {
      puVar1 = (undefined8 *)
               (*(long *)(param_1 + 0x80) + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *(long *)(param_1 + 0x90) = lVar4 + -1;
    (**(code **)(*(long *)*puVar1 + 0x28))();
    lVar4 = *(long *)(param_1 + 0x90);
  }
  uVar2 = *(undefined8 *)(param_1 + 0x80);
  uVar5 = *(ulong *)(param_1 + 0x88) << 3;
  if (0x7fffffffffffffff < uVar5) {
    uVar5 = 0x8000000000000000;
  }
  if (*(ulong *)(param_1 + 0x88) >> 0x3d != 0) {
    uVar5 = 0x8000000000000000;
  }
  *(undefined8 *)(param_1 + 0x80) = 0;
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4968,uVar2,uVar5);
  *(undefined8 *)(param_1 + 0x80) = 0;
  *(undefined8 *)(param_1 + 0x88) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081ee5d4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(PTR_DAT_fffffff007ca60d8 + 0x80))(param_1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ee5cc);
  (*pcVar3)();
}

