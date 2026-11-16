// FUN_fffffff00819d3c8 @ fffffff00819d3c8 size=296

undefined8 FUN_fffffff00819d3c8(undefined8 param_1,long param_2)

{
  long *plVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  thunk_EXT_FUN_8011000003350cfc(param_2,"",8,8);
  thunk_EXT_FUN_8011000003350958(param_2 + 0x28,"",0x60);
  thunk_EXT_FUN_8011000003350958(param_2 + 8,"",0x20);
  thunk_EXT_FUN_8011000003350958(param_2 + 0x88,"",0x20);
  thunk_EXT_FUN_8011000003350958(param_2 + 0xa8,"",0x20);
  thunk_EXT_FUN_8011000003350958(param_2 + 200,"Oct 13 2026 21:09:29",0x20);
  *(char (*) [8])(param_2 + 0xe8) = s_release_fffffff007113ed8;
  plVar1 = (long *)thunk_EXT_FUN_801100000392b5f0();
  if (plVar1 != (long *)0x0) {
    uVar2 = (**(code **)(*plVar1 + 0x370))();
    plVar1 = (long *)thunk_EXT_FUN_8011000003890f30(uVar2,*(undefined8 *)PTR_DAT_fffffff007ca6008);
    if (plVar1 != (long *)0x0) {
      pcVar3 = (char *)(**(code **)(*plVar1 + 0x1e8))(plVar1,0);
      goto LAB_fffffff00819d4c8;
    }
  }
  pcVar3 = "Unknown";
LAB_fffffff00819d4c8:
  thunk_EXT_FUN_8011000003350958(param_2 + 0x1a8,pcVar3,0x20);
  return 0;
}

