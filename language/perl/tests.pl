#!/usr/bin/perl
if(-e "test.dat")
{
  print("File test.dat exists\n");
}
else
{
  print("File test.dat not exist\n");
}
if(-x "test.dat")
{
  print("File test.dat is executable\n");
}
else
{
  print("File test.dat is not executable\n");
}
if(-d "test.dat")
{
  print("File test.dat is a directory\n");
}
else
{
  print("File test.dat is not a directory\n");
}
if(-r "test.dat")
{
  print("File test.dat is readable\n");
}
else
{
  print("File test.dat is not readable\n");
}
if(-w "test.dat")
{
  print("File test.dat is writeable\n");
}
else
{
  print("File test.dat is not writeable\n");
}
if(-p "test.dat")
{
  print("File test.dat is a pipe file\n");
}
elsif(-f "test.dat")
{
  print("File test.dat is an ordinary file\n");
}
if(-s "test.dat")
{
  $size=-s "test.dat";
  print("File test.dat is not empty and contains $size bytes\n");
}
else
{
  print("File test.dat is empty\n");
}