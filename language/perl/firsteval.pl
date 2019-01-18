#!/usr/bin/perl
$myvar=1;
eval("print (\"hi!\\n\");\$myvar=2;");
print("the value of \$myvar is $myvar\n");
