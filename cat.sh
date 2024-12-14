POSSIBLE_LINES=$(cat support.txt | wc -l)
LINE_NUM=$((RANDOM % $POSSIBLE_LINES + 1))
LINE=$(sed -n "${LINE_NUM}p" support.txt)
LINE=${LINE%$'\n'}
LINE_LEN=${#LINE}
BUBBLE_LEN=$((LINE_LEN + 4))

# Print the top of the bubble
echo -n "   "
for i in $(seq 1 $BUBBLE_LEN); do
    echo -n "_"
done
echo

# Print the middle of the bubble
echo -n "  / "
for i in $(seq 1 $(($BUBBLE_LEN-2))); do
    echo -n " "
done
echo " \\"

# Print the line
echo -n " |   "
echo -n $LINE
echo "   |"

# Print the bottom of the bubble
echo -n "  \\ "
for i in $(seq 1 $(($BUBBLE_LEN-2))); do
    echo -n "_"
done
echo " /"

cat cat.txt
