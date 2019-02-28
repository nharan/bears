#!/bin/bash

echo /tmp/core | tee /proc/sys/kernel/core_pattern
ulimit -c unlimited

# if we're not using PaaS mode then start offerd traditionally with sv to control it
if [[ ! "$USE_PAAS" ]]; then
  mkdir -p /etc/service/offerd
  cp /usr/local/bin/offer-sv-run.sh /etc/service/offerd/run
  chmod +x /etc/service/offerd/run
  runsv /etc/service/offerd
elif [[ "$IS_TESTNET" ]]; then
  /usr/local/bin/pulltestnetscripts.sh
else
  /usr/local/bin/startpaasofferd.sh
fi
