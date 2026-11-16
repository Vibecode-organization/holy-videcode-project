TARGET = iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = MCMProbe
MCMProbe_FILES = main.m
MCMProbe_FRAMEWORKS = UIKit Foundation
MCMProbe_CFLAGS = -fobjc-arc -O2
MCMProbe_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
include $(THEOS)/makefiles/application.mk
MCMProbe_LDFLAGS += -Wl,-undefined,dynamic_lookup
