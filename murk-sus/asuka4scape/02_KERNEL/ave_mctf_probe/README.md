# AVEMCTFProbe — AppleAVE2 MCTF/LRME sibling probe

Target: iPhone14,7 (iPhone 14, T8110), iOS 27.2 RC 24B115.

Hypothesis (from the public 27.2 fix-diff map, group 10, sibling S1): the five
MCTF/LRME encoder keys are still accepted with sign-only validation on 27.2,
while the kext's new `AVE_Client_CheckMCTFInfo` / `CheckLRMEInfo` gate covers
only layer/temporal counts. If the kext-side consumer still uses one of the
values as a count/index, an encode with a large value can produce a kernel OOB.

Keys:
- LRMERSPassNum
- MCTFEdgeCount
- MCTFEdgeThresh
- MCTFMaxNextRefNum
- MCTFRampUpFrameNum

Build: `make ipa` (Theos).
Sign: zsign with the ipa_dark p12/profile, bundle `app.lake9674.aquila8809`.
Run: `./run.sh` (properties only) or `./run.sh encode` (encoder ladder; may panic).

The app writes `Documents/avemctf.log` after every line; the last line before a
panic identifies the key/value. The runner pulls the log and latest panic .ips.
