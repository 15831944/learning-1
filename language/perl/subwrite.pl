#!/usr/bin/perl
while($line=<STDIN>)
{
  $line=~tr/A-Z/a-z/;
  $line=~s/[^a-z]//g;
  @letters=split(//,$line);
  foreach $letter (@letters)
  {
    $lettercount{$letter}+=1;
  }
}

$~="WRITEHEADER";
write;
$count=0;
foreach $letter (reverse sort occurrences (keys(%lettercount)))
{
  &write_letter($letter,$lettercount{$letter});
  last if(++$count==5);
}

sub occurrences
{
  $lettercount{$a} <=> $lettercount{$b};
}

sub write_letter
{
  local($letter,$value)=@_;
  $~="WRITELETTER";
  write;
}

format WRITEHEADER=
The five most frequently occurring letters are:
.
format WRITELETTER=
    @: @<<<<<
    $letter, $value
.