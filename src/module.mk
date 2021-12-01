OUT_DIR		:= $(BUILD_DIR)/$(MODULE_NAME)
OBJECTS		:= $(SOURCES:%.c=$(OUT_DIR)/%.o)

all: link

link: $(OBJECTS)
	$(LNK) $(LD_FLAGS) $(OBJECTS) -o $(OUT_DIR).o

$(OUT_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@