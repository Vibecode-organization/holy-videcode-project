TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = SYSID
SYSID_FILES = main.m
SYSID_FRAMEWORKS = UIKit Foundation
SYSID_CFLAGS = -Wno-everything
SYSID_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
SYSID_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
