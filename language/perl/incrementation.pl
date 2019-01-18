#!/usr/bin/perl
$value=0;
print("Preincrementation\n");
while(++$value<=5)
{
  print("value is now $value\n");
}
print("after while the value is $value\n");
print("Postincrementation\n");
$value=0;
while($value++<=5)
{
  print("value is now $value\n");
}
print("After while the value is $value\n");
print("all done\n");