TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = SLASH
SLASH_FILES = main.m
SLASH_FRAMEWORKS = UIKit Foundation
SLASH_CFLAGS = -Wno-everything
SLASH_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
SLASH_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
