export CC 	:= gcc
export LNK	:= ld

export ROOT_DIR 	:= $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
export OBJECT_DIR 	:= obj
export BUILD_DIR	:= $(ROOT_DIR)/$(OBJECT_DIR)

EXEC 		:= waffle

OBJECT_DIR 	:= obj
SOURCE_DIR 	:= src
BINARY_DIR	:= bin
LIB 		:= engine ../$(SOURCE_DIR)

REPLACE		:= $(wordlist 2,$(words $(LIB)),x $(LIB))
MODULES		:= $(BUILD_DIR)/$(subst ../,,$(lastword $(LIB))).o $(REPLACE:%=$(BUILD_DIR)/%.o)
OUTPUT		:= $(BINARY_DIR)/$(EXEC)

.PHONY: clean all

all: $(OUTPUT)
	@echo "done!"

$(LIB): 
	$(MAKE) -C $(SOURCE_DIR)/$@

$(OUTPUT): $(LIB)
	@mkdir -p $(@D)
	@echo "building executable..."
	$(CC) $(MODULES) -o $@

clean:
	rm -rf $(OBJECT_DIR) $(BINARY_DIR)