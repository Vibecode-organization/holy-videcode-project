THEOS ?= /opt/theos
LDID ?= /home/femboychik/claude_code/.tools/ldid-amd64
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME := SPTMProbe7
SPTMProbe7_FILES := main.m
SPTMProbe7_RESOURCE_FILES := Info.plist
SPTMProbe7_FRAMEWORKS := UIKit Foundation IOSurface IOKit
SPTMProbe7_CFLAGS := -fobjc-arc -O2 -Wall -Wno-unused-variable -fstack-protector-strong -fno-omit-frame-pointer
SPTMProbe7_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
SPTMProbe7_CODESIGN_FLAGS := -Sentitlements.plist

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	mkdir -p .theos/ipa/Payload
	cp -a .theos/obj/debug/SPTMProbe7.app .theos/ipa/Payload/
	$(LDID) -Sentitlements.plist .theos/ipa/Payload/SPTMProbe7.app/SPTMProbe7
	cd .theos/ipa && rm -f ../../SPTMProbe7.ipa && zip -qry ../../SPTMProbe7.ipa Payload
