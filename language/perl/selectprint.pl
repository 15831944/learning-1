#!/usr/bin/perl
open(FILE1,">file1.dat");
$string="junk";
select(FILE1);
&writeline;
select(STDOUT);
&writeline;
close(FILE1);

sub writeline
{
  $~="WRITELINE";
  write;
}

format WRITELINE=
    I am writting @<<<<< to my output files.
          $string
.