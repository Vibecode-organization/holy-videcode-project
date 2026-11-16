// FUN_fffffff0081a80e0 @ fffffff0081a80e0 size=1976

/* WARNING: Removing unreachable block (ram,0xfffffff0081a842c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081a8390) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081a8308) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081a8268) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081a82b0) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081a834c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081a83e8) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081a84e4) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081a8148) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff0081a80e0(long *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  ulong unaff_x30;
  float fVar12;
  
  thunk_EXT_FUN_8011000003a61cc0(param_1[0x58],0x6c48);
  thunk_EXT_FUN_8011000003a61b10(param_1[0x58] + 0xb0,param_1 + 0x126,0x160);
  uVar6 = (**(code **)(*(long *)param_1[0x50] + 0xb88))(*(long *)param_1[0x50] + 0xb88);
  lVar9 = param_1[0x58];
  *(undefined4 *)(lVar9 + 4) = uVar6;
  *(undefined4 *)(lVar9 + 8) = uVar6;
  uVar8 = thunk_EXT_FUN_8011000003397c88();
  lVar10 = param_1[0x58];
  *(undefined8 *)(lVar10 + 0x6a7c) = uVar8;
  uVar8 = DAT_fffffff007113e90;
  *(undefined8 *)(lVar10 + 0xc) = DAT_fffffff007113e90;
  *(undefined8 *)(lVar10 + 0x14) = 0x3f800000;
  *(undefined8 *)(lVar10 + 0x2c) = 0x100000001;
  *(undefined4 *)(lVar10 + 0x34) = 0;
  *(undefined4 *)(lVar10 + 0x50) = 100;
  *(undefined8 *)(lVar10 + 0x5c) = uVar8;
  *(undefined4 *)(lVar10 + 100) = 0x3f800000;
  uVar8 = _DAT_fffffff007113900;
  *(undefined8 *)(lVar10 + 0x70) = _UNK_fffffff007113908;
  *(undefined8 *)(lVar10 + 0x68) = uVar8;
  *(undefined4 *)(lVar10 + 0x90) = 100;
  lVar11 = param_1[0x50];
  *(undefined4 *)(lVar10 + 0x9cc) = 0;
  fVar12 = (float)NEON_ucvtf(*(undefined4 *)(lVar11 + 0x10eb8));
  *(float *)(lVar10 + 0x9d4) = (fVar12 + -1.0) / fVar12;
  *(float *)(lVar10 + 0x9dc) = 1.0 / fVar12;
  *(undefined4 *)(lVar10 + 0x9e4) = *(undefined4 *)(lVar11 + 0x10edc);
  *(undefined4 *)(lVar10 + 0x9f4) = *(undefined4 *)(lVar11 + 0x10ee8);
  uVar8 = NEON_scvtf(*(undefined8 *)(lVar11 + 0x10ee0),4);
  *(undefined8 *)(lVar10 + 0x9ec) = uVar8;
  *(undefined4 *)(lVar10 + 0x9fc) = *(undefined4 *)(lVar11 + 0x10eec);
  *(undefined8 *)(lVar10 + 0xa00) = *(undefined8 *)(lVar11 + 0x10ef0);
  *(undefined4 *)(lVar10 + 0xa14) = *(undefined4 *)(lVar11 + 0x10eb0);
  uVar6 = *(undefined4 *)(lVar11 + 0x10ef8);
  *(undefined4 *)(lVar10 + 0xa08) = uVar6;
  *(undefined4 *)(lVar10 + 0xa10) = 0;
  *(undefined4 *)(lVar10 + 0xa48) = uVar6;
  *(undefined4 *)(lVar10 + 0xa1c) = 0;
  *(undefined4 *)(lVar10 + 0xa44) = *(undefined4 *)(lVar11 + 0x10f08);
  *(undefined4 *)(lVar10 + 0xa4c) = *(undefined4 *)(lVar11 + 0x10f0c);
  uVar6 = (**(code **)(*param_1 + 0x848))(*param_1 + 0x848,param_1);
  *(undefined4 *)(lVar10 + 0xb54) = uVar6;
  *(undefined4 *)(lVar10 + 0xb58) = *(undefined4 *)(lVar11 + 0x10f38);
  uVar7 = (**(code **)(*param_1 + 0x840))(*param_1 + 0x840,param_1,0);
  fVar12 = (float)uVar7;
  *(float *)(lVar10 + 0xb5c) = (fVar12 + -1.0) / fVar12;
  *(float *)(lVar10 + 0xb64) = 1.0 / fVar12;
  uVar6 = (**(code **)(*param_1 + 0x830))(*param_1 + 0x830,param_1,0);
  *(undefined4 *)(lVar10 + 0xb6c) = uVar6;
  uVar6 = (**(code **)(*param_1 + 0x838))(*param_1 + 0x838,param_1,0);
  *(undefined4 *)(lVar10 + 0xb7c) = uVar6;
  uVar7 = (**(code **)(*param_1 + 0x840))(*param_1 + 0x840,param_1,1);
  fVar12 = (float)uVar7;
  *(float *)(lVar10 + 0xb60) = (fVar12 + -1.0) / fVar12;
  *(float *)(lVar10 + 0xb68) = 1.0 / fVar12;
  uVar6 = (**(code **)(*param_1 + 0x830))(*param_1 + 0x830,param_1,1);
  *(undefined4 *)(lVar10 + 0xb70) = uVar6;
  uVar6 = (**(code **)(*param_1 + 0x838))(*param_1 + 0x838,param_1,1);
  *(undefined4 *)(lVar10 + 0xb80) = uVar6;
  uVar8 = NEON_scvtf(*(undefined8 *)(lVar11 + 0x10f48),4);
  *(undefined8 *)(lVar10 + 0xb74) = uVar8;
  *(undefined4 *)(lVar10 + 0xb84) = *(undefined4 *)(lVar11 + 0x10f58);
  *(undefined8 *)(lVar10 + 0xb88) = *(undefined8 *)(lVar11 + 0x10f5c);
  *(undefined4 *)(lVar10 + 0xb98) = 0;
  iVar1 = *(int *)(lVar11 + 0x10f18);
  iVar2 = *(int *)(lVar11 + 0x10f1c);
  *(int *)(lVar10 + 0xb9c) = iVar1 - iVar2;
  *(int *)(lVar10 + 0xba4) = iVar2;
  lVar9 = param_1[0x58];
  *(int *)(lVar9 + 0xb38) = iVar1;
  uVar6 = NEON_ucvtf(*(undefined4 *)(lVar11 + 0x10f6c));
  *(undefined4 *)(lVar10 + 0xbcc) = uVar6;
  uVar8 = *(undefined8 *)(lVar11 + 0x10f64);
  *(int *)(lVar10 + 0xb90) = (int)uVar8;
  *(undefined8 *)(lVar10 + 0xbd0) = uVar8;
  *(int *)(lVar9 + 0x2880) = (int)param_1[0x16e] * 100;
  uVar6 = (**(code **)(*(long *)param_1[0x50] + 0x960))(*(long *)param_1[0x50] + 0x960);
  lVar10 = param_1[0x58];
  *(undefined4 *)(lVar10 + 0x2228) = uVar6;
  lVar9 = param_1[0x16e];
  *(int *)(lVar10 + 0x222c) = (int)lVar9 * 100;
  *(undefined4 *)(lVar10 + 0x2230) = 0;
  fVar12 = (float)NEON_ucvtf((int)param_1[0x179]);
  uVar8 = NEON_fmov(0x3f800000,4);
  *(ulong *)(lVar10 + 0x2234) =
       CONCAT44((float)((ulong)uVar8 >> 0x20) / fVar12,(fVar12 + -1.0) / fVar12);
  lVar10 = param_1[0x54];
  *(int *)(lVar10 + 0x10e0) = (int)lVar9;
  lVar9 = param_1[0x50];
  *(uint *)(lVar10 + 0x10e4) = *(uint *)(lVar9 + 0x19448) / 1000000;
  *(uint *)(lVar10 + 0x1924) = *(uint *)(lVar9 + 0x19c90) / 1000000;
  *(uint *)(lVar10 + 0x10e8) = *(uint *)(lVar9 + 0x1944c) / 1000000;
  *(uint *)(lVar10 + 0x1928) = *(uint *)(lVar9 + 0x19c94) / 1000000;
  *(uint *)(lVar10 + 0x10ec) = *(uint *)(lVar9 + 0x19450) / 1000000;
  *(uint *)(lVar10 + 0x192c) = *(uint *)(lVar9 + 0x19c98) / 1000000;
  *(uint *)(lVar10 + 0x10f0) = *(uint *)(lVar9 + 0x19454) / 1000000;
  *(uint *)(lVar10 + 0x1930) = *(uint *)(lVar9 + 0x19c9c) / 1000000;
  *(uint *)(lVar10 + 0x10f4) = *(uint *)(lVar9 + 0x19458) / 1000000;
  *(uint *)(lVar10 + 0x1934) = *(uint *)(lVar9 + 0x19ca0) / 1000000;
  *(uint *)(lVar10 + 0x10f8) = *(uint *)(lVar9 + 0x1945c) / 1000000;
  *(uint *)(lVar10 + 0x1938) = *(uint *)(lVar9 + 0x19ca4) / 1000000;
  *(uint *)(lVar10 + 0x10fc) = *(uint *)(lVar9 + 0x19460) / 1000000;
  *(uint *)(lVar10 + 0x193c) = *(uint *)(lVar9 + 0x19ca8) / 1000000;
  *(uint *)(lVar10 + 0x1100) = *(uint *)(lVar9 + 0x19464) / 1000000;
  *(uint *)(lVar10 + 0x1940) = *(uint *)(lVar9 + 0x19cac) / 1000000;
  *(uint *)(lVar10 + 0x1104) = *(uint *)(lVar9 + 0x19468) / 1000000;
  *(uint *)(lVar10 + 0x1944) = *(uint *)(lVar9 + 0x19cb0) / 1000000;
  *(uint *)(lVar10 + 0x1108) = *(uint *)(lVar9 + 0x1946c) / 1000000;
  *(uint *)(lVar10 + 0x1948) = *(uint *)(lVar9 + 0x19cb4) / 1000000;
  *(uint *)(lVar10 + 0x110c) = *(uint *)(lVar9 + 0x19470) / 1000000;
  *(uint *)(lVar10 + 0x194c) = *(uint *)(lVar9 + 0x19cb8) / 1000000;
  *(uint *)(lVar10 + 0x1110) = *(uint *)(lVar9 + 0x19474) / 1000000;
  *(uint *)(lVar10 + 0x1950) = *(uint *)(lVar9 + 0x19cbc) / 1000000;
  *(uint *)(lVar10 + 0x1114) = *(uint *)(lVar9 + 0x19478) / 1000000;
  *(uint *)(lVar10 + 0x1954) = *(uint *)(lVar9 + 0x19cc0) / 1000000;
  *(uint *)(lVar10 + 0x1118) = *(uint *)(lVar9 + 0x1947c) / 1000000;
  *(uint *)(lVar10 + 0x1958) = *(uint *)(lVar9 + 0x19cc4) / 1000000;
  *(uint *)(lVar10 + 0x111c) = *(uint *)(lVar9 + 0x19480) / 1000000;
  *(uint *)(lVar10 + 0x195c) = *(uint *)(lVar9 + 0x19cc8) / 1000000;
  *(uint *)(lVar10 + 0x1120) = *(uint *)(lVar9 + 0x19484) / 1000000;
  *(uint *)(lVar10 + 0x1960) = *(uint *)(lVar9 + 0x19ccc) / 1000000;
  lVar10 = param_1[0x50];
  lVar9 = param_1[0x69];
  *(uint *)(lVar9 + 0x30) = *(uint *)(lVar10 + 0x5c8) & 1;
  *(undefined4 *)(lVar9 + 0x2c) = *(undefined4 *)(lVar10 + 0x5f8);
  iVar1 = *(int *)(lVar10 + 0x5f4);
  if (iVar1 != 0) {
    *(int *)(lVar9 + 0x94) = iVar1;
    *(int *)(lVar9 + 0xac) = iVar1;
  }
  *(undefined8 *)(lVar9 + 0xa00) = 0;
  uVar7 = *(uint *)(param_1 + 0x171);
  thunk_EXT_FUN_80110000032222a8(param_1[0x178]);
  *(uint *)(param_1 + 0x171) = uVar7;
  if ((*(byte *)(param_1 + 0x170) & 1) == 0) {
    uVar7 = *(uint *)((long)param_1 + 0xb84);
  }
  lVar9 = param_1[0x50];
  *(uint *)(param_1[0x69] + 0x84) = uVar7;
  uVar3 = *(uint *)(lVar9 + 0x10eb0);
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = uVar7 / uVar3;
  }
  uVar4 = uVar4 * 100;
  if (99 < uVar4) {
    uVar4 = 100;
  }
  thunk_EXT_FUN_80110000039b78d4
            (*(undefined8 *)(*(long *)(lVar9 + 0x1ac50) + 0x78),0,(ulong)uVar4 * 0x1999999a >> 0x20)
  ;
  lVar9 = param_1[0x50];
  if ((*(byte *)(lVar9 + 0x1ac44) >> 2 & 1) != 0) {
    uVar6 = *(undefined4 *)(param_1[0x69] + 0x84);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar9 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85920860,uVar6,uVar7,0,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar9 + 0x1ac48));
  }
  thunk_EXT_FUN_8011000003222de0(param_1[0x178]);
  FUN_fffffff0081a8898(param_1,1,*(undefined4 *)((long)param_1 + 0xb94),0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    FUN_fffffff0081a8898(param_1,2,(int)param_1[0x174],0);
    return;
  }
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081a888c);
  (*pcVar5)();
}

