#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xae141548, "module_layout" },
	{ 0x91766c09, "param_get_ulong" },
	{ 0x799c50a, "param_set_ulong" },
	{ 0x744c0c68, "param_get_byte" },
	{ 0x72c3be87, "param_set_byte" },
	{ 0x43ab66c3, "param_array_get" },
	{ 0x45947727, "param_array_set" },
	{ 0x6980fe91, "param_get_int" },
	{ 0xff964b25, "param_set_int" },
	{ 0x859c6dc7, "request_threaded_irq" },
	{ 0x38787e33, "cdev_add" },
	{ 0xf432cc41, "cdev_init" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0xd8e484f0, "register_chrdev_region" },
	{ 0x3af98f9e, "ioremap_nocache" },
	{ 0xadf42bd5, "__request_region" },
	{ 0x105e2727, "__tracepoint_kmalloc" },
	{ 0x93fca811, "__get_free_pages" },
	{ 0x2da418b5, "copy_to_user" },
	{ 0x9bce482f, "__release_region" },
	{ 0x59d8223a, "ioport_resource" },
	{ 0x788fe103, "iomem_resource" },
	{ 0xedc03953, "iounmap" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0x37a0cba, "kfree" },
	{ 0x2152d374, "cdev_del" },
	{ 0xf20dabd8, "free_irq" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xb72397d5, "printk" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

