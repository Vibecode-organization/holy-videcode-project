THEOS ?= /opt/theos
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

LIBRARY_NAME := NewjailLog
NewjailLog_FILES := hook.m
NewjailLog_FRAMEWORKS := Foundation UIKit
NewjailLog_CFLAGS := -fobjc-arc -O2 -Wall -Wno-unused-function -Wno-deprecated-declarations
NewjailLog_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0

include $(THEOS)/makefiles/library.mk
