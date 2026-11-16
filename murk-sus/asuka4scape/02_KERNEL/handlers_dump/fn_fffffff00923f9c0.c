// FUN_fffffff00923f9c0 @ fffffff00923f9c0 size=88 depth=1
// CALLERS:
//   fffffff00afdcc6f ?
//   fffffff007cbf360 ?
//   fffffff007ccbb18 ?
//   fffffff007cccde8 ?
//   fffffff007d84548 ?
//   fffffff007dfd360 ?
//   fffffff007f00188 ?
//   fffffff007f00c68 ?
//   fffffff0092192f8 FUN_fffffff009219284
//   fffffff009248664 FUN_fffffff009248578
//   fffffff00921ecd4 FUN_fffffff00921ec8c
//   fffffff009228a5c FUN_fffffff009228a00
//   fffffff009228a90 FUN_fffffff009228a00
//   fffffff009228ac4 FUN_fffffff009228a00
//   fffffff00924bd50 FUN_fffffff00924bc2c
//   fffffff00924c288 FUN_fffffff00924bd74
//   fffffff00924c3a4 FUN_fffffff00924bd74
//   fffffff00924c4ec FUN_fffffff00924c468
//   fffffff009220d5c FUN_fffffff009220cec
//   fffffff009222ca0 FUN_fffffff009222c60
//   fffffff009222cd0 FUN_fffffff009222c60
//   fffffff009222db4 FUN_fffffff009222cf4
//   fffffff0092273b4 FUN_fffffff009227334
//   fffffff009228ba4 FUN_fffffff009228ae8
//   fffffff009228c2c FUN_fffffff009228ae8
//   fffffff009228d70 FUN_fffffff009228ae8
//   fffffff009229f64 FUN_fffffff009229e3c
//   fffffff009252a7c FUN_fffffff009252944
//   fffffff00922d3b0 FUN_fffffff00922d354
//   fffffff00922ebc4 FUN_fffffff00922dd28
//   fffffff00922f1c0 FUN_fffffff00922f0ec
//   fffffff009230724 FUN_fffffff00922fae8
//   fffffff009230fd8 FUN_fffffff009230f48
//   fffffff00923113c FUN_fffffff009230f48
//   fffffff009256dd4 FUN_fffffff009256d18
//   fffffff009235c78 FUN_fffffff009235874
//   fffffff00925a424 FUN_fffffff00925a3d8
//   fffffff00925a494 FUN_fffffff00925a448
//   fffffff00925a5b8 FUN_fffffff00925a4b8
//   fffffff0092379dc FUN_fffffff0092379a0
//   fffffff009237a10 FUN_fffffff0092379a0
//   fffffff009237aec ?
//   fffffff0092487bc FUN_fffffff0092486e0
//   fffffff009248874 FUN_fffffff0092487fc
//   fffffff00924d5bc FUN_fffffff00924d398
//   fffffff00924eadc FUN_fffffff00924e9f8
//   fffffff0092509f4 FUN_fffffff009250994
//   fffffff009251360 FUN_fffffff009251168
//   fffffff009254900 FUN_fffffff009254590
//   fffffff00925528c FUN_fffffff009254590
//   fffffff0092554ac FUN_fffffff009254590
//   fffffff0092557cc FUN_fffffff009254590
//   fffffff00925ab48 FUN_fffffff00925a9a4
//   fffffff00925fab0 FUN_fffffff00925f8e8
//   fffffff00925fee4 FUN_fffffff00925f8e8
//   fffffff00925fffc FUN_fffffff00925f8e8
//   fffffff00922bb24 FUN_fffffff00922bb18
//   fffffff009229e2c FUN_fffffff009229d90
//   fffffff00922d4b8 FUN_fffffff00922d414
//   fffffff0092195e8 FUN_fffffff0092195c8
//   fffffff00921fad4 FUN_fffffff00921fab8
//   fffffff009233130 FUN_fffffff009233118
//   fffffff00923314c FUN_fffffff009233134
//   fffffff009233170 FUN_fffffff00923315c
//   fffffff0092331a0 FUN_fffffff00923318c
//   fffffff00923ca98 FUN_fffffff00923ca78
//   fffffff00829da38 thunk_FUN_fffffff00923f9c0
//   fffffff0082cdb00 thunk_FUN_fffffff00923f9c0
//   fffffff008836310 thunk_FUN_fffffff00923f9c0
//   fffffff008b74c50 thunk_FUN_fffffff00923f9c0
//   fffffff00927a62c thunk_FUN_fffffff00923f9c0
//   fffffff00927c618 thunk_FUN_fffffff00923f9c0
//   fffffff0082d44fc thunk_FUN_fffffff00923f9c0
//   fffffff009260500 FUN_fffffff009260490
//   fffffff009260524 FUN_fffffff009260490
//   fffffff009260570 FUN_fffffff009260490
//   fffffff00922d194 FUN_fffffff00922d18c
//   fffffff009217f9c ?
//   fffffff009218044 ?
//   fffffff00921807c ?
// CALLS:

void FUN_fffffff00923f9c0
               (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0xa0) + 0xe8);
                    /* WARNING: Could not recover jumptable at 0xfffffff00923fa14. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0xa0),FUN_fffffff00923fd1c,param_2,param_3,param_4,param_5
                     ,puVar1);
  return;
}

