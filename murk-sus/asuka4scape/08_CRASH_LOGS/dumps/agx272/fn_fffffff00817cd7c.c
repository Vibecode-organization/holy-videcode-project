// FUN_fffffff00817cd7c @ fffffff00817cd7c size=4

undefined8 FUN_fffffff00817cd7c(long param_1)

{
  ulong uVar1;
  code *pcVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  ulong uStack_48;
  
  lVar4 = *(long *)(param_1 + 0x20);
  if (*(long *)(lVar4 + 0x1ac98) != 0) {
    uVar3 = thunk_EXT_FUN_8011000003397c88();
    plVar7 = *(long **)(lVar4 + 0x1ac98);
    if (plVar7 != (long *)0x0) {
      do {
        plVar8 = (long *)plVar7[0xc];
        if ((int)plVar7[0x11] == 0) {
          uVar1 = plVar7[0xb];
        }
        else {
          uStack_48 = 0;
          thunk_EXT_FUN_8011000003204ed8((int)plVar7[0x11],1000000,&uStack_48);
          plVar7[0xb] = uStack_48;
          uVar1 = uStack_48;
        }
        if (uVar1 < uVar3) {
          FUN_fffffff0081e2230(plVar7);
          lVar5 = plVar7[0xc];
          if (lVar5 == 0) {
            plVar6 = (long *)plVar7[0xd];
            if ((long *)*plVar6 != plVar7) goto LAB_fffffff00817cecc;
            *(long **)(lVar4 + 0x1aca0) = plVar6;
          }
          else {
            if (*(long **)(lVar5 + 0x68) != plVar7 + 0xc) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817cedc);
              (*pcVar2)();
            }
            if (*(long **)plVar7[0xd] != plVar7) {
LAB_fffffff00817cecc:
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817ced4);
              (*pcVar2)();
            }
            *(long **)(lVar5 + 0x68) = (long *)plVar7[0xd];
            plVar6 = (long *)plVar7[0xd];
          }
          *plVar6 = lVar5;
          *(undefined1 *)(plVar7 + 0xe) = 0;
          (**(code **)(*plVar7 + 0x28))(plVar7);
        }
        plVar7 = plVar8;
      } while (plVar8 != (long *)0x0);
      if (*(long *)(lVar4 + 0x1ac98) != 0) {
        (**(code **)(**(long **)(lVar4 + 0x1ac90) + 0xf0))
                  (*(long **)(lVar4 + 0x1ac90),*(undefined4 *)(*(long *)(lVar4 + 0x1ac98) + 0x88));
      }
    }
  }
  return 0;
}

