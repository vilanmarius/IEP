#!/bin/sh

sudo insmod ./modul.ko
dmesg | tail -1
