TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = MCMX
MCMX_FILES = main.m
MCMX_FRAMEWORKS = UIKit Foundation
MCMX_CFLAGS = -Wno-everything
MCMX_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
MCMX_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
