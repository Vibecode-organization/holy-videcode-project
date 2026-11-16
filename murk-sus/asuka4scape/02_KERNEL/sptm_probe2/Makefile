THEOS ?= /opt/theos
LDID ?= /home/femboychik/claude_code/.tools/ldid-amd64
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME := SPTMProbe2
SPTMProbe2_FILES := main.m
SPTMProbe2_RESOURCE_FILES := Info.plist
SPTMProbe2_FRAMEWORKS := UIKit Foundation IOSurface IOKit
SPTMProbe2_CFLAGS := -fobjc-arc -O2 -Wall -Wno-unused-variable -fstack-protector-strong -fno-omit-frame-pointer
SPTMProbe2_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
SPTMProbe2_CODESIGN_FLAGS := -Sentitlements.plist

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	mkdir -p .theos/ipa/Payload
	cp -a .theos/obj/debug/SPTMProbe2.app .theos/ipa/Payload/
	$(LDID) -Sentitlements.plist .theos/ipa/Payload/SPTMProbe2.app/SPTMProbe2
	cd .theos/ipa && rm -f ../../SPTMProbe2.ipa && zip -qry ../../SPTMProbe2.ipa Payload
