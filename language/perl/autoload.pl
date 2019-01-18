#!/usr/bin/perl
&notthere("hi",46);
AUTOLOAD
{
  print("subroutine $AUTOLOAD not found\n");
  print("arguments passed: @_\n");
}