%%
. ECHO;
\n ECHO;
%%
int yywrap(void)
{
	return 1;
}
int main()
{
	yylex();
	return 0;
}