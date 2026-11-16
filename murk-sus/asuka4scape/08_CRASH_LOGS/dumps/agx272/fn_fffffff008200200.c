// FUN_fffffff008200200 @ fffffff008200200 size=1284

ulong FUN_fffffff008200200(long param_1,int param_2,uint param_3)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  long *plVar4;
  long *plVar5;
  ulong uVar6;
  long *plVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  int iVar13;
  undefined8 uVar14;
  undefined4 local_a8;
  int iStack_a4;
  char local_a0;
  undefined2 uStack_9f;
  undefined1 uStack_9d;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 local_64;
  
  iVar3 = thunk_EXT_FUN_8011000002960e38(param_1,"com.apple.agx.gpurole");
  if (iVar3 == 0) {
    return 0xe00002c1;
  }
  if (3 < param_3) {
    return 0xe00002c2;
  }
  plVar4 = (long *)thunk_EXT_FUN_8011000002940a54
                             (*(undefined8 *)(*(long *)(param_1 + 0x48) + 0x1c8));
  if (plVar4 == (long *)0x0) {
    return 0xe00002bd;
  }
  iVar3 = (**(code **)(*plVar4 + 0x90))();
  lVar8 = *(long *)(param_1 + 0x48);
  if ((*(byte *)(lVar8 + 0x1ac44) >> 5 & 1) != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar8 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85951490,(long)param_2,param_3,iVar3,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar8 + 0x1ac48));
  }
  if (iVar3 != 0) {
    iVar13 = 0;
    cVar2 = '\x04' - (char)param_3;
    do {
      lVar8 = (**(code **)(*plVar4 + 0x118))(plVar4,iVar13);
      if ((lVar8 != 0) && (param_2 == *(int *)(lVar8 + 0x60))) {
        if ((*(byte *)(*(long *)(param_1 + 0x48) + 0x1ac44) >> 5 & 1) != 0) {
          FUN_fffffff00817dc48(*(long *)(param_1 + 0x48),0x525,0,(long)param_2,lVar8,0,0,0);
        }
        *(char *)(lVar8 + 0x120) = cVar2;
        plVar5 = (long *)thunk_EXT_FUN_8011000002940a54(*(undefined8 *)(lVar8 + 0x88));
        if (plVar5 == (long *)0x0) {
          uVar1 = 0;
          if (*(int *)(*(long *)(lVar8 + 0x88) + 0x30) != 0) {
            uVar1 = 0xe00002bd;
          }
          (**(code **)(*plVar4 + 0x28))(plVar4);
          return (ulong)uVar1;
        }
        iVar3 = (**(code **)(*plVar5 + 0x90))();
        if (iVar3 == 0) goto LAB_fffffff00820066c;
        iVar13 = 0;
        goto LAB_fffffff00820044c;
      }
      iVar13 = iVar13 + 1;
    } while (iVar3 != iVar13);
  }
  (**(code **)(*plVar4 + 0x28))(plVar4);
  return 0xe00002c0;
LAB_fffffff00820044c:
  lVar8 = (**(code **)(*plVar5 + 0x118))(plVar5,iVar13);
  if (lVar8 != 0) {
    thunk_EXT_FUN_80110000029728f4();
    uVar6 = thunk_EXT_FUN_80110000029474ec
                      (*(undefined8 *)(*(long *)(lVar8 + 0x530) + 0x148),lVar8 + 0x498);
    if ((uVar6 & 1) == 0) {
      lVar9 = *(long *)(param_1 + 0x48);
      if ((*(byte *)(lVar9 + 0x1ac44) >> 5 & 1) != 0) {
        uVar12 = *(undefined8 *)(*(long *)(lVar8 + 0x610) + 200);
        uVar14 = *(undefined8 *)(*(long *)(lVar8 + 0x610) + 0xe0);
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar9 + 0x1ac48));
        thunk_EXT_FUN_80110000036da494(0x85951498,lVar8,uVar12,uVar14,0,0);
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar9 + 0x1ac48));
        lVar9 = *(long *)(param_1 + 0x48);
      }
      local_70 = 0;
      uStack_78 = 0;
      local_80 = 0;
      uStack_88 = 0;
      local_90 = 0;
      uStack_94 = 0;
      uStack_9d = 0;
      local_a8 = 0x1f;
      uStack_9f = **(undefined2 **)(*(long *)(lVar8 + 0x610) + 200);
      uVar12 = *(undefined8 *)(*(long *)(lVar8 + 0x610) + 0xe0);
      uStack_9c = (undefined4)uVar12;
      uStack_98 = (undefined4)((ulong)uVar12 >> 0x20);
      lVar9 = *(long *)(lVar9 + 0x4b0);
      local_64 = 1;
      iStack_a4 = param_2;
      local_a0 = cVar2;
      uVar12 = (**(code **)(*(long *)(lVar9 + 0x848) + 0x30))(lVar9 + 0x848);
      local_68 = 0;
      plVar7 = *(long **)(*(long *)(lVar9 + 0x280) + 0x310);
      puVar11 = (undefined8 *)(*plVar7 + 0xe8);
      uVar6 = (*(code *)*puVar11)(puVar11,plVar7,FUN_fffffff00817ea94,&local_a8,&local_64,&local_68,
                                  0);
      if (((int)uVar6 != 0) ||
         ((((byte)local_64 >> 1 & 1) != 0 &&
          (uVar6 = FUN_fffffff0081a43cc(lVar9,uVar12,local_68), (int)uVar6 != 0)))) {
        thunk_EXT_FUN_8011000002972900(lVar8);
        (**(code **)(*plVar4 + 0x28))(plVar4);
        goto LAB_fffffff0082006e8;
      }
    }
    else {
      lVar9 = *(long *)(lVar8 + 0x610);
      lVar10 = *(long *)(param_1 + 0x48);
      if (lVar9 == 0) {
        if ((*(uint *)(lVar10 + 0x1ac44) >> 5 & 1) != 0) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar10 + 0x1ac48));
          thunk_EXT_FUN_80110000036da494(0x8595149c,0,0,0,0,0);
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar10 + 0x1ac48));
        }
      }
      else {
        if ((*(uint *)(lVar10 + 0x1ac44) >> 5 & 1) != 0) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar10 + 0x1ac48));
          thunk_EXT_FUN_80110000036da494(0x8595149c,0,0,0,0,0);
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar10 + 0x1ac48));
          lVar9 = *(long *)(lVar8 + 0x610);
        }
        lVar9 = *(long *)(lVar9 + 200);
        *(undefined4 *)(lVar9 + 0x22) = 1;
        *(char *)(lVar9 + 0x26) = cVar2;
      }
    }
    thunk_EXT_FUN_8011000002972900(lVar8);
  }
  iVar13 = iVar13 + 1;
  if (iVar3 == iVar13) {
LAB_fffffff00820066c:
    (**(code **)(*plVar4 + 0x28))(plVar4);
    uVar6 = 0;
LAB_fffffff0082006e8:
    (**(code **)(*plVar5 + 0x28))(plVar5);
    return uVar6;
  }
  goto LAB_fffffff00820044c;
}

