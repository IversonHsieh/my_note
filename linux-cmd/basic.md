Linux commands
--------------------------------------------
##### Watch something periodically
```sh
$ watch -n1 -d cat /proc/meminfo
```

##### Check disk utilization
```sh
$ df . -h
```

##### [apt-get or apt-cache](http://www.tecmint.com/useful-basic-commands-of-apt-get-and-apt-cache-for-package-management/)

Install or Upgrade Specific Packages
```sh
$ sudo apt-get install [pkg1]
$ sudo apt-get install [pkg1] [pkg2]
$ sudo apt-get install '*name*'
```
Remove Packages Without Configuration
```sh
$ sudo apt-get remove vsftpd
```

Completely Remove Packages
```sh
$ sudo apt-get purge vsftpd
```

Update System Packages
```sh
$ sudo apt-get update
```

Upgrade Software Packages
```sh
$ sudo apt-get upgrade
```

Check Package Information  
```sh
$ apt-cache show nodejs
```

Check Dependencies for Specific Packages
```sh
$ apt-cache showpkg nodejs
```


##### [Modify dhcp client to static ip](http://askubuntu.com/questions/470237/assigning-a-static-ip-to-ubuntu-server-14-04-lts)

```sh
# ubuntu 15.10
$ vim /etc/network/interfaces
```
```sh
auto eth0
iface eth0 inet static
   address 192.168.179.184
   netmask 255.255.255.0
   network 192.168.179.0
   gateway 192.168.179.2
   dns-nameservers 192.168.179.2
```
##### [Get dns servier info](http://askubuntu.com/questions/191563/how-to-view-the-dns-address-assigned-by-dhcp)
```sh
$ nmcli device show eth0 | grep IP4
```

##### [Checking your Ubuntu Version](https://help.ubuntu.com/community/CheckingYourUbuntuVersion)
```sh
$ lsb_release -a
```

