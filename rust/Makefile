PROJECT := rust
TARGET := thumbv6m-none-eabi
BUILD_DIR ?= build
CARGO = cargo

CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
OCPY=arm-none-eabi-objcopy
ODUMP=arm-none-eabi-objdump
SZ=arm-none-eabi-size
OCD=arduino-openocd
MKDIR=mkdir

.PHONY: all
all: $(BUILD_DIR)/$(PROJECT).bin

$(BUILD_DIR)/$(PROJECT).bin: $(BUILD_DIR)/$(TARGET)/debug/$(PROJECT)
	$(OCPY) $< $@ -O binary
	$(SZ) $<

.PHONY: $(BUILD_DIR)/$(TARGET)/debug/$(PROJECT)
$(BUILD_DIR)/$(TARGET)/debug/$(PROJECT):
	$(MKDIR) -p $(BUILD_DIR)
	CARGO_TARGET_DIR=$(BUILD_DIR) $(CARGO) build --target=$(TARGET)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
