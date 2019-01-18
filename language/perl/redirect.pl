#!/usr/bin/perl
open(STDOUT,">file1") || die("open STDOUT failed");
open(STDERR,">&STDOUT") || die("open STDERR failed");
$|=1;
select(STDERR);
$|=1;
print STDOUT ("line 1\n");
print STDERR ("line 2\n");
close(STDOUT);
close(STDERR);