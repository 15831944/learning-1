#!/usr/bin/perl
@input=<STDIN>;
chop(@input);
$currline=1;
while($currline<=@input)
{
  @words=split(/ /,$input[$currline-1]);
  @words=reverse(@words);
  $input[$currline-1]=join(" ",@words,"\n");
  $currline++;
}
@input=reverse(@input);
print(@input);
