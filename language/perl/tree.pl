#!/usr/bin/perl
$rootname="parent";
%tree=("parentleft","child1",
      "parentright","child2",
      "child1left","grandchild1",
      "child1right","grandchild2",
      "child2left","grandchild3",
      "child2right","grandchild4");

&print_tree($rootname);

sub print_tree
{
  local($nodename)=@_;
  local($leftchildname,$rightchildname);
  $leftchildname=$nodename . "left";
  $rightchildname=$nodename . "right";
  &print_tree($tree{$leftchildname}) if($tree{$leftchildname} ne "");
  print("$nodename\n");
  &print_tree($tree{$rightchildname}) if($tree{$rightchildname} ne "");
}