// FUN_fffffff008214518 @ fffffff008214518 size=324

/* WARNING: Removing unreachable block (ram,0xfffffff0082145a8) */

undefined8 FUN_fffffff008214518(long param_1,undefined8 param_2)

{
  long *plVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  plVar1 = (long *)(**(code **)(**(long **)(param_1 + 0xc0) + 0x838))();
  *(long **)(param_1 + 0x218) = plVar1;
  if (plVar1 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to create GTP channel\n");
    uVar3 = 0;
  }
  else {
    thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(param_1 + 0x18),&DAT_fffffff00ae21f50);
    uVar2 = (**(code **)(*plVar1 + 0x178))
                      (*plVar1 + 0x178,plVar1,*(undefined8 *)(param_1 + 0x18),param_1,
                       *(undefined4 *)(param_1 + 0xe8),*(undefined4 *)(param_1 + 0x54),param_2);
    if ((uVar2 & 1) == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to init GTP channel\n");
      if (*(long **)(param_1 + 0x218) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x218) + 0x28))();
      }
      uVar3 = 0;
      *(undefined8 *)(param_1 + 0x218) = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}

