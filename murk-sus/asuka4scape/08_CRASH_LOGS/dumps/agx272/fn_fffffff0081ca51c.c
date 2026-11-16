// FUN_fffffff0081ca51c @ fffffff0081ca51c size=4

/* WARNING: Removing unreachable block (ram,0xfffffff0081ca664) */

void FUN_fffffff0081ca51c(long param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  long *plVar5;
  undefined8 uVar6;
  undefined1 uStack_51;
  
  if (param_2 == 0) {
    thunk_EXT_FUN_801100000389060c(*(long *)(param_1 + 0x348) + 0x7c);
  }
  else {
    thunk_EXT_FUN_80110000038905fc();
    thunk_EXT_FUN_80110000038905fc(*(long *)(param_1 + 0x348) + 0x80);
    if (((param_3 == 2) ||
        (iVar2 = thunk_EXT_FUN_80110000029477a8(*(undefined8 *)(*(long *)(param_1 + 0x280) + 0x148))
        , iVar2 == 0)) || (*(int *)(*(long *)(param_1 + 0x918) + 0x68c) == 0)) {
      if ((*(byte *)(*(long *)(param_1 + 0x280) + 0x65d) & 1) != 0) {
        uStack_51 = 1;
        plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
        puVar4 = (undefined8 *)(*plVar5 + 0xe8);
        (*(code *)*puVar4)(puVar4,plVar5,FUN_fffffff00817db18,&uStack_51,0,0,0);
      }
    }
    else {
      iVar2 = thunk_EXT_FUN_801100000389062c(1,*(long *)(param_1 + 0x918) + 0x690);
      if (iVar2 == 0) {
        plVar5 = *(long **)(param_1 + 0x280);
        thunk_EXT_FUN_80110000032222a8(plVar5[0x234c]);
        (**(code **)(*plVar5 + 0x710))(plVar5,"",0);
        plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
        puVar4 = (undefined8 *)(*plVar5 + 0xe8);
        uVar6 = 1;
        (*(code *)*puVar4)(puVar4,plVar5,FUN_fffffff00817dfe8,4,1,0,0);
        plVar5 = *(long **)(param_1 + 0x280);
        (**(code **)(*plVar5 + 0x718))(*plVar5 + 0x718,plVar5,"",0);
        thunk_EXT_FUN_8011000003222de0(plVar5[0x234c]);
        goto LAB_fffffff0081ca704;
      }
    }
  }
  uVar6 = 0;
LAB_fffffff0081ca704:
  lVar3 = *(long *)(param_1 + 0x280);
  if ((*(byte *)(lVar3 + 0x1ac44) >> 3 & 1) != 0) {
    uVar1 = *(undefined4 *)(*(long *)(param_1 + 0x348) + 0x7c);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar3 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930cb8,param_2,param_3,uVar6,uVar1,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0x1ac48));
  }
  return;
}

