#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/mutex.h>



MODULE_LICENSE("GPL");
MODULE_AUTHOR("Breno Leitao");
MODULE_DESCRIPTION("Test");
MODULE_VERSION("1.0");


static int __init lkm_example_init(void) {
	int ret = 0;

	DEFINE_RWLOCK(lock);
	printk("Hello, World!\n");


	read_lock(&lock);

	printk("Am I here:  %d?\n", ret);

	read_unlock(&lock);


	return 0;
}


static void __exit lkm_example_exit(void) {
	printk("Goodbye, World!\n");
}

module_init(lkm_example_init);
module_exit(lkm_example_exit);
