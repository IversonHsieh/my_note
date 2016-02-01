PWD := $(shell pwd) 
LIB_DIR = /usr/include/
 
MODULE_NAME = genl_user

all:
	gcc genl_user.c -o genl_user
clean:
	rm -fr genl_user

.PHONY: tags tags-clean
tags: tags-clean
	find -L $(PWD) -iname "*.c" -o -iname "*.h" > cscope.files
	find -L $(LIB_DIR) -iname '*.h' -exec realpath {} \; >> cscope.files
	cscope -Rbq
	ctags -R . $(LIB_DIR)  --exclude=.git

tags-clean:
	rm -fr cscope*
	rm -fr tags

