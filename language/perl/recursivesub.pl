#!/usr/bin/perl
$inputline=<STDIN>;
chop($inputline);
$inputline=~s/^\s+|\s+$//g;
@list=split(/\s+/,$inputline);
$result=&rightcalc(0);
print("The result is $result.\n");

sub rightcalc
{
  my($index)=@_;
  my($result,$operand1,$operand2);
  $operand2=$index+3==@list ? $list[$index+2] : &rightcalc($index+2);
  $operand1=$list[$index+1];
  if($list[$index] eq "+")
  {
    $result=$operand1+$operand2;
  }
  elsif($list[$index] eq "*")
  {
    $result=$operand1*$operand2;
  }
  elsif($list[$index] eq "-")
  {
    $result=$operand1-$operand2;
  }
  else
  {
    $result=$operand1/$operand2;
  }
}
