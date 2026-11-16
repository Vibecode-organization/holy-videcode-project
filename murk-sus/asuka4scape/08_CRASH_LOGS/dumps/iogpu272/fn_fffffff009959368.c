// FUN_fffffff009959368 @ fffffff009959368 size=904

void FUN_fffffff009959368(long *param_1)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  long *plVar5;
  ulong uVar6;
  uint *puVar7;
  ulong uVar8;
  undefined8 uVar9;
  ulong unaff_x30;
  
  plVar5 = (long *)FUN_fffffff009965b58(*(undefined8 *)(param_1[10] + 0x78));
  if (plVar5 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid command list shmem ID\n");
    *(undefined1 *)((long)param_1 + 0x5c) = 1;
    return;
  }
  FUN_fffffff009952120();
  uVar6 = (**(code **)(*plVar5 + 0x98))(plVar5);
  if ((long)uVar6 < 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: command list length less than zero\n"
              );
  }
  else {
    puVar7 = (uint *)(**(code **)(*plVar5 + 0x80))(plVar5);
    if (7 < uVar6 && puVar7 != (uint *)0x0) {
      uVar9 = *(undefined8 *)(param_1[10] + 0x30);
      thunk_EXT_FUN_80110000036da494(0x850900fd,uVar9,param_1[7],0,0,0);
      uVar2 = *puVar7;
      uVar3 = puVar7[1];
      if (uVar3 < uVar2 || uVar6 < uVar3) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: Invalid command list header, commands_start=%u commands_end=%u cmdListShmemLength=%ld\n"
                  );
LAB_fffffff009959578:
        *(undefined1 *)((long)param_1 + 0x5c) = 1;
      }
      else {
        uVar6 = (long)puVar7 + (ulong)uVar3;
        if (uVar2 < uVar3) {
          uVar8 = (long)puVar7 + (ulong)uVar2;
          do {
            if ((*(byte *)((long)param_1 + 0x5c) & 1) != 0) break;
            if (uVar6 < uVar8 + 8) {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                         "%s: Insufficient bytes (%lu) to hold sIOGPUIOKernelCommand (%lu)\n");
              goto LAB_fffffff009959578;
            }
            uVar2 = *(uint *)(uVar8 + 4);
            uVar1 = uVar8 + uVar2;
            if ((CARRY8(uVar8,(ulong)uVar2)) || ((uVar2 < 8 || uVar6 < uVar1) || (uVar2 & 3) != 0))
            {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                         "%s: Invalid command_size (%u) min=%lu currentCommand=%p kernelCommandEnd=%p\n"
                        );
              goto LAB_fffffff009959578;
            }
            (**(code **)(*param_1 + 0x88))(param_1,uVar8,uVar1);
            uVar8 = uVar1;
          } while (uVar1 < uVar6);
        }
      }
      (**(code **)(*plVar5 + 0x88))(plVar5);
      FUN_fffffff00995212c(plVar5);
      (**(code **)(*plVar5 + 0x28))(plVar5);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099595fc);
        (*pcVar4)();
      }
      thunk_EXT_FUN_80110000036da494
                (0x850900fe,uVar9,param_1[7],*(byte *)((long)param_1 + 0x5c) & 1,0,0);
      return;
    }
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: command list length less insufficient (%zd)\n");
  }
  *(undefined1 *)((long)param_1 + 0x5c) = 1;
  FUN_fffffff00995212c(plVar5);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099594f8);
    (*pcVar4)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009959500. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar5 + 0x28))(plVar5,(undefined8 *)(*plVar5 + 0x28));
  return;
}

