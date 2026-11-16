TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = JpegReal
JpegReal_FILES = main.m
JpegReal_FRAMEWORKS = UIKit IOKit Foundation ImageIO CoreGraphics
JpegReal_CFLAGS = -Wno-everything
JpegReal_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
JpegReal_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
