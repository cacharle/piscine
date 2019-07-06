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
	char s1[] = "bonjour";
	char s2[] = "bonjouj";
	printf("%d : %d\n", ft_strcmp(s1, s2), strcmp(s1, s2));

	unsigned int size = 10;
	printf("%d : %d\n", ft_strncmp(s1, s2, size), strncmp(s1, s2, size));

	char *head;
	char dest[10] = "abc";
	char src[] = "defg";
	head =  ft_strcat(dest, src);
	printf("\n%s ", head);
	for (int i = 0; i < 15; i++)
		printf("%d ", head[i]);
	char _dest[10] = "abc";
	head = strcat(_dest, src);
	printf("\n%s ", head);
	for (int i = 0; i < 15; i++)
		printf("%d ", head[i]);

	unsigned int nsize = 1;
	char *nhead;
	char ndest[10] = "abc";
	char nsrc[] = "defg";
	nhead =  ft_strncat(ndest, nsrc, nsize);
	printf("\n%s ", nhead);
	for (int i = 0; i < 15; i++)
		printf("%d ", nhead[i]);
	char _ndest[10] = "abc";
	nhead = strncat(_ndest, nsrc, nsize);
	printf("\n%s ", nhead);
	for (int i = 0; i < 15; i++)
		printf("%d ", nhead[i]);

	printf("\n");
	char *haystack = "abcdefg";
	char *needle = "abcdefg";
	char *found;
	found = ft_strstr(haystack, needle);
	if (found)
		for (int i = 0; i < 5; i++)
			printf("%d ", found[i]);
	printf("\n%s\n", found);
	found = strstr(haystack, needle);
	if (found)
		for (int i = 0; i < 5; i++)
			printf("%d ", found[i]);
	printf("\n%s\n", found);

	unsigned int lsize = 100;
	char ldest[100] = "abcdef";
	char lsrc[] = "d";
	printf("\nsize %u, ", ft_strlcat(ldest, lsrc, lsize));
	printf("%s ", ldest);
	for (int i = 0; i < 15; i++)
		printf("%d ", ldest[i]);
	char _ldest[100] = "abcdef";
	printf("\nsize %lu, ", strlcat(_ldest, lsrc, lsize));
	printf("%s ", ldest);
	for (int i = 0; i < 15; i++)
		printf("%d ", ldest[i]);
}
