#!/usr/bin/perl
print("Enter three numbers, one at a time:\n");
$number1=<STDIN>;
chop($number1);
$number2=<STDIN>;
chop($number2);
$number3=<STDIN>;
chop($number3);
&printnum($number1,$number2,$number3);
sub printnum
{
  my($number1,$number2,$number3)=@_;
  my($total);
  print("The numbers you entered: ");
  print("$number1 $number2 $number3\n");
  $total=$number1+$number2+$number3;
  print("The total: $total\n");
}