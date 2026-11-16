// FUN_fffffff009c33548 @ fffffff009c33548 size=840

/* WARNING: Removing unreachable block (ram,0xfffffff009c33774) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c33634) */

long FUN_fffffff009c33548(long param_1,ulong param_2,long param_3,long param_4)

{
  uint uVar1;
  undefined *puVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar4 = (uint)param_2;
  if ((uVar4 == 0) || (*(uint *)(param_1 + 0xd8) <= uVar4)) goto LAB_fffffff009c33674;
  uVar5 = *(ulong *)(param_1 + 0xd0);
  uVar6 = uVar5 + (ulong)*(uint *)(param_1 + 0xd8) * 8;
  if (((uVar5 ^ uVar6) & 0xffc0000000000000) != 0) {
    uVar6 = uVar6 & 0xffffffffffff | 0xc8a2000000000000;
  }
  if ((uVar6 < uVar5) || (uVar6 - uVar5 >> 0x20 != 0)) {
    FUN_fffffff009c48f64();
  }
  else {
    lVar8 = (param_2 & 0xffffffff) * 8;
    if (lVar8 - (int)lVar8 == 0) {
      if (((param_2 & 0x1fffffff) >> 0x1c != 0) ||
         (uVar1 = uVar4 * 8, (uint)(uVar6 - uVar5) < uVar1 + 8)) goto LAB_fffffff009c33860;
      uVar7 = (ulong)CARRY8(uVar5,(ulong)uVar1);
      uVar6 = -uVar7;
      if ((uVar6 != uVar7) || ((long)uVar6 < 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f50();
      }
      lVar8 = *(long *)(uVar5 + uVar1);
      if (lVar8 != 0) {
        if (*(uint *)(lVar8 + 0x10) != uVar4) {
          lVar8 = thunk_EXT_FUN_8011000003a49114
                            (
                            "\"IOSurface in slot %08x has a mismatched surface ID of %08x\\n\" @%s:%d"
                            );
          return lVar8;
        }
        if ((param_3 == *(long *)(lVar8 + 0x170)) ||
           ((param_4 != 0 && (uVar6 = FUN_fffffff009c3f668(param_4,lVar8), (uVar6 & 1) != 0))))
        goto LAB_fffffff009c336a0;
        if ((*(uint *)(lVar8 + 0x3d0) >> 0x13 & 1) == 0) {
          if ((*(uint *)(lVar8 + 0x3d0) >> 1 & 1) == 0) {
            if ((*(uint *)(param_1 + 0x1a4) >> 2 & 1) != 0) {
LAB_fffffff009c3377c:
              lVar3 = thunk_EXT_FUN_80110000032970b4(param_3);
              if (lVar3 != 0) {
                uStack_68 = 0;
                local_70 = 0;
                uStack_58 = 0;
                uStack_60 = 0;
                uStack_88 = 0;
                local_90 = 0;
                uStack_78 = 0;
                uStack_80 = 0;
                uStack_a8 = 0;
                local_b0 = 0;
                uStack_98 = 0;
                uStack_a0 = 0;
                uStack_c8 = 0;
                local_d0 = 0;
                uStack_b8 = 0;
                uStack_c0 = 0;
                uStack_e8 = 0;
                local_f0 = 0;
                uStack_d8 = 0;
                uStack_e0 = 0;
                uStack_108 = 0;
                local_110 = 0;
                uStack_f8 = 0;
                uStack_100 = 0;
                uStack_128 = 0;
                local_130 = 0;
                uStack_118 = 0;
                uStack_120 = 0;
                uStack_148 = 0;
                local_150 = 0;
                uStack_138 = 0;
                uStack_140 = 0;
                thunk_EXT_FUN_8011000003722ec0(&local_150,0x100);
                puVar2 = PTR_DAT_fffffff00806ca48;
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"_   /|\n");
                thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar2,0x10,"\'o.O\'\n");
                thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar2,0x10,"=(___)=\n");
                thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar2,0x10,"   U     ack!\n");
                thunk_EXT_FUN_8011000003720f30(lVar3);
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,puVar2,0x10,
                           "Security: Process %s (%d) relying on global (insecure) IOSurface lookups\n"
                          );
              }
              goto LAB_fffffff009c336a0;
            }
          }
          else {
            if ((*(uint *)(param_1 + 0x1a4) >> 2 & 1) != 0) goto LAB_fffffff009c3377c;
            lVar8 = thunk_EXT_FUN_80110000032970b4(param_3);
            if (lVar8 != 0) {
              uStack_68 = 0;
              local_70 = 0;
              uStack_58 = 0;
              uStack_60 = 0;
              uStack_88 = 0;
              local_90 = 0;
              uStack_78 = 0;
              uStack_80 = 0;
              uStack_a8 = 0;
              local_b0 = 0;
              uStack_98 = 0;
              uStack_a0 = 0;
              uStack_c8 = 0;
              local_d0 = 0;
              uStack_b8 = 0;
              uStack_c0 = 0;
              uStack_e8 = 0;
              local_f0 = 0;
              uStack_d8 = 0;
              uStack_e0 = 0;
              uStack_108 = 0;
              local_110 = 0;
              uStack_f8 = 0;
              uStack_100 = 0;
              uStack_128 = 0;
              local_130 = 0;
              uStack_118 = 0;
              uStack_120 = 0;
              uStack_148 = 0;
              local_150 = 0;
              uStack_138 = 0;
              uStack_140 = 0;
              thunk_EXT_FUN_8011000003722ec0(&local_150,0x100);
              thunk_EXT_FUN_8011000003720f30(lVar8);
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                         "Security: Process %s (%d) failed global (insecure) IOSurface lookup for surface id %08x\n"
                        );
            }
          }
        }
      }
LAB_fffffff009c33674:
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "SID: 0x%X task: %p buffer: %p  buffer->fClientTask = %p not found\n");
      lVar8 = 0;
LAB_fffffff009c336a0:
      if (*(long *)PTR_DAT_fffffff00806ca40 == local_48) {
        return lVar8;
      }
      lVar8 = thunk_EXT_FUN_8011000003a48590();
      return lVar8;
    }
  }
  FUN_fffffff009c48f3c();
LAB_fffffff009c33860:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48f28();
}

