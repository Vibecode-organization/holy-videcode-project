// FUN_fffffff0092702f0 @ fffffff0092702f0 size=4 depth=0
// CALLERS:
//   fffffff00afdd210 ?
//   fffffff007efecf0 ?
// CALLS:

undefined8 FUN_fffffff0092702f0(long *param_1,long param_2,long param_3)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  undefined8 *puVar8;
  undefined8 uStack_180;
  long *aplStack_178 [3];
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined8 uStack_158;
  long *plStack_150;
  undefined8 uStack_148;
  long *aplStack_140 [30];
  
  puVar8 = *(undefined8 **)(param_3 + 0x30);
  aplStack_140[0x1c] = (long *)0x0;
  aplStack_140[0x19] = (long *)0x0;
  aplStack_140[0x18] = (long *)0x0;
  aplStack_140[0x1b] = (long *)0x0;
  aplStack_140[0x1a] = (long *)0x0;
  aplStack_140[0x15] = (long *)0x0;
  aplStack_140[0x14] = (long *)0x0;
  aplStack_140[0x17] = (long *)0x0;
  aplStack_140[0x16] = (long *)0x0;
  aplStack_140[0x11] = (long *)0x0;
  aplStack_140[0x10] = (long *)0x0;
  aplStack_140[0x13] = (long *)0x0;
  aplStack_140[0x12] = (long *)0x0;
  aplStack_140[0xd] = (long *)0x0;
  aplStack_140[0xc] = (long *)0x0;
  aplStack_140[0xf] = (long *)0x0;
  aplStack_140[0xe] = (long *)0x0;
  aplStack_140[9] = (long *)0x0;
  aplStack_140[8] = (long *)0x0;
  aplStack_140[0xb] = (long *)0x0;
  aplStack_140[10] = (long *)0x0;
  aplStack_140[5] = (long *)0x0;
  aplStack_140[4] = (long *)0x0;
  aplStack_140[7] = (long *)0x0;
  aplStack_140[6] = (long *)0x0;
  aplStack_140[1] = (long *)0x0;
  aplStack_140[0] = (long *)0x0;
  aplStack_140[3] = (long *)0x0;
  aplStack_140[2] = (long *)0x0;
  uStack_158 = 0;
  uStack_160 = 0;
  uStack_15c = 0;
  uStack_148 = 0;
  plStack_150 = (long *)0x0;
  lVar6 = 0x38;
  lVar7 = 0xf0;
  aplStack_178[0] = (long *)0x0;
  uStack_180 = 0;
  aplStack_178[2] = (long *)0x0;
  aplStack_178[1] = (long *)0x0;
  do {
    *(undefined4 *)((long)&uStack_180 + lVar6) = 0;
    *(undefined8 *)((long)aplStack_178 + lVar6) = 0;
    lVar6 = lVar6 + 0x10;
    lVar7 = lVar7 + -0x10;
  } while (lVar7 != 0);
  if (*(int *)(param_3 + 0x38) != 0x40) {
    thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
    return 0xe00002c2;
  }
  plVar1 = thunk_FUN_fffffff00a97ae84(*puVar8,puVar8[1],2,param_2);
  if (plVar1 == (long *)0x0) {
    thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
    return 0xe00002bc;
  }
  aplStack_178[0] = plVar1;
  plVar2 = thunk_FUN_fffffff00a97ae84(puVar8[2],puVar8[3],2,param_2);
  if (plVar2 == (long *)0x0) {
    thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
    plVar3 = (long *)0x0;
  }
  else {
    aplStack_178[2] = plVar2;
    plVar3 = thunk_FUN_fffffff00a97ae84(puVar8[4],puVar8[5],2,param_2);
    if (plVar3 != (long *)0x0) {
      uStack_160 = 1;
      uStack_158 = CONCAT44(uStack_158._4_4_,0x73626431);
      plStack_150 = plVar3;
      if (puVar8[7] == 0) {
        plVar4 = (long *)0x0;
      }
      else {
        plVar4 = thunk_FUN_fffffff00a97ae84(puVar8[6],puVar8[7],2,param_2);
        if (plVar4 == (long *)0x0) {
          uVar5 = 0xe00002bc;
          thunk_FUN_fffffff00a9029a0
                    ((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
          goto LAB_fffffff009270454;
        }
        uStack_148 = CONCAT44(uStack_148._4_4_,0x69636e66);
        uStack_160 = 2;
        aplStack_140[0] = plVar4;
      }
      uVar5 = (**(code **)(*param_1 + 0x550))(param_1,&uStack_180);
      goto LAB_fffffff009270454;
    }
    thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
  }
  uVar5 = 0xe00002bc;
  plVar4 = (long *)0x0;
LAB_fffffff009270454:
  (**(code **)(*plVar1 + 0x28))(plVar1);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  return uVar5;
}

