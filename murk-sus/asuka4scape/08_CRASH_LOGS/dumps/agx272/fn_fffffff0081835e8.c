// FUN_fffffff0081835e8 @ fffffff0081835e8 size=828

/* WARNING: Removing unreachable block (ram,0xfffffff0081837f0) */

void FUN_fffffff0081835e8(long *param_1,long *param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  undefined4 *puVar15;
  ulong unaff_x30;
  undefined8 uVar16;
  
  if ((*(byte *)((long)param_2 + 0x4c) & 1) != 0) {
    return;
  }
  puVar5 = (undefined8 *)(**(code **)(*param_2 + 0xf0))(param_2);
  uVar6 = (**(code **)(*param_2 + 0xf8))(param_2);
  FUN_fffffff008183924
            (param_1,uVar6,*(undefined4 *)((long)param_2 + 0x1dc),param_2[0x20],
             *(undefined4 *)puVar5,param_2 + 0x68);
  lVar14 = param_1[2];
  lVar7 = (**(code **)(**(long **)(*(long *)(lVar14 + 0x183a8) + 0x50) + 0x98))();
  uVar1 = *(uint *)(lVar14 + 0x4a0);
  lVar14 = param_1[2];
  lVar8 = (**(code **)(**(long **)(*(long *)(lVar14 + 0x183b0) + 0x50) + 0x98))();
  uVar2 = *(uint *)(lVar14 + 0x4a4);
  uVar9 = (**(code **)(**(long **)(param_1[2] + 0x148) + 0x88))
                    (*(long **)(param_1[2] + 0x148),*(undefined4 *)((long)puVar5 + 4));
  uVar10 = (**(code **)(**(long **)(param_1[2] + 0x148) + 0x88))
                     (*(long **)(param_1[2] + 0x148),*(undefined4 *)((long)puVar5 + 4));
  lVar14 = param_1[7];
  lVar3 = param_2[9];
  puVar15 = (undefined4 *)param_2[0x87];
  *puVar15 = 9;
  uVar16 = *puVar5;
  lVar11 = thunk_EXT_FUN_8011000003890f30(param_2[0xc],&DAT_fffffff00ae21f50);
  lVar13 = *(long *)(lVar11 + 0x620);
  *(long *)(lVar11 + 0x620) = lVar13 + 1;
  *(long *)(puVar15 + 1) = lVar13;
  puVar15[5] = *(undefined4 *)((long)param_2 + 0x1dc);
  puVar15[6] = param_3;
  puVar15[0x14] = *(byte *)((long)param_2 + 0x44c) & 1;
  uVar12 = thunk_EXT_FUN_8011000002c13530(param_2[0x48]);
  *(ulong *)(puVar15 + 0x15) = uVar12 & 0xffffffff;
  *(long *)(puVar15 + 0x17) = param_2[0x49];
  lVar11 = **(long **)(param_2[2] + 0x4b0);
  uVar6 = (**(code **)(lVar11 + 0x208))
                    (lVar11 + 0x208,*(long **)(param_2[2] + 0x4b0),param_2[0x4c],0);
  *(undefined8 *)(puVar15 + 0x1b) = uVar6;
  *(long *)(puVar15 + 0x19) = param_2[0x4a];
  if (param_2[0x4d] == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (**(code **)(**(long **)(param_2[2] + 0x4b0) + 0x208))
                      (*(long **)(param_2[2] + 0x4b0),param_2[0x4d],0);
  }
  *(undefined8 *)(puVar15 + 0x1d) = uVar6;
  (**(code **)(*param_2 + 0xe0))(param_2,1);
  *(long *)(puVar15 + 3) = param_2[0x40];
  *(ulong *)(puVar15 + 0xc) = lVar7 + (ulong)uVar1 + (uVar9 & 0xffffffff);
  *(ulong *)(puVar15 + 0xe) = lVar8 + (ulong)uVar2 + (uVar10 & 0xffffffff);
  *(undefined8 *)(puVar15 + 0x10) = uVar16;
  puVar15[0x12] = (int)lVar14;
  puVar15[0x13] = (uint)((int)lVar3 != 0);
  *(long *)(puVar15 + 10) = param_2[0x20];
  (**(code **)(*param_1 + 0xe8))(param_1,puVar15,param_2,param_2 + 0x10);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008183920. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 200))
              (param_1,param_2[0x88],puVar15,param_2[0x20],(undefined8 *)(*param_1 + 200));
    return;
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008183918);
  (*pcVar4)();
}

