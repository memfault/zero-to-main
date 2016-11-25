PROJECT := with-libc
BUILD_DIR ?= build

INCLUDES = \
	$(ASF_PATH)/sam0/drivers/sercom \
	$(ASF_PATH)/sam0/drivers/sercom/usart \
	$(ASF_PATH)/common/services/serial \
	$(ASF_PATH)/common/services/serial/sam0_usart

SRCS = \
	$(ASF_PATH)/sam0/drivers/sercom/usart/usart.c \
	$(ASF_PATH)/sam0/drivers/sercom/sercom.c \
	startup_samd21.c \
	$(PROJECT).c

include ../common.mk

