// FUN_fffffff00817f5cc @ fffffff00817f5cc size=172

undefined8 FUN_fffffff00817f5cc(long param_1)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  
  lVar2 = *(long *)(param_1 + 0x20);
  if (*(long *)(lVar2 + 0x1ac98) == 0) {
    (**(code **)(**(long **)(lVar2 + 0x1ac90) + 0x130))
              (*(long **)(lVar2 + 0x1ac90),*(undefined8 *)(*(long *)(param_1 + 0x28) + 0x58));
  }
  *(undefined8 *)(*(long *)(param_1 + 0x28) + 0x60) = 0;
  plVar3 = *(long **)(lVar2 + 0x1aca0);
  plVar1 = *(long **)(param_1 + 0x28);
  plVar1[0xd] = (long)plVar3;
  *plVar3 = (long)plVar1;
  *(long **)(lVar2 + 0x1aca0) = plVar1 + 0xc;
  *(undefined1 *)(plVar1 + 0xe) = 1;
  (**(code **)(*plVar1 + 0x20))();
  return 0;
}

