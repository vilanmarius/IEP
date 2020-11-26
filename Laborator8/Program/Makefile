
KDIR = /lib/modules/`uname -r`/build 

kbuild:
	make -C $(KDIR) M=`pwd`

clean:
	make _C $(KDIR) M=`pwd` clean
