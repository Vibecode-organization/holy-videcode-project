// FUN_fffffff0099576f4 @ fffffff0099576f4 size=920

undefined8
FUN_fffffff0099576f4
          (long param_1,undefined8 param_2,ulong param_3,ulong param_4,undefined8 param_5,
          int param_6,long *param_7)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  long *plVar8;
  ulong uVar9;
  
  lVar3 = FUN_fffffff009957448();
  if (lVar3 == 0) {
    FUN_fffffff0099574e0
              (param_1,
               "IOReturn IOGPUResource::replace_backing_ranges(task_t, mach_vm_address_t, uint64_t, bool, bool, uint64_t *)"
              );
    return 0xe00002e2;
  }
  if (param_4 >> 0x20 != 0) {
    thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: overflow\n");
    return 0xe00002c2;
  }
  thunk_EXT_FUN_80110000032977b0(param_2);
  iVar2 = thunk_EXT_FUN_80110000032ed234();
  iVar1 = (int)*(long *)PTR_DAT_fffffff007ff2838;
  if (*(long *)PTR_DAT_fffffff007ff2838 != (long)iVar2) {
    iVar1 = iVar2;
  }
  uVar9 = (ulong)(iVar1 - 1U & (uint)param_3);
  plVar4 = (long *)thunk_EXT_FUN_8011000003976e84
                             (param_3 & -(long)iVar2,uVar9 + param_4 * 0x10,0,param_2);
  if (plVar4 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: failed to create descriptor\n");
    return 0xe00002bd;
  }
  plVar5 = (long *)(**(code **)(*plVar4 + 0xe8))(plVar4,0x1000);
  if (plVar5 == (long *)0x0) {
    uVar7 = 0xe00002bd;
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: failed to create mapping\n");
    goto LAB_fffffff009957a50;
  }
  lVar6 = (**(code **)(*plVar5 + 0x78))();
  FUN_fffffff009942d70(lVar3);
  uVar7 = FUN_fffffff009982544(lVar3,param_2,lVar6 + uVar9,param_4,param_5);
  if ((int)uVar7 == 0) {
    if (*(long **)(param_1 + 0x90) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x90) + 0x28))();
      *(undefined8 *)(param_1 + 0x90) = 0;
    }
    if (param_6 == 0) {
      *param_7 = 0;
    }
    else {
      uVar7 = FUN_fffffff009981d00(lVar3);
      plVar8 = (long *)thunk_EXT_FUN_801100000396cb64(uVar7,param_2,0,1,0,0);
      if (plVar8 == (long *)0x0) {
        uVar7 = 0xe00002bd;
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Failed to make client map\n");
        FUN_fffffff009943a94(lVar3);
        goto LAB_fffffff009957a2c;
      }
      lVar6 = (**(code **)(*plVar8 + 0x78))();
      if ((*(byte *)(param_1 + 0x10) & 0x7f) == 0) {
        uVar9 = *(ulong *)(param_1 + 0x48);
      }
      else if (*(byte *)(param_1 + 0x10) == 0x82) {
        uVar9 = (ulong)*(uint *)(param_1 + 0x4c);
      }
      else {
        uVar9 = 0;
      }
      *param_7 = uVar9 + lVar6;
      *(long **)(param_1 + 0x90) = plVar8;
    }
    FUN_fffffff009943a94(lVar3);
    uVar7 = 0;
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Failed to replace memory\n");
  }
LAB_fffffff009957a2c:
  FUN_fffffff009942d7c(lVar3);
  (**(code **)(*plVar5 + 0x28))(plVar5);
LAB_fffffff009957a50:
  (**(code **)(*plVar4 + 0x28))(plVar4);
  return uVar7;
}

