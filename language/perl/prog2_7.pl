#!/usr/bin/perl
print("What is 17 plus 26?\n");
$correct_answer=43;
$input_answer=<STDIN>;
chop($input_answer);
until($input_answer==$correct_answer)
{
  print("Wrong ! Keep trying!\n");
  $input_answer=<STDIN>;
  chop($input_answer);
}
print("You've got it!\n");