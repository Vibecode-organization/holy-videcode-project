// FUN_fffffff00996ed24 @ fffffff00996ed24 size=300

void FUN_fffffff00996ed24(long param_1)

{
  long *plVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  if (*(int *)(param_1 + 0x38) == 1) {
    uVar3 = *(undefined8 *)(param_1 + 0x20);
    plVar1 = *(long **)(param_1 + 0x28);
    if (plVar1 != (long *)0x0) {
      (**(code **)(*plVar1 + 0x20))(plVar1);
    }
    iVar2 = FUN_fffffff009957f50
                      (uVar3,plVar1,*(undefined8 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x3c),
                       0);
    if (iVar2 != 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Copy Mappings Failed(0x%x)\n");
    }
  }
  else {
    if (*(int *)(param_1 + 0x38) != 0) {
      uVar3 = FUN_fffffff009983fa4();
      puVar4 = (undefined8 *)
               thunk_EXT_FUN_8011000003890d88
                         (uVar3,"IOGPUMappingCommandDescriptor",&DAT_fffffff00af22650,0x180);
      *puVar4 = &DAT_fffffff007fedb40;
      return;
    }
    plVar1 = *(long **)(param_1 + 0x20);
    uVar3 = *(undefined8 *)(param_1 + 0x28);
    if (plVar1 != (long *)0x0) {
      (**(code **)(*plVar1 + 0x20))(plVar1);
    }
    iVar2 = FUN_fffffff009957a8c
                      (uVar3,plVar1,*(undefined8 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x3c),
                       0);
    if (iVar2 != 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Update Mappings Failed(0x%x)\n");
    }
  }
  return;
}

