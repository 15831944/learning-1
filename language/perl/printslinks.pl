#!/usr/bin/perl
$dir="/usr/bin";
opendir(MYDIR,$dir);
while($name=readdir(MYDIR))
{
  if(-l $dir . "/" . $name)
  {
    print("$name is linked to ");
    print(readlink($dir . "/".$name)."\n");
  }
}
closedir(MYDIR);
