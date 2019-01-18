#!/usr/bin/perl
$company=<STDIN>;
$~="COMPANY";
write;
$grandtotal=0;
$custline=<STDIN>;
while($custline ne "")
{
  $total=0;
  ($customer,$date)=split(/#/,$custline);
  $~="CUSTOMER";
  write;
  while(1)
  {
    $orderline=<STDIN>;
    if($orderline eq "" || $orderline=~/#/)
    {
      $custline=$orderline;
      last;
    }
    ($item,$cost)=split(/:/,$orderline);
    $~="ORDERLINE";
    write;
    $total+=$cost;
  }
  &write_total("Total:",$total);
  $grandtotal+=$total;
}
&write_total("Grand total:",$grandtotal);

sub write_total
{
  local($totalstring,$total)=@_;
  $~="TOTAL";
  write;
}
format COMPANY=
**********************@||||||||||||||||||||||||||||||***************
$company
.
format CUSTOMER=
@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<                  @>>>>>>>>>>>>>>>
$customer, $date
.
format ORDERLINE=
      @<<<<<<<<<<<<<<<<<<<<<<<<<<<		@####.##
$item,$cost
.
format TOTAL=
@<<<<<<<<<<<<<<<<<<				@######.##
$totalstring,$total

.