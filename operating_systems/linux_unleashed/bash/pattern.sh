#!/bin/bash
#pattern.sh - demonstrate pattern matching operators

myfile=/usr/src/linux/Documentation/ide.txt

echo '${myfile##*/}=' ${myfile##*/}
echo 'basename $myfile =' $(basename $myfile)

echo '${myfile%/*}=' ${myfile%/*}
echo 'dirname $myfile =' $(dirname $myfile)