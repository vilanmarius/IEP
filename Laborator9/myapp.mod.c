#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Ctest,_mydevice");
MODULE_ALIAS("of:N*T*Ctest,_mydeviceC*");
MODULE_ALIAS("of:N*T*Ctest,_mytestdevice");
MODULE_ALIAS("of:N*T*Ctest,_mytestdeviceC*");

MODULE_INFO(srcversion, "B984177B39EBCDDC215F152");
