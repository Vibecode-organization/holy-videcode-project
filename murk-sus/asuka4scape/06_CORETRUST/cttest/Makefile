THEOS ?= /opt/theos
LDID ?= /usr/local/bin/ldid
TARGET := iphone:clang:latest:14.0
ARCHS := arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME := cttest
cttest_FILES := main.m
cttest_RESOURCE_FILES := Info.plist
cttest_FRAMEWORKS := UIKit Foundation Security
cttest_CFLAGS := -fobjc-arc -O2
cttest_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
include $(THEOS)/makefiles/application.mk
.PHONY: ipa
ipa: all
	mkdir -p .theos/ipa/Payload
	rm -rf .theos/ipa/Payload/cttest.app
	cp -a .theos/obj/debug/cttest.app .theos/ipa/Payload/
	$(LDID) -S .theos/ipa/Payload/cttest.app/cttest
	cd .theos/ipa && rm -f ../../cttest.ipa && zip -qry ../../cttest.ipa Payload
