#!/usr/bin/perl
@input=<STDIN>;
$string=join("",@input);
$~="MULTILINE";
write;

format MULTILINE=
************** contents of the input file: ****************
@*
$string
***********************************************************
.
