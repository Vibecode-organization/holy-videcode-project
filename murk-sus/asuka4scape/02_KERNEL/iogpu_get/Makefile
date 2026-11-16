TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = IOGPUGet
IOGPUGet_FILES = main.m
IOGPUGet_FRAMEWORKS = UIKit IOKit Foundation
IOGPUGet_CFLAGS = -Wno-everything
IOGPUGet_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
IOGPUGet_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
