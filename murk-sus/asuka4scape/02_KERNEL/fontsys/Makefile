TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = FontSys
FontSys_FILES = main.m
FontSys_FRAMEWORKS = UIKit IOKit Foundation CoreText
FontSys_CFLAGS = -Wno-everything
FontSys_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
FontSys_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
