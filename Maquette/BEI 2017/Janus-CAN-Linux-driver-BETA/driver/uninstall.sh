#!/bin/sh
module="sja1000"
device="sja1000"

# invoke rmmod with all arguments we got
/sbin/rmmod $module $* || exit 1

# Remove stale nodes
rm -f /dev/${device}[rn] 





