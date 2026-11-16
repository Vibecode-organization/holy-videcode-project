// FUN_fffffff0081fb0f4 @ fffffff0081fb0f4 size=136

undefined8 FUN_fffffff0081fb0f4(long *param_1)

{
  undefined8 local_30;
  undefined8 uStack_28;
  
  (**(code **)(*param_1 + 0x98))();
  if (*(char *)((long)param_1 + 0x59) == '\x01') {
    local_30 = 0;
    uStack_28 = 0;
    (**(code **)(*(long *)param_1[4] + 0x140))((long *)param_1[4],&uStack_28,&local_30);
  }
  return 1;
}

