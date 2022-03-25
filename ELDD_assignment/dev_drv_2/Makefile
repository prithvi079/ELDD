
obj-m := char-dvr-2.o

KERNSRC := /lib/modules/$(shell uname -r)/build

PWD := $(shell pwd)

modules:
	make -C $(KERNSRC) M=$(PWD) modules
	gcc -o Application Application.c

modules_install:
	make -C $(KERNSRC) M=$(PWD) modules_install
	depmod -a

clean:
	make -C $(KERNSRC) M=$(PWD) clean
	rm -rf Application
