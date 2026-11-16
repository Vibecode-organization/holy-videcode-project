// FUN_fffffff0089d201c @ fffffff0089d201c size=320
// CALLERS:
//   fffffff00afcc9ce ?
//   fffffff0089d1e58 FUN_fffffff0089d1e2c@fffffff0089d1e2c
//   fffffff0089d45f8 FUN_fffffff0089d45d4@fffffff0089d45d4
// CALLS:
//   fffffff008a81ed4 thunk_FUN_fffffff00a8df19c

undefined8
FUN_fffffff0089d201c
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined8 param_7,long param_8)

{
  undefined8 uVar1;
  
  if (param_8 == 0) {
    uVar1 = 0xe00002c2;
    thunk_FUN_fffffff00a8df19c
              (param_1,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff007ddeaa8,0x10,
               (byte *)"[ERROR] %s: %s: memoryMapRequest is nullptr\n");
  }
  else if (*(uint *)(param_8 + 0x810) < 0x81) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xe00002c2;
    thunk_FUN_fffffff00a8df19c
              (param_1,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff007ddeaa8,0x10,
               (byte *)"[ERROR] %s: %s: Buffer count: %u exceeds max allowed number: %u\n");
  }
  return uVar1;
}

