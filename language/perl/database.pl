#!/usr/bin/perl
@pitcherfields=("NAME","KEY","GP","W","ERA");
@playerfields=("NAME","KEY","GP","HR","RBI","BA");
$playercount=0;
while($input=<STDIN>)
{
  $input=~s/^\s+|\s+$//g;
  @words=split(/\s+/,$input);
  $playerlist[$playercount++]=$words[0];
  @fields= $words[1] eq "player" ? @playerfields : @pitcherfields;
  for($count=1;$count<=@words;$count++)
  {
    $playerbase{$words[0].$fields[$count-1]}=$words[$count-1];
  }
}
foreach $player (@playerlist)
{
  print("$player: ");
  if($playerbase{$player."KEY"} eq "player")
  {
    $value=$playerbase{$player."HR"};
    print("$value home runs\n");
  }
  else
  {
    $value=$playerbase{$player."W"};
    print("$value wins\n");
  }
}
