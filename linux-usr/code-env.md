Record Linux Environment Configuration
--------------------------------------------
##### Vim
	
- [vim-color-scheme][vimco]
[vimco]: http://monster-log.blogspot.tw/2010/12/vim-color-scheme-test.html)
	

##### ctags/cscope

- [cscope-tuition](http://hamisme.blogspot.tw/2011/02/cscope.html)
- [cscope-ctags-tuition](http://angledark0123.pixnet.net/blog/post/51919594-vim%E9%99%84%E4%BB%B6%EF%BC%9Acscope%2Bctag-%E4%BD%BF%E7%94%A8%E7%AD%86%E8%A8%98)
- [taglist-tuitiion](http://nelsonchunglife.blogspot.tw/2011/06/ubuntuvim-plugin-ctagstaglist.html)
- [screen-tuitiion](http://blogger.gtwang.org/2013/11/screen-command-examples-to-manage-linux-terminals.html)

##### cscope command:

Include database automatically - `cs add .` to `~/.vimrc` 

	$ find [path] -name '*.h' -o -name '*.c' -o -name '*.cpp' > cscope.files
	$ find [path] -name '*.h' -o -name '*.c' -o -name '*.cpp' >> cscope.files
	ex : find -L `pwd` -iname "*.c" -o -iname "*.h" > cscope.files
	ex : find -L /usr/src/linux-headers-3.19.0-15-generic/ -iname '*.h' -exec realpath {} \; >> cscope.files

	$ cscope -Rbq
	$ cscope

Use `TAB` to jump to search area.  
Use `CTRL+D` to quit cscope.
Use [cscopequickfix](http://stackoverflow.com/questions/28185067/vim-go-to-next-search-result-across-multiple-files), add below to `~/.vimrc`

	set cscopequickfix=s-,c-,d-,i-,t-,e-
	augroup qf
	    autocmd!
	    autocmd QuickFixCmdPost * cwindow
	augroup END

`tab cs f s` is abnormal when we use cscopequickfix so use `:tabnew [filename]` to tab a file.

[Cscope key map](http://cscope.sourceforge.net/cscope_maps.vim)

	nmap <C-\>s :cs find s <C-R>=expand("<cword>")<CR><CR>
	nmap <C-\>g :cs find g <C-R>=expand("<cword>")<CR><CR>
	nmap <C-\>c :cs find c <C-R>=expand("<cword>")<CR><CR>
	nmap <C-\>t :cs find t <C-R>=expand("<cword>")<CR><CR>
	nmap <C-\>e :cs find e <C-R>=expand("<cword>")<CR><CR>
	nmap <C-\>f :cs find f <C-R>=expand("<cfile>")<CR><CR>
	nmap <C-\>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
	nmap <C-\>d :cs find d <C-R>=expand("<cword>")<CR><CR>

##### ctags command:

	# Add file list
	$ ctags -R -L cscope.files
	# Add folders specified in command line
	$ ctags -R . /usr/src/linux-headers-3.19.0-15-generic/include/ --exclude=.git

[Open a new tab and vertical split][ctags_tab], add below to `~/.vim`
[ctags_tab]: http://stackoverflow.com/questions/563616/vim-and-ctags-tips-and-tricks

	map <C-t> :tab split<CR>:exec("tag ".expand("<cword>"))<CR>
	map <C-v> :vsp <CR>:exec("tag ".expand("<cword>"))<CR>

##### taglist command:

donwload taglist and install to vim

	$ wget -O taglist.zip http://vim.sourceforge.net/scripts/download_script.php?src_id=19574
	$ unzip taglist.zip
	$ cp -a doc/ ~/.vim
	$ cp -a plugin/ ~/.vim

add mapping `map <f9> :Tlist<CR>` to .vimrc  
modify taglist window size `let Tlist_WinWidth = somenumber` to .vimrc

##### vim command:

vim environemnt, add to `~\.vimrc`

	"vim screen
	syntax on
	set t_Co=256
	set number
	set hlsearch!
	colorscheme candy
	"set expandtab
	set tabstop=4
	set shiftwidth=4

Switch tab  
- next tab page - `gt`
- prev tab page - `gT`
- go to tab page {count} - `{count}gt`

Highlight multiword in vim command - `/\vword1|word2|word3` or `/word1\|word2\|word3`  
Adjust window size - `set mouse=a` and `set ttymouse=xterm2` to `~/.vimrc`
Disable adjusting window size - `set mouse=""`

##### screen command:

	# Create a screean
	$ screen -S [name]
	# See all screen task
	$ screen -ls
	# Detach a screen [CTRL+a][d]
	$ screen -d [pid]
	# Attach a screen
	$ screen -r [pid]



