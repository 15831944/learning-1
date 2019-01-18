#!/usr/bin/perl
&start_hot_keys;
while(1)
{
  $char=getc(STDIN);
  last if($char eq "\\");
  $char=~tr/a-zA-Z0-0/b-zaB-ZA1-90/;
  print($char);
}
&end_hot_keys;
print("\n");

sub start_hot_keys
{
  system("stty cbreak");
  system("stty -echo");
}

sub end_hot_keys
{
  system("stty -cbreak");
  system("stty echo");
}