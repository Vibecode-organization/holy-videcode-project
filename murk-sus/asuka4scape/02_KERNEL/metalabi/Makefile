TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = MetalABI
MetalABI_FILES = main.m
MetalABI_FRAMEWORKS = UIKit IOKit Foundation IOSurface Metal CoreVideo
MetalABI_CFLAGS = -Wno-everything
MetalABI_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
MetalABI_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
