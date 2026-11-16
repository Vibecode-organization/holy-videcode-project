TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = FontCheck
FontCheck_FILES = main.m
FontCheck_FRAMEWORKS = UIKit IOKit Foundation CoreText
FontCheck_CFLAGS = -Wno-everything
FontCheck_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
FontCheck_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
