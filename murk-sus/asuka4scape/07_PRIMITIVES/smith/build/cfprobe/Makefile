TARGET = iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = CFProbe
CFProbe_FILES = main.m
CFProbe_FRAMEWORKS = UIKit Foundation CoreFoundation
CFProbe_CFLAGS = -fobjc-arc -O2
CFProbe_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
include $(THEOS)/makefiles/application.mk
