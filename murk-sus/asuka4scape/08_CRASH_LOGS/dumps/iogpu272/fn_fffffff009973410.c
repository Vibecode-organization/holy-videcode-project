// FUN_fffffff009973410 @ fffffff009973410 size=1784

/* WARNING: Removing unreachable block (ram,0xfffffff009973820) */
/* WARNING: Removing unreachable block (ram,0xfffffff0099737e0) */

void FUN_fffffff009973410(long param_1,long param_2,long param_3)

{
  char *pcVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  ulong uVar11;
  long lVar12;
  long *plVar13;
  long *plVar14;
  long *plVar15;
  long *plVar16;
  long *plVar17;
  long *local_178;
  long *plStack_170;
  long *local_168;
  long *plStack_160;
  long *local_158;
  long *plStack_150;
  long *local_148;
  long *plStack_140;
  long *local_138;
  long *plStack_130;
  long *local_128;
  long *plStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined4 local_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  long local_78;
  
  local_78 = *(long *)PTR_DAT_fffffff007ff2800;
  uStack_98 = 0;
  local_a0 = 0;
  uStack_88 = 0;
  uStack_90 = 0;
  uStack_b8 = 0;
  local_c0 = 0;
  uStack_a8 = 0;
  uStack_b0 = 0;
  uStack_d8 = 0;
  local_e0 = 0;
  uStack_c8 = 0;
  uStack_d0 = 0;
  uStack_e8 = 0;
  local_f0 = 0;
  uStack_f8 = 0;
  local_100 = 0;
  if (param_2 != 0) {
    thunk_EXT_FUN_8011000003722d80(*(undefined4 *)(param_2 + 0x490),&local_100,0x80);
  }
  if (*(long **)(param_1 + 0x140) == (long *)0x0) {
    pcVar1 = "Undefined";
  }
  else {
    pcVar1 = (char *)(**(code **)(**(long **)(param_1 + 0x140) + 0xa8))();
  }
  plVar2 = (long *)thunk_EXT_FUN_80110000038ce200(pcVar1);
  plVar3 = (long *)thunk_EXT_FUN_80110000038ce200("Application");
  plVar4 = (long *)thunk_EXT_FUN_80110000038ce200("AppPath");
  plVar5 = (long *)thunk_EXT_FUN_80110000038ce200("Graphics");
  plVar6 = (long *)thunk_EXT_FUN_80110000038ce200("Report");
  plVar7 = (long *)thunk_EXT_FUN_80110000038ce200("Signature");
  plVar8 = (long *)thunk_EXT_FUN_80110000038ce200("GPUSubmissionTraceID");
  plVar9 = (long *)thunk_EXT_FUN_80110000038ce200(&local_100);
  pcVar1 = "";
  if (param_2 != 0) {
    pcVar1 = (char *)(param_2 + 0x10);
  }
  plVar10 = (long *)thunk_EXT_FUN_80110000038ce200(pcVar1);
  if (param_3 == 0) {
LAB_fffffff0099735ec:
    plVar13 = (long *)thunk_EXT_FUN_80110000038ce200("Vendor failed to provide GPURestartReport");
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Vendor failed to provide GPURestarrReport\n");
  }
  else {
    uVar11 = thunk_EXT_FUN_80110000031cd550(param_3);
    if (uVar11 < 0xffff) {
      if (uVar11 == 0) goto LAB_fffffff0099735ec;
      plVar13 = (long *)thunk_EXT_FUN_80110000038ce200(param_3);
    }
    else {
      lVar12 = thunk_EXT_FUN_80110000038fe580(0xffff);
      if (lVar12 == 0) {
        plVar13 = (long *)thunk_EXT_FUN_80110000038ce200
                                    (
                                    "Failed to reallocate/truncate vendor\'s (too-long) GPURestartReport"
                                    );
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: Failed to realloc/truncate vendor\'s (too-long) GPURestartReport from %ld to %d\n"
                  );
      }
      else {
        thunk_EXT_FUN_8011000003350958(lVar12,param_3,0xffff);
        plVar13 = (long *)thunk_EXT_FUN_80110000038ce200(lVar12);
        thunk_EXT_FUN_80110000038fe6b0(lVar12,0xffff);
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: Truncated vendor\'s (too-long) GPURestartReport from %ld to %d\n");
      }
    }
  }
  local_118 = 0;
  uStack_110 = 0;
  local_108 = 0;
  thunk_EXT_FUN_80110000037693ec(&local_118,0x14,"%x");
  plVar14 = (long *)thunk_EXT_FUN_80110000038ce200(&local_118);
  thunk_EXT_FUN_80110000037693ec(&local_118,0x14,"%llx");
  plVar15 = (long *)thunk_EXT_FUN_80110000038ce200(&local_118);
  if (((((plVar3 == (long *)0x0) || (plVar6 == (long *)0x0)) || (plVar4 == (long *)0x0)) ||
      ((((plVar5 == (long *)0x0 || (plVar7 == (long *)0x0)) ||
        ((plVar8 == (long *)0x0 || ((plVar9 == (long *)0x0 || (plVar13 == (long *)0x0)))))) ||
       (plVar10 == (long *)0x0)))) ||
     (((plVar2 == (long *)0x0 || (plVar14 == (long *)0x0)) || (plVar15 == (long *)0x0)))) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Can\'t allocate GPURestartReport keys/objects.  Skipping...\n");
    if (plVar15 == (long *)0x0) goto joined_r0xfffffff009973894;
  }
  else {
    local_178 = plVar9;
    plStack_170 = plVar10;
    local_168 = plVar2;
    plStack_160 = plVar13;
    local_158 = plVar14;
    plStack_150 = plVar15;
    local_148 = plVar3;
    plStack_140 = plVar4;
    local_138 = plVar5;
    plStack_130 = plVar6;
    local_128 = plVar7;
    plStack_120 = plVar8;
    plVar16 = (long *)thunk_EXT_FUN_801100000389d238(&local_178,&local_148,6,6);
    if (plVar16 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Can\'t allocate GPURestartReport dictionary.  Skipping....\n");
    }
    else {
      plVar17 = (long *)(**(code **)(*DAT_fffffff007feb440 + 0x68))();
      if (plVar17 == (long *)0x0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: Can\'t allocate GPURestartReport nub.  Skipping...\n");
      }
      else {
        (**(code **)(*plVar17 + 0xa8))(plVar17,plVar16);
        (**(code **)(*plVar17 + 0x210))(plVar17,"GPURestartReport",0);
        (**(code **)(*plVar17 + 0x360))(*plVar17 + 0x360,plVar17,param_1);
        (**(code **)(*plVar17 + 0x2a0))(*plVar17 + 0x2a0,plVar17,0);
        (**(code **)(*plVar17 + 0x28))(plVar17);
      }
      (**(code **)(*plVar16 + 0x28))(plVar16);
    }
  }
  (**(code **)(*plVar15 + 0x28))(plVar15);
joined_r0xfffffff009973894:
  if (plVar14 != (long *)0x0) {
    (**(code **)(*plVar14 + 0x28))(plVar14);
  }
  if (plVar13 != (long *)0x0) {
    (**(code **)(*plVar13 + 0x28))(plVar13);
  }
  if (plVar10 != (long *)0x0) {
    (**(code **)(*plVar10 + 0x28))(plVar10);
  }
  if (plVar9 != (long *)0x0) {
    (**(code **)(*plVar9 + 0x28))(plVar9);
  }
  if (plVar8 != (long *)0x0) {
    (**(code **)(*plVar8 + 0x28))(plVar8);
  }
  if (plVar7 != (long *)0x0) {
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))();
  }
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))();
  }
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  if (*(long *)PTR_DAT_fffffff007ff2800 == local_78) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

