SRCEXT         := c
OBJEXT         := o
HEADEREXT      := h

## directories

SRC_DIR        := src
BUILD_DIR      := build
TARGET_DIR     := target
INCLUDE_DIR    := include

REQ_DIRS       := $(BUILD_DIR) $(TARGET_DIR)

## compiler options

LIB_NAME       := shsc

WRN_ERR_FLAGS  := -Wall\
				  -Wno-unused-but-set-variable\
				  -Wno-unused-label\
				  -Wno-int-in-bool-context
ASAN_FLAGS	 := -fsanitize=address
ASAN_OPTIONS   := ASAN_OPTIONS=detect_leaks=1:$\
				  fast_unwind_on_malloc=0:$\
				  strict_init_order=true:$\
				  strict_string_checks=true:$\
				  check_initialization_order=true:$\
				  abort_on_error=1:$\
				  symbolize=1:$\
				  verbosity=0:$\
				  halt_on_error=0

CC             := gcc
CFLAGS         := $(WRN_ERR_FLAGS) -Ofast
CDBGFLAGS      := $(WRN_ERR_FLAGS) -g $(ASAN_FLAGS) -D DEBUG
DBG            := gdb -q

INCLUDE        := -I $(INCLUDE_DIR)
LIB            := -lm
DBG_LIB        := -lm

## targets
# Detect the operating system
ifeq ($(OS),Windows_NT)
	TARGET_EXTENSION := .lib
else
	TARGET_EXTENSION := .a
endif

TARGET_NAME    := $(LIB_NAME)
TARGET         := $(TARGET_DIR)/lib$(TARGET_NAME)-rel$(TARGET_EXTENSION)
DBG_TARGET     := $(TARGET_DIR)/lib$(TARGET_NAME)-dbg$(TARGET_EXTENSION)

SOURCES        := $(shell find $(SRC_DIR)/ -name "*."$(SRCEXT)) $(shell find $(SRC_DIR)/ -name "*".$(SRCEXT).$(HEADEREXT))
HEADERS        := $(shell find $(INCLUDE_DIR)/ -name "*."$(HEADEREXT))

## release build

rel: $(TARGET)

OBJECTS        := $(patsubst $(SRC_DIR)/%.$(SRCEXT), $(BUILD_DIR)/%-rel.$(OBJEXT), $(shell find $(SRC_DIR)/ -name "*."$(SRCEXT)))

$(OBJECTS): $(SOURCES) $(HEADERS)
	@cd $(SRC_DIR) && $(MAKE)

## target for executable
$(TARGET): $(REQ_DIRS) $(OBJECTS)
	ar rcs $(TARGET) $(BUILD_DIR)/*-rel.$(OBJEXT)

# Get the first 27 characters of the PREFIX environment variable
PREFIX_SUBSTRING := $(shell echo $${PREFIX} | cut -c 1-27)

## debug build

dbg: $(DBG_TARGET)

DBG_OBJECTS    := $(patsubst $(SRC_DIR)/%.$(SRCEXT), $(BUILD_DIR)/%-dbg.$(OBJEXT), $(shell find $(SRC_DIR)/ -name "*."$(SRCEXT)))

$(DBG_OBJECTS): $(SOURCES) $(HEADERS)
	@cd $(SRC_DIR) && $(MAKE) dbg

## target for debug executable
$(DBG_TARGET): $(REQ_DIRS) $(DBG_OBJECTS)
	ar rcs $(DBG_TARGET) $(BUILD_DIR)/*-dbg.$(OBJEXT)

## $(REQ_DIRS)

$(BUILD_DIR):
	@mkdir -p $(TARGET_DIR)

$(TARGET_DIR):
	@mkdir -p $(TARGET_DIR)

## cleanup

clean:
	@cd $(SRC_DIR) && $(MAKE) clean

cleaner:
	@cd $(SRC_DIR) && $(MAKE) cleaner
	@rm -rf $(BUILD_DIR)
	@rm -rf $(TARGET)
	@rm -rf $(DBG_TARGET)
	@rm -rf $(TARGET_DIR)
