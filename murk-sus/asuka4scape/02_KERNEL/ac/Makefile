TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = AgentCheck
AgentCheck_FILES = main.m
AgentCheck_FRAMEWORKS = UIKit Foundation
AgentCheck_CFLAGS = -Wno-everything
AgentCheck_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
AgentCheck_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
