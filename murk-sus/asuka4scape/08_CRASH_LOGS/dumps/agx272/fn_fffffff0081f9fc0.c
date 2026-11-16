// FUN_fffffff0081f9fc0 @ fffffff0081f9fc0 size=388

long * FUN_fffffff0081f9fc0(long param_1,long param_2,undefined8 param_3,ulong param_4,long param_5)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_48;
  
  local_48 = 0;
  plVar2 = (long *)thunk_EXT_FUN_801100000294f008
                             (param_1,param_2,0,param_3,*(uint *)(param_1 + 0x18b70) | 99,&local_48)
  ;
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x20))(plVar2);
    (**(code **)(*plVar2 + 0x28))(plVar2);
    iVar1 = (**(code **)(*plVar2 + 0x88))(plVar2,param_2,0,0);
    if (iVar1 != 0) {
      if ((param_4 >> 0x25 & 1) != 0) {
        lVar3 = thunk_EXT_FUN_8011000003890f30(plVar2[5],&DAT_fffffff00ae21bd0);
        *(undefined1 *)(lVar3 + 0xe8) = 3;
      }
      uVar4 = (**(code **)(*plVar2 + 0xb8))(plVar2,param_4 & 0x5000000003 | param_5 << 0x20 | 4);
      if ((uVar4 & 1) != 0) {
        return plVar2;
      }
    }
    if (param_2 == 0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
    else {
      (**(code **)(*plVar2 + 0xb0))(plVar2,param_2);
    }
  }
  return (long *)0x0;
}

