// FUN_fffffff00a8d8754 @ fffffff00a8d8754 size=192
// CALLERS:
//   fffffff00afbe435 no-fn
//   fffffff007d7c130 no-fn
//   fffffff007db41d8 no-fn
//   fffffff007dfd1e0 no-fn
//   fffffff007e0e6b0 no-fn
//   fffffff007e26350 no-fn
//   fffffff007e741d8 no-fn
//   fffffff007f0a140 no-fn
//   fffffff007f1f018 no-fn
//   fffffff007f57550 no-fn
//   fffffff007f99338 no-fn
//   fffffff007ff8c28 no-fn
//   fffffff007ffd8d0 no-fn
//   fffffff008016ec0 no-fn
//   fffffff008021bd8 no-fn
//   fffffff00806c618 no-fn
//   fffffff0080b65d8 no-fn
//   fffffff0080c5eb8 no-fn
//   fffffff0080d7e00 no-fn
//   fffffff0080dcf70 no-fn
//   fffffff00a9a8d8c FUN_fffffff00a9a8d08@fffffff00a9a8d08
//   fffffff00a9a8630 FUN_fffffff00a9a85b8@fffffff00a9a85b8
//   fffffff00a9a87e0 FUN_fffffff00a9a8794@fffffff00a9a8794
//   fffffff00a9a8b58 FUN_fffffff00a9a8b10@fffffff00a9a8b10
//   fffffff00a9a8a38 FUN_fffffff00a9a899c@fffffff00a9a899c
//   fffffff00a9b01b4 FUN_fffffff00a9aff58@fffffff00a9aff58
//   fffffff00a9abac8 FUN_fffffff00a9ab9f8@fffffff00a9ab9f8
//   fffffff00a9e06fc FUN_fffffff00a9e0640@fffffff00a9e0640
//   fffffff00880c154 thunk_FUN_fffffff00a8d8754@fffffff00880c148
//   fffffff008908940 thunk_FUN_fffffff00a8d8754@fffffff008908934
//   fffffff008b74950 thunk_FUN_fffffff00a8d8754@fffffff008b74944
//   fffffff008c1ffd8 thunk_FUN_fffffff00a8d8754@fffffff008c1ffcc
//   fffffff008c78930 thunk_FUN_fffffff00a8d8754@fffffff008c78924
//   fffffff008eb898c thunk_FUN_fffffff00a8d8754@fffffff008eb8980
//   fffffff0092ba118 thunk_FUN_fffffff00a8d8754@fffffff0092ba10c
//   fffffff009363c2c thunk_FUN_fffffff00a8d8754@fffffff009363c20
//   fffffff0094be7b8 thunk_FUN_fffffff00a8d8754@fffffff0094be7ac
//   fffffff0097ba7d0 thunk_FUN_fffffff00a8d8754@fffffff0097ba7c4
//   fffffff0099a0478 thunk_FUN_fffffff00a8d8754@fffffff0099a046c
//   fffffff0099b8bb4 thunk_FUN_fffffff00a8d8754@fffffff0099b8ba8
//   fffffff009a48168 thunk_FUN_fffffff00a8d8754@fffffff009a4815c
//   fffffff009a99d4c thunk_FUN_fffffff00a8d8754@fffffff009a99d40
//   fffffff009c49770 thunk_FUN_fffffff00a8d8754@fffffff009c49764
//   fffffff009e98978 thunk_FUN_fffffff00a8d8754@fffffff009e9896c
//   fffffff009f09438 thunk_FUN_fffffff00a8d8754@fffffff009f0942c
//   fffffff009f6f1d4 thunk_FUN_fffffff00a8d8754@fffffff009f6f1c8
//   fffffff009fa9768 thunk_FUN_fffffff00a8d8754@fffffff009fa975c
// CALLEES:
//   fffffff00a8d96f4 FUN_fffffff00a8d96f4
//   fffffff00aa7451c FUN_fffffff00aa7451c
//   fffffff00a8d846c FUN_fffffff00a8d846c

undefined ****** FUN_fffffff00a8d8754(char *param_1,ulong param_2,undefined8 *param_3)

{
  int iVar1;
  undefined ******ppppppuVar2;
  ulong in_x6;
  
  if ((param_1 != (char *)0x0) && (3 < param_2)) {
    iVar1 = FUN_fffffff00aa7451c(&DAT_fffffff007043a08,param_1);
    if ((iVar1 == 0) || (*param_1 == -0x2c)) {
      ppppppuVar2 = FUN_fffffff00a8d96f4(param_1,param_2,(undefined *)0x0,0,0,param_3,in_x6);
      return ppppppuVar2;
    }
    if (param_1[param_2 - 1] == '\0') {
      ppppppuVar2 = (undefined ******)FUN_fffffff00a8d846c((long)param_1,0,0,0,param_3);
      return ppppppuVar2;
    }
  }
  return (undefined ******)0x0;
}

