// FUN_fffffff0081c9af4 @ fffffff0081c9af4 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff0081c9b88) */

void FUN_fffffff0081c9af4(long *param_1,ulong param_2,ulong param_3,int param_4)

{
  undefined8 *puVar1;
  byte bVar2;
  code *pcVar3;
  int iVar4;
  ushort uVar5;
  ushort uVar6;
  ulong unaff_x30;
  undefined8 uStack_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 uStack_38;
  
  thunk_EXT_FUN_80110000038ff214(param_1[0x29a]);
  uStack_38 = 0;
  uStack_48 = (**(code **)(*param_1 + 0x208))(param_1,param_2,0);
  uStack_40 = (undefined4)(param_3 >> 0xc);
  uStack_3c = 0;
  iVar4 = (**(code **)(*param_1 + 0x288))(*param_1 + 0x288,param_1);
  bVar2 = 0;
  if (0xffffffa0bfffffff < param_2) {
    bVar2 = 0xffffff9fffdfffff < param_2 & (*(byte *)((long)param_1 + 0x291) ^ 0xff);
  }
  uVar5 = 3;
  if ((bVar2 & param_2 < 0xffffffa180000000) == 0) {
    uVar5 = 1;
  }
  uVar6 = 4;
  if (param_4 == 0) {
    uVar6 = 0;
  }
  uStack_38._0_4_ =
       CONCAT22(uVar5 | uVar6,(short)(1 << (ulong)(DAT_fffffff00ae2181c - iVar4 & 0x1f)));
  if (param_1[0x29b] == 0) {
    if ((*(byte *)(param_1 + 0x29d) & 1) != 0) {
      FUN_fffffff0081c9990(param_1,&uStack_48);
    }
  }
  else {
    uVar5 = *(ushort *)(param_1 + 0x29c);
    if (*(ushort *)((long)param_1 + 0x14e2) <= uVar5) {
      thunk_EXT_FUN_8011000003a49114
                (
                "AGXk: %s:%d:%s: !!! Verification failed: %s: FW mappings descriptor is full (%u) - Too many mappings to record\n"
                );
      return;
    }
    *(ushort *)(param_1 + 0x29c) = uVar5 + 1;
    puVar1 = (undefined8 *)(param_1[0x29b] + (ulong)uVar5 * 0x18);
    puVar1[1] = CONCAT44(uStack_3c,uStack_40);
    *puVar1 = uStack_48;
    puVar1[2] = uStack_38;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_80110000038ff2e0(param_1[0x29a]);
    return;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081c9c90);
  (*pcVar3)();
}

