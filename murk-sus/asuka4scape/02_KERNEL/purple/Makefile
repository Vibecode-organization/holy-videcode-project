TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = Purple
Purple_FILES = main.m
Purple_FRAMEWORKS = UIKit IOKit Foundation IOSurface
Purple_CFLAGS = -Wno-everything
Purple_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
Purple_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
