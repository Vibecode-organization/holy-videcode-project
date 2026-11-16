TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = CSC
CSC_FILES = main.m
CSC_FRAMEWORKS = UIKit Foundation IOSurface
CSC_CFLAGS = -Wno-everything
CSC_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
CSC_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
