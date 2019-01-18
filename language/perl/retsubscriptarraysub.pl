#!/usr/bin/perl
srand();
print("Random number tester.\n");
for($count=1;$count<=100;$count++)
{
  $randnum[&intrand]+=1;
}
print("Totals for the digits 0 through 9:\n");
print("@randnum\n");
sub intrand
{
  $num=int(rand(10));
}