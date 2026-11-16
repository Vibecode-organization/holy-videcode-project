// FUN_fffffff009cfbda8 @ fffffff009cfbda8

undefined8 FUN_fffffff009cfbda8(long param_1)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20);
  lVar1 = (**(code **)(**(long **)(lVar3 + 0xb8) + 0x118))
                    (*(long **)(lVar3 + 0xb8),"usb-device-slp-ddr");
  if ((lVar1 != **(long **)PTR_PTR_fffffff008089d58) && ((*(byte *)(lVar3 + 0x2691) & 1) == 0)) {
    plVar2 = *(long **)(lVar3 + 0x26c8);
    if ((plVar2 != (long *)0x0) && ((*(byte *)(lVar3 + 0x26f8) & 1) != 0)) {
      (**(code **)(*plVar2 + 0x568))(plVar2,0);
    }
    *(undefined1 *)(lVar3 + 0x26f8) = 0;
    *(undefined1 *)(lVar3 + 0x26fa) = 1;
    plVar2 = *(long **)(lVar3 + 0x26d0);
    if ((plVar2 != (long *)0x0) && ((*(byte *)(lVar3 + 0x26f9) & 1) != 0)) {
      (**(code **)(*plVar2 + 0x568))(plVar2,0);
    }
    *(undefined1 *)(lVar3 + 0x26f9) = 0;
    *(undefined1 *)(lVar3 + 0x26fb) = 1;
  }
  return 0;
}

