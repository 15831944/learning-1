#!/usr/bin/perl
$inputline=<STDIN>;
$inputline=~s/^\s+|\s+\n$//g;
%fruit=split(/\s+/,$inputline);
print("Number of bananas: $fruit{\"bananas\"}\n");