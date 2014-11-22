


#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

/* This function is called when the module is loaded. */

static int simple_init(void){
	printk(KERN_INFO "\n\n\n----Adding Module----\n\n\n");
	return 0;
}

/*Function called when module is removed */
static void simple_exit(void){
	printk(KERN_INFO "\n\n\n----Removing Module----\n\n\n");
}

/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("Kyle Chipps"); 