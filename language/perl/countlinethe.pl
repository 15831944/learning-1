#!/usr/bin/perl
$thecountline=0;
$thecount=0;
print("Enter the input here:\n");
$line=<STDIN>;
while($line ne "")
{
  if($line=~/\bthe\b/)
  {
    $thecountline+=1;
    @words=split(/\bthe\b/,$line);
    $thecount+=@words-1;
  }
  $line=<STDIN>;
}
print("Number of lines containing 'the': $thecountline\n");
print("Number of 'the' in the lines: $thecount\n");
