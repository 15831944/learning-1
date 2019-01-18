#!/usr/bin/perl
print("Enter a line of input:\n");
$inputline=<STDIN>;
print("uppercase: \U$inputline\E\n");
print("lowercase: \L$inputline\E\n");
print("as a sentece: \L\u$inputline\E\n");