#!/usr/bin/perl
$total=0;
&getnumbers;
foreach $number (@numbers)
{
  $total+=$number;
}
print("The total is $total\n");
sub getnumbers
{
  $line=<STDIN>;
  $line=~s/^\s+|\s*\n$//g;
  @numbers=split(/\s+/,$line);
}