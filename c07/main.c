#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "ex00/ft_strdup.c"
#include "ex01/ft_range.c"
#include "ex02/ft_ultimate_range.c"
#include "ex03/ft_strjoin.c"
#include "ex04/ft_convert_base.c"
#include "ex04/ft_convert_base2.c"
#include "ex05/ft_split.c"

int main()
{
	char *s = "bonjour";
	char *mydup = ft_strdup(s);
	char *stdup = strdup(s);

	printf("%s\n", mydup);
	printf("%s\n", stdup);
	free(mydup);
	free(stdup);

	printf("---------------\n");
	int *r = ft_range(-3, 5);
	if (r)
		for (int i = 0; i < 10; i++)
			printf("%d ", r[i]);
	printf("\n ");
	free(r);

	printf("---------------\n");
	int *rult;
	int len = ft_ultimate_range(&rult, 0, 10);
	printf("len(%d): ", len);
	for (int i = 0; i < len; i++)
		printf("%d ", rult[i]);
	printf("\n ");

	printf("---------------\n");
	char *strs[] = {"bon", "je", "", "charles"};
	char *sep = "%&^";
	int size = 4;
	char *join;
	join = ft_strjoin(size, strs, sep);
	printf("[%d] %s\n", my_strlen(join), join);
	for (int i = 0; i < my_strlen(join) + 1; i++)
		printf("%d ", join[i]);
	free(join);

	printf("\n---------------\n");
	char *converted;
	converted = ft_convert_base("-101010", "01", "0123456789");
	printf("%s\n", converted);
	free(converted);
	converted = ft_convert_base("  -+1010102345678ff", "01", "0123456789abcdef");
	printf("%s\n", converted);
	free(converted);
	converted = ft_convert_base(" \t\f\v +34589qw", "01234567", "012");
	printf("%s\n", converted);
	free(converted);
	converted = ft_convert_base(" \t\f\v +asdf", "fgh", ".?");
	printf("%s\n", converted);
	free(converted);
	printf("%s\n", ft_convert_base(" \t\f\v +34589qw", "01234567", "0+12"));
	printf("%s\n", ft_convert_base(" \t\f\v +34589qw", "01234567", "012 "));
	printf("%s\n", ft_convert_base(" \t\f\v +34589qw", "012345-67", "012"));
	printf("%s\n", ft_convert_base(" \t\f\v +34589qw", "012\t34567", "012"));
	printf("%s\n", ft_convert_base(" \t\f\v +34589qw", "0", "012"));
	printf("%s\n", ft_convert_base(" \t\f\v +34589qw", "01", ""));
	printf("%s\n", ft_convert_base(" \t\f\v +34w", "01", "0123456789"));
	printf("%s\n", ft_convert_base(" \t\f\v +34w", "01", "!?"));

	printf("\n---------------\n");
	char *const str = "3YaZkAP30iGoBWv L  asdf  h LbpX8Hx FWHwB2u1FH0S5";
	char *begin = "\n \t hgonjour";
	char *end = "jesuis\n\t   hhh";
	char *empty = "";
	char *charset = "\n\t ";
	char **sstrs = ft_split(begin, charset);
	for (int i = 0; i < count_segment(begin, charset) + 1; i++)
	{
		printf("\n%s: ", sstrs[i]);
		/*for (int j = 0; j < 10; j++)*/
			/*printf("%d ", sstrs[i][j]);*/
	}
	if (sstrs)
		for (int i = 0; sstrs[i] != 0; i++)
			free(sstrs[i]);
	free(sstrs);

	return 0;
}
