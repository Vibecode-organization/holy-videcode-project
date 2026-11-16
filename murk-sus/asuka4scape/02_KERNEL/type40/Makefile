TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = Type40
Type40_FILES = main.m
Type40_FRAMEWORKS = UIKit IOKit Foundation
Type40_CFLAGS = -Wno-everything
Type40_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
Type40_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
