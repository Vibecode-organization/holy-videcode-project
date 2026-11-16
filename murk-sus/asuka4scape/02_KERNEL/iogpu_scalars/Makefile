TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = IOGPUScalars
IOGPUScalars_FILES = main.m
IOGPUScalars_FRAMEWORKS = UIKit IOKit Foundation
IOGPUScalars_CFLAGS = -Wno-everything
IOGPUScalars_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
IOGPUScalars_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
