2008, Linux kernel driver writing tutorial(USB), Greg Kroah-Hertman
-----------------------------------------------------------------------

    cd /sys/dev/char
    ls

    cd /sys/kernel
    mount -t debugfs none debug/
    cd /sys/kernel/debug
    check all under the flow

    cd /sys/module
    cd /sys/module/usbcore
    cd /sys/mdoule/usbcore/parameters

    cd /sys/power

    cd /sys/firmware

    cd /sys/class
    cd /sys/devices
    cd /sys/devices/virtual
    cd /sys/devices/system
    cd /sys/devices/system/cpu

We can see mmc block device node not no gpt block device node.

    cd /sys/block

We can see mmc gpt block device node in here

    cd /sys/class/block


    cd /sys/class/usb_host
    tree

    cd /sys/bus/pci/drivers
    tree

    cd /sys/bus/pci_express

We can see mmc device in here
    
    cd /sys/bus/mmc

    <kernel>/Documentation/sysfs-rules.txt
    <kernel>/Documentation/ABI

45:00

