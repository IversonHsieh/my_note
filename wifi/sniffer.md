Omnipeek
-------------------------------------------
##### Simple Usage
- Make filter -> Type:Advance
- And -> Protocol -> Specific ProtoSpec

Wireshark
-------------------------------------------
##### Usage Article
- [Wireless Display and Capture Filters Samples](http://www.lovemytool.com/blog/2010/02/wireshark-wireless-display-and-capture-filters-samples-by-joke-snelders.html)
- [Wireshark: Wireless Display and Capture Filters Samples part 2](http://www.lovemytool.com/blog/2010/07/wireshark-wireless-display-and-capture-filters-samples-part-2-by-joke-snelders.html)

##### Simple examples
filter PS-Poll
```sh
wlan.fc.type_subtype eq 0x1A
```

filter NULL data
```sh
wlan.fc.type_subtype eq 0x24
```

filter control frame
```sh
wlan.fc.type eq 1
```

filter wlan mac_addr and mgmt frame without probe response
```sh
wlan.addr eq 00:0C:43:87:81:AD and (wlan.fc.type eq 0) and (not wlan.fc.type_subtype eq 5)
```

