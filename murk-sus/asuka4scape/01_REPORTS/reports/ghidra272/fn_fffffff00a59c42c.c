// FUN_fffffff00a59c42c @ fffffff00a59c42c size=764

void FUN_fffffff00a59c42c(long param_1)

{
  ulong *puVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  undefined8 *puVar6;
  long lVar7;
  long *plVar8;
  long lVar9;
  int in_wzr;
  long *local_c0;
  ushort local_b2;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_68;
  
  local_68 = DAT_fffffff00ad30000;
  local_b2 = 0;
  local_c0 = (long *)0x0;
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa5d948
              ("ifp != NULL",
               "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/netinet/in.c"
               ,0x7e1);
  }
  iVar5 = FUN_fffffff00a4bfd34(param_1,&local_c0,&local_b2,2,1,0,0);
  plVar8 = local_c0;
  if ((iVar5 == 0) && (local_c0 != (long *)0x0)) {
    uStack_88 = 0;
    local_90 = 0;
    uStack_78 = 0;
    local_80 = 0;
    FUN_fffffff00a76d3ec(&local_90,0x10,"%s");
    if (local_b2 == 0) {
LAB_fffffff00a59c63c:
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a59c640);
      (*pcVar4)();
    }
    lVar7 = *plVar8;
    if (lVar7 != 0) {
      lVar3 = tpidr_el1;
      lVar9 = 8;
      do {
        if (*(ulong *)(lVar7 + 8) == 0) {
          *(ulong *)(lVar7 + 8) = (ulong)*(uint *)(lVar3 + 0x4e8);
        }
        else {
          FUN_fffffff00a2262d4(lVar7,lVar3,0);
        }
        if ((&stack0x0000007f < &local_80) ||
           (puVar6 = *(undefined8 **)(lVar7 + 0x18), (undefined8 *)((long)puVar6 + 0xffU) < puVar6))
        goto LAB_fffffff00a59c63c;
        uStack_78 = puVar6[1];
        local_80 = *puVar6;
        if (*(int *)(lVar7 + 8) == *(int *)(lVar3 + 0x4e8)) {
          *(int *)(lVar7 + 8) = in_wzr;
        }
        else {
          FUN_fffffff00a226e08(lVar7,lVar3);
        }
        iVar5 = FUN_fffffff00a59815c(0,0x80206919,&local_90,param_1,DAT_fffffff007c6b250);
        if ((iVar5 != 0) && (iVar5 != 0x31)) {
          local_a0 = 0;
          uStack_98 = 0;
          local_b0 = 0;
          uStack_a8 = 0;
          puVar1 = (ulong *)(lVar7 + 8);
          if (*puVar1 == 0) {
            *puVar1 = (ulong)*(uint *)(lVar3 + 0x4e8);
          }
          else {
            FUN_fffffff00a2262d4(lVar7,lVar3,0);
          }
          lVar2 = *(long *)(lVar7 + 0x20);
          FUN_fffffff00a8dd3c8(2,*(long *)(lVar7 + 0x18) + 4,&local_a0,0x10);
          FUN_fffffff00a8dd3c8(2,lVar2 + 4,&local_b0,0x10);
          if (*(int *)puVar1 == *(int *)(lVar3 + 0x4e8)) {
            *(int *)puVar1 = in_wzr;
          }
          else {
            FUN_fffffff00a226e08(lVar7,lVar3);
          }
        }
        plVar8 = (long *)((long)local_c0 + lVar9);
        if ((plVar8 < local_c0) || (local_c0 + local_b2 <= plVar8)) goto LAB_fffffff00a59c63c;
        lVar7 = *plVar8;
        lVar9 = lVar9 + 8;
        plVar8 = local_c0;
      } while (lVar7 != 0);
    }
    FUN_fffffff00a4c0474(plVar8);
    local_c0 = (long *)0x0;
    local_b2 = 0;
  }
  lVar7 = tpidr_el1;
  if (*(ulong *)(param_1 + 0x4e0) == 0) {
    *(ulong *)(param_1 + 0x4e0) = (ulong)*(uint *)(lVar7 + 0x4e8);
    lVar9 = *(long *)(param_1 + 0x4e8);
  }
  else {
    FUN_fffffff00a2262d4(param_1 + 0x4d8,lVar7,0);
    lVar9 = *(long *)(param_1 + 0x4e8);
  }
  if (lVar9 != 0) {
    *(undefined8 *)(param_1 + 0x4e8) = 0;
    FUN_fffffff00a5a21b0(lVar9,0);
    FUN_fffffff00a5a263c(lVar9,0);
  }
  if (*(int *)(param_1 + 0x4e0) == *(int *)(lVar7 + 0x4e8)) {
    *(int *)(param_1 + 0x4e0) = in_wzr;
  }
  else {
    FUN_fffffff00a226e08(param_1 + 0x4d8,lVar7);
  }
  if (DAT_fffffff00ad30000 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590();
}

