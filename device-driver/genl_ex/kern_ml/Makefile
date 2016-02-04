PWD := $(shell pwd) 
KVERSION := $(shell uname -r)
KERNEL_DIR = /usr/src/linux-headers-$(KVERSION)/
 
MODULE_NAME = genl_kern_grp
obj-m := $(MODULE_NAME).o

all:
	make -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	make -C $(KERNEL_DIR) M=$(PWD) clean

.PHONY: tags tags-clean
tags: tags-clean
	find -L $(PWD) -iname "*.c" -o -iname "*.h" > cscope.files
	find -L $(KERNEL_DIR) -iname '*.h' -exec realpath {} \; >> cscope.files
	cscope -Rbq
	ctags -R . $(KERNEL_DIR)  --exclude=.git

tags-clean:
	rm -fr cscope*
	rm -fr tags

