#!/usr/bin/perl
print("Enter a date in the format YYYY-MM-DD:\n");
$date=<STDIN>;
chop($date);
#handle 31-day months
$md1="(0[13578]|1[02])\\2(0[1-9]|[12]\\d|3[01])";
#handle 30 day mounts
$md2="(0[469]|11)\\2(0[1-9]|[12]\\d|30)";
#handle February, without worrying about whether is't
$md3="02\\2(0[1-9]|[12]\\d)";
$match=$date=~/^(19)?\d\d(.)($md1|$md2|$md3)$/;
$olddate=$date=~/^(\d{1,4})(.)($md1|$md2|$md3)$/;
if($match)
{
  print("$date is a valid date in 20th century\n");
}
elsif($olddate)
{
  print("$date is not in the 20th century\n");
}
else
{
  print("$date is not a valid date\n");
}