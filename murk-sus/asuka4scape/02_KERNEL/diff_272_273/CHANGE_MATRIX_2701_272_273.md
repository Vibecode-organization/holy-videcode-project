# Матрица изменений: 27.0.1->27.2 vs 27.2->27.3

| kext | 27.0.1->27.2 | 27.2->27.3 | итог |
|---|---|---|---|
| com.apple.kernel | 392 | 310 | both |
| com.apple.driver.AppleH11ANEInterface | 144 | 138 | both |
| com.apple.driver.AppleBasebandPCI | 8 | 172 | both |
| com.apple.driver.AppleM2ScalerCSCDriver | 62 | 89 | both |
| com.apple.driver.AppleBasebandPCIMAVControl | 25 | 92 | both |
| com.apple.driver.AppleMobileDispH14P-DCP | 26 | 63 | both |
| com.apple.driver.RTBuddy | 67 | 4 | both |
| com.apple.filesystems.apfs | 51 | 16 | both |
| com.apple.iokit.IOUSBHostFamily | 38 | 25 | both |
| com.apple.kec.corecrypto | 50 | 8 | both |
| com.apple.driver.ApplePearlSEPDriver | 28 | 26 | both |
| com.apple.driver.AppleT8110CLPC | 28 | 26 | both |
| com.apple.driver.AppleFirmwareKit | 3 | 44 | both |
| com.apple.iokit.IOSkywalkFamily | 23 | 21 | both |
| com.apple.iokit.IOGPUFamily | 12 | 28 | both |
| com.apple.driver.ApplePPMCPMS | 29 | 10 | both |
| com.apple.driver.AppleAVE2 | 26 | 10 | both |
| com.apple.iokit.IOMobileGraphicsFamily-DCP | 9 | 27 | both |
| com.apple.AGXG14P | 23 | 11 | both |
| com.apple.iokit.IOHIDFamily | 16 | 18 | both |
| com.apple.driver.AppleOLYHAL | 18 | 7 | both |
| com.apple.iokit.IOAccessoryManager | 2 | 22 | both |
| com.apple.driver.AppleSmartBatteryManagerEmbedded | 16 | 7 | both |
| com.apple.filesystems.lifs | 21 | 2 | both |
| com.apple.driver.FairPlayIOKit | 14 | 6 | both |
| com.apple.driver.AppleProResHW | 8 | 9 | both |
| com.apple.driver.AppleUSBDeviceNCM | 11 | 2 | both |
| com.apple.driver.AppleSEPManager | 2 | 10 | both |
| com.apple.driver.usb.cdc.ncm | 2 | 10 | both |
| com.apple.driver.AppleSEPCredentialManager | 8 | 3 | both |
| com.apple.driver.DiskImages.UDIFDiskImage | 8 | 2 | both |
| com.apple.iokit.IOMobileGraphicsFamily | 2 | 8 | both |
| com.apple.driver.AppleSPU | 1 | 8 | both |
| com.apple.driver.corecapture | 1 | 8 | both |
| com.apple.iokit.IOAVFamily | 8 | 1 | both |
| com.apple.driver.AppleARMPlatform | 7 | 1 | both |
| com.apple.driver.AppleMultiFunctionManager | 2 | 5 | both |
| com.apple.driver.AppleSMCWirelessCharger | 4 | 3 | both |
| com.apple.driver.AppleMobileFileIntegrity | 3 | 3 | both |
| com.apple.driver.DCPAVFamilyProxy | 4 | 2 | both |
| com.apple.driver.usb.AppleUSBHub | 3 | 3 | both |
| com.apple.iokit.IOSCSIArchitectureModelFamily | 4 | 2 | both |
| com.apple.driver.AppleEmbeddedTempSensor | 2 | 3 | both |
| com.apple.driver.AppleSMC | 3 | 2 | both |
| com.apple.driver.AppleConvergedPCI | 3 | 1 | both |
| com.apple.driver.AppleDiagnosticDataAccessReadOnly | 3 | 1 | both |
| com.apple.iokit.IOStorageFamily | 3 | 1 | both |
| com.apple.driver.AppleBasebandM20 | 2 | 1 | both |
| com.apple.driver.AppleAOPHaptics | 1 | 1 | both |
| com.apple.security.sandbox | 72 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleSEPKeyStore | 41 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleIDV | 23 | 0 | only 27.0.1->27.2 |
| com.apple.iokit.IOBiometricFamily | 16 | 0 | only 27.0.1->27.2 |
| com.apple.iokit.IONVMeFamily | 15 | 0 | only 27.0.1->27.2 |
| com.apple.iokit.IOTimeSyncFamily | 15 | 0 | only 27.0.1->27.2 |
| com.apple.plugin.IOgPTPPlugin | 15 | 0 | only 27.0.1->27.2 |
| com.apple.AppleFSCompression.AppleFSCompressionTypeZlib | 12 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleDCP | 11 | 0 | only 27.0.1->27.2 |
| com.apple.driver.ASIOKit | 10 | 0 | only 27.0.1->27.2 |
| com.apple.driver.IOAudioCodecs | 9 | 0 | only 27.0.1->27.2 |
| com.apple.driver.usb.networking | 9 | 0 | only 27.0.1->27.2 |
| com.apple.driver.ApplePMGR | 7 | 0 | only 27.0.1->27.2 |
| com.apple.filesystems.tmpfs | 7 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleDCPDPTXProxy | 6 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleMultitouchDriver | 6 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleAVD | 5 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleT8110DART | 5 | 0 | only 27.0.1->27.2 |
| com.apple.iokit.IODisplayPortFamily | 5 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleDiskImages2 | 4 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleH13CameraInterface | 4 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleInputDeviceSupport | 4 | 0 | only 27.0.1->27.2 |
| com.apple.iokit.IOPCIFamily | 4 | 0 | only 27.0.1->27.2 |
| com.apple.iokit.IOUSBDeviceFamily | 4 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleTypeCPhy | 3 | 0 | only 27.0.1->27.2 |
| com.apple.driver.IODARTFamily | 3 | 0 | only 27.0.1->27.2 |
| com.apple.iokit.IOSurface | 3 | 0 | only 27.0.1->27.2 |
| com.apple.iokit.IOUserEthernet | 3 | 0 | only 27.0.1->27.2 |
| com.apple.kec.Compression | 3 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleActuatorDriver | 2 | 0 | only 27.0.1->27.2 |
| com.apple.driver.ApplePhoneBTM | 2 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleUSBEthernetHost | 2 | 0 | only 27.0.1->27.2 |
| com.apple.iokit.IOReportFamily | 2 | 0 | only 27.0.1->27.2 |
| com.apple.kext.CoreTrust | 2 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleBluetoothModule | 1 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleEmbeddedPCIE | 1 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleMCA2-T8110 | 1 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleStockholmControl | 1 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleT8110PMGR | 1 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleUSBDeviceMux | 1 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleUSBXDCIARM | 1 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AudioDMAController-T8110 | 1 | 0 | only 27.0.1->27.2 |
| com.apple.driver.usb.AppleUSBXHCI | 1 | 0 | only 27.0.1->27.2 |
| com.apple.driver.usb.IOUSBHostHIDDevice | 1 | 0 | only 27.0.1->27.2 |
| com.apple.driver.AppleBasebandPCIMAVPDP | 0 | 50 | only 27.2->27.3 |
| com.apple.driver.AppleSPURose | 0 | 15 | only 27.2->27.3 |
| com.apple.driver.AppleA7IOP | 0 | 4 | only 27.2->27.3 |
| com.apple.iokit.IONetworkingFamily | 0 | 3 | only 27.2->27.3 |
| com.apple.driver.AppleJPEGDriver | 0 | 2 | only 27.2->27.3 |
| com.apple.driver.ApplePMP | 0 | 2 | only 27.2->27.3 |
| com.apple.driver.usb.ethernet.asix | 0 | 2 | only 27.2->27.3 |
| com.apple.AUC | 0 | 1 | only 27.2->27.3 |
| com.apple.driver.AppleAOPAudio | 0 | 1 | only 27.2->27.3 |
| com.apple.driver.AppleC26Charger | 0 | 1 | only 27.2->27.3 |
| com.apple.driver.AppleConvergedIPCOLYBTControl | 0 | 1 | only 27.2->27.3 |
| com.apple.driver.AppleHapticsSupportLEAP | 0 | 1 | only 27.2->27.3 |
| com.apple.driver.AppleMikeyBusAudio | 0 | 1 | only 27.2->27.3 |
| com.apple.driver.AppleSPMIPMU | 0 | 1 | only 27.2->27.3 |
| com.apple.driver.AppleTopCaseHIDEventDriver | 0 | 1 | only 27.2->27.3 |
| com.apple.driver.DiskImages | 0 | 1 | only 27.2->27.3 |
| com.apple.iokit.AppleARMIISAudio | 0 | 1 | only 27.2->27.3 |
| com.apple.iokit.IOGameControllerFamily | 0 | 1 | only 27.2->27.3 |

Итого: both=49, only 2701->272=44, only 272->273=18, none=139.
