PWD := $(shell pwd) 
HDR_DIR = /usr/include/
HDR2_DIR = /home/crtt/src/linux_lib/libnl-3.2.27/include
LIB_DIR = /home/crtt/src/linux_lib/libnl-3.2.27/lib/.libs
LIB_SRC = /home/crtt/src/linux_lib/libnl-3.2.27/
LDFLAGS = -lnl-3 -lnl-genl-3
 
all:
	gcc genl_grp.c -I$(HDR2_DIR) -L$(LIB_DIR) $(LDFLAGS)  -o genl_grp
clean:
	rm -fr genl_grp

.PHONY: tags tags-clean
tags: tags-clean
	find -L $(PWD) -iname "*.c" -o -iname "*.h"  > cscope.files
	find -L $(HDR_DIR) -iname "*.h" -exec realpath {} \; >> cscope.files
	find -L $(LIB_SRC) \( -iname "*.c" -o -iname "*.h" \) -exec realpath {} \; >> cscope.files
	cscope -Rbq
	ctags -R . $(HDR2_DIR) $(LIB_SRC) --exclude=.git

tags-clean:
	rm -fr cscope*
	rm -fr tags

