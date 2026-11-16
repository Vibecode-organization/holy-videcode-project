TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = MKDIR
MKDIR_FILES = main.m
MKDIR_FRAMEWORKS = UIKit Foundation
MKDIR_CFLAGS = -Wno-everything
MKDIR_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
MKDIR_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
