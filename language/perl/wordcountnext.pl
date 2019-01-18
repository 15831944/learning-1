#!/usr/bin/perl
$total=0;
while ($line=<STDIN>)
{
  $line=~s/^[\t ]*//;
  $line=~s/[\t ]*\n$//;
  next if($line eq "");
  @words=split(/[\t ]+/,$line);
  $total+=@words;
}
print("The total number of words is $total\n");
