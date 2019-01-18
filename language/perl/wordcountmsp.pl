#!/usr/bin/perl
$wordcount=0;
$line=<STDIN>;
while($line ne "")
{
  chop($line);
#  @words=split(/ +/,$line);
  @words=split(/[\t ]+/,$line);
#  $wordcount+=@words;
  $wordcount+=(@words>0 && $words[0] ne "" ? @words-1 : @words);
  $line=<STDIN>;
}
print("Total number of words: $wordcount\n");