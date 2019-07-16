#include <unistd.h>

int	main(void)
{
	char z = 'z';
	write(1, &z, 1);
	return 0;
}	
