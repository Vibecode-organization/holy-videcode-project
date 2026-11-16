// FUN_fffffff009aaf910 @ fffffff009aaf910 size=348
// CALLERS:
//   fffffff00afb83a6 no-fn
//   fffffff009aafda8 FUN_fffffff009aafc60@fffffff009aafc60
// CALLEES:
//   fffffff009abd9fc thunk_EXT_FUN_8011000002c1e264
//   fffffff009abda6c thunk_EXT_FUN_8011000002c24af0
//   fffffff009abd8cc thunk_EXT_FUN_8011000002c1b1a8
//   fffffff009abdb9c thunk_EXT_FUN_8011000003a60ec0
//   fffffff009abd84c thunk_EXT_FUN_8011000002c20784

void FUN_fffffff009aaf910(long param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong unaff_x30;
  
  if ((param_1 != 0) && (lVar4 = thunk_EXT_FUN_8011000002c1e264(), lVar4 != 0)) {
    plVar5 = (long *)thunk_EXT_FUN_8011000002c1e264(param_1);
    plVar5 = (long *)(**(code **)(*plVar5 + 0xe8))(plVar5,0);
    if (plVar5 != (long *)0x0) {
      lVar4 = (**(code **)(*plVar5 + 0x78))();
      if (lVar4 != 0) {
        lVar6 = thunk_EXT_FUN_8011000002c24af0(param_1,0);
        if ((lVar6 == 0) || (*(char *)(lVar6 + 0x20) != '\x02')) {
          uVar9 = thunk_EXT_FUN_8011000002c1b1a8(param_1);
          uVar8 = thunk_EXT_FUN_8011000002c1b1a8(param_1);
          uVar7 = 0;
        }
        else {
          uVar1 = *(uint *)(lVar6 + 8);
          uVar8 = (ulong)uVar1;
          iVar3 = thunk_EXT_FUN_8011000002c1b1a8(param_1);
          uVar9 = (ulong)(iVar3 - uVar1);
          thunk_EXT_FUN_8011000003a60ec0(lVar4,uVar8,0,uVar8);
          lVar4 = lVar4 + uVar8;
          uVar7 = 0xff;
          uVar8 = uVar9;
        }
        thunk_EXT_FUN_8011000003a60ec0(lVar4,uVar9,uVar7,uVar8);
      }
      (**(code **)(*plVar5 + 0x28))(plVar5);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009aafa68);
        (*pcVar2)();
      }
      thunk_EXT_FUN_8011000002c20784(param_1,0);
      return;
    }
  }
  return;
}

