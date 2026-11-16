// FUN_fffffff0081c9268 @ fffffff0081c9268 size=476

undefined8 FUN_fffffff0081c9268(long *param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  float fVar5;
  
  param_1[899] = param_2;
  fVar5 = (float)(**(code **)(*param_1 + 0x130))();
  if (fVar5 == 0.0) {
    uVar2 = 0;
  }
  else {
    lVar4 = param_1[0x58];
    uVar2 = (**(code **)(*(long *)param_1[0x50] + 0xad0))((long *)param_1[0x50],lVar4 + 0x5bc8);
    if ((int)uVar2 != 0) {
      iVar1 = (**(code **)(*(long *)param_1[0x50] + 0xae0))();
      if (iVar1 != 0) {
        lVar3 = param_1[0x69];
        *(undefined8 *)(lVar3 + 0x4f4) = *(undefined8 *)(lVar4 + 0x5fd4);
        *(undefined8 *)(lVar3 + 0x534) = *(undefined8 *)(lVar4 + 0x6014);
        *(undefined8 *)(lVar3 + 0x4fc) = *(undefined8 *)(lVar4 + 0x5fdc);
        *(undefined8 *)(lVar3 + 0x53c) = *(undefined8 *)(lVar4 + 0x601c);
        *(undefined8 *)(lVar3 + 0x504) = *(undefined8 *)(lVar4 + 0x5fe4);
        *(undefined8 *)(lVar3 + 0x544) = *(undefined8 *)(lVar4 + 0x6024);
        *(undefined8 *)(lVar3 + 0x50c) = *(undefined8 *)(lVar4 + 0x5fec);
        *(undefined8 *)(lVar3 + 0x54c) = *(undefined8 *)(lVar4 + 0x602c);
        *(undefined8 *)(lVar3 + 0x514) = *(undefined8 *)(lVar4 + 0x5ff4);
        *(undefined8 *)(lVar3 + 0x554) = *(undefined8 *)(lVar4 + 0x6034);
        *(undefined8 *)(lVar3 + 0x51c) = *(undefined8 *)(lVar4 + 0x5ffc);
        *(undefined8 *)(lVar3 + 0x55c) = *(undefined8 *)(lVar4 + 0x603c);
        *(undefined8 *)(lVar3 + 0x524) = *(undefined8 *)(lVar4 + 0x6004);
        *(undefined8 *)(lVar3 + 0x564) = *(undefined8 *)(lVar4 + 0x6044);
        *(undefined8 *)(lVar3 + 0x52c) = *(undefined8 *)(lVar4 + 0x600c);
        *(undefined8 *)(lVar3 + 0x56c) = *(undefined8 *)(lVar4 + 0x604c);
      }
      iVar1 = (**(code **)(*(long *)param_1[0x50] + 0xad8))();
      if (iVar1 != 0) {
        lVar3 = param_1[0x69];
        *(undefined8 *)(lVar3 + 0x474) = *(undefined8 *)(lVar4 + 0x5f54);
        *(undefined8 *)(lVar3 + 0x47c) = *(undefined8 *)(lVar4 + 0x5f5c);
        *(undefined8 *)(lVar3 + 0x484) = *(undefined8 *)(lVar4 + 0x5f64);
        *(undefined8 *)(lVar3 + 0x48c) = *(undefined8 *)(lVar4 + 0x5f6c);
      }
      (**(code **)(*param_1 + 0x2b8))(param_1,0xd);
      uVar2 = 1;
    }
  }
  return uVar2;
}

