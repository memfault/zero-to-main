PROJECTS := \
		bootload-reloc \
		reloc \
		bootload \
		with-libc \
		minimal \
		default


OCD := arduino-openocd
RM := rm
BUILD_DIR := $(CURDIR)/build

$(PROJECTS):
	$(MAKE) -C $@ BUILD_DIR=$(BUILD_DIR)/$@

FLASH_TARGETS = $(patsubst %,flash-%,$(PROJECTS))

$(FLASH_TARGETS):
	$(eval PROJ := $(subst flash-,,$@))
	$(OCD) -d2 -f openocd.cfg -c "program {{build/$(PROJ)/$(PROJ).bin}} verify reset; shutdown"

all: $(PROJECTS)

clean:
	$(RM) -r build 2>/dev/null || true

.PHONY: clean all $(PROJECTS)