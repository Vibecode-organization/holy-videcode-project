// FUN_fffffff009c35850 @ fffffff009c35850 size=276

undefined8 FUN_fffffff009c35850(long param_1,undefined8 *param_2,undefined8 *param_3,long param_4)

{
  long *plVar1;
  code *pcVar2;
  long *plVar3;
  long lVar4;
  undefined8 uVar5;
  
  uVar5 = 0xe00002bd;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x150));
  if ((*(byte *)(param_4 + 0xf1) & 1) == 0) {
    plVar3 = *(long **)(param_1 + 0x188);
    if (plVar3 != (long *)0x0) {
      do {
        if ((plVar3[4] == param_3[1]) && (plVar3[0xb] == param_4)) {
          uVar5 = 0xe00002c9;
          goto LAB_fffffff009c35938;
        }
        plVar3 = (long *)*plVar3;
      } while (plVar3 != (long *)0x0);
    }
    plVar3 = (long *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff00806b2f0);
    if (plVar3 != (long *)0x0) {
      plVar1 = (long *)(param_1 + 0x188);
      thunk_EXT_FUN_80110000039a2344(plVar3 + 2,*param_2,*param_3,param_3[1]);
      plVar3[10] = param_3[2];
      plVar3[0xb] = param_4;
      lVar4 = *plVar1;
      if (lVar4 == 0) {
        *plVar3 = 0;
        *(long **)(param_1 + 400) = plVar3;
      }
      else {
        if (*(long **)(lVar4 + 8) != plVar1) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c35964);
          (*pcVar2)();
        }
        *plVar3 = lVar4;
        *(long **)(lVar4 + 8) = plVar3;
      }
      uVar5 = 0;
      *plVar1 = (long)plVar3;
      plVar3[1] = (long)plVar1;
    }
  }
  else {
    uVar5 = 0xe00002d8;
  }
LAB_fffffff009c35938:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x150));
  return uVar5;
}

