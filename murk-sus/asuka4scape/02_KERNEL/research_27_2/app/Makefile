THEOS ?= /opt/theos
LDID ?= /home/femboychik/claude_code/.tools/ldid-amd64
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME := KRW27
KRW27_FILES := main.m surface_probes.m
KRW27_RESOURCE_FILES := Info.plist
KRW27_FRAMEWORKS := UIKit Foundation IOSurface
KRW27_CFLAGS := -fobjc-arc -O2 -Wall -Wextra
KRW27_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
KRW27_CODESIGN_FLAGS := -Sentitlements.xml

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	mkdir -p .theos/ipa/Payload
	cp -a .theos/obj/debug/KRW27.app .theos/ipa/Payload/
	$(LDID) -Sentitlements.xml .theos/ipa/Payload/KRW27.app/KRW27
	cd .theos/ipa && zip -qry ../../KRW27.ipa Payload
