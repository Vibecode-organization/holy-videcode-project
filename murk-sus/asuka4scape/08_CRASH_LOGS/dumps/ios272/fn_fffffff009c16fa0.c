// FUN_fffffff009c16fa0 @ fffffff009c16fa0 size=620

/* WARNING: Removing unreachable block (ram,0xfffffff009c17104) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c17028) */

void FUN_fffffff009c16fa0(long param_1,int param_2)

{
  code *pcVar1;
  long **pplVar2;
  long **pplVar3;
  undefined8 *puVar4;
  long *plVar5;
  ulong uVar6;
  long *plVar7;
  long *local_58;
  long **local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  if (*(int *)(param_1 + 0x18) != 0) {
    thunk_EXT_FUN_8011000003246024(param_1,0,0);
  }
  local_50 = &local_58;
  local_58 = (long *)0x0;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x30));
  do {
    uVar6 = **(ulong **)(param_1 + 0x20);
    plVar7 = *(long **)(param_1 + 0x40);
joined_r0xfffffff009c17034:
    plVar5 = plVar7;
    if (plVar7 != (long *)0x0) {
      do {
        pplVar2 = (long **)(plVar5 + 5);
        plVar7 = *pplVar2;
        if ((ulong)plVar5[2] <= uVar6) {
          if (plVar7 == (long *)0x0) {
            puVar4 = (undefined8 *)plVar5[6];
            if ((long *)*puVar4 != plVar5) goto LAB_fffffff009c171e8;
            *(undefined8 **)(param_1 + 0x48) = puVar4;
          }
          else {
            if ((long **)plVar7[6] != pplVar2) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c171f8);
              (*pcVar1)();
            }
            if (*(long **)plVar5[6] != plVar5) {
LAB_fffffff009c171e8:
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c171f0);
              (*pcVar1)();
            }
            plVar7[6] = (long)plVar5[6];
            puVar4 = (undefined8 *)plVar5[6];
          }
          *puVar4 = plVar7;
          if ((param_2 == 0) || ((*(byte *)(plVar5 + 0xd) & 1) == 0)) goto LAB_fffffff009c170d4;
          FUN_fffffff009c158dc(plVar5[8],plVar5);
          (**(code **)(*plVar5 + 0x28))(plVar5);
        }
        plVar5 = plVar7;
        if (plVar7 == (long *)0x0) break;
      } while( true );
    }
    if (*(long *)(param_1 + 0x40) == 0 || uVar6 == **(ulong **)(param_1 + 0x20)) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x60));
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x30));
      plVar7 = local_58;
      do {
        if (plVar7 == (long *)0x0) {
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x60));
          if (*(long *)PTR_DAT_fffffff00806ca40 == local_48) {
            return;
          }
          thunk_EXT_FUN_8011000003a48590();
          return;
        }
        plVar5 = (long *)plVar7[5];
        if (plVar5 == (long *)0x0) {
          pplVar3 = (long **)plVar7[6];
          pplVar2 = pplVar3;
          if (*pplVar3 != plVar7) goto LAB_fffffff009c171f8;
        }
        else {
          if ((long *)plVar5[6] != plVar7 + 5) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c17208);
            (*pcVar1)();
          }
          if (*(long **)plVar7[6] != plVar7) {
LAB_fffffff009c171f8:
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c17200);
            (*pcVar1)();
          }
          plVar5[6] = (long)plVar7[6];
          pplVar3 = (long **)plVar7[6];
          pplVar2 = local_50;
        }
        local_50 = pplVar2;
        *pplVar3 = plVar5;
        FUN_fffffff009c15b1c(plVar7);
        (**(code **)(*plVar7 + 0x28))(plVar7);
        plVar7 = plVar5;
      } while( true );
    }
  } while( true );
LAB_fffffff009c170d4:
  plVar5[5] = 0;
  plVar5[6] = (long)local_50;
  *local_50 = plVar5;
  local_50 = pplVar2;
  goto joined_r0xfffffff009c17034;
}

