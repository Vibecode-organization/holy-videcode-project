TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = PARENT
PARENT_FILES = main.m
PARENT_FRAMEWORKS = UIKit Foundation
PARENT_CFLAGS = -Wno-everything
PARENT_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
PARENT_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
