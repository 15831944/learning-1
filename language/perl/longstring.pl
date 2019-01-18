#!/usr/bin/perl
$string="Here\nis a unbalanced line of\ntext.\n";
$~="OUTLINE";
write;
format OUTLINE=
#@*
^<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
$string
.