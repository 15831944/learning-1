#!/bin/bash
#simpletrap.sh using trap to handle signals

trap "echo 'Do not interrupt me !'" INT
trap "echo 'Attemped murder is illegal!'" TERM

echo "$0's PID is $$"
while true;
do
	sleep 30
done