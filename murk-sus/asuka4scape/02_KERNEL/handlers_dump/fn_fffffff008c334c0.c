// FUN_fffffff008c334c0 @ fffffff008c334c0 size=4 depth=1
// CALLERS:
//   fffffff00afd0465 ?
//   fffffff008c334b0 FUN_fffffff008c33490
// CALLS:

/* WARNING: Removing unreachable block (ram,0xfffffff008c335e8) */
/* WARNING: Removing unreachable block (ram,0xfffffff008c335a8) */

undefined8
FUN_fffffff008c334c0
          (long param_1,long *param_2,undefined8 param_3,undefined8 param_4,undefined8 *param_5)

{
  undefined8 *puVar1;
  long *plVar2;
  undefined8 uVar3;
  long *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  long *plStack_58;
  code *pcStack_50;
  undefined8 uStack_48;
  
  uVar3 = 0xe00002bd;
  if (*(long *)(param_1 + 0xe8) == 0) {
    puVar1 = (undefined8 *)thunk_FUN_fffffff00a902074((long *)&DAT_fffffff007e136d8);
    *(undefined8 **)(param_1 + 0xe8) = puVar1;
    if (puVar1 != (undefined8 *)0x0) {
      uVar5 = param_5[1];
      uVar3 = *param_5;
      uVar7 = param_5[3];
      uVar6 = param_5[2];
      uVar8 = param_5[4];
      uVar10 = param_5[7];
      uVar9 = param_5[6];
      puVar1[5] = param_5[5];
      puVar1[4] = uVar8;
      puVar1[7] = uVar10;
      puVar1[6] = uVar9;
      puVar1[1] = uVar5;
      *puVar1 = uVar3;
      puVar1[3] = uVar7;
      puVar1[2] = uVar6;
      (**(code **)(*param_2 + 0x20))(param_2);
      uVar3 = *(undefined8 *)(param_1 + 0xe0);
      uStack_48 = *(undefined8 *)(param_1 + 0xe8);
      pcStack_50 = FUN_fffffff008c33654;
      plVar4 = *(long **)(param_1 + 0xd8);
      plStack_58 = param_2;
      plVar2 = (long *)(**(code **)(*plVar4 + 0x378))(*plVar4 + 0x378,plVar4);
      uVar3 = (**(code **)(*plVar2 + 0x100))
                        (*plVar2 + 0x100,plVar2,plVar4[0x42],plVar4,param_3,param_4,&plStack_58,
                         uVar3);
      if ((int)uVar3 != 0) {
        puVar1 = *(undefined8 **)(param_1 + 0xe8);
        *(undefined8 *)(param_1 + 0xe8) = 0;
        thunk_FUN_fffffff00a22170c((long *)&DAT_fffffff007e13718,puVar1);
        (**(code **)(*param_2 + 0x28))(param_2);
      }
    }
  }
  else {
    uVar3 = 0xe00002c5;
  }
  return uVar3;
}

