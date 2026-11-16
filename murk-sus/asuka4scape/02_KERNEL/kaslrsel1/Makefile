TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = KaslrSel1
KaslrSel1_FILES = main.m
KaslrSel1_FRAMEWORKS = UIKit IOKit Foundation
KaslrSel1_CFLAGS = -Wno-everything
KaslrSel1_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
KaslrSel1_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
