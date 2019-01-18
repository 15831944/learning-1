#!/usr/bin/perl
while ($line=<STDIN>)
{
  $line=~s/[^aeiou]//g;
  @vowels=split(//,$line);
  foreach $vowel (@vowels)
  {
    $vowelcount{$vowel}+=1;
  }
}
$~="VOWELFORMAT";
write;
format VOWELFORMAT=
====================================================
Number of vowels found in the text file:
      a: @<<<<< e:@<<<<<
      $vowelcount{"a"}, $vowelcount{"e"}
      i: @<<<<< o: @<<<<<
      $vowelcount{"i"}. $vowelcount{"o"}
      u: @<<<<<
      $vowelcount{"u"}
====================================================
.