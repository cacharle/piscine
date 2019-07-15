#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "ex00/ft_strlen.c"
#include "ex01/ft_putstr.c"
#include "ex02/ft_putnbr.c"
#include "ex03/ft_atoi.c"
#include "ex04/ft_putnbr_base.c"
#include "ex05/ft_atoi_base.c"

int main()
{
	char *s1 = "jesuis7";
	printf("%d\n", ft_strlen(s1));

	char *s = "bonjour";
	ft_putstr(s);
	printf("\n");

	printf("----------------------\n");
	ft_putnbr(0); printf("\n");
	ft_putnbr(42); printf("\n");
	ft_putnbr(-42); printf("\n");
	ft_putnbr(INT_MAX); printf("\n");
	ft_putnbr(INT_MIN); printf("\n");

	printf("----------------------\n");
	char *s_happypath = "42";
	char *s_happypathn = "-42";
	char *s_int0 = "0";
	char *s_intmax = "2147483647";
	char *s_intmin = "-2147483648";
	char *spaces = "  \t\n\v\f\r  43";
	char *neg = " -+--++36";
	char *pos = "++--+++--4";
	char *garbage_tail = "76iqu21#!@";
	char *all = "\n\t  \v++++---12341234#3%^@";
	char *subject_test = " ---+--+1234ab567";
	char *nothing = "  --+qwer";
	printf("%d\n", ft_atoi(s_happypath));
	printf("%d\n", ft_atoi(s_happypathn));
	printf("%d\n", ft_atoi(s_int0));
	printf("%d\n", ft_atoi(s_intmax));
	printf("%d\n", ft_atoi(s_intmin));
	printf("%d\n", ft_atoi(spaces));
	printf("%d\n", ft_atoi(neg));
	printf("%d\n", ft_atoi(pos));
	printf("%d\n", ft_atoi(garbage_tail));
	printf("%d\n", ft_atoi(all));
	printf("%d\n", ft_atoi(subject_test));
	printf("%d\n", ft_atoi(nothing));

	printf("----------------------\n");
	ft_putnbr_base(42, "0123456789"); printf("\n");
	ft_putnbr_base(-42, "0123456789"); printf("\n");
	ft_putnbr_base(42, "01"); printf("\n");
	ft_putnbr_base(-42, "01"); printf("\n");
	ft_putnbr_base(42, "0123456789abcdef"); printf("\n");
	ft_putnbr_base(42, "01234567"); printf("\n");
	ft_putnbr_base(INT_MAX, "0123456789abcdef"); printf("\n");
	ft_putnbr_base(INT_MIN, "0123456789abcdef"); printf("\n");
	ft_putnbr_base(0, "0123456789"); printf("\n");
	ft_putnbr_base(INT_MAX, "");
	ft_putnbr_base(INT_MAX, "a");
	ft_putnbr_base(INT_MAX, "abb");
	ft_putnbr_base(INT_MAX, "-0123456789");

	printf("----------------------\n");
	printf("%d\n", ft_atoi_base("111000", "01"));
	printf("%d\n", ft_atoi_base("ff", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("52", "01234567"));
	printf("%d\n", ft_atoi_base("2a", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("7fffffff", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("ff", "0123-456789abcdef"));
	printf("%d\n", ft_atoi_base("ff", "01\r23456789abcdef"));
	printf("%d\n", ft_atoi_base("ff", "abcc"));
	printf("%d\n", ft_atoi_base("ff", ""));
	printf("%d\n", ft_atoi_base("ff", "a"));
}
