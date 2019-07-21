#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex02/ft_split.c"

int main()
{
	char *const str = "3YaZkAP30iGoBWv L H  asdf  h LbpX8Hx FWHwB2u1FH0S5";
	char *begin = "\n \t hgonjour";
	char *end = "jesuis\n\t   hhh";
	char *empty = "";
	char *charset = " H";
	char **strs = ft_split(empty, charset);
	printf("tab start\n");
	for (int i = 0; strs[i] != 0; i++)
	{
		printf("tab[%d]: %s\n", i, strs[i]);
		/*for (int j = 0; j < 10; j++)*/
			/*printf("%d ", strs[i][j]);*/
	}
	printf("tab end\n");
	for (int i = 0; strs[i] != 0; i++)
		free(strs[i]);
	free(strs);

	return 0;
}
