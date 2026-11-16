// FUN_fffffff00a216520 @ fffffff00a216520 size=1268

void FUN_fffffff00a216520
               (long param_1,undefined8 param_2,long param_3,undefined4 param_4,undefined4 param_5)

{
  long *plVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  int in_wzr;
  long local_150 [30];
  
  local_150[0x1c] = DAT_fffffff00ad30000;
  if (param_1 == 0) {
    uVar4 = 4;
  }
  else {
    uVar4 = FUN_fffffff00a21e488(0);
    if ((int)uVar4 == 0) {
      iVar3 = FUN_fffffff00aa3bd38(uVar4,param_2);
      if (iVar3 == 0) {
        lVar5 = FUN_fffffff00a29b24c();
        lVar6 = *(long *)(lVar5 + 0x18);
        if (*(long *)(lVar5 + 0x18) == 0) {
          lVar6 = DAT_fffffff007c6b250;
        }
        uVar4 = FUN_fffffff00aa3ca04(lVar6);
        lVar6 = FUN_fffffff00aa1c310(param_1 + 0x170);
        if (lVar6 == 0) {
          local_150[1] = FUN_fffffff00aa1c080(param_1 + 0x170,0,&DAT_fffffff007c6b298);
        }
        else {
          local_150[1] = 0;
        }
        local_150[0xb] = 0;
        local_150[10] = 0;
        local_150[0xd] = 0;
        local_150[0xc] = 0;
        local_150[7] = 0;
        local_150[6] = 0;
        local_150[9] = 0;
        local_150[8] = 0;
        local_150[3] = 0;
        local_150[2] = 0;
        local_150[5] = 0;
        local_150[4] = 0;
        local_150[0] = 0;
        lVar6 = FUN_fffffff00aa1c310(param_1 + 400);
        if (lVar6 == 0) {
          local_150[2] = FUN_fffffff00aa1c080(param_1 + 400,0,&DAT_fffffff007c6b298);
        }
        else {
          local_150[2] = 0;
        }
        lVar6 = FUN_fffffff00aa1c310(param_1 + 0x1b0);
        if (lVar6 == 0) {
          local_150[3] = FUN_fffffff00aa1c080(param_1 + 0x1b0,0,&DAT_fffffff007c6b298);
        }
        else {
          local_150[3] = 0;
        }
        lVar6 = FUN_fffffff00aa1c310(param_1 + 0x1d0);
        if (lVar6 == 0) {
          local_150[4] = FUN_fffffff00aa1c080(param_1 + 0x1d0,0,&DAT_fffffff007c6b298);
        }
        else {
          local_150[4] = 0;
        }
        lVar6 = FUN_fffffff00aa1c310(param_1 + 0x1f0);
        if (lVar6 == 0) {
          local_150[5] = FUN_fffffff00aa1c080(param_1 + 0x1f0,0,&DAT_fffffff007c6b298);
        }
        else {
          local_150[5] = 0;
        }
        lVar6 = FUN_fffffff00aa1c310(param_1 + 0x210);
        if (lVar6 == 0) {
          local_150[6] = FUN_fffffff00aa1c080(param_1 + 0x210,0,&DAT_fffffff007c6b298);
        }
        else {
          local_150[6] = 0;
        }
        lVar6 = FUN_fffffff00aa1c310(param_1 + 0x230);
        if (lVar6 == 0) {
          local_150[7] = FUN_fffffff00aa1c080(param_1 + 0x230,0,&DAT_fffffff007c6b298);
        }
        else {
          local_150[7] = 0;
        }
        lVar6 = FUN_fffffff00aa1c310(param_1 + 0x250);
        if (lVar6 == 0) {
          local_150[8] = FUN_fffffff00aa1c080(param_1 + 0x250,0,&DAT_fffffff007c6b298);
        }
        else {
          local_150[8] = 0;
        }
        lVar6 = FUN_fffffff00aa1c310(param_1 + 0x270);
        if (lVar6 == 0) {
          local_150[9] = FUN_fffffff00aa1c080(param_1 + 0x270,0,&DAT_fffffff007c6b298);
        }
        else {
          local_150[9] = 0;
        }
        lVar6 = FUN_fffffff00aa1c310(param_1 + 0x290);
        if (lVar6 == 0) {
          local_150[10] = FUN_fffffff00aa1c080(param_1 + 0x290,0,&DAT_fffffff007c6b298);
        }
        else {
          local_150[10] = 0;
        }
        lVar6 = FUN_fffffff00aa1c310(param_1 + 0x2b0);
        if (lVar6 == 0) {
          local_150[0xb] = FUN_fffffff00aa1c080(param_1 + 0x2b0,0,&DAT_fffffff007c6b298);
        }
        else {
          local_150[0xb] = 0;
        }
        lVar6 = FUN_fffffff00aa1c310(param_1 + 0x2d0);
        if (lVar6 == 0) {
          local_150[0xc] = FUN_fffffff00aa1c080(param_1 + 0x2d0,0,&DAT_fffffff007c6b298);
        }
        else {
          local_150[0xc] = 0;
        }
        lVar6 = FUN_fffffff00aa1c310(param_1 + 0x2f0);
        if (lVar6 == 0) {
          local_150[0xd] = FUN_fffffff00aa1c080(param_1 + 0x2f0,0,&DAT_fffffff007c6b298);
        }
        else {
          local_150[0xd] = 0;
        }
        local_150[0x19] = 0;
        local_150[0x18] = 0;
        local_150[0x1b] = 0;
        local_150[0x1a] = 0;
        local_150[0x15] = 0;
        local_150[0x14] = 0;
        local_150[0x17] = 0;
        local_150[0x16] = 0;
        local_150[0x11] = 0;
        local_150[0x10] = 0;
        local_150[0x13] = 0;
        local_150[0x12] = 0;
        local_150[0xf] = 0;
        local_150[0xe] = 0;
        lVar6 = tpidr_el1;
        if (*(ulong *)(param_1 + 8) == 0) {
          *(ulong *)(param_1 + 8) = (ulong)*(uint *)(lVar6 + 0x4e8);
        }
        else {
          FUN_fffffff00a2262d4(param_1,lVar6,0);
        }
        lVar8 = -0xd;
        lVar5 = 1;
        do {
          plVar1 = (long *)(param_1 + 0x138 + lVar5 * 0x20);
          lVar7 = FUN_fffffff00aa1c310(plVar1 + 3);
          if (lVar7 == 0) {
            FUN_fffffff00aa3c4a8(plVar1,local_150[lVar5]);
            local_150[lVar5] = 0;
          }
          if ((((uint)param_2 >> (ulong)((int)lVar8 + 0xeU & 0x1f) & 1) == 0) ||
             (iVar3 = FUN_fffffff00aa3c5d4(plVar1,uVar4), iVar3 != 0)) {
            local_150[lVar5 + 0xe] = 0;
          }
          else {
            local_150[lVar5 + 0xe] = *plVar1;
            lVar7 = param_3;
            if (1 < param_3 + 1U) {
              if (DAT_fffffff007bc7030 == param_3) {
                lVar7 = FUN_fffffff00a1f45e4();
              }
              else {
                lVar7 = FUN_fffffff00a1f472c();
              }
            }
            *plVar1 = lVar7;
            *(undefined4 *)(plVar1 + 1) = param_5;
            *(undefined4 *)((long)plVar1 + 0xc) = param_4;
          }
          lVar5 = lVar5 + 1;
          bVar2 = lVar8 != -1;
          lVar8 = lVar8 + 1;
        } while (bVar2);
        if (*(int *)(param_1 + 8) == *(int *)(lVar6 + 0x4e8)) {
          *(int *)(param_1 + 8) = in_wzr;
        }
        else {
          FUN_fffffff00a226e08(param_1);
        }
        FUN_fffffff00aa3c3b0(uVar4);
        lVar6 = 1;
        lVar5 = 0xd;
        do {
          if (local_150[lVar6 + 0xe] + 1U < 2) {
            lVar8 = local_150[lVar6];
          }
          else {
            FUN_fffffff00a1f4ae8();
            lVar8 = local_150[lVar6];
          }
          if (lVar8 != 0) {
            FUN_fffffff00aa3c3b0();
          }
          lVar6 = lVar6 + 1;
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
        if (1 < param_3 + 1U) {
          FUN_fffffff00a1f4ae8();
        }
        uVar4 = 0;
      }
      else {
        uVar4 = 8;
      }
    }
  }
  if (DAT_fffffff00ad30000 != local_150[0x1c]) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4c590(uVar4);
  }
  return;
}

