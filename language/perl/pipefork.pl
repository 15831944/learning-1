#!/usr/bin/perl
pipe(INPUT,OUTPUT);
$retval=fork();
if($retval!=0)
{
  close(INPUT);
  print("Enter a line of input:\n");
  $line=<STDIN>;
  print OUTPUT ($line);
}
else
{
  close(OUTPUT);
  $line=<INPUT>;
  print ($line);
  exit(0);
}