TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = DEEP
DEEP_FILES = main.m
DEEP_FRAMEWORKS = UIKit Foundation
DEEP_CFLAGS = -Wno-everything
DEEP_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
DEEP_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
