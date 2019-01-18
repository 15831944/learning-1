#!/usr/bin/perl
($wordcount,$charcount)=&getcounts(3);
print("Totals for three lines: ");
print("$wordcount words, $charcount characters\n");

sub getcounts
{
  my($numlines)=@_;
  my($charpattern,$wordpattern);
  my($charcount,$wordcount);
  my($line,$linecount);
  my(@retval);
  $charpattern="";
  $wordpattern="\\s+";
  $linecount=$charcount=$wordcount=0;
  while(1)
  {
    $line=<STDIN>;
    last if($line eq "");
    $linecount++;
    $charcount+=&count($line,$charpattern);
    $line=~s/^\s+|\s+$//g;
    $wordcount+=&count($line,$wordpattern);
    last if($linecount==$numlines);
  }
  @retval=($wordcount,$charcount);
}
sub count
{
  my($line,$pattern)=@_;
  my($count);
  @items=$pattern eq "" ? split(//,$line) : split(/$pattern/,$line);
#  @count=@items;
}