ifconfig -a | grep -E "ether\s([0-9a-f]{2}:){5}[0-9a-f]{2}" | sed "s/.*ether //g" | sed "s/ $//g" | sort | uniq
