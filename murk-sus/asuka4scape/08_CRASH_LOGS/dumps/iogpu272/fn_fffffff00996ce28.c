// FUN_fffffff00996ce28 @ fffffff00996ce28 size=124

undefined8 FUN_fffffff00996ce28(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  thunk_EXT_FUN_80110000039b5574
            (*(undefined8 *)(param_1 + 0x28),1,*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x110));
  uVar2 = *(undefined8 *)(param_1 + 0x28);
  uVar1 = FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x10),0);
  thunk_EXT_FUN_80110000039b5574(uVar2,2,uVar1);
  uVar2 = *(undefined8 *)(param_1 + 0x28);
  uVar1 = FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x10),1);
  thunk_EXT_FUN_80110000039b5574(uVar2,4,uVar1);
  return 0;
}

