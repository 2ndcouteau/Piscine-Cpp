

./replace "$1" "$2" "$3"

if [[ $? == 0 ]]; then

	diff filetest.txt filetest.txt.replace

	echo
	echo

	cat filetest.txt.replace

fi
