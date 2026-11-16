// FUN_fffffff009c265f8 @ fffffff009c265f8

/* WARNING: Removing unreachable block (ram,0xfffffff009c26654) */

long * FUN_fffffff009c265f8(long param_1)

{
  short sVar1;
  short sVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long lVar8;
  long *local_80;
  long *plStack_78;
  long *local_70;
  long *plStack_68;
  undefined1 local_60;
  undefined1 local_5f;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined8 local_5c;
  undefined4 local_54;
  undefined2 local_50;
  undefined2 local_4e;
  undefined4 local_4c;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_FUN_fffffff00a2262a8(*(ulong *)(param_1 + 0x50));
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
      thunk_FUN_fffffff00a226de0(*(ulong *)(param_1 + 0x50));
      plVar7 = (long *)0x0;
      goto LAB_fffffff009c267b8;
    }
    local_5e = 0;
    local_5d = 0;
  }
  else {
    local_5e = (undefined1)sVar2;
    local_5d = (undefined1)((ushort)sVar2 >> 8);
  }
  local_60 = (undefined1)sVar1;
  local_5f = (undefined1)((ushort)sVar1 >> 8);
  local_5c = *(undefined8 *)(lVar8 + 0x78);
  local_54 = *(undefined4 *)(lVar8 + 0x80);
  local_50 = (undefined2)(*(uint *)(lVar8 + 0x84) / 10000);
  local_4c = *(undefined4 *)(lVar8 + 0x8c);
  local_4e = (undefined2)*(undefined4 *)(lVar8 + 0x88);
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_1 + 0x50));
  plVar3 = thunk_FUN_fffffff00a89e264(&local_60,0x18);
  plVar4 = thunk_FUN_fffffff00a8d42e4((byte *)"CEA-861:Type1");
  local_70 = plVar4;
  plStack_68 = plVar3;
  plVar5 = thunk_FUN_fffffff00a8d42e4(&DAT_fffffff00789bea9);
  plVar6 = thunk_FUN_fffffff00a8d42e4(&DAT_fffffff00789beae);
  local_80 = plVar5;
  plStack_78 = plVar6;
  plVar7 = thunk_FUN_fffffff00a8a1174(&local_70,&local_80,2,0);
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
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_48) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return plVar7;
}

