#!/usr/bin/perl
$searchword=$ARGV[0];
print("Word to search for: $searchword\n");
shift(@ARGV);
$totalwordcount=$wordcount=0;
$filename=$ARGV[0];
while($line=<>)
{
  chop($line);
  @words=split(/ /,$line);
  $w=1;
  while($w<=@words)
  {
    if($words[$w-1] eq $searchword)
    {
      $wordcount+=1;
    }
    $w++;
  }
  if(eof)
  {
    print("Occurrence in file $filename: ");
    print("$wordcount\n");
    $totalwordcount+=$wordcount;
    $wordcount=0;
    $filename=$ARGV[0];
  }
}
print("Total number of occurrence: $totalwordcount\n");
