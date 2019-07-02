ifconfig -a | grep -E "ether\s([0-9a-f]{2}:){5}[0-9a-f]{2}" | cut -f 1
