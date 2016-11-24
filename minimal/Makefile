PROJECT := minimal
BUILD_DIR ?= build

include ../common.mk

SRCS += \
	startup_samd21.c \
	$(PROJECT).c

.PHONY: all
all: $(BUILD_DIR)/$(PROJECT).bin

$(BUILD_DIR)/$(PROJECT).bin: $(BUILD_DIR)/$(PROJECT).elf $(BUILD_DIR)/$(PROJECT).lst
	$(OCPY) $< $@ -O binary

$(BUILD_DIR)/$(PROJECT).lst: $(BUILD_DIR)/$(PROJECT).elf
	$(ODUMP) -D $^ > $@

$(BUILD_DIR)/$(PROJECT).elf: $(SRCS)
	$(MKDIR) -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

