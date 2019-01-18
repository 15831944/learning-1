#!/usr/bin/perl
$count=0;
while($ARGV[$count] ne "")
{
  open(FILE,"$ARGV[$count]");
  @file=<FILE>;
  $linenum=0;
  while($file[$linenum] ne "")
  {
    $file[$linenum]=~s/\d+/$&*2/eg;
    $linenum++;
  }
  close(FILE);
  open(FILE,">$ARGV[$count]");
  print FILE (@file);
  close(FILE);
  $count++;
}