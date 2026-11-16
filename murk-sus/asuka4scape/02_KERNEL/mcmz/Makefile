TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = MCMZ
MCMZ_FILES = main.m
MCMZ_FRAMEWORKS = UIKit Foundation
MCMZ_CFLAGS = -Wno-everything
MCMZ_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
MCMZ_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
