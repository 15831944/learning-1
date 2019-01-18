#!/usr/bin/perl
if(!opendir(DIRNAME,"/home/gabriel"))
{
 die("Can't open the directory\n");
}
while($filename=readdir(DIRNAME))
{
  print("$filename\n");
}
closedir(DIRNAME);
