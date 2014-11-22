#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/slab.h>
#include "/usr/src/linux-headers-3.13.0-32/include/linux/list.h"

/* Define the struct containing the elemets for the linked list */
struct Birthday{
	int day;
	int month;
	int year;
	struct list_head list;
};

struct Birthday birthdayList;
/* This function is called when the module is loaded. */

static int simple_init(void){
	
	struct Birthday *aBirthday;
	struct Birthday *aNewBirthday;
	unsigned int i;

	INIT_LIST_HEAD(&birthdayList.list); 
	/*The ISO C90 specification don't want variable delcarations below this line */
	printk(KERN_INFO "\n\n\n----Loading Module----\n\n\n");

	for (i=0; i<6; i++){
		aNewBirthday = kmalloc(sizeof(*aNewBirthday), GFP_KERNEL);
		aNewBirthday->day = i+1;
		aNewBirthday->month = i+1*2;
		aNewBirthday->year = 2000-i;

		INIT_LIST_HEAD(&aNewBirthday->list);

		list_add_tail(&(aNewBirthday->list), &(birthdayList.list));
	}
	printk(KERN_INFO "Traversing List\n");

    list_for_each_entry(aBirthday, &birthdayList.list, list) {
        //access each memeber of birthdayList
        printk(KERN_INFO "Birthday: Month: %d Day: %d Year: %d\n", aBirthday->day, aBirthday->month, aBirthday->year);
    }
	return 0;
}

/*Function called when module is removed */
static void simple_exit(void){

	struct Birthday *aBirthday;
	struct Birthday *tmp;
	printk(KERN_INFO "\n\n\n----Removing Module----\n\n\n");
    printk(KERN_INFO "Deleting and Freeing List\n");

    list_for_each_entry_safe(aBirthday, tmp, &birthdayList.list, list){
         printk(KERN_INFO "Removing and freeing node Birthday: Month: %d Day: %d Year: %d\n", aBirthday->day, aBirthday->month, aBirthday->year);
         list_del(&aBirthday->list);
         kfree(aBirthday);
    }
}

/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Linked List Module");
MODULE_AUTHOR("Kyle Chipps"); 