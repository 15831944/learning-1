#!/usr/bin/perl
$line=<STDIN>;
$line=~s/^\s+//;
$line=~s/\s+$//;
foreach $word (reverse sort split(/[\t ]+/,$line))
{
  print("$word ");
}
print("\n");