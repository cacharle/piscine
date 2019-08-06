#ifdef linux
# include <bsd/string.h> // with -lbsd
#endif
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "ex00/ft_strcpy.c"
#include "ex01/ft_strncpy.c"
#include "ex02/ft_str_is_alpha.c"
#include "ex03/ft_str_is_numeric.c"
#include "ex04/ft_str_is_lowercase.c"
#include "ex05/ft_str_is_uppercase.c"
#include "ex06/ft_str_is_printable.c"
#include "ex07/ft_strupcase.c"
#include "ex08/ft_strlowcase.c"
#include "ex09/ft_strcapitalize.c"
#include "ex10/ft_strlcpy.c"
#include "ex11/ft_putstr_non_printable.c"
#include "ex12/ft_print_memory.c"

int main()
{
	char dest[13];
	char src[] = "aonjour asdf\0 asdf";
	ft_strcpy(dest, src);
	for (int i = 0; i < 13; i++)
		printf("%d ", dest[i]);
	printf("\n%s\n", dest);
	strcpy(dest, "");
	strcpy(dest, src);
	for (int i = 0; i < 13; i++)
		printf("%d ", dest[i]);
	printf("\n%s\n", dest);

	char ndest[15];
	char nsrc[20] = "bonjour jew\0";
	ft_strncpy(ndest, nsrc, sizeof ndest);
	for (int i = 0; i < sizeof ndest; i++)
		printf("%d ", ndest[i]);
	printf("\n%s\n", ndest);
	strncpy(ndest, "eqwrwer", sizeof ndest);
	strncpy(ndest, nsrc, sizeof ndest);
	for (int i = 0; i < sizeof ndest; i++)
		printf("%d ", ndest[i]);
	printf("\n%s\n", ndest);

	char salpha[] = "BONJour";
	char snalpha[] = "bonJ our";
	printf("%d salpha\n", ft_str_is_alpha(salpha));
	printf("%d snalpha\n", ft_str_is_alpha(snalpha));

	char num[] = "0123456789";
	char nnum[] = "0123456789 ";
	printf("%d num\n", ft_str_is_numeric(num));
	printf("%d nnum\n", ft_str_is_numeric(nnum));

	char low[] = "";
	char nlow[] = "bonjOUR";
	printf("%d low\n", ft_str_is_lowercase(low));
	printf("%d nlow\n", ft_str_is_lowercase(nlow));

	char up[] = "BONJOUR";
	char nup[] = "BonjOUR";
	printf("%d up\n", ft_str_is_uppercase(up));
	printf("%d nup\n", ft_str_is_uppercase(nup));

	char printable[] = "boq4523$$%@$!``~~;'[[=_";
	char nprintable[] = "as^?f89*0(\xff";
	printf("%d printable\n", ft_str_is_printable(printable));
	printf("%d nprintable\n", ft_str_is_printable(nprintable));

	char toup[] = "bonjourJE6''";
	char *upped = ft_strupcase(toup);
	printf("%s\n", upped);

	char tolow[] = "bonJOURJE6''";
	char *lowered = ft_strlowcase(tolow);
	printf("%s\n", lowered);

	char tocap[1024] = "sal_ut, cOMMENT tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_strcapitalize(tocap);
	printf("%s\n", tocap);

	/* char a[] = "qweihroqwier"; */
	char ldest[6];
	/* char b[] = "qweqweeqwrqwer"; */
	char lsrc[] = "qwroiqwer";
	printf("len %u : ", ft_strlcpy(ldest, lsrc, sizeof ldest ));
	for (int i = 0; i < 33; i++)
		printf("%d ", ldest[i]);
	printf("\n%s\n", ldest);
	strlcpy(ldest, "", sizeof ldest);
	printf("len %lu : ", strlcpy(ldest, lsrc, sizeof ldest));
	for (int i = 0; i < 33; i++)
		printf("%d ", ldest[i]);
	printf("\n%s\n", ldest);

	char unp[10] = "bo\xfejou\x01\xaa";
	ft_putstr_non_printable(unp);
	char unp2[10] = {'\xff'};
	for (int i = 0; i < 256; i++)
	{
		unp2[0] = (char)i;
		ft_putstr_non_printable(unp2);
	}
	ft_putstr_non_printable("Coucou\ntu vas bien ?");

	printf("\n---------------------\n");
	char *addr = "bonjour je suis charles et je le suis bien";
	ft_print_memory(addr, sizeof addr);

	return 0;
}
