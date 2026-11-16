// FUN_fffffff00817d0fc @ fffffff00817d0fc size=4

/* WARNING: Removing unreachable block (ram,0xfffffff00817d1dc) */

void FUN_fffffff00817d0fc(long param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uStack_28;
  
  uVar2 = (**(code **)(**(long **)(param_1 + 0x4b0) + 0xf8))();
  if (((uVar2 & 1) != 0) ||
     (uVar2 = thunk_EXT_FUN_801100000294780c(*(undefined8 *)(param_1 + 0x148)), (uVar2 & 1) == 0)) {
    *(undefined1 *)(param_1 + 0x579) = 1;
    *(undefined1 *)(param_1 + 0x540) = 1;
    (**(code **)(**(long **)(param_1 + 0x538) + 0xb0))();
    (**(code **)(**(long **)(param_1 + 0x538) + 0xf0))
              (*(long **)(param_1 + 0x538),*(undefined1 *)(param_1 + 0x66c));
    uStack_28 = 0;
    thunk_EXT_FUN_8011000003204ed8((ulong)*(byte *)(param_1 + 0x66c) << 1,1000000,&uStack_28);
    lVar3 = **(long **)(param_1 + 0x310);
    iVar1 = (**(code **)(lVar3 + 0x110))
                      (lVar3 + 0x110,*(long **)(param_1 + 0x310),param_1 + 0x579,uStack_28,0);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 0x540) = 0;
      (**(code **)(**(long **)(param_1 + 0x538) + 0x138))();
    }
  }
  return;
}

