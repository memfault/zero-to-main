ASF_PATH := ../xdk-asf-3.32.0
REPO_ROOT := $(shell git rev-parse --show-toplevel)

ifdef DEBUG
	NO_ECHO :=
else
	NO_ECHO := @
endif

SRCS += \
	$(ASF_PATH)/common/utils/interrupt/interrupt_sam_nvic.c \
	$(ASF_PATH)/common2/services/delay/sam0/cycle_counter.c \
	$(ASF_PATH)/sam0/drivers/port/port.c \
	$(ASF_PATH)/sam0/drivers/system/clock/clock_samd21_r21_da/clock.c \
	$(ASF_PATH)/sam0/drivers/system/clock/clock_samd21_r21_da/gclk.c \
	$(ASF_PATH)/sam0/drivers/system/pinmux/pinmux.c \
	$(ASF_PATH)/sam0/utils/cmsis/samd21/source/system_samd21.c

INCLUDES += \
	$(ASF_PATH)/common/utils \
	$(ASF_PATH)/common2/services/delay \
	$(ASF_PATH)/common2/services/delay/sam0 \
	$(ASF_PATH)/sam0/drivers/port \
	$(ASF_PATH)/sam0/drivers/system \
	$(ASF_PATH)/sam0/drivers/system/clock \
	$(ASF_PATH)/sam0/drivers/system/clock/clock_samd21_r21_da \
	$(ASF_PATH)/sam0/drivers/system/clock/clock_samd21_r21_da/module_config \
	$(ASF_PATH)/sam0/drivers/system/interrupt \
	$(ASF_PATH)/sam0/drivers/system/interrupt/system_interrupt_samd21 \
	$(ASF_PATH)/sam0/drivers/system/pinmux \
	$(ASF_PATH)/sam0/drivers/system/power/power_sam_d_r \
	$(ASF_PATH)/sam0/drivers/system/reset/reset_sam_d_r \
	$(ASF_PATH)/sam0/utils \
	$(ASF_PATH)/sam0/utils/cmsis/samd21/include \
	$(ASF_PATH)/sam0/utils/cmsis/samd21/source \
	$(ASF_PATH)/sam0/utils/header_files \
	$(ASF_PATH)/sam0/utils/preprocessor \
	$(ASF_PATH)/thirdparty/CMSIS/Include


CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
OCPY=arm-none-eabi-objcopy
ODUMP=arm-none-eabi-objdump
SZ=arm-none-eabi-size
OCD=arduino-openocd
MKDIR=mkdir

CFLAGS += \
	-mcpu=cortex-m0plus \
	-mthumb \
	-Wall \
	-Werror \
	-std=c11 \
	-O0 \
	-fdebug-prefix-map=$(REPO_ROOT)= \
	-g \
	-ffreestanding \
	-ffunction-sections \
	-fdata-sections

LDFLAGS += \
	-specs=nano.specs \
	-Wl,--gc-sections \
	-Wl,--print-memory-usage \
	-Wl,-Map=$(BUILD_DIR)/$(PROJECT).map \
	-T samd21g18a_flash.ld

DEFINES += \
	__SAMD21G18A__ \
	CYCLE_MODE

CFLAGS += $(foreach i,$(INCLUDES),-I$(i))
CFLAGS += $(foreach d,$(DEFINES),-D$(d))

OBJ_DIR = $(BUILD_DIR)/objs/a/b/c
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all
all: $(BUILD_DIR)/$(PROJECT).bin

$(BUILD_DIR):
	$(NO_ECHO)$(MKDIR) -p $(BUILD_DIR)

$(OBJ_DIR):
	$(NO_ECHO)$(MKDIR) -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c $(OBJ_DIR)
	@echo "Compiling $<"
	$(NO_ECHO)$(MKDIR) -p $(dir $@)
	$(NO_ECHO)$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/$(PROJECT).bin: $(BUILD_DIR)/$(PROJECT).elf $(BUILD_DIR)/$(PROJECT).lst
	$(OCPY) $< $@ -O binary
	$(SZ) $<

$(BUILD_DIR)/$(PROJECT).lst: $(BUILD_DIR)/$(PROJECT).elf $(BUILD_DIR)
	$(ODUMP) -D $< > $@

$(BUILD_DIR)/$(PROJECT).elf: $(OBJS)
	@echo "Linking $@"
	$(NO_ECHO)$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
