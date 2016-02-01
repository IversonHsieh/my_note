Record netlink information
------------------------------------------
#### Documents

##### See netlink info - [netlink(3), netlink(7)][man-page]
[man-page]: https://www.kernel.org/doc/man-pages/

##### [Netlink Protocol Library Suite (libnl)][libnl-web]
[libnl-web]: https://www.infradead.org/~tgr/libnl/

##### See msghdr anciliary data, [cmsg(3)][man-page]

#### netlink sample Code

- [sample1][s1]
[s1]: http://linux-development-for-fresher.blogspot.tw/2012/05/understanding-netlink-socket.html
- [sample2][s2]
[s2]: http://1984.lsi.us.es/projects/netlink-examples/


##### struct sockaddr_nl in netlink(7)

	struct sockaddr_nl {
	   sa_family_t     nl_family;  /* AF_NETLINK */
	   unsigned short  nl_pad;     /* Zero. */
	   pid_t           nl_pid;     /* Port ID. */
	   __u32           nl_groups;  /* Multicast groups mask. */
	};

##### struct msghdr, struct cmsghdr in recvmsg(3)

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

##### [generic netlink kernel document][genl-ker]
[genl-ker]: http://www.linuxfoundation.org/collaborate/workgroups/networking/generic_netlink_howto


#### Generic netlink sample code

- [genl kernel module and user application without libnl][s1]
[s1]: http://www.electronicsfaq.com/2014/02/generic-netlink-sockets-example-code.html

##### struct gen_family, genl_ops, genl_info, nla_policy

	struct genl_family
	{
	     unsigned int            id;
	     unsigned int            hdrsize;
	     char                    name[GENL_NAMSIZ];
	     unsigned int            version;
	     unsigned int            maxattr;
	     struct nlattr **        attrbuf;
	     struct list_head        ops_list;
	     struct list_head        family_list;
	};
	
	struct genl_ops
	{
	     u8                      cmd;
	     unsigned int            flags;
	     struct nla_policy       *policy;
	     int                     (*doit)(struct sk_buff *skb,
	                                     struct genl_info *info);
	     int                     (*dumpit)(struct sk_buff *skb,
	                                       struct netlink_callback *cb);
	     struct list_head        ops_list;
	};

	struct genl_multicast_group {
	    char            name[GENL_NAMSIZ];
	};

	struct genl_info {
	    u32         		snd_seq;
	    u32         		snd_portid;
	    struct nlmsghdr 	*nlhdr;
	    struct genlmsghdr 	*genlhdr;
	    void 				*userhdr;
	    struct nlattr 		**attrs;
	#ifdef CONFIG_NET_NS
    	struct net 			*_net;
	#endif
    	void 				*user_ptr[2];
    	struct sock 		*dst_sk;
	};

	struct nla_policy
	{
	   u16             type;
	   u16             len;
	};	

#### Netlink user sample code

##### struct sockaddr_nl, nlmsghdr 

	struct sockaddr_nl {
	    __kernel_sa_family_t	nl_family;  /* AF_NETLINK   */
	    unsigned short  		nl_pad;     /* zero     */
	    __u32       			nl_pid;     /* port ID  */
		__u32       			nl_groups;  /* multicast groups mask */
	};

	 0                   1                   2                   3
	 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|                Netlink message header (nlmsghdr)              |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|           Generic Netlink message header (genlmsghdr)         |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|             Optional user specific message header (nlattr)    |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|           Optional Generic Netlink message payload            |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

/include/linux/netlink.h

	struct nlmsghdr {
	   __u32 nlmsg_len;    /* Length of message including header. */
	   __u16 nlmsg_type;   /* Type of message content. */
	   __u16 nlmsg_flags;  /* Additional flags. */
	   __u32 nlmsg_seq;    /* Sequence number. */
	   __u32 nlmsg_pid;    /* Sender port ID. */
	};

/include/linux/genetlink.h

	struct genlmsghdr {
	    __u8    cmd;
	    __u8    version;
	    __u16   reserved;
	};

	/*
	 *  <------- NLA_HDRLEN ------> <-- NLA_ALIGN(payload)-->
	 * +---------------------+- - -+- - - - - - - - - -+- - -+
	 * |        Header       | Pad |     Payload       | Pad |
	 * |   (struct nlattr)   | ing |                   | ing |
	 * +---------------------+- - -+- - - - - - - - - -+- - -+
	 *  <-------------- nlattr->nla_len -------------->
	 */
	
	struct nlattr {
	    __u16           nla_len;
	    __u16           nla_type;
	};


