#include "get_next_line.h"

int	main(void)
{
	int i = 0;
	int fd = open("one.txt", O_RDONLY);
	while (i < 6)
	{
		char *p = get_next_line(fd);
		printf("line %d %s",i,p);
		free(p);
		i++;
	}
}