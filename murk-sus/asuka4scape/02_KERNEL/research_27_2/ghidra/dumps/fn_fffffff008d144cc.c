// FUN_fffffff008d144cc @ fffffff008d144cc size=188
// CALLERS:
//   fffffff00afb8d3c no-fn
//   fffffff008d143e4 FUN_fffffff008d142e8@fffffff008d142e8
// CALLEES:
//   fffffff008dfff40 thunk_EXT_FUN_80110000039a40ec
//   fffffff008de6594 FUN_fffffff008de6594
//   fffffff008dffd30 thunk_EXT_FUN_80110000038fe270
//   fffffff008cd5954 FUN_fffffff008cd5954

void FUN_fffffff008d144cc(undefined8 param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  long *plVar5;
  ulong unaff_x30;
  
  if (((((*(byte *)(param_2 + 0x50) & 1) == 0) &&
       (*(long *)(*(long *)(param_2 + 0x48) + 0x120) != 0)) &&
      (uVar3 = thunk_EXT_FUN_80110000039a40ec(param_2,param_1,param_2 + 0x40,1), (int)uVar3 != 0))
     && (iVar2 = FUN_fffffff008cd5954(1,4), iVar2 != 0)) {
    FUN_fffffff008de6594(uVar3);
  }
  plVar5 = *(long **)(param_2 + 0x48);
  thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007e5c3a8,param_2);
  puVar4 = (undefined8 *)(*plVar5 + 0x28);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008d14570);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff008d14578. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar4)(plVar5,puVar4);
  return;
}

