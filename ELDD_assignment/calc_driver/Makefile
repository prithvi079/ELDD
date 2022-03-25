obj-m := cal.o
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

install:
	$(MAKE) -C $(KDIR) M=$(PWD) modules_install
	gcc ADD.c -o ADD.o
	gcc SUB.c -o SUB.o
	gcc MUL.c -o MUL.o
	gcc DIV.c -o DIV.o
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm -rf ADD.o SUB.o MUL.o DIV.o
