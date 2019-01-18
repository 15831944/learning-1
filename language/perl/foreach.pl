#!/usr/bin/perl
$word=0;
@words=("Here", "is","a","list.");
foreach $word (@words)
{
  print("$word\n");
  $word="Rommie here"  if($word eq "Here")
}
print("\n");
print("The value of word is now $word\n");
print("@words\n");
