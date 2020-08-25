#!/bin/bash
# menu.sh - creating simple menus with select

IFS=:
PS3="choice? "

#clear the screen
clear

select dir in $PATH
do
	if [ $dir ]; then
		cnt=$(ls -Al $dir | wc -l)
		echo "$cnt files in $dir"
	else
		echo "Dohhh! No such choice!"
	fi
	echo -e "\Press ENTER to continue, CTRL-C to quit"
	read 
	clear
done
