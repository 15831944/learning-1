#!/usr/bin/perl
@array=(1,2,3,4,5,6);
@subarray=@array[1..3];
print("The elements of subarray are:\n");
$count=0;
while($count<@subarray)
{
  print("element  $subarray[$count]\n");
  $count++;
}
@array1=("old1","old2","old3","old4");
@array1[1,2]=("new2","new3");
print("@array1\n");
@array2=("one", "two", "three","four","five");
@array2[1,2,3]=@array2[2,3,4];
print("@array2\n");