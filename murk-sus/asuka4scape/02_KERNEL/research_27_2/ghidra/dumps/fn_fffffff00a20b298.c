// FUN_fffffff00a20b298 @ fffffff00a20b298 size=524
// CALLERS:
//   fffffff00afb8481 no-fn
//   fffffff007bbc7c0 no-fn
// CALLEES:
//   fffffff00aa4d114 FUN_fffffff00aa4d114

undefined8
FUN_fffffff00a20b298
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,long param_8,
          int param_9)

{
  long *plVar1;
  code *pcVar2;
  undefined1 uVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  long lVar7;
  
  if (param_9 < 1) {
    if (param_9 == -1) {
      if (*(long *)(param_8 + 0x5d8) != param_7) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114
                  (param_1,param_2,param_3,param_4,param_5,param_6,
                   (byte *)
                   "%s: task %p attempting to set role %d in coalition %p to which it does not belong! @%s:%d"
                  );
      }
    }
    else if (param_9 != 0) {
LAB_fffffff00a20b38c:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114
                (param_1,param_2,param_3,param_4,param_5,param_6,
                 (byte *)"%s: invalid role(%d) for task @%s:%d");
    }
    uVar3 = 0;
    lVar4 = 0x70;
  }
  else if (param_9 == 3) {
    uVar3 = 3;
    lVar4 = 0x50;
  }
  else {
    if (param_9 != 2) {
      if (param_9 != 1) goto LAB_fffffff00a20b38c;
      lVar4 = *(long *)(param_7 + 0x48);
      if (lVar4 != 0) {
        plVar1 = (long *)(lVar4 + 0x5f0);
        plVar5 = *(long **)(lVar4 + 0x5f8);
        if (((long *)*plVar5 != plVar1) || (lVar7 = *plVar1, *(long **)(lVar7 + 8) != plVar1)) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a20b46c);
          (*pcVar2)();
        }
        plVar6 = (long *)(param_7 + 0x70);
        if (((long *)**(long **)(param_7 + 0x78) != plVar6) || (*(long **)(*plVar6 + 8) != plVar6))
        {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a20b474);
          (*pcVar2)();
        }
        *(long **)(lVar7 + 8) = plVar5;
        *plVar5 = lVar7;
        plVar5 = *(long **)(param_7 + 0x78);
        *(long **)(lVar4 + 0x5f0) = plVar6;
        *(long **)(lVar4 + 0x5f8) = plVar5;
        *plVar5 = (long)plVar1;
        *(long **)(param_7 + 0x78) = plVar1;
        *(undefined1 *)(*(long *)(param_7 + 0x48) + 0x5cc) = 0;
      }
      plVar1 = (long *)(param_8 + 0x5f0);
      plVar5 = *(long **)(param_8 + 0x5f8);
      if (((long *)*plVar5 != plVar1) || (lVar4 = *plVar1, *(long **)(lVar4 + 8) != plVar1)) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a20b468);
        (*pcVar2)();
      }
      *(long **)(lVar4 + 8) = plVar5;
      *plVar5 = lVar4;
      *(long *)(param_8 + 0x5f0) = param_8 + 0x5f0;
      *(long **)(param_8 + 0x5f8) = plVar1;
      uVar3 = 1;
      *(long *)(param_7 + 0x48) = param_8;
      goto LAB_fffffff00a20b444;
    }
    uVar3 = 2;
    lVar4 = 0x60;
  }
  plVar5 = (long *)(param_7 + lVar4);
  plVar1 = (long *)(param_8 + 0x5f0);
  plVar6 = *(long **)(param_8 + 0x5f8);
  if (((long *)*plVar6 != plVar1) || (lVar4 = *plVar1, *(long **)(lVar4 + 8) != plVar1)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a20b460);
    (*pcVar2)();
  }
  if ((*(long **)plVar5[1] != plVar5) || (*(long **)(*plVar5 + 8) != plVar5)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a20b464);
    (*pcVar2)();
  }
  *(long **)(lVar4 + 8) = plVar6;
  *plVar6 = lVar4;
  plVar6 = (long *)plVar5[1];
  *(long **)(param_8 + 0x5f0) = plVar5;
  *(long **)(param_8 + 0x5f8) = plVar6;
  *plVar6 = (long)plVar1;
  plVar5[1] = (long)plVar1;
LAB_fffffff00a20b444:
  *(undefined1 *)(param_8 + 0x5cc) = uVar3;
  return 0;
}

