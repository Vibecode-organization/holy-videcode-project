// FUN_fffffff00a50b094 @ fffffff00a50b094 size=2228

undefined8 FUN_fffffff00a50b094(long param_1,long param_2,undefined4 *param_3)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  code *pcVar5;
  int iVar6;
  undefined8 uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  undefined4 *puVar12;
  byte *pbVar13;
  long lVar14;
  ulong uVar15;
  byte *pbVar16;
  undefined8 *puVar17;
  ulong uVar18;
  long lVar19;
  int in_wzr;
  long *plVar20;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  ulong local_240;
  long local_238;
  undefined8 local_230;
  undefined8 uStack_228;
  undefined8 local_220;
  undefined8 uStack_218;
  undefined8 local_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
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
  undefined8 local_88;
  undefined8 uStack_80;
  long local_78;
  
  local_78 = DAT_fffffff00ad30000;
  local_88 = 0;
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
  uStack_168 = 0;
  local_170 = 0;
  uStack_158 = 0;
  uStack_160 = 0;
  uStack_188 = 0;
  local_190 = 0;
  uStack_178 = 0;
  uStack_180 = 0;
  uStack_1a8 = 0;
  local_1b0 = 0;
  uStack_198 = 0;
  uStack_1a0 = 0;
  uStack_1c8 = 0;
  local_1d0 = 0;
  local_1b8 = 0;
  uStack_1c0 = 0;
  uStack_1e8 = 0;
  local_1f0 = 0;
  uStack_1d8 = 0;
  uStack_1e0 = 0;
  uStack_208 = 0;
  local_210 = 0;
  uStack_1f8 = 0;
  uStack_200 = 0;
  uStack_218 = 0;
  local_220 = 0;
  if ((*(long *)(param_2 + 0x10) == 0) || (*(long *)(param_2 + 0x18) != 0x10)) {
    uVar15 = 0;
    uVar7 = 0x16;
    uVar18 = 0x768;
LAB_fffffff00a50b184:
    *param_3 = (int)uVar7;
    FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,"%s: Request nexus error (%d)\n");
  }
  else {
    lVar19 = *(long *)(param_2 + 0x28);
    uVar7 = FUN_fffffff00a389b14(*(long *)(param_2 + 0x10),&local_88,0x10);
    if ((int)uVar7 != 0) {
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,
                 "%s: necp_client_request_nexus copyin client_id error (%d)\n");
      uVar15 = 0;
      uVar18 = 0x768;
      goto LAB_fffffff00a50b184;
    }
    lVar4 = tpidr_el1;
    if (*(ulong *)(param_1 + 0x58) == 0) {
      *(ulong *)(param_1 + 0x58) = (ulong)*(uint *)(lVar4 + 0x4e8);
    }
    else {
      FUN_fffffff00a2262d4(param_1 + 0x50,lVar4,0);
    }
    uVar2 = *(undefined4 *)(param_1 + 0x4c);
    uVar15 = FUN_fffffff00a72456c(uVar2);
    uVar18 = uVar15 + 0x768;
    if (uVar15 == 0) {
      if (*(int *)(param_1 + 0x58) == *(int *)(lVar4 + 0x4e8)) {
        *(int *)(param_1 + 0x58) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(param_1 + 0x50,lVar4);
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,
                 "%s: necp_client_request_nexus process not found for pid %d error (%d)\n");
      uVar15 = 0;
      uVar7 = 3;
      goto LAB_fffffff00a50b184;
    }
    uVar8 = FUN_fffffff00a4fcfe0(param_1,&local_88);
    if (uVar8 == 0) {
      iVar6 = *(int *)(param_1 + 0x58);
      if (iVar6 == *(int *)(lVar4 + 0x4e8)) {
        *(int *)(param_1 + 0x58) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(param_1 + 0x50,lVar4,iVar6);
      }
      uVar7 = 2;
      goto LAB_fffffff00a50b184;
    }
    if (*(ulong *)(uVar8 + 0x38) == 0) {
      *(ulong *)(uVar8 + 0x38) = (ulong)*(uint *)(lVar4 + 0x4e8);
    }
    else {
      FUN_fffffff00a2262d4(uVar8 + 0x30,lVar4,0);
    }
    pbVar16 = (byte *)(uVar8 + 100);
    *pbVar16 = *pbVar16 | 8;
    if (uVar8 + 0x5b0 <= uVar8) goto LAB_fffffff00a50b7dc;
    iVar6 = *(int *)(uVar8 + 0x50);
    *(int *)(uVar8 + 0x50) = iVar6 + 1;
    if (iVar6 + 0xf0000001U < 0xf0000002) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa61ed0();
    }
    FUN_fffffff00a50f150(uVar8,&local_220);
    local_240 = 0;
    local_238 = 0;
    local_230 = 0;
    uStack_228 = 0;
    if (*(char *)(uVar8 + 0x538) == '\0') {
LAB_fffffff00a50b758:
      if (*(int *)(uVar8 + 0x38) == *(int *)(lVar4 + 0x4e8)) {
        *(int *)(uVar8 + 0x38) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(uVar8 + 0x30,lVar4);
      }
      if (*(int *)(param_1 + 0x58) == *(int *)(lVar4 + 0x4e8)) {
        *(int *)(param_1 + 0x58) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(param_1 + 0x50,lVar4);
      }
      if (*(ulong *)(uVar8 + 0x38) == 0) {
        *(ulong *)(uVar8 + 0x38) = (ulong)*(uint *)(lVar4 + 0x4e8);
      }
      else {
        FUN_fffffff00a2262d4(uVar8 + 0x30,lVar4,0);
      }
      uVar9 = FUN_fffffff00a5049b0(uVar8);
      if ((uVar9 & 1) == 0) {
        iVar6 = *(int *)(uVar8 + 0x38);
        if (iVar6 == *(int *)(lVar4 + 0x4e8)) {
          *(int *)(uVar8 + 0x38) = in_wzr;
        }
        else {
          FUN_fffffff00a226e08(uVar8 + 0x30,lVar4,iVar6);
        }
        uVar7 = 0x32;
      }
      else {
        uVar7 = 0x32;
      }
      goto LAB_fffffff00a50b184;
    }
    puVar17 = (undefined8 *)(uVar8 + 0x4d0);
    iVar6 = FUN_fffffff00a3542b4(puVar17,&DAT_fffffff007029084,0x10);
    if (iVar6 == 0) {
      if (1 < *(byte *)(uVar8 + 0x538)) {
        puVar17 = (undefined8 *)(uVar8 + 0x4e8);
        iVar6 = FUN_fffffff00a3542b4(puVar17,&DAT_fffffff007029084,0x10);
        if (iVar6 != 0) {
          puVar12 = (undefined4 *)(uVar8 + 0x4e0);
          goto LAB_fffffff00a50b2d0;
        }
        if (2 < *(byte *)(uVar8 + 0x538)) {
          puVar17 = (undefined8 *)(uVar8 + 0x500);
          iVar6 = FUN_fffffff00a3542b4(puVar17,&DAT_fffffff007029084,0x10);
          if (iVar6 != 0) {
            puVar12 = (undefined4 *)(uVar8 + 0x4f8);
            goto LAB_fffffff00a50b2d0;
          }
          if (3 < *(byte *)(uVar8 + 0x538)) {
            puVar17 = (undefined8 *)(uVar8 + 0x518);
            iVar6 = FUN_fffffff00a3542b4(puVar17,&DAT_fffffff007029084,0x10);
            if (iVar6 != 0) {
              puVar12 = (undefined4 *)(uVar8 + 0x510);
              goto LAB_fffffff00a50b2d0;
            }
            if (4 < *(byte *)(uVar8 + 0x538)) {
              lVar14 = 0;
              uVar9 = 4;
              do {
                uVar10 = *(ulong *)(uVar8 + 0x528);
                uVar11 = uVar10 + lVar14;
                if (*(ulong *)(uVar8 + 0x530) < uVar11 + 0x18 || uVar11 < uVar10)
                goto LAB_fffffff00a50b7dc;
                iVar6 = FUN_fffffff00a3542b4(uVar11 + 8,&DAT_fffffff007029084,0x10);
                if (iVar6 != 0) {
                  puVar12 = (undefined4 *)(uVar10 + lVar14);
                  puVar17 = (undefined8 *)(puVar12 + 2);
                  goto LAB_fffffff00a50b2d0;
                }
                uVar9 = uVar9 + 1;
                lVar14 = lVar14 + 0x18;
              } while (uVar9 < *(byte *)(uVar8 + 0x538));
            }
          }
        }
      }
      goto LAB_fffffff00a50b758;
    }
    puVar12 = (undefined4 *)(uVar8 + 0x4c8);
LAB_fffffff00a50b2d0:
    uStack_228 = puVar17[1];
    local_230 = *puVar17;
    if (*(int *)(uVar8 + 0x480) != 0) {
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,
                 "%s: <pid %d> Disallow request nexus with flow divert result\n");
      if (*(int *)(uVar8 + 0x38) == *(int *)(lVar4 + 0x4e8)) {
        *(int *)(uVar8 + 0x38) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(uVar8 + 0x30,lVar4);
      }
      if (*(int *)(param_1 + 0x58) == *(int *)(lVar4 + 0x4e8)) {
        *(int *)(param_1 + 0x58) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(param_1 + 0x50,lVar4);
      }
      FUN_fffffff00a50f57c(uVar8);
      uVar7 = 1;
      goto LAB_fffffff00a50b184;
    }
    uVar3 = *puVar12;
    uVar9 = FUN_fffffff00a4fd0fc(param_1,uVar8);
    pbVar13 = (byte *)(uVar9 + 0x6c);
    pbVar13[0] = 3;
    pbVar13[1] = 0;
    pbVar13[2] = 0;
    pbVar13[3] = 0;
    if (uVar9 + 200 <= uVar9) goto LAB_fffffff00a50b7dc;
    FUN_fffffff00a50f608(uVar9,&local_230,uVar3,(ushort)local_1b8 >> 9 & 1);
    pbVar1 = (byte *)(uVar9 + 0x5c);
    if ((*(uint *)(uVar9 + 0x6c) & 2) != 0) {
      pbVar1 = (byte *)(uVar8 + 0x54);
      pbVar13 = pbVar16;
    }
    if ((pbVar13 < pbVar1) || ((ulong)((long)pbVar13 - (long)pbVar1) < 0x10))
    goto LAB_fffffff00a50b7dc;
    plVar20 = &local_238;
    uVar7 = FUN_fffffff00a522d8c
                      (&local_230,pbVar1,uVar2,*(undefined8 *)(uVar8 + 0x550),10,
                       *(byte *)(uVar8 + 100) >> 6 & 1,&local_220,&local_240,plVar20);
    if ((int)uVar7 != 0) {
      if (*(int *)(uVar8 + 0x38) == *(int *)(lVar4 + 0x4e8)) {
        *(int *)(uVar8 + 0x38) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(uVar8 + 0x30,lVar4);
      }
      if (*(int *)(param_1 + 0x58) == *(int *)(lVar4 + 0x4e8)) {
        *(int *)(param_1 + 0x58) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(param_1 + 0x50,lVar4);
      }
      FUN_fffffff00a50f57c(uVar8);
      if (local_240 != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa5d948
                  ("assigned_results == NULL",
                   "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/net/necp_client.c"
                   ,0x2b11);
      }
      if (local_238 != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa5d948
                  ("assigned_results_length == 0",
                   "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/net/necp_client.c"
                   ,0x2b12);
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,"%s: netagent_client_message error (%d)\n");
      goto LAB_fffffff00a50b184;
    }
    if (local_240 != 0) {
      uVar11 = local_240 + local_238;
      if (((local_240 ^ uVar11) & 0xffc0000000000000) != 0) {
        uVar11 = uVar11 & 0xffffffffffff | 0xc8a2000000000000;
      }
      uVar10 = FUN_fffffff00a5030ec
                         (uVar15,param_1,uVar8,uVar9,&local_230,local_240,uVar11,local_238,
                          (ulong)plVar20 & 0xffffffffffff0000);
      lVar14 = local_238;
      uVar11 = local_240;
      if ((uVar10 & 1) == 0) {
        local_240 = 0;
        local_238 = 0;
        FUN_fffffff00a2212a8(&DAT_fffffff007c6afb0,uVar11,lVar14);
      }
    }
    if (((*(long *)(param_2 + 0x20) != 0) && (lVar19 == 0x18)) &&
       (iVar6 = FUN_fffffff00a50f7d0(param_1), iVar6 == 0)) {
      local_258 = 0;
      uStack_250 = 0;
      local_248 = 0;
      iVar6 = FUN_fffffff00a389b14(*(undefined8 *)(param_2 + 0x20),&local_258,0x18);
      if (iVar6 == 0) {
        FUN_fffffff00a50fae0(param_1,uVar8,uVar9,&local_258);
        iVar6 = FUN_fffffff00a38a690(&local_258,*(undefined8 *)(param_2 + 0x20),0x18);
        if (iVar6 != 0) {
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,
                     "%s: necp_client_request_nexus copyout bufreq error (%d)\n");
        }
      }
      else {
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,
                   "%s: necp_client_request_nexus copyin bufreq error (%d)\n");
      }
    }
    if (*(int *)(uVar8 + 0x38) == *(int *)(lVar4 + 0x4e8)) {
      *(int *)(uVar8 + 0x38) = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(uVar8 + 0x30,lVar4);
    }
    if (*(int *)(param_1 + 0x58) == *(int *)(lVar4 + 0x4e8)) {
      *(int *)(param_1 + 0x58) = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(param_1 + 0x50,lVar4);
    }
    if (*(ulong *)(uVar8 + 0x38) == 0) {
      *(ulong *)(uVar8 + 0x38) = (ulong)*(uint *)(lVar4 + 0x4e8);
    }
    else {
      FUN_fffffff00a2262d4(uVar8 + 0x30,lVar4,0);
    }
    uVar9 = FUN_fffffff00a5049b0(uVar8);
    if ((uVar9 & 1) == 0) {
      if (*(int *)(uVar8 + 0x38) == *(int *)(lVar4 + 0x4e8)) {
        *(int *)(uVar8 + 0x38) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(uVar8 + 0x30,lVar4);
      }
    }
    uVar7 = 0;
    *param_3 = 0;
  }
  if (uVar15 != 0) {
    if (uVar18 <= uVar15) {
LAB_fffffff00a50b7dc:
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a50b7e0);
      (*pcVar5)();
    }
    FUN_fffffff00a724838(uVar15);
  }
  if (DAT_fffffff00ad30000 == local_78) {
    return uVar7;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590();
}

