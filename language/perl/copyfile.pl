#!/usr/bin/perl

die("Can't open input\n") unless(open(INFILE,"test.dat"));
die("Can't open output\n") unless(open(OUTFILE,">output.dat"));
print OUTFILE ($line) while($line=<INFILE>);
close(INFILE);
clsoe(OUTFILE);