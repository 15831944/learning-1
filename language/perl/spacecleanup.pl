#!/usr/bin/perl
@input=<STDIN>;
$count=0;
while($input[$count] ne "")
{
  $input[$count]=~s/^[ \t]+//;
  $input[$count]=~s/[ \t]+\n$/\n/;
  $input[$count]=~s/[ \t]+/ /g;
  $count++;
}
print("Formated text:\n");
print(@input);