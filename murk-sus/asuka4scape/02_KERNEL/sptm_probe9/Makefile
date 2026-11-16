THEOS ?= /opt/theos
LDID ?= /home/femboychik/claude_code/.tools/ldid-amd64
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME := SPTMProbe9
SPTMProbe9_FILES := main.m
SPTMProbe9_RESOURCE_FILES := Info.plist
SPTMProbe9_FRAMEWORKS := UIKit Foundation IOSurface IOKit
SPTMProbe9_CFLAGS := -fobjc-arc -O2 -Wall -Wno-unused-variable -fstack-protector-strong -fno-omit-frame-pointer
SPTMProbe9_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
SPTMProbe9_CODESIGN_FLAGS := -Sentitlements.plist

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	mkdir -p .theos/ipa/Payload
	cp -a .theos/obj/debug/SPTMProbe9.app .theos/ipa/Payload/
	$(LDID) -Sentitlements.plist .theos/ipa/Payload/SPTMProbe9.app/SPTMProbe9
	cd .theos/ipa && rm -f ../../SPTMProbe9.ipa && zip -qry ../../SPTMProbe9.ipa Payload
