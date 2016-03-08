#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/kthread.h>

/* the program is refered from essential linux device drviers */

#define KTHD_EVT_HDL_LEN	80

static char kthreadd_event_handler[KTHD_EVT_HDL_LEN];

static struct ctl_table kthreadd_kern_table[] = {
	{
		.procname	= "kthreadd_event_handler",
		.data		= kthreadd_event_handler,
		.maxlen		= KTHD_EVT_HDL_LEN,
		.mode		= 0644,
		.proc_handler	= proc_dostring,
	},
	{}
};

static struct ctl_table kthreadd_root_table[] = {
	{
		.procname	= "kernel",
		.mode		= 0755,
		.child		= kthreadd_kern_table,
	},
	{}
};
struct ctl_table_header *kthreadd_table_header;

static DECLARE_WAIT_QUEUE_HEAD(myevent_waitqueue);
rwlock_t myevent_lock;

struct task_struct *mytask;

/* TODO */
//extern unsigned int myevent_id;
unsigned int myevent_id;

static void
run_umode_handler(int event_id)
{
	int i = 0;
	char *argv[2], *envp[4], *buffer = NULL;
	int value;

	argv[i++] = kthreadd_event_handler;

	buffer = kmalloc(32, GFP_KERNEL);
	if(!buffer)
		return;
	sprintf(buffer, "TROUBLED_DS=%d", event_id);

	/* If no user mode handlers are found, return */
	if (!argv[0])
		return;
	argv[i] = 0;

	/* Prepare the environment */
	i = 0;
	envp[i++] = "HOME=/";
	envp[i++] = "PATH=/sbin:/usr/sbin:/bin:/usr/bin";
	envp[i++] = buffer;
	envp[i] = 0;

	/* Execute the user mode program */
	value = call_usermodehelper(argv[0], argv, envp, 0);

	/* Check return values */
	kfree (buffer);
}

static int mykthread(void *unused)
{
	unsigned int event_id = 0;
	DECLARE_WAITQUEUE(wait, current);

	/* Become a kernel thread without attached user resources */
	/* TODO - daemonize is not existed in kernel 3.19.0 */
	//daemonize("mykthread");

	/* Request delivery of SIGKILL */
	allow_signal(SIGKILL);

	add_wait_queue(&myevent_waitqueue, &wait);

	while (!kthread_should_stop()) {
		/* Relinquish the processor until the event occurs */
		set_current_state(TASK_INTERRUPTIBLE);
		schedule();
		/* Die if I receive SIGKILL */
		if (signal_pending(current)) break;
		/* Control gets here when the thread is woken up */
		read_lock(&myevent_lock);			/* Critical section starts */
		if (myevent_id) {
			event_id = myevent_id;
			read_unlock(&myevent_lock);		/* Critical section ends */
			/* Invoke the registered user mode helper and 
				pass the identity code in its environment */
			run_umode_handler(event_id);	/* Expanded later on */
		} else {
			read_unlock(&myevent_lock);
		}
	}

	set_current_state(TASK_RUNNING);
	remove_wait_queue(&myevent_waitqueue, &wait);
	return 0;
}

static int kthreadd_init(void)
{
	pr_info("Start %s()\n", __func__);

	kthreadd_table_header = register_sysctl_table(kthreadd_root_table);
	if (!kthreadd_table_header) {
		pr_err("Unable to register kthreadd sysctl\n");
		return -ENOMEM;
	}

	/* TODO - kernel log show `Unknown symbol kernel_thread` during insmod the module */
/*
	kernel_thread(mykthread, NULL,
		CLONE_FS | CLONE_FILES | CLONE_SIGHAND | SIGCHLD);
*/
	mytask = kthread_create(&mykthread, NULL, "mykthread");
	if (mytask)
		wake_up_process(mytask);

	return 0;
}
  
static void kthreadd_exit(void)
{
	pr_info("Exit %s()\n", __func__);

	kthread_stop(mytask);

	unregister_sysctl_table(kthreadd_table_header);
}
  
module_init(kthreadd_init);
module_exit(kthreadd_exit);

MODULE_DESCRIPTION("Kthreadd");
MODULE_LICENSE("GPL");
