TARGET = iphone:clang:latest:14.0
ARCHS = arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME = ctauditfuzz
ctauditfuzz_FILES = main.m
ctauditfuzz_FRAMEWORKS = UIKit Foundation
ctauditfuzz_CFLAGS = -fobjc-arc -O2
ctauditfuzz_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
ctauditfuzz_RESOURCE_FILES = Info.plist orig.cms orig.cd fake.cms fake.cd

include $(THEOS)/makefiles/application.mk
