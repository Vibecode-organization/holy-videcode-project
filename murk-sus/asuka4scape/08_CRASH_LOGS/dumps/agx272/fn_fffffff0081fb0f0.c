// FUN_fffffff0081fb0f0 @ fffffff0081fb0f0 size=4

undefined8 FUN_fffffff0081fb0f0(long *param_1)

{
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  (**(code **)(*param_1 + 0x98))();
  if (*(char *)((long)param_1 + 0x59) == '\x01') {
    uStack_30 = 0;
    uStack_28 = 0;
    (**(code **)(*(long *)param_1[4] + 0x140))((long *)param_1[4],&uStack_28,&uStack_30);
  }
  return 1;
}

