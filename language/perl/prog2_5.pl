#!/usr/bin/perl
print("Enter a number:\n");
$number1=<STDIN>;
chop($number1);
print("Enter another number:\n");
$number2=<STDIN>;
chop($number2);
if($number1==$number2)
{
  print("The two numbers are equal.\n");
}
elsif($number1==$number2+1)
{
  print("The fist number is greater by one.\n");
}
elsif($number1+1==$number2)
{
  print("The second number is greater by one\n");
}
else
{
  print("The two numbers are not equal.\n");
}
  