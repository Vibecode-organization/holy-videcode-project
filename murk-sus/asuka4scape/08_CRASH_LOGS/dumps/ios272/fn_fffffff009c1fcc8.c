// FUN_fffffff009c1fcc8 @ fffffff009c1fcc8 size=308

long * FUN_fffffff009c1fcc8(long *param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  
  thunk_EXT_FUN_80110000032222a8(param_1[10]);
  plVar4 = param_1 + 8;
  plVar3 = (long *)*plVar4;
  do {
    if (plVar3 == (long *)0x0) {
      plVar3 = (long *)FUN_fffffff009c2d4d8(param_1,param_2,param_3,param_4,plVar4);
      if (plVar3 != (long *)0x0) {
        lVar2 = *plVar4;
        if (lVar2 == 0) {
          plVar3[6] = 0;
          param_1[9] = (long)(plVar3 + 6);
        }
        else {
          if (*(long **)(lVar2 + 0x38) != plVar4) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c1fdfc);
            (*pcVar1)();
          }
          plVar3[6] = lVar2;
          *(long **)(lVar2 + 0x38) = plVar3 + 6;
        }
        *plVar4 = (long)plVar3;
        plVar3[7] = (long)plVar4;
      }
LAB_fffffff009c1fd80:
      thunk_EXT_FUN_8011000003222de0(param_1[10]);
      return plVar3;
    }
    if ((plVar3[3] == param_2) && (*(int *)((long)plVar3 + 0x54) == (int)param_4)) {
      if ((*(byte *)((long)plVar3 + 0x59) & 1) == 0) {
        (**(code **)(*plVar3 + 0x20))(plVar3);
      }
      else {
        (**(code **)(*param_1 + 0x20))(param_1);
        *(undefined1 *)((long)plVar3 + 0x59) = 0;
      }
      goto LAB_fffffff009c1fd80;
    }
    plVar3 = (long *)plVar3[6];
  } while( true );
}

