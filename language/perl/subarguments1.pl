#!/usr/bin/perl
$wordcount=$charcount=0;
$charpattern="";
$wordpattern="\\s+";
while($line=<STDIN>)
{
  $charcount+=&count($line,$charpattern);
  $line=~s/^\+|\s+$//g;
  $wordcount+=&count($line,$wordpattern);
}
print("Totals: $wordcount words, $charcount characters\n");

sub count
{
  my($line,$pattern)=@_;
  my($count);
#  if($pattern eq "")
#  {
#    @items=split(//,$line);
#  }
#  else
#  {
#    @items=split(/$pattern/,$line);
#  }
  @items=$pattern eq "" ? split(//,$line) : split(/$pattern/,$line);
  $count=@items;
}