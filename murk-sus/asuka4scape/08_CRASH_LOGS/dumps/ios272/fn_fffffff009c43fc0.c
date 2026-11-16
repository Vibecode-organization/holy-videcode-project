// FUN_fffffff009c43fc0 @ fffffff009c43fc0 size=156

undefined8 FUN_fffffff009c43fc0(long param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long *plVar3;
  
  thunk_EXT_FUN_8011000003223a00(*(undefined8 *)(param_1 + 0x10));
  lVar2 = *(long *)(param_2 + 0x10);
  if (lVar2 == 0) {
    plVar3 = *(long **)(param_2 + 0x18);
    if (plVar3 == (long *)0x0) goto LAB_fffffff009c44034;
    if (*plVar3 != param_2) goto LAB_fffffff009c4404c;
    *(long **)(param_1 + 0x28) = plVar3;
  }
  else {
    if (*(long **)(lVar2 + 0x18) != (long *)(param_2 + 0x10)) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c4405c);
      (*pcVar1)();
    }
    if (**(long **)(param_2 + 0x18) != param_2) {
LAB_fffffff009c4404c:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c44054);
      (*pcVar1)();
    }
    *(long **)(lVar2 + 0x18) = *(long **)(param_2 + 0x18);
    plVar3 = *(long **)(param_2 + 0x18);
  }
  *plVar3 = lVar2;
LAB_fffffff009c44034:
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(param_1 + 0x10));
  return 1;
}

