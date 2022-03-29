#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define BUFF_SIZE 10

int
main(int argc, char *argv[])
{
	int pid, status;
	int pipefd[2];

	pipe(pipefd);
	if ((pid = fork()) != 0){
		/* Parent */
		char *message = "message";
		char *buff = malloc(BUFF_SIZE);
		
		write(pipefd[1], message, 1);
		
		while (!read(pipefd[0], buff, sizeof(buff))){}
		printf("%d: received pong\n", getpid());

		wait(&status);

	}else {
		/* Child */
		char *buff = malloc(BUFF_SIZE);
		int n;

		while (!(n = read(pipefd[0], buff, sizeof(buff)))){}
		printf("%d: received ping\n", getpid());
		
		write(pipefd[1], buff, n);

		exit(0);
	}
  exit(0);
}
