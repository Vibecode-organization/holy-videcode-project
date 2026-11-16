TARGET = iphone:clang:latest:14.0
ARCHS = arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME = ctapp
ctapp_FILES = main.m
ctapp_RESOURCE_FILES = Info.plist dylib_control dylib_apple dylib_apple_cs dylib_apple_ext dylib_adhoc_v2 dylib_adhoc_ent
ctapp_FRAMEWORKS = UIKit
ctapp_CFLAGS = -fobjc-arc -O2
ctapp_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	rm -rf .theos/ipa && mkdir -p .theos/ipa/Payload
	cp -a .theos/obj/debug/ctapp.app .theos/ipa/Payload/
	mkdir -p .theos/ipa/Payload/ctapp.app/Frameworks
	cp dylib_test.dylib .theos/ipa/Payload/ctapp.app/Frameworks/test.dylib
	/usr/local/bin/ldid -S .theos/ipa/Payload/ctapp.app/ctapp
	rm -f ../../ctapp.ipa
	cd .theos/ipa && zip -qry ../../ctapp.ipa Payload
