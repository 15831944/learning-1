#!/usr/bin/perl
$total=&get_total;
#if($total eq "error")
#{
#  print("No input supplied.\n");
#}
#else
#{
#  print("The total is $total.\n");
#}
$total eq "error" ? print("No input supplied.\n") : print("The total is $total.\n");
sub get_total
{
  $value=0;
  $inputline=<STDIN>;
  $inputline=~s/^\s+|\s*\n$//g;
  return("error") if($inputline eq "");
  @subwords=split(/\s+/,$inputline);
  $index=0;
  $value+=$subwords[$index++] while($subwords[$index] ne "");
  $value;
}