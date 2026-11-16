// FUN_fffffff009c35964 @ fffffff009c35964 size=252

undefined8 FUN_fffffff009c35964(long param_1,long param_2,long param_3)

{
  code *pcVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  undefined8 uVar5;
  
  uVar5 = 0xe00002c2;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x150));
  plVar4 = *(long **)(param_1 + 0x188);
  if (plVar4 != (long *)0x0) {
    do {
      if ((plVar4[4] == *(long *)(param_2 + 8)) && (plVar4[0xb] == param_3)) {
        lVar2 = *plVar4;
        if (lVar2 == 0) {
          plVar3 = (long *)plVar4[1];
          if ((long *)*plVar3 != plVar4) goto LAB_fffffff009c35a50;
          *(long **)(param_1 + 400) = plVar3;
        }
        else {
          if (*(long **)(lVar2 + 8) != plVar4) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c35a60);
            (*pcVar1)();
          }
          if (*(long **)plVar4[1] != plVar4) {
LAB_fffffff009c35a50:
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c35a58);
            (*pcVar1)();
          }
          *(undefined8 **)(lVar2 + 8) = (undefined8 *)plVar4[1];
          plVar3 = (long *)plVar4[1];
        }
        *plVar3 = lVar2;
        thunk_EXT_FUN_80110000039a3d30(plVar4 + 2);
        thunk_EXT_FUN_80110000038fe270(&DAT_fffffff00806b330,plVar4);
        uVar5 = 0;
        break;
      }
      plVar4 = (long *)*plVar4;
    } while (plVar4 != (long *)0x0);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x150));
  return uVar5;
}

