TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = Type80B
Type80B_FILES = main.m
Type80B_FRAMEWORKS = UIKit IOKit Foundation IOSurface
Type80B_CFLAGS = -Wno-everything
Type80B_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
Type80B_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
