SRCEXT         := c
OBJEXT         := o
HEADEREXT      := h

## directories

SRC_DIR        := ../src
BUILD_DIR      := ../build
TARGET_DIR     := ../target
INCLUDE_DIR    := ../include

## compiler options

EXEC_NAME      := shsc

WRN_ERR_FLAGS  := -Wall\
				  -Wno-unused-but-set-variable\
				  -Wno-unused-label\
				  -Wno-int-in-bool-context
ASAN_FLAGS	   := -fsanitize=address
ASAN_OPTIONS   := ASAN_OPTIONS=detect_leaks=1:$\
				  fast_unwind_on_malloc=0:$\
				  strict_init_order=true:$\
				  strict_string_checks=true:$\
				  check_initialization_order=true:$\
				  abort_on_error=1:$\
				  symbolize=1:$\
				  verbosity=0:$\
				  halt_on_error=0

CC             ?= clang
CFLAGS         := $(WRN_ERR_FLAGS) -Ofast -fPIC
CDBGFLAGS      := $(WRN_ERR_FLAGS) -g $(ASAN_FLAGS) -D DEBUG -fPIC
DBG            := gdb -q

INCLUDE        := -I $(INCLUDE_DIR) -I $(SRC_DIR)
LIB            := -lm
DBG_LIB        := -lm

HEADERS        := $(shell find $(INCLUDE_DIR)/ -name "*."$(HEADEREXT))

SUB_DIRS       := $(shell find -type f -name Makefile | sed 's/Makefile//g')
SUB_DIR_DBG    := $(SUB_DIRS)

## release build

OBJECTS        := $(patsubst %.$(SRCEXT), %-rel.$(OBJEXT), $(wildcard *.$(SRCEXT)))

rel: mkdirp $(OBJECTS) cpobj

%-rel.$(OBJEXT): %.$(SRCEXT) $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

## build subdirs
# $(SUB_DIRS): FORCE
# @$(MAKE) -C $@

## debug build

DBG_OBJECTS    := $(patsubst %.$(SRCEXT), %-dbg.$(OBJEXT), $(wildcard *.$(SRCEXT)))

dbg: mkdirp $(DBG_OBJECTS) cpobj

%-dbg.$(OBJEXT): %.$(SRCEXT) $(HEADERS)
	$(CC) $(CDBGFLAGS) $(INCLUDE) -c -o $@ $<

## build subdirs
# $(SUB_DIR_DBG): FORCE
#     @$(MAKE) -C $@ dbg

cpobj:
	@cp *.$(OBJEXT) $(BUILD_DIR)

mkdirp:
	@mkdir -p $(BUILD_DIR)

clean:
	@rm -f *.$(OBJEXT)

cleaner: clean
	@rm -f $(BUILD_DIR)/*.$(OBJEXT)

## FORCE:
