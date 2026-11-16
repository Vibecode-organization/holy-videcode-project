TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = ENUM
ENUM_FILES = main.m
ENUM_FRAMEWORKS = UIKit Foundation
ENUM_CFLAGS = -Wno-everything -fblocks
ENUM_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
ENUM_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
