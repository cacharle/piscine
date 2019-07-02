echo $FT_NBR1
B10_1=$(echo $FT_NBR1 | tr "'\\$(echo '\"')?!" "43210")
echo $B10_1
echo $FT_NBR2
B10_2=$(echo $FT_NBR2 | tr "mrdoc" "43210")
echo $B10_2

B5_ADD=$(echo "ibase=5; obase=5; $B10_1 + $B10_2" | bc)
echo "ibase=5;obase=13; $B5_ADD" | bc
# ADD=$(echo "ibase=5; obase=13; $B10_1 + $B10_2" | bc)
# echo $ADD

ADD_CONV=$(echo $B5_ADD | tr "0123456789ABC" "gtaio luSnemf")
echo $ADD_CONV
