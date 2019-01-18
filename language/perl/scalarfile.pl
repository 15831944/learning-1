#!/usr/bin/perl
&open_file("INFILE","","file1_2.dat");
&open_file("OUTFILE",">","file2_2.dat");
&print_to_file("OUTFILE",$line) while($line=&read_from_file("INFILE"));

sub open_file
{
  local($filevar,$filemode,$filename)=@_;
  open($filevar,$filemode.$filename) || die("Can't open $filename");
}

sub read_from_file
{
  local($filevar)=@_;
  <$filevar>;
}

sub print_to_file
{
  local($filevar,$line)=@_;
  print $filevar ($line);
}
