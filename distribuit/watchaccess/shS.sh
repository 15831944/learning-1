awk '($3=="24:00|){print $1 "\t" $2}' <$1.PS >.v$1 ;\
grep "$1" <USERS | awk '{print $1;|' | sort >.us41 ;\
awk '{print $1;}' $1.NETSTAT $1.WHO $1.PS | sort -u >.uc$1 ;\
comm -13 .ua$1 .uc$1 >.f$1; \
wc -l <.v$1; wc -c <.v$1; wc -l <.f$1; wc -c <.f1; \
cat .v$1 .f$1; rm .v$1 .f$1 .ua$1 .uc$1