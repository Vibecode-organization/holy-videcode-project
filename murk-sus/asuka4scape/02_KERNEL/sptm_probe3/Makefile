THEOS ?= /opt/theos
LDID ?= /home/femboychik/claude_code/.tools/ldid-amd64
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME := SPTMProbe3
SPTMProbe3_FILES := main.m
SPTMProbe3_RESOURCE_FILES := Info.plist
SPTMProbe3_FRAMEWORKS := UIKit Foundation IOSurface IOKit
SPTMProbe3_CFLAGS := -fobjc-arc -O2 -Wall -Wno-unused-variable -fstack-protector-strong -fno-omit-frame-pointer
SPTMProbe3_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
SPTMProbe3_CODESIGN_FLAGS := -Sentitlements.plist

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	mkdir -p .theos/ipa/Payload
	cp -a .theos/obj/debug/SPTMProbe3.app .theos/ipa/Payload/
	$(LDID) -Sentitlements.plist .theos/ipa/Payload/SPTMProbe3.app/SPTMProbe3
	cd .theos/ipa && rm -f ../../SPTMProbe3.ipa && zip -qry ../../SPTMProbe3.ipa Payload
