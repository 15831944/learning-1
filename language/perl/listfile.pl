#!/usr/bin/perl
unless(open(MYFILE,"test.dat"))
{
  die("cannot open input file test.dat\n");
}
unless(open(OUTPUT,">output.dat"))
{
  close(MYFILE);
  die("cannot open the output file output.dat\n");
}
$line=<MYFILE>;
while($line ne "")
{
  print($line);
  print OUTPUT ($line);
  $line=<MYFILE>;
}
close(MYFILE);
unless(open(MYFILE,"test.dat"))
{
  close(OUTPUT);
  die("Cannot open the request file\n");
}
@input=<MYFILE>;
print(@input);
print OUTPUT (@input);
close(MYFILE);
close(OUTPUT);
