#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd = open("/dev/tty", O_RDWR);

	if (fd < 0) {
		perror("open file error!");
	
	    return -1;
	}

	dup2(fd, STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	dup2(fd, STDERR_FILENO);

	printf("Hello World!\n");

    return 0;
}
