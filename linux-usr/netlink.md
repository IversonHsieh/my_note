Record netlink information
------------------------------------------
#### See netlink info

	$ man netlink
	$ man -s7 netlink

#### See msghdr anciliary data

	$ man cmsg

#### 

	$ man -s7 netlink


	struct sockaddr_nl {
	   sa_family_t     nl_family;  /* AF_NETLINK */
	   unsigned short  nl_pad;     /* Zero. */
	   pid_t           nl_pid;     /* Port ID. */
	   __u32           nl_groups;  /* Multicast groups mask. */
	};


#### struct msghdr, struct cmsghdr

	$ man recvmsg


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

