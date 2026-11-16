// FUN_fffffff009aa3d3c @ fffffff009aa3d3c size=248 depth=0
// CALLERS:
//   fffffff00afe886d ?
//   fffffff008024700 ?
// CALLS:
//   fffffff009aa19f4 FUN_fffffff009aa19f4

undefined8
FUN_fffffff009aa3d3c
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined8 param_8,long param_9)

{
  long lVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  bool bVar5;
  long lVar6;
  undefined8 uVar7;
  ulong unaff_x30;
  
  uVar7 = 0xe00002c2;
  lVar6 = *(long *)(param_9 + 0x30);
  if ((lVar6 != 0) && (1 < *(uint *)(param_9 + 0x28))) {
    iVar2 = **(int **)(param_9 + 0x20);
    bVar5 = FUN_fffffff009aa19f4
                      (param_1,param_2,param_3,param_4,param_5,param_6,*(long *)(param_7 + 0xe8),
                       iVar2,*(int *)(param_7 + 0x104),(ulong)*(uint *)(param_7 + 0x108));
    if (bVar5) {
      iVar3 = *(int *)(param_9 + 0x28) + -2;
      lVar1 = 0;
      if (iVar3 != 0) {
        lVar1 = *(long *)(param_9 + 0x20) + 0x10;
      }
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009aa3e0c);
        (*pcVar4)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff009aa3e14. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      uVar7 = (**(code **)(**(long **)(param_7 + 0xd8) + 0x720))
                        (*(long **)(param_7 + 0xd8),*(undefined8 *)(param_7 + 0xe8),iVar2,
                         *(undefined4 *)(*(long *)(param_9 + 0x20) + 8),lVar1,iVar3,lVar6,
                         *(undefined4 *)(param_9 + 0x38));
      return uVar7;
    }
    uVar7 = 0xe00002c1;
  }
  return uVar7;
}

