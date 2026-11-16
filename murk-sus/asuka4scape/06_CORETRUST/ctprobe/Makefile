TARGET = iphone:clang:latest:14.0
ARCHS = arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME = ctprobe
ctprobe_FILES = main.m
ctprobe_FRAMEWORKS = UIKit Security
ctprobe_CFLAGS = -fobjc-arc -O2
ctprobe_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
ctprobe_RESOURCE_FILES = Info.plist \
	p_adhoc.b64 p_adhoc_ent.b64 p_control.b64 \
	p_apple_iphone.b64 p_apple_iphone_noext.b64 p_apple_cs.b64 p_apple_dev.b64 \
	p_trollstore.b64 p_trollstore_rev.b64 \
	p_modcd_reuse.b64 p_modcd_app.b64 p_modcd_real.b64 p_modcd_ours.b64 \
	p_modcd_ours_app.b64 p_modcd_ours_real.b64 \
	p_swap_reuse.b64 p_swap_app.b64 p_swap_real.b64 p_swap_ours_app.b64

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	rm -rf .theos/ipa && mkdir -p .theos/ipa/Payload
	cp -a .theos/obj/debug/ctprobe.app .theos/ipa/Payload/
	/usr/local/bin/ldid -S .theos/ipa/Payload/ctprobe.app/ctprobe
	rm -f ctprobe.ipa
	cd .theos/ipa && zip -qry ../../ctprobe.ipa Payload
