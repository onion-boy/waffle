export CC 	:= gcc
export LNK	:= ld

export ROOT_DIR 	:= $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
export OBJECT_DIR 	:= obj
export BUILD_DIR	:= $(ROOT_DIR)/$(OBJECT_DIR)

EXEC 		:= waffle

OBJECT_DIR 	:= obj
SOURCE_DIR 	:= src
BINARY_DIR	:= bin
LIB 		:= engine

LIB_SRC		:= ../$(SOURCE_DIR)
COMBINED	:= $(LIB) $(LIB_SRC)
MODULES		:= $(BUILD_DIR)/$(SOURCE_DIR).o $(LIB:%=$(BUILD_DIR)/%.o)
OUTPUT		:= $(BINARY_DIR)/$(EXEC)
ALL_SOURCES := $(shell find . -name "*.c")

done 		:= (echo " > done :)" && echo)

.PHONY: clean done $(COMBINED)

done: $(OUTPUT)
	

$(OUTPUT): $(ALL_SOURCES)
	@mkdir -p $(@D)
	@echo " > building executable"
	@$(CC) $(MODULES) -o $@
	@$(call done)

$(ALL_SOURCES): $(COMBINED)

$(COMBINED): 
	@echo
	@$(MAKE) -C $(SOURCE_DIR)/$@

clean:
	@echo
	@echo " > deleting object and binary directories"
	@rm -rf $(OBJECT_DIR) $(BINARY_DIR)
	@$(call done)