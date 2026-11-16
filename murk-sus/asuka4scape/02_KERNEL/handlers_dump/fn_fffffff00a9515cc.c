// FUN_fffffff00a9515cc @ fffffff00a9515cc size=280 depth=1
// CALLERS:
//   fffffff00afbed38 ?
//   fffffff00aa0f758 FUN_fffffff00aa0f014
//   fffffff00a9d46d8 FUN_fffffff00a9d4470
//   fffffff00aa0f9f8 FUN_fffffff00aa0f8a0
//   fffffff00aa0fabc FUN_fffffff00aa0fa88
//   fffffff00a9f0028 FUN_fffffff00a9eff54
//   fffffff00a9c1c2c FUN_fffffff00a9c1940
//   fffffff00a9c3484 FUN_fffffff00a9c342c
//   fffffff00a9efef0 FUN_fffffff00a9efed0
//   fffffff00a9f0360 FUN_fffffff00a9f0034
//   fffffff00a9f45f4 FUN_fffffff00a9f3fc8
//   fffffff00a9f4d18 FUN_fffffff00a9f4b0c
//   fffffff00a9f4d48 FUN_fffffff00a9f4b0c
//   fffffff00a9f7bbc FUN_fffffff00a9f76f0
//   fffffff00a9fdb30 FUN_fffffff00a9fd944
//   fffffff00a9ff680 FUN_fffffff00a9ff008
//   fffffff00aa04fc0 FUN_fffffff00aa04934
//   fffffff00aa0d368 FUN_fffffff00aa0d290
//   fffffff00aa0d528 FUN_fffffff00aa0d290
//   fffffff00aa0fb14 FUN_fffffff00aa0fae4
//   fffffff00aa11c5c FUN_fffffff00aa11c0c
//   fffffff00aa11e8c FUN_fffffff00aa11e40
//   fffffff00a9e0198 FUN_fffffff00a9dfff0
//   fffffff00a9fd6a8 ?
// CALLS:
//   fffffff00a226e08 FUN_fffffff00a226e08
//   fffffff00a2262d4 FUN_fffffff00a2262d4
//   fffffff00a2211ec FUN_fffffff00a2211ec

undefined8 FUN_fffffff00a9515cc(long param_1,undefined4 param_2,long param_3,long param_4)

{
  ulong *puVar1;
  long *plVar2;
  uint *puVar3;
  long lVar4;
  code *pcVar5;
  long *plVar6;
  uint uVar7;
  long *plVar8;
  uint in_wzr;
  
  uVar7 = 0x8004;
  if ((DAT_fffffff007c7d1b8 & 0x10) != 0) {
    uVar7 = 4;
  }
  plVar6 = (long *)FUN_fffffff00a2211ec((long *)&DAT_fffffff007c7d190,uVar7);
  *(undefined4 *)(plVar6 + 2) = param_2;
  plVar6[3] = param_3;
  plVar6[4] = param_4;
  lVar4 = tpidr_el1;
  puVar1 = (ulong *)(*(ulong *)(param_1 + 0x58) + 8);
  if (*puVar1 == 0) {
    *puVar1 = (ulong)*(uint *)(lVar4 + 0x4e8);
  }
  else {
    FUN_fffffff00a2262d4(*(ulong *)(param_1 + 0x58),lVar4,(undefined **)0x0);
  }
  plVar2 = (long *)(param_1 + 0x48);
  plVar8 = *(long **)(param_1 + 0x50);
  if ((long *)*plVar8 != plVar2) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a9516d8);
    (*pcVar5)();
  }
  *plVar6 = (long)plVar2;
  plVar6[1] = (long)plVar8;
  if (plVar8 == plVar2) {
    *plVar2 = (long)plVar6;
  }
  else {
    *plVar8 = (long)plVar6;
  }
  *(long **)(param_1 + 0x50) = plVar6;
  puVar3 = (uint *)(*(ulong *)(param_1 + 0x58) + 8);
  uVar7 = *puVar3;
  if (uVar7 == *(uint *)(lVar4 + 0x4e8)) {
    *puVar3 = in_wzr;
  }
  else {
    FUN_fffffff00a226e08(*(ulong *)(param_1 + 0x58),lVar4,uVar7);
  }
  (**(code **)(**(long **)(param_1 + 0x30) + 0xd0))();
  return 1;
}

