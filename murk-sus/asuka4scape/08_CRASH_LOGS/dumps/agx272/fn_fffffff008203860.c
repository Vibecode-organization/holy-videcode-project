// FUN_fffffff008203860 @ fffffff008203860 size=204

void FUN_fffffff008203860
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  code *pcVar1;
  long *plVar2;
  undefined8 *puVar3;
  ulong unaff_x30;
  
  plVar2 = *(long **)(*(long *)(param_1 + 0x10) + 0x310);
  puVar3 = (undefined8 *)(*plVar2 + 0xf8);
  (*(code *)*puVar3)(puVar3,plVar2,FUN_fffffff00820392c,param_1,0,0,0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008203920);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff008203928. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6120 + 0xb0))(param_1,param_2,param_3,param_4,param_5);
  return;
}

