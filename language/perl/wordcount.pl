#!/usr/bin/perl
$wordcount=0;
$line=<STDIN>;
while($line ne "")
{
  chop($line);
  @array=split(/ /,$line);
  $wordcount+=@array;
  $line=<STDIN>;
}
print("The total number of words is $wordcount\n");
