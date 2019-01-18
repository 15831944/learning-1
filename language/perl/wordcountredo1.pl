#!/usr/bin/perl
$nonblanklines=0;
while(1)
{
  $line=<STDIN>;
  last if($line eq "");
  $line=~s/^[\t ]*//;
  $line=~s/[\t ]*\n$//;
  if($line ne "")
  {
    $nonblanklines+=1;
    @words=split(/[\t ]+/,$line);
    $total+=@words;
  }
  last if($nonblanklines==3);
}
print("The total number of words is $total\n");
