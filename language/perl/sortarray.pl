#!/usr/bin/perl
print("Enter the array to sort, one item at a time.\n");
print("Enter an empty line to quit,\n");
$count=1;
$inputline=<STDIN>;
chop($inputline);
while($inputline ne "")
{
  @array[$count-1]=$inputline;
  $count++;
  $inputline=<STDIN>;
  chop($inputline);
}
#now we sort the array with their method
@theirsort=@array;
$count=1;
while($count<@theirsort)
{
  $x=1;
  while($x<@theirsort)
  {
    if($theirsort[$x-1] gt $theirsort[$x])
    {
      @theirsort[$x-1,$x]=@theirsort[$x,$x-1];
    }
    $x++;
  }
  $count++;
}
print("their buble sort: @theirsort\n");
#now we sort the array with direct insetion
@direct=@array;
$i=0;
while($i<@direct)
{
  $aux=$direct[$i];
  $j=$i-1;
  while($j>=0,$aux lt $direct[$j])
  {
    $direct[$j+1]=$direct[$j];
    $j--;
  }
  $direct[$j+1]=$aux;
  $i++;
}
print("direct insetion : @direct\n");
#now we sort the array with direct selection
@select=@array;
$i=0;
while($i<(@select-1))
{
  $k=$i;
  $min=$select[$i];
  $j=$i+1;
  while($j<@select)
  {
    if($select[$j] lt $min)
    {
      $min=$select[$j];
      $k=$j;
    }
    $j++;
  }
  $select[$k]=$select[$i];
  $select[$i]=$min;
  $i++;
}
print("direct selection: @select\n");
#now we sort the array with buble sort
@buble=@array;
$j=0;
while($j<@buble)
{
  $i=@buble-1;
  while($i>$j)
  {
    if(@buble[$i-1] gt @buble[$i])
    {
      @buble[$i-1,$i]=@buble[$i,$i-1];
    }
    $i--;
  }
  $j++;
}
print("buble sort: @buble\n");