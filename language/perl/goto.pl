#!/usr/bin/perl
NEXTLINE: $line=<STDIN>;
if($line ne "")
{
  print($line);
  goto NEXTLINE;
}