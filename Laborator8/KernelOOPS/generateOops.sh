#!/bin/sh

sudo insmod ./oops.ko
dmesg | tail -32
