#!/usr/bin/perl
open(OUTFILE,">file1");
select(OUTFILE);
$~="WRITELINE";
$^="TOP_OF_PAGE";
$==60;
write while($line=<STDIN>);
close(OUTFILE);
format TOP_OF_PAGE=
                        - page @<
                                $%
.
format WRITELINE=
@*
$line
.
