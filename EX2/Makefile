#ifeq ($(KERNELRELEASE),) 
PWD :=$(shell pwd)
KERSRC := /lib/modules/$(shell uname -r)/build/ 
modules:
	$(MAKE) -C $(KERSRC) M=$(PWD) modules
moules_install:
	$(MAKE) -C $(KERSRC) M=$(PWD) modules_install
.PHONY:
	modules modules_install clean
clean:
	make -C $(KERSRC) M=$(PWD) clean
#Else
modules-objs :=mapDriver.o
obj-m := mapDriver.o
#endif
