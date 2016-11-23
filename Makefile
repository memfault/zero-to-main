PROJECTS := \
		default

RM := rm
BUILD_DIR := $(CURDIR)/build

$(PROJECTS):
	$(MAKE) -C $@ BUILD_DIR=$(BUILD_DIR)/$@

all: $(PROJECTS)

clean:
	$(RM) -r build 2>/dev/null || true

.PHONY: clean all $(PROJECTS)