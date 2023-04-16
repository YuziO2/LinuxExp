obj-m += device_driver.o

CURRENT_PATH := $(shell pwd)
LINUX_KERNEL := $(shell uname -r)
LINUX_KERNEL_PATH := /usr/lib/modules/$(shell uname -r)

all:
	make -C $(LINUX_KERNEL_PATH)/build M=$(CURRENT_PATH) modules
clean:
	make -C $(LINUX_KERNEL_PATH)/build M=$(CURRENT_PATH) clean