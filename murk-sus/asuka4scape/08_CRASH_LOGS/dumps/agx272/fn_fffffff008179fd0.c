// FUN_fffffff008179fd0 @ fffffff008179fd0 size=448

void FUN_fffffff008179fd0(long param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  ulong uVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  ulong unaff_x30;
  
  uVar3 = thunk_EXT_FUN_8011000003397c88();
  plVar6 = *(long **)(param_1 + 0x1ac98);
  if (plVar6 != (long *)0x0) {
    do {
      plVar7 = (long *)plVar6[0xc];
      if (uVar3 <= (ulong)plVar6[0xb]) break;
      if ((*(byte *)(param_1 + 0x1ff) >> 3 & 1) != 0) {
        lVar4 = *(long *)(plVar6[2] + 0x28);
        if (lVar4 != 0) {
          thunk_EXT_FUN_8011000002c13530(lVar4);
          thunk_EXT_FUN_8011000002c13500(lVar4);
        }
        thunk_EXT_FUN_8011000003a49114
                  (
                  "\"Timeout SharedEvent: late eval wait timed out sharedID=%llu waitValue=%llu completedValue=%llu stampIdx=%d stamp=0x%llx\" @%s:%d"
                  );
        return;
      }
      FUN_fffffff0081e2230(plVar6);
      lVar4 = plVar6[0xc];
      if (lVar4 == 0) {
        plVar5 = (long *)plVar6[0xd];
        if ((long *)*plVar5 != plVar6) goto LAB_fffffff00817a13c;
        *(long **)(param_1 + 0x1aca0) = plVar5;
      }
      else {
        if (*(long **)(lVar4 + 0x68) != plVar6 + 0xc) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817a14c);
          (*pcVar2)();
        }
        if (*(long **)plVar6[0xd] != plVar6) {
LAB_fffffff00817a13c:
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817a144);
          (*pcVar2)();
        }
        *(long **)(lVar4 + 0x68) = (long *)plVar6[0xd];
        plVar5 = (long *)plVar6[0xd];
      }
      *plVar5 = lVar4;
      *(undefined1 *)(plVar6 + 0xe) = 0;
      (**(code **)(*plVar6 + 0x28))(plVar6);
      plVar6 = plVar7;
    } while (plVar7 != (long *)0x0);
    if (*(long *)(param_1 + 0x1ac98) != 0) {
      puVar1 = (undefined8 *)(**(long **)(param_1 + 0x1ac90) + 0x130);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00817a104. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)*puVar1)(*(long **)(param_1 + 0x1ac90),plVar6[0xb],puVar1);
        return;
      }
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817a0fc);
      (*pcVar2)();
    }
  }
  return;
}

