TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = MetalLeak
MetalLeak_FILES = main.m
MetalLeak_FRAMEWORKS = UIKit IOKit Foundation Metal
MetalLeak_CFLAGS = -Wno-everything
MetalLeak_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
MetalLeak_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
