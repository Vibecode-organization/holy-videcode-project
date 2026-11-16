// FUN_fffffff009c2344c @ fffffff009c2344c size=448

/* WARNING: Removing unreachable block (ram,0xfffffff009c2353c) */

void FUN_fffffff009c2344c(long param_1)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  undefined8 *puVar4;
  long lVar5;
  long lVar6;
  long local_48;
  long *local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  local_40 = &local_48;
  local_48 = 0;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  lVar6 = *(long *)(param_1 + 0x40);
joined_r0xfffffff009c23490:
  lVar5 = lVar6;
  if (lVar6 != 0) {
    do {
      plVar2 = (long *)(lVar5 + 0x30);
      lVar6 = *plVar2;
      if ((*(byte *)(lVar5 + 0x59) & 1) != 0) {
        if (lVar6 == 0) {
          plVar3 = *(long **)(lVar5 + 0x38);
          if (*plVar3 != lVar5) goto LAB_fffffff009c235f8;
          *(long **)(param_1 + 0x48) = plVar3;
        }
        else {
          if (*(long **)(lVar6 + 0x38) != plVar2) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c23608);
            (*pcVar1)();
          }
          if (**(long **)(lVar5 + 0x38) != lVar5) {
LAB_fffffff009c235f8:
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c23600);
            (*pcVar1)();
          }
          *(long **)(lVar6 + 0x38) = *(long **)(lVar5 + 0x38);
          plVar3 = *(long **)(lVar5 + 0x38);
        }
        *plVar3 = lVar6;
        *(undefined8 *)(lVar5 + 0x30) = 0;
        *(long **)(lVar5 + 0x38) = local_40;
        *local_40 = lVar5;
        local_40 = plVar2;
        thunk_EXT_FUN_80110000038905fc(param_1 + 0x3a8);
        if (lVar5 == *(long *)(param_1 + 0x38)) goto LAB_fffffff009c23518;
      }
      lVar5 = lVar6;
      if (lVar6 == 0) break;
    } while( true );
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  lVar6 = local_48;
  do {
    if (lVar6 == 0) {
      if (*(long *)PTR_DAT_fffffff00806ca40 != local_38) {
        thunk_EXT_FUN_8011000003a48590();
        return;
      }
      return;
    }
    lVar5 = *(long *)(lVar6 + 0x30);
    if (lVar5 == 0) {
      plVar3 = *(long **)(lVar6 + 0x38);
      plVar2 = plVar3;
      if (*plVar3 != lVar6) goto LAB_fffffff009c235e8;
    }
    else {
      if (*(long **)(lVar5 + 0x38) != (long *)(lVar6 + 0x30)) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c235f8);
        (*pcVar1)();
      }
      if (**(long **)(lVar6 + 0x38) != lVar6) {
LAB_fffffff009c235e8:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c235f0);
        (*pcVar1)();
      }
      *(long **)(lVar5 + 0x38) = *(long **)(lVar6 + 0x38);
      plVar3 = *(long **)(lVar6 + 0x38);
      plVar2 = local_40;
    }
    local_40 = plVar2;
    *plVar3 = lVar5;
    FUN_fffffff009c2da10();
    thunk_EXT_FUN_801100000389060c(param_1 + 0x3a8);
    lVar6 = lVar5;
  } while( true );
LAB_fffffff009c23518:
  *(undefined8 *)(param_1 + 0x38) = 0;
  puVar4 = *(undefined8 **)(param_1 + 0x178);
  *(undefined2 *)(puVar4 + 1) = 0;
  *puVar4 = 0;
  goto joined_r0xfffffff009c23490;
}

