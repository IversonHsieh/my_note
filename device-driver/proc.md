Record some useful proc command
---------------------------------------------
#### man-page - [proc(5)][so_man]
[so_man]: http://man7.org/linux/man-pages/man5/proc.5.html

#### Disable kernel log

    $ echo 0 > /proc/sys/kernel/printk

#### Check kernel cmdline

    $ cat /proc/cmdline

#### [Check scoket buffer][socket]
[socket]: http://man7.org/linux/man-pages/man7/socket.7.html

Receive buffer
	
	$ cat /proc/sys/net/core/rmem_default
	$ cat /proc/sys/net/core/rmem_max

Write buffer

	$ cat /proc/sys/net/core/wmem_default
	$ cat /proc/sys/net/core/wmem_max

