Linux commands
--------------------------------------------
##### Watch something periodically

    $ watch -n1 -d cat /proc/meminfo

##### Check disk utilization

    $ df . -h

##### [Modify dhcp client to static ip](http://askubuntu.com/questions/470237/assigning-a-static-ip-to-ubuntu-server-14-04-lts)

	# ubuntu 15.10
	$ vim /etc/network/interfaces

	auto eth0
	iface eth0 inet static
	   address 192.168.179.184
	   netmask 255.255.255.0
	   network 192.168.179.0
	   gateway 192.168.179.2
	   dns-nameservers 192.168.179.2

##### [Get dns servier info](http://askubuntu.com/questions/191563/how-to-view-the-dns-address-assigned-by-dhcp)

	$ nmcli device show eth0 | grep IP4
	
