#include <linux/init.h>
#include <linux/module.h>

static DECLARE_WAIT_QUEUE_HEAD(myevent_waitqueue);
rwlock_t myevent_lock;
extern unsigned int myevent_id;

static int mykthread(void *unused)
{
	unsigned int event_id = 0;
	DECLARE_WAITQUEUE(wait, current);

	/* Become a kernel thread without attached user resources */
	daemonize("mykthread");

	/* Request delivery of SIGKILL */
	allow_signal(SIGKILL);

	add_wait_queue(&myevent_waitqueue, &wait);

	for (;;) {
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

	return 0;
}
  
static void kthreadd_exit(void)
{
	pr_info("Exit %s()\n", __func__);
}
  
module_init(kthreadd_init);
module_exit(kthreadd_exit);

MODULE_DESCRIPTION("Kthreadd");
MODULE_LICENSE("GPL");
