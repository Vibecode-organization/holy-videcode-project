TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = AGXSubmit
AGXSubmit_FILES = main.m
AGXSubmit_FRAMEWORKS = UIKit IOKit Foundation IOSurface
AGXSubmit_CFLAGS = -Wno-everything
AGXSubmit_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
AGXSubmit_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
