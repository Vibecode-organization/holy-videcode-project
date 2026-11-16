// FUN_fffffff00819ea90 @ fffffff00819ea90 size=336

/* WARNING: Removing unreachable block (ram,0xfffffff00819eb58) */

void FUN_fffffff00819ea90(long param_1)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  ulong unaff_x30;
  undefined8 local_48;
  
  lVar6 = *(long *)(*(long *)(param_1 + 0x120) + 0x88);
  if (lVar6 != 0) {
    thunk_EXT_FUN_801100000294063c(lVar6);
    uVar1 = *(uint *)(lVar6 + 0x28);
    if (1 < uVar1) {
      uVar7 = 1;
      do {
        lVar3 = thunk_EXT_FUN_8011000002941214(lVar6,uVar7);
        if ((((lVar3 != 0) &&
             (uVar4 = thunk_EXT_FUN_80110000029474ec
                                (*(undefined8 *)(*(long *)(lVar3 + 0x530) + 0x148),lVar3 + 0x498),
             (uVar4 & 1) == 0)) && (*(long *)(lVar3 + 0x928) != 0)) &&
           (*(int *)(lVar3 + 0x920) != 0)) {
          local_48 = 0;
          thunk_EXT_FUN_8011000003204ed8(*(int *)(lVar3 + 0x920),1000000,&local_48);
          lVar5 = **(long **)(lVar3 + 0x928);
          (**(code **)(lVar5 + 0x130))(lVar5 + 0x130,*(long **)(lVar3 + 0x928),local_48);
          (**(code **)(**(long **)(lVar3 + 0x928) + 0xb0))();
        }
        uVar7 = uVar7 + 1;
      } while (uVar1 != uVar7);
    }
    thunk_EXT_FUN_8011000002940648(lVar6);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00819ebdc. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(PTR_DAT_fffffff007ca6150 + 0x578))(param_1,PTR_DAT_fffffff007ca6150 + 0x578);
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00819ebd4);
  (*pcVar2)();
}

