#!/usr/bin/perl
@list1=("test","14","26","test2");
@list2=sort num_last (@list1);
print("@list2\n");

sub num_last
{
  my($num_a,$num_b);
  $num_a=$a=~/^[0-9]/;
  $num_b=$b=~/^[0-9]/;
  if($num_a && $num_b)
  {
    $retval=$a <=> $b;
  }
  elsif($num_a)
  {
    $retval=1;
  }
  elsif($num_b)
  {
    $retval=-1;
  }
  else
  {
    $retval=$a cmp $b;
  }
  $retval;
}