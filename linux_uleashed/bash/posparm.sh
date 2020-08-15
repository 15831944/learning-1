#!/bin/bash
# posparm.sh - using positional parameters
function cntparm
{
	echo -e "inside cntparm $# params: $*\n"
}
cntparm "$*"
cntparm "$@"

echo -e "outside cntparm $*\n"
echo -e "outside cntparm $#\n"
