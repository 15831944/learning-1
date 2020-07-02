/* diferite definii penru varibile si modificari */
void main()
{
	char *str0;
	/* declaratia unui pointer constant de caracter */
	char * const str1 = "test1";
	/* declaratii de pointeri de caractere constante */
	const char * str2 = "text2";
	char const * str3 = "text3";
	/* operatii */
	/* eroare, str1 = obiect constant
	str1 = "alt text1"; */
	/* corect, str2 = obiect variabil */
	str2 = "alt text2";
	/* corect, str3 = obiect variabil */
	str3 = "alt text3";
	/* eroare, str1 = obiect constant
	str1++; */
	/*corect, *str1 = obiect variabil */
	str1[4]++;
	/* eroare, *str2 = obiect constant
	(*str2)++; */
	/* eroare, *str3 = obiect constant
	str0 = str3; */
}