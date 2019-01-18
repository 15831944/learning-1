#!/usr/bin/perl
unless(open(INFILE1,"merge1.dat"))
{
  die("Cannot open input file merge1.dat\n");
}
unless(open(INFILE2,"merge2.dat"))
{
  close(INFILE1);
  die("Cannot open input file merge2.dat\n");
}
unless(open(OUTFILE,">output.dat"))
{
  close(INFILE1);
  close(INFILE2);
  die("Cannot open output file output.dat\n");
}
$inline1=<INFILE1>;
$inline2=<INFILE2>;
while($inline1 ne "" || $inline2 ne "")
{
  if($inline1 ne "")
  {
    print OUTFILE ($inline1);
    $inline1=<INFILE1>;
  }
  if($inline2 ne "")
  {
    print OUTFILE ($inline2);
    $inline2=<INFILE2>;
  }
}
close(INFILE1);
close(INFILE2);
close(OUTFILE);