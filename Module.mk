LD_FLAGS	:= -r
C_FLAGS		:= -g

OUT_DIR		:= $(BUILD_DIR)/$(MODULE_NAME)
OBJECTS		:= $(SOURCES:%.c=$(OUT_DIR)/%.o)

$(OUT_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@echo " > building object $@"
	@$(CC) -c $< -o $@

$(OUT_DIR).o: $(OBJECTS)
	@echo " > combining"
	@echo
	@$(LNK) $(LD_FLAGS) $^ -o $@