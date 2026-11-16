// FUN_fffffff009c4277c @ fffffff009c4277c size=152

undefined8 FUN_fffffff009c4277c(long param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long *plVar3;
  
  thunk_EXT_FUN_8011000003223a00(*(undefined8 *)(param_1 + 0x18));
  lVar2 = *(long *)(param_2 + 0x30);
  if (lVar2 == 0) {
    plVar3 = *(long **)(param_2 + 0x38);
    if (*plVar3 != param_2) goto LAB_fffffff009c42804;
    *(long **)(param_1 + 0x38) = plVar3;
  }
  else {
    if (*(long **)(lVar2 + 0x38) != (long *)(param_2 + 0x30)) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c42814);
      (*pcVar1)();
    }
    if (**(long **)(param_2 + 0x38) != param_2) {
LAB_fffffff009c42804:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c4280c);
      (*pcVar1)();
    }
    *(long **)(lVar2 + 0x38) = *(long **)(param_2 + 0x38);
    plVar3 = *(long **)(param_2 + 0x38);
  }
  *plVar3 = lVar2;
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(param_1 + 0x18));
  return 0;
}

