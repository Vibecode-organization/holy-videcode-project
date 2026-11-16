TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = TaskZero
TaskZero_FILES = main.m
TaskZero_FRAMEWORKS = UIKit IOKit Foundation IOSurface
TaskZero_CFLAGS = -Wno-everything
TaskZero_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
TaskZero_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
