#!/usr/bin/perl
$total=0;
while(1)
{
  $line=<STDIN>;
  last if($line eq "");
  chop($line);
  @numbers=split(/[\t ]+/,$line);
  foreach $number (@numbers)
  {
    if($number=~/[^0-9]/)
    {
      print STDERR("$number is not a number\n");
    }
    $total+=$number;
  }
}
print("The total is $total.\n");
  