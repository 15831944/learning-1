#!/usr/bin/perl
while(1)
{
  &readline;
  last if($line eq "");
  sub readline
  {
    $line=<STDIN>;
  }
  print($line);
}
print("done\n");