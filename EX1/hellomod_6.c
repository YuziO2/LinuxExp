#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

static int year = 2023;
static int hello_init(void)
{
  printk("Hello kernel, it's %d!\n", year);
  return 0;
}
static void hello_exit(void)
{
  printk("Bye, kernel!\n");
}
/* main module function*/
module_init(hello_init);
module_exit(hello_exit);