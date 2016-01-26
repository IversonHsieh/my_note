#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd = open("/dev/null", O_RDWR);
	int in, out, err;

	if (fd < 0) {
		perror("open file error!");
		
		return -1;
	}

	printf("test1\n");

	in = dup(STDIN_FILENO);
	out = dup(STDOUT_FILENO);
	err = dup(STDERR_FILENO);

	dup2(fd, STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	dup2(fd, STDERR_FILENO);

	printf("test2\n");

	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	dup2(err, STDERR_FILENO);
	
	printf("test3\n");

	close(fd);

    return 0;
}
