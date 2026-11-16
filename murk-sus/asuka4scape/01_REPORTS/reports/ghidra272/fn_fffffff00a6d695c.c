// FUN_fffffff00a6d695c @ fffffff00a6d695c size=488

void FUN_fffffff00a6d695c(long param_1)

{
  ulong *puVar1;
  long lVar2;
  undefined2 uVar3;
  int iVar4;
  undefined8 *puVar5;
  int *piVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  int in_wzr;
  undefined4 in_register_000040fc;
  undefined8 local_38;
  
  lVar2 = tpidr_el1;
  puVar1 = (ulong *)(param_1 + 0x58);
  if (*puVar1 == 0) {
    *puVar1 = (ulong)*(uint *)(lVar2 + 0x4e8);
  }
  else {
    FUN_fffffff00a2262d4(param_1 + 0x50,lVar2,0);
  }
  puVar5 = *(undefined8 **)(param_1 + 0x638);
  *(long *)(param_1 + 0x638) = CONCAT44(in_register_000040fc,in_wzr);
  if (*(int *)puVar1 == *(int *)(lVar2 + 0x4e8)) {
    *(int *)puVar1 = in_wzr;
  }
  else {
    FUN_fffffff00a226e08(param_1 + 0x50,lVar2);
  }
  if (puVar5 != (undefined8 *)0x0) {
    if ((*(ushort *)(lVar2 + 0x528) >> 5 & 1) != 0) {
      *(undefined8 *)(lVar2 + 0x2c8) = 0;
    }
    FUN_fffffff00a27bd90(*puVar5);
    FUN_fffffff00a27bd90(puVar5[1]);
    FUN_fffffff00a27bd90(puVar5[2]);
    FUN_fffffff00a27b31c(*puVar5);
    FUN_fffffff00a27b31c(puVar5[1]);
    FUN_fffffff00a27b31c(puVar5[2]);
    lVar9 = puVar5[0x1c];
    while (lVar8 = lVar9, lVar8 != 0) {
      lVar9 = *(long *)(lVar8 + 0x1b8);
      *(undefined8 *)(lVar8 + -0x2c8) = 0;
      if (lVar8 != 0x590) {
        piVar6 = (int *)(lVar8 + -0x378);
        iVar4 = *piVar6;
        *piVar6 = iVar4 + -1;
        LORelease();
        if (iVar4 == 0) goto LAB_fffffff00a6d6a64;
        if (iVar4 == 1) {
          FUN_fffffff00a270c78();
        }
      }
    }
    piVar6 = (int *)(puVar5 + 7);
    iVar4 = *piVar6;
    *piVar6 = iVar4 + -1;
    if (iVar4 == 0) {
LAB_fffffff00a6d6a64:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa61ea0(piVar6);
    }
    if (iVar4 == 1) {
      local_38 = 0;
      lVar9 = puVar5[3];
      lVar8 = *(long *)(lVar9 + 0x18);
      if (lVar8 == 0) {
        uVar7 = 0;
        puVar5[3] = 0;
      }
      else {
        *(undefined8 *)(lVar9 + 0x18) = *(undefined8 *)(lVar8 + 0x18);
        *(undefined8 *)(lVar8 + 0x18) = 0;
        uVar7 = puVar5[3];
        lVar9 = lVar8;
      }
      FUN_fffffff00a28646c(puVar5,lVar2,lVar9,uVar7,&local_38);
      FUN_fffffff00a287c08();
      FUN_fffffff00a285dac(local_38);
      if (*(uint *)(puVar5 + 4) >> 0x18 != 0x44) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa51020(puVar5 + 4);
      }
      *(uint *)(puVar5 + 4) = *(uint *)(puVar5 + 4) & 0xffffff;
      *(undefined4 *)(puVar5 + 5) = 0;
      lVar2 = *DAT_fffffff007c063a0;
      lVar9 = DAT_fffffff007c063a0[1];
      uVar3 = *(undefined2 *)(lVar2 + 0x34);
      FUN_fffffff00aa65cc0(puVar5,uVar3);
      FUN_fffffff00a29223c(lVar2,lVar9,puVar5,uVar3);
    }
  }
  return;
}

