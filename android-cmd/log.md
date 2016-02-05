Record Android log usage
----------------------------------------
##### watch klog

In system/core/libcutils/klog.c, we can find a function klog_init() which opens a `/dev/kmsg` device node and write log to the device node.

	$ cat /dev/kmsg

#####



