#!/usr/bin/perl
@array1=(14, "cheesburger", 1.23, -7, "toad");
@array2=@array1;
$count=1;
while($count<=5)
{
  print("element $count: $array1[$count-1] ");
  print("$array2[$count-1]\n");
  $count++;
}