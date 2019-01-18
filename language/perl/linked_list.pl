#!/usr/bin/perl
$header="";
while($line=<STDIN>)
{
  $line=~s/^\s+|\s+$//g;
  @words=split(/\s+/,$line);
  foreach $word (@words)
  {
    $word=~s/[,.;:-]$//;
    $word=~tr/A-Z/a-z/;
    &add_word_to_list($word);
  }
}
&print_list;

sub add_word_to_list
{
  local($word)=@_;
  local($pointer);
  if($header eq "")
  {
    $header=$word;
    $wordlist{$word}="";
    return;
  }
  return if($header eq $word);
  if($header gt $word)
  {
    $wordlist{$word}=$header;
    $header=$word;
    return;
  }
  $pointer=$header;
  $pointer=$wordlist{$pointer}  while($wordlist{$pointer} ne "" && $wordlist{$pointer} lt $word);
  return if($word eq $wordlist{$pointer});
  $wordlist{$word}=$wordlist{$pointer};
  $wordlist{$pointer}=$word;
}

sub print_list
{
  local($pointer);
  print("Words  in this file:\n");
  $pointer=$header;
  while($pointer ne "")
  {
    print("$pointer\n");
    $pointer=$wordlist{$pointer};
  }
}