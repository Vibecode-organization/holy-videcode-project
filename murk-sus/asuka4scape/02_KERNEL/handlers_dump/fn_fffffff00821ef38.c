// FUN_fffffff00821ef38 @ fffffff00821ef38 size=4 depth=0
// CALLERS:
//   fffffff00afc19d1 ?
//   fffffff007caff88 ?
// CALLS:

ulong FUN_fffffff00821ef38(long *param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  long *plVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  ulong *puVar7;
  ulong uVar8;
  undefined8 *puVar9;
  long lVar10;
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
  plStack_78 = (long *)0x0;
  plStack_70 = (long *)0x0;
  plStack_80 = (long *)0x0;
  plVar4 = thunk_FUN_fffffff00a894f30(param_1,-0xff51d6e70);
  if (plVar4 == (long *)0x0) {
    uVar8 = 0xe00002bc;
  }
  else if ((((param_3 == 0) || (*(int *)(param_3 + 0x50) != 5)) || (*(int *)(param_3 + 0x28) != 0xb)
           ) || (*(long *)(param_3 + 0x30) == 0)) {
    uVar8 = 0xe00002c2;
  }
  else {
    uVar8 = 0xe00002c2;
    if (*(long *)(param_3 + 0x58) != 0) {
      uStack_58 = CONCAT44(uStack_58._4_4_,*(undefined4 *)(param_3 + 0x38));
      uStack_50 = *(undefined8 *)(param_3 + 0x20);
      uStack_48 = CONCAT44(uStack_48._4_4_,0xb);
      lStack_60 = *(long *)(param_3 + 0x30);
      uVar8 = (**(code **)(*plVar4 + 0x5d0))(plVar4,&plStack_70,&plStack_78,&plStack_80,&lStack_60);
      iVar1 = (int)uVar8;
      if (iVar1 == -0x7925) {
        if (plStack_70 == (long *)0x0) {
          uVar8 = 0xffff9682;
          goto LAB_fffffff00821f058;
        }
      }
      else if (iVar1 != 0) goto LAB_fffffff00821f034;
      uVar2 = (**(code **)(*plStack_70 + 0xa0))();
      if (*(uint *)(param_3 + 0x60) < uVar2) {
LAB_fffffff00821f0f4:
        uVar8 = 0xe00002db;
      }
      else {
        puVar9 = *(undefined8 **)(param_3 + 0x58);
        puVar5 = (undefined8 *)(**(code **)(*plStack_70 + 0xd8))();
        uVar8 = (ulong)uVar2;
        uVar6 = thunk_FUN_fffffff00aa65b10(puVar9,puVar5,uVar8);
        puVar7 = *(ulong **)(param_3 + 0x48);
        *puVar7 = uVar8;
        uStack_64 = uVar2;
        if (iVar1 == -0x7925) {
          puVar7[1] = 0;
          uVar8 = 0xffffffffffff86db;
        }
        else {
          uVar3 = (**(code **)(*plStack_78 + 0xa0))();
          if ((ulong)*(uint *)(param_3 + 0x60) < uVar8 + uVar3) goto LAB_fffffff00821f0f4;
          lVar10 = *(long *)(param_3 + 0x58);
          puVar5 = (undefined8 *)(**(code **)(*plStack_78 + 0xd8))();
          uVar6 = thunk_FUN_fffffff00aa65b10((undefined8 *)(lVar10 + uVar8),puVar5,(ulong)uVar3);
          uVar8 = 0;
          puVar7 = *(ulong **)(param_3 + 0x48);
          puVar7[1] = (ulong)uVar3;
          uStack_64 = uVar3 + uVar2;
        }
        puVar7[4] = uVar8;
        uVar2 = FUN_fffffff00821f880
                          (uVar6,plStack_80,puVar7 + 2,*(long *)(param_3 + 0x58),&uStack_64,
                           *(uint *)(param_3 + 0x60));
        uVar8 = (ulong)uVar2;
      }
    }
  }
LAB_fffffff00821f034:
  if (plStack_70 != (long *)0x0) {
    (**(code **)(*plStack_70 + 0x28))();
  }
LAB_fffffff00821f058:
  plStack_70 = (long *)0x0;
  if (plStack_78 != (long *)0x0) {
    (**(code **)(*plStack_78 + 0x28))();
  }
  plStack_78 = (long *)0x0;
  if (plStack_80 != (long *)0x0) {
    (**(code **)(*plStack_80 + 0x28))();
  }
  return uVar8;
}

