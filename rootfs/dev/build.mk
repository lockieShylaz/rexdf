include dev/null/build.mk
include dev/sdcard/build.mk
include dev/sramdisk/build.mk
include dev/ttyd/build.mk
include dev/keybd/build.mk
include dev/moused/build.mk
include dev/kevent/build.mk
include dev/consoled/build.mk
include dev/xmand/build.mk
include dev/fbd/build.mk
include dev/procd/build.mk

EXTRA_CLEAN += $(PROGRAM)
