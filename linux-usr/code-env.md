Record Linux Environment Configuration
--------------------------------------------
#### Vim
	
- [vim-color-scheme][vimco]
[vimco]: http://monster-log.blogspot.tw/2010/12/vim-color-scheme-test.html)
	

#### ctags/cscope

- [cscope-tuition](http://hamisme.blogspot.tw/2011/02/cscope.html)
- [cscope-ctags-tuition](http://angledark0123.pixnet.net/blog/post/51919594-vim%E9%99%84%E4%BB%B6%EF%BC%9Acscope%2Bctag-%E4%BD%BF%E7%94%A8%E7%AD%86%E8%A8%98)
- [taglist-tuitiion](http://nelsonchunglife.blogspot.tw/2011/06/ubuntuvim-plugin-ctagstaglist.html)

#### cscope command:

	$ find [path] -name '*.h' -o -name '*.c' -o -name '*.cpp' > cscope.files
	$ find [path] -name '*.h' -o -name '*.c' -o -name '*.cpp' >> cscope.files
	ex : find -L `pwd` -iname "*.c" -o -iname "*.h" > cscope.files
	ex : find -L /usr/src/linux-headers-3.19.0-15-generic/ -iname '*.h' -exec realpath {} \; >> cscope.files

	$ cscope -Rbq
	$ cscope

Use `TAB` to jump to search area.

Use `CTRL+D` to quit cscope.

#### ctags command:

	$ ctags -R . /usr/src/linux-headers-3.19.0-15-generic/include/ --exclude=.git

#### taglist command:

donwload taglist and install to vim

	$ wget -O taglist.zip http://vim.sourceforge.net/scripts/download_script.php?src_id=19574
	$ unzip taglist.zip
	$ cp -a doc/ ~/.vim
	$ cp -a plugin/ ~/.vim

add mapping `map <f9> :Tlist<CR>` to .vimrc

	$ vim ~/.vimrc


