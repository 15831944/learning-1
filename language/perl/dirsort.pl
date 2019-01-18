#!/usr/bin/perl
opendir(HOMEDIR,"/home/gabriel") || die("Unable to open directory");
@files=readdir(HOMEDIR);
closedir(HOMEDIR);
foreach $file (sort @files)
{
  print("$file\n");
}