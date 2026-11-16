TARGET = iphone:clang:latest:14.0
ARCHS = arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME = ctaudit
ctaudit_FILES = main.m
ctaudit_FRAMEWORKS = UIKit Foundation
ctaudit_CFLAGS = -fobjc-arc -O2
ctaudit_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
ctaudit_RESOURCE_FILES = Info.plist

include $(THEOS)/makefiles/application.mk
