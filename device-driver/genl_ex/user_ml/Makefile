PWD := $(shell pwd) 
TARGET := genl_ml
SRC := main.c
HDR_DIR = /usr/include/
LDFLAGS = 

all:
	gcc $(SRC) $(LDFLAGS) -o $(TARGET)
clean:
	rm -fr $(TARGET)

.PHONY: tags tags-clean
tags: tags-clean
	find -L $(PWD) -iname "*.c" -o -iname "*.h"  > cscope.files
	find -L $(HDR_DIR) -iname "*.h" -exec realpath {} \; >> cscope.files
	cscope -Rbq
	ctags -R . $(HDR_DIR) --exclude=.git

tags-clean:
	rm -fr cscope*
	rm -fr tags

