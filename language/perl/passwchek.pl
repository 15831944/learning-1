#!/usr/bin/perl
print("Enter the selecret passwork:\n");
$password="Rommie";
$inputline=<STDIN>;
chop($inputline);
$outputline=$inputline eq $password ? "Yes, that is the correct password!\n" : "No. that is not the correct password.\n";
print($outputline);