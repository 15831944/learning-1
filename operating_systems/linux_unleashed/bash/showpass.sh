#!/bin/bash
#showpass.sh - using read to process a text file

IFS=:

while read name pass uid gid gecos home shell
do
	echo "********************"
	echo "name	: $name"
	echo "pass	: $pass"
	echo "uid	: $uid"
	echo "gid	: $gid"
	echo "gecos	: $gecos"
	echo "home	: $home"
	echo "shell	: $shell"
done
