// FUN_fffffff009c265f8 @ fffffff009c265f8 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff009c26654) */

undefined8 FUN_fffffff009c265f8(long param_1)

{
  short sVar1;
  short sVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  undefined8 uVar7;
  long lVar8;
  long *plStack_80;
  long *plStack_78;
  long *plStack_70;
  long *plStack_68;
  undefined1 uStack_60;
  undefined1 uStack_5f;
  undefined1 uStack_5e;
  undefined1 uStack_5d;
  undefined8 uStack_5c;
  undefined4 uStack_54;
  undefined2 uStack_50;
  undefined2 uStack_4e;
  undefined4 uStack_4c;
  long lStack_48;
  
  lStack_48 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  lVar8 = *(long *)(param_1 + 0x178);
  sVar1 = *(short *)(lVar8 + 0x74);
  sVar2 = *(short *)(lVar8 + 0x76);
  if ((sVar1 == 0) && (sVar2 == 0)) {
    if ((((((*(short *)(lVar8 + 0x78) == 0) && (*(short *)(lVar8 + 0x7a) == 0)) &&
          (*(short *)(lVar8 + 0x7c) == 0)) &&
         ((*(short *)(lVar8 + 0x7e) == 0 && (*(short *)(lVar8 + 0x80) == 0)))) &&
        ((*(short *)(lVar8 + 0x82) == 0 &&
         ((*(int *)(lVar8 + 0x84) == 0 && (*(int *)(lVar8 + 0x88) == 0)))))) &&
       ((*(short *)(lVar8 + 0x8c) == 0 && (*(short *)(lVar8 + 0x8e) == 0)))) {
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
      uVar7 = 0;
      goto LAB_fffffff009c267b8;
    }
    uStack_5e = 0;
    uStack_5d = 0;
  }
  else {
    uStack_5e = (undefined1)sVar2;
    uStack_5d = (undefined1)((ushort)sVar2 >> 8);
  }
  uStack_60 = (undefined1)sVar1;
  uStack_5f = (undefined1)((ushort)sVar1 >> 8);
  uStack_5c = *(undefined8 *)(lVar8 + 0x78);
  uStack_54 = *(undefined4 *)(lVar8 + 0x80);
  uStack_50 = (undefined2)(*(uint *)(lVar8 + 0x84) / 10000);
  uStack_4c = *(undefined4 *)(lVar8 + 0x8c);
  uStack_4e = (undefined2)*(undefined4 *)(lVar8 + 0x88);
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  plVar3 = (long *)thunk_EXT_FUN_801100000389a264(&uStack_60,0x18);
  plVar4 = (long *)thunk_EXT_FUN_80110000038d02e4("CEA-861:Type1");
  plStack_70 = plVar4;
  plStack_68 = plVar3;
  plVar5 = (long *)thunk_EXT_FUN_80110000038d02e4("Type");
  plVar6 = (long *)thunk_EXT_FUN_80110000038d02e4("Data");
  plStack_80 = plVar5;
  plStack_78 = plVar6;
  uVar7 = thunk_EXT_FUN_801100000389d174(&plStack_70,&plStack_80,2,0);
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
LAB_fffffff009c267b8:
  if (*(long *)PTR_DAT_fffffff00806ca40 != lStack_48) {
    uVar7 = thunk_EXT_FUN_8011000003a48590();
    return uVar7;
  }
  return uVar7;
}

