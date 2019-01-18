#!/usr/bin/perl
$total=0;
@numbers=&getnumbers;
foreach $number (@numbers)
{
  $total+=$number;
}
print("The total is $total\n");
sub getnumbers
{
  $line=<STDIN>;
  $line=~s/^\s+|\s*\n$//g;
  split(/\s+/,$line); #this is the return value
}