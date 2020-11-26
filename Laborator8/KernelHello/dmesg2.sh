#!/bin/sh

sudo rmmod modul.ko
dmesg | tail -2
