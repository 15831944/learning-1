#!/usr/bin/perl
@array=<STDIN>;
print(@array);
chop(@array);
$string=join(" ",@array);
print("$string\n");