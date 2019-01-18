#!/usr/bin/perl
$total=0;
while(1)
{
  $linetotal=&get_total;
  last if($linetotal eq "done");
  print("Total for this line: $linetotal\n");
  $total+=$linetotal;
}
print("Total for all lines: $total\n");
sub get_total
{
  my ($total, $inputline, @subwords);
  my ($index,$retval);
  $total=0;
  $inputline=<STDIN>;
  return("done") if($inputline eq "");
  $inputline=~s/^\s+|\s*\n$//g;
  @subwords=split(/\s+/,$inputline);
  $index=0;
  $total+=$subwords[$index++] while($subwords[$index] ne "");
  $retval=$total;
}