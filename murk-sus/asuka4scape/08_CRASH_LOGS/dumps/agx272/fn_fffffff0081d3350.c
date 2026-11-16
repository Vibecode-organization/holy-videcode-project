// FUN_fffffff0081d3350 @ fffffff0081d3350 size=512

/* WARNING: Removing unreachable block (ram,0xfffffff0081d3484) */

undefined8
FUN_fffffff0081d3350(long param_1,undefined8 param_2,long param_3,long param_4,uint param_5)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  long *plVar4;
  long lVar5;
  undefined *puVar6;
  long *plVar7;
  undefined8 uVar8;
  undefined8 *in_stack_00000000;
  long *in_stack_00000008;
  
  uVar3 = thunk_EXT_FUN_8011000003977d8c(param_2,0);
  if (uVar3 < (ulong)(param_4 + param_3)) {
    uVar8 = thunk_EXT_FUN_8011000003a49114
                      ("AGXk: %s:%d:%s: !!! Attempting to map past the end of the descriptor!\n");
    return uVar8;
  }
  uVar8 = 0xe00002bc;
  FUN_fffffff0081d30b8(param_1);
  plVar4 = (long *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff007ca17c8);
  if (plVar4 == (long *)0x0) {
    uVar8 = 0xe00002bd;
  }
  else {
    lVar5 = FUN_fffffff0081b6bf8
                      (*(undefined8 *)(*(long *)(param_1 + 0xe0) + 0x4b0),param_2,param_5 >> 1 & 1,9
                      );
    *plVar4 = lVar5;
    if (lVar5 == 0) {
      puVar6 = &DAT_fffffff007ca1808;
    }
    else {
      iVar2 = thunk_EXT_FUN_801100000297b3fc();
      if (iVar2 == 0) {
        plVar4[1] = param_3;
        plVar4[2] = param_4;
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xe8));
        plVar7 = (long *)(param_1 + 0xf0);
        lVar5 = *plVar7;
        if (lVar5 == 0) {
          plVar4[3] = 0;
          *(long **)(param_1 + 0xf8) = plVar4 + 3;
        }
        else {
          if (*(long **)(lVar5 + 0x20) != plVar7) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0081d3550);
            (*pcVar1)();
          }
          plVar4[3] = lVar5;
          *(long **)(lVar5 + 0x20) = plVar4 + 3;
        }
        *(long **)(param_1 + 0xf0) = plVar4;
        plVar4[4] = (long)plVar7;
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xe8));
        lVar5 = (**(code **)(*(long *)*plVar4 + 0x98))();
        plVar4 = *(long **)(*(long *)(param_1 + 0xe0) + 0x4b0);
        uVar8 = (**(code **)(*plVar4 + 0x208))(plVar4,lVar5 + param_3,0);
        *in_stack_00000000 = uVar8;
        *in_stack_00000008 = param_4;
        return 0;
      }
      if ((long *)*plVar4 != (long *)0x0) {
        (**(code **)(*(long *)*plVar4 + 0x28))();
      }
      *plVar4 = 0;
      puVar6 = &DAT_fffffff007ca1848;
    }
    thunk_EXT_FUN_80110000038fe270(puVar6,plVar4);
  }
  return uVar8;
}

