Record netlink information
------------------------------------------
#### See netlink info - [netlink(3), netlink(7)][man-page]
[man-page]: https://www.kernel.org/doc/man-pages/

#### [Netlink Protocol Library Suite (libnl)][libnl-web]
[libnl-web]: https://www.infradead.org/~tgr/libnl/

#### Sample Code

	- [sample1](http://linux-development-for-fresher.blogspot.tw/2012/05/understanding-netlink-socket.html)

#### See msghdr anciliary data, [cmsg(3)][man-page]

#### struct sockaddr_nl in netlink(7)

	struct sockaddr_nl {
	   sa_family_t     nl_family;  /* AF_NETLINK */
	   unsigned short  nl_pad;     /* Zero. */
	   pid_t           nl_pid;     /* Port ID. */
	   __u32           nl_groups;  /* Multicast groups mask. */
	};

#### struct msghdr, struct cmsghdr in recvmsg(3)

	struct msghdr {
	   void         *msg_name;       /* optional address */
	   socklen_t     msg_namelen;    /* size of address */
	   struct iovec *msg_iov;        /* scatter/gather array */
	   size_t        msg_iovlen;     /* # elements in msg_iov */
	   void         *msg_control;    /* ancillary data, see below */
	   size_t        msg_controllen; /* ancillary data buffer len */
	   int           msg_flags;      /* flags on received message */
	};

	struct cmsghdr {
	   socklen_t     cmsg_len;     /* data byte count, including hdr */
	   int           cmsg_level;   /* originating protocol */
	   int           cmsg_type;    /* protocol-specific type */
	/* followed by
	   unsigned char cmsg_data[]; */
	};

#### struct nlmsghdr in netlink(7)

	struct nlmsghdr {
	   __u32 nlmsg_len;    /* Length of message including header. */
	   __u16 nlmsg_type;   /* Type of message content. */
	   __u16 nlmsg_flags;  /* Additional flags. */
	   __u32 nlmsg_seq;    /* Sequence number. */
	   __u32 nlmsg_pid;    /* Sender port ID. */
	};


