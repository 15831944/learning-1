#!/usr/bin/perl

@quotation=<STDIN>;
$quotation=join("",@quotation);
$~="QUOTATION";
write;

format QUOTATION=
Quotation for the day:
------------------------
#  ^<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#  $quotation
#  ^<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#  $quotation
#  ^<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#  $quotation
~~ ^<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  $quotation
-----------------------
.