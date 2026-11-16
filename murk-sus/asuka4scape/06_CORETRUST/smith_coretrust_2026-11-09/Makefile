TARGET = iphone:clang:latest:14.0
ARCHS = arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME = ctoracle
ctoracle_FILES = main.m
ctoracle_FRAMEWORKS = UIKit Foundation
ctoracle_CFLAGS = -fobjc-arc -O2
ctoracle_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
ctoracle_RESOURCE_FILES = Info.plist orig.cms orig.cd fake.cms fake.cd

include $(THEOS)/makefiles/application.mk
