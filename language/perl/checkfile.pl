#!/usr/bin/perl
unless(open(MYFILE,"test.dat"))
{
  if(-e "test.dat")
  {
    die("File test.dat exists, but cannot be opened.\n");
  }
  else
  {
    die("File test.dat does not exists.\n");
  }
}
$line=<MYFILE>;
while($line ne "")
{
  chop($line);
  print("\U$line\E\n");
  $line=<MYFILE>;
}
