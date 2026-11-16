// FUN_fffffff009976f64 @ fffffff009976f64 size=168

bool FUN_fffffff009976f64(long *param_1)

{
  bool bVar1;
  int iVar2;
  int local_24;
  
  if (param_1[0x91] == 0) {
    bVar1 = true;
  }
  else {
    local_24 = *(int *)((long)param_1 + 0x444);
    iVar2 = FUN_fffffff0099684a8
                      (param_1[0x91],&local_24,(long)param_1 + 0x43b,local_24,(int)param_1[0x89]);
    *(int *)((long)param_1 + 0x454) = (int)param_1[0x92];
    if (local_24 != *(int *)((long)param_1 + 0x44c)) {
      *(int *)((long)param_1 + 0x44c) = local_24;
      (**(code **)(*param_1 + 0xb0))(param_1);
    }
    bVar1 = iVar2 == 0;
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0xa4) = 6;
    }
  }
  return bVar1;
}

