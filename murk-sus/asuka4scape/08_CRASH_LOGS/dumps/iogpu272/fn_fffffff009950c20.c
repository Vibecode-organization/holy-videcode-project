// FUN_fffffff009950c20 @ fffffff009950c20 size=196

void FUN_fffffff009950c20(long param_1,long *param_2,ulong param_3,ulong param_4)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  lVar3 = *param_2;
  while( true ) {
    do {
      lVar1 = lVar3;
      if (lVar1 == 0) {
        return;
      }
      lVar3 = *(long *)(lVar1 + 0xb0);
      uVar2 = FUN_fffffff00994b9f8(*(undefined8 *)(param_1 + 0x18),lVar1 + 0x70);
    } while ((uVar2 & 1) != 0);
    if (*(ulong *)(lVar1 + 0x20) != 0 && *(ulong *)(lVar1 + 0x20) < param_3) break;
    if (*(ulong *)(lVar1 + 0x18) < param_4) {
      thunk_EXT_FUN_8011000003a49114
                ("\"IOGPUFenceMachine: block fence %p appears stuck after creation\" @%s:%d");
      return;
    }
  }
  thunk_EXT_FUN_8011000003a49114
            ("\"IOGPUFenceMachine: block fence %p appears stuck after starting\" @%s:%d");
  return;
}

