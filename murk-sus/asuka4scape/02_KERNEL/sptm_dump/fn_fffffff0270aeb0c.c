// FUN_fffffff0270aeb0c @ fffffff0270aeb0c size=968
// CALLERS:
//   fffffff02701c0e8 ?

void FUN_fffffff0270aeb0c(undefined8 param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  undefined8 uVar4;
  undefined2 *puVar5;
  ulong uVar6;
  ulong uVar7;
  byte in_wzr;
  undefined1 auVar8 [16];
  
  pbVar3 = (byte *)FUN_fffffff0270be6dc(param_1,2,5);
  if ((*pbVar3 & 5) != 0) {
    uVar6 = *(ulong *)(pbVar3 + 8);
    FUN_fffffff0270dfa18(uVar6,0x18);
    if (*pbVar3 == 4) {
      uVar7 = *(ulong *)(pbVar3 + 0x10);
      FUN_fffffff0270dfa18(uVar7,0x18);
    }
    else {
      uVar7 = 0xffffffff;
    }
    iVar2 = FUN_fffffff0270dff8c(uVar6,0xffffffff);
    uVar4 = extraout_x1;
    if ((iVar2 != 1) ||
       ((*pbVar3 == 4 &&
        (iVar2 = FUN_fffffff0270dff8c(uVar7,0xffffffff), uVar4 = extraout_x1_00, iVar2 != 1)))) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f353c(0x4000007,uVar4,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx)\n");
    }
    if ((uVar6 < DAT_fffffff0270921c8) || (DAT_fffffff0270921d0 <= uVar6)) {
      auVar8 = FUN_fffffff0270de884(uVar6);
      uVar4 = auVar8._8_8_;
      puVar5 = &DAT_fffffff0270fdec0;
      if (auVar8._0_8_ != (undefined2 *)0x0) {
        puVar5 = auVar8._0_8_;
      }
    }
    else {
      puVar5 = (undefined2 *)
               (DAT_fffffff0270914f0 + (uVar6 - DAT_fffffff0270921c8 >> 0xe & 0xffffffff) * 0x10);
    }
    if (*(char *)(puVar5 + 4) != '\x02') {
LAB_fffffff0270aee9c:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f353c(0x4000000,uVar4,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx)\n");
    }
    *(char *)(puVar5 + 4) = '\x03';
    bVar1 = *pbVar3;
    if (bVar1 == 4) {
      if ((uVar7 < DAT_fffffff0270921c8) || (DAT_fffffff0270921d0 <= uVar7)) {
        auVar8 = FUN_fffffff0270de884(uVar7);
        uVar4 = auVar8._8_8_;
        puVar5 = &DAT_fffffff0270fdec0;
        if (auVar8._0_8_ != (undefined2 *)0x0) {
          puVar5 = auVar8._0_8_;
        }
      }
      else {
        puVar5 = (undefined2 *)
                 (DAT_fffffff0270914f0 + (uVar7 - DAT_fffffff0270921c8 >> 0xe & 0xffffffff) * 0x10);
      }
      if (*(char *)(puVar5 + 4) != '\x02') goto LAB_fffffff0270aee9c;
      *(char *)(puVar5 + 4) = '\x03';
      bVar1 = *pbVar3;
    }
    if ((bVar1 & 5) != 0) {
      pbVar3[8] = 0xff;
      pbVar3[9] = 0xff;
      pbVar3[10] = 0xff;
      pbVar3[0xb] = 0xff;
      pbVar3[0xc] = 0;
      pbVar3[0xd] = 0;
      pbVar3[0xe] = 0;
      pbVar3[0xf] = 0;
      if (bVar1 == 4) {
        pbVar3[0x10] = 0xff;
        pbVar3[0x11] = 0xff;
        pbVar3[0x12] = 0xff;
        pbVar3[0x13] = 0xff;
        pbVar3[0x14] = 0;
        pbVar3[0x15] = 0;
        pbVar3[0x16] = 0;
        pbVar3[0x17] = 0;
      }
      if (*(short *)(pbVar3 + 0x18) != -1) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff0270f353c(0x4000006,uVar4,"%s(%s:%d) - %s(%#llx), %s(%#llx)\n");
      }
      FUN_fffffff0270dff8c(param_1,0xffffffff);
      FUN_fffffff0270dfc5c(uVar6);
      if (*pbVar3 == 4) {
        FUN_fffffff0270dfc5c(uVar7);
      }
      if (pbVar3[0x1a] != 1) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff0270f34fc("%s: state_guard_release - %#llx, %#llx");
      }
      pbVar3[0x1a] = in_wzr;
      if ((*pbVar3 & 5) == 0) {
        return;
      }
      FUN_fffffff0270d2f50(pbVar3);
      FUN_fffffff0270dfc5c();
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff0270f34fc("%s: %d is not a valid UAT state object type when getting TTBR%d");
}

