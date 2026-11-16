// FUN_fffffff0081c983c @ fffffff0081c983c size=4

/* WARNING: Removing unreachable block (ram,0xfffffff0081c98d0) */

void FUN_fffffff0081c983c(long *param_1,ulong param_2,ulong param_3,undefined4 param_4)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  undefined2 uVar4;
  ulong unaff_x30;
  undefined8 uStack_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 uStack_38;
  
  thunk_EXT_FUN_80110000038ff214(param_1[0x29a]);
  uStack_38 = 0;
  uStack_48 = (**(code **)(*param_1 + 0x208))(param_1,param_2,0);
  uStack_40 = (undefined4)(param_3 >> 0xc);
  uStack_3c = param_4;
  iVar3 = (**(code **)(*param_1 + 0x288))(*param_1 + 0x288,param_1);
  bVar1 = 0;
  if (0xffffffa0bfffffff < param_2) {
    bVar1 = 0xffffff9fffdfffff < param_2 & (*(byte *)((long)param_1 + 0x291) ^ 0xff);
  }
  uVar4 = 2;
  if ((bVar1 & param_2 < 0xffffffa180000000) == 0) {
    uVar4 = 0;
  }
  uStack_38._0_4_ = CONCAT22(uVar4,(short)(1 << (ulong)(DAT_fffffff00ae2181c - iVar3 & 0x1f)));
  if ((*(byte *)(param_1 + 0x29d) & 1) != 0) {
    FUN_fffffff0081c9990(param_1,&uStack_48);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_80110000038ff2e0(param_1[0x29a]);
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081c998c);
  (*pcVar2)();
}

