TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = MCMY
MCMY_FILES = main.m
MCMY_FRAMEWORKS = UIKit Foundation
MCMY_CFLAGS = -Wno-everything
MCMY_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
MCMY_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
