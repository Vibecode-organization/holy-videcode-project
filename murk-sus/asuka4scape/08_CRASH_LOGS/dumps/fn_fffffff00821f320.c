// FUN_fffffff00821f320 @ fffffff00821f320 size=4
// CALLERS:
//   fffffff00afc19d6 no-fn
//   fffffff007caffd0 no-fn
// CALLEES:

ulong FUN_fffffff00821f320(long *param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  uint uVar2;
  long *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  undefined8 *puVar9;
  ulong uVar10;
  long *plStack_80;
  long *plStack_78;
  long *plStack_70;
  uint uStack_64;
  long lStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  
  uStack_58 = 0;
  lStack_60 = 0;
  uStack_48 = 0;
  uStack_50 = 0;
  uStack_64 = 0;
  plStack_78 = (long *)0x0;
  plStack_70 = (long *)0x0;
  plStack_80 = (long *)0x0;
  plVar3 = thunk_FUN_fffffff00a894f30(param_1,-0xff51d6e70);
  if (plVar3 == (long *)0x0) {
    uVar6 = 0xe00002bc;
  }
  else if ((((param_3 == 0) || (*(int *)(param_3 + 0x50) != 5)) || (*(int *)(param_3 + 0x28) != 0xb)
           ) || (*(long *)(param_3 + 0x30) == 0)) {
    uVar6 = 0xe00002c2;
  }
  else {
    uVar6 = 0xe00002c2;
    if (*(long *)(param_3 + 0x58) != 0) {
      uStack_58 = CONCAT44(uStack_58._4_4_,*(undefined4 *)(param_3 + 0x38));
      uStack_50 = *(undefined8 *)(param_3 + 0x20);
      uStack_48 = CONCAT44(uStack_48._4_4_,0xb);
      lStack_60 = *(long *)(param_3 + 0x30);
      uVar6 = (**(code **)(*plVar3 + 0x5d8))(plVar3,&plStack_70,&plStack_78,&plStack_80,&lStack_60);
      if ((((int)uVar6 == 0) && (uVar6 = 0xffff9682, plStack_70 != (long *)0x0)) &&
         (plStack_78 != (long *)0x0)) {
        uVar1 = (**(code **)(*plStack_70 + 0xa0))();
        uVar6 = 0xe00002db;
        if (uVar1 <= *(uint *)(param_3 + 0x60)) {
          puVar9 = *(undefined8 **)(param_3 + 0x58);
          puVar4 = (undefined8 *)(**(code **)(*plStack_70 + 0xd8))();
          uVar8 = (ulong)uVar1;
          thunk_FUN_fffffff00aa65b10(puVar9,puVar4,uVar8);
          **(ulong **)(param_3 + 0x48) = uVar8;
          uVar2 = (**(code **)(*plStack_78 + 0xa0))();
          uVar10 = (ulong)uVar2;
          if (uVar10 + uVar1 <= (ulong)*(uint *)(param_3 + 0x60)) {
            lVar7 = *(long *)(param_3 + 0x58);
            puVar4 = (undefined8 *)(**(code **)(*plStack_78 + 0xd8))();
            uVar5 = thunk_FUN_fffffff00aa65b10((undefined8 *)(lVar7 + uVar8),puVar4,uVar10);
            lVar7 = *(long *)(param_3 + 0x48);
            *(ulong *)(lVar7 + 8) = uVar10;
            uStack_64 = uVar2 + uVar1;
            *(undefined8 *)(lVar7 + 0x20) = 0;
            uVar1 = FUN_fffffff00821f880
                              (uVar5,plStack_80,(ulong *)(lVar7 + 0x10),*(long *)(param_3 + 0x58),
                               &uStack_64,*(uint *)(param_3 + 0x60));
            uVar6 = (ulong)uVar1;
          }
        }
      }
    }
  }
  if (plStack_70 != (long *)0x0) {
    (**(code **)(*plStack_70 + 0x28))();
  }
  plStack_70 = (long *)0x0;
  if (plStack_78 != (long *)0x0) {
    (**(code **)(*plStack_78 + 0x28))();
  }
  plStack_78 = (long *)0x0;
  if (plStack_80 != (long *)0x0) {
    (**(code **)(*plStack_80 + 0x28))();
  }
  return uVar6;
}

