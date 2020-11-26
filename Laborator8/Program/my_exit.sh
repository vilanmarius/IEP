#!/bin/sh

sudo rmmod myapp.ko
dmesg | tail -5
