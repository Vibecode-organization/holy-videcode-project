// FUN_fffffff008200008 @ fffffff008200008 size=500

undefined8 FUN_fffffff008200008(long param_1,int param_2,uint *param_3)

{
  undefined1 uVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  int iVar7;
  
  uVar6 = 0xe00002c0;
  iVar2 = thunk_EXT_FUN_8011000002960e38(param_1,"com.apple.agx.gpurole");
  if (iVar2 == 0) {
    uVar6 = 0xe00002c1;
  }
  else {
    plVar3 = (long *)thunk_EXT_FUN_8011000002940a54
                               (*(undefined8 *)(*(long *)(param_1 + 0x48) + 0x1c8));
    if (plVar3 == (long *)0x0) {
      uVar6 = 0xe00002bd;
    }
    else {
      iVar2 = (**(code **)(*plVar3 + 0x90))();
      lVar4 = *(long *)(param_1 + 0x48);
      if ((*(byte *)(lVar4 + 0x1ac44) >> 5 & 1) != 0) {
        uVar1 = *(undefined1 *)(param_1 + 0x120);
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar4 + 0x1ac48));
        thunk_EXT_FUN_80110000036da494(0x85951490,(long)param_2,uVar1,iVar2,0,0);
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar4 + 0x1ac48));
      }
      if (iVar2 != 0) {
        iVar7 = 0;
        do {
          lVar4 = (**(code **)(*plVar3 + 0x118))(plVar3,iVar7);
          if ((lVar4 != 0) && (param_2 == *(int *)(lVar4 + 0x60))) {
            lVar5 = *(long *)(param_1 + 0x48);
            if ((*(byte *)(lVar5 + 0x1ac44) >> 5 & 1) != 0) {
              thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x1ac48));
              thunk_EXT_FUN_80110000036da494(0x85951494,(long)param_2,lVar4,0,0,0);
              thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x1ac48));
            }
            if ((byte)(*(char *)(lVar4 + 0x120) - 1U) < 4) {
              uVar6 = 0;
              *param_3 = (uint)(byte)(4 - *(char *)(lVar4 + 0x120));
            }
            else {
              uVar6 = 0xe00002bc;
            }
            break;
          }
          iVar7 = iVar7 + 1;
        } while (iVar2 != iVar7);
      }
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
  }
  return uVar6;
}

