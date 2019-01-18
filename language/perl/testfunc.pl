#!/usr/bin/perl
open(MYFILE,"file1_3.dat") || die("Can't open file1_3.dat");
eval("\n$start=tell(MYFILE);");
if($@ eq "")
{
  print("The tell function is defined.\n");
}
else
{
  print("The tell function is not defined!\n");
}