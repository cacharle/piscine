echo $FT_NBR1
B10_1=$(echo $FT_NBR1 | tr "'\\$(echo '\"')?!" "01234")
echo $B10_1
echo $FT_NBR2
B10_2=$(echo $FT_NBR2 | tr "mrdoc" "01234")
echo $B10_2

ADD=$(echo "ibase=5; obase=13; $B10_1 + $B10_2" | bc)
echo $ADD

ADD_CONV=$(echo $ADD | tr "0123456789abc" "gtaio luSmemf")
echo $ADD_CONV
