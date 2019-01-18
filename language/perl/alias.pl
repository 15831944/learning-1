#!/usr/bin/perl
#in fact this is a reference (or pointer) called alias
$foo=26;
@foo=("here's","a","list");
&testsub(*foo);
print("The value of \$foo is now $foo\n");
print("The list is @foo\n");
sub testsub
{
  local(*printarray)=@_;
  foreach $element (@printarray)
  {
    print("$element\n");
  }
  $printarray=61;
}