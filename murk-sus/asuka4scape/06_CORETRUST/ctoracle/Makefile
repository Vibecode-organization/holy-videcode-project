THEOS ?= /opt/theos
LDID ?= /usr/local/bin/ldid
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME := ctoracle
ctoracle_FILES := main.m
ctoracle_RESOURCE_FILES := Info.plist
ctoracle_FRAMEWORKS := UIKit Foundation Security
ctoracle_CFLAGS := -fobjc-arc -O2 -Wall -Wno-unused-variable -Wno-unused-function
ctoracle_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
ctoracle_CODESIGN_FLAGS := -Sentitlements.plist

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	mkdir -p .theos/ipa/Payload
	rm -rf .theos/ipa/Payload/ctoracle.app
	cp -a .theos/obj/debug/ctoracle.app .theos/ipa/Payload/
	$(LDID) -Sentitlements.plist .theos/ipa/Payload/ctoracle.app/ctoracle
	cd .theos/ipa && rm -f ../../ctoracle.ipa && zip -qry ../../ctoracle.ipa Payload
