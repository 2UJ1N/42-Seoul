#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int    main(void)
{
    int        fd;
    int        fd2;
    char    *line;
    char    *line2;

    fd = open("text1.txt", O_RDONLY);
    fd2 = open("text2.txt", O_RDONLY);
    if(fd < 0 || fd2 < 0)
	{
		printf("open Error\n");
		return (1);
	}
	
	printf("fd: %d\n", fd);
    printf("fd2: %d\n", fd2);

    line = get_next_line(fd);
    printf("1. %s", line);
    line2 = get_next_line(fd2);
    printf("2. %s", line2);

    free(line);
    free(line2);

    line = get_next_line(fd);
    printf("3. %s", line);
    line2 = get_next_line(fd2);
    printf("4. %s", line2);

    free(line);
    free(line2);
    close(fd);
    close(fd2);
    return (0);
}
