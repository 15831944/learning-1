#!/bin/bash
# getops.sh - using getopts

while getopts ":xy:z:" opt;
do
	case $opt in
		x ) xopt='-x set' ;;
		y ) yopt="-y set and called with $OPTARG" ;;
		z ) zopt="-z set and called with $OPTARG" ;;
		\? ) echo 'USAGE: getopts.sh [-x][-y arg] [-z arg] file ...'
			exit 1
	esac
done
shift $(($OPTIND -1))
echo ${xopt:-'did not use -x'}
echo ${yopt:-'did not use -y'}
echo ${zopt:-'did not use -z'}

echo "Remaining command-line arguments are:"
for f in "$@"
do
	echo -e "\t$f"
done		