PWD := $(shell pwd) 
KVERSION := $(shell uname -r)
KERNEL_DIR = /usr/src/linux-headers-$(KVERSION)/
KERNEL_SRC_DIR = /usr/src/linux-source-3.19.0/

MODULE_NAME = mylist
obj-m := $(MODULE_NAME).o
$(MODULE_NAME)-objs := main.o

all:
	make -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	make -C $(KERNEL_DIR) M=$(PWD) clean

.PHONY: tags tags-clean
tags: tags-clean
	find -L $(PWD) -iname "*.c" -o -iname "*.h" > cscope.files
#	find -L $(KERNEL_DIR) -iname '*.h' -exec realpath {} \; >> cscope.files
	find -L $(KERNEL_SRC_DIR) -iname '*.h' -exec realpath {} \; >> cscope.files
	find -L $(KERNEL_SRC_DIR) -iname '*.c' -exec realpath {} \; >> cscope.files
#	find -L $(KERNEL_SRC_DIR) -iname '*.h' -o -iname '*.c' >> cscope.files
	cscope -Rbq
	ctags -R -L cscope.files

tags-clean:
	rm -fr cscope*
	rm -fr tags

