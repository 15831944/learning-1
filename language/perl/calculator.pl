#!/usr/bin/perl
$nextnode=1;
&get_next_item;
$treeroot=&build_expr;
$result=&get_result($treeroot);
print("the results is $result\n");

sub build_expr
{
  local($currnode,$leftchild,$rightcild);
  local($operator);
  $leftchild=&build_add_operand;
  if(&is_next_item("+") || &is_next_item("-"))
  {
    $operator=&get_next_item;
    $rightchild=&build_expr;
    $currnode=&build_expr;
    $currnode=&get_new_node($operator,$leftchild,$rightchild);
  }
  else
  {
    $currnode=$leftchild;
  }
}

sub build_add_operand
{
  local($currnode,$leftchild,$rightchild);
  local($operator);
  $leftchild=&build_mult_operand;
  if(&is_next_item("*") || &is_next_item("/"))
  {
    $operator=&get_next_item;
    $rightchild=&build_add_operand;
    $currnode=&get_new_node($operator,$leftchild,$rightchild);
  }
  else
  {
    $currnode=$leftchild;
  }
}

sub build_mult_operand
{
  local($currnode);
  if(&is_next_item("("))
  {
    &get_next_item;
    $currnode=&build_expr;
    die("Invalid expression") if(!&is_next_item(")"));
    &get_next_item;
  }
  else
  {
    $currnode=&get_new_node(&get_next_item,"","");
    $currnode;
  }
}

sub is_next_item
{
  local($expected)=@_;
  $curritem eq $expected;
}

sub get_next_item
{
  local($retitem);
  $retitem=$curritem;
  $curritem=&read_item;
  $retitem;
}

sub read_item
{
  local($line);
  return if($curritem eq "EOF");
  while($wordsread==@words)
  {
    $line=<STDIN>;
    if($line eq "")
    {
      $curritem="EOF";
      return;
    }
    $line=~s/\(/ ( /g;
    $line=~s/\)/ ) /g;
    $line=~s/^\s+|\s+$//g;
    @words=split(/\s+/,$line);
    $wordsread=0;
  }
  $curritem=$words[$wordsread++];
}

sub get_new_node
{
  local($value,$leftchild,$rightchild)=@_;
  local($nodenum);
  $nodenum=$nextnodenum++;
  $tree{$nodenum}=$value;
  $tree{$nodenum."left"}=$leftchild;
  $tree{$nodenum."right"}=$rightchild;
  $nodenum;
}

sub get_result
{
  local($node)=@_;
  local($nodevalue,$result);
  $nodevalue=$tree{$node};
  if($nodevalue eq "")
  {
    die("Bad tree");
  }
  elsif($nodevalue eq "+")
  {
    $result=&get_result($tree{$node."left"})+&get_result($tree{$node."right"});
  }
  elsif($nodevalue eq "-")
  {
    $result=&get_result($tree{$node."left"})-&get_result($tree{$node."right"});
  }
  elsif($nodevalue eq "*")
  {
   $result=&get_result($tree{$node."left"})*&get_result($tree{$node."right"}); 
  }
  elsif($nodevalue eq "/")
  {
    $result=&get_result($tree{$node."left"})/&get_result($tree{$node."right"});
  }
  elsif($nodevalue=~/^[0-9]+$/)
  {
    $result=$nodevalue;
  }
  else
  {
    die("Bad tree");
  }
}