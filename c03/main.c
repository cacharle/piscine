#include <stdio.h>
#include <string.h>
#include "ex00/ft_strcmp.c"
#include "ex01/ft_strncmp.c"
#include "ex02/ft_strcat.c"
#include "ex03/ft_strncat.c"
#include "ex04/ft_strstr.c"
#include "ex05/ft_strlcat.c"

int main()
{
	char s3[] = "";
	char s4[] = "qwer";
	printf("%d : %d\n", ft_strcmp(s3, s4), strcmp(s3, s4));

	unsigned int size = 4;
	printf("%d : %d\n", ft_strncmp(s3, s4, size), strncmp(s3, s4, size));

	printf("-----------------\n");
	char *head;
	char dest[10] = "abc";
	char src[] = "a";
	head =  ft_strcat(dest, src);
	printf("\n%s ", head);
	for (int i = 0; i < 15; i++)
		printf("%d ", head[i]);
	char _dest[10] = "abc";
	head = strcat(_dest, src);
	printf("\n%s ", head);
	for (int i = 0; i < 15; i++)
		printf("%d ", head[i]);

	printf("\n-----------------\n");
	unsigned int nsize = 2;
	char *nhead;
	char ndest[12] = "abc";
	char nsrc[] = "defg";
	nhead =  ft_strncat(ndest, nsrc, nsize);
	printf("\n%s ", nhead);
	for (int i = 0; i < 15; i++)
		printf("%d ", nhead[i]);
	char _ndest[12] = "abc";
	nhead = strncat(_ndest, nsrc, nsize);
	printf("\n%s ", nhead);
	for (int i = 0; i < 15; i++)
		printf("%d ", nhead[i]);

	printf("\n-----------------\n");
	char *haystack = "abcdefg";
	char *needle = "";
	char *found;
	found = ft_strstr(haystack, needle);
	printf("\n%s ", found);
	if (found)
		for (int i = 0; i < 5; i++)
			printf("%d ", found[i]);
	found = strstr(haystack, needle);
	printf("\n%s ", found);
	if (found)
		for (int i = 0; i < 5; i++)
			printf("%d ", found[i]);

	printf("\n-----------------\n");
	unsigned int lsize = 15;
	char ldest[15] = "0123456789";
	char lsrc[] = "doit";
	printf("\nsize %u, ", ft_strlcat(ldest, lsrc, lsize));
	printf("%s ", ldest);
	for (int i = 0; i < 15; i++)
		printf("%d ", ldest[i]);
	char _ldest[15] = "0123456789";
	printf("\nsize %lu, ", strlcat(_ldest, lsrc, lsize));
	printf("%s ", _ldest);
	for (int i = 0; i < 15; i++)
		printf("%d ", _ldest[i]);
}
