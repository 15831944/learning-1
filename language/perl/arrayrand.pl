#!/usr/bin/perl
$count=1;
while($count<=100)
{
  $randnum=int(rand(10))+1;
  $randtotal[$randnum]+=1;
  $count++;
}
$count=1;
print("Total for each number:\n");
while($count<=10)
{
  print("\tnumber $count: $randtotal[$count]\n");
  $count++;
}