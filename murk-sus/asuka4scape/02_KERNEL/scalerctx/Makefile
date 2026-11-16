TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = ScalerCtx
ScalerCtx_FILES = main.m
ScalerCtx_FRAMEWORKS = UIKit IOKit Foundation IOSurface CoreVideo VideoToolbox CoreMedia
ScalerCtx_CFLAGS = -Wno-everything
ScalerCtx_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
ScalerCtx_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
