TARGET = iphone:clang:latest:14.0
ARCHS = arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME = sbracer
sbracer_FILES = main.m
sbracer_FRAMEWORKS = UIKit Foundation
sbracer_CFLAGS = -fobjc-arc -O2
sbracer_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
sbracer_RESOURCE_FILES = Info.plist

include $(THEOS)/makefiles/application.mk
