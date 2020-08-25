#!/bin/bash
# descpath.sh - File test operators

IFS=:

for dir in $PATH;
do
	echo $dir
	if [ -w $dir ]; then
		echo -e "\tYou have write persmission in $dir"
	else
		echo -e "\tYou don't have write permission in $dir"
	fi
	if [ -O $dir ]; then
		echo -e "\tYou own $dir"
	else
		echo -e "\tYou don't own $dir"
	fi
	if [ -G $dir ]; then
		echo -e "\tYou are a member of $dir's group"
	else
		echo -e "\tYou aren't a member of $dir's group"
	fi
done
