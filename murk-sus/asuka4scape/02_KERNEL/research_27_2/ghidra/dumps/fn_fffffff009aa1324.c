// FUN_fffffff009aa1324 @ fffffff009aa1324 size=312
// CALLERS:
//   fffffff00afb8175 no-fn
//   fffffff009aa207c FUN_fffffff009aa1fb4@fffffff009aa1fb4
// CALLEES:
//   fffffff009abd43c thunk_EXT_FUN_80110000039afad8
//   fffffff009abd46c thunk_EXT_FUN_801100000396cb64
//   fffffff009abd13c thunk_EXT_FUN_80110000038fe9a0

undefined8 FUN_fffffff009aa1324(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  bool bVar2;
  long *plVar3;
  long lVar4;
  char *pcVar5;
  long lVar6;
  long lVar7;
  
  lVar6 = 0;
  lVar7 = -0xc;
  do {
    if ((lVar7 == -9) && (*(long *)(param_1 + 0x3b8) == 0)) {
      plVar3 = (long *)thunk_EXT_FUN_80110000039afad8(0x1040);
      *(long **)(param_1 + 0x3b8) = plVar3;
      pcVar5 = "IOMFB ERROR: IOSharedDataQueue::withCapacity Failed\n";
      if (plVar3 == (long *)0x0) {
LAB_fffffff009aa140c:
        thunk_EXT_FUN_80110000038fe9a0(pcVar5);
        if (*(long **)(param_1 + 0x3b8) != (long *)0x0) {
          (**(code **)(**(long **)(param_1 + 0x3b8) + 0x28))();
        }
        *(undefined8 *)(param_1 + 0x3b8) = 0;
        return 0;
      }
      lVar4 = (**(code **)(*plVar3 + 0xa0))();
      if (lVar4 == 0) {
        pcVar5 = "IOMFB ERROR: ioDataQueue->getMemoryDescripto Failed\n";
        goto LAB_fffffff009aa140c;
      }
      lVar4 = thunk_EXT_FUN_801100000396cb64(lVar4,param_2,0,1,0,0);
      *(long *)(param_1 + 0x3c0) = lVar4;
      pcVar5 = "IOMFB ERROR: ioDataQueueMemDesc->createMappingInTask Failed\n";
      if (lVar4 == 0) goto LAB_fffffff009aa140c;
    }
    else {
      puVar1 = (undefined8 *)(param_1 + lVar6 * 0xb0 + 0x1a8);
      *puVar1 = 0;
      puVar1[1] = 0;
    }
    lVar6 = lVar6 + 1;
    bVar2 = lVar7 == -1;
    lVar7 = lVar7 + 1;
    if (bVar2) {
      return 1;
    }
  } while( true );
}

