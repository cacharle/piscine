#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex00/ft_strdup.c"
#include "ex01/ft_range.c"
#include "ex02/ft_ultimate_range.c"
#include "ex03/ft_strjoin.c"
#include "ex04/ft_convert_base.c"
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
	int len = ft_ultimate_range(&rult, -4, 15);
	printf("len(%d): ", len);
	for (int i = 0; i < len; i++)
		printf("%d ", rult[i]);
	printf("\n ");

	printf("---------------\n");
	char *strs[] = {"bon", "je", "suis", "charles"};
	char *sep = ", ";
	int size = 4;
	char *join;
	join = ft_strjoin(size, strs, sep);
	printf("[%d] %s\n", my_strlen(join), join);
	/*for (int i = 0; i < my_strlen(join) + 1; i++)*/
		/*printf("%d ", join[i]);*/
	free(join);

	printf("\n---------------\n");
	printf("%s\n", ft_convert_base("101010", "01", "0123456789"));
	printf("%s\n", to_base(34, "10"));

	/*printf("\n---------------\n");*/
	/*char *str = "bon.je.suis,asdofoisafj.ladjsf";*/
	/*char *charset = "";*/
	/*char **sstrs = ft_split(str, charset);*/
	/*for (int i = 0; sstrs[i] != 0; i++)*/
		/*printf("%s\n", sstrs[i]);*/
	/*for (int i = 0; sstrs[i] != 0; i++)*/
		/*free(sstrs[i]);*/
	/*free(sstrs);*/

	return 0;
}
