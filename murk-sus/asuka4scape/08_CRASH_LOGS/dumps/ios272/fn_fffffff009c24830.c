// FUN_fffffff009c24830 @ fffffff009c24830 size=620

/* WARNING: Removing unreachable block (ram,0xfffffff009c24a14) */

void FUN_fffffff009c24830(long param_1)

{
  undefined *puVar1;
  code *pcVar2;
  long *plVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  ulong unaff_x30;
  
  plVar3 = *(long **)(param_1 + 0x1a8);
  if (plVar3 == (long *)0x0) {
    plVar3 = (long *)0x0;
  }
  else {
    plVar3 = (long *)(**(code **)(*plVar3 + 0x138))(plVar3,"IOSurfaceName");
    if (plVar3 != (long *)0x0) {
      (**(code **)(*plVar3 + 0x20))(plVar3);
    }
  }
  uVar4 = thunk_EXT_FUN_801100000389d0d8(4);
  if (*(long **)(param_1 + 0x1a8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1a8) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x1a8) = uVar4;
  puVar1 = PTR_DAT_fffffff00806ca10;
  if ((plVar3 != (long *)0x0) &&
     (lVar5 = thunk_EXT_FUN_8011000003890f30(plVar3,*(undefined8 *)PTR_DAT_fffffff00806ca10),
     lVar5 != 0)) {
    (**(code **)(**(long **)(param_1 + 0x1a8) + 0x100))
              (*(long **)(param_1 + 0x1a8),"IOSurfaceName",plVar3);
  }
  if (*(long *)(param_1 + 0x268) != 0) {
    (**(code **)(**(long **)(param_1 + 0x1a8) + 0x100))
              (*(long **)(param_1 + 0x1a8),"CreationProperties");
    uVar4 = *(undefined8 *)puVar1;
    if ((plVar3 == (long *)0x0) ||
       (lVar5 = thunk_EXT_FUN_8011000003890f30(plVar3,uVar4), lVar5 == 0)) {
      uVar6 = (**(code **)(**(long **)(param_1 + 0x268) + 0x138))
                        (*(long **)(param_1 + 0x268),"IOSurfaceName");
      lVar5 = thunk_EXT_FUN_8011000003890f30(uVar6,uVar4);
      if (lVar5 != 0) {
        (**(code **)(**(long **)(param_1 + 0x1a8) + 0x100))
                  (*(long **)(param_1 + 0x1a8),"IOSurfaceName",lVar5);
      }
    }
  }
  lVar5 = *(long *)(param_1 + 0x178);
  *(undefined4 *)(lVar5 + 0xb4) = 0;
  *(undefined8 *)(lVar5 + 0xac) = 0;
  *(undefined8 *)(lVar5 + 0xa4) = 0;
  *(undefined8 *)(lVar5 + 0x9c) = 0;
  *(undefined8 *)(lVar5 + 0x94) = 0;
  *(undefined8 *)(lVar5 + 0x8c) = 0;
  *(undefined8 *)(lVar5 + 0x84) = 0;
  *(undefined8 *)(lVar5 + 0x7c) = 0;
  *(undefined8 *)(lVar5 + 0x74) = 0;
  *(undefined8 *)(lVar5 + 0x6c) = 0;
  *(undefined8 *)(lVar5 + 100) = 0;
  *(undefined8 *)(lVar5 + 0x5c) = 0;
  *(undefined8 *)(lVar5 + 0x54) = 0;
  *(undefined8 *)(lVar5 + 0x4c) = 0;
  *(undefined8 *)(lVar5 + 0x44) = 0;
  *(undefined8 *)(lVar5 + 0x3c) = 0;
  *(undefined8 *)(lVar5 + 0x34) = 0;
  if (plVar3 != (long *)0x0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c24a88. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*plVar3 + 0x28))(plVar3,(undefined8 *)(*plVar3 + 0x28));
      return;
    }
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c24a80);
    (*pcVar2)();
  }
  return;
}

