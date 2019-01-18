#!/usr/bin/perl
print("Ask me a question politely:\n");
$question=<STDIN>;
if($question=~/please/)
{
  print("Thank you for being polite!\n");
}
else
{
  print("That was not very polite!\n");
}