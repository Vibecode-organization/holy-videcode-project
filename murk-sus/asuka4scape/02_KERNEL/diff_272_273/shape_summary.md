# 27.2 vs 27.3 kext shape diff (priority set)

| kext | status | funcs 272/273 | identical | ratio | changed regions | seconds |
|---|---|---|---|---|---|---|
| com.apple.AGXFirmwareKextRTBuddy64 | OK | 1/1 | 1 | 1.0 | 0 | 0.3 |
| com.apple.driver.ASIOKit | OK | 95/95 | 95 | 1.0 | 0 | 2.1 |
| com.apple.driver.AppleA7IOP | OK | 279/193 | 191 | 0.80932 | 4 | 0.4 |
| com.apple.driver.AppleAOPAudio | OK | 1224/1224 | 1223 | 0.99918 | 1 | 3.1 |
| com.apple.driver.AppleBasebandPCI | OK | 2232/2407 | 1847 | 0.79629 | 172 | 5.6 |
| com.apple.driver.AppleBasebandPCIMAVControl | OK | 1078/1097 | 798 | 0.73379 | 92 | 3.6 |
| com.apple.driver.AppleBasebandPCIMAVPDP | OK | 389/398 | 268 | 0.68107 | 50 | 1.4 |
| com.apple.driver.AppleDiskImages2 | OK | 399/399 | 399 | 1.0 | 0 | 1.5 |
| com.apple.driver.AppleGameControllerPersonality | OK | 76/76 | 76 | 1.0 | 0 | 0.3 |
| com.apple.driver.AppleH11ANEInterface | OK | 5042/5175 | 2947 | 0.57688 | 138 | 22.4 |
| com.apple.driver.AppleH13CameraInterface | OK | 1377/1377 | 1377 | 1.0 | 0 | 7.1 |
| com.apple.driver.AppleHIDKeyboard | OK | 122/122 | 122 | 1.0 | 0 | 0.5 |
| com.apple.driver.AppleIDV | OK | 176/176 | 176 | 1.0 | 0 | 0.7 |
| com.apple.driver.AppleMobileDispH14P-DCP | OK | 1881/1881 | 1701 | 0.90431 | 63 | 5.7 |
| com.apple.driver.AppleProResHW | OK | 3014/3014 | 3004 | 0.99668 | 9 | 5.9 |
| com.apple.driver.AppleProxDriver | OK | 195/195 | 195 | 1.0 | 0 | 0.8 |
| com.apple.driver.AppleSEPManager | OK | 2543/2547 | 2534 | 0.99568 | 10 | 4.9 |
| com.apple.driver.AppleSPURose | OK | 669/677 | 657 | 0.97623 | 15 | 1.8 |
| com.apple.driver.AppleT8110CLPC | OK | 1343/1341 | 1299 | 0.96796 | 26 | 6.3 |
| com.apple.driver.AudioDMAController-T8110 | OK | 339/339 | 339 | 1.0 | 0 | 1.5 |
| com.apple.driver.ExclavesAudioKext | OK | 701/701 | 701 | 1.0 | 0 | 1.5 |
| com.apple.driver.IISAudioIsolatedStreamECProxy | OK | 90/90 | 90 | 1.0 | 0 | 0.3 |
| com.apple.driver.usb.cdc.ncm | OK | 354/359 | 349 | 0.97896 | 10 | 1.1 |
| com.apple.filesystems.apfs | OK | 2398/2401 | 2380 | 0.99187 | 16 | 22.7 |
| com.apple.iokit.AppleARMIISAudio | OK | 322/322 | 321 | 0.99689 | 1 | 1.4 |
| com.apple.iokit.IOAccessoryManager | OK | 5012/5018 | 4991 | 0.99521 | 22 | 15.0 |
| com.apple.iokit.IOGameControllerFamily | OK | 672/673 | 672 | 0.99926 | 1 | 1.8 |
| com.apple.iokit.IOHIDFamily | OK | 2808/2808 | 2793 | 0.99466 | 18 | 8.5 |
| com.apple.iokit.IOMobileGraphicsFamily-DCP | OK | 799/802 | 764 | 0.9544 | 27 | 3.1 |
| com.apple.iokit.IONetworkingFamily | OK | 861/863 | 860 | 0.99768 | 3 | 2.2 |
| com.apple.iokit.IOSCSIArchitectureModelFamily | OK | 733/733 | 731 | 0.99727 | 2 | 1.6 |
| com.apple.iokit.IOSCSIBlockCommandsDevice | OK | 302/302 | 302 | 1.0 | 0 | 1.0 |
| com.apple.kext.AppleMatch | OK | 34/34 | 34 | 1.0 | 0 | 0.2 |
| com.apple.security.sandbox | OK | 657/657 | 657 | 1.0 | 0 | 3.8 |
