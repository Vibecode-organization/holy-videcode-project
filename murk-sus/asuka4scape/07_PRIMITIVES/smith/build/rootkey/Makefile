TARGET = iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = RootKey
RootKey_FILES = main.m
RootKey_FRAMEWORKS = UIKit Foundation
RootKey_CFLAGS = -fobjc-arc -O2 -I.
RootKey_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
include $(THEOS)/makefiles/application.mk
RootKey_RESOURCE_FILES = Info.plist
