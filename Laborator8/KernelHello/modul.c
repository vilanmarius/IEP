#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
MODULE_DESCRIPTION("Modulul meu kernel!");
MODULE_AUTHOR("Marius Vilan");
MODULE_LICENSE("GPL");

static int hello_init(void)
{
	printk(KERN_ALERT "Primul mesaj!\n");
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Al doilea mesaj!\n");
}

module_init(hello_init);
module_exit(hello_exit);
