Record netlink information
------------------------------------------
#### See netlink info - [netlink(3), netlink(7)][man-page]
[man-page]: https://www.kernel.org/doc/man-pages/

#### [Netlink Protocol Library Suite (libnl)][libnl-web]
[libnl-web]: https://www.infradead.org/~tgr/libnl/

#### Sample Code

	- [sample1][s1]
[s1]: http://linux-development-for-fresher.blogspot.tw/2012/05/understanding-netlink-socket.html
	- [sample2][s2]
[s2]: http://1984.lsi.us.es/projects/netlink-examples/
	

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

#### [generic netlink kernel document][genl-ker]
[genl-ker]: http://www.linuxfoundation.org/collaborate/workgroups/networking/generic_netlink_howto


#### Sample code

	- [genl kernel module and user application without libnl][s1]
[s1]: http://www.electronicsfaq.com/2014/02/generic-netlink-sockets-example-code.html

#### struct gen_family, genl_ops, genl_info, nla_policy

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

	struct genl_info
	{
	   u32                     snd_seq;
	   u32                     snd_pid;
	   struct nlmsghdr *       nlhdr;
	   struct genlmsghdr *     genlhdr;
	   void *                  userhdr;
	   struct nlattr **        attrs;
	};

	struct nla_policy
	{
	   u16             type;
	   u16             len;
	};	

