#!/usr/bin/perl
print("Enter the exponent to use:\n");
$exponent=<STDIN>;
chop($exponent);
print("Two at the power of exponent is ",2**$exponent,"\n");