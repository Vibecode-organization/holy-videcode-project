THEOS ?= /opt/theos
LDID ?= /home/femboychik/claude_code/.tools/ldid-amd64
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME := SBX
SBX_FILES := main.m
SBX_RESOURCE_FILES := Info.plist
SBX_FRAMEWORKS := UIKit Foundation IOKit IOSurface
SBX_CFLAGS := -fobjc-arc -O2 -Wall -Wextra
SBX_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
SBX_CODESIGN_FLAGS := -Sentitlements.plist

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	rm -rf .theos/ipa && mkdir -p .theos/ipa/Payload
	cp -a .theos/obj/debug/SBX.app .theos/ipa/Payload/
	$(LDID) -Sentitlements.plist .theos/ipa/Payload/SBX.app/SBX
	cd .theos/ipa && zip -qry ../../SBX.ipa Payload
	@echo "built SBX.ipa (ad-hoc + entitlements)"
