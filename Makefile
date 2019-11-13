PROJECTS := \
		rust \
		bootload-reloc \
		reloc \
		bootload \
		with-libc \
		minimal \
		default


OCD := openocd
RM := rm
BUILD_DIR := $(CURDIR)/build

OPENOCD_CFG := openocd.cfg

$(PROJECTS):
	$(MAKE) -C $@ BUILD_DIR=$(BUILD_DIR)/$@

FLASH_TARGETS = $(patsubst %,flash-%,$(PROJECTS))

$(FLASH_TARGETS): $(OPENOCD_CFG)
	$(eval PROJ := $(subst flash-,,$@))
	$(OCD) -d2 -f $< -c "program {{build/$(PROJ)/$(PROJ).bin}} verify reset; shutdown"

unlock: $(OPENOCD_CFG)
	$(OCD) -d2 -f $< -c "init; halt; at91samd bootloader 0; reset; shutdown"

all: $(PROJECTS)

clean:
	$(RM) -r build 2>/dev/null || true

.PHONY: clean all unlock $(PROJECTS) $(FLASH_TARGETS)