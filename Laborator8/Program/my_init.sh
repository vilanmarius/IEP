#!/bin/sh

sudo insmod ./myapp.ko
dmesg | tail -7
