// FUN_fffffff009c8bb44 @ fffffff009c8bb44

/* WARNING: Removing unreachable block (ram,0xfffffff009c8bc3c) */

undefined8 FUN_fffffff009c8bb44(long *param_1,undefined8 param_2,long param_3)

{
  ulong uVar1;
  ulong uVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  ulong uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  ulong *puVar9;
  code *pcVar10;
  ulong uVar11;
  long **pplVar12;
  undefined8 **ppuVar13;
  long *local_80;
  undefined1 *puStack_78;
  undefined8 *local_70;
  ulong local_68;
  
  puVar9 = *(ulong **)(param_3 + 0x20);
  uVar6 = puVar9[1];
  uVar1 = puVar9[2];
  if (param_1 != (long *)0x0) {
    uVar2 = puVar9[3];
    local_80 = (long *)&DAT_aaaaaaaaaaaaaaaa;
    puStack_78 = &DAT_aaaaaaaaaaaaaaaa;
    local_70 = (undefined8 *)&DAT_aaaaaaaaaaaaaaaa;
    uVar11 = *puVar9;
    if (uVar11 >> 0x20 == 0) {
      local_68 = uVar1;
      thunk_FUN_fffffff00a2262a8(param_1[0x20]);
      plVar3 = (long *)(**(code **)(*(long *)param_1[0x1f] + 0x118))((long *)param_1[0x1f],uVar11);
      plVar3 = thunk_FUN_fffffff00a894f30(plVar3,(long)PTR_DAT_fffffff00807c5a8);
      if (plVar3 == (long *)0x0) {
        thunk_FUN_fffffff00a226de0(param_1[0x20]);
      }
      else {
        (**(code **)(*plVar3 + 0x20))();
        thunk_FUN_fffffff00a226de0(param_1[0x20]);
        plVar4 = (long *)(**(code **)(*param_1 + 0x6a0))(*param_1 + 0x6a0,param_1,uVar6);
        if (plVar4 == (long *)0x0) {
          pcVar10 = *(code **)(*plVar3 + 0x28);
        }
        else {
          plVar5 = (long *)(**(code **)(*plVar4 + 0x98))();
          if (plVar5 == (long *)0x0) {
            (**(code **)(*plVar3 + 0x28))(plVar3);
            (**(code **)(*plVar4 + 0x28))(plVar4);
            return 0xe00002bd;
          }
          uVar6 = (**(code **)(*plVar5 + 0xb0))();
          if ((uVar1 <= uVar6) && (*(uint *)(param_3 + 0x18) < 9)) {
            (**(code **)(*plVar5 + 0x20))(plVar5);
            (**(code **)(*plVar4 + 0x28))(plVar4);
            if (*(long *)(param_3 + 8) == 0) {
              pplVar12 = (long **)0x0;
              ppuVar13 = (undefined8 **)&DAT_00000010;
            }
            else {
              ppuVar13 = &local_70;
              puVar7 = (undefined8 *)thunk_FUN_fffffff00a902074((long *)&DAT_fffffff00807f138);
              puVar7[8] = plVar5;
              puVar7[9] = uVar1;
              puVar7[10] = plVar3;
              if (*(undefined8 **)(param_3 + 0x10) != (undefined8 *)0x0) {
                thunk_FUN_fffffff00aa65b10
                          (puVar7,*(undefined8 **)(param_3 + 0x10),
                           (ulong)*(uint *)(param_3 + 0x18) << 3);
              }
              puStack_78 = &LAB_fffffff009c8f4b4;
              pplVar12 = &local_80;
              local_80 = param_1;
              local_70 = puVar7;
            }
            uVar8 = (**(code **)(*param_1 + 0x648))
                              (param_1,plVar3,plVar5,&local_68,pplVar12,(int)uVar2);
            if ((pplVar12 == (long **)0x0) || ((int)uVar8 != 0)) {
              (**(code **)(*plVar3 + 0x28))(plVar3);
              (**(code **)(*plVar5 + 0x28))(plVar5);
              if ((pplVar12 != (long **)0x0) && (puVar7 = *ppuVar13, puVar7 != (undefined8 *)0x0)) {
                *ppuVar13 = (undefined8 *)0x0;
                thunk_FUN_fffffff00a22170c((long *)&DAT_fffffff00807f178,puVar7);
              }
            }
            **(ulong **)(param_3 + 0x48) = local_68;
            return uVar8;
          }
          (**(code **)(*plVar3 + 0x28))(plVar3);
          pcVar10 = *(code **)(*plVar4 + 0x28);
          plVar3 = plVar4;
        }
        (*pcVar10)(plVar3);
      }
    }
  }
  return 0xe00002c2;
}

