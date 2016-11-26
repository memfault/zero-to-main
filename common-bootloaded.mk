ASF_PATH = ../xdk-asf-3.32.0

SRCS += \
	$(ASF_PATH)/common/utils/interrupt/interrupt_sam_nvic.c \
	$(ASF_PATH)/common2/services/delay/sam0/cycle_counter.c \
	$(ASF_PATH)/sam0/drivers/port/port.c \
	$(ASF_PATH)/sam0/drivers/system/clock/clock_samd21_r21_da/clock.c \
	$(ASF_PATH)/sam0/drivers/system/clock/clock_samd21_r21_da/gclk.c \
	$(ASF_PATH)/sam0/drivers/system/pinmux/pinmux.c \
	$(ASF_PATH)/sam0/utils/cmsis/samd21/source/system_samd21.c

SRCS_BOOT += $(SRCS)
SRCS_APP += $(SRCS)

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
	-g \
	-ffreestanding \
	-ffunction-sections \
	-fdata-sections

LDFLAGS += \
	-specs=nano.specs \
	-Wl,--gc-sections \
	-Wl,-Map=$(BUILD_DIR)/$(PROJECT).map

LDFLAGS_BOOT = $(LDFLAGS) -T samd21g18a_flash-boot.ld
LDFLAGS_APP = $(LDFLAGS) -T samd21g18a_flash-app.ld

DEFINES += \
	__SAMD21G18A__ \
	CYCLE_MODE

CFLAGS += $(foreach i,$(INCLUDES),-I$(i))
CFLAGS += $(foreach d,$(DEFINES),-D$(d))

.PHONY: all
all: $(BUILD_DIR)/$(PROJECT).bin

$(BUILD_DIR)/$(PROJECT).bin: $(BUILD_DIR)/$(PROJECT)-boot.bin $(BUILD_DIR)/$(PROJECT)-app.bin
	cat $^ > $@

$(BUILD_DIR)/$(PROJECT)-app.bin: $(BUILD_DIR)/$(PROJECT)-app.elf
	$(OCPY) $< $@ -O binary
	$(SZ) $<

$(BUILD_DIR)/$(PROJECT)-boot.bin: $(BUILD_DIR)/$(PROJECT)-boot.elf
	$(OCPY) --pad-to=0x10000 --gap-fill=0xFF -O binary $< $@
	$(SZ) $<

$(BUILD_DIR)/$(PROJECT)-app.elf: $(SRCS_APP)
	$(MKDIR) -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS_APP) $^ -o $@

$(BUILD_DIR)/$(PROJECT)-boot.elf: $(SRCS_BOOT)
	$(MKDIR) -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS_BOOT) $^ -o $@


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
