#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void){
    int n = open("text1.txt", O_RDONLY);
	if (n < 0)
	{
		printf("open Error\n");
		return (1);
	}
    char *line = get_next_line(n);
    printf("%s", line);
    free(line);
    close(n);
}
