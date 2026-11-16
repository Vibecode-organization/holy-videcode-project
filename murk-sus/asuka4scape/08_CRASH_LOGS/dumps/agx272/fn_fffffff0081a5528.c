// FUN_fffffff0081a5528 @ fffffff0081a5528 size=600

undefined8 FUN_fffffff0081a5528(long *param_1,long *param_2,long *param_3,long *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  
  uVar1 = (**(code **)(*param_4 + 0xa8))(param_4);
  uVar2 = (**(code **)(*param_3 + 0xb8))(param_3,"target");
  if (((uVar2 & 1) == 0) && (iVar3 = (**(code **)(*param_3 + 0xb8))(param_3,"transfer"), iVar3 == 0)
     ) {
    uVar5 = 0xe00002c7;
  }
  else {
    (**(code **)(*param_1 + 0x6c0))(param_1,0,0);
    iVar3 = (**(code **)(*param_2 + 0xb8))(param_2,"power");
    if (iVar3 == 0) {
      iVar3 = (**(code **)(*param_2 + 0xb8))(param_2,"perf");
      if (iVar3 == 0) {
        uVar5 = 0xe00002c7;
      }
      else {
        if (uVar2 == 0) {
          if (uVar1 != 0) {
            if (uVar1 < 100) {
              return 0xe00002c2;
            }
            if ((uint)((int)param_1[0x16e] * 100) < uVar1) {
              return 0xe00002c2;
            }
          }
          *(uint *)(param_1[0x50] + 0x10f68) = uVar1;
          *(uint *)(param_1[0x69] + 0xac) = uVar1;
        }
        else {
          if (100 < uVar1) {
            return 0xe00002c2;
          }
          *(float *)(param_1[0x50] + 0x10f70) = (float)uVar1;
          *(uint *)(param_1[0x69] + 0xa4) = uVar1;
        }
        uVar5 = 0;
        *(undefined1 *)(param_1[0x123] + 0x5c8) = 1;
      }
    }
    else {
      lVar4 = param_1[0x50];
      if (uVar2 == 0) {
        if ((uVar1 == 0) ||
           ((uVar5 = 0xe00002c2, *(uint *)(lVar4 + 0x10ef0) <= uVar1 &&
            (uVar1 <= *(uint *)(lVar4 + 0x10ef4))))) {
          uVar5 = 0;
          *(uint *)(lVar4 + 0x10f0c) = uVar1;
          *(uint *)(param_1[0x69] + 0x94) = uVar1;
        }
      }
      else {
        uVar5 = 0;
        *(uint *)(lVar4 + 0x10efc) = uVar1;
        *(uint *)(param_1[0x69] + 0x90) = (*(int *)(lVar4 + 0x10eb0) * uVar1) / 100;
      }
    }
  }
  return uVar5;
}

