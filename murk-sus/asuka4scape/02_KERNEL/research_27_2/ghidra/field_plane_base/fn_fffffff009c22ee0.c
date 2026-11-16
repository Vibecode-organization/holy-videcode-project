// FUN_fffffff009c22ee0 @ fffffff009c22ee0

/* WARNING: Removing unreachable block (ram,0xfffffff009c22f3c) */

void FUN_fffffff009c22ee0
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long param_7,uint param_8)

{
  ulong *puVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  code *pcVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  ulong uVar9;
  ulong uVar10;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 auVar11 [16];
  
  if (param_8 < 2) {
    do {
      if ((*(byte *)(param_7 + 0x3d2) >> 5 & 1) != 0) {
        uVar9 = thunk_FUN_fffffff00a725814();
        if (uVar9 == 0) {
          iVar8 = -1;
          auVar11 = extraout_q0;
        }
        else {
          iVar8 = thunk_FUN_fffffff00a724f30(uVar9);
          thunk_FUN_fffffff00a724838(uVar9);
          auVar11 = extraout_q0_00;
        }
        iVar4 = *(int *)(param_7 + 0x3d4);
        bVar6 = iVar4 != DAT_fffffff00af48588;
        bVar7 = iVar8 != DAT_fffffff00af4858c;
        if (bVar6 || bVar7) {
          DAT_fffffff00af48588 = iVar4;
          DAT_fffffff00af4858c = iVar8;
        }
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
          FUN_fffffff009c231e4
                    (auVar11,param_2,param_3,param_4,param_5,param_6,(uint)(bVar6 || bVar7));
          return;
        }
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2301c);
        (*pcVar5)();
      }
      do {
        uVar10 = *(ulong *)(*(long *)(param_7 + 0x178) + 0x18);
        uVar9 = (uVar10 & 0xffffffff00000000) + 0x100000000;
        if (0xfffffffeffffffff < uVar10) {
          uVar9 = 0xffffffff00000000;
        }
        uVar2 = 0xffffffff;
        if ((int)uVar10 != -1) {
          uVar2 = (ulong)((int)uVar10 + 1);
        }
        uVar3 = 0xffffffff;
        if (param_8 == 0) {
          uVar3 = 0xffffffff00000000;
          uVar9 = uVar2;
        }
        puVar1 = (ulong *)(*(long *)(param_7 + 0x178) + 0x18);
      } while (*puVar1 != uVar10);
      *puVar1 = uVar9 | uVar3 & uVar10;
      param_7 = *(long *)(param_7 + 0x378);
    } while (param_7 != 0);
  }
  return;
}

