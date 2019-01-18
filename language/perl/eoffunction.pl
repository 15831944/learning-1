#!/usr/bin/perl

while($line=<>)
{
  print($line);
#  if(eof)
  if(eof())
  {
    print("--- end of current file --\n");
  }
}